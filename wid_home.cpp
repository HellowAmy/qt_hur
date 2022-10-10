#include "wid_home.h"

wid_home::wid_home(QWidget *parent)
    : qt_frameless{parent}
{
    this->resize(820,540);

    init_wid();
    init_signal();
}

void wid_home::init_wid()
{
    //主界面
    w_main=new wid_main(this);
    w_main->open_move_parent();
    w_main->show();

    //选择菜单
    w_dig =  new wid_menu_dig(this);
    w_dig->hide();

    //m1按钮界面
    butt_m1 = new wid_m1(this);
    butt_m1->move(0,540);

    //m2按钮界面
    butt_m2 = new wid_m2(this);
    butt_m2->open_rect(QRect(QPoint(0,0),QPoint(820,40)));
    butt_m2->open_move_parent();
    butt_m2->move(0,540);

    //m3按钮界面
    butt_m3 = new wid_m3(this);
    butt_m3->open_rect(QRect(QPoint(0,0),QPoint(820,40)));
    butt_m3->open_move_parent();
    butt_m3->move(0,540);

    //m4按钮界面
    butt_m4 = new wid_m4(this);
    butt_m4->open_rect(QRect(QPoint(0,0),QPoint(820,40)));
    butt_m4->open_move_parent();
    butt_m4->move(0,540);

    init_m2();//初始化m2下的子界面
}

void wid_home::init_signal()
{
    signal_show_menu();
    signal_main();
    signal_m1();
    signal_m2();
    signal_m3();
    signal_m4();

}

void wid_home::init_m2()
{
    //m2_1按钮界面
    butt_m2_1 = new wid_m2_1(butt_m2);
    butt_m2_1->hide();

    //m2_2按钮界面
    butt_m2_2 = new wid_m2_2(butt_m2);
    butt_m2_2->hide();

    //m2_3按钮界面
    butt_m2_3 = new wid_m2_3(butt_m2);
    butt_m2_3->hide();

    //m2_4按钮界面
    butt_m2_4 = new wid_m2_4(butt_m2);
    butt_m2_4->hide();
}

void wid_home::signal_show_menu()
{
    //点击显示菜单
    connect(w_main,&wid_main::fa_menu,this,&wid_home::cao_show_menu);
    connect(butt_m1,&wid_main::fa_menu,this,&wid_home::cao_show_menu);
    connect(butt_m2,&wid_main::fa_menu,this,&wid_home::cao_show_menu);
    connect(butt_m3,&wid_main::fa_menu,this,&wid_home::cao_show_menu);
    connect(butt_m4,&wid_main::fa_menu,this,&wid_home::cao_show_menu);

    //点击隐藏——点击窗口
    connect(w_main,&wid_main::fa_press,this,&wid_home::cao_hide_menu);
    connect(butt_m1,&wid_main::fa_press,this,&wid_home::cao_hide_menu);
    connect(butt_m2,&wid_main::fa_press,this,&wid_home::cao_hide_menu);
    connect(butt_m3,&wid_main::fa_press,this,&wid_home::cao_hide_menu);
    connect(butt_m4,&wid_main::fa_press,this,&wid_home::cao_hide_menu);

    //点击隐藏——返回
    connect(butt_m1,&qt_move::fa_back,this,&wid_home::cao_hide_menu);
    connect(butt_m2,&qt_move::fa_back,this,&wid_home::cao_hide_menu);
    connect(butt_m3,&qt_move::fa_back,this,&wid_home::cao_hide_menu);
    connect(butt_m4,&qt_move::fa_back,this,&wid_home::cao_hide_menu);

    //点击隐藏——最小化
    connect(butt_m1,&qt_move::fa_min,this,&wid_home::cao_hide_menu);
    connect(butt_m2,&qt_move::fa_min,this,&wid_home::cao_hide_menu);
    connect(butt_m3,&qt_move::fa_min,this,&wid_home::cao_hide_menu);
    connect(butt_m4,&qt_move::fa_min,this,&wid_home::cao_hide_menu);

}

