#include "wid_m2_4.h"

wid_m2_4::wid_m2_4(QWidget *parent)
    : QWidget{parent}
{
    init_wid();
    init_signal();
}

void wid_m2_4::init_wid()
{
    this->move(170,50);//自身相对父类偏移——wid_m2

    //将按键放入滑动区域
    butt_m1 = new wid_butt_col(this);
    butt_m1->move(30,0);
    butt_m1->set_text("对文件、注册表以及程序的执行进行控制以及防护");
    butt_m1->set_backdrop(":/pic/m_two_four/m_1.png");
    butt_m1->set_butt_text("自定义防护");

    butt_m2 = new wid_butt_col(this);
    butt_m2->move(30,80 * 1);
    butt_m2->set_text("限制对指定IP的出站、入站请求");
    butt_m2->set_backdrop(":/pic/m_two_four/m_2.png");
    butt_m2->set_butt_text("IP黑名单");

    butt_m3 = new wid_butt_col(this);
    butt_m3->move(30,80 * 2);
    butt_m3->set_text("在IP协议层进行网络访问控制");
    butt_m3->set_backdrop(":/pic/m_two_four/m_3.png");
    butt_m3->set_butt_text("IP协议控制");
}

void wid_m2_4::init_signal()
{
    connect(butt_m1,&wid_butt_col::fa_press_text,this,&wid_m2_4::fa_butt_text_1);
    connect(butt_m2,&wid_butt_col::fa_press_text,this,&wid_m2_4::fa_butt_text_2);
    connect(butt_m3,&wid_butt_col::fa_press_text,this,&wid_m2_4::fa_butt_text_3);

    connect(butt_m1,&wid_butt_col::fa_press_slip,this,&wid_m2_4::fa_butt_slip_1);
    connect(butt_m2,&wid_butt_col::fa_press_slip,this,&wid_m2_4::fa_butt_slip_2);
    connect(butt_m3,&wid_butt_col::fa_press_slip,this,&wid_m2_4::fa_butt_slip_3);
}
