#include "wid_menu_dig.h"

wid_menu_dig::wid_menu_dig(QWidget *parent)
    : QDialog{parent}
{
    init_wid();
    init_signal();
}

void wid_menu_dig::set_pos(QPoint pos)
{
    this->move(pos);
    this->show();
}

void wid_menu_dig::init_wid()
{
    this->resize(132,30*9);//设置界面大小
    this->setWindowFlags(Qt::FramelessWindowHint | Qt::Dialog);//无边框

    c1 = new qt_button_col(this);
    c1->move(0,0);
    c1->set_pic(":/pic/c_one/c_one_1.png");
    c1->set_col_pic(QColor(0x909090),QColor(0xffffff),QColor());
    c1->set_col_pic_back(QColor(0xffffff),QColor(0xffa924),QColor());
    c1->set_col_font(QColor(0x444444),QColor(0xffffff),QColor());
    c1->set_align(Qt::AlignLeft | Qt::AlignVCenter);
    c1->set_rect(QRect(37,0,124,28));
    c1->set_font(QFont("微软雅黑",9));
    c1->set_text("安全设置");

    c2 = new qt_button_col(this);
    c2->move(0,30* 1);
    c2->set_pic(":/pic/c_one/c_one_2.png");
    c2->set_col_pic(QColor(0x909090),QColor(0xffffff),QColor());
    c2->set_col_pic_back(QColor(0xffffff),QColor(0xffa924),QColor());
    c2->set_col_font(QColor(0x444444),QColor(0xffffff),QColor());
    c2->set_align(Qt::AlignLeft | Qt::AlignVCenter);
    c2->set_rect(QRect(37,0,124,28));
    c2->set_font(QFont("微软雅黑",9));
    c2->set_text("安全日志");

    c3 = new qt_button_col(this);
    c3->move(0,30* 2);
    c3->set_pic(":/pic/c_one/c_one_3.png");
    c3->set_col_pic(QColor(0x909090),QColor(0xffffff),QColor());
    c3->set_col_pic_back(QColor(0xffffff),QColor(0xffa924),QColor());
    c3->set_col_font(QColor(0x444444),QColor(0xffffff),QColor());
    c3->set_align(Qt::AlignLeft | Qt::AlignVCenter);
    c3->set_rect(QRect(37,0,124,28));
    c3->set_font(QFont("微软雅黑",9));
    c3->set_text("隔离区");

    c4 = new qt_button_col(this);
    c4->move(0,30* 3);
    c4->set_pic(":/pic/c_one/c_one_4.png");
    c4->set_col_pic(QColor(0x909090),QColor(0xffffff),QColor());
    c4->set_col_pic_back(QColor(0xffffff),QColor(0xffa924),QColor());
    c4->set_col_font(QColor(0x444444),QColor(0xffffff),QColor());
    c4->set_align(Qt::AlignLeft | Qt::AlignVCenter);
    c4->set_rect(QRect(37,0,124,28));
    c4->set_font(QFont("微软雅黑",9));
    c4->set_text("信任区");

    c5 = new qt_button_col(this);
    c5->move(0,30* 4);
    c5->set_pic(":/pic/c_one/c_one_5.png");
    c5->set_col_pic(QColor(0x909090),QColor(0xffffff),QColor());
    c5->set_col_pic_back(QColor(0xffffff),QColor(0xffa924),QColor());
    c5->set_col_font(QColor(0x444444),QColor(0xffffff),QColor());
    c5->set_align(Qt::AlignLeft | Qt::AlignVCenter);
    c5->set_rect(QRect(37,0,124,28));
    c5->set_font(QFont("微软雅黑",9));
    c5->set_text("检查更新");

    c6 = new qt_button_col(this);
    c6->move(0,30* 5);
    c6->set_pic(":/pic/c_one/c_one_6.png");
    c6->set_col_pic(QColor(0x909090),QColor(0xffffff),QColor());
    c6->set_col_pic_back(QColor(0xffffff),QColor(0xffa924),QColor());
    c6->set_col_font(QColor(0x444444),QColor(0xffffff),QColor());
    c6->set_align(Qt::AlignLeft | Qt::AlignVCenter);
    c6->set_rect(QRect(37,0,124,28));
    c6->set_font(QFont("微软雅黑",9));
    c6->set_text("语言设置");

    c7 = new qt_button_col(this);
    c7->move(0,30* 6);
    c7->set_pic(":/pic/c_one/c_one_7.png");
    c7->set_col_pic(QColor(0x909090),QColor(0xffffff),QColor());
    c7->set_col_pic_back(QColor(0xffffff),QColor(0xffa924),QColor());
    c7->set_col_font(QColor(0x444444),QColor(0xffffff),QColor());
    c7->set_align(Qt::AlignLeft | Qt::AlignVCenter);
    c7->set_rect(QRect(37,0,124,28));
    c7->set_font(QFont("微软雅黑",9));
    c7->set_text("问题反馈");

    c8 = new qt_button_col(this);
    c8->move(0,30* 7);
    c8->set_pic(":/pic/c_one/c_one_8.png");
    c8->set_col_pic(QColor(0x909090),QColor(0xffffff),QColor());
    c8->set_col_pic_back(QColor(0xffffff),QColor(0xffa924),QColor());
    c8->set_col_font(QColor(0x444444),QColor(0xffffff),QColor());
    c8->set_align(Qt::AlignLeft | Qt::AlignVCenter);
    c8->set_rect(QRect(37,0,124,28));
    c8->set_font(QFont("微软雅黑",9));
    c8->set_text("病毒上报");

    c9 = new qt_button_col(this);
    c9->move(0,30* 8);
    c9->set_pic(":/pic/c_one/c_one_9.png");
    c9->set_col_pic(QColor(0x909090),QColor(0xffffff),QColor());
    c9->set_col_pic_back(QColor(0xffffff),QColor(0xffa924),QColor());
    c9->set_col_font(QColor(0x444444),QColor(0xffffff),QColor());
    c9->set_align(Qt::AlignLeft | Qt::AlignVCenter);
    c9->set_rect(QRect(37,0,124,28));
    c9->set_font(QFont("微软雅黑",9));
    c9->set_text("关于我们");
}

void wid_menu_dig::init_signal()
{
    connect(c1,&qt_button_col::clicked,this,&wid_menu_dig::fa_press_c1);
    connect(c2,&qt_button_col::clicked,this,&wid_menu_dig::fa_press_c2);
    connect(c3,&qt_button_col::clicked,this,&wid_menu_dig::fa_press_c3);
    connect(c4,&qt_button_col::clicked,this,&wid_menu_dig::fa_press_c4);
    connect(c5,&qt_button_col::clicked,this,&wid_menu_dig::fa_press_c5);
    connect(c6,&qt_button_col::clicked,this,&wid_menu_dig::fa_press_c6);
    connect(c7,&qt_button_col::clicked,this,&wid_menu_dig::fa_press_c7);
    connect(c8,&qt_button_col::clicked,this,&wid_menu_dig::fa_press_c8);
    connect(c9,&qt_button_col::clicked,this,&wid_menu_dig::fa_press_c9);
}
