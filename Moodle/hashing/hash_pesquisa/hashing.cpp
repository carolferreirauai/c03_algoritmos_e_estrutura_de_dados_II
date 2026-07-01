/*
HASH - PESQUISA

O ALGORITMOS DE PESQUSA EM UMA TABELA HASH É MOSTRADO ABAIXO:
HASH-SEARCH(T, M, K)
    I <- 0
    DO
        J <- HASH1(K, I, M)
        IF T[J].K = K
            RETURN J
        I <- I  + 1
    WHILE(T[J].STATUS != AND I < M)
    RETURN -1

FAÇA UMA FUNÇÃO QUE IMPLEMENTE ESTE ALGORITMO. ESTA FUNÇÃO DEVE RETORNAR A POSIÇÃO ONDE A CHAVE FOI
ENCONTRADA NA TABELA HASH, OU -1 SE A CHAVE NÃO ESTIVER NA TABELA. USE A SONDAGEM LINEAR PARA FAZER A
SONDAGEM NA TABELA. SUA FUNÇÃO DEVE TER O SEGUINTE CABEÇALHO.

INT HA_SEARCH(DADO T[], INT M, INT K)

FAÇA ENTÃO UM PROGRAMA QUE LEIA O TAMANHO DESEJADO M PARA A TABElA HASH E INSIRA VÁRIAS CHAVES 
NESTA.

DEPOIS, O PROGRAMA DEVE LER O ELEMENTO A SER PROCURTADO E RETORNAR A POSIÇÃO EM QUE ESTE SE ENCONTRA.
SE O ELEMENTO NÃO ESTIVER NA TABELA, UMA MENSAGEM DEVE SER MOSTRADA

ENTRADA: A ENTRADA CONSISTE DE TRÊS LINHAS:
- A PRIMEIRA LINHA IRÁ CONTER O TAMANHO M DA TABELA (UM NÚMERO INTEIRO).
- A SEGUNDA LINHA CONSISTE DE VÁRIOS POSITIVOS, CORRESPONDENTES AOS VALORES DAS CHAVES A SEREM
INSERIDAS. ESTA LINHAS TERMINA COM O NÚMERO 0, QUE NÃO DEVE SER INSERIDO NA TABELA.
- A ÚLTIMA LINHA TEM ÚNICO INTEIRO, QUE CORREPONDE À CHAVE QUE QUEREMOS VERIFICAR.

SAÍDA: NA SAÍDA, O PROGRAMA DEVE MOSTRAR ONDE A CHAVE FOI ENCONTRADA, OU UMA MENSAGEM DIZENDO QUE A
CHAVE NÃO ESTÁ NA TABEL, COMO NO EXEMPLO ABAIXO.
*/

//biblioteca
#include <iostream>
#include "hashing.h"

using namespace std;

//sondagem linear - hash auxiliar
int hash_aux(int k, int m)
{
    //metodo de divisão
    int h = k % m;

    //verifica se o resto 'h' é negativo
    if(h < 0)
    {
        return h + m;
    }
    return h;
}

//sondagem linear
int hash1(int k, int i, int m)
{
    //(h'(k, m) + i) mod m
    return (hash_aux(k, m) + i) % m;
}

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
    } while (i != m); //while i != m
    
    return -1; //return -1, tabela cheia
}

//função search (Nova função de Pesquisa!)
int hash_search(dado t[], int m, int k)
{
    int i = 0; //i <- 0
    int j;
    
    do //do
    {
        j = hash1(k, i, m); //j <- hash1(k, i, m)

        //if T[j].k = k
        if (t[j].k == k)
        {
            return j; //return j
        }
        
        i = i + 1; //i <- i+1

    //while (T[j].status != 0 and i < m)
    } while (t[j].status != 0 && i < m); 

    return -1; //return -1 (chave não encontrada)
}

//função principal
int main()
{
    //declaração de váriaveis
    int m, chaves, procurado;
    dado tabela[100];

    //entrada de dados
    //ler tamanho da tabela
    cin >> m;

    //desenvolvimento
    //inicializando a tabela
    for (int i = 0; i < m; i++)
    {
        tabela[i].k = -1;     // Preenchidas com -1 inicialmente
        tabela[i].status = 0; // 0: Vazio
    }
    
    //ler as chaves até que seja digitado 0
    while(cin >> chaves && chaves != 0)
    {
        //inserindo na tabela
        hash_insert(tabela, m, chaves);
    }

    //ler a chave a ser pesquisada
    cin >> procurado;

    //buscar a chave na tabela hash
    int resultado = hash_search(tabela, m, procurado);

    //saida de dados
    if (resultado != -1)
    {
        cout << "Chave " << procurado << " encontrada na posicao " << resultado << endl;
    }
    else
    {
        cout << "Chave " << procurado << " nao encontrada" << endl;
    }

    return 0;
}