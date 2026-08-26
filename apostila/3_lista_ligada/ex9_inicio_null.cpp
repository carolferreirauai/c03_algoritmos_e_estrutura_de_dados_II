/*
9. DADA A FILA ABAIXO:
Q -> INICIO --> [4] -> [4] -> [2] Q -> FIM [7] -> NULL
DESENHE A NOVA CONFIGURAÇÃO DA MESMA DEPOIS DE EXECUTADA A INSTRUÇÃO
XYZ(Q, 3);
A FUNÇÃO XYZ É MOSTRADA ABAIXO:
VOID XYZ(FILA &PQ, INT X)
{
    NOPTR P;

    P = NEW NO;
    P -> INFO = X;
    P -> NEXT = NULL;
    
    IF(PQ -> FIM == NULL)
        PQ -> INICIO = P;
    ELSE
        (PQ -> FIM) -> NEXT = P;
    PQ -> FIM = P;
}
A ESTRUTURA FILA É MOSTRADA ABAIXO:
STRUCT FILA
{
    NOPTR INICIO;
    NOPTR FIM;
};
*/

//biblioteca
#include <iostream>
#include <list> //necessária para lista

using namespace std;

void xyz(list<int> &fila, int x)
{
    fila.push_back(x); //insere
}

//função auxiliar para imprimir
void imprimir(list<int> &fila)
{
    if (fila.empty())
    {
        cout << "[Vazia]" << endl;
        return;
    }

    list<int>::iterator p;
    for(p = fila.begin(); p != fila.end(); p++)
    {
        cout << "[" << *p << "] -> ";
    } 

    cout << "NULL" << endl;
}

//função principal
int main()
{
    list<int> fila;

    //criando configuração
    fila.push_back(4);
    fila.push_back(2);
    fila.push_back(7);

    cout << "q->inicio aponta para o primeiro elemento [" << fila.front() << "]" << endl;
    cout << "q->fim aponta para o novo ultimo elemento [" << fila.back() << "]" << endl;
    cout << "Fila final: ";
    imprimir(fila);

    cout << "Executando: xyz(q, 3)..." << endl;
    xyz(fila, 3);

    cout << "q->inicio aponta para o primeiro elemento [" << fila.front() << "]" << endl;
    cout << "q->fim aponta para o novo ultimo elemento [" << fila.back() << "]" << endl;
    cout << "Fila final: ";
    imprimir(fila);

    return 0;
}