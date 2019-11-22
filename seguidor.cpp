#include "Seguidor.h"
#include "windows.h"

using namespace std;

seguidor::seguidor()
{
    setsensoresfront(5);
    setsensoreslat(2);
    getSensoresfront();
    getSensoreslat();
    constantes.Kp = 5;
    constantes.Ki = 0.12;
    constantes.Kd = 4;
    getPID();
    Estado Orientacao;
    Orientacao = Orientar ();
    setOrientacao(Orientacao);
    getOrientacao();
}
seguidor::~seguidor()
{
    cout << "ROBO DESTRUIDO!!" << endl;
}
void seguidor::getPID()
{
    cout << "Kp = " << constantes.Kp << endl;
    cout << "Ki = " << constantes.Ki << endl;
    cout << "Kd = " << constantes.Kd << endl;
}

void seguidor::setPID(PID valores)
{
    constantes.Kp = valores.Kp;
    constantes.Ki = valores.Ki;
    constantes.Kd = valores.Kd;
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

float* seguidor::getvelocidade()
{
    return velocidade;
}


bool seguidor::getluminosidade0 ()
{
    return leiturasens[0];
}

void seguidor::setluminosidade0(bool luz[5])
{
    leiturasens[0] = luz[0];
}

void seguidor::setluminosidade1(bool luz[5])
{
    leiturasens[1] = luz[1];
}

void seguidor::setluminosidade2(bool luz[5])
{
    leiturasens[2] = luz[2];
}

void seguidor::setluminosidade3(bool luz[5])
{
    leiturasens[3] = luz[3];
}

void seguidor::setluminosidade4(bool luz[5])
{
    leiturasens[4] = luz[4];
}

bool seguidor::getluminosidade1 ()
{
    return leiturasens[1];
}

bool seguidor::getluminosidade2 ()
{
    return leiturasens[2];
}

bool seguidor::getluminosidade3 ()
{
    return leiturasens[3];
}

bool seguidor::getluminosidade4 ()
{
    return leiturasens[4];
}

void seguidor::setvelocidade(float esq,float dir)
{
    velocidade[0] = esq;
    velocidade[1] = dir;
}


PID seguidor::AtrapalhaPID()
{
    PID atrapalhado;
    atrapalhado.Kp = 500;
    atrapalhado.Ki = 400;
    atrapalhado.Kd = 300;
    return atrapalhado;
}

Estado seguidor::Orientar ()
{
    Estado Orientacao;
    Orientacao.x = 5.0;
    Orientacao.y = 4.0;
    Orientacao.theta = 60;
    return Orientacao;
}


Estado seguidor::atrapalhaOrientacao()
{
    Estado Orientacao;
    Orientacao.x = 200;
    Orientacao.y = 245;
    Orientacao.theta = 654;
    return Orientacao;
}

float seguidor::getvelesqreta()
{
    return velreta[0];
}

float seguidor::getveldirreta()
{
    return velreta[1];
}

float seguidor::getvelEsqcurvaEsq()
{
    return velcurvaesq[0];
}

float seguidor::getvelDircurvaEsq()
{
    return velcurvaesq[1];
}

float seguidor::getvelEsqcurvaDir()
{
    return velcurvadir[0];
}

float seguidor::getvelDircurvaDir()
{
    return velcurvadir[1];
}

float seguidor::getParar()
{
    return Parar;
}



/*
bool* seguidor::getleiturasenslat()
{
    return leiturasenslat;
}
*/
float seguidor::getvelEsqAjusteEsq()
{
    return velAjusteEsq[0];
}

float seguidor::getvelEsqAjusteDir()
{
    return velAjusteEsq[1];
}

float seguidor::getvelDirAjusteEsq()
{
    return velAjusteDir[0];
}

float seguidor::getvelDirAjusteDir()
{
    return velAjusteDir[1];
}


void seguidor::Imprimirvelocidade()
{
    cout << "Velocidade esquerda: " << velocidade[0] << endl;
    cout << "Velocidade direita: " << velocidade[1] << endl;

}

bool seguidor::getcurva()
{
    return curva;
}

void seguidor::setcurva(bool lat)
{
    curva = lat;
}

void seguidor::getSensoresfront()
{
    cout << "sensores frontais = " << sensoresfront << endl;
}

void seguidor::getSensoreslat()
{
    cout << "sensores laterais = " << sensoreslat << endl;
}
