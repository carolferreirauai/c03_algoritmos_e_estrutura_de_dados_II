/*
ORD - ORDENE UM VETOR

FAÇA UM PROGRAMA QUE USE ALGORITMOS QUICK SORT PARA ORDENAR UM VETOR EM ORDEM CRESCENTE.

ENTRADA: A ENTRADA CONSISTE DE VÁRIOS NÚMEROS REAIS, QUE DEVEM SER INSERIDOS NO VETOR. O FINAL DA ENTRADA É SINALIZADO PELO
NÚMERO -1, QUE NÃO DEVE SER INSERIDO NO VETOR.

SAÍDA: NA SAÍDA, O PROGRAMA DEVE MOSTRAR COMO FICOU O VETOR EM ORDEM CRESCENTE.
*/
#include <iostream>
#include <cmath> //necessária para a função round() no quick sort
#include "ordenacao.h"
#include <iomanip> //necessário para setprecision(1)

using namespace std;

//troca e partiição
// ========================================================================= //
void quicksort(double vetor[], int i, int j) //mudar vetor de 'int' para 'float'
// ========================================================================= //
{
    // ====================================== //
    double trab, pivo; //mudei de int para float
    // ====================================== //
    int esq, dir;
    esq = i; //ponteiro da esquerda começa com o início do subvetor
    dir = j; //ponteiro da direita começa no final do subvetor

    //escolher o elemet=nto do meio como pivô, a função round() serve para arredondar
    pivo = vetor[(int)round((esq + dir) / 2.0)];

    //fase de particionamento
    do
    {
        //o ponteiro 'esq' anda para direita enquanto os números forem menores que pivo
        while (vetor[esq] < pivo)
        {
            esq++;
        }
        //o ponteiro 'dir' anda para esquerda enquanto os números forem maiores que pivo
        while (vetor[dir] > pivo)
        {
            dir--;
        }
        //se eles pararam e ainda não se cruzaram, é porque acharam elemento do lado errado
        if (esq <= dir)
        {
            //troca os elementos de lado
            trab = vetor[esq];
            vetor[esq] = vetor[dir];
            vetor[dir] = trab;

            //depois da troca, ambos dão um passo á frente
            esq++;
            dir--;
        }
    } while (esq <= dir); //repete até os ponteiros cruzarem

    //fase recursiva
    //se o subvetor esquerdo, tiver mais de um elemento, chama o quicksort
    if (dir - i >= 0)
    {
        quicksort(vetor, i, dir);
    }
    //se o subvetor direita, tiver mais de um elemento, chama o quicksort
    if (j - esq >= 0)
    {
        quicksort(vetor, esq, j);
    }
}

//função principal
int main()
{
    //declaração de variaveis
    double numeros; //numeros reais
    double vetor[100]; //vetor com 100 elemento
    int tamanho = 0;

    //entrada de dados
    //ler os número diferente de -1
    while(cin >> numeros && numeros != -1)
    {
        //armazenar em vetor
        vetor[tamanho] = numeros;
        tamanho++;
    }

    //desenvolvimento
    //chamar a função
    //passar o primeiro índice (0), até o penúltimo índice
    quicksort(vetor, 0, tamanho - 1);

    //saida de dados
    //números decimais 1.1
    cout << fixed << setprecision(1);

    //percorrer ao vetor do 0 até o penúltimo.
    for (int i = 0; i < tamanho; i++)
    {
        cout << vetor[i] << " ";
    }

    cout << endl;

    return 0;
}