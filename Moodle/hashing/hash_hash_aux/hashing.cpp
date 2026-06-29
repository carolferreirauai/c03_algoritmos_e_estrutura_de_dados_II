/*
HASH - HASH_AUX

FAÇA UMA FUNÇÃO QUE IMPLEMENTE O MÉTODO DA DIVISÃO, DADO POR:
H(K, M) = K MOD M

SE O VALOR RESULTANTE FOR NEGATIVO, VOCÊ DEVE SOMAR M A ELE.

A SUA FUNÇÃO DEVE TER O SEGUINTE CABEÇALHO:
INT HASH_AUX(INT K, INT M)

ONDE K É A CHAVE A SER INSERIDA, E M É O TAMANHO DA TAVBELA HASH.

DEPOIS FAÇA UM PROGRAMA QUE LEIA VÁRIOS VALORES DE K E M E FAÇA USO DESTA FUNÇÃO RETORNAR O VALOR
DELA

ENTRADA: A ENTRADA CONSISTE DE VÁRIAS LINHAS. CADA LINHA TERÁ 2 INTEIROS, CORREPONDENTES AOS VALORES DE K E M,
RESPECTIVAMENTE. O FINAL DA ENTRADA OCORRE QUANDO FOREM DIGITADOS VALORES NULOS PARA K E M.

SAÍDA: PARA CADA PAR DE VALORES K E M, O PROGRAMA DEVE MOSTRAR O VALOR DA FUNÇÃO HASH.
*/

//bibliotecas
#include <iostream>
#include <cmath>
#include "hashing.h"

using namespace std;

int hash_aux(int k, int m)
{
    int h = k % m; //método divisão

    if (k < 0)
    {
        //se o número for negativo, tem que aplicar a regra + m
        return h += m;
    }
    else
    {
        return h;
    }
}

//função principal
int main()
{
    //declaração de variaveis
    int k; //chaves
    int m; //mod

    //entrada de dados
    //ler os valores k e m
    while (cin >> k >> m && k != 0 && m != 0)
    {
        //desenvolvimento
        //chamar a função
        int resultado = hash_aux(k, m);

        //saída de dados
        cout << resultado << endl;
    }

    return 0;
}