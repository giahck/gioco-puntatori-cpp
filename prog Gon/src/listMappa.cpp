/*
 * listMappa.cpp
 *
 *  Created on: 13 giu 2016
 *      Author: giacc_000
 */
#include <iostream>
#include "listMappa.hpp"
using namespace std;

	nodoMappa* listaMappa::posizioneZero()
	{
		nodoMappa * p=NULL;
		if(old==NULL)
		{
			    p=new nodoMappa();		//creo la prima cella
		        p->setX(0);
		        p->setY(0);
		        p->setN(NULL);
		        old=p;
		}
        p->setN(NULL);
        return old;//torna al main con la prima cella creata

	}

	void listaMappa::GiocatorePuntaZero(giocatore*head)//tutti i giocatori vengono puntati alla prima cella (x=0,y=0)
	{
		//gli passo head(contenente tutti i giocatori)
		nodoMappa*ol=old;
		giocatore *r=head;
        if(ol!=NULL){
		while(r!=NULL)
		{
            r->setP(ol);  // setP fa puntare il mio giocatore alla classe nodoMappa nella cella (x=0,y=0)
            r=r->NEXT();
		}  }


	}

	bool listaMappa::punta(char arrow,giocatore*h)
		{  //quindi uso i miei 4 puntatori per vedere se le caselle adiacenti sono nulle
		   // se i 4 puntatori puntano a NULL  restituisco falso, se no faccio puntare il mio giocatore alla cella prescelta
			bool k=true;
		        	nodoMappa *p=NULL;
		        	p=h->PUNTA();//p punta alla cella dove punta il giocatore
			                if(arrow=='w')
							{
			                	 if(p->NORD()==NULL)
			                   		k=false;
			                	 else
			                		 h->setP(p->NORD());
							}
							else if(arrow=='s')
							{
								 if(p->SUD()==NULL)
									 k=false;
								 else
								 h->setP(p->SUD());
							}
							else if(arrow=='a')
							{
	                             if(p->OVEST()==NULL)
	                            	k=false;
	                             else
	                            	 h->setP(p->OVEST());
							}
							else if(arrow=='d')
							{
								 if(p->EST()==NULL)
									 k=false;
								 else
									 h->setP(p->EST());
							}

			                return k; //torna vero se esiste la cella oppure falso se non esiste
		}
	nodoMappa* listaMappa::posizione(char arrow,giocatore*h)
	{/*1)creo la mia cella con un puntatore p
	   2)setto le mie coordinate es(nel caso voglio andare a nord quindi "w", dovrò aumentare la mia vecchia y di +1 e la mia x rimarra la stessa)
	                             es2(nel caso voglio andare a est quindi "D", dovrò aumentare la mia vecchia x di +1 e la mia y rimarra la stessa)
	   3)collego la mia cella alla coda del nodoMappa e sposto il mio giocatore alla nuova cella
	  */
			nodoMappa*p=NULL;
    		p=new nodoMappa;

				if(arrow=='w')
				{
					p->setY(h->PUNTA()->retY()+1);
					p->setX(h->PUNTA()->retX());
				}
				else if(arrow=='s')
				{
                 	p->setY(h->PUNTA()->retY()-1);
                 	p->setX(h->PUNTA()->retX());
				}
				else if(arrow=='a')
				{
				    p->setX(h->PUNTA()->retX()-1);
				    p->setY(h->PUNTA()->retY());
				}
				else if(arrow=='d')
				{
				    p->setX(h->PUNTA()->retX()+1);
				    p->setY(h->PUNTA()->retY());
				}
				p->setN(NULL);
				nodoMappa *tmp=old;
				if(tmp!=NULL)
				{

					while(tmp->NEXT()!=NULL)tmp=tmp->NEXT();
					tmp->setN(p);

					h->setP(p);// il mio giocatore punta alla mia nuova cella quindi si è spostato di stanza in questo momento
				}
				tmp=tmp->NEXT();
               return tmp;//ritorno la mia nuova posizione
	}
	void listaMappa::lineaPuntata(nodoMappa*tmp)
	{
		/*tmp)ha la nuova posizione
		    p)all'inizio punta alla testa della lista mappa
		es(fecendo che  tmp ha come posizione (1,0) cioè sta alla destra dalla cella(0,0)dove punta p,
		   quindi controlero dove tmp a(x-1,y=0) se e vera collego il puntatore ovest da tmp->p e est da p->tmp
		  */
		nodoMappa*p=old;
		    while(p!=NULL){
		    if(p->retY()==(tmp->retY()+1) && p->retX()==tmp->retX())
		    {
                p->setSud(tmp);
                tmp->setNord(p);
		    }
		    if(p->retY()==(tmp->retY()-1) && p->retX()==tmp->retX())
		    {
               p->setNord(tmp);
               tmp->setSud(p);
			}
			if(p->retX()==(tmp->retX()-1) && p->retY()==tmp->retY())
			{
               p->setEst(tmp);
               tmp->setOvest(p);
			}
			if(p->retX()==(tmp->retX()+1) && p->retY()==tmp->retY())
			{
				p->setOvest(tmp);
				tmp->setEst(p);
			}
		    p=p->NEXT();
		    }
	}
	nodoMappa* listaMappa::linea(char arrow,giocatore*h)//funzione base
	{  //gli passo come parametri la mia direzione in cui voglio andare(arrow) e la mia attuale posizione
		nodoMappa *tmp=NULL;
        bool k;
		k=punta(arrow,h);//se torna falso entra nel if se no torno al main tmp =NULL
        if(k==false)
        {
        tmp=posizione(arrow,h);//tmp ha l'ultima posizione
        lineaPuntata(tmp);
        return tmp;//ritorno la nuova posizione per la stampa
        }else
        {
        	return tmp=NULL;
        }
	}
	void listaMappa::stampa()
	{
		nodoMappa*p=old;
		while(p!=NULL)
		{
			p->stampa();
					p=p->NEXT();
		}
	}




