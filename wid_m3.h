#ifndef WID_M3_H
#define WID_M3_H

#include <QWidget>

#include "qt_frameless.h"
#include "wid_move.h"
#include "wid_butt_col.h"
#include "qt_button_text.h"

class wid_m3 : public wid_move
{
    Q_OBJECT
public:
    explicit wid_m3(QWidget *parent = nullptr);

signals:
    emit void fa_butt_text_1();
    emit void fa_butt_text_2();
    emit void fa_butt_text_3();
    emit void fa_butt_text_4();

    emit void fa_butt_slip_1(bool go);
    emit void fa_butt_slip_2(bool go);
    emit void fa_butt_slip_3(bool go);
    emit void fa_butt_slip_4(bool go);

    emit void fa_bott_text_press();

protected:
    wid_butt_col *butt_m1;
    wid_butt_col *butt_m2;
    wid_butt_col *butt_m3;
    wid_butt_col *butt_m4;

    qt_button_text *butt_text;


private:
    void init_wid();
    void init_signal();

};

#endif // WID_M3_H
