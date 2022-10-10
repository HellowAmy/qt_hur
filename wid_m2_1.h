#ifndef WID_M2_1_H
#define WID_M2_1_H

#include <QWidget>

#include "wid_butt_col.h"

class wid_m2_1 : public QWidget
{
    Q_OBJECT
public:
    explicit wid_m2_1(QWidget *parent = nullptr);

signals:
    emit void fa_butt_text_1();
    emit void fa_butt_text_2();
    emit void fa_butt_text_3();
    emit void fa_butt_text_4();
    emit void fa_butt_text_5();
    emit void fa_butt_text_6();

    emit void fa_butt_slip_1(bool go);
    emit void fa_butt_slip_2(bool go);
    emit void fa_butt_slip_3(bool go);
    emit void fa_butt_slip_4(bool go);
    emit void fa_butt_slip_5(bool go);
    emit void fa_butt_slip_6(bool go);

protected:
    wid_butt_col *butt_m1;
    wid_butt_col *butt_m2;
    wid_butt_col *butt_m3;
    wid_butt_col *butt_m4;
    wid_butt_col *butt_m5;
    wid_butt_col *butt_m6;

private:
    void init_wid();
    void init_signal();
};

#endif // WID_M2_1_H
