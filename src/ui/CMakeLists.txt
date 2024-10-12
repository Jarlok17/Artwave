set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOMOC ON)

find_package(Qt6 COMPONENTS Core Widgets REQUIRED)

set(PROJECT_SOURCES
    MainPanel.cpp
    MainPanel.hpp
    StartDialog.cpp
    StartDialog.hpp
)

add_library(ui STATIC
    ${PROJECT_SOURCES}
)

target_link_libraries(ui PRIVATE Qt6::Core Qt6::Widgets)
