/*
HASH - JUNTANDO TUDO 1

FAÇA UM PROGRAMA QUE INSIRA, REMOVA, PESQUISE E LISTE OS ELEMENTOS DE UMA TABELA, SEGUNDO O MENU ABAIXO:

1: INSERIR

2: PESQUISAR

3: REMOVER

4: LISTAR

5: SAIR DO PROGRAMA

USE SONDAGEM LINEAR PARA ESTE PROBLEMA.

ENTRADA: A ENTRADA CONSISTE DE VÁRIAS LINHAS:
- A PRIMEIRA LINHA IRÁ CONTER O TAMANHO M DA TABELA (UM NÚMERO INTEIRO)
- AS DEMAIS LINHAS PODEM CONTER UM OU DOIS INTEIROS, DEPENDENDO DA OPÇÃO DO MENU ESCOLHIDA:
   SE O OPÇÃO FOR 1 (INSERIR), O PROGRAMA DEVE LER O VALOR DA CHAVE K E INSERI-LA NO PROGRAMA. NENHUMA SAÍDA DEVERÁ SER DADA NESTE CASO.
   SE A OPÇÃO FOR 2 (PESQUISAR), O PROGRAMA DEVE LER O VALOR DA CHAVE K E MOSTRAR A POSIÇÃO EM QUE ESTA ESTÁ NA TABELA HASH, OU MOSTRAR -1, CASO NÃO ESTEJA;
   SE A OPÇÃO FOR 3 (REMOVER), O PROGRAMA DEVE LER O VALOR DA CHAVE K E REMOVÊ-LA DA TABELA HASH. NENHUMA SAÍDA DEVERÁ SER DADA NESTE CASO.
   SE A OPÇÃO FOR 4 (LISTAR A TABELA), O PROGRAMA DEVE MOSTRAR OS VALORES DAS CHAVES NA TABELA, EM UMA ÚNICA LINHA, COM AS CHAVES SEPARADAS POR ESPAÇOS.
   SE A OPÇÃO FOR (SAIR), O PROGRAMA DEVERÁ SER ENCERRADO.

SAÍDA: NA SAÍDA, O PROGRAMA DEVE EFETUAR A OPERAÇÃO SOLICITADA.
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
    
    return -1; //tabela cheia
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
    int j = hash_search(t, m, k);
    
    if(j != -1)
    {
        t[j].status = 2;
        t[j].k = -1;     
        return 0;        
    }
    else
    {
        return -1;       
    }
}

//função principal
int main()
{
    //declaração de variaveis
    int m;
    int opcao;
    int k;
    dado tabela[100];

    //entrada de dados
    //ler tamanho da tabela
    cin >> m;

    //desenvolvimento
    //inicializando a tabela
    for (int i = 0; i < m; i++)
    {
        tabela[i].k = -1;     
        tabela[i].status = 0; 
    }

    //leitura do menu
    while (cin >> opcao && opcao != 5)
    {
        switch (opcao)
        {
            case 1: //inserir
                cin >> k;
                hash_insert(tabela, m, k);
                break;
                
            case 2: //pesquisar
                cin >> k;
                cout << hash_search(tabela, m, k) << endl;
                break;
                
            case 3: //remover
                cin >> k;
                hash_remove(tabela, m, k);
                break;
                
            case 4: //listar
                for (int i = 0; i < m; i++)
                {
                    cout << tabela[i].k << " ";
                }
                cout << endl;
                break;
            
            default:
                break;
        }
    }
    return 0;
}