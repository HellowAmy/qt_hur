#ifndef QT_BUTTON_H
#define QT_BUTTON_H

#include <QWidget>
#include <QPushButton>
#include <QString>
#include <QPixmap>
#include <QPainter>

#include "c_define.h"



class qt_button : public QPushButton
{
    Q_OBJECT
public:

    //使用方法：
    //添加normal、press、enter 三张图片 ——分别显示正常、进入和按下时的切换
    //add_pic_normal()函数必须使用，不然出现错误
    //必须在最后调用 open()函数

    explicit qt_button(QWidget *parent = nullptr);
    explicit qt_button(QString normal,QString press,QString enter,QWidget *parent = nullptr)
        : QPushButton(parent),v_normal(normal),v_press(press),v_enter(enter){}

    void add_pic_normal(QString pic);//正常
    void add_pic_press(QString pic);//按下
    void add_pic_enter(QString pic);//释放
    void open(int x=0,int y=0);//启动
    void set_mask(QString pic = "");
    void set_scaled(int wide,int high);
    void set_border(int border);
    void set_fix_size(int wide , int high);

signals:
    emit void fa_enter();
    emit void fa_leave();

private:
    QString v_normal;
    QString v_press;
    QString v_enter;

    bool is_scaled=false;
    int v_wide = 0;
    int v_high = 0;
    int v_border = 0;//边距（会压缩图片大小的位置）

    QPixmap pix;
    QRect rect;

    void show_update(QString pic);
    void show_scaled(QString pic);

protected:
    //改变图片事件
    void mousePressEvent(QMouseEvent *) override;//点击事件
    void mouseReleaseEvent(QMouseEvent *) override;//释放事件
    void enterEvent(QEnterEvent *) override;//进入事件
    void leaveEvent(QEvent *) override;//离开事件

    void paintEvent(QPaintEvent *e) override;//绘图事件

};

#endif // QT_BUTTON_H
