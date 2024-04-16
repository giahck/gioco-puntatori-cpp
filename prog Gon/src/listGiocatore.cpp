/*
 * listGiocatore.cpp
 *
 *  Created on: 13 giu 2016
 *      Author: giacc_000
 */
#include <iostream>
#include "listGiocatore.hpp"
using namespace std;

	void lGiocatore::insert(int i) //Inserimento giocatori
	{
		char name[length];

		cout<<"Inserisci il nome del "<<i+1<<" giocatore ";
		do{
		cin>>strcpy(name,name);
        if(strlen(name)<2)
        cout<<"reinserisci nome con almeno 2 lettere ";
		}while(strlen(name)<2);//controllo se ci sono almeno due lettere

		//creazione giocatore
		giocatore * p;
		p=new giocatore();
		p->setI(name);
			p->setN(NULL);
			giocatore *tmp=head;
			if(tmp!=NULL)
			{
				while(tmp->NEXT()!=NULL)
							tmp=tmp->NEXT();
						    tmp->setN(p);
			}
			else
			{
				 head=p;
			}
	}
	void lGiocatore::stampa()
	{
	    giocatore * p=head;
	   cout<<"I giocatori: ";
	    while(p!=NULL)
	    {
	    	p->stampa();			//stampa i giocatori
	    	cout<<" - ";
	    	p=p->NEXT();
	    }
	    cout<<"\nsi trovano tutti nella stanza di INIZIO"<<endl;
	    cout<<"   [x]";

	}





