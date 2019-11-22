#include <iostream>
#include <iomanip>
#include "C:\Backup Real\Renan\Rino\Robot2\Seguidor de Linha\seguidor.h"
#include "C:\Backup Real\Renan\Rino\Robot2\Seguidor de Linha\Pista.h"

using namespace std;

int main()
{
    //Valores inicializados diferentes dos sets, exceto PID e Orientacao que foram atrapalhados
    seguidor follow;
    //float velreta[2]={4,4},velcurvaesq[2]={2,3},velcurvadir[2]={3,2};
    //float ajusteesq[2]={3.5,4}, ajustedir[2]={4,3.5};
    /*Orientacao = follow.atrapalhaOrientacao(); //Como usei Orientacao como argumento da funcao set, mudo para ter certeza que o get vai pegar o dado da classe e nao da variavel
    cout << "ORIENTACAO ATRAPALHADA: (" << Orientacao.x << ", " << Orientacao.y << ", " << Orientacao.theta << ")" << endl;*/
    //Orientacao = follow.getOrientacao ();
    //follow.setvelocidade(follow.getvelreta());
    //valores = follow.AtrapalhaPID(); // Como usei valores como argumento da funcao setPID, atrapalho para ter certeza que o get vai pegar o dado da classe e nao da variavel
    /*cout << "PID ATRAPALHADO: " << endl;
    follow.getPID(valores);
    cout << endl;*/
    Pista Circuito;
    int Marca[10];
    Circuito.PreencherMarcacao(Marca);
    //follow.setvelocidade();
    cout << endl << endl;
    while (Circuito.getFaixaParada()!=1)
    {
        if (Circuito.getFaixaParada() ==0)
            cout << "LARGADA" << endl << endl;
        else
            cout << "VOLTA" << endl << endl;
        Circuito.setFaixaParada();
        for (int i=0;i<10;i++)
       {
            if (Marca[i]==0)
            {
                follow.setvelocidade(follow.getvelesqreta(),follow.getveldirreta());
                cout << "RETA" << endl;
                follow.setcurva(false);
                follow.Imprimirvelocidade();
                cout << endl;
            }
            if (Marca[i]==1)
            {
                follow.setvelocidade(follow.getvelEsqcurvaEsq(),follow.getvelDircurvaEsq());
                cout << "ESQUERDA" << endl;
                follow.setcurva(true);
                follow.Imprimirvelocidade();
                cout << endl;
            }

            if (Marca[i]==2)//A primeira vez que o robo enxerga a faixa de parada é a largada
            {
                follow.setvelocidade(follow.getvelEsqcurvaDir(),follow.getvelDircurvaDir());
                cout << "DIREITA" << endl;
                follow.setcurva(true);
                follow.Imprimirvelocidade();
                cout << endl;
            }
            //Ajustes:
            if (follow.getluminosidade4()==1 || follow.getluminosidade3()==1)
            {
                if (follow.getcurva()== false)
                {
                    follow.setvelocidade(follow.getvelEsqAjusteDir(),follow.getvelDirAjusteDir());
                    cout << "Ajustando para a direita na reta" << endl;
                    follow.Imprimirvelocidade();
                    cout << endl << endl;
                }
                else
                {
                    follow.setvelocidade(follow.getvelEsqcurvaDir(),follow.getvelDircurvaDir()-0.5);
                    cout << "Ajustando para a direita na curva" << endl;
                    follow.Imprimirvelocidade();
                    cout << endl << endl;
                }
            }
            else if (follow.getluminosidade2()==1)
            {
                if (follow.getcurva()==false)
                {
                    //cout << "Robo alinhado na reta!" << endl;
                    //follow.Imprimirvelocidade();
                    //cout << endl << endl;
                }
            }
            else if (follow.getluminosidade1()==1 || follow.getluminosidade0()==1)
            {
                if (follow.getcurva()==false)
                {
                    follow.setvelocidade(follow.getvelEsqAjusteEsq(),follow.getvelDirAjusteEsq());
                    cout << "Ajustando para a esquerda na reta" << endl;
                    follow.Imprimirvelocidade();
                    cout << endl << endl;
                }
                else
                {
                    follow.setvelocidade(follow.getvelEsqcurvaEsq()-0.5,follow.getvelEsqcurvaDir());
                    cout << "Ajustando para a esquerda na curva" << endl;
                    follow.Imprimirvelocidade();
                    cout << endl << endl;
                }
            }
        }

        //Imprimir dados do robot

        follow.setcurva(true);

        }
        follow.setvelocidade(follow.getParar(),follow.getParar());
        follow.getvelocidade();
        cout << "FAIXA DE PARADA" << endl;
        cout << "PAROU" << endl;
        return 0;
}
