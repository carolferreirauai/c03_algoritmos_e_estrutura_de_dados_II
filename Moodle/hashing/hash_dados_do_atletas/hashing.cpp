/*
HASH - DADOS DOS ATLETAS

QUEREMOS GUARDAR ALGUNS DADOS DOS ATLETAS DE UMA EQUIPE EM UMA TABELA HASH.
OS DADOS SÃO:
- NOME
- IDADE
- PESO
- ALTURA

DESTA FORMA, PODEMOS CRIAR UMA STRUCT PARA ARMAZENAR ESTES DADOS:

STRUCT INFO
{
    STRING NOME;
    INT IDADE;
    FLOAT PESO;
    FLOAT ALTURA; 
};

E A STRUCT DADO FICARIA ASSIM:

STRUCT DADO
{
    INFO ATLETA; // NOME, IDADE, PESO E ALTURA DE CADA ATLETA
    INT K; // CHAVE
    INT STATUS; // 0:VAZIO, 1:OCUPADO, 2:REMOVIDO
};

REPITA O PROBLEMA ANTERIOR PARA UM ESQUEMA DE HASHING QUE GERE A CHAVE A PARTIR DO NOME DE CADA ATLETA.
COMO NO EXERCÍCIO ANTERIOR, A CHAVE DEVE SER CALCULADA COMO A SOMA DOS VALORES ASCII DE CADA UM DE SEUS CARACTERES.
POR EXEMPLO, "INATEL" GERA UMA CHAVE K = 605.

USE O DOUBLE HASHING PARA ESTE PROBLEMA.

ENTRADA: A ENTRADA CONSISTE DE VÁRIAS LINHAS:
- A PRIMEIRA LINHA IRÁ CONTER O TAMANHO M DA TABELA (UM NÚMERO INTEIRO)
- AS DEMAIS LINHAS DEPENDEM DA OPÇÃO DO MENU ESCOLHIDA:
   SE A OPÇÃO FOR 1 (INSERIR), O PROGRAMA DEVE LER AS INFORMAÇÕES A SEREM ARMAZENADAS PARA CADA ATLETA (NOME, IDADE, PESO E ALTURA) E INSERI-LAS NA TABELA. NENHUMA SAÍDA DEVERÁ SER DADA NESTE CASO.
   SE A OPÇÃO FOR 2 (PESQUISAR), O PROGRAMA DEVE LER O NOME DO ATLETA A SER PESQUISADO E MOSTRAR OS DADOS DESTE ATLETA, OU MOSTRAR A MENSAGEM "ATLETA NAO CADASTRADO" (OU "NAO ENCONTRADO"), CASO NÃO ESTEJA;
   SE A OPÇÃO FOR 3 (REMOVER), O PROGRAMA DEVE LER O NOME DO ATLETA E REMOVÊ-LO DA TABELA HASH. NENHUMA SAÍDA DEVERÁ SER DADA NESTE CASO.
   SE A OPÇÃO FOR 4 (LISTAR A TABELA), O PROGRAMA DEVE MOSTRAR TODAS AS INFORMAÇÕES CONTIDAS NA TABELA, PULANDO UMA LINHA ENTRE CADA ATLETA.
   SE A OPÇÃO FOR 5 (SAIR), O PROGRAMA DEVERÁ SER ENCERRADO.

SAÍDA: NA SAÍDA, O PROGRAMA DEVE EFETUAR A OPERAÇÃO SOLICITADA.
*/
//biblioteca
#include <iostream>
#include <string>
#include <iomanip>
#include "hashing.h"

using namespace std;

//função que transforma o texto em um número 'k' (Soma ASCII)
int calcular_k(string nome)
{
    int k = 0;
    //percorre melhorado sem usar o .length()
    for (int i = 0; nome.length(); i++)
    {
        k += nome[i];
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
int hash_insert(dado t[], int m, info atleta)
{
    //a chave é gerada a partir do nome do atleta
    int k = calcular_k(atleta.nome); 
    int i = 0;
    
    do
    {
        int j = dhash(k, i, m);

        //se a gaveta estiver livre
        if (t[j].status != 1)
        {
            t[j].atleta = atleta; 
            t[j].k = k;       
            t[j].status = 1;  
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
int hash_search(dado t[], int m, string nome)
{
    int k = calcular_k(nome);
    int i = 0;
    int j;
    
    do
    {
        j = dhash(k, i, m);

        if (t[j].atleta.nome == nome && t[j].status == 1)
        {
            return j;
        }
        
        i = i + 1;

    } while (t[j].status != 0 && i < m);
    
    return -1;
}

//função de remoção
int hash_remove(dado t[], int m, string nome)
{
    int j = hash_search(t, m, nome);
    
    if (j != -1)
    {
        t[j].status = 2;
        t[j].atleta.nome = "";
        t[j].k = -1;
        return 0;
    }
    return -1;
}

//função principal
int main()
{
    int m;
    int opcao;
    dado tabela[1000];

    //lendo o tamanho da tabela
    cin >> m;

    //inicializando a tabela
    for (int i = 0; i < m; i++)
    {
        tabela[i].status = 0;
        tabela[i].k = -1;
        tabela[i].atleta.nome = "";
    }

    //leitura do menu
    while (cin >> opcao && opcao != 5)
    {
        switch (opcao)
        {
            case 1: //inserir
            {
                info novo_atleta;
        
                getline(cin >> ws, novo_atleta.nome); //lê o nome permitindo espaços
                
                //lê o restante dos dados normalmente
                cin >> novo_atleta.idade >> novo_atleta.peso >> novo_atleta.altura;
                
                hash_insert(tabela, m, novo_atleta);
                break;
            }    
            case 2: //pesquisar
            {
                string nome_busca;
      
                getline(cin >> ws, nome_busca);
                
                int pos = hash_search(tabela, m, nome_busca);
                if (pos != -1)
                {
                    cout << tabela[pos].atleta.nome << endl;
                    cout << tabela[pos].atleta.idade << endl;
                    cout << tabela[pos].atleta.peso << endl;
                    cout << tabela[pos].atleta.altura << endl << endl;
                }
                else
                {
                    cout << nome_busca << " nao encontrado" << endl << endl;
                }
                break;
            }    
            case 3: //remover
            {
                string nome_remover;
                 
                getline(cin >> ws, nome_remover);
                
                hash_remove(tabela, m, nome_remover);
                break;
            }   
            case 4: //listar
            {
                for (int i = 0; i < m; i++)
                {
                    //imprime os dados apenas se a gaveta estiver ocupada
                    if (tabela[i].status == 1)
                    {
                        cout << "Nome: " << tabela[i].atleta.nome << endl;
                        cout << "Idade: " << tabela[i].atleta.idade << endl;
                        cout << fixed << setprecision(1) <<"Peso: " << tabela[i].atleta.peso << endl;
                        cout << fixed << setprecision(4) << "Altura: " << tabela[i].atleta.altura << endl;
                        cout << endl;
                    }
                }
                break;
            }    
            default:
                break;
        }
    }

    return 0;
}