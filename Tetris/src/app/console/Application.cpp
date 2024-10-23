#include <iostream>
#include "../../model/Grid.h"
#include "../../model/Loader.h"
#include "../../model/Game.h"
#include "../../view/console/TetrisView.h"
#include "../../controller/TetrisController.h"
#include "Application.h"
#include <conio.h>

int main() {

   printWelcome();

    std::shared_ptr<model::Loader> loader;
    std::shared_ptr<controller::TetrisController> controller;
    std::shared_ptr<view::console::TetrisView> view;

    int level = 1;

    if (defaultConfiguration()) {

        std::vector<model::TypeBrick> shapes {model::TypeBrick::SHAPE_T,model::TypeBrick::SHAPE_C
                ,model::TypeBrick::SHAPE_Z,model::TypeBrick::SHAPE_S,model::TypeBrick::SHAPE_L,model::TypeBrick::SHAPE_J,
                                              model::TypeBrick::SHAPE_I};
        loader = std::make_shared<model::Loader>(0,10,20,shapes);
    } else {
        int density = getValueFromUser(0,100,"Enter the requested grid density in %");
        int gridWidth = getValueFromUser(10,100,"Enter the requested grid width"); //the bounds are arbitrary and can be changed
        int gridHeight = getValueFromUser(5,100,"Enter the requested grid height");
         level = getValueFromUser(1,20,"Enter the level at which you want to start");
        std::array<char,7> shapesArr = getShapesFromUser();
        std::vector<model::TypeBrick> shapes;
        for (const char & c : shapesArr) {
            fillShapeVector(c,shapes);
        }
        loader = std::make_shared<model::Loader>(density,gridWidth,gridHeight,shapes);
    }

    model::Grid grid = loader->getGrid();
    model::BagBrick bag = loader->getBag();
    std::string username = askUserName();
    std::shared_ptr<model::Game> game = std::make_shared<model::Game>(grid, username, bag,level);
    controller = std::make_shared<controller::TetrisController>(game);
    view = std::make_shared<view::console::TetrisView>(*controller);
    controller->addObserver(view);

    view->printBoard();


    int c = 0;
    int ex = 0;
    while(1)
    {
        //TODO sleep graphic
        c = getch();

        if (c == 0 || c == 224) // Check for arrow key or function key
        {
            switch (ex = getch()) {
                case KEY_DOWN:
                    controller->moveBrick();
                    break;
                case KEY_LEFT:
                    controller->moveBrick(model::DirectionStruct::LEFT);
                    break;
                case KEY_RIGHT:
                    controller->moveBrick(model::DirectionStruct::RIGHT);
                    break;
                default:
                    std::cout << std::endl << "Invalid input. Please try again." << std::endl;
                    break;
            }
        }
        else
        {
            switch (c) {
                case 'q':
                    controller->rotateBrick(model::DirectionStruct::LEFT);
                    break;
                case 'd':
                    controller->rotateBrick(model::DirectionStruct::RIGHT);
                    break;
                case ' ':
                    controller->dropBrick();
                    break;
                default:
                    std::cout << std::endl << "Invalid input. Please try again." << std::endl;
                    break;
            }
        }

    }

}

bool defaultConfiguration() {
    std::string choice;

    do {
        std::cout << "Do you want to Load the default Configuration ? (y/n)" << std::endl;
        std::cin >> choice;


        std::transform(choice.begin(), choice.end(), choice.begin(),
                       [](unsigned char c) { return std::tolower(c); });   //to lowercase

        if (choice != "y" && choice != "n") {
            std::cout << "Invalid input. Please enter 'y' or 'n'" << std::endl;
        }

    } while (choice != "y" && choice != "n");


    return choice == "y";
}

int getValueFromUser(int lowerBound, int upperBound, std::string message) {
    int n;

    do {
        std::cout << message << " (between " << lowerBound << " and " << upperBound << "): ";
        std::cin >> n;

        if (std::cin.fail() || n < lowerBound || n > upperBound) {
            std::cout << "Invalid input. Please enter a valid number between "
                      << lowerBound << " and " << upperBound << "." << std::endl;

            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    } while (std::cin.fail() || n < lowerBound || n > upperBound);

    return n;
}

std::array<char, 7> getShapesFromUser() {
    std::array<char, 7> shapes;
    const std::string validShapes = "ICTJLZS";

    for (int i = 0; i < 7; ++i) {
        char choice;
        bool isValidChoice = false;

        do {
            std::cout << "Enter shape " << i+1 << " (I, C, T, J, L, Z, S): ";
            std::cin >> choice;
            choice = std::toupper(choice);

            if (validShapes.find(choice) != std::string::npos) {
                isValidChoice = true;
            } else {
                std::cout << "Invalid shape. Please choose from I, C, T, J, L, Z, S." << std::endl;
            }
        } while (!isValidChoice);

        shapes[i] = choice;
    }

    return shapes;
}

void fillShapeVector(const char & c, std::vector<model::TypeBrick> &shapes) {
    switch (c) {
        case 'I':
            shapes.push_back(model::TypeBrick::SHAPE_I);
            break;

        case 'C':
            shapes.push_back(model::TypeBrick::SHAPE_C);
            break;

        case 'T':
            shapes.push_back(model::TypeBrick::SHAPE_T);
            break;

        case 'J':
            shapes.push_back(model::TypeBrick::SHAPE_J);
            break;

        case 'L':
            shapes.push_back(model::TypeBrick::SHAPE_L);
            break;

        case 'Z':
            shapes.push_back(model::TypeBrick::SHAPE_Z);
            break;

        case 'S':
            shapes.push_back(model::TypeBrick::SHAPE_S);
            break;

        default:
            throw model::TetrisException("Invalid char type");

    }
}

std::string askUserName() {
    std::string username;
    std::cout << "Enter your username : ";
    std::cin >> username;
    std::cout<<std::endl;

    return username;
}

void printWelcome() {
    std::cout << R"(

                              ___________________________________________ .___   _________
                              \__    ___/\_   _____/\__    ___/\______   \|   | /   _____/
     ______   ______   ______   |    |    |    __)_   |    |    |       _/|   | \_____  \   ______   ______   ______
    /_____/  /_____/  /_____/   |    |    |        \  |    |    |    |   \|   | /        \ /_____/  /_____/  /_____/
                                |____|   /_______  /  |____|    |____|_  /|___|/_______  /
                                                 \/                    \/              \/
)";
    std::cout << std::endl;
}
