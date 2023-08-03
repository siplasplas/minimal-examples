#ifndef LIBWINDOW_H
#define LIBWINDOW_H

#include <QMainWindow>

class LibWindow : public QMainWindow
{
    Q_OBJECT
public:
    LibWindow(QWidget *parent = nullptr);
};
#endif // LIBWINDOW_H
