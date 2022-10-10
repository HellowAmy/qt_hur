#ifndef WID_MENU_DIG_H
#define WID_MENU_DIG_H

#include <QWidget>
#include <QDialog>

#include "qt_button_col.h"

class wid_menu_dig : public QDialog
{
    Q_OBJECT
public:
    explicit wid_menu_dig(QWidget *parent = nullptr);
    void set_pos(QPoint pos);//菜单相对界面的偏移

signals:
    emit void fa_press_c1();
    emit void fa_press_c2();
    emit void fa_press_c3();
    emit void fa_press_c4();
    emit void fa_press_c5();
    emit void fa_press_c6();
    emit void fa_press_c7();
    emit void fa_press_c8();
    emit void fa_press_c9();

protected:
    qt_button_col *c1;
    qt_button_col *c2;
    qt_button_col *c3;
    qt_button_col *c4;
    qt_button_col *c5;
    qt_button_col *c6;
    qt_button_col *c7;
    qt_button_col *c8;
    qt_button_col *c9;

private:
    void init_wid();
    void init_signal();

};

#endif // WID_MENU_DIG_H
