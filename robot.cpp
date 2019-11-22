#include "robot.h"
#include <windows.h>

using namespace std;

Robot::Robot(){
    cout << "ROBO CONSTRUIDO" << endl;
    setNivelBateria(100);
    setNumeroMotores(2);
    setNumeroSensores(7);
    cout << "Motores: ";
    getMotores();
    cout << "Bateria: " ;
    getBateria();
    cout << "Sensores: ";
    getSensores();
    }

void Robot::Locomocao()
{
    Sleep(5000);
}

void Robot::getOrientacao()
{
    cout << "Orientacao : (" << orientacao.x << "," <<  orientacao.y << "," << orientacao.theta << ")" << endl;
}

void Robot::setOrientacao(Estado state)
{
    orientacao = state;
}

void Robot::setNivelBateria(float nivelBateria)
{
    bateria = nivelBateria;
}

void Robot::setNumeroMotores(int numMotores)
{
    numeroMotores = numMotores;
}

void Robot:: setNumeroSensores(int numsensores)
{
    numeroSensores = numsensores;
}

void Robot:: getSensores ()
{
    cout << numeroSensores << endl;
}

void Robot:: getBateria()
{
    cout << bateria << endl;
}

void Robot:: getMotores()
{
    cout << numeroMotores << endl;
}
