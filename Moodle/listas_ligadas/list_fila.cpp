/*
LIST - FILA

FAÇA UM PROGRAMA QUE LEIA 4 VALORES INTEIROS E OS INSIRA NO FINAL DE UMA LISTA LIGADA (VEJA QUE ESTAMOS IMPLEMENTANDO
UMA FILA).

DEPOIS O PROGRAMA DEVE IR REMOVENDO OS ELEMENTOS DA LISTA E MOSTRANDO-OS NA TELA.

ENTRADA: A ENTRADA CONSISTE DE 4 NÚMEROS INTEIROS
SAÍDA: NA SAÍDA, O PROGRAMA DEVE MOSTRAR OS ELEMENTOS INSERIDOS.
*/
//biblioteca
#include <iostream>
#include <list>

using namespace std;

//função principal
int main()
{
    //declaração de variaveis
    int valores;
    list<int> fila;
    list<int>::iterator p_aux;

    //entrada de dados
    //ler 4 valores inteiros e inserir em uma lista
    for (int i = 0; i < 4; i++)
    {
        cin >> valores;
        fila.push_back(valores);
    }
   //desenvolvimento e saída de dados
    for (p_aux = fila.begin(); p_aux != fila.end(); p_aux++)
    {
        cout << *p_aux << " "; //mostrando na tela
    }

    //liberar memória
    while(!fila.empty())
    {
        fila.pop_front(); //removendo da tela
    }
    
    return 0;
}
 