/*
LIST - SOMA DOS NÓS

FAÇA UMA FUNÇÃO QUE RECEBA EM SUA ENTRADA UM PONTEIRO PARA UMA LISTA LIGADA, E RETORNE A SOMA DOS NÓS NESTA LISTA.
O CABEÇALHO DESTA FUNÇÃO DEVE SER:

INT SOMA(LIST<INT> LISTA)

DEPOIS, FAÇA UM PROGRAMA QUE VÁ LENDO VÁRIOS NÚMEROS E OS INSERINDO NA LISTA, E EM SEGUIDA MOSTRE A SOMA DOS NÓS 
DESTA LISTA.

ENTRADA: A ENTRADA CONSISTE VÁRIOS NÚMEROS INTEIROS, QUE DEVEM SER COLOCADOS NA LISTA. O FINAL DA ENTRADA É SINALIZADO 
PELO NÚMERO 0, QUE NÃO DEVE SER INSERIDO NA LISTA.

SAÍDA: NA SAÍDA, O PROGRAMA DEVE MOSTRAR A SOMA DOS NÓS QUE FORAM INSERIDOS NA LISTA.
*/
//biblioteca
#include <iostream>
#include <list>

using namespace std;

//função soma
int soma(list<int> lista)
{
    list<int>::iterator p; //ponteiro
    int soma = 0;

    //lista ligada - varre do inicio até o fim
    for (p = lista.begin(); p != lista.end(); p++)
    {
        //soma da lista
        soma += *p;
    }
    return soma;
}

//função principal
int main()
{
    //declaração de variáveis
    int num;
    list<int> lista;
    int total;

    //entrada de dados
    //ler o vários números e diferente de 0 e inseri-los em uma lista
    while (cin >> num && num != 0)
    {
        lista.push_back(num);
    }

    //desenvolvimento
    total = soma(lista);

    //saída de dados
    cout << total << endl;

    //liberar a memória
    while(!lista.empty())
    {
        lista.pop_front();
    }
    return 0;
}