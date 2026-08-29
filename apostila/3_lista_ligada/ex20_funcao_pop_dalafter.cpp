/*
20. FAÇA UMA FUNÇÃO QUE REMOVA TODOS OS NÓS DE UMA LISTA LIGADA CUJO CAMPO INFO
SEJA UM NÚMERO PAR. ASSUMA QUE FUNÇÕES POP() E DELAFTER() ESTEJAM DISPONIVEIS.
*/

//biblioteca
#include <iostream>
#include <list> //necessaria para listas

using namespace std;

//função remover
void remover_pares(list<int> &lista)
{
    list<int>::iterator p = lista.begin();

    //varrer a lista
    while(p != lista.end())
    {
        //verifica
        if(*p % 2 == 0)
        {
            p = lista.erase(p);
        }
        else
        {
            p++; //se for impar
        }
    }
}

//função auxiliar
void imprimir(list<int> &lista)
{
    if(lista.empty())
    {
        cout << "[Vazia]";
    }
    else
    {
        list<int>::iterator p;
        for (p = lista.begin(); p != lista.end(); p++)
        {
            cout << *p << " ";
        }
    }
    cout << endl;
}

//função principal
int main()
{
    //declaração de variaveis
    list<int> lista;
    int quantidades, numeros;

    //entrada de dados
    cin >> quantidades;
    for (int i = 0; i < quantidades; i++)
    {
        cin >> numeros;
        //insere no final
        lista.push_back(numeros);
    }

    //desenvolvimento
    //chamar função
    imprimir(lista);
    remover_pares(lista);

    //saida de dados
    imprimir(lista);

    return 0;
}