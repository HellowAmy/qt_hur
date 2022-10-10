#ifndef WID_MOVE_H
#define WID_MOVE_H

#include <QWidget>

#include "qt_move.h"

class wid_move : public qt_move
{
    Q_OBJECT
public:
    explicit wid_move(QWidget *parent = nullptr);

    //绘制文字样式
    void set_text(QString text);
    void set_rect(QRect rect);
    void set_font(QFont font,QColor col);

signals:

private:
    void init_wid();
    void init_signal();

protected:

    //绘制文字
    QString v_text;
    QFont v_font;
    QColor v_col;
    QRect v_rect;
    void paintEvent(QPaintEvent *event) override;

};

#endif // WID_MOVE_H
