/*
18. FAÇA UMA FUNÇÃO QUE TOME UM PONTEIRO PARA UMA LISTA LIGADA E RETORNE A MÉDIA
DOS ELEMENTOS DESTA LISTA. A SUA FUNÇÃO DEVE TER O SEGUINTE CABEÇALHO:
FLOAT MEDIA(NOPTR LISTA)
*/
//biblioteca
#include <iostream>
#include <list> //necessaria para a lista

using namespace std;

//media
float media(list<int> &lista)
{
    if(lista.empty())
    {
        return 0.0;
    }

    float soma = 0;
    int contador = 0;
    list<int>::iterator p;

    //percorre a lista
    for(p = lista.begin(); p != lista.end(); p++)
    {
        //soma os valores
        soma += *p;

        //contar os elementos
        contador++;
    }
    
    float media = (soma) / (contador);

    return media;
}

//função imprimir
void imprimir(list<int> &lista)
{
    if(lista.empty())
    {
        cout << "[Vazia]";
    }
    else
    {
        list<int>::iterator p;
        for(p = lista.begin(); p != lista.end(); p++)
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
    list<int> lista;
    int quantidades, numeros;

    //entrada de dados
    cin >> quantidades;
    for(int i = 0; i < quantidades; i++)
    {
        cin >> numeros;
        //insere no final
        lista.push_back(numeros);
    }

    imprimir(lista);

    //calcular
    float resultado = media(lista);

    cout << "Media: " << resultado << endl;

    return 0;
}