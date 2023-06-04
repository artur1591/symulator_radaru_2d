#include "obiekt_sceny.h"
//*****************************
Tobiektsceny::Tobiektsceny():
zakonczyl(false)
{}
//*****************************
Tobiektsceny::~Tobiektsceny()
{
#if INFO_AKTYWNOSCI_DESTRUKTOROW
	cerr<<__func__<<" ";
#endif
}
//*****************************
bool Tobiektsceny::czy_zakonczyl()
{return zakonczyl;}
//********************

