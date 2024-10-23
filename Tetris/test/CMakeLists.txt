cmake_minimum_required(VERSION 3.5)

add_executable(Test
    testMain.cpp
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


)

# Set include directories for the test target
target_include_directories(Test PRIVATE
    ../src
)

# Include Catch2 library using FetchContent
include(FetchContent)
FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v3.3.1 # or a later release
)
FetchContent_MakeAvailable(Catch2)

# Link Catch2 to the test target
target_link_libraries(Test Catch2::Catch2WithMain)
