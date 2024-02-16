#ifndef FINESLIDER_FINESLIDER_H
#define FINESLIDER_FINESLIDER_H

#include <QSlider>
#include <QMouseEvent>
#include <QStyle>

class FineSlider : public QSlider {
Q_OBJECT
  bool blocked = false;
  bool blockRecursion = false;
  int oldValue = INT_MAX;
  int direction = 0;
  FineSlider *mainSlider;
  QVector<FineSlider *> fineSliders;
  double gamma();
  int pixelsToValue(int pos);
  int valueToPixels(int val);
public:
  explicit FineSlider(FineSlider *mainSlider, Qt::Orientation orientation, QWidget *parent = nullptr);

protected:
  void sliderChange(SliderChange change) override;
  void mousePressEvent(QMouseEvent *event) override;
  void mouseReleaseEvent(QMouseEvent *event) override;
  void mouseMoveEvent(QMouseEvent *ev) override;
  int pixelPosToRangeValue(int pos);
};
#endif //FINESLIDER_FINESLIDER_H
