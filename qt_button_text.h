#ifndef QT_BUTTON_TEXT_H
#define QT_BUTTON_TEXT_H

#include <QWidget>
#include <QFontMetrics>
#include <QString>
#include <QPushButton>
#include <QPainter>
#include <QPoint>
#include <QFont>
#include <QFont>

class qt_button_text : public QPushButton
{
    Q_OBJECT
public:
    explicit qt_button_text(QWidget *parent = nullptr); 
    void set_text(QString str,QFont font);//设置文本和字体
    void set_col(QColor normal,QColor enter);//设置文本颜色
    void set_col(QColor normal,QColor enter,QColor press);//设置文本颜色

signals:

protected:
    //绘图事件
    QFont v_font;
    QColor col_pen;
    void paintEvent(QPaintEvent *event) override;

    //鼠标事件
    void leaveEvent(QEvent *event) override;
    void enterEvent(QEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;



private:
    QString v_text;//设置文本

    //设置文本颜色
    QColor col_normal;
    QColor col_enter;
    QColor col_press;

    void update_col(QColor col);

};

#endif // QT_BUTTON_TEXT_H
