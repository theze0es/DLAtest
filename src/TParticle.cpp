#include "TParticle.h"

TParticle::TParticle()
{
RandomizePosition();
mob=true;
}

TParticle::~TParticle()  //è il distruttore!!
{
    //dtor
}

void TParticle::Move()
{

int dx[6], dy[6], R[2];

dx[0]=-2; dx[1]=2; dx[2]=1; dx[3]=-1; dx[4]=1; dx[5]=-1;
dy[0]=0; dy[1]=0; dy[2]=1; dy[3]=1; dy[4]=-1; dy[5]=-1;
R[0]=-1; R[1]=1;  //possibilità di rotazione

int tr=randM(6);                 //sposto il CdM
xc=(xc+dx[tr]+L)%L;
yc=(yc+dy[tr]+L)%L;
xs=(xs+dx[tr]+L)%L;    //e di conseguenza i siti d e s
ys=(ys+dy[tr]+L)%L;
xd=(xd+dx[tr]+L)%L;     //INSERIRE UNA FUNZIONE (O CLASSE?) PER LE PBC??
yd=(yd+dy[tr]+L)%L;

//rotazione: senso orario o antiorario, stocastico
int r=randM(2);
int rot=R[r];
int sx, sy; //valori utili per effettuare la rotazione

//definisco l'orientazione in x

        if (((xs-xd)==2)||((xs-xd)==4)||((xs-xd)==-2)||((xs-xd)==-4)){   //lontano dal bordo
            sx=(xs-xd)/abs(xs-xd);
            }
            else{
            sx=-(xs-xd)/abs(xs-xd);         //sul bordo il valore di sx va invertito
            }

        if (ys==yd){        //monomero in orizzontale: gira a seconda di rot che è stocastico
        xs=(xs-sx+L)%L;
        ys=(ys+rot+L)%L;
        xd=(xd+sx+L)%L;
        yd=(yd-rot+L)%L;
        }
        else{               //monomero in diagonale:

        //definisco orientazione in y

                if (((ys-yd)==2)||((ys-yd)==-2)){ //lontano dai bordi, caso ys-yd==0 già trattato sopra
                sy=(ys-yd)/abs(ys-yd);
                }
                else{
                sy=-(ys-yd)/abs(ys-yd);         //vicino ai bordi
                }

        // ora i due possibili movimenti non sono simmetrici, discrimino in base a rot che è stocastico

            if (rot==-1){  //si mette in orizzontale
            xs=(xs-2*sx+L)%L;
            xd=(xd+2*sx+L)%L;
            }
            else{           //ruota nell'altra posizione diagonale disponibile
            xs=(xs+sx+L)%L;
            ys=(ys-sy+L)%L;
            xd=(xd-sx+L)%L;
            yd=(yd+sy+L)%L;
            }
        }

}

void TParticle::RandomizePosition()
{
xc=randM(L);                 //posiziono il centro random
if (xc%2==0){                //ma sulla griglia triangolare: la somma degli indici deve essere pari
        yc=(randM(L)*2)%L;  //se x pari, y pari
    }
    else{
        yc=(randM(L)*2+1)%L; //se x dispari, y dispari
    }

//creo i siti d e s con un movimento fittizio attorno a xc, yc

int tr=randM(6);

xs=(xc+dx[tr]+L)%L; //il sito d lo metto in direzione dello spostamento fittizio
ys=(yc+dy[tr]+L)%L;

xd=(xc-dx[tr]+L)%L; //il sito s nella direzione opposta
yd=(yc-dy[tr]+L)%L;
}


