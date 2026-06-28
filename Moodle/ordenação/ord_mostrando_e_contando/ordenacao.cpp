/*
ORD - MOSTRANDO E CONTANDO

FAÇA UMA FUNÇÃO USANDO O ALGORITMO BUBBLE SORT, QEU MOSTRE TODA VEZ QUE A VARIÁVEL TRAB RECEBER UM NOVO VALOR, O
VALOR QUE ELA RECEBEU. POR ULTIMO FAÇA UM CONTADOR, QUE CONTE QUANTAS VEZES A VARIÁVEL TROCA RECEBE O VALOR TRU.

ENTRADA: A ENTRADA CONSISTE EM UM VALOR INTEIRO QUE CORRESPONDE A QUANTIDADE DE VALORES QUE IRÁ ADICIONAR NO VETOR. EM
SEGUIDA, DEVERÁ ENTRAR COM OS NÚMEROS INTEIROS QUE IRÃO SER INSERIDOS NO VETOR.

SAÍDA: NA SAÍDA, O PROGRAMA DEVE MOSTRAR "NEW TAB:" E OS VALORES QUE VARIÁVEL TRAB RECEBEU E POR FIM "CONTADOR:" COM O
VALOR CONTADO.
*/
#include "ordenacao.h"
#include <iostream>

using namespace std;

//método da bolha
void bubblesort(int vetor[], int tamanho)
{
    int i, j; // contadores
    int trab; //variável auxiliar
    bool troca; //sinalizador para saber se houve a troca
    int limite; //marca aré onde

    troca = true; //força a primeira entrada
    limite = tamanho - 1; //na primeira rodada até o penúltimo elemento

    /* ============================================ */
    int contagem_true = 0; //contagem de trocas true
    /* ============================================ */

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

                /* ============================== */
                //saida de dados 
                cout << "New trab:" << trab << endl;
                /* ============================== */

                vetor[i] = vetor[i + 1];
                vetor[i + 1] = trab;
                
                j = i; //grava a posição da última troca
                troca = true; //sinaliza que 0o vetor ainda não tá pronto

                /* =============== */
                //contagem da troca
                contagem_true++;
                /* =============== */
            }
        }
        // tudo que está no 'j' já flutuou para o lugar certo.
        limite = j;
    }
    /* ======================================== */
    //saida de dados da contagem
    cout << "Contador:" << contagem_true << endl; 
    /* ======================================== */
}

//função principal
int main()
{
    //declaração de váriavel
    int quantidade;
    int vetor[100];

    //entrada de dados
    cin >> quantidade; //ler a quantidade de valores

    //loop que leia todos o números.
    for(int i = 0; i < quantidade; i++)
    {
        cin >> vetor[i];
    }

    //desenvolvimento
    bubblesort(vetor, quantidade);

    return 0;
}