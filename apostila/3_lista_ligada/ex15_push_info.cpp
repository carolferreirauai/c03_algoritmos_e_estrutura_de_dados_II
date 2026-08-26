/*
15. REIMPLEMENTE A FUNÇÃO PUSH PARA UMA LISTA CIRCULAR COM NÓ DE CABEÇALHO, CUJO
CAMPO INFO CONTÉM O NÚMERODE NÓS ATUALMENTE NA LISTA.

CONDIÇÕES DE PROJETO:
- ASSUMA QUE A LISTA JÁ INICIALMENTE CRIADO COM O NÓ DE CABEÇALHO.
- O PONTEIRO EXTERNO DEVE APONTAR PARA O NÓ DE CABEÇALHO.
*/
//biblioteca
#include <iostream>
#include <list> //necessario para a lista

using namespace std;

//função inicialização
void inicializar(list<int> &lista)
{
    lista.clear();
    lista.push_back(0);
}

//função push
void push(list<int> &lista, int x)
{
    list<int>::iterator p = lista.begin();
    p++; //avança pro próximo

    lista.insert(p, x);
    lista.front()++; //soma 1 no contador
}

//função imprimir
void imprimir(list<int> &lista)
{
    int tamanho_real = lista.front();

    if(tamanho_real == 0)
    {
        cout << "[Vazia]" << endl;
        return;
    }
    list<int>::iterator p = lista.begin();

    cout << *p << endl;
    p++; //avança

    for(int i = 0; i < tamanho_real; i++)
    {
        cout << *p << " ";
        p++;

        if(p == lista.end())
        {
            p = lista.begin();
            p++;
        }
    }
    cout << endl;
}

//função principal
int main()
{
    //declaracao de variaveis
    list<int> lista;
    int quantidades, numeros;
    //chamar a função
    inicializar(lista);
    
    //entrada de dados
    cin >> quantidades;

    for(int i = 0; i < quantidades; i++)
    {
        cin >> numeros;

        //atualizar
        push(lista, numeros);
    }

    //saida de dados
    imprimir(lista);

    return 0;
}