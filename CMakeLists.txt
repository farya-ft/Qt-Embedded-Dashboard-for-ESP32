cmake_minimum_required(VERSION 3.14)
project(QtProject_WithExampleFiles LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

# اضافه کردن SerialPort به لیست پکیج‌ها
find_package(Qt6 REQUIRED COMPONENTS Core Gui Qml Quick QuickControls2 SerialPort)

file(GLOB_RECURSE APP_SOURCES CONFIGURE_DEPENDS
    "${CMAKE_SOURCE_DIR}/src/*.cpp"
    "${CMAKE_SOURCE_DIR}/src/*.h"
    "${CMAKE_SOURCE_DIR}/*.qrc"
)

qt_add_executable(MyApp
    ${APP_SOURCES}
)

target_link_libraries(MyApp
    PRIVATE Qt6::Core Qt6::Gui Qt6::Qml Qt6::Quick Qt6::QuickControls2 Qt6::SerialPort
)