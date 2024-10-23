#include "mainwindow.h"
#include "qboxlayout.h"
#include "qlabel.h"
#include "ui_mainwindow.h"




std::string getSourceDirectory() {
    std::string fullPath(__FILE__);
    size_t pos = fullPath.rfind('/');
    if (pos != std::string::npos) {
        return fullPath.substr(0, pos);
    }
    return "";
}





MainWindow::MainWindow(const controller::TetrisController &ctrl,int gridWidth, int gridHeight, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow),
    controller(ctrl)
    ,_scene(this)
    ,_sceneBrick(this)
    ,_currBrick(controller.getCurrentBrick())
    ,_shadow(controller.getShadow())
    ,_nextBrick(controller.getNextBrick())

{
    this->setFocus();

    ui->setupUi(this);

    effect = new QMediaPlayer;

    theme = new QMediaPlayer;

    audio = new QAudioOutput;

    QAudioOutput *audioTheme = new QAudioOutput;

    effect->setAudioOutput(audio);

    audio->setVolume(2);

    audioTheme->setVolume(0.1);

    theme->setAudioOutput(audioTheme);

    timer = new QTimer(this);

    connect(timer, &QTimer::timeout, this, &MainWindow::autoMoveBrick);

    timer->start((controller.getSpeed())*1000);

    std::string pathTheme = getSourceDirectory()+"/theme.mp3";

    QString filePathTheme = QString::fromStdString(pathTheme);

    theme->setSource(filePathTheme);


    connect(theme, &QMediaPlayer::mediaStatusChanged, this, &MainWindow::onThemeMediaStatusChanged);
    theme->play();


    std::string path = getSourceDirectory()+"/effect.mp3";

    QString filePath = QString::fromStdString(path);


    effect->setSource(filePath);

    ui->name->setText(QString::fromStdString(controller.getPlayerName()));
    ui->score->setMode(QLCDNumber::Dec);
    ui->level->setMode(QLCDNumber::Dec);

    ui->level->display(1);



    QRect viewContentsRect = ui->graphicsView->contentsRect();

    QRect viewNextBrickRect = ui->brickView->contentsRect();


    std::string pathToBackground = getSourceDirectory()+"/background.png";


    QPixmap bkgnd(QString::fromStdString(pathToBackground));
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Window, bkgnd);
    this->setPalette(palette);



    ui->graphicsView->setScene(&_scene);
    ui->brickView->setScene(&_sceneBrick);
    updateGrid();
    drawNextBrick();
}


void MainWindow::update(model::Notification notification) {
    switch (notification) {
    case model::Notification::NEW_BRICK:
        _currBrick = controller.getCurrentBrick();
        _nextBrick = controller.getNextBrick();
        drawNextBrick();
        break;
    case model::Notification::NEW_LEVEL:
        ui->level->display(controller.getLevel());
        timer->setInterval((controller.getSpeed())*1000);
        break;

    case model::Notification::NEW_POSITION:
        updateGrid();
        break;

    case model::Notification::NEW_SCORE:

        ui->score->display(controller.getScore());
        break;

    case model::Notification::NEW_SHADOW:
        _shadow = controller.getShadow();
        break;

    case model::Notification::GAME_OVER:
        gameOver();
        break;

    case model::Notification::WIN:
        gameWon();
        break;

    case model::Notification::NEW_SOUND:

        effect->play();

        break;
    }
}



void MainWindow::drawNextBrick(){
    _sceneBrick.clear();
    int blockSize = 40;


    for(int i = 0 ; i < _nextBrick.getListSquareSize();i++){

        model::Position pos =  _nextBrick.getPosOfSquare(i);


        qreal blockX = pos.get_x() * blockSize;
        qreal blockY =  pos.get_y() * blockSize;

        QGraphicsRectItem *blockItem = _sceneBrick.addRect(blockX, blockY, blockSize, blockSize, QPen(Qt::white), QBrush(Qt::black));


        switch (_nextBrick.getColor()) {
        case model::Color::RED :

            blockItem->setBrush(QBrush(Qt::red));
            break;
        case model::Color::LIGHTBLUE:

            blockItem->setBrush(QBrush(Qt::blue));
            break;
        case model::Color::GREEN:

            blockItem->setBrush(QBrush(Qt::green));
            break;
        case model::Color::YELLOW:

            blockItem->setBrush(QBrush(Qt::yellow));
            break;
        case model::Color::ORANGE:

            blockItem->setBrush(QBrush(QColorConstants::Svg::orange));
            break;
        case model::Color::MAGENTA:

            blockItem->setBrush(QBrush(Qt::magenta));
            break;
        case model::Color::DARKBLUE:

            blockItem->setBrush(QBrush(Qt::darkBlue));
            break;
        case model::Color::GREY:

            blockItem->setBrush(QBrush(Qt::gray));
            break;

        }


}


}


