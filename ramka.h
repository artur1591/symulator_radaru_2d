#ifndef RAMKA_H
#define RAMKA_H

#include "obiekt_sceny.h"
//**************************************
class Tramka final:public Tobiektsceny
{
public:
	Tramka(QColor k);
	~Tramka();
	QRectF boundingRect()const;
	void paint(QPainter*painter,const QStyleOptionGraphicsItem*option,QWidget*widget);

};//koniec klasy Tramka
//****************************        
#endif 

