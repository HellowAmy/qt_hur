#include "qt_button_text.h"

qt_button_text::qt_button_text(QWidget *parent)
    : QPushButton{parent}
{

}

void qt_button_text::set_text(QString str,QFont font)
{
    if(str.isEmpty() == false)
    {
        v_font=font;
        v_text=str;

        //计算字符显示需要的大小
        QFontMetrics me(font);
        this->resize(me.size(Qt::TextSingleLine,str));
    }
}

void qt_button_text::set_col(QColor normal, QColor enter)
{
    col_normal=normal;
    col_enter=enter;
    update_col(col_normal);
}

void qt_button_text::set_col(QColor normal, QColor enter, QColor press)
{
    col_normal=normal;
    col_enter=enter;
    col_press=press;
    update_col(col_normal);
}

void qt_button_text::paintEvent(QPaintEvent *)
{
    QPainter *show=new QPainter(this);
    if(v_text.isEmpty() == false)
    {
        show->setFont(v_font);
        show->setPen(col_pen);
        show->drawText(this->rect(),Qt::AlignCenter,v_text);
    }


    show->end();
}

void qt_button_text::leaveEvent(QEvent *event)
{
    update_col(col_normal);
    QPushButton::leaveEvent(event);
}

void qt_button_text::enterEvent(QEvent *event)
{
    update_col(col_enter);
    QPushButton::enterEvent(event);
}

void qt_button_text::mousePressEvent(QMouseEvent *event)
{
    update_col(col_press);
    QPushButton::mousePressEvent(event);
}

void qt_button_text::mouseReleaseEvent(QMouseEvent *event)
{
    update_col(col_enter);
    QPushButton::mouseReleaseEvent(event);
}

void qt_button_text::update_col(QColor col)
{
    col_pen=col;
    this->update();
}
