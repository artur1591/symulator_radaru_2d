#include "radar.h"
#include "operatory.h"
using std::cout;
using std::cerr;
using std::endl;
using std::vector;
//**************************************
//statyczne
unsigned Tradar::chwila{0};
unsigned Tradar::itemCount{0};
unsigned Tradar::ile_wystartowalo{0};
unsigned Tradar::okno_wym_x{600},Tradar::okno_wym_y{700};
QPointF Tradar::lg,Tradar::pg,Tradar::ld,Tradar::pd;
QList<Twybuch*> Tradar::wek_wyb;
//**************************************
void Tradar::argumenty_programu(const QStringList&args)
{
wymuszona_ilosc=0;
/*
mozna wymusic ilosc pojawiajacych sie obiektow w danej jednostce czasu(zmienna ilosc).(ale jesli w losowaniu sie powtorzą to moze ich byc troche mniej)
*/
	if(args.size()>2)
		cerr<<"---za dużo argumentów. ma być 1 liczba dodatnia.---\n";

	if(args.size()==2)
	{

	bool udalo_sie{false};
	wymuszona_ilosc=args.at(1).toInt(&udalo_sie);

	if(!udalo_sie || wymuszona_ilosc<=0)
		{	
		cerr<<"zły argument. ma być 1 liczba dodatnia.\n";
		return; 
		}	

	}//koniec jesli 2 argumenty 

}//koniec f.argumenty_programu
//**************************************
void Tradar::przelicz_punkty_ramki()
{
double wspol{0.75};

	lg.setX(okno_wym_x/2*-wspol);
	lg.setY(okno_wym_y/2*-wspol);

	pg.setX(okno_wym_x/2*wspol);
	pg.setY(okno_wym_y/2*-wspol);

	ld.setX(okno_wym_x/2*-wspol);
	ld.setY(okno_wym_y/2*wspol);

	pd.setX(okno_wym_x/2*wspol);
	pd.setY(okno_wym_y/2*wspol);

}//koniec f.przelicz_punkty_ramki
//**************************************
void Tradar::generuj_starty(vector<unsigned>&mom,int pocz)
{
const int ilosc{30}; 
int ilosc_momentow{0};


if(wymuszona_ilosc>=ilosc)
	{
	cerr<<"===WYMUSZONE STARTY CO 1 sekundę\n";
	for(int a=0; a<ilosc; a++)
		mom.push_back(1+pocz+a*10);
	return;
	}

	if(wymuszona_ilosc==0) 
		ilosc_momentow=losuj_z_zakresu(16,21);
	else 
		ilosc_momentow=wymuszona_ilosc;

for(int a=0; a<ilosc_momentow; a++)
	mom.push_back(pocz+(losuj_z_zakresu(1,ilosc-1))*10);


sort(mom.begin(),mom.end());
mom.erase(std::unique(mom.begin(),mom.end()),mom.end());

}//koniec f.generuj_starty
//**************************************
Tobiektlatajacy* Tradar::wylosuj_obj_poch(unsigned moment)
{
int ktory=losuj_z_zakresu(0,2);
	Tobiektlatajacy*wsk{nullptr};

//zakresy predkości dla kazdego typu obiektow
	int r_pred_min=22,r_pred_max=26;
	int s_pred_min=11,s_pred_max=16;
	int p_pred_min=3,p_pred_max=6;
//oraz kolory
	QColor r_kol(Qt::yellow);
	QColor s_kol(Qt::blue);
	QColor p_kol(Qt::green);

	switch(ktory)
	{
	case 0: wsk=new Trakieta(r_kol,moment,r_pred_min,r_pred_max); break;
	case 1: wsk=new Tsamolot(s_kol,moment,s_pred_min,s_pred_max); break;
	case 2: wsk=new Tptak(p_kol,moment,p_pred_min,p_pred_max); 
	}

return wsk;
}

//**************************************
void Tradar::czas_leci()
{

if(!wek_wyb.isEmpty())
  scena->addItem(wek_wyb.takeFirst());
  
if(ile_wystartowalo==itemCount)
{

ile_wystartowalo=0;

vector<unsigned>momenty;
generuj_starty(momenty,chwila);
itemCount=momenty.size();

//usuwanie ze sceny zakonczonych
Tobiektsceny*wsk{nullptr};
for(int a=0; a<scena->items().size(); a++)
{
wsk=reinterpret_cast<Tobiektsceny*>(scena->items().at(a));

if(wsk->czy_zakonczyl())
	{
	scena->removeItem(wsk); 
	delete wsk; 
	a--;
	}
}

//dodawanie nowych do sceny
for(unsigned a=0; a<itemCount; a++)
scena->addItem(wylosuj_obj_poch(momenty.at(a)));


}//koniec kolejnego dodawania obiektow

chwila++;
}//koniec f.czas_leci
//**************************************
Tradar::Tradar()
{
	scena=new QGraphicsScene(this);

	widok=new QGraphicsView(this);
	widok->setScene(scena);
	widok->resize(okno_wym_x,okno_wym_y);

	argumenty_programu(qApp->arguments());

	rama=new Tramka(Qt::red);
	scena->addItem(rama);

	setMinimumSize(okno_wym_x,okno_wym_y);
	setMaximumSize(okno_wym_x,okno_wym_y);

	przelicz_punkty_ramki();

	timer=new QTimer(this);

	connect(timer,SIGNAL(timeout()),scena,SLOT(advance()));
	connect(timer,SIGNAL(timeout()),this,SLOT(czas_leci()));
	timer->start(100);

	setWindowTitle(tr("Symulator Radaru 2D"));
	show();

}//koniec konstruktora
//**************************************
Tradar::~Tradar()
{
#if INFO_AKTYWNOSCI_DESTRUKTOROW
	cerr<<__func__<<" ";
#endif

//ponizsze delete(petla i 3szt nizej bez wplywu na wyciek pamieci. więc co z nimi?

/*for(auto i:scena->items())
	{
	delete i;
	}*/

	delete timer;	
	delete scena;	
	delete widok; 
}
//**************************************
void Tradar::fun_zamknij()
{
	QMessageBox messageBox;
	messageBox.setWindowTitle(tr("tytul okna kłit"));
	messageBox.setText(tr("naprawdę zamykać?"));
	messageBox.setStandardButtons(QMessageBox::Yes|QMessageBox::No);
	messageBox.setDefaultButton(QMessageBox::No);

	if(messageBox.exec()==QMessageBox::Yes)
		qApp->quit();

}
//**************************************
void Tradar::closeEvent(QCloseEvent*e)
{
	cerr<<"Wciśnij Escape aby zamknąć!\n";
	e->ignore();
}
//**************************************
void Tradar::keyPressEvent(QKeyEvent*event)
{
	if(event->key()==Qt::Key_Escape)fun_zamknij();

	if(event->key()==Qt::Key_F5)	
	{
	cerr<<" =PAUZA= bo F5 (a F6 wznawia)\n";
	timer->stop();
	}

	if(event->key()==Qt::Key_F6)
	{
	cout<<"---wznowienie---\n";
	timer->start();
	}

}//koniec f.keyPressEvent

//**************************************
int Tradar::losuj_z_zakresu(int pocz,int kon)
{

return QRandomGenerator::global()->bounded(pocz,kon+1); 
//bo zapis [pocz,kon)


//poniżej sposób c++. 
/*wymaga #include <random>
	std::random_device rd;
	std::default_random_engine re(rd());
	std::uniform_int_distribution<int> uid(pocz,kon);

return uid(re);*/
}
//**************************************

