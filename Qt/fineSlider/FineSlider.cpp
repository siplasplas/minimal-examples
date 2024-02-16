#include "FineSlider.h"

using namespace std;

FineSlider::FineSlider(FineSlider *mainSlider, Qt::Orientation orientation, QWidget *parent)
    : QSlider(orientation, parent), mainSlider(mainSlider) {
  if (mainSlider)
    mainSlider->fineSliders.push_back(this);
}

void FineSlider::sliderChange(QAbstractSlider::SliderChange change) {
  if (mainSlider && !mainSlider->blockRecursion) {
    blockRecursion = true;
    mainSlider->setValue(value());
    blockRecursion = false;
  }
  for (auto *f : fineSliders) {
    if (f->blockRecursion)
      continue;
    blockRecursion = true;
    int v = value();
    int range = f->maximum() - f->minimum();
    f->setMinimum((int) floor((double) v / range) * range);
    f->setMaximum(f->minimum() + range);
    f->setValue(value());
    blockRecursion = false;
  }
  QSlider::sliderChange(change);
}

void FineSlider::mouseReleaseEvent(QMouseEvent *event) {
  if (event->button() == Qt::LeftButton) {
    blocked = false;
  }
}

void FineSlider::mouseMoveEvent(QMouseEvent *ev) {
  if (blocked) {
    ev->accept();
    return;
  }
  if (oldValue == INT_MAX)
    oldValue = minimum();
  int range = maximum() - minimum();
  if (value() == maximum() && direction > 0
      && mainSlider && maximum() < mainSlider->maximum()) {
    blocked = true;
    blockSignals(true);
    int val = value();
    setMinimum(maximum());
    setMaximum(minimum() + range);
    setValue(min(val, mainSlider->maximum()));
    blockSignals(false);
  } else if (value() == minimum() && direction < 0
      && mainSlider && minimum() > mainSlider->minimum()) {
    blocked = true;
    blockSignals(true);
    int val = value();
    setMaximum(minimum());
    setMinimum(maximum() - range);
    setValue(max(val, mainSlider->minimum()));
    blockSignals(false);
  } else if (orientation() == Qt::Horizontal)
    setValue(pixelPosToRangeValue(ev->pos().x()));
  else
    setValue(pixelPosToRangeValue(ev->pos().y()));
  if (value() > oldValue)
    direction = 1;
  else if (value() < oldValue)
    direction = -1;
  else
    direction = 0;
  oldValue = value();
  ev->accept();
}

int FineSlider::pixelPosToRangeValue(int pos) {
  int sliderLength;
  if (orientation() == Qt::Horizontal) {
    sliderLength = width();
  } else {
    sliderLength = height();
  }
  if (mainSlider) {
    int mainMax = mainSlider->maximum();
    int mainMin = mainSlider->minimum();
    pos = valueToPixels(max(min(pixelsToValue(pos), mainMax), mainMin));
  }
  return QStyle::sliderValueFromPosition(minimum(), maximum(), pos, sliderLength);
}

void FineSlider::mousePressEvent(QMouseEvent *event) {
  int sliderLength, m;
  if (orientation() == Qt::Horizontal) {
    sliderLength = width();
    m = event->pos().x();
  } else {
    sliderLength = height();
    m = event->pos().y();
  }
  int range = maximum() - minimum();
  int thumbPos = (int) ((double) sliderLength / range * (value() - minimum()));
  if (abs(m - thumbPos) > 10) {
    setValue(pixelPosToRangeValue(m));
  } else
    event->accept();
}

int FineSlider::pixelsToValue(int pos) {
  return (int) (pos / gamma()) + minimum();
}

int FineSlider::valueToPixels(int val) {
  return (int) ((val - minimum()) * gamma());
}

double FineSlider::gamma() {
  double sliderLength;
  if (orientation() == Qt::Horizontal) {
    sliderLength = width();
  } else {
    sliderLength = height();
  }
  int range = maximum() - minimum();
  return sliderLength / range;
}
