//============================================================================
// Name        : prog.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================




/*Benvenuti alla prova di "Gon la fine".
Questo gioco è molto semplice e segue alcune regole basilari.
Prima di tutto bisogna specificare che livello di giocabilita desidera,(scegliendo in tre casi)
poi quantigiocatori partecipano; Dopodichè ogni giocatore inserirà il proprio nome.
Ogni personaggio del gioco può muoversi tra le stanze tramite i tasti sottoindicati. All'entrata nella stanza del giocatore
comparirà un numero random, e il giocatore tirerà due dadi: se la somma dei dadi è più alta del numero random allora si
totalizzerà un punto, altrimenti nulla.
Se i numeri dei dadi lanciati dal giocatore sono uguali otterrà un bonus, e si toglierà un punto a ciascun giocatore
partaendo da una sognlia(in base all'ivello indicato).
Se vengono lanciati dal giocatore, tramite i dadi, due 6 e il numero random è 6, si perde la partita.
Buon divertimento.*/


#include <iostream>
#include "simuPunti.hpp"
#include "listMappa.hpp"
#include "listGiocatore.hpp"
#include "stampa.hpp"
#include <windows.h>
using namespace std;
int maxBonus=7,maxGioco=13;
int n;//numero giocatori
void difficolta()				//funzione che permette di scegliere la difficoltà del gioco
{
	int tmp;
    cout<<"scegli la durata del gioco, piu' e' lunga e' pie' hai possibbilita' di vittoria \ndigita 1 - 2 - 3\n";
    cout<<"1)breve (chi arriva prima a 7)\n";
    cout<<"2)media (chi arriva prima a 10)\n";
    cout<<"3)lungha (chi arriva prima a 13)\n";
     cin>>tmp;			//scelta durata del gioco
    if(tmp==1)	//se si inserisce 1 la durata del gioco è breve
    {

    	maxBonus=maxBonus-4;			//i rispettivi valori di punteggio max e bonus vengono modificati in base alla durata del gioco scelto
    	maxGioco=maxGioco-6;
    }
    else if(tmp==2)
    {
    	maxBonus=maxGioco-3;
    	maxGioco=maxBonus-2;
    }
    else
    {
    	maxBonus+=0;
        maxGioco+=0;
    }
}
int main() {

	cout<<"Benvenuto nel gioco GON"<<endl;
	difficolta();	//stampa a video la funzione precedentemente descritta


    cout<<"Quanti giocatori partecipano? ";
    cin>>n;
	lGiocatore ins;		//viene inserito il giocatore in lista

    for(int i=0;i<n;i++)	//contatore che calcola quanti giocatori devono essere ancora inseriti
								//(es. se inserisco 3 giocatori mi stamperà "inserisci nome" per tre volte)
    ins.insert(i);

    listaMappa line;
    nodoMappa *old=line.getOld();//mi da old(classe linea)
    line.posizioneZero();//crea la posizione 0 della linea

    giocatore* head = ins.gethead();  // mi da head(classe giocatori)

   Stampa printMap=Stampa();	//stampa la mappa

    //mappa con inizio
    giocatore * h=head;//head prende h
    nodoMappa *o=old;//old prende o
    PlaySound(TEXT("partita.wav"), NULL,SND_LOOP|SND_ASYNC);	//la musica in sottofondo è impostata a LOOP

           ins.stampa();
        cout<<"\ni tasti per caminare sono: \n \t w ^ \n a <-\t s | \td->"<<endl;




       Simulazione gioca=Simulazione(head,maxBonus,maxGioco);

            	line.GiocatorePuntaZero(head);//giocatore punta alla mappa nella posizione 0
               h=head;
     nodoMappa *tmp=NULL;
            char arrow;
            bool kFine=0;
   		    while(kFine==false){

   				h=head;//ritorna h alla prima cella
   				while(h!=NULL&&kFine==false)
   				{
   					//inserimento posizione del giocatore
                    cout<<"\nE' il turno di "<<h->getNome()<<endl;
   					do{
                    cin>>arrow;
   					if(arrow!='d'&&arrow!='s'&&arrow!='w'&&arrow!='a') //se si inserisce una lettera diversa da "a","s","w","d" c'è errore
   						cout<<"hai sbagliato tasto ritenta";
   					}while(arrow!='d'&&arrow!='s'&&arrow!='w'&&arrow!='a');

   					tmp=line.linea(arrow,h);

                     o=line.getOld();
                     old=o;
                    // line.stampa();

                    printMap.prendiPos(tmp,o);
                   printMap.stampaM(head);
                   kFine=gioca.funzione_random(h);
                   head=gioca.gethead();
                   if(kFine==false)
                   {

                   h=h->NEXT();
   				}

   				}
   		     }
   		 system("pause");
             cout<<"il giocatore vincente e': "; h->stampa();		//stampa vincitore

	return 0;
}
