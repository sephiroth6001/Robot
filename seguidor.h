#ifndef SEGUIDOR_H_INCLUDED
#define SEGUIDOR_H_INCLUDED

#include "D:\Users\Ednéa\Desktop\Robot\Robot.h"

#include <iostream>

    struct PID
    {
        float Kp,Ki,Kd;
    };

class seguidor : public Robot
{
    private:

        int sensoresfront;
        int sensoreslat;
        float velocidade[2]; // velocidade [0] : roda esquerda, velocidade [1] : roda direita
        bool leiturasens[5]={1,1,1,0,0};//leiturasens[4] é o sensor mais a direita e leiturasens[0] é o mais a esquerda
        bool leiturasenslat[2]; // leiturasenslat[0] : esquerdo , leiturasenslat[1] : direito
        float angulo;
        bool curva=false;
        float Parar=0;
        float velreta[2]={4,4};
        float velcurvaesq[2]={2,3};
        float velcurvadir[2]={3,2};
        float velAjusteEsq[2]={3.5,4};
        float velAjusteDir[2]={4,3.5};
        PID constantes;

    public:
        seguidor();
        ~seguidor();
        PID getPID();
        void setPID(PID);
        int getsensoresfront();
        void setsensoresfront(int);
        int getsensoreslat();
        void setsensoreslat(int);
        float* getvelocidade();
        void setvelocidade(float,float);
        bool getluminosidade0();
        bool getluminosidade1();
        bool getluminosidade2();
        bool getluminosidade3();
        bool getluminosidade4();
        void setluminosidade0(bool*);
        void setluminosidade1(bool*);
        void setluminosidade2(bool*);
        void setluminosidade3(bool*);
        void setluminosidade4(bool*);
        PID definirvalores ();
        Estado atrapalhaOrientacao();
        Estado Orientar ();
        PID AtrapalhaPID();
        bool* getleiturasenslat();
        void ImprimirPID (PID constantes);
        float getvelesqreta();
        float getveldirreta();
        float getvelEsqcurvaEsq();//Roda esquerda da curva para a esquerda
        float getvelDircurvaEsq();//Roda direita da curva para a esquerda
        float getvelEsqcurvaDir();//Roda esquerda da curva para a direita
        float getvelDircurvaDir();//Roda direita da curva para a direita
        float getvelEsqAjusteEsq();
        float getvelDirAjusteEsq();
        float getvelEsqAjusteDir();
        float getvelDirAjusteDir();
        float getParar();
        void Imprimirvelocidade();
        bool getcurva();
        void setcurva(bool);
};

#endif // SEGUIDOR_H_INCLUDED
