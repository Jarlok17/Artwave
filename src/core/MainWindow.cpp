#include "MainWindow.hpp"

#include "../ui/StartDialog.hpp"
#include "../ui/MainPanel.hpp"

#include <QMenuBar>
#include <QAction>
#include <QToolBar>
#include <QApplication>
#include <QPushButton>
#include <QFileDialog>
#include <QDockWidget>
#include <QDebug>
#include <QDir>

namespace art
{
    MainWindow::MainWindow()
        : QMainWindow(),
        filemanager(new FileManager()),
        tabWidget(new QTabWidget(this)),
        startScreen(new QWidget(this))
    {
        setWindowTitle("Artwave");
        resize({800, 600});
        setupStartScreen();

        setupMenuBar();
        setupToolBar();

        this->setCentralWidget(startScreen); 
    }

    void MainWindow::setupMenuBar()
    {
        QMenuBar *menuBar = this->menuBar();

        QMenu* fileMenu = menuBar->addMenu(tr("File"));
        QMenu* editMenu = menuBar->addMenu(tr("Edit"));
        QMenu* selectMenu = menuBar->addMenu(tr("Select"));
        QMenu* imageMenu = menuBar->addMenu(tr("Image"));
        QMenu* viewMenu = menuBar->addMenu(tr("View"));
        QMenu* windowMenu = menuBar->addMenu(tr("Window"));
        QMenu* helpMenu = menuBar->addMenu(tr("Help"));

        QAction* newAct = new QAction(tr("New..."), this);
        newAct->setShortcuts(QKeySequence::New);
        fileMenu->addAction(newAct);

        QAction* openAct = new QAction(tr("Open..."), this);
        openAct->setShortcuts(QKeySequence::Open);
        fileMenu->addAction(openAct);

        QAction* saveAct = new QAction(tr("Save..."), this);
        saveAct->setShortcuts(QKeySequence::Save);
        fileMenu->addAction(saveAct);

        QAction* saveAsAct = new QAction(tr("Save As..."), this);
        saveAsAct->setShortcut(QKeySequence(tr("Ctrl+Shift+S", "File | Save as...")));
        fileMenu->addAction(saveAsAct);

        QAction* exportAct = new QAction(tr("Export..."), this);
        exportAct->setShortcut(QKeySequence(tr("Ctrl+E", "File | Export...")));
        fileMenu->addAction(exportAct);

        QAction* exportAsAct = new QAction(tr("Export as..."), this);
        exportAsAct->setShortcut(QKeySequence(tr("Shift+Ctrl+E", "File | Export as...")));
        fileMenu->addAction(exportAsAct);

        QAction* undoAct = new QAction(tr("Undo"), this);
        undoAct->setShortcuts(QKeySequence::Undo);
        editMenu->addAction(undoAct);

        QAction* redoAct = new QAction(tr("Redo"), this);
        redoAct->setShortcuts(QKeySequence::Redo);
        editMenu->addAction(redoAct);


        connect(newAct, &QAction::triggered, this, &MainWindow::createNewProject);
        connect(openAct, &QAction::triggered, this, &MainWindow::openProject);
        connect(saveAct, &QAction::triggered, this, &MainWindow::saveProject);
        connect(undoAct, &QAction::triggered, this, &MainWindow::undo);
        connect(redoAct, &QAction::triggered, this, &MainWindow::redo);
        connect(tabWidget, &QTabWidget::tabCloseRequested, this, &MainWindow::closeTab);
    }

    void MainWindow::setupToolBar()
    {
        QWidget *buttonMenu = new QWidget(this);

        QGridLayout *layout = new QGridLayout(buttonMenu);

        QPushButton *brushButton = new QPushButton(tr("B"), this);
        brushButton->setFixedSize(30, 30);
        layout->addWidget(brushButton, 0, 0);
        
        QPushButton *cursorButton = new QPushButton(tr("C"), this);
        cursorButton->setFixedSize(36, 36);
        layout->addWidget(cursorButton, 0, 1);

        QPushButton *eraserButton = new QPushButton(tr("E"), this);
        eraserButton->setFixedSize(30, 30);
        layout->addWidget(eraserButton, 1, 0);

        QPushButton *fillButton = new QPushButton(tr("F"), this);
        fillButton->setFixedSize(30, 30);
        layout->addWidget(fillButton, 1, 1);

        QPushButton *shapeButton = new QPushButton(tr("S"), this);
        shapeButton->setFixedSize(30, 30);
        layout->addWidget(shapeButton, 2, 0);

        QPushButton *colorPickerButton = new QPushButton(tr("CP"), this);
        colorPickerButton->setFixedSize(30, 30);
        layout->addWidget(colorPickerButton, 2, 1);

        buttonMenu->setLayout(layout);

        QDockWidget *dockWidget = new QDockWidget(tr("Tools"), this);
        dockWidget->setWidget(buttonMenu);

        this->addDockWidget(Qt::LeftDockWidgetArea, dockWidget);    
    }

