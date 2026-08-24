/*
8. FAÇA UMA FUNÇÃO QUE INSIRA UM NÓ À ESQUERDA DE UM NÓ APONTADO POR P EM UMA
LISTA DUPLAMENTE LIGADA.
*/

//biblioteca
#include <iostream>
#include <list> //necessário para lista

using namespace std;

//função
void inserir_esquerda(list<int> &lista, list<int>::iterator p, int x)
{
    lista.insert(p, x);
}

//função auxiliar imprimir
void imprimir(list<int> &lista)
{
    if(lista.empty())
    {
        cout << "[Vazia]" << endl;
        return;
    }
    for(list<int>::iterator p = lista.begin(); p != lista.end(); p++)
    {
        cout << *p << " ";
    }
    cout << endl;
}

//função principal
int main()
{
    list<int> lista;
    int quantidades, numeros;
    int valor_referencia;
    int novo_valor;
    
    cin >> quantidades;

    for(int i = 0; i < quantidades; i++)
    {
        cin >> numeros;
        lista.push_back(numeros);
    }

    imprimir(lista);

    cin >> valor_referencia;

    list<int>::iterator p = lista.end();

    for(list<int>::iterator p1 = lista.begin(); p1 != lista.end(); p1++)
    {
        if(*p1 == valor_referencia)
        {
            p = p1;
            break;
        }
    }
    
    if(p == lista.end())
    {
        return 0;
    }

    cin >> novo_valor;

    inserir_esquerda(lista, p, novo_valor);

    imprimir(lista);

    return 0;
}