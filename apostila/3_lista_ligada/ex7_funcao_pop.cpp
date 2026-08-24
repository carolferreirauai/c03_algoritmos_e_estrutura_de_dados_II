/*
7. FAÇA UM PROGRAMA QUE LEIA VÁRIOS DADOS E OS ARMAZENE EM UMA PILHA IMPLEMENTADA
COMO UMA LISTA CIRCULAR, USANDO A FUNÇÃO PUSH. DEPOIS, OS DADOS DEVEM SER
DESEMPILHADOS USANDO A FUNÇÃO POP. APRESENTE ESTES RESULTADOS NA TELA PARA QUE
POSSAM SER CONFERIDOS.
*/

#include <iostream>
#include <list> //necessária para lista

using namespace std;

//função push
void push_circular(list<int> &lista, int x)
{
    lista.push_front(x); //insere no início
}

//função pop - remove o elemento do topo (frente da lista) e devolve o valor
int pop_circular(list<int> &lista)
{
    if (lista.empty())
    {
        //se a lista tiver vazia
        return -1;
    }
    
    int topo = lista.front(); //pega o elemento do topo
    lista.pop_front();        //remove o elemento da lista
    return topo;
}

//função auxiliar e circular - varre a lista e, ao chegar no fim, volta para o início para provar a circularidade
void imprimir_circular(list<int> &lista)
{
    if (lista.empty())
    {
        cout << "[Vazia]" << endl;
        return;
    }

    list<int>::iterator p = lista.begin();
    int tamanho = lista.size();

    cout << "[ ";
    for (int i = 0; i < tamanho + 1; i++)
    {
        cout << *p << " ";
        p++;
        if (p == lista.end())
        {
            p = lista.begin(); 
        }
    }
    cout << "(volta ao inicio) ]" << endl;
}

//função principal
int main()
{
    //declaração de variáveis
    list<int> pilha;
    int quantidades, numeros;

    //entrada de dados
    cin >> quantidades;

    cout << "Digite os " << quantidades << " numeros:" << endl;
    for(int i = 0; i < quantidades; i++)
    {
        cin >> numeros;
        push_circular(pilha, numeros); // Empilha os números
    }

    //saída demonstrando a lista circular
    imprimir_circular(pilha);

    //desempilhando os elementos
    while(!pilha.empty())
    {
        int removido = pop_circular(pilha);
        cout << "Removido: " << removido << " | Pilha restante: ";
        imprimir_circular(pilha);
    }

    return 0;
}