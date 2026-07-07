/*
PONT - MAIOR ELEMENTO DE UM VETOR

FAÇA UM PROGRAMA QUE LEIA INICIALMENTE O TAMANHO DE N DE UM VETOR DE INTEIROS.

DEPOIS, O PROGRAMA DEVE LER N NÚMEROS INTEIROS E OS INSERI-LOS NO VETOR.

FINALMENTE, VARRA O VETOR USANDO UM PONTEIRO, E RETORNE O MAIOR ELEMENTO DESTE VETOR.

ENTRADA: A ENTRADA CONSISTE DE 2 LINHAS:
- A PRIMEIRA LINHA CONTÉM APENAS UM INTEIROS N, QUE CORRESPONDE AO TAMANHO DO VETOR.
- NA SEGUNDA LINHA, TEM-SE N INTEIROS, SEPARADOS POR UM ESPAÇO EM BRANCO.

SAÍDA: NA SAÍDA, O PROGRAMA DEVE MOSTRAR O MAIOR ELEMENTO INSERIDO NO VETOR.
*/
//biblioteca
#include <iostream>

using namespace std;

//função principal
int main()
{
    //declaração de variáveis
    int tamanho;
    int *vetor;
    int *p;
    int maior_elemento;

    //entrada de dados
    cin >> tamanho; //ler o tamanho n do vetor

    vetor = new int[tamanho]; //alocar memória dinamicamente

    //desenvolvimento
    //ler n e inseri-los no vetor
    for (int i = 0; i < tamanho; i++)
    {
        cin >> vetor[i];
    }

    p = vetor; //ponteiro auxiliar apontando o inicio do vetor
    maior_elemento = *p; //primeiro elemento apontado para p

    //varrer um varrar o vetor usando ponteiro e retornar o maior elemento
    for (int i = 0; i < tamanho; i++)
    {
        //se o endereço de 'p' for maior que maior_elemento
        if (*p > maior_elemento)
        {
            maior_elemento = *p; //atualiza o maior_elemento
        }
        p++; //avança pro próximo
    }

    //saída de dados
    cout << maior_elemento << endl;

    //liberar memórias
    delete[] vetor;

    return 0;
}