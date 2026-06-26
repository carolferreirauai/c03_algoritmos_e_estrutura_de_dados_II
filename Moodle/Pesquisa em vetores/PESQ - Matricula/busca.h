#ifndef SEQUENCIAL_H
#define SEQUENCIAL_H

#include <string>

using namespace std;

//irá guarda os registros
struct dados
{
    string nome; //nome do aluno
    string curso; //curso
    int matricula; //matricula
};

int sequencial(dados vetor[], int tamanho, string x);

#endif