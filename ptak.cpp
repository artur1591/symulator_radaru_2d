#include "rakieta.h"
#include "wybuch.h"
using std::cerr;
//*************************
Tptak::Tptak(QColor k,int moment,int pred_min,int pred_max) 
{
	kolor=k;
	sila=1;
	moment_startu=moment;
	speed=Tradar::losuj_z_zakresu(pred_min,pred_max); 

	oblicz_parametry_lotu();
	setVisible(false);
	setRotation(angle);
	setPos(StartX,StartY);

}//koniec konstruktora domniemanego
//*************************
QPainterPath Tptak::shape()const
{
QPainterPath path;

QVector<QPointF> obrys; 
	obrys.push_back(QPointF(-20,26));
	obrys.push_back(QPointF(0,-11));
	obrys.push_back(QPointF(20,26));
	obrys.push_back(QPointF(5,30));
	obrys.push_back(QPointF(-5,30));

path.addPolygon(obrys);

return path;
}//koniec f.shape
//*************************

Tptak::~Tptak()
{
#if INFO_AKTYWNOSCI_DESTRUKTOROW
	cerr<<__func__<<" ";
#endif
}
//*************************
void Tptak::paint(QPainter*painter,const QStyleOptionGraphicsItem*option,QWidget*widget)
{
if(zakonczyl || !wystartowal)return;

Q_UNUSED(option); Q_UNUSED(widget);

	QBrush pisak(kolor);

//bez kolizji
if(scene()->collidingItems(this).size()==1)
		{
		setOpacity(1.0);
		}
else
//jest kolizja czyli
//if(scene()->collidingItems(this).size()>1)
{
int ile_sila1{0},ile_sila2{0},ile_sila3{0};
policz_ile_jakich_jest(ile_sila1,ile_sila2,
ile_sila3,scene()->collidingItems(this));


//przypadek transparentnosc (A)
if(ile_sila1>0 && ile_sila2==0 && ile_sila3==0)
{
//cerr<<"transparentnosc ptaka ";
setOpacity(0.5); pisak.setColor(Qt::red);
}

//przypadek jesli ma zniknac (C)
if(ile_sila2>0 || ile_sila3>0)
if(!zakonczyl)
{
zakonczyl=true; setVisible(false);

Tradar::wek_wyb.push_back(new 
Twybuch(Tradar::chwila,pos(),kolor));
}

}//koniec jesli jest kolizja



{//blok rysujacy
painter->setBrush(pisak);

QVector<QPointF>cialo;

	cialo.push_back(QPointF(-20,26));
	cialo.push_back(QPointF(-3,4));
	cialo.push_back(QPointF(-2,-3));
	cialo.push_back(QPointF(0,-11));
	cialo.push_back(QPointF(2,3));
	cialo.push_back(QPointF(3,4));
	cialo.push_back(QPointF(20,26));
	cialo.push_back(QPointF(3,20));
	cialo.push_back(QPointF(5,30));
	cialo.push_back(QPointF(0,26));
	cialo.push_back(QPointF(-5,30));
	cialo.push_back(QPointF(-3,20));

painter->drawPolygon(QPolygonF(cialo));

}//koniec nowego bolku rysujacego

}//koniec f.paint
//*************************

