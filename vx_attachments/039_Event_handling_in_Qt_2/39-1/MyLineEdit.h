#ifndef MYLINEEDIT_H
#define MYLINEEDIT_H

#include <QLineEdit>

class MyLineEdit : public QLineEdit
{
    Q_OBJECT
public:
    explicit MyLineEdit(QWidget *parent = 0);

    // 重载跟父类Widget一样的两个事件处理函数
    bool event(QEvent* e);
    void keyPressEvent(QKeyEvent* e);
signals:
    
public slots:
    
};

#endif // MYLINEEDIT_H