void wid_home::signal_m1()
{
    //m1-1按钮
    connect(butt_m1,&wid_m1::fa_press_m1,[=](){
        out<<"全盘查杀";
    });

    //m1-2按钮
    connect(butt_m1,&wid_m1::fa_press_m2,[=](){
        out<<"快速查杀";
    });

    //m1-3按钮
    connect(butt_m1,&wid_m1::fa_press_m3,[=](){
        out<<"自定义查杀";
    });
}

void wid_home::signal_m2()
{
    //m2_1按钮
    connect(butt_m2,&wid_m2::fa_press_m1,this,[=](){
        cao_show_m2(1);
        out<<"butt_m2_1";
    });

    //m2_2按钮
    connect(butt_m2,&wid_m2::fa_press_m2,this,[=](){
        cao_show_m2(2);
        out<<"butt_m2_2";
    });

    //m2_3按钮
    connect(butt_m2,&wid_m2::fa_press_m3,this,[=](){
        cao_show_m2(3);
        out<<"butt_m2_3";
    });

    //m2_4按钮
    connect(butt_m2,&wid_m2::fa_press_m4,this,[=](){
        cao_show_m2(4);
        out<<"butt_m2_4";
    });

    signal_m2_1();
    signal_m2_2();
    signal_m2_3();
    signal_m2_4();

}

void wid_home::signal_m3()
{
    //滑动按钮
    connect(butt_m3,&wid_m3::fa_butt_slip_1,[=](){
        out<<"fa_butt_slip_1";
    });

    connect(butt_m3,&wid_m3::fa_butt_slip_2,[=](){
        out<<"fa_butt_slip_2";
    });

    connect(butt_m3,&wid_m3::fa_butt_slip_3,[=](){
        out<<"fa_butt_slip_3";
    });

    connect(butt_m3,&wid_m3::fa_butt_slip_4,[=](){
        out<<"fa_butt_slip_4";
    });


    //文字按钮
    connect(butt_m3,&wid_m3::fa_butt_text_1,[=](){
        out<<"fa_butt_text_1";
    });

    connect(butt_m3,&wid_m3::fa_butt_text_2,[=](){
        out<<"fa_butt_text_2";
    });

    connect(butt_m3,&wid_m3::fa_butt_text_3,[=](){
        out<<"fa_butt_text_3";
    });

    connect(butt_m3,&wid_m3::fa_butt_text_4,[=](){
        out<<"fa_butt_text_4";
    });

    connect(butt_m3,&wid_m3::fa_bott_text_press,[=](){
        out<<"fa_bott_text_press";
    });

}

void wid_home::signal_m4()
{
    //文字按钮
    connect(butt_m4,&wid_m4::fa_butt_text_1,[=](){
        out<<"fa_butt_text_1";
    });

    connect(butt_m4,&wid_m4::fa_butt_text_2,[=](){
        out<<"fa_butt_text_2";
    });

    connect(butt_m4,&wid_m4::fa_butt_text_3,[=](){
        out<<"fa_butt_text_3";
    });

    connect(butt_m4,&wid_m4::fa_butt_text_4,[=](){
        out<<"fa_butt_text_4";
    });

    connect(butt_m4,&wid_m4::fa_butt_text_5,[=](){
        out<<"fa_butt_text_5";
    });

    connect(butt_m4,&wid_m4::fa_butt_text_6,[=](){
        out<<"fa_butt_text_6";
    });

    connect(butt_m4,&wid_m4::fa_butt_text_7,[=](){
        out<<"fa_butt_text_7";
    });

    connect(butt_m4,&wid_m4::fa_butt_text_8,[=](){
        out<<"fa_butt_text_8";
    });

    connect(butt_m4,&wid_m4::fa_butt_text_9,[=](){
        out<<"fa_butt_text_9";
    });

    connect(butt_m4,&wid_m4::fa_butt_text_10,[=](){
        out<<"fa_butt_text_10";
    });

    connect(butt_m4,&wid_m4::fa_butt_text_11,[=](){
        out<<"fa_butt_text_11";
    });

    connect(butt_m4,&wid_m4::fa_butt_text_12,[=](){
        out<<"fa_butt_text_12";
    });
}

