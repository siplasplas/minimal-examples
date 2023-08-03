#include "MainWindow.h"
#include <QPushButton>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QPushButton *button = new QPushButton(this);
    QIcon icon;
    icon.addFile(":1.png", QSize(48, 48));
    setCentralWidget(button);
    button->setIcon(icon);
    lw.show();
}
