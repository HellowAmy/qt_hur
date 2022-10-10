#ifndef WID_M4_H
#define WID_M4_H

#include <QWidget>
#include <QScrollArea>
#include <QLabel>

#include "qt_frameless.h"
#include "wid_move.h"
#include "wid_butt_col.h"
#include "qt_button_text.h"

class wid_m4 : public wid_move
{
    Q_OBJECT
public:
    explicit wid_m4(QWidget *parent = nullptr);

signals:
    emit void fa_butt_text_1();
    emit void fa_butt_text_2();
    emit void fa_butt_text_3();
    emit void fa_butt_text_4();
    emit void fa_butt_text_5();
    emit void fa_butt_text_6();
    emit void fa_butt_text_7();
    emit void fa_butt_text_8();
    emit void fa_butt_text_9();
    emit void fa_butt_text_10();
    emit void fa_butt_text_11();
    emit void fa_butt_text_12();

protected:
    QScrollArea *area;
    QWidget *wid_temp;

    QLabel *label_1;
    QLabel *label_2;
    QLabel *label_3;

    wid_butt_col *butt_m1;
    wid_butt_col *butt_m2;
    wid_butt_col *butt_m3;
    wid_butt_col *butt_m4;
    wid_butt_col *butt_m5;
    wid_butt_col *butt_m6;
    wid_butt_col *butt_m7;
    wid_butt_col *butt_m8;
    wid_butt_col *butt_m9;
    wid_butt_col *butt_m10;
    wid_butt_col *butt_m11;
    wid_butt_col *butt_m12;

private:
    void init_wid();
    void init_signal();

};

#endif // WID_M4_H
