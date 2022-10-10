#ifndef WID_M2_H
#define WID_M2_H

#include <QWidget>

#include "qt_frameless.h"
#include "wid_move.h"
#include "qt_button_col.h"


class wid_m2 : public wid_move
{
    Q_OBJECT
public:
    explicit wid_m2(QWidget *parent = nullptr);

signals:
    emit void fa_press_m1();
    emit void fa_press_m2();
    emit void fa_press_m3();
    emit void fa_press_m4();

protected:
    qt_button_col *butt_m1;
    qt_button_col *butt_m2;
    qt_button_col *butt_m3;
    qt_button_col *butt_m4;

private:
    void init_wid();
    void init_signal();
    void set_col_butt(qt_button_col *butt);
    QColor v_col;
    QColor v_col_press;

};

#endif // WID_M2_H
