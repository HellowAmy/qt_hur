#include "qt_layout.h"

qt_layout::qt_layout(QWidget *parent)
    : QWidget{parent}
{
    init_wid();


//    wid = new QWidget(this);



    area = new QScrollArea(parent);
    area->resize(200,200);

    this->setBackgroundRole(QPalette::Dark);
    //    area->setFrameShape(QFrame::NoFrame);
    //    area->resize(this->size()+QSize(20,0));

    area->setWidget(this);
//        area->show();
}

void qt_layout::set_size_wid(int wide,int high)
{
    this->resize(QSize(wide,high));
//    area->resize(QSize(wide,high)+QSize(20,0));
}

void qt_layout::set_size_area(int wide,int high)
{
    area->resize(QSize(wide,high));
}

void qt_layout::move_area(QPoint pos)
{
//    this->move(pos);
    area->move(pos);
}

void qt_layout::init_wid()
{

    box_h = new QVBoxLayout(this);

//    this->show();
    this->resize(400,1000);

    m1 = new qt_button_col(this);
    m1->set_pic(":/pic/m_one/m_1.png");
    m1->setFixedSize(120,120);
    m1->move(100,0);

    m2 = new qt_button_col(this);
    m2->set_pic(":/pic/m_one/m_2.png");
    m2->move(200,0);
    m2->setFixedSize(120,120);

    m3 = new qt_button_col(this);
    m3->set_pic(":/pic/m_one/m_3.png");
    m3->move(300,0);
    m3->setFixedSize(120,120);

    QPushButton *t1=new QPushButton(this);
    t1->resize(500,40);
    t1->setText("1");

    QPushButton *t2=new QPushButton(this);
    t2->resize(500,40);
    t2->setText("2");

    QPushButton *t3=new QPushButton(this);
    t3->resize(500,40);
    t3->setText("3");

    box_h->setSpacing(10);
//    box_h->setSizeConstraint(QLayout::SetFixedSize);
    box_h->addWidget(t1);
    box_h->addWidget(t2);
    box_h->addWidget(t3);
    box_h->setSizeConstraint(QLayout::SetFixedSize);
    this->setLayout(box_h);

}
