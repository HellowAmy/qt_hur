#include "qt_button_col.h"

qt_button_col::qt_button_col(QWidget *parent)
    : QPushButton{parent}
{
    //画笔
    v_font.setFamily("微软雅黑");
    v_font.setPixelSize(16);
    v_font.setWeight(QFont::Medium);

    enum_flg=Qt::AlignCenter;//中间对齐
    enum_button=Qt::LeftButton;//允许左键点击

    //区域
    v_rect=QRect(0,100-1,120,20-1);
}

void qt_button_col::set_pic(QString pic)
{
    pic_col = pic;

    if(pix.load(pic_col))
    {
        this->resize(pix.width(),pix.height());//设置按钮大小

        //将有颜色部分加入容器
        QImage img=pix.toImage();//载入
        for (int w = 0; w < img.width(); ++w)
        {
            vec_col.push_back(QVector<bool>());
            vec_rgb.push_back(QVector<QColor>());
            for (int h = 0; h < img.height(); ++h)
            {
                vec_col[w].push_back(false);
                vec_rgb[w].push_back(img.pixelColor(w, h));
                if(img.pixel(w, h) != 0) vec_col[w][h] = true;
            }
        }
        pix=QPixmap::fromImage(img);//保存
    }
}

void qt_button_col::set_col_pic(QColor normal,QColor enter,QColor press)
{
    col_normal=normal;
    col_enter=enter;
    col_press=press;

    change_col_pic(col_normal);
    this->update();
}

void qt_button_col::set_col_pic_back(QColor normal,QColor enter,QColor press)
{
    col_normal_back=normal;
    col_enter_back=enter;
    col_press_back=press;

    change_col_back(col_normal_back);
    this->update();
}

void qt_button_col::set_col_font(QColor normal,QColor enter,QColor press)
{
    col_normal_font=normal;
    col_enter_font=enter;
    col_press_font=press;

    change_col_font(col_normal_font);
    this->update();
}

void qt_button_col::change_col_pic(QColor col)
{
    if(col.isValid())
    {
        if(pix.isNull() == false)
        {
            QImage img=pix.toImage();//载入
            for (int w = 0; w < img.width(); w++)
            {
                for (int h = 0; h < img.height(); h++)
                {
                    if(vec_col[w][h] == true)
                    {
                        QColor temp(col);
                        temp.setAlpha(vec_rgb[w][h].alpha());
                        img.setPixelColor(w,h,temp);
                    }
                }
            }
            pix=QPixmap::fromImage(img);//保存
        }
    }
}

void qt_button_col::change_col_back(QColor col)
{
    if(col.isValid())
    {
        if(pix.isNull() == false)
        {
            QImage img=pix.toImage();//载入
            for (int w = 0; w < img.width(); w++)
            {
                for (int h = 0; h < img.height();h++)
                {
                    if(vec_col[w][h] == false) img.setPixel(w,h,col.rgba());
                }
            }
            pix=QPixmap::fromImage(img);//保存
        }
    }
}

void qt_button_col::change_col_font(QColor col)
{
    if(col.isValid()) col_font=col;
}

void qt_button_col::set_text(QString text)
{
    v_text=text;
    if(col_normal.isValid())
    {
        if(col_normal_font.isValid()) col_font=col_normal_font;
        else col_font=col_normal;
    }
}

void qt_button_col::set_rect(QRect rect)
{
    v_rect=rect;
}

void qt_button_col::set_font(QFont font)
{
    v_font=font;

//    v_font.setFamily("微软雅黑");
//    v_font.setPixelSize(16);
//    v_font.setWeight(QFont::Medium);
}

void qt_button_col::set_align(int align)
{
    enum_flg=align;

//    Qt::AlignLeft
//    Qt::AlignRight
//    Qt::AlignHCenter
//    Qt::AlignJustify
//    Qt::AlignTop
//    Qt::AlignBottom
//    Qt::AlignVCenter
//    Qt::AlignCenter
//    Qt::TextDontClip
//    Qt::TextSingleLine
//    Qt::TextExpandTabs
//    Qt::TextShowMnemonic
//    Qt::TextWordWrap
//    Qt::TextIncludeTrailingSpaces
}

void qt_button_col::set_butt_enable(Qt::MouseButton butt)
{
    enum_button=butt;
}

void qt_button_col::paintEvent(QPaintEvent *event)
{
    if(pix.isNull() == false)
    {
        QPainter *show=new QPainter(this);
        show->drawPixmap(0,0,pix);

        //字体
        if(v_text.isEmpty() == false)
        {
            show->setPen(QColor(col_font));
            show->setFont(v_font);
            show->drawText(v_rect, enum_flg, v_text);
        }

        show->end();
    }
    else QPushButton::paintEvent(event);
}

void qt_button_col::enterEvent(QEvent *e)
{
    //颜色变化
    if(col_enter.isValid()) change_col_pic(col_enter);//图片
    if(col_enter_back.isValid()) change_col_back(col_enter_back);//背景
    if(col_enter_font.isValid()) change_col_font(col_enter_font);//画笔

    this->update();
    emit fa_enter();
    QPushButton::enterEvent(e);
}

void qt_button_col::mousePressEvent(QMouseEvent *e)
{
    if(e->button() == enum_button)
    {
        //颜色变化
        if(col_press.isValid()) change_col_pic(col_press);//图片
        if(col_press_back.isValid()) change_col_back(col_press_back);//背景
        if(col_press_font.isValid()) change_col_font(col_press_font);//画笔

        this->update();
        emit fa_press();
    }
    QPushButton::mousePressEvent(e);
}

void qt_button_col::leaveEvent(QEvent *e)
{
    //颜色变化
    if(col_normal.isValid()) change_col_pic(col_normal);//图片
    if(col_normal_back.isValid()) change_col_back(col_normal_back);//背景
    if(col_normal_font.isValid()) change_col_font(col_normal_font);//画笔

    this->update();
    emit fa_leave();
    QPushButton::leaveEvent(e);
}

void qt_button_col::mouseReleaseEvent(QMouseEvent *e)
{
    //颜色变化
    if(col_enter.isValid()) change_col_pic(col_enter);//图片
    if(col_enter_back.isValid()) change_col_back(col_enter_back);//背景
    if(col_enter_font.isValid()) change_col_font(col_enter_font);//画笔

    this->update();
    emit fa_release();
    QPushButton::mouseReleaseEvent(e);
}
