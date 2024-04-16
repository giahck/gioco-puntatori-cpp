/*
 * stampa.hpp
 *
 *  Created on: 13 giu 2016
 *      Author: giacc_000
 */

#ifndef STAMPA_HPP_
#define STAMPA_HPP_
#include <iostream>
#include "nodMappa.hpp"
#include "nodGiocatore.hpp"
class Stampa
{
protected:
	nodoMappa*Sup,*Inf;
	nodoMappa*old;

	int estremoX,inferioreX;

public:
	Stampa()
{

		estremoX=0;
		inferioreX=0;
  old=NULL;
   Sup=NULL;
   Inf=NULL;
}
	void prendiPos(nodoMappa*tmp,nodoMappa*o);//la funzione prendiPos: prende tutti gli estremi funzione preliminare

	void Cout(giocatore* head,nodoMappa*o);//stampa la mappa ne senso letterario

	void stampaM(giocatore *head);//la funzione stampaM: prende la cella più grande con x y scansiona tutta la riga  della x e poi decrementa di 1 fino alla cella più piccola

};



#endif /* STAMPA_HPP_ */
