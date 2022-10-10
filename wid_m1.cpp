#include "wid_m1.h"

wid_m1::wid_m1(QWidget *parent)
    : qt_move{parent}
{
    init_wid();
    init_signal();
}

void wid_m1::init_wid()
{   
    //界面大小和背景
    this->resize(820,180);
    this->set_backdrop(":/pic/m_one/m_backdrop.png");//背景
    this->open_move_parent();//开启父类移动

    //移动速度
    this->set_distance(540-360);
    this->set_speed(2);

    butt_m1 = new qt_button_col(this);
    butt_m1->set_pic(":/pic/m_one/m_1.png");
    butt_m1->move(140,0);
    butt_m1->set_col_pic(QColor(0x848484),QColor(0xffa924),QColor(0xf17f05));
    butt_m1->set_col_font(QColor(0x444444),QColor(0xffa924),QColor(0xf17f05));
    butt_m1->set_text("全盘查杀");

    butt_m2 = new qt_button_col(this);
    butt_m2->set_pic(":/pic/m_one/m_2.png");
    butt_m2->move(350,0);
    butt_m2->set_col_pic(QColor(0x848484),QColor(0xffa924),QColor(0xf17f05));
    butt_m2->set_col_font(QColor(0x444444),QColor(0xffa924),QColor(0xf17f05));
    butt_m2->set_text("快速查杀");

    butt_m3 = new qt_button_col(this);
    butt_m3->set_pic(":/pic/m_one/m_3.png");
    butt_m3->move(560,0);
    butt_m3->set_col_pic(QColor(0x848484),QColor(0xffa924),QColor(0xf17f05));
    butt_m3->set_col_font(QColor(0x444444),QColor(0xffa924),QColor(0xf17f05));
    butt_m3->set_text("自定义查杀");

    //开启返回键
    this->set_butt_pos(QPoint(390,150));
    this->set_butt_pic(":/pic/m_one/m_back.png");
    this->set_butt_col(QColor(0x909090),QColor(0xffa924),QColor(0xf17f05));
    this->open_back();
}

void wid_m1::init_signal()
{
    connect(butt_m1,&qt_button_col::clicked,this,&wid_m1::fa_press_m1);
    connect(butt_m2,&qt_button_col::clicked,this,&wid_m1::fa_press_m2);
    connect(butt_m3,&qt_button_col::clicked,this,&wid_m1::fa_press_m3);
}
