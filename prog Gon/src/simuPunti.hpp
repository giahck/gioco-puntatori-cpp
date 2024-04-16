/*
 * simuPunti.hpp
 *
 *  Created on: 13 giu 2016
 *      Author: giacc_000
 */

#ifndef SIMUPUNTI_HPP_
#define SIMUPUNTI_HPP_
#include <iostream>
#include "nodMappa.hpp"
#include "nodGiocatore.hpp"
class Simulazione
{
protected:
	giocatore *head,*gioco;
	int maxBonus,maxGioco;	//maxBonus è il bonus, il maxGioco è la durata massima del gioco
public:
	Simulazione(giocatore *Head,int maxbonus,int maxgioco)
{
		maxBonus=maxbonus;	
		maxGioco=maxgioco;
		gioco=NULL;
		head=Head;
}
	giocatore* elimina(giocatore *gioco); //funzione che elimina un giocatore
	 void bonus (giocatore*gioco);	//funzione bonus
	 bool funzione_random(giocatore *gioco); //funzione random 
     giocatore* gethead2(){return gioco;} 
	 giocatore* gethead() {return head;}
};




#endif /* SIMUPUNTI_HPP_ */
