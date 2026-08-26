/*
19. FAÇA UMA FUNÇÃO QUE RETORN A MÉDIA DOS ELEMENTOS DE UMA LISTA LIGADA CIRCULAR.
*/
//biblioteca
#include <iostream>
#include <list> //necessaria para lista

using namespace std;

//função media em lista circular
float media(list<int> lista)
{
    if(lista.empty())
    {
        return 0.0;
    }

    float soma = 0;
    int contador = 0;

    list<int>::iterator inicio = lista.begin();
    list<int>::iterator p = inicio;

    //travessia circular
    do
    {
        soma += *p;
        contador++;
        p++;

        if(p == lista.end())
        {
            p = lista.begin();
        }
    } while (p != inicio);

    float media = soma / contador;

    return media;    
}

//função imprimir
void imprimir(list<int> &lista)
{
    if(lista.empty())
    {
        cout << "[Vazia]" << endl;
        return;
    }

    list<int>::iterator p;
    
    for(p = lista.begin(); p != lista.end(); p++)
    {
        cout << "[" << *p << "] -> ";
    }
    cout << endl;
}

int main()
{
    //declaração de variaveis
    list<int> lista;
    int qunatidades, numeros;

    //entrada de dados
    cin >> qunatidades;
    for(int i = 0; i < qunatidades; i++)
    {
        cin >> numeros;
        //insere no final
        lista.push_back(numeros);
    }

    //desenvolvimento
    imprimir(lista);

    //chamar a função
    float resultado = media(lista);

    cout << "Media: " << resultado << endl;

    return 0;
}