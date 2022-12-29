#ifndef QT_BUTTON_COL_H
#define QT_BUTTON_COL_H

#include <QWidget>
#include <QVector>
#include <QPushButton>
#include <QPainter>
#include <QPixmap>
#include <QImage>
#include <QColor>
#include <QLabel>
#include <QMouseEvent>

class qt_button_col : public QPushButton
{
    Q_OBJECT
public:
    explicit qt_button_col(QWidget *parent = nullptr);

    void set_pic(QString pic);//设置图片
    void set_col_pic(QColor normal,QColor enter,QColor press);//设置图片变化颜色
    void set_col_pic_back(QColor normal,QColor enter,QColor press);//设置图片背景变化颜色
    void set_col_font(QColor normal,QColor enter,QColor press);//设置字体变化颜色

    //设置字体样式
    void set_text(QString text);
    void set_rect(QRect rect);
    void set_font(QFont font);
    void set_align(int align);

    void set_butt_enable(Qt::MouseButton butt);//鼠标生效（默认左键生效）

signals:
    emit void fa_enter();
    emit void fa_press();
    emit void fa_leave();
    emit void fa_release();

protected:
    void paintEvent(QPaintEvent *event) override;

    //触发改变颜色事件
    void enterEvent(QEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void leaveEvent(QEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;

private:
    QVector<QVector<bool>> vec_col;//数据容器
    QVector<QVector<QColor>> vec_rgb;//数据容器
    QString pic_col;//图片路径
    QPixmap pix;//图片

    //图标改变颜色
    QColor col_normal;
    QColor col_enter;
    QColor col_press;

    //字体改变颜色
    QColor col_normal_font;
    QColor col_enter_font;
    QColor col_press_font;

    //背景改变颜色
    QColor col_normal_back;
    QColor col_enter_back;
    QColor col_press_back;

    //文字样式
    int enum_flg;//对齐方式
    QRect v_rect;
    QFont v_font;
    QString v_text;//外部文字
    QColor col_font;//画笔颜色

    Qt::MouseButton enum_button;//允许点击的按键

    void change_col_pic(QColor col);
    void change_col_back(QColor col);
    void change_col_font(QColor col);

};

#endif // QT_BUTTON_COL_H
