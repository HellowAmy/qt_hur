#include "wid_m3.h"

wid_m3::wid_m3(QWidget *parent)
    : wid_move{parent}
{
    init_wid();
    init_signal();
}

void wid_m3::init_wid()
{
    //背景
    this->resize(820,540);
    this->set_backdrop(":/pic/m_three/m3_backdrop_text.png");

    //速度
    this->set_distance(540);
    this->set_speed(10);

    this->set_text("访问控制");// 标题

    //文字按钮默认设置
    QFont font;
    font.setFamily("微软雅黑");
    font.setPixelSize(14);

    butt_text = new qt_button_text(this);
    butt_text->move(722,70);
    butt_text->set_text("密码保护",font);
    butt_text->set_col(QColor(0xf17f05),QColor(0xffa96d),QColor(0xea4c0b));

    butt_m1 = new wid_butt_col(this);
    butt_m1->move(40,160);
    butt_m1->set_text("控制计算机上网的时间段或者累计的上网时长");
    butt_m1->set_backdrop(":/pic/m_three/m_1.png");
    butt_m1->set_butt_text("上网时段控制");
    butt_m1->resize(360,90);
    butt_m1->set_rect(QRect(80,50,360-80,90-50));
    butt_m1->set_butt_move(80,25);
    butt_m1->set_butt_slip_move(300,20);
    butt_m1->set_butt_slip_min();

    butt_m2 = new wid_butt_col(this);
    butt_m2->move(40 + 20 + 360 * 1 ,160);
    butt_m2->set_text("限制计算机访问特定类型网站");
    butt_m2->set_backdrop(":/pic/m_three/m_2.png");
    butt_m2->set_butt_text("网站内容控制");
    butt_m2->resize(360,90);
    butt_m2->set_rect(QRect(80,50,360-80,90-50));
    butt_m2->set_butt_move(80,25);
    butt_m2->set_butt_slip_move(300,20);
    butt_m2->set_butt_slip_min();

    butt_m3 = new wid_butt_col(this);
    butt_m3->move(40,160 + 20 + 90 * 1);
    butt_m3->set_text("限制指定应用程序的执行");
    butt_m3->set_backdrop(":/pic/m_three/m_3.png");
    butt_m3->set_butt_text("程序执行控制");
    butt_m3->resize(360,90);
    butt_m3->set_rect(QRect(80,50,360-80,90-50));
    butt_m3->set_butt_move(80,25);
    butt_m3->set_butt_slip_move(300,20);
    butt_m3->set_butt_slip_min();

    butt_m4 = new wid_butt_col(this);
    butt_m4->move(40 + 20 + 360 * 1,160 + 20 + 90 * 1);
    butt_m4->set_text("限制未信任的U盘接入计算机");
    butt_m4->set_backdrop(":/pic/m_three/m_4.png");
    butt_m4->set_butt_text("U盘使用控制");
    butt_m4->resize(360,90);
    butt_m4->set_rect(QRect(80,50,360-80,90-50));
    butt_m4->set_butt_move(80,25);
    butt_m4->set_butt_slip_move(300,20);
    butt_m4->set_butt_slip_min();


}

void wid_m3::init_signal()
{
    connect(butt_m1,&wid_butt_col::fa_press_text,this,&wid_m3::fa_butt_text_1);
    connect(butt_m2,&wid_butt_col::fa_press_text,this,&wid_m3::fa_butt_text_2);
    connect(butt_m3,&wid_butt_col::fa_press_text,this,&wid_m3::fa_butt_text_3);
    connect(butt_m4,&wid_butt_col::fa_press_text,this,&wid_m3::fa_butt_text_4);

    connect(butt_m1,&wid_butt_col::fa_press_slip,this,&wid_m3::fa_butt_slip_1);
    connect(butt_m2,&wid_butt_col::fa_press_slip,this,&wid_m3::fa_butt_slip_2);
    connect(butt_m3,&wid_butt_col::fa_press_slip,this,&wid_m3::fa_butt_slip_3);
    connect(butt_m4,&wid_butt_col::fa_press_slip,this,&wid_m3::fa_butt_slip_4);

    connect(butt_text,&qt_button_text::clicked,this,&wid_m3::fa_bott_text_press);
}
