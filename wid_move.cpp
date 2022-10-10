#include "wid_move.h"

wid_move::wid_move(QWidget *parent)
    : qt_move{parent}
{
    init_wid();
    init_signal();
}

void wid_move::set_text(QString text)
{
    v_text=text;
}

void wid_move::set_rect(QRect rect)
{
    v_rect=rect;
}

void wid_move::set_font(QFont font, QColor col)
{
    v_font=font;
    v_col=col;
}

void wid_move::init_wid()
{
    this->resize(820,540);


    //文字样式
    v_font.setFamily("微软雅黑");
    v_font.setPointSize(12);
    v_font.setWeight(QFont::Medium);

    v_text="防护中心";//文字
    v_col=0x303030;//文字颜色
    v_rect=QRect(0,0,820,40);//文字范围

    //速度
    this->set_distance(540);
    this->set_speed(3);

    //开启返回键
    this->set_butt_pos(QPoint(703-36,8));
    this->set_butt_pic(":/pic/close/c_back.png");
    this->set_butt_col_back(QColor(0xf8f9f9),QColor(0xdfe0e0),QColor(0xd0d1d1));
    this->open_back();

    //关闭按钮
    this->open_butt();
    this->butt_c1->set_pic(":/pic/close/c_1.png");
    this->butt_c1->move(703,8);
    this->butt_c1->set_col_pic_back(QColor(0xf8f9f9),QColor(0xdfe0e0),QColor(0xd0d1d1));

    this->butt_c2->set_pic(":/pic/close/c_2.png");
    this->butt_c2->move(703+36 * 1,8);
    this->butt_c2->set_col_pic_back(QColor(0xf8f9f9),QColor(0xdfe0e0),QColor(0xd0d1d1));

    this->butt_c3->set_pic(":/pic/close/c_3.png");
    this->butt_c3->move(703+36 * 2,8);
    this->butt_c3->set_col_pic_back(QColor(0xf8f9f9),QColor(0xf26223),QColor(0xdf4c0b));
    this->butt_c3->set_col_pic(QColor(0x909090),QColor(0xfbcab5),QColor(0xfbcab5));
}

void wid_move::init_signal()
{

}

void wid_move::paintEvent(QPaintEvent *event)
{
    qt_move::paintEvent(event);//继承父类背景

    //绘制文字
    QPainter *show=new QPainter(this);
    show->setPen(QColor(v_col));
    show->setFont(v_font);
    show->drawText(v_rect, Qt::AlignCenter, v_text);
    show->end();
}
