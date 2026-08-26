/*
12. IMPLEMENTE A FUNÇÃO PLACE PARA UMA FILA DE PRIORIDADE ASCENDENTE, IMPLEMENTADA
A PARTIR DE UMA LISTA DUPLAMENTE LIGADA.
*/

//biblioteca
#include <iostream>
#include <list> //necessaria para listas

using namespace std;

//função place - insere de uma forma ordenada
void place(list<int> &lista, int x)
{
    list<int>::iterator p;
    bool inserido = false;

    //percorrer a lista
    for(p = lista.begin(); p != lista.end(); p++)
    {
        if(*p > x)
        {
            lista.insert(p, x);
            inserido = true;
            break;
        }
    }

    //varreu e ninguem é maior
    if(!inserido)
    {
        lista.push_back(x);
    }
}

//função remover - remover o menor elemento
int remover(list<int> &lista)
{
    if(lista.empty())
    {
        return -1; //lista vazia
    }
    int menor = lista.front(); //ordenada, o menor está no início
    lista.pop_front(); //remove
    return menor;
}

void imprimir(list<int> &lista)
{
    if(lista.empty())
    {
        cout << "[Vazia]";
    }
    else
    {
        list<int>::iterator p;
        for(p = lista.begin(); p != lista.end(); p++)
        {
            cout << *p << endl;
        }
    }
    cout << endl;
}

//função principal
int main()
{
    //declaração de variáveis
    list<int> fila_prioridade;
    int quantidades, numeros;

    //entrada de dados
    cin >> quantidades;
    for (int i = 0; i < quantidades; i++)
    {
        cin >> numeros;

        //chama função
        place(fila_prioridade, numeros);
        cout << "Inserido: " << numeros << " -> Fila atual: ";
        imprimir(fila_prioridade);
    }

    //desevolvimento/saida de dados
    while(!fila_prioridade.empty())
    {
        int removido = remover(fila_prioridade);
        cout << "Removido: " << removido << " | Fila restante: ";
        imprimir(fila_prioridade);
    }

    return 0;
}