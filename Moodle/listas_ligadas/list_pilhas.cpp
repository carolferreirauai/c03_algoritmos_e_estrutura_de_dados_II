/*
LIST - PILHA

FAÇA UM PROGRAMA QUE LEIA 4 VALORES INTEIROS E OS INSIRA EM UMA PILHA. DEPOIS O PROGRAMA DEVE IR REMOVENDO OS
ELEMENTOS DA PILHA E MOSTRANDO-OS NA TELA.

ENTRADA: A ENTRADA CONSISTE EM 4 NÚMEROS INTEIROS
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
    list<int> pilha; //cria a nossa pilha baseada em lista

    //entrada de dados
    //ler o valores e inseri em uma pilha
    for(int i = 0; i < 4; i++)
    {
        cin >> valores;
        pilha.push_front(valores);
    }

    //desenvolvimento e saída de dados
    //o laço continua rodando enquanto a pilha (! - não) estiver vazia.
    while(!pilha.empty())
    {
        valores = *pilha.begin(); //ler o topo

        cout << valores << " ";

        pilha.pop_front(); //desempilhar
    }
    cout << endl;

    return 0;
}