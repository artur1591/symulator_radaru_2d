#ifndef RAKIETA_H
#define RAKIETA_H

#include "obiekt_latajacy.h"
#include <iostream>
#include "radar.h"
//***********************
class Trakieta final:public Tobiektlatajacy
{
public:
	Trakieta(QColor k,int moment=0,int pred_min=8,int pred_max=8);
	~Trakieta()override; 
	void paint(QPainter*painter,const QStyleOptionGraphicsItem*option,QWidget*widget)override;
	QPainterPath shape()const override;

};//koniec klasy Trakieta
//****************************
#endif

