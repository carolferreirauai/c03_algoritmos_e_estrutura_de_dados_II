/*
23. FAÇA UMA FUNÇÃO QUE TOME O PONTEIRO PARA UMA LISTA LIGADA, GERADA PELO EXERCÍCIO
ANTERIOR, E MOSTRE O NOME DAS PESSOAS COM MENOS DE 18 ANOS DE IDADE. A FUNÇÃO
DEVE TER O SEGUINTE CABEÇALHO:

VOID MOSTRAMAIORES(NOPTR LISTA)
*/

//biblioteca
#include <iostream>
#include <list> //necessario para listas

using namespace std;

struct pessoa
{
    char nome[100];
    int idade;
    char sexo;
};

//função push
void push(list<pessoa> &lista, pessoa nova_pessoa)
{
    lista.push_front(nova_pessoa); //insere no inicio
}

void mostrarmaiores(list<pessoa> &lista)
{
    list<pessoa>::iterator p;
    bool encontrou = false;

    //percorre a lista
    for(p = lista.begin(); p != lista.end(); p++)
    {
        if((*p).idade < 18)
        {
            cout << "Nome: " << (*p).nome << endl;
            cout << "Idade: " << (*p).idade << endl;
            encontrou = true;
        }
    }
    if(!encontrou)
    {
        cout << "[Nenhuma pessoa com menos de 18 anos encontrada]" << endl;
    }
}

//função principal
int main()
{
    //declaração de variáveis
    list<pessoa> lista;
    pessoa novo;
    int quantidades;

    //entrada de dados
    //quantidades
    cout << "Quantidades: ";
    cin >> quantidades;

    //cadastro
    for(int i = 0; i < quantidades; i++)
    {
        cout << "Nome: ";
        cin >> ws;
        cin.getline(novo.nome, 100);

        cout << "Sexo: ";
        cin >> novo.sexo;

        cout << "Idade: ";
        cin >> novo.idade;

        //chamar a função push
        push(lista, novo);
    }

    //saida de dados
    mostrarmaiores(lista);

    return 0;
}