#include "samolot.h"
#include "radar.h"
using std::cerr;
//*************************
Tsamolot::Tsamolot(QColor k,int moment,int pred_min,int pred_max)
{
	kolor=k;
	sila=2;
	moment_startu=moment;
	speed=Tradar::losuj_z_zakresu(pred_min,pred_max); 

	oblicz_parametry_lotu();
	setVisible(false);
	setRotation(angle);
	setPos(StartX,StartY);

}//koniec konstruktora domniemanego
//*************************
QPainterPath Tsamolot::shape()const
{
QPainterPath path;

QVector<QPointF>obrys;
	obrys.push_back(QPointF(-4,20));
	obrys.push_back(QPointF(4,20));
	obrys.push_back(QPointF(16,-2));
	obrys.push_back(QPointF(16,2));
	obrys.push_back(QPointF(12,20));
	obrys.push_back(QPointF(-12,20));
	obrys.push_back(QPointF(-16,2));
	obrys.push_back(QPointF(-16,-2));

path.addPolygon(QPolygonF(obrys));

return path;
}//koniec f.shape
//*************************
Tsamolot::~Tsamolot()
{
#if INFO_AKTYWNOSCI_DESTRUKTOROW
	cerr<<__func__<<" ";
#endif
}
//*************************
void Tsamolot::paint(QPainter*painter,const QStyleOptionGraphicsItem*option,QWidget*widget)
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
if(ile_sila1==0 && ile_sila2>0 && ile_sila3==0)
{
//cerr<<"transparentnosc samolotu ";
setOpacity(0.5); pisak.setColor(Qt::red);
}

//przypadek jesli ma zniknac (C)
if(ile_sila3>0)
if(!zakonczyl)
{
zakonczyl=true; setVisible(false);

Tradar::wek_wyb.push_back(new Twybuch(Tradar::chwila,pos(),kolor));
}


}//koniec jesli jest kolizja


{ //blok rysujacy
painter->setBrush(pisak);

//kadłub:
	painter->drawEllipse(-4,-20,8,8);
	

QVector<QPointF> punkty_kadluba;
	punkty_kadluba.push_back(QPointF(-4,-16));
	punkty_kadluba.push_back(QPointF(4,-16));
	punkty_kadluba.push_back(QPointF(4,5));
	punkty_kadluba.push_back(QPointF(0,20));
	punkty_kadluba.push_back(QPointF(-4,5));

	painter->drawPolygon(QPolygonF(punkty_kadluba));
//przednie skrzydła
	QVector<QPointF>lewe_skrzydlo_front;

	lewe_skrzydlo_front.push_back(QPointF(-4,-12));
	lewe_skrzydlo_front.push_back(QPointF(-4,-3));
	lewe_skrzydlo_front.push_back(QPointF(-16,2));
	lewe_skrzydlo_front.push_back(QPointF(-16,-2));

	painter->drawPolygon(QPolygonF(lewe_skrzydlo_front));

	QVector<QPointF>prawe_skrzydlo_front;

prawe_skrzydlo_front.push_back(QPointF(4,-12));
	prawe_skrzydlo_front.push_back(QPointF(4,-3));
	prawe_skrzydlo_front.push_back(QPointF(16,2));
	prawe_skrzydlo_front.push_back(QPointF(16,-2));
		
	painter->drawPolygon(QPolygonF(prawe_skrzydlo_front));
//silniki:
//lewe
	painter->drawRect(-13,0,2,2);
	painter->drawRect(-9,-2,2,2);
//prawe
	painter->drawRect(7,-2,2,2);
	painter->drawRect(11,0,2,2);
//skrzydla tylnie
		QVector<QPointF>lewe_skrzydlo_rear;

	lewe_skrzydlo_rear.push_back(QPointF(-12,17));
	lewe_skrzydlo_rear.push_back(QPointF(0,10));
	lewe_skrzydlo_rear.push_back(QPointF(0,17));
	lewe_skrzydlo_rear.push_back(QPointF(-12,20));

	painter->drawPolygon(QPolygonF(lewe_skrzydlo_rear));

		QVector<QPointF>prawe_skrzydlo_rear;
		
	prawe_skrzydlo_rear.push_back(QPointF(12,17));
	prawe_skrzydlo_rear.push_back(QPointF(0,10));
	prawe_skrzydlo_rear.push_back(QPointF(0,17));
	prawe_skrzydlo_rear.push_back(QPointF(12,20));

	painter->drawPolygon(QPolygonF(prawe_skrzydlo_rear));
}//koniec bloku rysujacego

}//koniec f.paint
//*************************

