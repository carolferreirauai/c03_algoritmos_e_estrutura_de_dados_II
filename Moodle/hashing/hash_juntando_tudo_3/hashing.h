#ifndef HASHING_H
#define HASHING_H

struct dado
{
    int k;      // chave a ser inserida
    int status; // 0: vazio, 1: ocupado, 2: removido
};

//Funções auxiliares do Double Hashing
int h1(int k, int m);
int h2(int k, int m);
int dhash(int k, int i, int m);

//Funções principais
int hash_insert(dado t[], int m, int k);
int hash_search(dado t[], int m, int k);
int hash_remove(dado t[], int m, int k);

#endif