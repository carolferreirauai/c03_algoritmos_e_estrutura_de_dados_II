/*
LIST - PROCURAR NA LISTA

FAÇA UMA FUNÇÃO QUE RECEBA EM SUA ENTRADA UM PONTEIRO PARA UMA LISTA LIGADA QUE ARMAZENA NÚMEROS INTEIROS, E UM 
NÚMERO INTEIRO, E RETORNE TRUE SE ESTE ESTIVER NA LISTA, E FALSE CASO CONTRÁRIO. O CABEÇALHO DESTA FUNÇÃO DEVE SER:

BOOL ENCONTRAR(LIST<INT> LISTA, INT X)

DEPOIS, FAÇA UM PROGRAMA QUE VÁ LENDO VÁRIOS NÚMEROS E OS INSERINDO NA LISTA, E EM SEGUIDA LEIA O NÚMERO A SER 
PESQUISADO. ESTE DEVE MOSTRAR A MENSAGEM "ENCONTRADO", SE O NÚMERO A SER PESQUISADO ESTIVER NA LISTA, E "NAO 
ENCONTRADO", CASO CONTRÁRIO

ENTRADA: A ENTRADA CONSISTE DUAS LINHAS.
A PRIMEIRA CONTÉM VÁRIOS NÚMEROS INTEIROS, QUE DEVEM SER COLOCADOS NA LISTA. O FINAL DESTA LINHA É SINALIZADO PELO 
NÚMERO 0, QUE NÃO DEVE SER INSERIDO NA LISTA.
A SEGUNDA LINHA CONTÉM APENAS UM INTEIRO N, QUE É O NÚMERO A SER PESQUISADO NA LISTA.

SAÍDA: NA SAÍDA, O PROGRAMA DEVE MOSTRAR "ENCONTRADO" SE N ESTIVER NA LISTA, E "NÃO ENCONTRADO", CASO CONTRÁRIO
*/
//biblioteca
#include <iostream>
#include <list>

using namespace std;

//função de encontrar
bool encontrar(list<int> lista, int x)
{
    list<int>::iterator p; //ponteiro auxiliar

    //lista ligada que armazena os números
    for (p = lista.begin(); p != lista.end(); p++)
    {
        if(*p == x)
        {
            return true;
        }
    }

    return false;
}

//função principal
int main()
{
    //declaração de variaveis
    int num; //números
    list <int> lista;
    int procurado;
    int busca;

    //entrada de dados 
    //ler os números e inseri-los em lista
    while (cin >> num && num != 0)
    {
        lista.push_back(num); //usado pilha
    }
    
    //ler o procurado
    cin >> procurado;

    //desenvolvimento
    //chamar a função
    busca = encontrar(lista, procurado);

    //saida de dados
    if(busca == true)
    {
        cout << "Encontrado" << endl;
    }
    else
    {
        cout << "Nao encontrado" << endl;
    }
    
    //liberar a memória
    while(!lista.empty())
    {
        lista.pop_front();
    }
    return 0;
}