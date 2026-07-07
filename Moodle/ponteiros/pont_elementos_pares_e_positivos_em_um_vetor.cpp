/*
PONT - ELEMENTOS PARES E POSITIVOS DE UM VETOR

FAÇA UM PROGRAMA QUE LEIA INICIALMENTE O TAMANHO N DE UM VETOR DE INTEIROS

DEPOIS, O PROGRAMA DEVE LER N NÚMEROS INTEIROS E OS INSERI-LOS NO VETOR

FINALMENTE, VARRA O VETOR USANDO UM PONTEIRO, E DETERMINE QUANTOS ELEMENTOS SÃO PARES E POSITIVOS.

ENTRADA: A ENTRADA CONSISTE DE 2 LINHAS:
- A PRIMEIRA LINHA CONTÉM APENAS UM INTEIRO N, QUE CORRESPONDE AO TAMANHO DO VETOR.
- NA SEGUNDA LINHA, TEM-SE N INTEIROS, SEPARADOS POR UM ESPAÇO EM BRANCO.

SAÍDA: NA SAÍDA, O PROGRAMA DEVE MOSTRAR O NÚMERO DE ELEMENTOS PARES E POSITIVOS INSERIDOS NO VETOR.
*/
//biblioteca
#include <iostream>

using namespace std;

int main()
{
    //declaração de variáveis
    int tamanho;
    int *vetor;
    int *p; //ponteiro auxiliar
    int pares_e_positivos = 0; //contador de pares e positivos

    //entrada de dados
    cin >> tamanho; //ler o tamanho n de um vetor

    vetor = new int[tamanho]; //alocar memória dinamicamente

    //desenvolvimento
    //inseri-los em um vetor
    for (int i = 0; i < tamanho; i++)
    {
        cin >> vetor[i];
    }

    //ponteiro auxiliar aponta o inicio
    p = vetor;
    
    //varrar o vetor
    for (int i = 0; i < tamanho; i++)
    {
        //determinar os elementos pares e positivos
        if (*p % 2 == 0 && *p > 0)
        {
            pares_e_positivos++;
        }
        p++; //avança para o próximo ponteiro
    }

    //saída de dados
    cout << pares_e_positivos << endl;

    //liberar memória
    delete[] vetor;

    return 0;
}