    void MainWindow::setupStartScreen()
    {
        QVBoxLayout *layout = new QVBoxLayout(startScreen);

        QPushButton *newProjectButton = new QPushButton(tr("Create New Project"), this);
        newProjectButton->setFixedSize(200, 50);
        connect(newProjectButton, &QPushButton::clicked, this, &MainWindow::createNewProject);

        QPushButton *openProjectButton = new QPushButton(tr("Open Existing Project"), this);
        openProjectButton->setFixedSize(200, 50);
        connect(openProjectButton, &QPushButton::clicked, this, &MainWindow::openProject);

        layout->addStretch();
        layout->addWidget(newProjectButton, 0, Qt::AlignCenter);
        layout->addWidget(openProjectButton, 0, Qt::AlignCenter);
        layout->addStretch();

        startScreen->setLayout(layout);
    }

    void MainWindow::createNewProject()
    {
        showMainInterface();

        NewProjectDialog newProjectDialog(this);
        if (newProjectDialog.exec() == QDialog::Accepted)
        {
            int canvasWidth = newProjectDialog.getCanvasWidth();
            int canvasHeight = newProjectDialog.getCanvasHeight();

            CustomPanel* newPanel = new CustomPanel(this);
            newPanel->setFixedSize(canvasWidth, canvasHeight);

            QScrollArea* scrollArea = new QScrollArea(this);
            scrollArea->setWidgetResizable(true);
            scrollArea->setAlignment(Qt::AlignCenter);
            scrollArea->setWidget(newPanel);

            int newTabIndex = tabWidget->addTab(scrollArea, tr("Project %1").arg(tabWidget->count() + 1));

            tabWidget->setCurrentIndex(newTabIndex);
            tabWidget->setTabsClosable(true);
        }
    }

    void MainWindow::openProject()
    {
        QString filename = QFileDialog::getOpenFileName(this, tr("Open Project"), QDir::homePath(), tr("ART Files (*.art)"));
        if (!filename.isEmpty())
        {
            filemanager->openARTFile(filename.toStdString());
        }
    }

    void MainWindow::saveProject()
    {
        QString filename = QFileDialog::getSaveFileName(this, tr("Save Project"), QDir::homePath(), tr("ART Files (*.art)"));
        if (!filename.isEmpty())
        {
            filemanager->createARTFile(filename.toStdString());
        }
    }

    void MainWindow::showMainInterface()
    {
        if (centralWidget() != tabWidget)
        {
            setCentralWidget(tabWidget);
        }
    }

    void MainWindow::undo()
    {
        int currentTabIndex = tabWidget->currentIndex();

        if (currentTabIndex != -1)
        {
            QScrollArea* scrollArea = qobject_cast<QScrollArea*>(tabWidget->widget(currentTabIndex));
            if (scrollArea)
            {
                CustomPanel* currentPanel = qobject_cast<CustomPanel*>(scrollArea->widget());
                if (currentPanel)
                {
                    currentPanel->undo();
                }
            }
        }
    }

    void MainWindow::redo()
    {
        int currentTabIndex = tabWidget->currentIndex();

        if (currentTabIndex != -1)
        {
            QScrollArea* scrollArea = qobject_cast<QScrollArea*>(tabWidget->widget(currentTabIndex));
            if (scrollArea)
            {
                CustomPanel* currentPanel = qobject_cast<CustomPanel*>(scrollArea->widget());
                if (currentPanel)
                {
                    currentPanel->redo();
                }
            }
        }
    }

    void MainWindow::closeTab(int index)
    {
        QWidget* widget = tabWidget->widget(index);
        if (widget)
        {
            tabWidget->removeTab(index);
            widget->deleteLater();
        }
    }
}
