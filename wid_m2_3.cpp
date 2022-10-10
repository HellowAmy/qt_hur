#include "wid_m2_3.h"

wid_m2_3::wid_m2_3(QWidget *parent)
    : QWidget{parent}
{
    init_wid();
    init_signal();
}

void wid_m2_3::init_wid()
{
    this->move(170,50);//自身相对父类偏移——wid_m2


    //创建滑动区域
    wid_temp = new QWidget(this);
    area = new QScrollArea(this);
    area->resize(650,470);
    area->setWidget(wid_temp);
    area->setPalette(QColor(Qt::white));
    area->setFrameShape(QFrame::NoFrame);
    wid_temp->resize(650-20,550);

    //将按键放入滑动区域
    butt_m1 = new wid_butt_col(wid_temp);
    butt_m1->move(30,0);
    butt_m1->set_text("在网络层拦截漏洞攻击、黑客入侵等威胁");
    butt_m1->set_backdrop(":/pic/m_two_three/m_1.png");
    butt_m1->set_butt_text("网络入侵拦截");

    butt_m2 = new wid_butt_col(wid_temp);
    butt_m2->move(30,80 * 1);
    butt_m2->set_text("在网络层拦截横向渗透攻击");
    butt_m2->set_backdrop(":/pic/m_two_three/m_2.png");
    butt_m2->set_butt_text("横向渗透防护");

    butt_m3 = new wid_butt_col(wid_temp);
    butt_m3->move(30,80 * 2);
    butt_m3->set_text("在网络层拦截本机对外部计算机的漏洞攻击行为");
    butt_m3->set_backdrop(":/pic/m_two_three/m_3.png");
    butt_m3->set_butt_text("对外攻击拦截");

    butt_m4 = new wid_butt_col(wid_temp);
    butt_m4->move(30,80 * 3);
    butt_m4->set_text("在网络层拦截潜在后门攻击");
    butt_m4->set_backdrop(":/pic/m_two_three/m_4.png");
    butt_m4->set_butt_text("僵尸网络防护");

    butt_m5 = new wid_butt_col(wid_temp);
    butt_m5->move(30,80 * 4);
    butt_m5->set_text("发现爆破攻击行为，拦截潜在暴力破解攻击");
    butt_m5->set_backdrop(":/pic/m_two_three/m_5.png");
    butt_m5->set_butt_text("爆破攻击防护");

    butt_m6 = new wid_butt_col(wid_temp);
    butt_m6->move(30,80 * 5);
    butt_m6->set_text("针对高危Web服务漏洞渗透攻击进行防护");
    butt_m6->set_backdrop(":/pic/m_two_three/m_6.png");
    butt_m6->set_butt_text("Web服务保护");

    butt_m7 = new wid_butt_col(wid_temp);
    butt_m7->move(30,80 * 6);
    butt_m7->set_text("自动阻止木马、欺诈、钓鱼类等网站");
    butt_m7->set_backdrop(":/pic/m_two_three/m_7.png");
    butt_m7->set_butt_text("恶意网址拦截");
}

void wid_m2_3::init_signal()
{
    connect(butt_m1,&wid_butt_col::fa_press_text,this,&wid_m2_3::fa_butt_text_1);
    connect(butt_m2,&wid_butt_col::fa_press_text,this,&wid_m2_3::fa_butt_text_2);
    connect(butt_m3,&wid_butt_col::fa_press_text,this,&wid_m2_3::fa_butt_text_3);
    connect(butt_m4,&wid_butt_col::fa_press_text,this,&wid_m2_3::fa_butt_text_4);
    connect(butt_m5,&wid_butt_col::fa_press_text,this,&wid_m2_3::fa_butt_text_5);
    connect(butt_m6,&wid_butt_col::fa_press_text,this,&wid_m2_3::fa_butt_text_6);
    connect(butt_m7,&wid_butt_col::fa_press_text,this,&wid_m2_3::fa_butt_text_7);

    connect(butt_m1,&wid_butt_col::fa_press_slip,this,&wid_m2_3::fa_butt_slip_1);
    connect(butt_m2,&wid_butt_col::fa_press_slip,this,&wid_m2_3::fa_butt_slip_2);
    connect(butt_m3,&wid_butt_col::fa_press_slip,this,&wid_m2_3::fa_butt_slip_3);
    connect(butt_m4,&wid_butt_col::fa_press_slip,this,&wid_m2_3::fa_butt_slip_4);
    connect(butt_m5,&wid_butt_col::fa_press_slip,this,&wid_m2_3::fa_butt_slip_5);
    connect(butt_m6,&wid_butt_col::fa_press_slip,this,&wid_m2_3::fa_butt_slip_6);
    connect(butt_m7,&wid_butt_col::fa_press_slip,this,&wid_m2_3::fa_butt_slip_7);
}
