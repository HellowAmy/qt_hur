#ifndef QT_LAYOUT_H
#define QT_LAYOUT_H

#include <QWidget>
#include <QScrollArea>
#include <QPoint>
#include <QSize>
#include <QPushButton>
#include <QVBoxLayout>

#include "qt_button_col.h"


class qt_layout : public QWidget
{
    Q_OBJECT
public:
    explicit qt_layout(QWidget *parent = nullptr);
    void set_size_wid(int wide,int high);
    void set_size_area(int wide,int high);
    void move_area(QPoint pos);
//    void set_shift(QPoint pos);

signals:

protected:
//    QWidget *wid;
    QScrollArea *area;

    qt_button_col *m1;
    qt_button_col *m2;
    qt_button_col *m3;


    QVBoxLayout *box_h;

private:
    void init_wid();
};

#endif // QT_LAYOUT_H
