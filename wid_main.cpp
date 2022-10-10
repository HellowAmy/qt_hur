#include "wid_main.h"

wid_main::wid_main(QWidget *parent)
    : qt_frameless{parent}
{
    init_wid();
    init_signal();
}

void wid_main::init_wid()
{
    this->resize(820,540);
    this->set_backdrop(":/pic/backdrop_main/backdrop.png");//背景

    //主按键
    butt_m1 = new qt_button_col(this);
    butt_m1->set_pic(":/pic/main_butt/m_1.png");
    butt_m1->move(71,360);
    butt_m1->set_col_pic(QColor(0x848484),QColor(0xffa924),QColor(0xf17f05));
    butt_m1->set_col_font(QColor(0x444444),QColor(0xffa924),QColor(0xf17f05));
    butt_m1->set_text("病毒查杀");

    butt_m2 = new qt_button_col(this);
    butt_m2->set_pic(":/pic/main_butt/m_2.png");
    butt_m2->move(257,360);
    butt_m2->set_col_pic(QColor(0x848484),QColor(0xffa924),QColor(0xf17f05));
    butt_m2->set_col_font(QColor(0x444444),QColor(0xffa924),QColor(0xf17f05));
    butt_m2->set_text("防护中心");

    butt_m3 = new qt_button_col(this);
    butt_m3->set_pic(":/pic/main_butt/m_3.png");
    butt_m3->move(441,360);
    butt_m3->set_col_pic(QColor(0x848484),QColor(0xffa924),QColor(0xf17f05));
    butt_m3->set_col_font(QColor(0x444444),QColor(0xffa924),QColor(0xf17f05));
    butt_m3->set_text("访问控制");

    butt_m4 = new qt_button_col(this);
    butt_m4->set_pic(":/pic/main_butt/m_4.png");
    butt_m4->move(627,360);
    butt_m4->set_col_pic(QColor(0x848484),QColor(0xffa924),QColor(0xf17f05));
    butt_m4->set_col_font(QColor(0x444444),QColor(0xffa924),QColor(0xf17f05));
    butt_m4->set_text("安全工具");

    //关闭按钮
    this->open_butt();
    this->butt_c1->move(703,8);
    this->butt_c1->set_pic(":/pic/close/c_1.png");
    this->butt_c1->set_col_pic_back(QColor(0xe4d9c5),QColor(0xcdc4b2),QColor(0xbfb7a5));

    this->butt_c2->move(703+36 * 1,8);
    this->butt_c2->set_pic(":/pic/close/c_2.png");
    this->butt_c2->set_col_pic_back(QColor(0xe4d9c5),QColor(0xcdc4b2),QColor(0xbfb7a5));

    this->butt_c3->move(703+36 * 2,8);
    this->butt_c3->set_pic(":/pic/close/c_3.png");
    this->butt_c3->set_col_pic_back(QColor(0xe4d9c5),QColor(0xf26223),QColor(0xdf4c0b));
    this->butt_c3->set_col_pic(QColor(0x909090),QColor(0xfbcab5),QColor(0xfbcab5));
}

void wid_main::init_signal()
{
    //传递主按键信号
    connect(butt_m1,&qt_button_col::clicked,this,&wid_main::fa_press_m1);
    connect(butt_m2,&qt_button_col::clicked,this,&wid_main::fa_press_m2);
    connect(butt_m3,&qt_button_col::clicked,this,&wid_main::fa_press_m3);
    connect(butt_m4,&qt_button_col::clicked,this,&wid_main::fa_press_m4);
}
