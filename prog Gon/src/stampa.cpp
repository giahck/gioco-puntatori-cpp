/*
 * stampa.cpp
 *
 *  Created on: 13 giu 2016
 *      Author: giacc_000
 */
#include <iostream>
#include "stampa.hpp"
#include <cstring>
using namespace std;

	void Stampa::prendiPos(nodoMappa*tmp,nodoMappa*o)//precauzioni per la stampa
	{/*suggerimento(farsi un disegnino delle celle(x,y))
	   1)estremoX e' una variabile che prende la x più piccola es(cella1(0,1) cella2(-1,-3), prendera x=-1)
	   2)inferioreX e' una variabile che prende la x più grande es(cella1(0,1) cella2(-1,-3), prendera x=0)
estremo superiore sinistro 3)sup è un puntatore che prende la y più grande e nello stesso momento la x più piccola es((cella1(0,1) cella2(-1,-1), prendera y=1 e x=0)
estremo inferiore destro   4)inf è un puntatore che prende la y più piccola e nello stesso momento la x più grande es((cella1(0,1) cella2(3,-1), prendera y=-1 e x=3)
	 */
		old=o;
        if(Sup==NULL||Inf==NULL)
        {
        	Sup=old;
            Inf=old;
        }
        	//tmp->stampa();
		cout<<endl;
		if(tmp!=NULL)
        {
			if(tmp->retY() > Sup->retY())/*se la mia y è maggiore della y di sup  allora sup puntera alla y più alta
			                            (capitera solo alla prima persona che sale ogni volta di y+1)*/
			{
				Sup=tmp;          //sup sara la cella più alta
			}
			else if(tmp->retX() < Sup->retX()&&tmp->retY()==Sup->retY())//se la mia x è minore della vecchia x di qualunque altro giocatore, la y è quella con il valore maggiore
			{
				Sup=tmp;                                                          //sup  sara la cella più alta a sinistra
			}


			if(tmp->retY()<Inf->retY())/*se la mia y è minore della y di inf  allora inf puntera alla y più bassa
			                           (capitera solo alla prima persona che scende ogni volta di y-1)*/
			{
				Inf=tmp;   //inf sara la cella più bassa
			}
			else if(tmp->retX() > Inf->retX()&&tmp->retY()==Inf->retY())//se la mia x è maggiore della vecchia x di qualunque altro giocatore e la y è quella con il valore minore
			{
				Inf=tmp;  //inf sara la cella più bassa a destra
			}
			if(tmp->retX()<estremoX)//ha la x più pù picola non importa la y
			estremoX=tmp->retX();
			if(tmp->retX()>inferioreX)//ha la x più grande non impora la y
				inferioreX=tmp->retX();

        }
	}
	void Stampa::Cout(giocatore* head,nodoMappa*o)
	{
         giocatore*h=head;//h ha l'intera lista di giocatori
         bool k=false;
         char spezzato[10]= {0};

         int i=0;
          while(h!=NULL)// (i) serve per contare quanti giocatori ci sono in quella cella
          {         //controlla se c'è qualche giocatore in quella posizione, quindi per ogni cella fa la scansione di tutto head
        	 if(h->PUNTA()==o)
        	  {
        	    k=true;
        	    i++;
        	  }
        	 //else
        	 h=h->NEXT();

          }
               h=head;

                        int count=0,lunga=0,spazzio=0,r;

                       if(k==false)//se non c'è nessun nome in quella cella allora stampo la mia stanza vuota
                        {
                        	cout<<"   [x]    ";//o uno spazio di 10 carateri
                        }
                        else//nel caso ci fossero uno o piu giocatori quindi la i >0
                        {
                        	while(h!=NULL)//faccio scansionare tutta la mia lista di giocatori
                        	{
                        	if(h->PUNTA()==o)//vedo se quel giocatore è esistente
                             {
                        		if(i<2)//nel caso in cui nella cella c'è un solo giocatore
                        	                        		{

                        			lunga=strlen(h->getNome());//calcolo la lungezza del nome
                        	                        			 spazzio=4-(lunga/2);//stampo il nome centrato in uno spazio da 10
                        	                        			//es..(luca=4) mi verra scritto "  luca   "*/
                        	                        			 for( r=0;r<spazzio;r++)
                        	                                      cout<<" ";//"  "
                        	                        			 h->stampa();//"  luca"
                        	                        			 spazzio=lunga+r;//calcolo lo spazio mancante nel caso di (luca) avro 4 spazzi dopo il nome
                        	                        			 for(r=spazzio;r<=9;r++)
                        	                        				 cout<<" ";//"  luca    "
                        	                        			 k=false;
                                                      r=0;lunga=0,spazzio=0;

                        	                        		}
                        		else if(i<3&&i>1)//nel caso ci fossero 2 giocatori nella stessa cella
                        	    {             //esempio con (gianluca,ana)
                                            strncpy(spezzato,h->getNome(),10/i-1);//nel caso ci fossero nomi che superano i 4 caratteri li taglio es(gian,ana)
                                            lunga=strlen(spezzato);//mi controlla la lunghezza del nome, nel caso in cui uno dei due nomi è minore di 4 aggiungo dei spazi vuoti
                                            lunga=4-lunga;//vedo quanti spazi occorono es(gian=0 niente spazio; ana=1 quindi ha bisogno di uno spazio)
                                            if(spazzio==0)/*metto una variabile che si incrementa di 1 perche: visto che devo inserire 2 nomi prima inserisco lo spazio nel caso
                                            	ci serva  e quindi farò il mio primo for mettendo gli eventuali spazi e poi il primo nome, e ci lascio uno spazio */
                                              {
                                            	for(int r=lunga;r>0;r--)//il for mi parte da lungezza fino ad arrivare a zero, nel caso di (gian) non entra per niente
                                                 {cout<<" "; }
                                                 cout<<spezzato<<" ";//es("gian ")
                                              }
                                            else/*ora al secondo nome faccio la stessa cosa */
                                              {
                                            	cout<<spezzato;//es(gian ana) ma cosi non ricopro i miei 10 spazi
                                               for(int r=lunga;r>=0;r--)//lunga=1 quindi farà 2 cicli anche se a noi ne interessa 1 (per fare i nomi della stessa lungezza e per arrivare a 10 spazi)
                                               cout<<" ";//es("gian ana  ")
                                              }spazzio++;
                                              k=false;
                        	    }
                        	    else if(count<3)//nel caso ci fossero da 3 a più nomi nella stessa cella entrerà in questo if solo 3 volte
                        	    {
                        	    	//es(franca,giovanni,anna)
                        	    	strncpy(spezzato,h->getNome(),2);//i nomi vengono tagliati in due lettere (fr,gi,an)
                        	    	cout<<spezzato;//stampo il nome dimezzato
                        	    	if(count<2)//faccio l'if in modo tale che lo spazio non vada alla fine del terzo nome
                        	    	cout<<" ";
                        	    	k=true;
                        	    	count++;
                        	    }
                             }


                        	 h=h->NEXT();
                             }
                        	if(k==true)//nel caso i>2
                        	{if(i>3)//se sono di più di tre giocatori scriverò a fianco il numero giocatori restanti
                               //ess..(gianluca,roberto,franca,pino,lorenzzo)=("gi ro fr+2")

                        		cout<<"+"<<i-3;
                        	else
                        		cout<<"  ";}//nel caso c'è ne sono solo tre ci metto 2 spazzi vuoti per arrivare a 10
                        }
	}
	void Stampa::stampaM(giocatore *head)//funzione per stampare la mappa
	{ //IMPORTANTE:ogni cella comporta 10 spazi, che comprendono o solo la 'x' o solo il nome, per ogni ciclo dovro inserire sempre 10 spazi(vuoti o con le lettere,per poter avere le colonne tutte nella stessa righa)
        nodoMappa*o=old;
        int x=estremoX,y=Sup->retY();
        while(y>=Inf->retY())//la funzione finisce quando arriva alla y più piccola, ad ogni ciclo la y decrementa di uno, alla fine della scansione della x
        {
        	x=estremoX;
        	o=old;
        	while(x<=inferioreX)//la funzione finisce quando arriva alla x più piccola quindi ogni volta aumento la x di +1
        	{
        		//scansiono più volte la mia lista mappa  perche non è ordinata, il NULL è quando finisce di scansionare la lista però nn trova niente quindi li c'è un buco e quindi inseriro dopo uno spazzio vuoto
				if((x==o->retX()&&y==o->retY())|| o->NEXT()==NULL)//entra quando scansionando con il puntatore la x e la y risultano uguali,  quando la o incontra la casella della (x,y) più grande
        		{                                                  //per poi scalare la mia x+1 oppure entra nel caso o=null quindi tutte le caselle sono state scansionate(quando non c'è una cella)

        			if(x==o->retX()&&y==o->retY())//se la mia cella della o è uguale alla x e alla y vuol dire che la cella esiste, allora stampo
        				{
        				  Cout(head,o);//serve per stampare il nome o la il carattere [x]
        				}
        			else	//altrimenti inserisco degli spazi per il successivo 
        				cout<<"          ";//inserisco 10 spazi vuoti

        		o=old;
        			x=x+1;
        		}
        		else//se non sono uguali vado alla cella successiva
        		o=o->NEXT();

        	}
        	y=y-1;
        	cout<<endl<<endl;
        }
        cout<<endl;
	}



