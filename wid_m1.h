#ifndef WID_M1_H
#define WID_M1_H

#include <QWidget>

#include "qt_move.h"
#include "qt_button_col.h"

class wid_m1 : public qt_move
{
    Q_OBJECT
public:
    explicit wid_m1(QWidget *parent = nullptr);

signals:
    emit void fa_press_m1();
    emit void fa_press_m2();
    emit void fa_press_m3();

protected:
    qt_button_col *butt_m1;
    qt_button_col *butt_m2;
    qt_button_col *butt_m3;

private:
    void init_wid();
    void init_signal();

};

#endif // WID_M1_H
