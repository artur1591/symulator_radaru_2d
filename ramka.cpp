#include "ramka.h"
#include "radar.h"
using std::cerr;
//********************
Tramka::Tramka(QColor k)
{kolor=k;}
//********************
Tramka::~Tramka()
{
#if INFO_AKTYWNOSCI_DESTRUKTOROW
	cerr<<__func__<<" ";
#endif
}
//********************
QRectF Tramka::boundingRect()const
{
int obwodka{40};

	return QRectF(Tradar::lg.x()-obwodka,Tradar::lg.y()-obwodka,Tradar::pg.x()-Tradar::lg.x()+(2*obwodka),Tradar::pd.y()-Tradar::pg.y()+(2*obwodka));
}
//********************
void Tramka::paint(QPainter*painter,const QStyleOptionGraphicsItem*option,QWidget*widget)
{
Q_UNUSED(option);
Q_UNUSED(widget);


QPen piuro; //oczywiście wiem 
piuro.setColor(kolor);
piuro.setWidth(4);
painter->setPen(piuro);

	painter->drawLine(Tradar::lg,Tradar::pg);
	painter->drawLine(Tradar::lg,Tradar::ld);
	painter->drawLine(Tradar::pg,Tradar::pd);
	painter->drawLine(Tradar::ld,Tradar::pd);

}//koniec f.paint
//********************

