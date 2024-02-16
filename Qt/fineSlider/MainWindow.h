#ifndef FINESLIDER_MAINWINDOW_H
#define FINESLIDER_MAINWINDOW_H

#include <QMainWindow>
#include <QSlider>
#include <QLineEdit>
#include <QLabel>
#include <QPlainTextEdit>

class MainWindow : public QMainWindow {
Q_OBJECT
  QLineEdit *lineEdit1;
  QLineEdit *lineEdit2;
  QLineEdit *lineEdit3;
  QPlainTextEdit *editor;
public:
  explicit MainWindow(QWidget *parent = nullptr);

private slots:
  void slider1changed(int value);
  void slider2changed(int value);
  void slider3changed(int value);
};

#endif // FINESLIDER_MAINWINDOW_H
