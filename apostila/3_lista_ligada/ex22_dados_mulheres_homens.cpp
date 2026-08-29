/*
22. FAÇA UM PROGRAMA QUE USE AS FUNÇÕES QUE VOCÊ IMPLEMENENTOU PARA LER O NOME E A
IDADE DE UM CONJUNTO DE PESSOAS E GERAR UMA LISTA LIGADA.

DEPOIS O PROGRAMA DEVE MOSTRAR NA TELA, OS DADOS INSERIDOS, NA SEGUINTES ORDEM:
(A) MULHERES COM MENOS DE 18 ANOS
(B) HOMENS COM MENOS DE 18 ANOS
(C) MULHERES COM 18 ANOS OU MAIS
(D) HOMENS COM 18 ANOS OU MAIS
*/

//biblioteca
#include <iostream>
#include <list> //necessario para listas

using namespace std;

struct pessoa
{
    char nome[100];
    int idade;
    char sexo; //M ou F
};

//função push - insere uma nova pessoa no inicio
void push(list<pessoa> &lista, pessoa nova_pessoa)
{
    lista.push_front(nova_pessoa); //insere no inicio da lista
}

void grupo(list<pessoa> &lista, char sexo_alvo, bool menor)
{
    list<pessoa>::iterator p;
    bool encontrou = false;

    char sexo_minusculo = sexo_alvo + 32;

    for (p = lista.begin(); p != lista.end(); p++)
    {
        if((*p).sexo == sexo_alvo || (*p).sexo == sexo_minusculo)
        {
            if(menor && (*p).idade < 18)
            {
                cout << "Nome: " << (*p).nome << endl;
                cout << "Idade: " << (*p).idade << endl;
                encontrou = true;
            }
            else if (!menor && (*p).idade >= 18)
            {
                cout << "Nome: " << (*p).nome << endl;
                cout << "Idade: " << (*p).idade << endl;
                encontrou = true;
            }
        }
    }

    if(!encontrou)
    {
        cout << "[Nenhuma pessoa cadastrada nesta categoria]" << endl;
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
    for (int i = 0; i < quantidades; i++)
    {
        cout << "Nome: ";
        cin >> ws;
        cin.getline(novo.nome, 100);

        cout << "Sexo: ";
        cin >> novo.sexo;

        cout << "Idade: ";
        cin >> novo.idade;

        //chama a função
        push(lista, novo);
    }

    //saida de dados
    cout << "Mulheres com menor de 18 anos: " << endl;
    grupo(lista, 'F', true);

    cout << "Homens com menor de 18 anos: " << endl;
    grupo(lista, 'M', true);

    cout << "Mulheres com maiores de 18 anos: " << endl;
    grupo(lista, 'F', false);

    cout << "Homens com maiores de 18 anos: " << endl;
    grupo(lista, 'M', false);

    return 0;
}