/*
 * nodGiocatore.hpp
 *
 *  Created on: 13 giu 2016
 *      Author: giacc_000
 */

#ifndef NODGIOCATORE_HPP_
#define NODGIOCATORE_HPP_
#include <cstring>
#include "nodMappa.hpp"
#include <iostream>
const int length=10;//max lunghezza nome
//nodo in cui si inseriscono i nomi dei giocatori
class giocatore			//classe giocatore
{
protected:
	char nome[length];	//nome del giocatore
	int lunghezza;		//lunghezza del nome del giocatore
	giocatore *next;	//puntatore al giocatore successivo
	nodoMappa *punta;	//puntatore alla cella della mappa
	int punti;	//punti

public:
	giocatore(){punti=0;punta=NULL; next=NULL; lunghezza=0;}	//costruttore giocatore
	void setI(char Name[])	{		strcpy(nome,Name); lunghezza=strlen(nome);	}	//copio il nome del giocatore in Name[], calcolo la lunghezza del nome
	void setN(giocatore*Next)	{		next=Next;	}	//puntatore giocatore successivo
	void setP(nodoMappa*Punta)	{		punta=Punta;	}	//setta la posizione di ogni giocatore
	char* getNome()    {    	return nome;    }	//ritorna il nome
	int getlunghezza(){ return lunghezza;	}	//ritorna la lunghezza del nome

    giocatore*NEXT()    {    	return next;    }	
    nodoMappa *PUNTA(){return punta;} //ritorna il puntatore (ci dice dove punta il giocatore)
    void stampa();
    void setPunti(int Punti){ punti=Punti;   }	//setta i punti
    int getPunti(){ return punti;    }	//stampa i punti

};



#endif /* NODGIOCATORE_HPP_ */
