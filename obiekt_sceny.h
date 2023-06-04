#ifndef OBIEKT_SCENY
#define OBIEKT_SCENY

#include <QApplication> 
#include <QGraphicsItem>
//*************************
class Tobiektsceny:public QGraphicsItem
{
public:
	virtual ~Tobiektsceny()=0;
	Tobiektsceny();
	virtual QRectF 	boundingRect()const=0;
	virtual void paint(QPainter*painter,const QStyleOptionGraphicsItem*option,QWidget*widget)=0;
	bool czy_zakonczyl();

	QColor kolor;
	bool zakonczyl;

};//koniec klasy Tobiektsceny
//*************************
#endif
