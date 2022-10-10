#include "wid_m2_1.h"

wid_m2_1::wid_m2_1(QWidget *parent)
    : QWidget{parent}
{
    init_wid();
    init_signal();
}

void wid_m2_1::init_wid()
{
    this->move(170,50);//自身相对父类偏移——wid_m2

    //将按键放入滑动区域
    butt_m1 = new wid_butt_col(this);
    butt_m1->move(30,0);
    butt_m1->set_text("当文件被执行、创建、打开时，进行病毒扫描");
    butt_m1->set_backdrop(":/pic/m_two_one/m_1.png");
    butt_m1->set_butt_text("文件实时监控");

    butt_m2 = new wid_butt_col(this);
    butt_m2->move(30,80 * 1);
    butt_m2->set_text("监控程序在运行过程中，是否有恶意行为");
    butt_m2->set_backdrop(":/pic/m_two_one/m_2.png");
    butt_m2->set_butt_text("恶意行为监控");

    butt_m3 = new wid_butt_col(this);
    butt_m3->move(30,80 * 2);
    butt_m3->set_text("在接入U盘时，自动对U盘根目录下的文件进行扫描");
    butt_m3->set_backdrop(":/pic/m_two_one/m_3.png");
    butt_m3->set_butt_text("U盘保护");

    butt_m4 = new wid_butt_col(this);
    butt_m4->move(30,80 * 3);
    butt_m4->set_text("实时扫描通过浏览器，即时通讯软件下载的文件");
    butt_m4->set_backdrop(":/pic/m_two_one/m_4.png");
    butt_m4->set_butt_text("下载保护");

    butt_m5 = new wid_butt_col(this);
    butt_m5->move(30,80 * 4);
    butt_m5->set_text("对邮件客户端收发的邮件及附件进行病毒扫描");
    butt_m5->set_backdrop(":/pic/m_two_one/m_5.png");
    butt_m5->set_butt_text("邮件监控");

    butt_m6 = new wid_butt_col(this);
    butt_m6->move(30,80 * 5);
    butt_m6->set_text("对HTTP协议接收的数据进行病毒扫描");
    butt_m6->set_backdrop(":/pic/m_two_one/m_6.png");
    butt_m6->set_butt_text("Web扫描");
}

void wid_m2_1::init_signal()
{
    connect(butt_m1,&wid_butt_col::fa_press_text,this,&wid_m2_1::fa_butt_text_1);
    connect(butt_m2,&wid_butt_col::fa_press_text,this,&wid_m2_1::fa_butt_text_2);
    connect(butt_m3,&wid_butt_col::fa_press_text,this,&wid_m2_1::fa_butt_text_3);
    connect(butt_m4,&wid_butt_col::fa_press_text,this,&wid_m2_1::fa_butt_text_4);
    connect(butt_m5,&wid_butt_col::fa_press_text,this,&wid_m2_1::fa_butt_text_5);
    connect(butt_m6,&wid_butt_col::fa_press_text,this,&wid_m2_1::fa_butt_text_6);

    connect(butt_m1,&wid_butt_col::fa_press_slip,this,&wid_m2_1::fa_butt_slip_1);
    connect(butt_m2,&wid_butt_col::fa_press_slip,this,&wid_m2_1::fa_butt_slip_2);
    connect(butt_m3,&wid_butt_col::fa_press_slip,this,&wid_m2_1::fa_butt_slip_3);
    connect(butt_m4,&wid_butt_col::fa_press_slip,this,&wid_m2_1::fa_butt_slip_4);
    connect(butt_m5,&wid_butt_col::fa_press_slip,this,&wid_m2_1::fa_butt_slip_5);
    connect(butt_m6,&wid_butt_col::fa_press_slip,this,&wid_m2_1::fa_butt_slip_6);
}
