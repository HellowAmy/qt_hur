#include "wid_m2.h"

wid_m2::wid_m2(QWidget *parent)
    : wid_move{parent}
{

    init_wid();
    init_signal();
}

void wid_m2::init_wid()
{
    //背景
    this->resize(820,540);
    this->set_backdrop(":/pic/backdrop_main/backrdop_move.png");

    //速度
    this->set_distance(540);
    this->set_speed(10);

    QFont font;
    font.setFamily("微软雅黑");
    font.setPixelSize(14);
    font.setWeight(QFont::Medium);

    v_col_press=QColor(0xffa924);//选中时颜色变化

    butt_m1 = new qt_button_col(this);
    butt_m1->set_pic(":/pic/m_two_left/left_1.png");
    butt_m1->move(20,55);
    butt_m1->set_col_pic(QColor(0xc3c3c3),QColor(0xffa924),QColor());
    butt_m1->set_col_font(QColor(0x444444),QColor(0xffa924),QColor());
    butt_m1->set_text("病毒防护");
    butt_m1->set_font(font);
    butt_m1->set_align(Qt::AlignLeft | Qt::AlignVCenter);
    butt_m1->set_rect(QRect(45,0,120-45,30));

    butt_m2 = new qt_button_col(this);
    butt_m2->set_pic(":/pic/m_two_left/left_2.png");
    butt_m2->move(20,55+40);
    butt_m2->set_col_pic(QColor(0xc3c3c3),QColor(0xffa924),QColor());
    butt_m2->set_col_font(QColor(0x444444),QColor(0xffa924),QColor());
    butt_m2->set_text("系统防护");
    butt_m2->set_font(font);
    butt_m2->set_align(Qt::AlignLeft | Qt::AlignVCenter);
    butt_m2->set_rect(QRect(45,0,120-45,30));

    butt_m3 = new qt_button_col(this);
    butt_m3->set_pic(":/pic/m_two_left/left_3.png");
    butt_m3->move(20,55+40+40);
    butt_m3->set_col_pic(QColor(0xc3c3c3),QColor(0xffa924),QColor());
    butt_m3->set_col_font(QColor(0x444444),QColor(0xffa924),QColor());
    butt_m3->set_text("网络防护");
    butt_m3->set_font(font);
    butt_m3->set_align(Qt::AlignLeft | Qt::AlignVCenter);
    butt_m3->set_rect(QRect(45,0,120-45,30));

    butt_m4 = new qt_button_col(this);
    butt_m4->set_pic(":/pic/m_two_left/left_4.png");
    butt_m4->move(20,487);
    butt_m4->set_col_pic(QColor(0xc3c3c3),QColor(0xffa924),QColor());
    butt_m4->set_col_font(QColor(0x444444),QColor(0xffa924),QColor());
    butt_m4->set_text("高级防护");
    butt_m4->set_font(font);
    butt_m4->set_align(Qt::AlignLeft | Qt::AlignVCenter);
    butt_m4->set_rect(QRect(45,0,120-45,30));

}

void wid_m2::init_signal()
{

    connect(butt_m1,&qt_button_col::clicked,[=](){
        set_col_butt(butt_m1);
        emit fa_press_m1();
    });

    connect(butt_m2,&qt_button_col::clicked,[=](){
        set_col_butt(butt_m2);
        emit fa_press_m2();
    });

    connect(butt_m3,&qt_button_col::clicked,[=](){
        set_col_butt(butt_m3);
        emit fa_press_m3();
    });

    connect(butt_m4,&qt_button_col::clicked,[=](){
        set_col_butt(butt_m4);
        emit fa_press_m4();
    });
}

void wid_m2::set_col_butt(qt_button_col *butt)
{
    //点击切换颜色
    butt_m1->set_col_pic(QColor(0xc3c3c3),QColor(0xffa924),QColor());
    butt_m2->set_col_pic(QColor(0xc3c3c3),QColor(0xffa924),QColor());
    butt_m3->set_col_pic(QColor(0xc3c3c3),QColor(0xffa924),QColor());
    butt_m4->set_col_pic(QColor(0xc3c3c3),QColor(0xffa924),QColor());

    butt_m1->set_col_font(QColor(0x444444),QColor(0xffa924),QColor());
    butt_m2->set_col_font(QColor(0x444444),QColor(0xffa924),QColor());
    butt_m3->set_col_font(QColor(0x444444),QColor(0xffa924),QColor());
    butt_m4->set_col_font(QColor(0x444444),QColor(0xffa924),QColor());

    butt->set_col_pic(v_col_press,QColor(0xffa924),QColor());
    butt->set_col_font(v_col_press,QColor(0xffa924),QColor());
}
