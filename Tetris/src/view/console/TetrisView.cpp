#include <iomanip>
#include "TetrisView.h"


namespace view::console{


    TetrisView::TetrisView(const controller::TetrisController &controller) : _controller(controller), _score(0),_level(1), _currBrick(controller.getCurrentBrick()),
    _shadow(controller.getShadow()), _nextBrick(controller.getNextBrick()){
    }

    void TetrisView::printBoard() {
        #ifdef _WIN32
        system("cls");
        #else
        system("clear");
        #endif
        model::GRID2D grid2D = _controller.getGrid();
        int width = grid2D.at(0).size();

        printNextBrick();

        int borderWidth = width * 2 + 4;

        int padding = (borderWidth - 6 - 5) / 2;

        // Print the top border
        std::cout << std::string(borderWidth, '-') << std::endl;
        std::cout << "| " << std::setw(padding + 5) << "Board" << std::setw(padding + 5) << " |" << std::endl;
        std::cout << "| " << std::string(borderWidth - 4, '-') << " |" << std::endl;

        for (int i = 0; i < grid2D.size(); ++i) {
            std::cout << "| ";
            for (int j = 0; j < width; ++j) {
                bool occupied = grid2D.at(i).at(j)->isOccuped();
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

                    switch (grid2D.at(i).at(j)->getColor()) {
                    case model::Color::RED :
                        std::cout << _RED << "[]" << _RESET;
                        break;
                    case model::Color::LIGHTBLUE:
                        std::cout << _BLUE << "[]" << _RESET;
                        break;
                    case model::Color::GREEN:
                        std::cout << _GREEN << "[]" << _RESET;
                        break;
                    case model::Color::YELLOW:
                        std::cout << _YELLOW << "[]" << _RESET;
                        break;
                    case model::Color::ORANGE:
                        std::cout << "\033[38;5;208m[]" << _RESET;
                        break;
                    case model::Color::MAGENTA:
                        std::cout << _MAGENTA << "[]" << _RESET;
                        break;
                    case model::Color::DARKBLUE:
                        std::cout << "\033[38;5;20m[]" << _RESET;
                        break;
                    case model::Color::GREY:
                        std::cout << _WHITE << "[]" << _RESET;
                        break;
                    default:
                        std::cout << "[]";
                    }

                } else if (isShadow) {
                    std::cout << _CYAN << "||" << _RESET; // Shadow color
                }
                else if(isBrick){
                    switch (_currBrick.getColor()) {
                    case model::Color::RED :
                        std::cout << _RED << "[]" << _RESET;
                        break;
                    case model::Color::LIGHTBLUE:
                        std::cout << _BLUE << "[]" << _RESET;
                        break;
                    case model::Color::GREEN:
                        std::cout << _GREEN << "[]" << _RESET;
                        break;
                    case model::Color::YELLOW:
                        std::cout << _YELLOW << "[]" << _RESET;
                        break;
                    case model::Color::ORANGE:
                        std::cout << "\033[38;5;208m[]" << _RESET;
                        break;
                    case model::Color::MAGENTA:
                        std::cout << _MAGENTA << "[]" << _RESET;
                        break;
                    case model::Color::DARKBLUE:
                        std::cout << "\033[38;5;20m[]" << _RESET;
                        break;
                    case model::Color::GREY:
                        std::cout << _WHITE << "[]" << _RESET;
                        break;
                    default:
                        std::cout << "[]";
                    }
                }else {
                    std::cout << ". ";
                }
            }
            std::cout << " |" << std::endl;
        }

        std::cout << "| " << std::string(borderWidth - 4, '-') << " |" << std::endl;
        std::cout << std::string(borderWidth, '-') << std::endl;

        std::cout << std::endl;

        printPlayer();
    }



    void TetrisView::printLoose() {
        std::cout << "-----------------------------------------" << std::endl;
        std::cout << "|                                         " << std::endl;
        std::cout << "|           Game Over! You lost.          " << std::endl;
        std::cout << "|           Score : " <<_score<<"                 " << std::endl;
        std::cout << "-----------------------------------------" << std::endl;
    }

    void TetrisView::printWin() {
        std::cout << "-----------------------------------------" << std::endl;
        std::cout << "|                                         " << std::endl;
        std::cout << "|      Congratulations! You win!          " << std::endl;
        std::cout << "|           Score : " <<_score<<"                   " << std::endl;
        std::cout << "-----------------------------------------" << std::endl;
    }

    void TetrisView::printPlayer() {
        std::cout<<"Player : "+_controller.getPlayerName()+" "<<"Score  : "<<_score<<" Current level : "<<_level<<std::endl;
    }

    void TetrisView::printNextBrick() {
        model::Brick nextBrick = _controller.getNextBrick();

        // Get the dimensions of the next brick
        int minX = std::numeric_limits<int>::max();
        int maxX = std::numeric_limits<int>::min();
        int minY = std::numeric_limits<int>::max();
        int maxY = std::numeric_limits<int>::min();

        for (int i = 0; i < nextBrick.getListSquareSize(); ++i) {
            model::Position pos = nextBrick.getPosOfSquare(i);
            minX = std::min(minX, pos.get_x());
            maxX = std::max(maxX, pos.get_x());
            minY = std::min(minY, pos.get_y());
            maxY = std::max(maxY, pos.get_y());
        }

        // Print the next brick with a square border
        std::cout << "---------------------" << std::endl;
        std::cout << "| Next Brick:       |" << std::endl;
        std::cout << "|-------------------|" << std::endl;

        for (int y = minY; y <= maxY; ++y) {
            std::cout << "| ";
            std::cout << std::setw(8);
            for (int x = minX; x <= maxX; ++x) {
                bool occupied = false;
                for (int i = 0; i < nextBrick.getListSquareSize(); ++i) {
                    if (nextBrick.getPosOfSquare(i) == model::Position(x, y)) {
                        occupied = true;
                        break;
                    }
                }
                if (occupied) {
                    std::cout << "[]";
                } else {
                    std::cout << "  ";
                }
            }
            std::cout << std::endl;
        }

        std::cout << "|-------------------|" << std::endl;

    }

    void TetrisView::update(model::Notification notification) {
        switch (notification) {
            case model::Notification::NEW_BRICK:
                _currBrick = _controller.getCurrentBrick();
                break;
            case model::Notification::NEW_LEVEL:
                _level = _controller.getLevel();
                break;

            case model::Notification::NEW_POSITION:
                printBoard();
                break;

            case model::Notification::NEW_SCORE:
                _score = _controller.getScore();
                break;

            case model::Notification::NEW_SHADOW:
                _shadow = _controller.getShadow();
                break;

            case model::Notification::NEW_SOUND:
                //TODO graphic view
                break;


            case model::Notification::GAME_OVER:
                printLoose();
                break;

            case model::Notification::WIN:
                printWin();
                break;
        }
    }
}
