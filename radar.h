#ifndef RADAR_H
#define RADAR_H

#include <QMessageBox> 
#include <QRandomGenerator>
#include <algorithm>
#include <QKeyEvent>
#include <QTimer>
#include <QGraphicsScene>
#include <QGraphicsView>
#include "wybuch.h"
#include "obiekt_latajacy.h" 
#include "rakieta.h"
#include "samolot.h"
#include "ptak.h"
#include "ramka.h"

class Twybuch;
//*******************
using typ1=Tobiektlatajacy;
//**************************
#define INFO_AKTYWNOSCI_DESTRUKTOROW 0
//**************************
class Tradar final:public QWidget
{
	Q_OBJECT

public:
	Tradar();
	~Tradar()override;
	static int losuj_z_zakresu(int pocz,int kon);
	void argumenty_programu(const QStringList&);
	static unsigned chwila;
	static unsigned itemCount;
	static unsigned ile_wystartowalo;
	static unsigned okno_wym_x,okno_wym_y;
	static QPointF lg,pg,ld,pd;
	static QList<Twybuch*> wek_wyb;

private slots:
	void fun_zamknij();
	void generuj_starty(std::vector<unsigned>&mom,int pocz);
	void czas_leci();
	Tobiektlatajacy* wylosuj_obj_poch(unsigned moment);
	void przelicz_punkty_ramki();
	void keyPressEvent(QKeyEvent*e);
	void closeEvent(QCloseEvent*e);

private:
	QGraphicsView*widok;
	QGraphicsScene*scena;
	Tramka*rama;
	QTimer*timer;
	unsigned wymuszona_ilosc;
	
};//koniec klasy Tradar
//**************************************
#endif 
