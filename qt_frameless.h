#ifndef QT_FRAMELESS_H
#define QT_FRAMELESS_H

#include <QWidget>
#include <QMouseEvent>
#include <QPainter>

#include "qt_button_col.h"

class qt_frameless : public QWidget
{
    Q_OBJECT
public:
    explicit qt_frameless(QWidget *parent = nullptr);

    void set_backdrop(QString pic);//设置背景

    //开启移动权限
    void open_rect(QRect rect);
    void close_rect();
    void open_move();
    void close_move();
    void open_move_parent();
    void close_move_parent();
    void open_butt();
    QPoint get_pos_menu();

signals:
    emit void fa_press();//移动点击消失
    emit void fa_butt_menu();
    emit void fa_menu();
    emit void fa_min();
    emit void fa_close();

protected:
    //关闭按键
    qt_button_col *butt_c1;
    qt_button_col *butt_c2;
    qt_button_col *butt_c3;

    //无边框移动事件操作
    QWidget *v_parent;//父类指针
    QPoint pos_global;//记录点击位置
    QRect v_rect;//启动范围
    bool is_press = false;//点击移动时防止抖动

    //无边框移动事件操作——允许范围
    bool is_open = false;//开启移动
    bool is_open_parent = false;//开启父类移动
    bool is_open_rect = false;//开启范围

    //无边框移动事件操作——事件处理
    void mouseMoveEvent(QMouseEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;

    //绘制背景
    QString pic_backdrop;//背景图片
    void paintEvent(QPaintEvent *event) override;

private:
    void init_wid();
    void init_signal();


};

#endif // QT_FRAMELESS_H
