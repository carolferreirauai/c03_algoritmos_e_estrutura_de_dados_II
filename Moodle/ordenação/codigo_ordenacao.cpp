#include <cmath> //necessária para a função round() no quick sort
#include "ordenacao.h"

//inserção direta
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

//método da bolha
void bubblesort(int vetor[], int tamanho)
{
    int i, j; // contadores
    int trab; //variável auxiliar
    bool troca; //sinalizador para saber se houve a troca
    int limite; //marca aré onde

    troca = true; //força a primeira entrada
    limite = tamanho - 1; //na primeira rodada até o penúltimo elemento

    //continnua rodado enquanto o vetor não estiver ordenado
    while (troca)
    {
        //assume que está ordenado
        troca = false;

        //varre o vetor do início até o limite atual
        for (i = 0; i < limite; i++)
        {
            //o elemento da esquerda for maior que da direita
            if (vetor[i] > vetor[i + 1])
            {
                //faz a troca de posições
                trab = vetor[i];
                vetor[i] = vetor[i + 1];
                vetor[i + 1] = trab;
                
                j = i; //grava a posição da última troca
                troca = true; //sinaliza que 0o vetor ainda não tá pronto
            }
        }
        // tudo que está no 'j' já flutuou para o lugar certo.
        limite = j;
    }
}

//troca e partiição
void quicksort(int vetor[], int i, int j)
{
    int trab, esq, dir, pivo;
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
        quickSort(vetor, i, dir);
    }
    //se o subvetor direita, tiver mais de um elemento, chama o quicksort
    if (j - esq >= 0)
    {
        quickSort(vetor, esq, j);
    }
}