cmake_minimum_required(VERSION 3.24)
project(Freewheelin-mobile)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_PREFIX_PATH "/opt/homebrew/Cellar/qt@5/5.15.7")

find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        Multimedia
        MultimediaWidgets
        REQUIRED)

set(QT_SOURCE_FILES
        res.qrc
        )

add_executable(Freewheelin-mobile main.cpp MainWindow.cpp MainWindow.h MainWindow.ui res.qrc ThePlayer.h TheButton.cpp TheButton.h MainWindow.cpp MainWindow.h MainWindow.ui)
target_link_libraries(Freewheelin-mobile
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
        Qt5::Multimedia
        Qt5::MultimediaWidgets
        )
