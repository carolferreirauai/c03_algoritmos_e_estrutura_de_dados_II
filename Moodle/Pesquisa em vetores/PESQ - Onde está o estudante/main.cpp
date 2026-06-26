#include <iostream>
#include "busca.h"

using namespace std;

int main()
{
    //declaração de variaveis
    int matricula; //matricula dos alunos
    int n; //quantidade de alunos
    int x; //corredor que o aluno vai
    int vetor[10005]; //vetor de 10.000 alunos

    //entrada de dados
    cin >> n; //lê a quantidade de alunos

    //lê as matriculas
    //loop, irá rodar até n vezes
    for(int i = 0; i < n; i++)
    {
        cin >> vetor[i]; //guarda a matrícula na posição i
    }

    //lê a matrícula que estou procurando
    cin >> x;

    //desenvolvimento
    //chama a função
    int posicao = sequencial(vetor, n, x);

    //saida de dados
    //a posição em que a matricula está guardada representa o número do corredor
    if (posicao != -1)
    {
        cout << "Corredor " << posicao << endl;
    }
    //se retornar -1, o aluno não foi encontrado
    else
    {
        cout << "Não localizado" << endl;
    }

    return 0;
}