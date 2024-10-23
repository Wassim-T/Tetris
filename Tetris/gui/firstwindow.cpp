#include "firstwindow.h"


firstWindow::firstWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::firstWindow)

{
    ui->setupUi(this);

    connect(ui->submitButton, &QPushButton::clicked, this, &firstWindow::onSubmitButtonClicked);

    connect(ui->defaultBtn, &QPushButton::clicked, this, &firstWindow::onSubmitButtonClickedDefault);

}

firstWindow::~firstWindow()
{
    delete ui;
}

void firstWindow::onSubmitButtonClicked()
{
    QString name = ui->name->text();
    int height = ui->height->value();
    int width = ui->width->value();
    int gridDensity = ui->density->value();
    std::vector<model::TypeBrick> shapes {
        getBrickChoice(ui->box1->currentText().toStdString()),getBrickChoice(ui->box2->currentText().toStdString()),getBrickChoice(ui->box3->currentText().toStdString()),
        getBrickChoice(ui->box4->currentText().toStdString()),getBrickChoice(ui->box5->currentText().toStdString()),getBrickChoice(ui->box6->currentText().toStdString()),
        getBrickChoice(ui->box7->currentText().toStdString())
    };

    std::shared_ptr<model::Loader> loader = std::make_shared<model::Loader>(gridDensity,width,height, shapes);
    model::Grid grid = loader->getGrid();
    model::BagBrick bag = loader->getBag();
    std::string username = name.toStdString();

    std::cout << name.toStdString() << "  " <<height << "  " << width << std::endl;

    std::shared_ptr<model::Game> game = std::make_shared<model::Game>(grid, username, bag, 1);
    std::shared_ptr<controller::TetrisController> controller = std::make_shared<controller::TetrisController>(game);

    mainWindow = std::make_shared<MainWindow>(*controller,width,height);

    controller->addObserver(mainWindow);

    this->close();

    mainWindow->show();

}

void firstWindow::onSubmitButtonClickedDefault()
{


    QString name = ui->name->text();

    if (name.isEmpty()) {
        QMessageBox::warning(this, "Invalid Name", "The Username field cannot be empty.");
            return;
    }
    std::vector<model::TypeBrick> shapes {
        model::TypeBrick::SHAPE_T, model::TypeBrick::SHAPE_C,
        model::TypeBrick::SHAPE_Z, model::TypeBrick::SHAPE_S,
        model::TypeBrick::SHAPE_L, model::TypeBrick::SHAPE_J,
        model::TypeBrick::SHAPE_I
    };


    std::shared_ptr<model::Loader> loader = std::make_shared<model::Loader>(0, 10, 20, shapes);
    model::Grid grid = loader->getGrid();
    model::BagBrick bag = loader->getBag();
    std::string username = name.toStdString();

    std::shared_ptr<model::Game> game = std::make_shared<model::Game>(grid, username, bag, 1);
    std::shared_ptr<controller::TetrisController> controller = std::make_shared<controller::TetrisController>(game);

    mainWindow = std::make_shared<MainWindow>(*controller,10, 20);

    controller->addObserver(mainWindow);

    this->close();

    mainWindow->show();


}


model::TypeBrick firstWindow::getBrickChoice(const std::string& choice){
    if(choice =="T"){
            return model::TypeBrick::SHAPE_T;
    } else if(choice == "C"){
            return model::TypeBrick::SHAPE_C;
    } else if(choice == "Z"){
            return model::TypeBrick::SHAPE_Z;
    } else if(choice == "S"){
         return model::TypeBrick::SHAPE_S;
    } else if(choice == "L"){
         return model::TypeBrick::SHAPE_L;
    } else if (choice == "J"){
            return model::TypeBrick::SHAPE_J;
    } else if (choice == "I"){
         return model::TypeBrick::SHAPE_I;
    } else {
            throw model::TetrisException("The brick doesnt exist.");
    }

}


