/*
16. FAÇA UMA FUNÇÃO QUE INSIRA UM NOVO NÓ EM UMA LISTA LIGADA, DE FORMA A MANTÊ-LA
ORDENADA DE FORMA DESCENDENTE. VOCÊ PODE SE BASEAR NA FUNÇÃO PLACE, MOSTRADA 
ANTERIORMENTE. CONSIDERE QUE AS FUNÇÃO PUSH E INSERTAFTER ESTEJAM DISPONÍVEIS.
*/

//biblioteca
#include <iostream>
#include <list> //necessaria para lista

using namespace std;

//função inserir
void inserir(list<int> &lista, int x)
{
    list<int>::iterator p;
    bool inserido = false;

    //percorre a lista procurada
    for(p = lista.begin(); p != lista.end(); p++)
    {
        if(*p < x)
        {
            lista.insert(p, x);
            inserido = true;
            break;
        }
    }

    //varrer e ninguem menor
    if(!inserido)
    {
        lista.push_back(x);
    }
}

//função remover
int remover(list<int> &lista)
{
    if(lista.empty())
    {
        return -1;
    }

    int maior = lista.front();
    lista.pop_front();
    return maior;
}

//função imprimir
int imprimir(list<int> &lista)
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
    list<int> fila;
    int quantidades, numeros;

    //entrada de dados
    cin >> quantidades;

    for(int i = 0; i < quantidades; i++)
    {
        cin >> numeros;

        inserir(fila, numeros);

        imprimir(fila);
    }

    //desenvolvimento e saida de dados
    while(!fila.empty())
    {
        int removido = remover(fila);
        imprimir(fila);
    }
    return 0;
}
