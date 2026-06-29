#ifndef ORDENACAO_H
#define ORDENACAO_H

#include <string>
using namespace std;

//função de struct para armazenar os dados de cada alunos
struct dados
{
    string nome;
    string curso;
    int matricula;
};

//declaração de função ordenada - insertion sort
void insercaodireta(dados vetor[], int tamanho); //muda o int do vetor para o nome da struct
#endif