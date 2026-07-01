/*
HASH - REMOÇÃO

A REMOÇÃO DE ELEMENTOS DE UMA TABELA HASH CRIA PROBLEMAS NA BUSCA, POIS POSIÇÕES QUE FORAM REMOVIDAS INTERROMPEM A SEQUÊNCIA DE SONDAGEM.

UMA FORMA DE EVITAR ESTE PROBLEMA É CRIAR UM SINALIZADOR DE STATUS DE CADA POSIÇÃO. ASSIM, A TABELA HASH IRÁ ARMAZENAR EM CADA POSIÇÃO, NÃO SÓ A CHAVE, MAS TAMBÉM O SEU STATUS. PARA IMPLEMENTAR ESTA IDEIA, PODEMOS USAR A STRUCT ABAIXO:

STRUCT DADO
{
    INT K;
    INT STATUS; // 0-VAZIO, 1-OCUPADO, 2-REMOVIDO
};

PARA REMOVER UM ELEMENTO DA TABELA, BASTA FAZER A BUSCA E, SE ESTE FOR ENCONTRADO, BASTA ALTERAR O STATUS DELE PARA 2, COMO MOSTRADO NO PSEUDOCÓDIGO ABAIXO:

HASH_REMOVE(T, M, K)
    J = HASH_SEARCH(T, M, K)
    IF(J != -1)
        T[J].STATUS = 2
        T[J].K = -1
        RETURN 0 // CONSEGUI REMOVER
    ELSE
        RETURN -1 // K NAO ESTA NA TABELA

A FUNÇÃO DE REMOÇÃO DEVE TER O SEGUINTE CABEÇALHO:

INT HASH_REMOVE(DADO T[], INT M, INT K)

SUA TAREFA É ENTÃO IMPLEMENTAR A FUNÇÃO HASH_REMOVE().

FAÇA ENTÃO UM PROGRAMA QUE LEIA O TAMANHO DA TABELA E INSIRA VÁRIAS CHAVES NELA. DEPOIS, O PROGRAMA DEVE LER A CHAVE QUE DEVE SER REMOVIDA, E MOSTRAR A TABELA DEPOIS DA REMOÇÃO.

ENTRADA: A ENTRADA CONSISTE DE TRÊS LINHAS:
- A PRIMEIRA LINHA IRÁ CONTER O TAMANHO M DA TABELA (UM NÚMERO INTEIRO)
- A SEGUNDA LINHA CONSISTE DE VÁRIOS INTEIROS POSITIVOS, CORRESPONDENTES AOS VALORES DAS CHAVES A SEREM INSERIDAS. ESTA LINHA TERMINA COM O NÚMERO 0, QUE NÃO DEVE SER INSERIDO NA TABELA.
- A ÚLTIMA LINHA TEM UM ÚNICO INTEIRO, QUE CORRESPONDE À CHAVE QUE QUEREMOS REMOVER.

SAÍDA: NA SAÍDA, O PROGRAMA DEVE A TABELA DEPOIS DA REMOÇÃO DA CHAVE.
*/

//biblioteca
#include <iostream>
#include "hashing.h"

using namespace std;

//sondagem linear - hash auxiliar
int hash_aux(int k, int m)
{
    int h = k % m;
    if(h < 0)
    {
        return h + m;
    }
    return h;
}

//sondagem linear
int hash1(int k, int i, int m)
{
    return (hash_aux(k, m) + i) % m;
}

//função insert
int hash_insert(dado t[], int m, int k)
{
    int i = 0; 
    do 
    {
        int j = hash1(k, i, m);

        if (t[j].status != 1)
        {
            t[j].k = k; 
            t[j].status = 1; 
            return j; 
        }
        else
        {
            i = i + 1; 
        }
    } while (i != m); 
    
    return -1; 
}

//função search
int hash_search(dado t[], int m, int k)
{
    int i = 0; 
    int j;     
    do 
    {
        j = hash1(k, i, m); 

        if (t[j].k == k)
        {
            return j; 
        }
        
        i = i + 1; 

    } while (t[j].status != 0 && i < m); 

    return -1; 
}

//função remove
int hash_remove(dado t[], int m, int k)
{
    //j = HASH_SEARCH(T, m, k)
    int j = hash_search(t, m, k);
    
    //if(j != -1)
    if(j != -1)
    {
        t[j].status = 2; //T[j].status = 2 (Marca como removido logicamente)
        t[j].k = -1;     //T[j].k = -1
        return 0;        //return 0 // consegui remover
    }
    else
    {
        return -1;       //return -1 // k nao esta na tabela
    }
}

//função principal
int main()
{
    //declaração de váriaveisw
    int m;
    int chaves;
    int remover;
    dado tabela[100];

    //entrada de dados
    //ler tamanho da tabela
    cin >> m;

    //inicializando a tabela
    for (int i = 0; i < m; i++)
    {
        tabela[i].k = -1;     
        tabela[i].status = 0; 
    }

    //ler as chaves a serem inseridas (até digitar 0)
    while(cin >> chaves && chaves != 0)
    {
        hash_insert(tabela, m, chaves);
    }

    //ler a chave que deve ser removida (última linha)
    cin >> remover;

    //removendo a chave
    hash_remove(tabela, m, remover);

    //saída de dados
    //mostrar a tabela depois da remoção
    for (int i = 0; i < m; i++)
    {
        cout << tabela[i].k << " ";
    }
    cout << endl;
    return 0;
}