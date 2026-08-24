/*
3. ESCREVA ALGORITMOS PARA INSERIR E REMOVER DADOS EM UMA FILA DE PRIORIDADE ASCENDENTE
PARA OS SEGUINTES CASOS:

(A) LISTA ORDENADA.
(B) LISTA DESORDENADA.
*/

//biblioteca
#include <iostream>
#include <list> //necessário para listas

using namespace std;

//caso a: a fila de prioridade em lista ordenada
//insere mantendo a ordem crescente (custa: o(n))
void inserir_ordenado(list<int> &lista, int x)
{
    list<int>::iterator p;
    bool inserido = false;

    //percorre a lisyta procurado onde encaixar o novo elemento
    for (p = lista.begin(); p != lista.end(); p++)
    {
        if (*p > x)
        {
            lista.insert(p, x);
            inserido = true;
            break;
        }
    }

    //se varreu toda a lista e ningém era maior, insere no final
    if(!inserido)
    {
        lista.push_back(x);
    }
}

//remove o menor elemento.
int remover_ordenado(list<int> &lista)
{
    if (lista.empty())
    {
        //se a lista tiver vazi
        return -1;
    }

    int menor = lista.front(); //pega o primeiro valor
    lista.pop_front(); //remove
    return menor;
}


//caso b: fila de prioridade em lista desordenada
//insere rapidamente no final da lista
void inserir_desordenado(list<int> &lista, int x)
{
    lista.push_back(x);
}

//procurar e remover o menor
int remover_desordenado(list<int> &lista)
{
    if(lista.empty())
    {
        //se estiver vazia
        return -1;
    }

    list<int>::iterator p;
    list<int>::iterator p_menor = lista.begin(); //chuta que é o menor
    int menor = *p_menor;

    //varrer toda a lista
    for(p = lista.begin(); p != lista.end(); p++)
    {
        if(*p < menor)
        {
            menor = *p;
            p_menor = p;
        }
    }

    lista.erase(p_menor); //remover
    return menor;
}

//função auxiliar
void imprimir_lista(list<int> lista)
{
    if (lista.empty())
    {
        cout << "[Vazia]";
    }
    else
    {
        for(list<int>::iterator p = lista.begin(); p != lista.end(); p++)
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
    list<int> fila_ordenada;
    list<int> fila_desordenada;
    int vetor[100];
    int quantidades;

    //entrada de dados
    cin >> quantidades;

    //ler numeros e armazenar no vetor
    for(int i = 0; i < quantidades; i++)
    {
        cin >> vetor[i];
    }

    //desemvolvimento
    //fila ordenada
    for(int i = 0; i < quantidades; i++)
    {
        cout << "Inserido: " << vetor[i] << " -> Estado de lista: ";
        inserir_ordenado(fila_ordenada, vetor[i]);
        imprimir_lista(fila_ordenada);
    }

    cout << "removendo o elemento: " << endl;
    while(!fila_ordenada.empty())
    {
        int removido = remover_ordenado(fila_ordenada);
        cout << "removido: " << removido << " | Fila restante: ";
        imprimir_lista(fila_ordenada);
    }
    cout << endl;

    //fila desordenada
    for (int i = 0; i < quantidades; i++)
    {
        cout << "Inserido: " << vetor[i] << " -> Estado de lista: ";
        inserir_desordenado(fila_desordenada, vetor[i]);
        imprimir_lista(fila_desordenada);
    }

    cout << "removendo elementos: " << endl;
    while(!fila_desordenada.empty())
    {
        int removido = remover_desordenado(fila_desordenada);
        cout << "removido: " << removido << " | Fila restante: ";
        imprimir_lista(fila_desordenada);
    }

    return 0;
}