Problem: 

In my minimal example is main project and static library with Qt widgets.
Both have qrc files, like
```
<!DOCTYPE RCC>
<RCC version="1.0">
<qresource prefix="/">
    <file>1.png</file>
</qresource>
</RCC>
```
whereas main app can see paths do png images,
library can't.

Second problem:

although images are 48x48 and even explicit is set size to 48x48
```
    QIcon icon;
    icon.addFile(":1.png", QSize(48, 48));
    button->setIcon(icon);
    setCentralWidget(button);
```
Digit "1" is too small, seems to be resized to 16x16 or 24x24.