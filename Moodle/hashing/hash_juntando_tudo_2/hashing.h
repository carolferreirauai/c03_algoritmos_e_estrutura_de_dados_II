#ifndef HASHING_H
#define HASHING_H

struct dado
{
    int k;      // chave a ser inserida
    int status; // 0: vazio, 1: ocupado, 2: removido
};

int hash_aux(int k, int m);
int hash2(int k, int i, int m, int c1, int c2);
int hash_insert(dado t[], int m, int k, int c1, int c2);
int hash_search(dado t[], int m, int k, int c1, int c2);
int hash_remove(dado t[], int m, int k, int c1, int c2);

#endif