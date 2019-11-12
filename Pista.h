#ifndef PISTA_H_INCLUDED
#define PISTA_H_INCLUDED

class Pista
{
    private:
        int Marcacao[10];
        int FaixaParada[2]={0,1}; //A primeira vez q o leitor direito lê é largada
    public:
        Pista();
        ~Pista();
        void PreencherMarcacao(int*);
        void PreencherParada(int*);
};

#endif // PISTA_H_INCLUDED
