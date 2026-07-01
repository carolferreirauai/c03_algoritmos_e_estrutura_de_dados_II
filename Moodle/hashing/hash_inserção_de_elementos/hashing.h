#ifndef HASHING_H
#define HASHING_H

//função de dados
struct dado
{
    int k;
    int status;
};

int hash_insert(dado t[], int m, int k);
int hash_aux(int k, int m);
int hash1(int k, int i, int m);

#endif