#include "lcdui.h"
#include <QPainter>
#include <QPaintEvent>
#include <QRgb>
#include <QBrush>
#include "lcd.h"
#include <cstdio>

LcdUi::LcdUi(QWidget *parent) :
    QWidget(parent)
{
    image = new QImage(160,144,QImage::Format_RGB32);
    image->fill(0);
}

LcdUi::~LcdUi()
{
    delete image;
}


void LcdUi::paintEvent(QPaintEvent *event)
{
    QPainter painter;
    QColor background(255, 255, 255);

    painter.begin(this);
    painter.fillRect(event->rect(), background);
    painter.drawImage(0,0,*image,160,144);
    //painter.fillRect(0,0,160,144,);
    painter.end();
}

void LcdUi::drawBlank()
{
    printf("blank\n");
    image->fill(0);
    this->update();
}

void LcdUi::drawImage(RGB lcdimage[][144])
{
    printf("not blank\n");
    for (int i=0;i<160;i++)
        for (int j=0;j<144;j++){

            //image->setPixel(i,j,qRgb(lcdimage[i][j].r,lcdimage[i][j].g,lcdimage[i][j].b));
            image->setPixel(i,j,qRgb(120,56,56));
            //printf("i:%d j:%d : r: %d g:%d b:%d \n",i,j,lcdimage[i][j].r,lcdimage[i][j].g,lcdimage[i][j].b);
        }
    this->update();
}



