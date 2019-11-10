#ifndef SEGUIDOR_H_INCLUDED
#define SEGUIDOR_H_INCLUDED

#include "C:\Users\y\Desktop\Seguidor\robot.h"

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
        float velocidade=1;
        bool luminosidade;
        bool curva;
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
        float getvel();
        void setvel(float);
        bool getluminosidade();
        void setluminosidade(bool);
        bool getcurva();
        void setcurva(bool);
};

#endif // SEGUIDOR_H_INCLUDED
