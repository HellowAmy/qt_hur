#include "wid_butt_col.h"

wid_butt_col::wid_butt_col(QWidget *parent)
    : qt_frameless{parent}
{
    init_wid();
    init_signal();
}

void wid_butt_col::paintEvent(QPaintEvent *event)
{
    QPainter *show=new QPainter(this);

    //绘制颜色背景——填充背景和画外线框
    if(col_brush.isValid() && col_pen.isValid())
    {
        show->setBrush(QBrush(QColor(col_brush)));
        show->setPen(QPen(QColor(col_pen),2));
        show->drawRect(this->rect());
    }

    //绘制文字
    if(v_text.isEmpty() == false)
    {
        show->setPen(QColor(col_font));
        show->setFont(v_font);
        show->drawText(v_rect, enum_flg, v_text);
    }

    show->end();

    qt_frameless::paintEvent(event);//继承父类
}

void wid_butt_col::leaveEvent(QEvent *event)
{
    update_col(col_normal_brush,col_normal_pen);//正常状态
    qt_frameless::leaveEvent(event);
}

void wid_butt_col::enterEvent(QEvent *event)
{
    update_col(col_enter_brush,col_enter_pen);//进入状态
    qt_frameless::enterEvent(event);
}

void wid_butt_col::init_wid()
{
    this->resize(580,70);

    butt_text = new qt_button_text(this);//文字按钮

    butt_slip = new qt_button_slip(this);//平滑按钮
    butt_slip->move(530,37);
    butt_slip->resize(40,18);
    butt_slip->set_space(3);
    butt_slip->move_max();

    //文字按钮默认设置
    v_font_butt.setFamily("微软雅黑");
    v_font_butt.setPixelSize(14);

    //小字默认设置
    v_font.setFamily("微软雅黑");
    v_font.setPixelSize(12);
    v_font.setWeight(QFont::Medium);

    //默认小文字绘制样式
    enum_flg=Qt::AlignLeft | Qt::AlignTop;//中间对齐
    v_rect=QRect(85,35+2,580-85,70-35);//区域
    col_font = 0x909090;//小文字颜色

    //默认文字颜色
    this->set_col_brush(QColor(0xffffff),QColor(0xfffcf8));
    this->set_col_pen(QColor(0xffffff),QColor(0xffe7c1));

    //默认按钮颜色
    this->set_butt_move(85,15);
    this->set_butt_col(QColor(0x444444),QColor(0xf17f05));//按钮文字颜色
}

void wid_butt_col::init_signal()
{
    connect(butt_text,&qt_button_text::clicked,this,&wid_butt_col::fa_press_text);
    connect(butt_slip,&qt_button_slip::fa_press,this,&wid_butt_col::fa_press_slip);
}

void wid_butt_col::update_col(QColor brush, QColor pen)
{
    col_brush=brush;
    col_pen=pen;
    this->update();
}

void wid_butt_col::set_text(QString text)
{
    v_text=text;
}

void wid_butt_col::set_rect(QRect rect)
{
    v_rect=rect;
}

void wid_butt_col::set_font(QFont font)
{
    v_font=font;

//    v_font.setFamily("微软雅黑");
//    v_font.setPixelSize(16);
//    v_font.setWeight(QFont::Medium);
}

void wid_butt_col::set_align(int align)
{
    enum_flg=align;

//    Qt::AlignLeft
//    Qt::AlignRight
//    Qt::AlignHCenter
//    Qt::AlignJustify
//    Qt::AlignTop
//    Qt::AlignBottom
//    Qt::AlignVCenter
//    Qt::AlignCenter
//    Qt::TextDontClip
//    Qt::TextSingleLine
//    Qt::TextExpandTabs
//    Qt::TextShowMnemonic
//    Qt::TextWordWrap
//    Qt::TextIncludeTrailingSpaces
}

void wid_butt_col::set_font_col(QColor col)
{
    col_font = col;
}

void wid_butt_col::set_butt_move(int x, int y)
{
    butt_text->move(x,y);
}

void wid_butt_col::set_butt_col(QColor normal, QColor enter)
{
    butt_text->set_col(normal,enter);
}

void wid_butt_col::set_butt_text(QString str)
{
    butt_text->set_text(str,v_font_butt);
}

void wid_butt_col::set_butt_font(QFont font)
{
    v_font_butt=font;
}

void wid_butt_col::set_butt_slip_move(int x, int y)
{
    butt_slip->move(x,y);
}

void wid_butt_col::set_butt_slip_min()
{
    butt_slip->move_min();
}

void wid_butt_col::set_col_brush(QColor normal, QColor enter)
{
    col_normal_brush = normal;
    col_enter_brush = enter;
    this->update_col(col_normal_brush,col_normal_pen);
}

void wid_butt_col::set_col_pen(QColor normal, QColor enter)
{
    col_normal_pen = normal;
    col_enter_pen = enter;
    this->update_col(col_normal_brush,col_normal_pen);
}