void wid_home::signal_m2_1()
{
    //滑动按钮
    connect(butt_m2_1,&wid_m2_1::fa_butt_slip_1,[=](){
        out<<"fa_butt_slip_1";
    });

    connect(butt_m2_1,&wid_m2_1::fa_butt_slip_2,[=](){
        out<<"fa_butt_slip_2";
    });

    connect(butt_m2_1,&wid_m2_1::fa_butt_slip_3,[=](){
        out<<"fa_butt_slip_3";
    });

    connect(butt_m2_1,&wid_m2_1::fa_butt_slip_4,[=](){
        out<<"fa_butt_slip_4";
    });

    connect(butt_m2_1,&wid_m2_1::fa_butt_slip_5,[=](){
        out<<"fa_butt_slip_5";
    });

    connect(butt_m2_1,&wid_m2_1::fa_butt_slip_6,[=](){
        out<<"fa_butt_slip_6";
    });

    //文字按钮
    connect(butt_m2_1,&wid_m2_1::fa_butt_text_1,[=](){
        out<<"fa_butt_text_1";
    });

    connect(butt_m2_1,&wid_m2_1::fa_butt_text_2,[=](){
        out<<"fa_butt_text_2";
    });

    connect(butt_m2_1,&wid_m2_1::fa_butt_text_3,[=](){
        out<<"fa_butt_text_3";
    });

    connect(butt_m2_1,&wid_m2_1::fa_butt_text_4,[=](){
        out<<"fa_butt_text_4";
    });

    connect(butt_m2_1,&wid_m2_1::fa_butt_text_5,[=](){
        out<<"fa_butt_text_5";
    });

    connect(butt_m2_1,&wid_m2_1::fa_butt_text_6,[=](){
        out<<"fa_butt_text_6";
    });
}

void wid_home::signal_m2_2()
{
    //滑动按钮
    connect(butt_m2_2,&wid_m2_2::fa_butt_slip_1,[=](){
        out<<"fa_butt_slip_1";
    });

    connect(butt_m2_2,&wid_m2_2::fa_butt_slip_2,[=](){
        out<<"fa_butt_slip_2";
    });

    connect(butt_m2_2,&wid_m2_2::fa_butt_slip_3,[=](){
        out<<"fa_butt_slip_3";
    });

    connect(butt_m2_2,&wid_m2_2::fa_butt_slip_4,[=](){
        out<<"fa_butt_slip_4";
    });

    connect(butt_m2_2,&wid_m2_2::fa_butt_slip_5,[=](){
        out<<"fa_butt_slip_5";
    });

    connect(butt_m2_2,&wid_m2_2::fa_butt_slip_6,[=](){
        out<<"fa_butt_slip_6";
    });

    //文字按钮
    connect(butt_m2_2,&wid_m2_2::fa_butt_text_1,[=](){
        out<<"fa_butt_text_1";
    });

    connect(butt_m2_2,&wid_m2_2::fa_butt_text_2,[=](){
        out<<"fa_butt_text_2";
    });

    connect(butt_m2_2,&wid_m2_2::fa_butt_text_3,[=](){
        out<<"fa_butt_text_3";
    });

    connect(butt_m2_2,&wid_m2_2::fa_butt_text_4,[=](){
        out<<"fa_butt_text_4";
    });

    connect(butt_m2_2,&wid_m2_2::fa_butt_text_5,[=](){
        out<<"fa_butt_text_5";
    });

    connect(butt_m2_2,&wid_m2_2::fa_butt_text_6,[=](){
        out<<"fa_butt_text_6";
    });
}

