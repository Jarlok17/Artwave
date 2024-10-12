set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOMOC ON)

find_package(Qt6 COMPONENTS Core Widgets REQUIRED)

set(PROJECT_SOURCES
    main.cpp
    MainWindow.cpp
    MainWindow.hpp
)

qt_add_executable(core
    MANUAL_FINALIZATION
    ${PROJECT_SOURCES}
)

target_link_libraries(core PRIVATE Qt6::Core Qt6::Widgets ui managers)

set_target_properties(core PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
    OUTPUT_NAME "Artwave"
)

qt_finalize_executable(core)
