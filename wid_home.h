#ifndef WID_HOME_H
#define WID_HOME_H

#include <QWidget>

#include "qt_frameless.h"
#include "wid_main.h"
#include "wid_menu_dig.h"

#include "wid_m1.h"
#include "wid_m2.h"
#include "wid_m3.h"
#include "wid_m4.h"

#include "wid_m2_1.h"
#include "wid_m2_2.h"
#include "wid_m2_3.h"
#include "wid_m2_4.h"


class wid_home : public qt_frameless
{
    Q_OBJECT
public:
    explicit wid_home(QWidget *parent = nullptr);

signals:

protected:
    wid_main *w_main;//主菜单
    wid_menu_dig *w_dig;//选择菜单

    //main下连接界面
    wid_m1 *butt_m1;
    wid_m2 *butt_m2;
    wid_m3 *butt_m3;
    wid_m4 *butt_m4;

    //m2下连接界面
    wid_m2_1 *butt_m2_1;
    wid_m2_2 *butt_m2_2;
    wid_m2_3 *butt_m2_3;
    wid_m2_4 *butt_m2_4;


private:
    void init_wid();
    void init_signal();

    void init_m2();//m2界面下按钮的初始化

    //主界面信号
    void signal_main();
    void signal_m1();
    void signal_m2();
    void signal_m3();
    void signal_m4();

    //m2子界面下的信号
    void signal_m2_1();
    void signal_m2_2();
    void signal_m2_3();
    void signal_m2_4();

    void cao_show_m2(int index);//m2按钮选择高亮
    void is_show_m2_1();//默认高亮

    //显示和隐藏菜单栏
    void signal_show_menu();
    void cao_show_menu();
    void cao_hide_menu();

};

#endif // WID_HOME_H
