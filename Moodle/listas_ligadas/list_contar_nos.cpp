/*
LIST - CONTAR NÓS

FAÇA UMA FUNÇÃO QUE RECEBA EM SUA ENTRADA UM PONTEIRO PARA UMA LISTA LIGADA, E RETORNE O NÚMERO DE NÓS NESTA LISTA.
ESTA FUNÇÃO DEVE TER O SEGUINTE CABEÇALHO:

INT CONTAR(LIST<INT> LISTA)

DEPOIS, FAÇA UM PROGRAMA QUE VÁ LENDO VÁRIOS NÚMEROS E OS INSERINDO NA LISTA, E EM SEGUIDA MOSTRE O NÚMERO DE NÓS 
DESTA LISTA.

ENTRADA: A ENTRADA CONSISTE VÁRIOS NÚMEROS INTEIROS, QUE DEVEM SER COLOCADOS NA LISTA. O FINAL DA ENTRADA É SINALIZADO PELO 
NÚMERO 0, QUE NÃO DEVE SER INSERIDO NA LISTA.

SAÍDA: NA SAÍDA, O PROGRAMA DEVE MOSTRAR O NÚMERO DE NÓS QUE FORAM INSERIDOS NA LISTA.
*/
//biblioteca
#include <iostream>
#include <list>

using namespace std;

//função contar
int contar(list<int> lista)
{
    list<int>::iterator p; //ponteiro
    int contador = 0;

    for(p = lista.begin(); p != lista.end(); p++)
    {
        contador++;
    }
    return contador;
}

//função principal
int main()
{
    //declaração de váriaveis
    int num;
    list<int> lista;
    int nos;

    //entrada de dados
    //ler vários números e diferente de 0 e inseri-los na lista
    while(cin >> num && num != 0)
    {
        lista.push_back(num);
    }

    //desenvolvimento
    //chamar a função
    nos = contar(lista);

    //saida de dados
    cout << nos << endl;

    //liberar memória
    while(!lista.empty())
    {
        lista.pop_front();
    }
    return 0;
}