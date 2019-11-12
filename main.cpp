#include <iostream>
#include <iomanip>
#include "D:\Users\Ednéa\Desktop\Robot2\Seguidor de Linha\seguidor.h"
#include "D:\Users\Ednéa\Desktop\Robot2\Seguidor de Linha\Pista.h"

using namespace std;

int main()
{
    //Valores inicializados diferentes dos sets, exceto PID e Orientacao que foram atrapalhados
    seguidor follow;
    Pista Circuito;
    int sensores=0,motores=0,sensfront=0,senslat=0,parada=0;
    float bateria=0,parado[2]={0};
    //float velreta[2]={4,4},velcurvaesq[2]={2,3},velcurvadir[2]={3,2};
    //float ajusteesq[2]={3.5,4}, ajustedir[2]={4,3.5};
    int luz[5] = {1,1,1,0,0}; //luz[4] é o sensor mais a direita e luz [0] é o mais a esquerda
    PID valores;
    valores = follow.definirvalores();
    Estado Orientacao;
    Orientacao = follow.Orientar ();
//Métodos robot:
    //sets:
    follow.setNivelBateria(100);
    follow.setNumeroMotores(2);
    follow.setNumeroSensores(7);
    follow.setOrientacao(Orientacao);
    Orientacao = follow.atrapalhaOrientacao(); //Como usei Orientacao como argumento da funcao set, mudo para ter certeza que o get vai pegar o dado da classe e nao da variavel
    cout << "ORIENTACAO ATRAPALHADA: (" << Orientacao.x << ", " << Orientacao.y << ", " << Orientacao.theta << ")" << endl;
    //gets:
    sensores = follow.getNumeroSensores();
    motores = follow.getNumeroMotores();
    bateria = follow.getNivelBateria();
    Orientacao = follow.getOrientacao ();
//Métodos seguidor:
    //sets:
    //follow.setvelocidade(follow.getvelreta());
    follow.setPID(valores);
    valores = follow.AtrapalhaPID(); // Como usei valores como argumento da funcao setPID, atrapalho para ter certeza que o get vai pegar o dado da classe e nao da variavel
    cout << "PID ATRAPALHADO: " << endl;
    follow.ImprimirPID(valores);
    cout << endl;
    follow.setsensoresfront(5);
    follow.setsensoreslat(2);
    //gets:
    valores = follow.getPID();
    sensfront = follow.getsensoresfront();
    senslat = follow.getsensoreslat();
    int Marca[10];
    Circuito.PreencherMarcacao(Marca);
    //follow.setvelocidade();
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
    }
    int FaixaParada[2];
    Circuito.PreencherParada(FaixaParada);

    //Imprimir dados do robot
    cout << endl;
    cout << "Sensores: " << sensores << endl;
    cout << "Motores: " << motores << endl;
    cout << "Bateria: " << bateria << endl;
    cout << "Orientacao:(" << Orientacao.x << ", " << Orientacao.y << ", " << Orientacao.theta << ")" << endl;
    cout << "Constantes PID reais: ";
    cout << endl;
    //Imprimir dados do seguidor
    follow.ImprimirPID(valores);
    cout << "Sensores frontais: " << sensfront << endl;
    cout << "Sensores laterais: " << senslat << endl;
    follow.Imprimirvelocidade();
    follow.setcurva(true);
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
                cout << "Robo alinhado na reta!" << endl;
                follow.Imprimirvelocidade();
                cout << endl << endl;
            }
            else
            {
                cout << "Robo alinhado na curva!" << endl;
                follow.Imprimirvelocidade();
                cout << endl << endl;
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
        for (int i=0;i<2;i++)
    {
        cout << "FAIXA DE PARADA" << endl;
        if (FaixaParada[i]==1)
        {
            follow.setvelocidade(follow.getParar(),follow.getParar());
            cout << "PAROU" << endl;
        }
    }
        return 0;
}
