/*
6. ESCREVA UM ALGORITMOS QUE RETORNE UM PONTEIRO PARA UM NÓ CONTENDO O ELEMENTO
X NUMA LISTA COM UM NÓ DE CABEÇALHO. O CAMPO INFO DO CABEÇALHO DEVERÁ CONTER 
O PONTEIRO QUE ATRAVESSA A LISTA.
*/

//biblioteca
#include <iostream>
#include <list> //necessaria para lista

using namespace std;

//função inicialização - criar a lista
void inicializar(list<int> &lista)
{
    lista.clear();
    lista.push_back(0); //primeira posição
}

//função busca - retornar iterator
list<int>::iterator buscar(list<int> &lista, int x)
{
    //se a lista só tem cabeçalho, está vazia
    if(lista.size() <= 1)
    {
        lista.front() = 0;
        return lista.end();
    }

    lista.front() = 1;

    //criamos o navegador
    list<int>::iterator p = lista.begin();
    p++; //pula o cabeçalho para o primeiro elemento

    while(p != lista.end())
    {
        //encontramos o valor x
        if(*p == x)
        {
            return p;
        }
        
        p++;
        lista.front()++;
    }

    lista.front() = 0;
    return lista.end();
}

//função auxiliar
void imprimir(list<int> &lista)
{
    list<int>::iterator p = lista.begin();
    cout << "Cabecalho (Ponteiro de busca: " << *p << ") -> Elementos reais: [ ";
    p++;
    for(; p != lista.end(); p++)
    {
        cout << *p << " ";
    }
    cout << "]" << endl;
}

//função principal
int main()
{
    //declaração de váriaveis
    list<int> lista;
    inicializar(lista);
    int quantidades, numeros;
    int elemento_procurado;

    cin >> quantidades;

    for(int i = 0; i < quantidades; i++)
    {
        cin >> numeros;
        lista.push_back(numeros); //insere no final
    }

    imprimir(lista);

    cin >> elemento_procurado;

    list<int>::iterator resultado = buscar(lista, elemento_procurado);

    imprimir(lista);

    if(resultado != lista.end())
    {
        cout << "Elemento " << elemento_procurado << " encontrado na posicao real: " << lista.front() << endl;
    }
    else
    {
        cout << "Elemento nao encontradp na lista" << endl;
    }

    return 0;
}