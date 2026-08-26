/*
13. FUNÇÃO QUE RETORNA O NÚMERO DE ELEMENTOS MAIORES QUE X NA LISTA
*/

//biblioteca
#include <iostream>
#include <list> //necessário para lista

using namespace std;

//função contador - para contar o maiores
int contador(list <int> &lista, int x)
{
    int contador = 0;
    list<int>::iterator p;

    //varre a lista
    for (p = lista.begin(); p != lista.end(); p++)
    {
        if(*p > x)
        {
            contador++;
        }
    }

    return contador;
}

//função imprimir
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
    int quantidades, numeros, x;

    //entrada de dados
    cin >> quantidades;
    for (int i = 0; i < quantidades; i++)
    {
        cin >> numeros;
        //insere no final da lista
        lista.push_back(numeros);
    }

    cout << "Lista digitada: ";
    imprimir(lista);

    //comparação
    cin >> x;

    //chamar a função e guardar o resultado
    int total = contador(lista, x);

    //saida de dados
    cout << total << endl;

    return 0;
}
