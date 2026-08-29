/*
25. FAÇA UMA FUNÇÃO QUE TOME UM PONTEIRO PARA UMA LISTA LIGADA E INVERTA AS POSIÇÕES
DO PRIMEIRO E ÚLTIMO NÓS DA MESMA. (DICA: NÃO PRECISA INVERTER AS POSIÇÕES,
APENAS OS CONTEÚDOS DOS CAMPOS INFO)

VOID INVERTE(NOPTR &LISTA)
*/
//biblioteca
#include <iostream>
#include <list> //necessários para lista

using namespace std;

//função inverter
void inverte(list<int> &lista)
{
    if(lista.size() < 2)
    {
        return;
    }

    list<int>::iterator primeiro = lista.begin();
    list<int>::iterator ultimo = lista.end();
    ultimo--;
    int auxiliar = *primeiro;
    *primeiro = *ultimo;
    *ultimo = auxiliar;
}

//função auxiliar para imprimir
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
    int quantidades, numero;

    //entrada de dados
    cout << "Quantidades: ";
    cin >> quantidades;

    for (int i = 0; i < quantidades; i++)
    {
        cin >> numero;
        lista.push_back(numero); //insere no fim da lista
    }
    
    //desenvolvimento
    imprimir(lista);
    //chamar a função
    inverte(lista);

    //saida de dados
    imprimir(lista);

    return 0;
}
