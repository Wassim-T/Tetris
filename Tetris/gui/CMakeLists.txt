cmake_minimum_required(VERSION 3.5)

project(gui LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set (CMAKE_AUTOUIC ON)
set (CMAKE_AUTOMOC ON)
set (CMAKE_AUTORCC ON)

add_executable(
        gui
        mainwindow.h mainwindow.cpp mainwindow.ui
        firstwindow.h firstwindow.cpp firstwindow.ui
        main.cpp
        ../src/model/Direction.hpp
        ../src/model/Position.cpp
        ../src/model/Position.h
        ../src/model/TypeBrick.hpp
        ../src/model/Color.hpp
        ../src/model/util/Notification.hpp
        ../src/model/util/Observable.hpp
        ../src/model/util/Observer.hpp
        ../src/model/Square.cpp
        ../src/model/Square.h
        ../src/model/Brick.cpp
        ../src/model/Brick.h
        ../src/model/Box.cpp
        ../src/model/Box.h
        ../src/model/Player.cpp
        ../src/model/Player.h
        ../src/model/util/TetrisException.cpp
        ../src/model/util/TetrisException.h
        ../src/model/BagBrick.cpp
        ../src/model/BagBrick.h
        ../src/model/Grid.cpp
        ../src/model/Grid.h
        ../src/model/Game.cpp
        ../src/model/Game.h
        ../src/model/BrickFactory.cpp
        ../src/model/BrickFactory.h
        ../src/model/Loader.cpp
        ../src/model/Loader.h
        ../src/view/console/TetrisView.h
        ../src/view/console/TetrisView.cpp
        ../src/controller/TetrisController.cpp
        ../src/controller/TetrisController.h
        effect.mp3

)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets Multimedia )
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets Multimedia)

target_link_libraries(gui PRIVATE
    Qt${QT_VERSION_MAJOR}::Widgets
    Qt${QT_VERSION_MAJOR}::Multimedia
)



include(GNUInstallDirs)
install(TARGETS gui
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
