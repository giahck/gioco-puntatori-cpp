/*
 * listGiocatore.hpp
 *
 *  Created on: 13 giu 2016
 *      Author: giacc_000
 */

#ifndef LISTGIOCATORE_HPP_
#define LISTGIOCATORE_HPP_
#include "nodGiocatore.hpp"
#include <iostream>
class lGiocatore
{
protected:
	giocatore *head;  //è la lista del giocatore
public:
	//inserimento dei giocatori nella lista giocatore
	lGiocatore(){head=NULL;}
	void insert(int i);
    void stampa();

	 giocatore* gethead() {return head;}

};



#endif /* LISTGIOCATORE_HPP_ */
