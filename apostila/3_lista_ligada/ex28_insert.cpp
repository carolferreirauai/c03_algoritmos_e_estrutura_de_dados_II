/*
28. FAÇA UMA FUNÇÃO QUE INSIRA UM ELEMENTO EM UMA LISTA DUPLAMENTE LIGADA DE
FORMA A MANTÊ-LA SEMPRE ORDENADA.
*/
//biblioteca
#include <iostream>
#include <list> //necessario para listas

using namespace std;

//função insere mantendo a lista sempre ordenada
void insere_ordenado(list<int> &lista, int x)
{
    list<int>::iterator p;

    //varre a lista
    for(p = lista.begin(); p != lista.end(); p++)
    {
        if(*p >= x)
        {
            //insere o elemento
            lista.insert(p, x);
            return; //termina a função
        }
    }

    //insere no final
    lista.push_back(x);
}

//função auxiliar para imprimir
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
            cout << *p << " ";
        }
    }
    cout << endl;
}

//função principal
int main()
{
    //declaração de variáveis
    list<int> lista;
    int quantidades, numero;

    //entrada de dados
    cout << "Quantidades: ";
    cin >> quantidades;

    for(int i = 0; i < quantidades; i++)
    {
        cin >> ws;
        cin >> numero;

        //chamar a função de inserção
        insere_ordenado(lista, numero);

        //exibe o estado
        cout << "Lista atual: ";
        imprimir(lista);
    }

    return 0;
}