/*
PONT - INSERIDO ELEMENTOS EM UM VETOR

FAÇA UM PROGRAMA QUE LEIA INICIALMENTE O TAMANHO N DE UM VETOR DE INTEIROS

DEPOIS, O PROGRAMA DEVE ALOCAR DINAMICAMENTE UM VETOR DE N POSIÇÕES.

EM SEGUIDA, O PROGRAMA DEVE LER N NÚMEROS INTEIROS E OS INSERI-LOS NO VETOR, USANDO UM SEGUNDO
PONTEIRO PARA ESTA TAREFA: SE O VETOR É V, E O PONTEIRO É P, VOCÊ DEVE USAR P PARA APONTAR PARA A POSIÇÃO
CORRETA DO VETOR, E USAR ESTE PONTEIRO PARA INSERIR O ELEMENTO NO VETOR.

FINALMENTE, VARRA O VETOR USANDO UM PONTEIRO, E MOSTRE O SEU CONTEÚDO.

ENTRADA: A ENTRADA CONSISTE DE 2 LINHAS:
- A PRIMEIRA LINHA CONTÉM APENAS UM INTEIRO N, QUE CORRESPONDE AO TAMANHO DO VETOR
- NA SEGUNDA LINHA, TEM-SE N INTEIROS, SEPARADOS POR UM ESPAÇO EM BRANCO.

SAÍDA: NA SAÍDA, O PROGRAMA DEVE MOSTRAR OS ELEMENTOS INSERIDOS.
*/
#include <iostream>

using namespace std;

int main()
{
    //declaração de váriaveis
    int tamanho; 
    int *v;
    int *p; //segundo ponteiros

    //entrada de dados
    cin >> tamanho; //ler o tamanho n de um vetor
    v = new int[tamanho]; //alocar dinamicamente um vetor de n

    //'p' aponta a posição correta
    p = v;

    //ler n números inteiros e os inseri-los no vetor usando um segundo ponteiro
    for (int i = 0; i < tamanho; i++)
    {
        cin >> *p; //insere
        p++; //avança pro próximo
    }

    //'p' aponta a posição correta
    p = v;

    //saída de dados
    for (int i = 0; i < tamanho; i++)
    {
        cout << *p << " "; //imprime 
        p++; //avança
    }
    cout << endl;

    //liberar a memória
    delete[] v;

    return 0;
}