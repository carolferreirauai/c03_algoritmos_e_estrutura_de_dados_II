/*
HASH - GUARDANDO NOMES

REPITA O PROBLEMA ANTERIOR PARA UM ESQUEMA DE HASHING QUE GERE A CHAVE A PARTIR DA INFORMAÇÃO A SER ARMAZENADA.

A INFORMAÇÃO VAI SER UMA STRING DE ATÉ 50 CARACTERES, E A CHAVE DEVE SER CALCULADA COMO A SOMA DOS VALORES ASCII DE CADA UM DE SEUS CARACTERES.

POR EXEMPLO, "INATEL" GERA UMA CHAVE K = 605.

A STRUCT PARA ARMAZENAR OS DADOS DEVE SER MODIFICADA PARA:

STRUCT DADO
{
    STRING INFO; // INFORMACAO
    INT K; // CHAVE
    INT STATUS; // 0: VAZIO, 1:OCUPADO, 2:REMOVIDO
};

USE O DOUBLE HASHING PARA ESTE PROBLEMA.

ENTRADA: A ENTRADA CONSISTE DE VÁRIAS LINHAS:
- A PRIMEIRA LINHA IRÁ CONTER O TAMANHO M DA TABELA (UM NÚMERO INTEIRO)
- AS DEMAIS LINHAS DEPENDEM DA OPÇÃO DO MENU ESCOLHIDA:
   SE A OPÇÃO FOR 1 (INSERIR), O PROGRAMA DEVE LER A INFORMAÇÃO A SER ARMAZENADA (UMA STRING) E INSERI-LA NO PROGRAMA. NENHUMA SAÍDA DEVERÁ SER DADA NESTE CASO.
   SE A OPÇÃO FOR 2 (PESQUISAR), O PROGRAMA DEVE LER A INFORMAÇÃO A SER PESQUISADA E MOSTRAR A POSIÇÃO EM QUE ESTA ESTÁ NA TABELA HASH, OU MOSTRAR -1, CASO NÃO ESTEJA;
   SE A OPÇÃO FOR 3 (REMOVER), O PROGRAMA DEVE LER A INFORMAÇÃO A SER REMOVIDA E REMOVÊ-LA DA TABELA HASH. NENHUMA SAÍDA DEVERÁ SER DADA NESTE CASO.
   SE A OPÇÃO FOR 4 (LISTAR A TABELA), O PROGRAMA DEVE MOSTRAR TODAS AS INFORMAÇÕES CONTIDAS NA TABELA, UMA POR LINHA.
   SE A OPÇÃO FOR 5 (SAIR), O PROGRAMA DEVERÁ SER ENCERRADO.

SAÍDA: NA SAÍDA, O PROGRAMA DEVE EFETUAR A OPERAÇÃO SOLICITADA.
*/
//biblioteca
#include <iostream>
#include <string>
#include "hashing.h"

using namespace std;

//função que transforma o texto em um número 'k' (Soma ASCII)
int calcular_k(string info)
{
    int k = 0;
    //percorre cada letra da palavra
    for (int i = 0; i < info.length(); i++)
    {
        k += info[i]; //soma o valor da letra atual
    }
    return k;
}

//funções do double hashing
int h1(int k, int m)
{
    return k % m;
}

int h2(int k, int m)
{
    return 1 + (k % (m - 1));
}

int dhash(int k, int i, int m)
{
    return (h1(k, m) + i * h2(k, m)) % m;
}

//função de inserção
int hash_insert(dado t[], int m, string info)
{
    int k = calcular_k(info); //calcula o k baseado na palavra
    int i = 0;
    
    do
    {
        int j = dhash(k, i, m);

        // Se a gaveta estiver vazia ou tiver lápide (removido)
        if (t[j].status != 1)
        {
            t[j].info = info; // Salva o nome
            t[j].k = k;       // Salva a chave calculada
            t[j].status = 1;  // Ocupa a vaga
            return j;
        }
        else
        {
            i = i + 1;
        }
    } while (i < m);
    
    return -1;
}

//função de pesquisa
int hash_search(dado t[], int m, string info)
{
    int k = calcular_k(info); 
    int i = 0;
    int j;
    
    do
    {
        j = dhash(k, i, m);

        if (t[j].info == info && t[j].status == 1)
        {
            return j;
        }
        
        i = i + 1;

    } while (t[j].status != 0 && i < m);
    
    return -1;
}

//função de Remoção
int hash_remove(dado t[], int m, string info)
{
    int j = hash_search(t, m, info);
    
    if (j != -1)
    {
        t[j].status = 2; // Lápide de removido
        t[j].info = "";  // Apaga a string (boa prática)
        t[j].k = -1;
        return 0;
    }
    return -1;
}

//função Principal
int main()
{
    int m;
    int opcao;
    string info;
    dado tabela[1000];

    //lendo o tamanho da tabela
    cin >> m;

    //inicializando a tabela
    for (int i = 0; i < m; i++)
    {
        tabela[i].status = 0;
        tabela[i].k = -1;
        tabela[i].info = "";
    }

    //leitura do menu
    while (cin >> opcao && opcao != 5)
    {
        switch (opcao)
        {
            case 1: //inserir
                cin >> info;
                hash_insert(tabela, m, info);
                break;
                
            case 2: //pesquisar
                cin >> info;
                {
                    int pos = hash_search(tabela, m, info);
                    if (pos != -1)
                    {
                        cout << info << " encontrado na posicao " << pos << endl;
                    }
                    else
                    {
                        cout << info << " nao encontrado" << endl;
                    }
                }
                break;
                
            case 3: //remover
                cin >> info;
                hash_remove(tabela, m, info);
                break;
                
            case 4: //listar
                for (int i = 0; i < m; i++)
                {
                    // se estiver ocupado, imprime a string
                    if (tabela[i].status == 1)
                    {
                        cout << tabela[i].info << endl;
                    }
                    // se estiver vazio (0) ou removido (2), imprime "vazio"
                    else
                    {
                        cout << "vazio" << endl;
                    }
                }
                break;
                
            default:
                break;
        }
    }

    return 0;
}