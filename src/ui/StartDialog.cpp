#include "StartDialog.hpp"

#include <QLabel>

namespace art 
{
    ////////////////////////////// NEW PROJECT CLASS //////////////////////////////////// 
    NewProjectDialog::NewProjectDialog(QWidget *parent)
        : QDialog(parent)
    {
        setWindowTitle(tr("New Project"));

        QVBoxLayout *layout = new QVBoxLayout(this);

        widthSpinBox = new QSpinBox(this);
        widthSpinBox->setRange(100, 5000);  // Встановимо допустимі значення
        widthSpinBox->setValue(800);  // Значення за замовчуванням

        heightSpinBox = new QSpinBox(this);
        heightSpinBox->setRange(100, 5000);
        heightSpinBox->setValue(600);

        QPushButton *createButton = new QPushButton(tr("Create"), this);
        connect(createButton, &QPushButton::clicked, this, &QDialog::accept);

        layout->addWidget(new QLabel(tr("Width:")));
        layout->addWidget(widthSpinBox);
        layout->addWidget(new QLabel(tr("Height:")));
        layout->addWidget(heightSpinBox);
        layout->addWidget(createButton);

        setLayout(layout);
    }

    int NewProjectDialog::getCanvasWidth() const
    {
        return widthSpinBox->value();
    }

    int NewProjectDialog::getCanvasHeight() const
    {
        return heightSpinBox->value();
    }
}
