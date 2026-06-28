/*
ORD - INSERTION SORT

FAÇA UMA FUNÇÃO QUE ORDENE UM VETOR EM ORDEM DECRESCENTE USANDO O ALGORITMO DE ORDENAÇÃO
INSERTION SORT.

ENTRADA: A ENTRADA CONSISTE EM VÁRIOS NÚMEROS INTEIROS, QUE DEVEM SER INSERIDOS NO VETO. O FINAL DA ENTRADA É
SINALIZADO PELO NÚMERO 0, QUE NÃO DEVE SER INSERIDO NO VETOR.

SAÍDA: NA SAÍDA, O PROGRAMA DEVE MOSTRAR COMO FICOU O VETOR EM ORDEM DECRESCENTE. NÃO HÁ ESPAÇO EM
BRANCO APÓS O ÚLTIMO ELEMENTO.
*/

#include <cmath> //necessária para a função round() no quick sort
#include "ordenacao.h"
#include <iostream>

using namespace std;

//função inserção direta
void insercaodireta(int vetor[], int tamanho)
{
    int i, j; // contadores
    int chave; //guarda o valor que tea inserir na posição certa

    //o loop começa no índice = 1, pois assumira que o índice 0 já está ordenado
    for (j = 1; j < tamanho; j++)
    {
        chave = vetor[j]; //pega o próximo elemento
        i = j - 1; //'i' aponta para o último elemento

        //o loop enquanto não chegar no início do vetor (i >= 0)
        // o elemento atual for maior que a chave
        while ((i >= 0) && (vetor[i] > chave))
        {
            //empurra o elemento grande uma posição a direita
            vetor[i + 1] = vetor[i];
            i = i - 1; //volta a posição a esquerda
        }
        
        //achar um elemento maior ou igual chave, coloca a chave na posição correta.
        vetor[i + 1] = chave;
    }
}

//função principal
int main()
{
    //declaração de váriaveis
    int numeros; //numeros inteiros
    int vetor[105];
    int tamanho = 0;

    //entrada de dados
    //ler os números diferente de 0.
    while(cin >> numeros && numeros != 0)
    {
        vetor[tamanho] = numeros; //guarda o número no vetor
        tamanho++; //aumenta mais um no contador de tamanho
    }

    //desenvolvimento
    //chamar a função
    insercaodireta(vetor, tamanho);

    //saída de dados
    //imprime os números 
    for(int i = 0; i < tamanho; i++)
    {
        cout << vetor[i];

        if(i < tamanho - 1)
        {
            cout << " ";
        }
    }

    cout << endl;
    
    return 0;
}