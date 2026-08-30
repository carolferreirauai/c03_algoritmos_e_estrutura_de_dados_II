/*
27. SEJAM LISTA1 E LISTA2, DUAS LISTAS LIGADAS. ESTA DUAS LISTAS POSSUEM UM NÓ
DE CABEÇALHO CUJO CAMPO INFO CONTÉM O NÚMERO DE ELEMENTOS EM CADA LISTA.
FAÇA UMA FUNÇÃO QUE GERE UMA TERCEIRA LISTA LISTA3, RESULTANTE DA CONCATENAÇÃO
DE LISTA1 COM LISTA2. NÃO SE ESQUEÇA DE ATUALIZAR O CAMPO INFO DO NÓ DE
CABEÇALHO DE LISTA3.
*/

//biblioteca
#include <iostream>
#include <list> //necessarios para lista

using namespace std;

void concatenacao(list<int> &lista1, list<int> &lista2, list<int> &lista3)
{
    lista3.clear();

    //recupera a quantidade de elementos guardada no primeiro elemento
    int tamanho1 = lista1.empty() ? 0 : lista1.front();
    int tamanho2 = lista2.empty() ? 0 : lista2.front();

    //insere lista 3 com a soma dos tamanhos
    lista3.push_back(tamanho1 + tamanho2);

    //copia os elementos reais de lista1
    if(lista1.empty())
    {
        list<int>::iterator p = lista1.begin();
        p++;

        for(; p != lista1.end(); p++)
        {
            lista3.push_back(*p);
        }
    }

    //copia os elementos reais de lista2
    if(!lista2.empty())
    {
        list<int>::iterator p = lista2.begin();
        p++;
        for(; p != lista2.end(); p++)
        {
            lista3.push_back(*p);
        }
    }
}

//função auxiliar para imprimir
void imprimir(list<int> &lista)
{
    if(lista.empty())
    {
        cout << "[Vazia]" << endl;
        return;
    }

    list<int>::iterator p = lista.begin();

    //mostra o cabeçalho
    cout << "Quantidades: " << *p << " Elementos: [ ";
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
    //declaração de variaveis
    list<int> lista1, lista2, lista3;
    int quantidade1, quantidade2, numero;

    //inicializar os cabeçalhos com zero
    lista1.push_back(0);
    lista2.push_back(0);

    //entrada de dados
    //lista1
    cout << "Quantidades (Lista1): ";
    cin >> quantidade1;

    if(quantidade1 > 0)
    {
        for (int i = 0; i < quantidade1; i++)
        {
            cin >> ws;
            cin >> numero;
            lista1.push_back(numero);
        }
        lista1.front() = quantidade1; //atualizar
    }

    //lista2
    cout << "Quantidades (Lista2): ";
    cin >> quantidade2;

    if(quantidade2 > 0)
    {
        for (int i = 0; i < quantidade2; i++)
        {
            cin >> ws;
            cin >> numero;
            lista2.push_back(numero);
        }
        lista2.front() = quantidade2; //atualizar
    }
    
    //desenvolvimento
    //exibe listas originais
    cout << "Lista1: ";
    imprimir(lista1);

    cout << "Lista2: ";
    imprimir(lista2);

    //chamar a função 
    concatenacao(lista1, lista2, lista3);

    //saida de dados
    //exibe a lista concatenada
    cout << "Lista 3: ";
    imprimir(lista3);

    return 0;
}