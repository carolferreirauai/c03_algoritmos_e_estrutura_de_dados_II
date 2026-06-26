#include "busca.h"

using namespace std;

int sequencial(dados vetor[], int tamanho, string x)
{
    //começa assumido que não achou o aluno
    bool achou = false; // var aux p/ busca
    //iniciará na primeira posição
    int i = 0;          // contador

    //loop será realizado enquanto o 'achou' == falso e o 'i' não ultrapassar o tamanho
    while (achou == false && i < tamanho)
    {
        //compara 'vetor[i++].nome' á string x.
        //'i++' irá contar mais 1, e ir para o próximo aluno
        achou = vetor[i++].nome == x;
    }
    if (achou)
    {
        //se achou for verdadeiro, ele retornará sua posição
        return (i - 1);
    }
    else
    {
        //se achou continuar falso, ele irá retornar -1
        return -1;
    }
}