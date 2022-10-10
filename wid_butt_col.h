#ifndef WID_BUTT_COL_H
#define WID_BUTT_COL_H

#include <QWidget>

#include "qt_button_col.h"
#include "qt_frameless.h"
#include "qt_button_text.h"
#include "qt_button_slip.h"

class wid_butt_col : public qt_frameless
{
    Q_OBJECT
public:
    explicit wid_butt_col(QWidget *parent = nullptr);

    //设置字体样式
    void set_text(QString text);
    void set_rect(QRect rect);
    void set_font(QFont font);
    void set_align(int align);
    void set_font_col(QColor col);

    //设置按钮样式
    void set_butt_move(int x,int y);
    void set_butt_col(QColor normal,QColor enter);
    void set_butt_text(QString str);
    void set_butt_font(QFont font);

    //slip按钮位置
    void set_butt_slip_move(int x,int y);
    void set_butt_slip_min();

    //设置背景颜色样式
    void set_col_brush(QColor normal,QColor enter);
    void set_col_pen(QColor normal,QColor enter);

signals:
    emit void fa_press_text();
    emit void fa_press_slip(bool go);

protected:
    qt_button_text *butt_text;
    qt_button_slip *butt_slip;

    //绘制事件——文字样式
    int enum_flg; //对齐方式
    QRect v_rect;
    QFont v_font;
    QFont v_font_butt;
    QString v_text;  //外部文字
    QColor col_font; //画笔颜色

    //绘制事件——改变背景颜色
    QColor col_brush;
    QColor col_pen;
    QColor col_normal_brush;
    QColor col_enter_brush;
    QColor col_normal_pen;
    QColor col_enter_pen;

    //绘制事件
    void paintEvent(QPaintEvent *event) override;

    //鼠标事件
    void leaveEvent(QEvent *event) override;
    void enterEvent(QEvent *event) override;

private:
    void init_wid();
    void init_signal();

    void update_col(QColor brush,QColor pen);
};

#endif // WID_BUTT_COL_H
