#include "Pista.h"
#include <iostream>

using namespace std;

Pista::Pista()
{
    Marcacao[0]=1;
    Marcacao[1]=0;
    Marcacao[2]=2;
    Marcacao[3]=0;
    Marcacao[4]=1;
    Marcacao[5]=0;
    Marcacao[6]=1;
    Marcacao[7]=0;
    Marcacao[8]=1;
    Marcacao[9]=0;
    cout << endl;
    cout << "Pista construida" << endl;
}

Pista::~Pista()
{
    cout << "Pista concluida" << endl;
}

void Pista::PreencherMarcacao(int Marcas[10])
{
    for (int i=0;i<10;i++)
        Marcas[i]=Marcacao[i];
}
//if curva[i] == 0 -> linha reta
//if curva[i] == 1 -> curva a esquerda
// if curva [i] == 2 -> curva a esquerda

int Pista::setFaixaParada()
{
    FaixaParada++;
}

int Pista::getFaixaParada ()
{
    return FaixaParada;
}
