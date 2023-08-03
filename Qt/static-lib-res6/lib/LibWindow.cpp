#include "LibWindow.h"
#include <QPushButton>

LibWindow::LibWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QPushButton *button = new QPushButton(this);
    QIcon icon;
    icon.addFile(":2.png", QSize(48, 48));
    setCentralWidget(button);
}
