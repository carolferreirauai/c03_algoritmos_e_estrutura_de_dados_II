/*
HASH - SONDAGEM LINEAR

USANDO A FUNÇÃO HASH_AUX(), FAÇA UMA FUNÇÃO QUE IMPLEMENTE A SONDAGEM LINEAR, DADA POR:
H(K, I, M) = (H'(K,M) + I) MOD M

ESTA FUNÇÃO DEVE TER O SEGUINTE CABEÇALHO:
INT HASH1(INT K, INT I, INT M)

ONDE K É A CHAVE A SER INSERIDA, M É O TAMANHO DA TABELA HASH E I É O NÚMERO DA TENTATIVA.

DEPOIS FAÇA UM PROGRAMA QUE LEIA OS VALORES DE K E M E FAÇA USO DESTA FUNÇÃO PARA RETORNAR AS 
POSIÇÕES DA SONDAGEM LINEAR.

ENTRADA: A ENTRADA CONSISTE UMA ÚNICA LINHA COM 2 INTEIROS, CORRESPONDENTES AOS VALORES DE K E M,
RESPECTIVAMENTE.

SAÍDA: NA SAÍDA, O PROGRAMA DEVE MOSTRAR TODAS AS POSIÇÕES DA SONDAGEM LINEAR PARA AS ENTRADAS DADAS.
*/

//biblioteca
#include <iostream>
#include <cmath>
#include "hashing.h"

using namespace std;

//função hash_aux
int hash_aux(int k, int m)
{
    //metodo da divisão
    int h = k % m;

    //números negativo
    if (k < 0)
    {
        //aplicar a regra
        return h += m;
    }
    else
    {
        return h;
    }
}

//função hash sondagem linear
int hash1(int k, int i, int m)
{
    //(h'(k, m) + i) mod m
    return (hash_aux(k, m) + i) % m;
}

//função principal
int main()
{
    //declaração de váriaveis
    int k; //chave
    int m; //tamanho da tabela

    //entrada de dados
    //ler os valores
    while(cin >> k >> m)
    {
        //desenvolvimento
        //a sondagem linear testa todas as casas i = 0 até i = m - 1
        for(int i = 0; i < m; i++)
        {
            int resultado = hash1(k, i, m);

            //saida de dados
            cout << resultado << " ";
        }

        //pular uma linha para o próximo caso de teste
        cout << endl;
    }

    return 0;
}