#include "rakieta.h"
using std::cerr;
//*************************
Trakieta::Trakieta(QColor k,int moment,int pred_min,int pred_max)
{
	kolor=k;
	sila=3;
	moment_startu=moment;
	speed=Tradar::losuj_z_zakresu(pred_min,pred_max); 

	oblicz_parametry_lotu();
	setVisible(false);
	setRotation(angle);
	setPos(StartX,StartY);

}//koniec konstruktora domniemanego
//*************************
QPainterPath Trakieta::shape()const
{
QPainterPath path;

QVector<QPointF>obrys;
	obrys.push_back(QPointF(0,-16));
	obrys.push_back(QPointF(4,-5));
	obrys.push_back(QPointF(4,19));
	obrys.push_back(QPointF(-4,19));
	obrys.push_back(QPointF(-4,-5));

path.addPolygon(QPolygonF(obrys));

return path;
}//koniec f.shape
//*************************
Trakieta::~Trakieta()
{
#if INFO_AKTYWNOSCI_DESTRUKTOROW
	cerr<<__func__<<" ";
#endif
}
//*************************
void Trakieta::paint(QPainter*painter,const QStyleOptionGraphicsItem*option,QWidget*widget)
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
if(ile_sila1==0 && ile_sila2==0 && ile_sila3>0)
{
//cerr<<"transparentnosc rakiety ";
setOpacity(0.5); pisak.setColor(Qt::red);
}


}//koniec jesli jest kolizja




{ //blok rysujacy
painter->setBrush(pisak);

QVector<QPointF> punkty_rakety;
	punkty_rakety.push_back(QPointF(-4,15));
	punkty_rakety.push_back(QPointF(-4,-5));
	punkty_rakety.push_back(QPointF(0,-16));
	punkty_rakety.push_back(QPointF(4,-5));
	punkty_rakety.push_back(QPointF(4,15));

painter->drawPolygon(QPolygonF(punkty_rakety));

QVector<QPointF> wydech_rakety;
wydech_rakety.push_back(QPointF(-4,15));


wydech_rakety.push_back(QPointF(4,15));
wydech_rakety.push_back(QPointF(4,19));
wydech_rakety.push_back(QPointF(3,19));
wydech_rakety.push_back(QPointF(3,16));
wydech_rakety.push_back(QPointF(1,16));
wydech_rakety.push_back(QPointF(1,19));
wydech_rakety.push_back(QPointF(-1,19));
wydech_rakety.push_back(QPointF(-1,16));
wydech_rakety.push_back(QPointF(-3,16));
wydech_rakety.push_back(QPointF(-3,19));
wydech_rakety.push_back(QPointF(-4,19));

painter->drawPolygon(QPolygonF(wydech_rakety));
}//koniec bloku rysujacego

}//koniec f.paint
//*************************

