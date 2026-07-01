#ifndef HASHING_H
#define HASHING_H
struct dado
{
    int k;
    int status; // 0: vazio, 1: ocupado, 2: removido
};

int hash_aux(int k, int m);
int hash1(int k, int i, int m);
int hash_insert(dado t[], int m, int k);
int hash_search(dado t[], int m, int k);
int hash_remove(dado t[], int m, int k);

#endif