/*
14. SEJA O SEGUINTE PROGRAMA:

INT MAIN()
{
    NOPTR P,Q;

    P=NEW NO;
    P->INFO=4;
    P->NEXT=NULL;
    Q=NEW NO;
    Q->INFO=3;
    Q->NEXT=P;
    P=NEW NO;
    P->INFO=2;
    P->NEXT=Q;
    Q=NEW NO;
    Q->INFO=7;
    Q->NEXT=P;

    RETURN 0;
}

(A) DESENHE A LISTA GERADA POR ESTE PROGRAMA.
(B) QUAL PONTEIRO ESTÁ APONTANDO PARA O INÍCIO DA LISTA?
(C) ESCREVA UMA SEQUÊNCIA DE COMANDOS PARA LIBERAR A MEMÓRIA ALOCADA.
*/

/*
============ (A) ============
       +------------+       +------------+       +------------+       +-------------+
q -->  |  info: 7   |  p--> |  info: 2   |       |  info: 3   |       |  info: 4    |
       |  next: ------------|  next: ------------|  next: ------------|  next: NULL |
       +------------+       +------------+       +------------+       +-------------+

============ (B) ============
O ponteiro que está apontando para o primeiro nó da lista (elemento 7) é o ponteiro q

*/
// ============ (C) ============
//biblioteca
#include <iostream>
#include <list> //necessário para lista

using namespace std;

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
       cout << "NULL" << endl;
}

//função principal
int main()
{
       list<int> lista;

       lista.push_back(4);
       
       list<int>::iterator p = lista.begin();
       list<int>::iterator q = lista.insert(p, 3);
       
       p = lista.insert(q, 2);
       q = lista.insert(p, 7);
       
       cout << "Ponteiro de inicio (q) aponta para: [" << *q << "]" << endl;
       cout << "Ponteiro p aponta para: [" << *p << "]" << endl;
       
       cout << "Lista gerada pelo programa: ";
       imprimir(lista);
}