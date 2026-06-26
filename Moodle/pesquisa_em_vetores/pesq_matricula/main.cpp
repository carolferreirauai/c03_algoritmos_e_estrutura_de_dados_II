#include <iostream>
#include "busca.h"

using namespace std;

//função principal
int main()
{
    //declaração de váriaveis
    int n; //quantidade alunos
    dados alunos[10005]; //vetor com 10000
    string nome_consultado; //aluno para ser encontrado

    //entrada de dados
    cin >> n; //lê a quantidade de alunos

    //lê os dados
    for (int i = 0; i < n; i++)
    {
        //getline por conta da strings
        getline(cin >> ws, alunos[i].nome); //nome
        getline(cin >> ws, alunos[i].curso); //curso
        cin >> alunos[i].matricula; //matriculas
    }

    //lê o aluno para ser consultado
    getline(cin >> ws, nome_consultado);

    //desenvolvimento
    //chama a função
    int posicao = sequencial(alunos, n, nome_consultado);

    //saida de dados
    if (posicao != -1)
    {
        //se a função retornar diferente de -1, acessa os dados dele
        cout << alunos[posicao].nome << endl;
        cout << alunos[posicao].curso << endl;
        cout << alunos[posicao].matricula << endl;
    }
    else
    {
        //se a função retornar -1, ele dá não encontrado
        cout << "Aluno não encontrado" << endl;
    }
    return 0;
}