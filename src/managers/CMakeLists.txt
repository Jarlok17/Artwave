set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOMOC ON)

find_package(Qt6 COMPONENTS Core Widgets REQUIRED)

set(PROJECT_SOURCES
    FileManager.cpp
    FileManager.hpp
)

add_library(managers STATIC
    ${PROJECT_SOURCES}
)

target_link_libraries(managers PRIVATE Qt6::Core Qt6::Widgets)
