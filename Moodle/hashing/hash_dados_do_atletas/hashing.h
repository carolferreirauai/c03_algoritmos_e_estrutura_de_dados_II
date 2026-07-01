#ifndef HASHING_H
#define HASHING_H

#include <string>
using namespace std;

//struct com os dados completos do atleta
struct info
{
    string nome;
    int idade;
    float peso;
    float altura; 
};

//struct que representa uma gaveta da tabela hash
struct dado
{
    info atleta; //nome, idade, peso e altura de cada atleta
    int k;       //chave
    int status;  //0:vazio, 1:ocupado, 2:removido
};

//funções de cálculo e double hashing
int calcular_k(string nome);
int h1(int k, int m);
int h2(int k, int m);
int dhash(int k, int i, int m);

//funções de operação
int hash_insert(dado t[], int m, info atleta);
int hash_search(dado t[], int m, string nome);
int hash_remove(dado t[], int m, string nome);

#endif