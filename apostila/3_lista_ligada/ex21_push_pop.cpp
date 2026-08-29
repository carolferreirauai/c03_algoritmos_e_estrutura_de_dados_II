/*
21. REIMPLEMENTE AS FUNÇÕES PUSH E POP PARA UM NO COM A SEGUINTE ESTRUTURA:
STRUCT NO
{
    CHAR NOME[200];
    INT MATRICULA;
    INT IDADE;
};
*/

//biblioteca
#include <iostream>
#include <list> //necessario para listas

using namespace std;

struct aluno
{
    char nome[100];
    int matricula;
    int idade;
};

//função push - insere um novo aluno no topo da pilha
void push(list<aluno> &lista, aluno novo_aluno)
{
    lista.push_front(novo_aluno); //insere no topo
}

//função pop - remove o aluno do topo da pilha
bool pop(list<aluno> &lista, aluno &aluno_removido)
{
    if(lista.empty())
    {
        return false; //pilha vazia
    }

    aluno_removido = lista.front(); //recupera os dados do aluno do topo
    lista.pop_front(); //remove fisicamente da lista
    return true; //sucesso
}

//função auxiliar para imprimir
void imprimir(aluno a)
{
    cout << "Nome: " << a.nome << endl;
    cout << "Matricula: " << a.matricula << endl;
    cout << "Idade: " << a.idade << endl;
}

//função principal
int main()
{
    //declaração de variaveis
    list<aluno> pilha;
    int quantidades;
    aluno aluno_max;
    aluno novo;

    //entrada de dados
    //quantidades de alunos
    cout << "Quantidades: ";
    cin >> quantidades;

    //cadastro
    for(int i = 0; i < quantidades; i++)
    {
        cout << "Nome: ";
        cin >> ws;
        cin.getline(novo.nome, 100);

        cout << "Matricula: ";
        cin >> novo.matricula;

        cout << "Idade: ";
        cin >> novo.idade;

        //emilhar registro
        push(pilha, novo);
    }

    //saida de dados
    while(!pilha.empty())
    {
        if(pop(pilha, aluno_max))
        {
            imprimir(aluno_max);
        }
    }

    return 0;
}