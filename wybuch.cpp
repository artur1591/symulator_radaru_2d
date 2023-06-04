#include "wybuch.h"
using std::cerr;
using std::endl;
//*************************
bool&Twybuch::zakoncz_dost(){return zakonczyl;}
//*************************
QRectF Twybuch::boundingRect()const
{
int bok{40};

return QRectF(-bok/2,-bok/2,bok,bok);
}
//*************************
Twybuch::Twybuch(unsigned pocz,QPointF gdz,QColor kol):chw_pocz(pocz),
gdzie(gdz),prom(6),grub(2)
{
	kolor=kol;
	setVisible(false);
}
//*************************
Twybuch::~Twybuch()
{
#if INFO_AKTYWNOSCI_DESTRUKTOROW
	cerr<<__func__<<" ";
//qInfo(__func__); //bo robi newline
#endif
}
//*************************
void Twybuch::advance(int phase)
{
if(zakonczyl || !phase)return;

if(Tradar::chwila>=chw_pocz)
	{
	setPos(gdzie); setVisible(true); 		prom+=2;
	if(prom==12)grub++;
	else if(prom==16)grub++;
	}

if(prom==20)
	{zakonczyl=true; setVisible(false);}

	
if(Tradar::chwila>=chw_pocz)update();

}//koniec f.advance
//*************************
void Twybuch::paint(QPainter*painter,const QStyleOptionGraphicsItem*option,QWidget*widget)
{
Q_UNUSED(option); Q_UNUSED(widget);
	QPen pisak(kolor,grub);


{//pocz bloku rysujacego
painter->setPen(pisak);

//proste
painter->drawLine(0,-prom,0,prom); //pionowo
painter->drawLine(-prom,0,prom,0); //poziom

//ukosne
painter->drawLine(0.5*prom,-0.5*prom, -0.5*prom,0.5*prom); 
painter->drawLine(0.5*prom,0.5*prom, -0.5*prom,-0.5*prom);

}//koniec bloku rysujacego

}//koniec f.paint
//*************************
QPainterPath Twybuch::shape()const
{
QPainterPath path;
int w{prom*2}; 

QVector<QPointF>kwadrat;

	kwadrat.push_back(QPointF(-w,-w));
	kwadrat.push_back(QPointF(w,-w));
	kwadrat.push_back(QPointF(w,w));
	kwadrat.push_back(QPointF(-w,w));

path.addPolygon(QPolygonF(kwadrat));

return path;
}
//*************************

