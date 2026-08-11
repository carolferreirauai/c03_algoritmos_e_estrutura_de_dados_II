/*
11. REIMPLEMENTE OS ALGORITMOS DESTA SEÇÃO PARA ORDENAR LISTAS LIGADAS AO INVÉS DE 
VETORES.
*/
//biblioteca
#include <iostream>
#include <list>

using namespace std;

struct no
{
    int info;
    no *next; //ponteiro para o próximo nó
};

typedef no* noptr; //noptr é um "ponteiro para no"

//bubble sort
void bubblesort_lista(noptr lista)
{
    //se a lista estiver vazia ou tiver só 1 nó, já está ordenada
    if(lista == NULL || lista -> next == NULL)
        return;
        
    bool troca = true; //controla se houve alguma alteração na verredura
    noptr p; //ponteiro
    int trab; //variavel aux para troca

    while(troca)
    {
        troca = false; //inicialmente que não haverá trocas
        p = lista; //o navegador volta para o ínicio da lista

        //percorrer a lista
        while(p -> next != NULL)
        {
            if(p -> info > p -> next -> info)
            {
                //troca apenas a informação
                trab = p -> info;
                p -> info = p -> next -> info;
                p -> next -> info = trab;

                //lista ainda estava desordenada
                troca = true;
            }
            //avança para o próximo nó da lista
            p = p -> next;
        }
         
    }
}

//selção direta
void selecaodireta_lista(noptr lista)
{
    noptr i, j, menor;
    int aux;

    //laço para percorrer a lista do ponteiro 'i'
    for (i = lista; i != NULL; i = i -> next)
    {
        menor = i; //iniciar o menor

        //laço para percorrer a lista do ponteiro 'j'
        for(j = i -> next; j != NULL; j = j -> next)
        {
            //se achar um número menor que o ponteiro
            if(j -> info < menor -> info)
            {
                menor = j;
            }
        }

        //se achar um número menor mais pra frente, faz a troca
        if(menor != i)
        {
            aux = i -> info;
            i -> info = menor -> info;
            menor -> info = aux;
        }
    }
}

/*
Por que não adaptar o Quick Sort ou o Shell Sort?
Embora seja teoricamente possível, o Quick Sort avança ponteiros da esquerda para a direita 
(esq++) e da direita para a esquerda (dir--) até que eles se cruzem. Como as listas 
ligadas simples que estudamos só possuem um ponteiro next (indo só pra frente), não 
conseguimos voltar caminhando para trás (dir--).
O mesmo vale para o Shell Sort, que exige saltos matemáticos para a frente e para trás entre 
os blocos intercalados.
Por isso, na prática acadêmica e de mercado, quando somos forçados a ordenar uma Lista 
Ligada Simples trocando informações, Bolha e Seleção (que caminham sempre linearmente 
para a frente) são os métodos perfeitos e esperados pelo professor!
*/