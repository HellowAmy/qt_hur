#include "qt_button_slip.h"

qt_button_slip::qt_button_slip(QWidget *parent)
    : QPushButton{parent}
{
    init_wid();
    init_signal();
}

void qt_button_slip::set_space(int space)
{
    v_space=space;
    v_min=v_space;//间隔大小等于移动最小值
    v_max=this->width()+v_space-this->height();//最大值为按钮长度减去间隔和圆圈直径
    v_move_count=v_min;//小圆圈初始位置
}

void qt_button_slip::set_speed_move(int speed)
{
    v_speed_move=speed;
}

void qt_button_slip::move_max()
{
    v_move_count=v_max-1;
    col_back=col_back_press;
    is_go=false;
    this->update();
}

void qt_button_slip::move_min()
{
    v_move_count=v_min;
    col_back=col_back_normal;
    is_go=true;
    this->update();
}

void qt_button_slip::paintEvent(QPaintEvent *)
{
    QPainter *show=new QPainter(this);

    //椭圆底色部分
    show->setPen(QPen(Qt::NoPen));
    show->setRenderHint(QPainter::Antialiasing);
    show->setBrush(col_back);//QColor(0xe8be86)
    show->drawEllipse(0,0,height(),height());//第一个圆
    show->drawEllipse(width()-height()-1,0,height(),height());//第二个圆
    show->drawRect(height()/2,0,width()-height(),height());//中间矩形

    //小圆圈部分
    show->setBrush(col_roundness);//QColor(0xffffff)
    show->drawEllipse(v_move_count,v_space,(height()-v_space*2),(height()-v_space*2));

    show->end();
}

void qt_button_slip::mousePressEvent(QMouseEvent *event)
{
    time.start(v_speed_move);
    if(is_go) col_back=col_back_press;

    QPushButton::mousePressEvent(event);
}

void qt_button_slip::init_wid()
{
    v_speed_move=18;//速度控制
    v_space=30;//间隔

    //默认颜色
    col_back_normal=QColor(0xc3c3c3);
    col_roundness_normal=QColor(0xffffff);

    //按下颜色
    col_back_press=QColor(0xffb000);

    //颜色赋值
    col_back=col_back_normal;
    col_roundness=col_roundness_normal;

    v_min=v_space;//最小位置
    v_max=this->width();//最大位置
    v_move_count=v_min;//当前位置
}

void qt_button_slip::init_signal()
{
    connect(&time,&QTimer::timeout,[=](){
        if(is_go) v_move_count+=1;
        else v_move_count-=1;

        //颜色改变
        if(is_go==false && v_move_count < (v_max-v_space)/2) col_back=col_back_normal;

        //标记打开还是关闭
        if(v_move_count >= v_max-1 || v_move_count <= v_min)
        {
            emit fa_press(is_go);//发送状态信号
            is_go=!is_go;//改变状态
            time.stop();
        }

        this->update();
    });
}
