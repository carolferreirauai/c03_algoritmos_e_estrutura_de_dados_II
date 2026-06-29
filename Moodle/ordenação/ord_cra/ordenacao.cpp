/* 
ORD - CRA

O CRA (CENTRO DE REGISTROS ACADÊMICOS) É O ÓRGÃO RESPOSÁVEL POR CADASTRAR OS ALUNOS, REGISTRAR AS
NOTAS, ATRIBUIR AS DISCIPLINAS QUE CADA ALUNO DEVE CURSAR, ALÉM DE VÁRIAS OUTRAS ATIVIDADES.

A ROBÉLIA, COORDENADORA DESTE CENTRO, PEDIU PARA VOCÊ LESSE O NOME, CURSO E MATRÍCULA DOS ALUNOS E
MOSTRASSE ESTES DADOS, ORDENADO POR NOME.

ENTRADA:
- A PRIMEIRA LINHA CONSISTE DE UM ÚNICO INTEIRO, QUE CORREPONDE À QUANTIDADE DE ALUNOS A SEREM
CADASTRADOS.
- DEPOIS, PARA CADA UM DOS N ALUNOS, SERÃO INSERIDOS O NOME, O CURSO E O NÚMERO DE MATRÍCULA. CADA
INFORMAÇÃO VAI SER DIGITADA EM UMA LINHA SEPARADA.

SAÍDA: NA SAÍDA, O PROGRAMA DEVE MOSTRAR OS DADOS DOS ALUNOS, APRESENTADOS EM ORDEM ALFAVÉTICA POR NOME.
*/

#include <cmath> //necessária para a função round() no quick sort
#include "ordenacao.h"
#include <iostream>

using namespace std;

//inserção direta
void insercaodireta(dados vetor[], int tamanho)
{
    int i, j; // contadores

    // ==== mudamos o int da chave para dados ================== //
    dados chave; //guarda o valor que a inserir na posição certa
    // ========================================================= //

    //o loop começa no índice = 1, pois assumira que o índice 0 já está ordenado
    for (j = 1; j < tamanho; j++)
    {
        chave = vetor[j]; //pega o próximo elemento
        i = j - 1; //'i' aponta para o último elemento

        //o loop enquanto não chegar no início do vetor (i >= 0)
        // o elemento atual for maior que a chave

        // ==== acrescentamos .nome no vetor e na chave ==== //
        while ((i >= 0) && (vetor[i].nome > chave.nome))
        // ================================================= //
        {
            //empurra o elemento grande uma posição a direita
            vetor[i + 1] = vetor[i];
            i = i - 1; //volta a posição a esquerda
        }
        
        //achar um elemento maior ou igual chave, coloca a chave na posição correta.
        vetor[i + 1] = chave;
    }
}

int main()
{
    //declaração de váriaveis
    int quantidade; //quantidades de alunos a serem cadastrado
    dados vetor[100]; //vetor com 100 elementos

    //entrada de dados
    //ler as quantidade de alunos
    cin >> quantidade;

    //ler os dados dos alunos
    for (int i = 0; i < quantidade; i++)
    {
        getline(cin >> ws, vetor[i].nome);
        getline(cin >> ws, vetor[i].curso);
        cin >> vetor[i].matricula;
    }

    //desenvolvimento
    //chamar a função
    insercaodireta(vetor, quantidade);

    //saída de dados
    for (int i = 0; i < quantidade; i++)
    {
        cout << vetor[i].nome << endl;
        cout << vetor[i].curso << endl;
        cout << vetor[i].matricula << endl;
    }

    return 0;
}