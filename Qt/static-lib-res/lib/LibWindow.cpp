#include "LibWindow.h"
#include <QPushButton>

void initLibraryResources() {
    Q_INIT_RESOURCE(2);
}

Q_CONSTRUCTOR_FUNCTION(initLibraryResources)

LibWindow::LibWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QPushButton *button = new QPushButton(this);
    QIcon icon;
    icon.addFile(":2.png", QSize(48, 48));
    button->setIcon(icon);
    setCentralWidget(button);
}
