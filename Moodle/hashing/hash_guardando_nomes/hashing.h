#ifndef HASHING_H
#define HASHING_H

#include <string>
using namespace std;

// Nova struct pedida pelo exercício
struct dado
{
    string info; //informacao (nova)
    int k;       //chave numerica calculada
    int status;  //0: vazio, 1: ocupado, 2: removido
};

//funções de cálculo e hashing duplo
int calcular_k(string info);
int h1(int k, int m);
int h2(int k, int m);
int dhash(int k, int i, int m);

//funções de operação (agora recebendo a string info)
int hash_insert(dado t[], int m, string info);
int hash_search(dado t[], int m, string info);
int hash_remove(dado t[], int m, string info);

#endif
