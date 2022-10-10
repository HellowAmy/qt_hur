#ifndef QT_BUTTON_SLIP_H
#define QT_BUTTON_SLIP_H

#include <QWidget>
#include <QPushButton>
#include <QPainter>
#include <QTimer>

#include <QDebug>
#define out qDebug()

class qt_button_slip : public QPushButton
{
    Q_OBJECT
public:
    explicit qt_button_slip(QWidget *parent = nullptr);

    void set_space(int space);//小圆形到边界的间隔
    void set_speed_move(int speed);//按钮移动速度
    void move_max();//初始位置在右（默认为左）
    void move_min();//初始位置在右（默认为左）

signals:
    emit void fa_press(bool go);

protected:
    //绘制底色和圆形
    QColor col_back;
    QColor col_roundness;
    void paintEvent(QPaintEvent *event) override;

    //鼠标事件
    void mousePressEvent(QMouseEvent *event) override;

private:
    QTimer time;
    int v_speed_move=1;//速度
    int v_min=0;
    int v_max=0;
    int v_move_count=0;
    int v_space=0;//间隔
    bool is_go=true;

    QColor col_back_normal;
    QColor col_back_press;
    QColor col_roundness_normal;
    QColor col_roundness_press;

    void init_wid();
    void init_signal();

};

#endif // QT_BUTTON_SLIP_H
