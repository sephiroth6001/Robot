#include <iostream>
#include <iomanip>
#include "C:\Users\y\Desktop\Seguidor\seguidor.h"

using namespace std;

void ImprimirPID (PID constantes)
{
    cout << "Kp = " << constantes.Kp << endl;
    cout << "Ki = " << constantes.Ki << endl;
    cout << "Kd = " << constantes.Kd << endl;
}

PID AtrapalhaPID()
{
    PID atrapalhado;
    atrapalhado.Kp = 222;
    atrapalhado.Ki = 111;
    atrapalhado.Kd = 888;
    return atrapalhado;
}

Estado Orientar ()
{
    Estado Orientacao;
    Orientacao.x = 1.0;
    Orientacao.y = 2.0;
    Orientacao.theta = 22.5;
    return Orientacao;
}

Estado NovaOrient ()
{
    Estado Nova;
    Nova.x = 2.0;
    Nova.y = 5.0;
    Nova.theta = 45;
    return Nova;
}

Estado atrapalhaOrientacao()
{
    Estado Orientacao;
    Orientacao.x = 200;
    Orientacao.y = 245;
    Orientacao.theta = 654;
    return Orientacao;
}

PID definirvalores ()
{
    PID valores;
    valores.Kp = 5;
    valores.Ki = 0.12;
    valores.Kd = 5;
    return valores;
}


int main()
{
    //Valores inicializados diferentes dos sets, exceto PID e Orientacao que foram atrapalhados
    seguidor follow;
    int sensores=0,motores=0,sensfront=0,senslat=0;
    float bateria=0,vel=0;
    bool luz = false,curva = true;
    PID valores;
    valores = definirvalores();
    Estado Orientacao,Nova;
    Orientacao = Orientar ();
//Métodos robot:
    //sets:
    follow.setNivelBateria(100);
    follow.setNumeroMotores(2);
    follow.setNumeroSensores(7);
    follow.setOrientacao(Orientacao);
    Orientacao = atrapalhaOrientacao(); //Como usei Orientacao como argumento da funcao set, mudo para ter certeza que o get vai pegar o dado da classe e nao da variavel
    cout << "ORIENTACAO ATRAPALHADA: (" << Orientacao.x << ", " << Orientacao.y << ", " << Orientacao.theta << ")" << endl;
    //gets:
    sensores = follow.getNumeroSensores();
    motores = follow.getNumeroMotores();
    bateria = follow.getNivelBateria();
    Orientacao = follow.getOrientacao ();

//Métodos seguidor:
    //sets:
    follow.setvel(3);
    follow.setPID(valores);
    valores = AtrapalhaPID(); // Como usei valores como argumento da funcao setPID, atrapalho para ter certeza que o get vai pegar o dado da classe e nao da variavel
    cout << "PID ATRAPALHADO: " << endl;
    ImprimirPID(valores);
    cout << endl;
    follow.setsensoresfront(5);
    follow.setsensoreslat(2);
    follow.setluminosidade(true);
    follow.setcurva(false);
    //gets:
    valores = follow.getPID();
    sensfront = follow.getsensoresfront();
    senslat = follow.getsensoreslat();
    vel = follow.getvel();
    luz = follow.getluminosidade ();
    curva = follow.getcurva();
    //Imprimir dados do robot
    cout << endl;
    cout << "Sensores: " << sensores << endl;
    cout << "Motores: " << motores << endl;
    cout << "Bateria: " << bateria << endl;
    cout << "Orientacao:(" << Orientacao.x << ", " << Orientacao.y << ", " << Orientacao.theta << ")" << endl;
    cout << "Constantes PID reais: ";
    cout << endl;
    //Imprimir dados do seguidor
    ImprimirPID(valores);
    cout << "Sensores frontais: " << sensfront << endl;
    cout << "Sensores laterais: " << senslat << endl;
    cout << "Velocidade: " << vel << endl;
    cout << "Luminosidade: " << luz << endl;
    cout << "Curva: " << curva << endl;
    return 0;
}
