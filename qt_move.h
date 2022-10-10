#ifndef QT_MOVE_H
#define QT_MOVE_H

#include <QWidget>
#include <QTimer>

#include "qt_frameless.h"
#include "qt_button_col.h"

class qt_move : public qt_frameless
{
    Q_OBJECT
public:
    explicit qt_move(QWidget *parent = nullptr);

    //移动设置
    void set_distance(int distance);
    void set_speed(int speed);
    void move_start(int time=1);
    void move_back(int time=1);

    //按钮初始化
    void set_butt_pos(QPoint pos);
    void set_butt_pic(QString pic);
    void set_butt_col(QColor normal,QColor enter,QColor press);
    void set_butt_col_back(QColor normal,QColor enter,QColor press);
    void open_back();//准备工作完成之后开启

signals:
    emit void fa_butt_open();
    emit void fa_back();

protected:
    QTimer v_time;

    int v_speed=1;
    int v_distance=0;
    int v_count=0;
    bool is_back=false;

    //按钮部分
    qt_button_col *butt_back;
    QPoint pos_back;
    QString pic_butt;
    bool is_butt_open=false;

private:
    void init_wid();
    void init_signal();

};

#endif // QT_MOVE_H
