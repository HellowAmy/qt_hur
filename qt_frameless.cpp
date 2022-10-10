#include "qt_frameless.h"

qt_frameless::qt_frameless(QWidget *parent)
    : QWidget{parent}
{
    v_parent=parent;
    this->setWindowFlag(Qt::FramelessWindowHint,true);//无边框

    init_wid();
    init_signal();
}

void qt_frameless::set_backdrop(QString pic)
{
    pic_backdrop=pic;
}

void qt_frameless::open_rect(QRect rect)
{
    v_rect=rect;
    is_open_rect=true;
}

void qt_frameless::close_rect()
{
    is_open_rect=false;
}

void qt_frameless::open_move()
{
    is_open=true;
}

void qt_frameless::close_move()
{
    is_open=false;
}

void qt_frameless::open_move_parent()
{
    is_open=true;
    is_open_parent=true;
}

void qt_frameless::close_move_parent()
{
    is_open=false;
    is_open_parent=false;
}

void qt_frameless::open_butt()
{
    butt_c1->show();
    butt_c2->show();
    butt_c3->show();
}

QPoint qt_frameless::get_pos_menu()
{
    return butt_c1->pos();
}

void qt_frameless::mouseMoveEvent(QMouseEvent *event)
{
    if(is_open)
    {
        //判断防止抖动和LeftButton点击
        if(event->buttons()==Qt::LeftButton && is_press)
        {
            //开启父类移动则移动父类窗口
            if(is_open_parent) v_parent->move(event->pos()-pos_global+v_parent->pos());
            else this->move(event->pos()-pos_global+this->pos());
        }
    }

    QWidget::mouseMoveEvent(event);
}

void qt_frameless::mousePressEvent(QMouseEvent *event)
{
    if(is_open)
    {
        //点击移动
        if(event->button()==Qt::LeftButton)
        {
            if(is_open_rect)//开启点击范围
            {
                //判断是否符合范围
                if(v_rect.contains(event->pos()))
                {
                    is_press = true;//允许移动——防止抖动
                    pos_global=event->pos();
                }
            }
            else//不开启点击范围
            {
                is_press = true;//允许移动——防止抖动
                pos_global=event->pos();
            }
        }
    }

    emit fa_press();//移动点击消失
    QWidget::mousePressEvent(event);
}

void qt_frameless::mouseReleaseEvent(QMouseEvent *event)
{
    if(is_open) is_press = false;//禁止移动——防止抖动
    QWidget::mouseReleaseEvent(event);
}

void qt_frameless::paintEvent(QPaintEvent *)
{
    //背景图片
    QPainter *shou=new QPainter(this);
    shou->drawPixmap(0,0,QPixmap(pic_backdrop));
    shou->end();
}

void qt_frameless::init_wid()
{
    //按钮
    butt_c1 = new qt_button_col(this);
    butt_c2 = new qt_button_col(this);
    butt_c3 = new qt_button_col(this);

    butt_c1->hide();
    butt_c2->hide();
    butt_c3->hide();
}

void qt_frameless::init_signal()
{
    //菜单
    connect(butt_c1,&qt_button_col::clicked,this,[=](){
        emit fa_menu();
        emit fa_butt_menu();
    });

    //最小化
    connect(butt_c2,&qt_button_col::clicked,this,[=](){
        emit fa_min();
        v_parent->setWindowState(Qt::WindowMinimized);
    });

    //关闭
    connect(butt_c3,&qt_button_col::clicked,this,[=](){
        emit fa_close();
        v_parent->close();
    });
}


