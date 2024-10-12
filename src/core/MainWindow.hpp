#pragma once

#include "../managers/FileManager.hpp"

#include <QMainWindow>
#include <QHBoxLayout>
#include <QWidget>
#include <QScrollArea>
#include <qtabwidget.h>

namespace art
{
    class MainWindow : public QMainWindow
    {
        Q_OBJECT

        public:
            MainWindow();

        private:
                void setupMenuBar();
                void setupToolBar();

                void createNewProject();
                void openProject();
                void saveProject();
                void setupStartScreen();
                void showMainInterface();

                void undo();
                void redo();
                void closeTab(int index);

                QWidget* startScreen;
                QTabWidget* tabWidget;
                FileManager* filemanager;
    };

}

