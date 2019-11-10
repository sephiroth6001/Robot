#include "Seguidor.h"
#include "windows.h"

using namespace std;

seguidor::seguidor()
{
    cout << "VAMO CORRER!!" << endl;
}
seguidor::~seguidor()
{
    cout << "TA PEGANDO FOGO BIXO!!" << endl;
}

PID seguidor::getPID()
{
    return constantes;
}

void seguidor::setPID(PID constantesPID)
{
    constantes = constantesPID;
}

int seguidor::getsensoresfront ()
{
    return sensoresfront;
}

void seguidor::setsensoresfront(int numsensores)
{
    sensoresfront = numsensores;
}

int seguidor::getsensoreslat ()
{
    return sensoreslat;
}

void seguidor::setsensoreslat(int numsensores)
{
    sensoreslat = numsensores;
}

float seguidor::getvel()
{
    return velocidade;
}


bool seguidor::getluminosidade ()
{
    return luminosidade;
}

void seguidor::setluminosidade(bool luz)
{
    luminosidade = luz;
}

bool seguidor::getcurva ()
{
    return curva;
}

void seguidor::setcurva(bool luzlat)
{
    curva = luzlat;
}

void seguidor::setvel(float vel)
{
    velocidade = vel;
}

