#include "LibWindow.h"
#include <QPushButton>

LibWindow::LibWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QPushButton *button = new QPushButton(this);
    setCentralWidget(button);
}
