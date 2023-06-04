#ifndef WYBUCH_H
#define WYBUCH_H

#include "obiekt_sceny.h"
#include "radar.h"
//********************************
class Twybuch final:public Tobiektsceny
{
public:
	Twybuch(unsigned pocz,QPointF gdz,QColor kol);
	~Twybuch();

	QRectF boundingRect()const;
	void advance(int phase);
	void paint(QPainter*painter,const QStyleOptionGraphicsItem*option,QWidget*widget);
	QPainterPath shape()const;
	bool&zakoncz_dost();

private:
	unsigned chw_pocz; 
	QPointF gdzie;
	int prom,grub;

}; //koniec klasy Twybuch
//****************************
#endif
