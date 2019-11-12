#include "robot.h"
#include <windows.h>

using namespace std;

Robot::Robot(){}

void Robot::Locomocao()
{
    Sleep(5000);
}

int Robot::getNumeroMotores()
{
    return numeroMotores;
}

int Robot::getNumeroSensores()
{
    return numeroSensores;
}

float Robot::getNivelBateria()
{
    return bateria;
}

Estado Robot::getOrientacao()
{
    return orientacao;
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
