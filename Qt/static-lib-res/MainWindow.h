#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "lib/LibWindow.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT
    LibWindow lw;
public:
    MainWindow(QWidget *parent = nullptr);
};
#endif // MAINWINDOW_H
