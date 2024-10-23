cmake_minimum_required(VERSION 3.5)

project(Tetris LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable( 
    Tetris
        app/console/Application.cpp
        model/Direction.hpp
        model/Position.cpp
        model/Position.h
        model/TypeBrick.hpp
        model/Color.hpp
        model/util/Notification.hpp
        model/util/Observable.hpp
        model/util/Observer.hpp
        model/Square.cpp
        model/Square.h
        model/Brick.cpp
        model/Brick.h
        model/Box.cpp
        model/Box.h
        model/Player.cpp
        model/Player.h
        model/util/TetrisException.cpp
        model/util/TetrisException.h
        model/BagBrick.cpp
        model/BagBrick.h
        model/Grid.cpp
        model/Grid.h
        model/Game.cpp
        model/Game.h
        model/BrickFactory.cpp
        model/BrickFactory.h
        model/Loader.cpp
        model/Loader.h
        view/console/TetrisView.h
        view/console/TetrisView.cpp
        controller/TetrisController.cpp
        controller/TetrisController.h
        app/console/Application.h
        resources/resource.qrc







)

include(GNUInstallDirs)
install(TARGETS Tetris
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
