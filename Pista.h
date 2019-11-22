#ifndef PISTA_H_INCLUDED
#define PISTA_H_INCLUDED

class Pista
{
    private:
        int Marcacao[10];
        int FaixaParada = 0; //A primeira vez q o leitor direito lê é largada
    public:
        Pista();
        ~Pista();
        void PreencherMarcacao(int*);
        int setFaixaParada();
        int getFaixaParada();
};

#endif // PISTA_H_INCLUDED
