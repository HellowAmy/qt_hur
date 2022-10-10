#include "wid_m2_2.h"

wid_m2_2::wid_m2_2(QWidget *parent)
    : QWidget{parent}
{
    init_wid();
    init_signal();
}

void wid_m2_2::init_wid()
{
    this->move(170,50);//自身相对父类偏移——wid_m2

    //将按键放入滑动区域
    butt_m1 = new wid_butt_col(this);
    butt_m1->move(30,0);
    butt_m1->set_text("针对计算机系统潜在的弱点进行防护");
    butt_m1->set_backdrop(":/pic/m_two_two/m_1.png");
    butt_m1->set_butt_text("系统加固");

    butt_m2 = new wid_butt_col(this);
    butt_m2->move(30,80 * 1);
    butt_m2->set_text("控制应用程序的行为，防止被恶意软件的利用");
    butt_m2->set_backdrop(":/pic/m_two_two/m_2.png");
    butt_m2->set_butt_text("应用加固");

    butt_m3 = new wid_butt_col(this);
    butt_m3->move(30,80 * 2);
    butt_m3->set_text("实时监控并提示软件安装行为");
    butt_m3->set_backdrop(":/pic/m_two_two/m_3.png");
    butt_m3->set_butt_text("软件安装拦截");

    butt_m4 = new wid_butt_col(this);
    butt_m4->move(30,80 * 3);
    butt_m4->set_text("发现并提示应用程序开启摄像头");
    butt_m4->set_backdrop(":/pic/m_two_two/m_4.png");
    butt_m4->set_butt_text("摄像头保护");

    butt_m5 = new wid_butt_col(this);
    butt_m5->move(30,80 * 4);
    butt_m5->set_text("保护浏览器首页和搜索不被篡改");
    butt_m5->set_backdrop(":/pic/m_two_two/m_5.png");
    butt_m5->set_butt_text("浏览器保护");

    butt_m6 = new wid_butt_col(this);
    butt_m6->move(30,80 * 5);
    butt_m6->set_text("管控应用程序的联网行为");
    butt_m6->set_backdrop(":/pic/m_two_two/m_6.png");
    butt_m6->set_butt_text("联网控制");
}

void wid_m2_2::init_signal()
{
    connect(butt_m1,&wid_butt_col::fa_press_text,this,&wid_m2_2::fa_butt_text_1);
    connect(butt_m2,&wid_butt_col::fa_press_text,this,&wid_m2_2::fa_butt_text_2);
    connect(butt_m3,&wid_butt_col::fa_press_text,this,&wid_m2_2::fa_butt_text_3);
    connect(butt_m4,&wid_butt_col::fa_press_text,this,&wid_m2_2::fa_butt_text_4);
    connect(butt_m5,&wid_butt_col::fa_press_text,this,&wid_m2_2::fa_butt_text_5);
    connect(butt_m6,&wid_butt_col::fa_press_text,this,&wid_m2_2::fa_butt_text_6);

    connect(butt_m1,&wid_butt_col::fa_press_slip,this,&wid_m2_2::fa_butt_slip_1);
    connect(butt_m2,&wid_butt_col::fa_press_slip,this,&wid_m2_2::fa_butt_slip_2);
    connect(butt_m3,&wid_butt_col::fa_press_slip,this,&wid_m2_2::fa_butt_slip_3);
    connect(butt_m4,&wid_butt_col::fa_press_slip,this,&wid_m2_2::fa_butt_slip_4);
    connect(butt_m5,&wid_butt_col::fa_press_slip,this,&wid_m2_2::fa_butt_slip_5);
    connect(butt_m6,&wid_butt_col::fa_press_slip,this,&wid_m2_2::fa_butt_slip_6);
}
