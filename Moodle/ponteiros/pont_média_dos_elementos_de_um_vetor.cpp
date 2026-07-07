/*
PONT - MÉDIA DOS ELEMENTOS DE UM VETOR

FAÇA UM PROGRAMA QUE LEIA INICIALMENTE O TAMANHO N DE UM VETOR DE INTEIROS.

DEPOIS, O PROGRAMA DEVE LER N NÚMEROS INTEIROS E OS INSERI-LOS NO VETOR.

FINALMENTE, VARRA O VETOR USANDO UM PONTEIRO, E CALCULE A MÉDIA DOS ELEMENTOS DESTE VETOR.

ENTRADA: A ENTRADA CONSISTE DE 2 LINHAS:
- A PRIMEIRA CONTÉM APENAS UM INTEIRO N, QUE CORRESPONDE AO TAMANHO DE VETOR.
- NA SEGUNDA LINHA, TEM-SE N INTEIROS, SEPARADOS POR UM ESPAÇO EM BRANCO.

SAÍDA: NA SAÍDA, O PROGRAMA DEVE MOSTRAR A MÉDIA DOS ELEMENTOS INSERIDOS NO VETOR, COM 2 CASAS DECIMAIS.
*/
//biblioteca
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    //declaração de variáveis
    int tamanho;
    int *vetor;
    int *p; //ponteiro auxiliar
    double soma = 0;
    double media;

    //entrada de dados
    cin >> tamanho; //ler tamanho de n de um vetor

    //alocar memória dinamicamente
    vetor = new int[tamanho];

    //ler tamanho e inseri-los no vetor
    for (int i = 0; i < tamanho; i++)
    {
        cin >> vetor[i];
    }

    //desenvolvimento
    p = vetor; //ponteiro auxiliar apontando para o inicio do vetor alocado

    //varrer o vetor
    for (int i = 0; i < tamanho; i++)
    {
        soma += *p; //somar no ponteiro auxiliar
        p++; //avançar pro prócimo
    }

    //calcular a média
    media = soma / tamanho;

    //saída de dados com 2 casas decimais
    cout << fixed << setprecision(2) << media << endl;

    //liberar memória
    delete[] vetor;

    return 0;
}