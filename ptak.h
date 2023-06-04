#ifndef PTAK_H
#define PTAK_H

#include "obiekt_latajacy.h"
//****************************
class Tptak final:public Tobiektlatajacy
{
public:
	Tptak(QColor k,int moment=0,int pred_min=8,int pred_max=8);
	~Tptak()override;
	void paint(QPainter*painter,const QStyleOptionGraphicsItem*option,QWidget*widget)final;
	QPainterPath shape()const override;

};//koniec klasy Tptak
//****************************
#endif

