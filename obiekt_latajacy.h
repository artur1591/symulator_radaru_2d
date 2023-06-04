#ifndef OBIEKT_LATAJACY_H
#define OBIEKT_LATAJACY_H

#include "obiekt_sceny.h"
//**************************************
class Tobiektlatajacy:public Tobiektsceny
{
public:
	~Tobiektlatajacy()=0;
	Tobiektlatajacy();
	virtual QPainterPath shape()const=0;
	QRectF 	boundingRect()const;
	void oblicz_parametry_lotu();
	bool czy_osiagnal_koniec(QPointF);
	bool czy_wystartowal();
	virtual void advance(int phase);
	int jaka_sila();

	void policz_ile_jakich_jest(int&,int&,int&, QList<QGraphicsItem*>);

protected:

	int sila;
	unsigned moment_startu;
	qreal StartX,StartY; 
	int angle;
	int speed;
	int sciana;
	bool wystartowal;

};//koniec klasy Tobiektlatajacy
//*********************************
#endif 

