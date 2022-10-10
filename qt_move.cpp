#include "qt_move.h"

qt_move::qt_move(QWidget *parent)
    : qt_frameless{parent}
{
    init_wid();
    init_signal();
}

void qt_move::init_signal()
{
    //启动定时器
    connect(&v_time,&QTimer::timeout,[=](){

        v_count+=v_speed;
        if(v_count >= v_distance)
        {
            v_time.stop();
            v_count=0;
        }

        if(is_back) this->move(this->pos()+QPoint(0,v_speed));
        else this->move(this->pos()-QPoint(0,v_speed));
    });

    connect(butt_back,&qt_button_col::clicked,[=](){
        this->move_back();
        emit fa_back();
    });

    connect(this,&qt_move::fa_butt_open,[=](){
        butt_back->move(pos_back);
        butt_back->set_pic(pic_butt);

        butt_back->show();
    });
}

void qt_move::move_start(int time)
{
    is_back=false;
    v_time.start(time);
}

void qt_move::move_back(int time)
{
    is_back=true;
    v_time.start(time);
}

void qt_move::open_back()
{
    is_butt_open=true;
    emit fa_butt_open();
}

void qt_move::set_butt_pos(QPoint pos)
{
    pos_back=pos;
}

void qt_move::set_butt_pic(QString pic)
{
    pic_butt=pic;
}

void qt_move::set_butt_col(QColor normal, QColor enter, QColor press)
{
    butt_back->set_col_pic(normal,enter,press);
}

void qt_move::set_butt_col_back(QColor normal, QColor enter, QColor press)
{
    butt_back->set_col_pic_back(normal,enter,press);
}

void qt_move::init_wid()
{
    //返回按键
    butt_back = new qt_button_col(this);
    butt_back->hide();
}

void qt_move::set_distance(int distance)
{
    v_distance=distance;
}

void qt_move::set_speed(int speed)
{
    v_speed=speed;
}