void MainWindow::updateGrid(){
    _scene.clear();

    model::GRID2D grid= controller.getGrid();

    int gridSizeY = grid.at(0).size();
    int gridSizeX = grid.size();


    int blockSize = 20;


    for (int i = 0; i < gridSizeX; i++) {
        for (int j = 0; j < gridSizeY; j++) {

            qreal blockX = i * blockSize;
            qreal blockY = j * blockSize;

            QGraphicsRectItem *blockItem = _scene.addRect(blockY, blockX, blockSize, blockSize, QPen(Qt::white), QBrush(Qt::black));

            bool occupied = grid.at(i).at(j)->isOccuped();
            bool isShadow = false;
            bool isBrick = false;
            for (int k = 0; k < _currBrick.getListSquareSize(); ++k) {
                if (_currBrick.getPosOfSquare(k) == model::Position(j, i)) {
                    isBrick = true;

                    break;
                }
            }
            for (int k = 0; k < _shadow.getListSquareSize(); ++k) {
                if (_shadow.getPosOfSquare(k) == model::Position(j, i)) {
                    isShadow = true;
                    break;
                }
            }

            if (occupied) {

                switch (grid.at(i).at(j)->getColor()) {
                case model::Color::RED :

                    blockItem->setBrush(QBrush(Qt::red));
                    break;
                case model::Color::LIGHTBLUE:

                    blockItem->setBrush(QBrush(Qt::blue));
                    break;
                case model::Color::GREEN:

                    blockItem->setBrush(QBrush(Qt::green));
                    break;
                case model::Color::YELLOW:

                    blockItem->setBrush(QBrush(Qt::yellow));
                    break;
                case model::Color::ORANGE:

                    blockItem->setBrush(QBrush(QColorConstants::Svg::orange));
                    break;
                case model::Color::MAGENTA:

                    blockItem->setBrush(QBrush(Qt::magenta));
                    break;
                case model::Color::DARKBLUE:

                    blockItem->setBrush(QBrush(Qt::darkBlue));
                    break;
                case model::Color::GREY:

                    blockItem->setBrush(QBrush(Qt::gray));
                    break;

                }

            }      else if(isBrick){
                switch (_currBrick.getColor()) {
                case model::Color::RED :
                    std::cout<<"r"<<std::endl;
                    blockItem->setBrush(QBrush(Qt::red));
                    break;
                case model::Color::LIGHTBLUE:
                    std::cout<<"r"<<std::endl;
                    blockItem->setBrush(QBrush(Qt::blue));
                    break;
                case model::Color::GREEN:
                    std::cout<<"g"<<std::endl;
                    blockItem->setBrush(QBrush(Qt::green));
                    break;
                case model::Color::YELLOW:
                    std::cout<<"y"<<std::endl;
                    blockItem->setBrush(QBrush(Qt::yellow));
                    break;
                case model::Color::ORANGE:
                    std::cout<<"o"<<std::endl;
                    blockItem->setBrush(QBrush(QColorConstants::Svg::darkorange));
                    break;
                case model::Color::MAGENTA:
                    std::cout<<"m"<<std::endl;
                    blockItem->setBrush(QBrush(Qt::magenta));
                    break;
                case model::Color::DARKBLUE:
                    std::cout<<"d"<<std::endl;
                    blockItem->setBrush(QBrush(Qt::darkBlue));
                    break;
                case model::Color::GREY:
                    std::cout<<"grey"<<std::endl;
                    blockItem->setBrush(QBrush(Qt::gray));
                    break;
                }


            } else if (isShadow) {

                if(!isBrick){
                    blockItem->setBrush(QBrush(Qt::cyan));
                }
            }
        }
    }


    ui->graphicsView->setScene(&_scene);
}




void MainWindow::autoMoveBrick(){
    controller.moveBrick();
}


void MainWindow::onThemeMediaStatusChanged(QMediaPlayer::MediaStatus status) {
    if (status == QMediaPlayer::EndOfMedia) {
        theme->setPosition(0); // Reset the position to the beginning
        theme->play();
    }
}



void MainWindow::keyPressEvent(QKeyEvent *event) {
    // Appelez la méthode keyPressEvent de votre contrôleur et transmettez-lui l'événement
    switch(event->key()){
    case Qt::Key_Left:
        controller.moveBrick(model::DirectionStruct::LEFT);
        break;
    case Qt::Key_Right:
        controller.moveBrick(model::DirectionStruct::RIGHT);
        break;
    case Qt::Key_Down:
        controller.moveBrick();
        break;
    case Qt::Key_D:
        controller.rotateBrick(model::DirectionStruct::RIGHT);
        break;
    case Qt::Key_Q:
        controller.rotateBrick(model::DirectionStruct::LEFT);
        break;
    case Qt::Key_Space:
        controller.dropBrick();
        break;
    }

    // Appelez la méthode de la classe de base pour gérer les événements clavier par défaut
    QMainWindow::keyPressEvent(event);
}



void MainWindow::gameOver() {
    QMessageBox::warning(this, "Game Over", QString::fromStdString("You lost! : \nScore : " + std::to_string(ui->score->value()) + "\nLevel : " +std::to_string(ui->level->value())));
    this->close();
}

void MainWindow::gameWon() {
    QMessageBox::warning(this, "Game Won",QString::fromStdString("Congratulations! You won!\nScore : " + std::to_string(ui->score->value()) + "\nLevel : " + std::to_string(ui->level->value())) );
    this->close();
}



// Dans la classe de votre widget principal, MainWindow par exemple
void MainWindow::focusOutEvent(QFocusEvent *event) {
    // Appelé lorsque le focus est perdu
    Q_UNUSED(event);
    this->setFocus(); // Récupérer le focus
}




MainWindow::~MainWindow()
{
    delete ui;
}
