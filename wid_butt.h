#ifndef WID_BUTT_H
#define WID_BUTT_H

#include <QWidget>

#include "qt_button_col.h"

class wid_butt : public QWidget
{
    Q_OBJECT
public:
    explicit wid_butt(QWidget *parent = nullptr);

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

#endif // WID_BUTT_H
