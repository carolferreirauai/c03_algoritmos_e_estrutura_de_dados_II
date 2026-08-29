/*
26. FAÇA UMA FUNÇÃO QUE TOME UM PONTEIRO PARA LISTA LIGADA E DUPLIQUE TODOS OS
NÓS CUJO CAMPO INFO SEJA PAR. VOCÊ PODE CONSIDERAR QUE AS FUNÇÕES PUSH(LISTA, X)
E INSERTAFTER(P, X) JÁ ESTEJAM IMPLEMENTADAS.

VOID DUPLICAPAR(NOPTR &LISTA)
*/

//biblioca
#include <iostream>
#include <list> //necessario para lista

using namespace std;

//função duplica par
void duplicapar(list<int> &lista)
{
    list<int>::iterator p = lista.begin();

    while(p != lista.end())
    {
        //verifica se o elemento é par
        if(*p % 2 == 0)
        {
            list<int>::iterator proximo = p;
            proximo++;

            //insere uma cópia
            lista.insert(proximo, *p);
            p++;
        }
        p++;
    }
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
    //declaração variaveis
    list<int> lista;
    int quantidades, numeros;

    //entrada de dados
    cout << "Quantidades: ";
    cin >> quantidades;

    for(int i = 0; i < quantidades; i++)
    {
        cin >> numeros;
        lista.push_back(numeros); //insere no final
    }

    //desenvolvimento
    imprimir(lista);
    //chamar a função
    duplicapar(lista);

    //saida de dados
    imprimir(lista);

    return 0;
}