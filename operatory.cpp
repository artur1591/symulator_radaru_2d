#include "operatory.h"

//*************************
ostream&operator<<(ostream&out,QPointF&o)
{
	out<<"(x="<<o.x()<<",y="<<o.y()<<")";

return out;
}
//*************************
/*
ostream&operator<<(ostream&out,Tobiektlatajacy&o)
{//ZAPRZYJAZNIĆ SIE TRZEBA

out<<"id="<<o.id()<<" speed="<<o.speed()
   <<" moment_startu="<<o.moment_startu()
   <<" sciana="<<o.sciana()<<" angle="<<o.angle
   <<" StartX="<<o.StartX()<<" StartY="<<o.StartY
   <<endl
   <<" FinishX="<<o.FinishX
   <<" FinishY="<<o.FinishY
   <<"("<<o.ile_obiektow<<"obiektów)";

return out;
}*/
//*************************