void wid_home::signal_m2_3()
{
    //滑动按钮
    connect(butt_m2_3,&wid_m2_3::fa_butt_slip_1,[=](){
        out<<"fa_butt_slip_1";
    });

    connect(butt_m2_3,&wid_m2_3::fa_butt_slip_2,[=](){
        out<<"fa_butt_slip_2";
    });

    connect(butt_m2_3,&wid_m2_3::fa_butt_slip_3,[=](){
        out<<"fa_butt_slip_3";
    });

    connect(butt_m2_3,&wid_m2_3::fa_butt_slip_4,[=](){
        out<<"fa_butt_slip_4";
    });

    connect(butt_m2_3,&wid_m2_3::fa_butt_slip_5,[=](){
        out<<"fa_butt_slip_5";
    });

    connect(butt_m2_3,&wid_m2_3::fa_butt_slip_6,[=](){
        out<<"fa_butt_slip_6";
    });

    connect(butt_m2_3,&wid_m2_3::fa_butt_slip_7,[=](){
        out<<"fa_butt_slip_7";
    });


    //文字按钮
    connect(butt_m2_3,&wid_m2_3::fa_butt_text_1,[=](){
        out<<"fa_butt_text_1";
    });

    connect(butt_m2_3,&wid_m2_3::fa_butt_text_2,[=](){
        out<<"fa_butt_text_2";
    });

    connect(butt_m2_3,&wid_m2_3::fa_butt_text_3,[=](){
        out<<"fa_butt_text_3";
    });

    connect(butt_m2_3,&wid_m2_3::fa_butt_text_4,[=](){
        out<<"fa_butt_text_4";
    });

    connect(butt_m2_3,&wid_m2_3::fa_butt_text_5,[=](){
        out<<"fa_butt_text_5";
    });

    connect(butt_m2_3,&wid_m2_3::fa_butt_text_6,[=](){
        out<<"fa_butt_text_6";
    });

    connect(butt_m2_3,&wid_m2_3::fa_butt_text_7,[=](){
        out<<"fa_butt_text_7";
    });



}

void wid_home::signal_m2_4()
{
    //滑动按钮
    connect(butt_m2_4,&wid_m2_4::fa_butt_slip_1,[=](){
        out<<"fa_butt_slip_1";
    });

    connect(butt_m2_4,&wid_m2_4::fa_butt_slip_2,[=](){
        out<<"fa_butt_slip_2";
    });

    connect(butt_m2_4,&wid_m2_4::fa_butt_slip_3,[=](){
        out<<"fa_butt_slip_3";
    });

    //文字按钮
    connect(butt_m2_4,&wid_m2_4::fa_butt_text_1,[=](){
        out<<"fa_butt_text_1";
    });

    connect(butt_m2_4,&wid_m2_4::fa_butt_text_2,[=](){
        out<<"fa_butt_text_2";
    });

    connect(butt_m2_4,&wid_m2_4::fa_butt_text_3,[=](){
        out<<"fa_butt_text_3";
    });

}

void wid_home::cao_show_m2(int index)
{
    butt_m2_1->hide();
    butt_m2_2->hide();
    butt_m2_3->hide();
    butt_m2_4->hide();

    if(index == 1) butt_m2_1->show();
    else if(index == 2) butt_m2_2->show();
    else if(index == 3) butt_m2_3->show();
    else if(index == 4) butt_m2_4->show();

}

void wid_home::cao_show_menu()
{
    w_dig->set_pos(this->pos()+w_main->get_pos_menu()+QPoint(2,27));
}

void wid_home::cao_hide_menu()
{
    w_dig->hide();
}

void wid_home::is_show_m2_1()
{
    //m2下窗口全部隐藏则显示默认窗口
    if(butt_m2_1->isHidden() && butt_m2_2->isHidden()
            && butt_m2_3->isHidden() && butt_m2_4->isHidden()) cao_show_m2(1);
}

void wid_home::signal_main()
{
    //m1按钮
    connect(w_main,&wid_main::fa_press_m1,this,[=](){
        butt_m1->move_start(2);
        out<<"butt_m1";
    });

    //m2按钮
    connect(w_main,&wid_main::fa_press_m2,this,[=](){
        butt_m2->move_start(1);
        is_show_m2_1();
        out<<"butt_m2";
    });

    //m3按钮
    connect(w_main,&wid_main::fa_press_m3,this,[=](){
        butt_m3->move_start(1);
        out<<"butt_m3";
    });

    //m4按钮
    connect(w_main,&wid_main::fa_press_m4,this,[=](){
        butt_m4->move_start(1);
        out<<"butt_m4";
    });
}
