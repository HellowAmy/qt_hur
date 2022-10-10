#include "wid_m4.h"

wid_m4::wid_m4(QWidget *parent)
    : wid_move{parent}
{
    init_wid();
    init_signal();
}

void wid_m4::init_wid()
{
    //背景
    this->resize(820,540);
    this->set_backdrop(":/pic/m_four/m4_backdrop.png");

    //速度
    this->set_distance(540);
    this->set_speed(10);

    this->set_text("安全工具");// 标题

    //创建滑动区域
    wid_temp = new QWidget(this);
    area = new QScrollArea(this);
    area->resize(820-40,540-60);
    area->setWidget(wid_temp);
    area->move(40,50-1);
    area->setPalette(QColor(Qt::white));
    area->setFrameShape(QFrame::NoFrame);
    wid_temp->resize(820-40-20,310+120+90+10);//310+120+90

    label_1 = new QLabel(wid_temp);
    label_1->resize(240,40);
    label_1->setPixmap(QPixmap(":/pic/m_four/m_label_1.png"));
    label_1->move(0,0);

    butt_m1 = new wid_butt_col(wid_temp);
    butt_m1->resize(240,62);
    butt_m1->set_rect(QRect(65,35-2,240-65,62-35));
    butt_m1->set_butt_move(65,15-3);
    butt_m1->set_align(Qt::AlignLeft | Qt::AlignTop);
    butt_m1->set_backdrop(":/pic/m_four/m_1.png");
    butt_m1->set_text("扫描并修复系统漏洞");
    butt_m1->set_butt_text("漏洞修复");
    butt_m1->move(label_1->pos()+QPoint(0,label_1->height()+10));

    butt_m2 = new wid_butt_col(wid_temp);
    butt_m2->resize(240,62);
    butt_m2->set_rect(QRect(65,35-2,240-65,62-35));
    butt_m2->set_butt_move(65,15-3);
    butt_m2->set_align(Qt::AlignLeft | Qt::AlignTop);
    butt_m2->set_backdrop(":/pic/m_four/m_2.png");
    butt_m2->set_text("修复因病毒等导致的系统异常");
    butt_m2->set_butt_text("系统修复");
    butt_m2->move(butt_m1->pos()+QPoint(butt_m1->width()+10,0));

    butt_m3 = new wid_butt_col(wid_temp);
    butt_m3->resize(240,62);
    butt_m3->set_rect(QRect(65,35-2,240-65,62-35));
    butt_m3->set_butt_move(65,15-3);
    butt_m3->set_align(Qt::AlignLeft | Qt::AlignTop);
    butt_m3->set_backdrop(":/pic/m_four/m_3.png");
    butt_m3->set_text("拦截程序推送的不受欢迎弹窗");
    butt_m3->set_butt_text("弹窗拦截");
    butt_m3->move(butt_m2->pos()+QPoint(butt_m2->width()+10,0));

    butt_m4 = new wid_butt_col(wid_temp);
    butt_m4->resize(240,62);
    butt_m4->set_rect(QRect(65,35-2,240-65,62-35));
    butt_m4->set_butt_move(65,15-3);
    butt_m4->set_align(Qt::AlignLeft | Qt::AlignTop);
    butt_m4->set_backdrop(":/pic/m_four/m_4.png");
    butt_m4->set_text("清理各种系统垃圾");
    butt_m4->set_butt_text("垃圾清理");
    butt_m4->move(butt_m1->pos()+QPoint(0,butt_m1->height()+10));

    butt_m5 = new wid_butt_col(wid_temp);
    butt_m5->resize(240,62);
    butt_m5->set_rect(QRect(65,35-2,240-65,62-35));
    butt_m5->set_butt_move(65,15-3);
    butt_m5->set_align(Qt::AlignLeft | Qt::AlignTop);
    butt_m5->set_backdrop(":/pic/m_four/m_5.png");
    butt_m5->set_text("管理各种软件的开机启动");
    butt_m5->set_butt_text("启动项管理");
    butt_m5->move(butt_m4->pos()+QPoint(butt_m4->width()+10,0));

    butt_m6 = new wid_butt_col(wid_temp);
    butt_m6->resize(240,62);
    butt_m6->set_rect(QRect(65,35-2,240-65,62-35));
    butt_m6->set_butt_move(65,15-3);
    butt_m6->set_align(Qt::AlignLeft | Qt::AlignTop);
    butt_m6->set_backdrop(":/pic/m_four/m_6.png");
    butt_m6->set_text("强制删除或彻底粉碎文件");
    butt_m6->set_butt_text("文件粉碎");
    butt_m6->move(butt_m4->pos()+QPoint(butt_m4->width()+10,0));

    butt_m7 = new wid_butt_col(wid_temp);
    butt_m7->resize(240,62);
    butt_m7->set_rect(QRect(65,35-2,240-65,62-35));
    butt_m7->set_butt_move(65,15-3);
    butt_m7->set_align(Qt::AlignLeft | Qt::AlignTop);
    butt_m7->set_backdrop(":/pic/m_four/m_7.png");
    butt_m7->set_text("清理各种系统垃圾");
    butt_m7->set_butt_text("垃圾清理");
    butt_m7->move(butt_m4->pos()+QPoint(0,butt_m4->height()+10));

    label_2 = new QLabel(wid_temp);
    label_2->resize(240,40);
    label_2->setPixmap(QPixmap(":/pic/m_four/m_label_2.png"));
    label_2->move(butt_m7->pos()+QPoint(0,butt_m7->height()+20));

    butt_m8 = new wid_butt_col(wid_temp);
    butt_m8->resize(240,62);
    butt_m8->set_rect(QRect(65,35-2,240-65,62-35));
    butt_m8->set_butt_move(65,15-3);
    butt_m8->set_align(Qt::AlignLeft | Qt::AlignTop);
    butt_m8->set_backdrop(":/pic/m_four/m_8.png");
    butt_m8->set_text("检测并修复断网的问题");
    butt_m8->set_butt_text("断网修复");
    butt_m8->move(label_2->pos()+QPoint(0,label_2->height()+10));

    butt_m9 = new wid_butt_col(wid_temp);
    butt_m9->resize(240,62);
    butt_m9->set_rect(QRect(65,35-2,240-65,62-35));
    butt_m9->set_butt_move(65,15-3);
    butt_m9->set_align(Qt::AlignLeft | Qt::AlignTop);
    butt_m9->set_backdrop(":/pic/m_four/m_9.png");
    butt_m9->set_text("检测及控制程序的网络流量");
    butt_m9->set_butt_text("流量控制");
    butt_m9->move(butt_m8->pos()+QPoint(butt_m8->width()+10,0));

    butt_m10 = new wid_butt_col(wid_temp);
    butt_m10->resize(240,62);
    butt_m10->set_rect(QRect(65,35-2,240-65,62-35));
    butt_m10->set_butt_move(65,15-3);
    butt_m10->set_align(Qt::AlignLeft | Qt::AlignTop);
    butt_m10->set_backdrop(":/pic/m_four/m_10.png");
    butt_m10->set_text("修改负责域名快速解析的文件");
    butt_m10->set_butt_text("修改HOST文件");
    butt_m10->move(butt_m9->pos()+QPoint(butt_m9->width()+10,0));

    label_3 = new QLabel(wid_temp);
    label_3->resize(240,40);
    label_3->setPixmap(QPixmap(":/pic/m_four/m_label_3.png"));
    label_3->move(butt_m8->pos()+QPoint(0,butt_m8->height()+20));

    butt_m11 = new wid_butt_col(wid_temp);
    butt_m11->resize(240,62);
    butt_m11->set_rect(QRect(65,35-2,240-65,62-35));
    butt_m11->set_butt_move(65,15-3);
    butt_m11->set_align(Qt::AlignLeft | Qt::AlignTop);
    butt_m11->set_backdrop(":/pic/m_four/m_11.png");
    butt_m11->set_text("安全专业人士的分析工具");
    butt_m11->set_butt_text("火绒剑");
    butt_m11->move(label_3->pos()+QPoint(0,label_3->height()+10));

    butt_m12 = new wid_butt_col(wid_temp);
    butt_m12->resize(240,62);
    butt_m12->set_rect(QRect(65,35-2,240-65,62-35));
    butt_m12->set_butt_move(65,15-3);
    butt_m12->set_align(Qt::AlignLeft | Qt::AlignTop);
    butt_m12->set_backdrop(":/pic/m_four/m_12.png");
    butt_m12->set_text("查杀各类恶性顽固病毒");
    butt_m12->set_butt_text("专杀工具");
    butt_m12->move(butt_m11->pos()+QPoint(butt_m11->width()+10,0));

}

