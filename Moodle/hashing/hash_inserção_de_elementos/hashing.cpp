/*
HASH - INSERÇÃO DE ELEMENTOS

O ALGORITMO DE INSERÇÃO DE CHAVES É MOSTRADO ABAIXO:
HASH-INSERT(T, M, K)
    I <- 0
    DO
        J <- HASH1(K, I, M)
        IF T[J].STATUS != 1
            T[J].K <- K
            T[J].STATUS = 1
            RETURN J
        ELSE
            I <- I + 1
    WHILE I != M
    RETURN -1

FAÇA UMA FUNÇÃO QUE IMPLEMENTE ESTE ALGORITMO. ESTA FUNÇÃO DEVE RETORNAR A POSIÇÃO ONDE A CHAVE FOI
INSERIDA NA TABELA HASH, OU -1 SE NÃO FOR POSSÍVEL INSERI-LA (TABELA CHEIA). USE A SONDAGEM LINEAR PARA 
ESCOLHER A POSIÇÃO DE INSERÇÃO DA CHAVE. SUA FNÇÃODEVE TER O SEGUINTE CABEÇALHO:

INT HASH_INSERT(DADO T[], INT M, INT K)

ONDE A STRUCT DADO É:

STRUCT DADO
{
    INT K; //CHAVE A SER INSERIDA
    INT STATUS; //0: VAZIO 1: OCUPADO
}
E DEVE SER DEFINIDA EM HASHING.H

FAÇA ENTÃO UM PROGRAMA QUE LEIA O TAMANHO DESEJADO M PARA A TABELA HASH E AS CHAVES A SEREM
INSERIDAS.

DEPOIS, O PROGRAMA DEVE CRIAR UMA TABELA DE TAMANHO M INICIALMENTE VAZIA (TODAS AS POSIÇÕES 
PREENCHIDAS COM -1), E IR INSERINDO AS CHAVES DIGITADAS.

AO FINAL, SEU PROGRAMA DEVE MOSTRAR A TABELA DEPOIS DAS INSERÇÕES.

ENTRADA: A ENTRADA CONSISTE DE DUAS LINHAS:
- A PRIMEIRA LINHA IRÁ CONTER O TAMANHO M DA TABELA (UM NÚMERO INTEIRO)
- A SEGUNDA LINHA CONSISTE DE VÁRIOS INTEIROS POSITIVOS, CORREPONDENTES AOS VALORES DAS CHAVES A SEREM 
INSERIDAS. ESTA LINHA TERMINA COM O NÚMERO 0, QUE NÃO DEVE SER INSERIDO NA TABELA.

SAÍDA: NA SAÍDA, O PROGRAMA DEVE MOSTRAR A TABELA PREENCHIDA, COMO NO EXEMPLO ABAIXO.
*/

//biblioteca
#include <iostream>
#include "hashing.h"

using namespace std;

//função insert
int hash_insert(dado t[], int m, int k)
{
    int i = 0; //i <- 0
    do //do
    {
        //j <- hash1(k, i, m)
        int j = hash1(k, i, m);

        //if t[j].status != 1
        if (t[j].status != 1)
        {
            t[j].k = k; //t[j].k <- k
            t[j].status = 1; //t[j].status = 1
            return j; 
        }
        else
        {
            i = i + 1; //i <- i + 1
        }
    }while (i != m); //while i != m
    
    return -1; //return -1, se não for possível a tabela cheia
}

//sondagem linear
//hash auxiliar
int hash_aux(int k, int m)
{
    //metodo de divisão
    int h = k % m;

    //número negativo
    if(h < 0)
    {
        return h += m;
    }
    return h;
}
//sondagem linear
int hash1(int k, int i, int m)
{
    //(h'(k, m) + i) mod m
    return (hash_aux(k, m) + i) % m;
}

//função principal
int main()
{
    //declaração de váriaveis
    int m;
    int chaves;
    dado tabela[100];

    //entrada de dados
    //ler m
    cin >> m;

    //criar a tabela e inicializando a tabaela
    for(int i = 0; i < m; i++)
    {
        tabela[i].k = -1; //preenciada com -1
        tabela[i].status = 0; //vazia
    }

    //ler as chaves
    while(cin >> chaves && chaves != 0)
    {
        //desenvolvimento
        //chamar a função, inserindo na tabelas
        hash_insert(tabela, m, chaves);
    }

    //saida de dados
    for(int i = 0; i < m; i++)
    {
        cout << tabela[i].k << " ";
    }
    cout << endl;
    return 0;
}