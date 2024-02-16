#include "MainWindow.h"
#include "FineSlider.h"
#include <QSplitter>
#include <QVBoxLayout>
#include <QPlainTextEdit>
#include <QMenuBar>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
  setWindowTitle("Fine Slider demo");
  auto *splitter = new QSplitter(Qt::Horizontal, this);
  auto *leftWidget = new QWidget(splitter);
  auto *leftLayout = new QVBoxLayout(leftWidget);
  leftWidget->setLayout(leftLayout);

  auto *groupWidget1 = new QWidget(leftWidget);
  auto *groupLayout1 = new QHBoxLayout(groupWidget1);
  auto *label1 = new QLabel("extra width", groupWidget1);
  lineEdit1 = new QLineEdit(groupWidget1);
  lineEdit1->setFixedWidth(50);
  groupLayout1->addWidget(lineEdit1);
  groupLayout1->addWidget(label1);
  leftLayout->addWidget(groupWidget1);

  auto *slider1 = new FineSlider(nullptr, Qt::Horizontal, leftWidget);
  slider1->setRange(-250, 250);
  lineEdit1->setText(QString::number(slider1->value()));
  connect(slider1, &QSlider::valueChanged, this, &MainWindow::slider1changed);
  leftLayout->addWidget(slider1);

  auto *groupWidget2 = new QWidget(leftWidget);
  auto *groupLayout2 = new QHBoxLayout(groupWidget2);
  auto *label2 = new QLabel("height", groupWidget2);
  lineEdit2 = new QLineEdit(groupWidget2);
  lineEdit2->setFixedWidth(50);
  groupLayout2->addWidget(lineEdit2);
  groupLayout2->addWidget(label2);
  leftLayout->addWidget(groupWidget2);

  auto *slider2 = new FineSlider(slider1, Qt::Horizontal, leftWidget);
  slider2->setRange(0, 100);
  lineEdit2->setText(QString::number(slider2->value()));
  connect(slider2, &QSlider::valueChanged, this, &MainWindow::slider2changed);
  leftLayout->addWidget(slider2);

  auto *groupWidget3 = new QWidget(leftWidget);
  auto *groupLayout3 = new QHBoxLayout(groupWidget3);
  auto *label3 = new QLabel("height", groupWidget3);
  lineEdit3 = new QLineEdit(groupWidget3);
  lineEdit3->setFixedWidth(50);
  groupLayout3->addWidget(lineEdit3);
  groupLayout3->addWidget(label3);
  leftLayout->addWidget(groupWidget3);

  auto *slider3 = new FineSlider(slider1, Qt::Horizontal, leftWidget);
  slider3->setRange(0, 20);
  lineEdit3->setText(QString::number(slider3->value()));
  connect(slider3, &QSlider::valueChanged, this, &MainWindow::slider3changed);
  leftLayout->addWidget(slider3);

  auto *spacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);
  leftLayout->addItem(spacer);

  splitter->addWidget(leftWidget);
  editor = new QPlainTextEdit(splitter);
  splitter->addWidget(editor);
  setStyleSheet("QSplitter::handle { background-color: gray;}");
  splitter->setStretchFactor(0, 0);
  splitter->setStretchFactor(1, 1);
  setCentralWidget(splitter);
  resize(400, 300);
}

void MainWindow::slider1changed(int value) {
  lineEdit1->setText(QString::number(value));
}

void MainWindow::slider2changed(int value) {
  lineEdit2->setText(QString::number(value));
  editor->document()->setPlainText(QString::number(value));
}

void MainWindow::slider3changed(int value) {
  lineEdit3->setText(QString::number(value));
  editor->document()->setPlainText(QString::number(value));
}
