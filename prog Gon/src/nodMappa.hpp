/*
 * nodMappa.hpp
 *
 *  Created on: 13 giu 2016
 *      Author: giacc_000
 */

#ifndef NODMAPPA_HPP_
#define NODMAPPA_HPP_
#include <iostream>

//il nodo della mia mappa con i 4 puntatori per collegarli tra di loro e il next che fa da lista

class nodoMappa
{
protected:
	nodoMappa *next;		//puntatori di ogni cella, utili per collegare le celle adiacenti tra di loro
	nodoMappa *nord;
	nodoMappa *sud;
	nodoMappa *ovest;
	nodoMappa *est;
	int x,y;
public:
	nodoMappa(){x=0;y=0; next=NULL;nord=NULL;est=NULL;sud=NULL;ovest=NULL;}	//costruttore con puntatori uguali a NULL
	void setX(int X)	{		x=X;	}	//copia il valore della x nella variabile X
	void setY(int Y)	{		y=Y;	}	//copia il valore della y nella variabile Y
	int retX(){return x;}	//ritorna x della mappa
	int retY(){return y;}	//ritorna y	della mappa

	nodoMappa *NEXT(){	return next;}    //ritorna il puntatore della mappa
	void setN(nodoMappa*Next)	{		next=Next;	}	

	nodoMappa *NORD(){return nord;}
	void setNord(nodoMappa*Nord)	{		nord=Nord;	}	//collega le celle a Nord

	nodoMappa *SUD(){return sud;}
	void setSud(nodoMappa*Sud)	{		sud=Sud;	}	//collega le celle a Sud

	nodoMappa *OVEST(){return ovest;}
	void setOvest(nodoMappa*Ovest)	{		ovest=Ovest;	} //collega le celle ad Ovest

	nodoMappa *EST(){return est;}
	void setEst(nodoMappa*Est)	{		est=Est;	}	//collega le celle ad Est

	void stampa();

};

#endif /* NODMAPPA_HPP_ */
