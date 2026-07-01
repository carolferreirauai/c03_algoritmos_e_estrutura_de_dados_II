/*
HASH - DOUBLE HASHING

FAÇA UMA FUNÇÃO QUE IMPLEMENTE O DOUBLE HASHING, DADO POR:
H(K, I, M) = (H1(K,M) + IH2(K, M)) MOD M

ONDE 

H1(K, M) = K MOD M
H2(K, M) = 1 + (K MOD (M -1))

SÃO FUNÇÕES AUXILIARES.
AS FUNÇÕES DEVEM TER OS SEGUINTES CABEÇALHOS:
INT H1(INT K, INT M)
INT H2(INT K, INT M)
INT DHASH (INT K, INT I, INT M)

ONDE K É A CHAVE A SER INSERIDA, M É O TAMANHO DA TABELA HASH, E O I É NÚMERO DA TENTATICA.

DEPOIS FAÇA UM PROGRAMA QUE LEIA OS VALOR DE K E M E FAÇA USO DESTA FUNÇÃO PARA RETORNAR AS 
POSIÇÕES DE SONDAGEM PARA DOUBLE HASHING.

ENTRADA: A ENTRADA CONSISTE UMA ÚNICA LINHA COM 2 INTEIROS, CORRESPONDENTES AOS VALORES DE K E M,
RESPECTIVAMENTE.

SAÍDA: NA SAÍDA, O PROGRAMA DEVE MOSTRAR TODAS AS POSIÇÕES DA SONDAGEM DOUBLE HASHING PARA AS ENTRADAS
DADAS.
*/

//biblioteca
#include <iostream>
#include "hashing.h"

using namespace std;

//função hash auxiliar h1
int h1(int k, int m)
{
    //h1(k, m) = k mod m
    //metodo de divisão
    int h1_aux = k % m;
    
    return h1_aux;
}

//função hash auxiliar h2
int h2 (int k, int m)
{
    //h2(k, m) = 1 + (k mod (m -1))
    int h2_aux = 1 + k % (m - 1);

    return h2_aux;
}

//função double hashing
int dhash (int k, int i, int m)
{
    //h(k, i, m) = (h1(k, m) + i * h2(k, m)) mod m
    int double_hash = (h1(k, m) + i * h2(k, m)) % m;

    return double_hash;
}

//função principal
int main()
{
    //declaração de váriioaveis
    int k, m;

    //entrada de dados
    //ler os 2 valores inteiros
    while (cin >> k >> m)
    {
        //números negativos, antes de chamar a váriaveis
        if (k < 0)
        {
            k = (k % m) + m;
        }
        //desenvolvimento
        for(int i = 0; i < m; i++)
        {
            //chamar a função
            int resultado = dhash(k, i, m);

            //saida de dados
            cout << resultado << " ";
        } 
        cout << endl;
    }
    return 0;
}