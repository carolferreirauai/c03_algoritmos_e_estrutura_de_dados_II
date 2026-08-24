/*
4. REESCREVA AS FUNÇÕES EMPTY, PUSH, POP, INSERE E REMOVE CONSIDERANDO A PRESENÇA
DE UM NÓ DE CABEÇALHO.
*/
#include <iostream>
#include <list>

using namespace std;

//estrutura para fila
struct fila
{
    list<int> dados;
};

//função de pilha
//verificar se a lista está vazia
bool empty_cabecalho(list<int> &lista)
{
    list<int>::iterator p = lista.begin();
    p++; //avança de posição
    return (p == lista.end());
}

//função push - insere um elemento no início
void push_cabecalho(list<int> &lista, int x)
{
    list<int>::iterator p = lista.begin();
    p++;

    lista.insert(p, x);
}

//função pop - remove o primeiro elementos
int pop_cabecalho(list<int> &lista)
{
    if(empty_cabecalho(lista))
    {
        //se não houver dados reais para remover
        return -1;
    }

    list<int>::iterator p = lista.begin();
    p++;

    int valor = *p; //guarda o numero
    lista.erase(p); //deleta
    return valor;
}

//função de fila com cabeçalho
//função insere - insere um novo dado
void insere_cabecalho(fila &fila, int x)
{
    fila.dados.push_back(x);
}

//função remove - remove o inicio da fila
int remove_cabecalho(fila &fila)
{
    return pop_cabecalho(fila.dados);
}

//função auxiliar
void imprimir_lista(list<int> &lista)
{
    if(empty_cabecalho(lista))
    {
        cout << "[Vazia]" << endl;
        return;
    }

    list<int>::iterator p = lista.begin();
    p++;

    for(; p != lista.end(); p++)
    {
        cout << *p << " ";
    }
    cout << endl;
}

//função principal
int main()
{
    //declaração de variaveis
    list <int> lista;
    lista.push_back(-999);
    int quantidades, numeros;
    
    //entrada de dados
    cin >> quantidades;

    for(int i = 0; i < quantidades; i++)
    {
        cin >> numeros;

        //chamando a função
        push_cabecalho(lista, numeros);
    }

    imprimir_lista(lista);

    return 0;
}