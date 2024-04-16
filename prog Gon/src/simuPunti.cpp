/*
 * simuPunti.cpp
 *
 *  Created on: 13 giu 2016
 *      Author: giacc_000
 */
#include <iostream>
#include <ctime>
#include <cstdlib>
#include "simuPunti.hpp"
using namespace std;


	giocatore* Simulazione::elimina(giocatore *gioco)//eliminazione giocatore
	{
        bool t=false;
		giocatore *p=head,*old=NULL;
		old =new giocatore();
		old->setN(head);
		head=old;
		while(p!=NULL&&t==false)
		{
			if(p==gioco)
			{
				if(gioco->NEXT()!=NULL)
				gioco=gioco->NEXT();
				old->setN(p->NEXT());
				delete p;
				p=old->NEXT();

			     t=true;
			}
			else
			{
				old=p;
				p=p->NEXT();
			}
		}

         p=head->NEXT();
         delete head;
         head=p;
          return head;
	}
	 void Simulazione::bonus (giocatore*gioco) //funzione bonus
	 {
	  	 giocatore*p=head;
	  	 int somma=maxBonus;			//la somma prende il valore della variabile maxBonus
	  	 while (p!=NULL){
	  		 if (somma<p->getPunti())			//se la somma è minore dei punti accumulati allora il valore della variabile somma viene aggiornato
	  			 somma=p->getPunti();
	  			 p=p->NEXT();

	  	 }
	  	p=head;
	  	while (p!=NULL)
	  	{
	     	if(somma==p->getPunti()&&p!=gioco)	//se la somma è uguale ai punti allora tolgo un punto al giocatore che ne ha di più
	  	    {
	  	    	p->setPunti(p->getPunti()-1);
	  	       p->stampa();cout<<": ha perso 1 punto -- con totale "<<p->getPunti()<<endl;
	     	}
	  	   p=p->NEXT();
	  	 }
	 }
	 bool Simulazione::funzione_random(giocatore *gioco){ //funzione creazione numeri random
		 //gioco è il giocatore corrente
                     bool k=false;
	                 srand(time(0));			//genera numeri random
	             int random, dado1, dado2, somma;

	             random=rand() % 12+1;	//i numeri random si generano tra 1 e 12
	                cout<<"Il numero random e': "<<random;

	                dado1=rand() % 6+1;
	                dado2=rand() % 6+1;			//genera numeri random per i due dadi
	               cout<<"\nDado 1: "<<dado1;
	                cout<<"\nDado 2: "<<dado2;
	            somma=dado1+dado2;		//somma dei risultati dei due dadi

                      cout<<endl;

                      if(dado1==6 && dado2==6 && random==6)			// se i valori dei due dadi e del numero random coincidono (6,6,6) allora il giocatore viene eliminato
                      {
                    	  cout<<"Sei stato eliminato dal gioco"<<endl;
                      elimina(gioco);}
                      else
                      {
                       if(somma>=random)			//se la somma dei dadi è maggiore o uguale del numero random allora guadagno un punto
	                	{gioco->setPunti(gioco->getPunti()+1);
	                	cout<<"\nHai guadagato 1 punto\n";
	                	}
	             if(dado1==dado2)
	             {
	                    bonus(gioco);			//se il risultato dei due dadi sono uguale allora guadagno il bonus
	             }

	             cout<<"Il tuo totale punti e' "<<gioco->getPunti()<<endl;		//stampa a video il totale dei punti
                      }
                      if(gioco->getPunti()>=maxGioco||head->NEXT()==NULL)	//ritorna il vincitore
                                     k=true;

                    return k;
	  }




