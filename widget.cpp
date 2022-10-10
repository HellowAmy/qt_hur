#include "widget.h"
#include "ui_widget.h"

#include "wid_main.h"
#include "wid_home.h"

#include "wid_butt_col.h"

#include <QFontMetrics>
#include <QPushButton>

#include "qt_button_text.h"
#include "qt_button_slip.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //=========================================
    wid_home *ho=new wid_home;
    ho->show();


//=====================
//    qt_button_slip *uu=new qt_button_slip(this);
//    uu->resize(40,18);
//    uu->move(100,100);
//    uu->show();
//    uu->set_space(3);


//================
//    QFont fon("微软雅黑");
//    fon.setPixelSize(20);
//    qt_button_text *uu=new qt_button_text(this);
//    uu->set_text("你是谁氨甲环酸大开杀戒东南",QFont("微软雅黑",20));
//    uu->set_col(QColor(0x444444),QColor(0xffaf33));
//    uu->set_text("你是谁氨甲环酸大开杀戒东南",fon);
//    connect(uu,&qt_button_text::clicked,[](){
//        out<<"cliked";
//    });
//    wid_home *home=new wid_home;
//    home->show();
//    QFontMetrics me(fon);
//    QSize si=me.size(Qt::TextSingleLine,"你好啊");
//    int h=me.lineWidth();
//    int g=me.height();
//    QPushButton *u=new QPushButton(this);
//    u->resize(si);
//    u->setText("你好啊");
//    QRect t=me.boundingRect("你好啊");


//================
//    wid_butt_col *hu=new wid_butt_col(this);
//    hu->resize(580,70);
//    hu->move(100,100);

//    //背景默认设置
//    hu->set_text("针对高危Web服务漏洞渗透攻击进行防护");
//    hu->set_backdrop("C:\\Users\\IAIAI\\Desktop\\hu\\新建文件夹\\ss_6_nor.png");
//    hu->set_butt_text("Web服务保护");

//    QFont font;
//    font.setFamily("微软雅黑");
//    font.setPixelSize(12);
//    font.setWeight(QFont::Medium);

//    hu->set_pic("C:\\Users\\IAIAI\\Desktop\\hu\\新建文件夹\\ss_6_nor.png");
//    hu->set_text("针对高危Web服务漏洞渗透攻击进行防护");
//    hu->set_rect(QRect(85,35,580-85,70-35));
//    hu->set_font(font);
//    hu->set_col_font(QColor(0x777777),QColor(),QColor());
//    hu->set_align(Qt::AlignLeft | Qt::AlignTop);
//    hu->show();

}

Widget::~Widget()
{
    delete ui;
}