void wid_m4::init_signal()
{
    connect(butt_m1,&wid_butt_col::fa_press_text,this,&wid_m4::fa_butt_text_1);
    connect(butt_m2,&wid_butt_col::fa_press_text,this,&wid_m4::fa_butt_text_2);
    connect(butt_m3,&wid_butt_col::fa_press_text,this,&wid_m4::fa_butt_text_3);
    connect(butt_m4,&wid_butt_col::fa_press_text,this,&wid_m4::fa_butt_text_4);
    connect(butt_m5,&wid_butt_col::fa_press_text,this,&wid_m4::fa_butt_text_5);
    connect(butt_m6,&wid_butt_col::fa_press_text,this,&wid_m4::fa_butt_text_6);
    connect(butt_m7,&wid_butt_col::fa_press_text,this,&wid_m4::fa_butt_text_7);
    connect(butt_m8,&wid_butt_col::fa_press_text,this,&wid_m4::fa_butt_text_8);
    connect(butt_m9,&wid_butt_col::fa_press_text,this,&wid_m4::fa_butt_text_9);
    connect(butt_m10,&wid_butt_col::fa_press_text,this,&wid_m4::fa_butt_text_10);
    connect(butt_m11,&wid_butt_col::fa_press_text,this,&wid_m4::fa_butt_text_11);
    connect(butt_m12,&wid_butt_col::fa_press_text,this,&wid_m4::fa_butt_text_12);
}
