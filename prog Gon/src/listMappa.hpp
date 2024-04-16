/*
 * listMappa.hpp
 *
 *  Created on: 13 giu 2016
 *      Author: giacc_000
 */

#ifndef LISTMAPPA_HPP_
#define LISTMAPPA_HPP_
#include "nodMappa.hpp"
#include "nodGiocatore.hpp"
#include <iostream>
class listaMappa
{
protected:
	nodoMappa *old;

public:
	listaMappa()
{
		old=NULL;
}
	nodoMappa* posizioneZero(); //crea la mia prima stanza (0,0)

	void GiocatorePuntaZero(giocatore*head);//tutti i giocatori vengono puntati alla prima cella (0,0)


	bool punta(char arrow,giocatore*h);//questa funzione controlla se esistono celle adiacenti a quella in cui il giocatore si trova

	nodoMappa* posizione(char arrow,giocatore*h);/*la funzione posizione: mi crea la mia nuova cella nella lista mappa con (x,y)
	                                             pasandogli sempre la mia posizione e la direzione voluta*/

	void lineaPuntata(nodoMappa*tmp);/*la funzione lineaPunta serve per far puntare i miei 4 puntatori della nuova cella creata alle altre rispetive
	                                celle adiacenti(il while serve per far scorere ogni cella della lista mappa perche non sono ordinate)*/

	nodoMappa* linea(char arrow,giocatore*h);//la funzione linea: gestisce se la cella in cui voglio andare esiste altrimenti la crea

	nodoMappa* getOld() {return old;}

	void stampa();

};



#endif /* LISTMAPPA_HPP_ */
