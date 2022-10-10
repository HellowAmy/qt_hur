#ifndef WID_M2_4_H
#define WID_M2_4_H

#include <QWidget>

#include "wid_butt_col.h"

class wid_m2_4 : public QWidget
{
    Q_OBJECT
public:
    explicit wid_m2_4(QWidget *parent = nullptr);

signals:
    emit void fa_butt_text_1();
    emit void fa_butt_text_2();
    emit void fa_butt_text_3();

    emit void fa_butt_slip_1(bool go);
    emit void fa_butt_slip_2(bool go);
    emit void fa_butt_slip_3(bool go);

protected:
    wid_butt_col *butt_m1;
    wid_butt_col *butt_m2;
    wid_butt_col *butt_m3;

private:
    void init_wid();
    void init_signal();

};

#endif // WID_M2_4_H
