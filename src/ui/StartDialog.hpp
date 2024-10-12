#pragma once

#include <QDialog>
#include <QPushButton>
#include <QVBoxLayout>
#include <QFileDialog>
#include <QMessageBox>
#include <QSpinBox>

namespace art
{
    class NewProjectDialog : public QDialog
    {
        Q_OBJECT

        public:
            explicit NewProjectDialog(QWidget *parent = nullptr);

            int getCanvasWidth() const;
            int getCanvasHeight() const;

        private:
            QSpinBox *widthSpinBox;
            QSpinBox *heightSpinBox;
    };
}
