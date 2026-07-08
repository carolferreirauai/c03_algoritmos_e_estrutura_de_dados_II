/*
LIST - UNIÃO

FAÇA UM PROGRAMA QUE LEIA OS DADOS DE DUAS LISTAS LIGADAS CUJOS ELEMENTOS ESTÃO EM ORDEM CRESCENTE, CRIE E MOSTRE 
UMA TERCEIRA LISTA LIGADA, FORMADA PELA UNIÃO DOS ELEMENTOS DAS DUAS LISTAS ORIGINAIS, TAMBÉM ORDENADA EM ORDEM 
CRESCENTE.

ENTRADA: A ENTRADA CONSISTE DUAS LINHAS:
- A PRIMEIRA CONTÉM VÁRIOS NÚMEROS INTEIROS, QUE DEVEM SER COLOCADOS NA LISTA 1. O FINAL DESTA LINHA É SINALIZADO PELO
NÚMERO 0, QUE NÃO DEVE SER INSERIDO NA LISTA 1.
- A SEGUNDA TAMBÉM CONTÉM VÁRIOS NÚMEROS INTEIROS, QUE DEVEM SER COLOCADOS NA LISTA 2. O FINAL DESTA LINHA É 
SINALIZADO PELO NÚMERO 0, QUE NÃO DEVE SER INSERIDO NA LISTA 2.

SAÍDA: NA SAÍDA, O PROGRAMA DEVE MOSTRAR OS ELEMENTOS DA LISTA 3, FORMADA PELA UNIÃO DOS ELEMENTOS DAS DUAS LISTAS, 
ORDENADOS EM ORDEM CRESCENTE.
*/

//biblioteca
#include <iostream>
#include <list>

using namespace std;

//função principal
int main()
{
    //declaração de variáveis
    list<int> lista1;
    list<int> lista2;
    list<int> uniao;
    int num;
    list<int>::iterator p1;
    list<int>::iterator p2;

    //entrada de dados
    //da lista 1
    //ler os números e diferente de 0
    while(cin >> num && num != 0)
    {
        lista1.push_back(num); //inserir na lista
    }

    //da lista 2
    while(cin >> num && num != 0)
    {
        lista2.push_back(num); //inserir na lista
    }

    //desenvolvimentos
    //apontando o começo de cada listas
    p1 = lista1.begin();
    p2 = lista2.begin();

    //varremos ambas as listas
    while (p1 != lista1.end() && p2 != lista2.end())
    {
        //se p1 for menor que p2, o menor entra na união
        if(*p1 < *p2)
        {
            uniao.push_back(*p1);
            p1++; //avança apenas na lista 1
        }

        //se p2 for menor que p1, o menor entra na união
        else if(*p2 < *p1)
        {
            uniao.push_back(*p2);
            p2++; //avança apenas na lista 2
        }
        else
        {
            //se forem iguais, o número entra na união apenas uma vez
            uniao.push_back(*p1);
            p1++; //avança na lista 1
            p2++; //avança na lista 2
        }
    }

    //caso a lista 2 tenha acabado primeiro, guardado apenas a lista 1
    while(p1 != lista1.end())
    {
        uniao.push_back(*p1);
        p1++;
    }

    //caso a lista 1 tenha acabado primeiro, guardado apenas a lista 2
    while(p2 != lista2.end())
    {
        uniao.push_back(*p2);
        p2++;
    }

    //saida de dados
    while(!uniao.empty())
    {
        cout << *uniao.begin() << " ";
        uniao.pop_front();
    }
    cout << endl;

    //liberar a memória
    while(!lista1.empty())
    {
        lista1.pop_front();
    }
    while(!lista2.empty())
    {
        lista2.pop_front();
    }
    while(!uniao.empty())
    {
        uniao.pop_front();
    }

    return 0;
}