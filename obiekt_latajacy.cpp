#include "obiekt_latajacy.h"
#include "radar.h"
#include "operatory.h"
using std::cout;
using std::cerr;
using std::endl;
using typ1=Tobiektlatajacy;
//***************************
Tobiektlatajacy::Tobiektlatajacy():wystartowal(false)
{}
//**************************************
void Tobiektlatajacy::policz_ile_jakich_jest(int&ile_sila1, int&ile_sila2,int& ile_sila3, QList<QGraphicsItem*>lista)
{
for(auto i:lista)
	{
	if(reinterpret_cast<typ1*>(i)->jaka_sila()==1)ile_sila1++;
	if(reinterpret_cast<typ1*>(i)->jaka_sila()==2)ile_sila2++;
	if(reinterpret_cast<typ1*>(i)->jaka_sila()==3)ile_sila3++;
	}

}//koniec f.policz_ile_jakich_jest
//********************
int Tobiektlatajacy::jaka_sila()
{return sila;}
//********************
QRectF Tobiektlatajacy::boundingRect()const
{
	int bok{46};

return QRectF(-bok/2,-bok/2,bok,bok);
}
//********************
Tobiektlatajacy::~Tobiektlatajacy()
{
#if INFO_AKTYWNOSCI_DESTRUKTOROW
	cerr<<__func__<<" ";
#endif
}
//********************
void Tobiektlatajacy::oblicz_parametry_lotu() 
{
sciana=Tradar::losuj_z_zakresu(0,3);
int toler{10}; //zeby nie startowal rownolegle do swojej sciany

if(sciana==0)
	{
	angle=Tradar::losuj_z_zakresu(90+toler,270-toler);
	StartX=Tradar::losuj_z_zakresu(Tradar::lg.x(),Tradar::pg.x());
	StartY=Tradar::pg.y();
	}

if(sciana==1)
	{
	angle=Tradar::losuj_z_zakresu(180+toler,360-toler);
	StartX=Tradar::pg.x();
	StartY=Tradar::losuj_z_zakresu(Tradar::pg.y(),Tradar::pd.y());
	}

if(sciana==2)
	{
	if(Tradar::losuj_z_zakresu(0,1))
		angle=Tradar::losuj_z_zakresu(270+toler,360);
	else
		angle=Tradar::losuj_z_zakresu(0,90-toler);
	StartX=Tradar::losuj_z_zakresu(Tradar::ld.x(),Tradar::pd.x());
	StartY=Tradar::ld.y();
	}

if(sciana==3)
	{
	angle=Tradar::losuj_z_zakresu(toler,180-toler);
	StartX=Tradar::ld.x();
	StartY=Tradar::losuj_z_zakresu(Tradar::lg.y(),Tradar::ld.y());
	}

}//koniec f.oblicz_parametry_lotu
//********************
bool Tobiektlatajacy::czy_osiagnal_koniec(QPointF poz)
{

if(sciana==0) //gorna
	if(poz.y()>Tradar::ld.y() || poz.x()>Tradar::pd.x() || poz.x()<Tradar::ld.x()) return true;

if(sciana==1) //prawa
	if(poz.x()<Tradar::ld.x() || poz.y()<Tradar::pg.y() || poz.y()>Tradar::pd.y()) return true;

if(sciana==2) //dolna
	if(poz.y()<Tradar::lg.y() || poz.x()>Tradar::pg.x() || poz.x()<Tradar::lg.x()) return true;

if(sciana==3) //lewa
	if(poz.x()>Tradar::pg.x() || poz.y()>Tradar::pd.y() || poz.y()<Tradar::pg.y()) return true;

return false;
}
//********************
bool Tobiektlatajacy::czy_wystartowal(){return wystartowal;}
//********************
void Tobiektlatajacy::advance(int phase)
{
if(!phase || zakonczyl)return;

if(wystartowal)
{
	if(czy_osiagnal_koniec(this->pos()))
	{
	zakonczyl=true; 
	setVisible(false);
	}
	else
		setPos(mapToParent(0,-speed));

}
else if(Tradar::chwila==moment_startu)
	{
	wystartowal=true;
	setVisible(true);
	Tradar::ile_wystartowalo++;
	}

}//koniec f.advance
//********************

