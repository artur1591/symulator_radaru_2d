#ifndef SAMOLOT_H
#define SAMOLOT_H

#include "obiekt_latajacy.h"
//***********************
class Tsamolot final:public Tobiektlatajacy
{
public:
	Tsamolot(QColor k,int moment=0,int pred_min=8,int pred_max=8);
	~Tsamolot()override; 
	void paint(QPainter*painter,const QStyleOptionGraphicsItem*option,QWidget*widget)override;
	QPainterPath shape()const override;

};//koniec klasy Tsamolot
//****************************
#endif

