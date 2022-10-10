#ifndef WID_MAIN_H
#define WID_MAIN_H

#include <QWidget>

#include "qt_frameless.h"

class wid_main : public qt_frameless
{
    Q_OBJECT
public:
    explicit wid_main(QWidget *parent = nullptr);

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

};

#endif // WID_MAIN_H
