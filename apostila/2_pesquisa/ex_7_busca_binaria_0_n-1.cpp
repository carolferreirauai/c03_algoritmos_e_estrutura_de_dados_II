/*
7. MODIFIQUE O ALGORITMOS DE BUSCA BINÁRIA DE MODO QUE, NO CASO DE UMA BUSCA 
MAL-SUCEDIDA, ELE RETORNE O ÍNDICE I TAL QUE O ELEMENTO PROCURADO ESTEJA ENTRE I E I + 1.
SE O ELEMENTO PROCURADO FOR MENOR QUE O MENOR ELEMENTO DA LISTA, O ALGORITMO
DEVE RETORNAR -1, E SE FOR MAIO QUE O MAIOR ELEMENTO DA LISTA O ALGORITMO DEVE 
RETORNAR N. OBSERVE QUE A LISTA TEM N ELEMENTOS: [0, N, -1]
*/

//biblioteca
#include <iostream>

using namespace std;

//busca binária em vetor ordenado
int binaria_modificada (int vetor[], int tamanho, int x) //vetor ordenado onde a buaca será feita, quantidade de elementos do vetor, valor a ser procurado
{
    bool achou = false; //controle: indica se o elemento foi encontrado
    int baixo = 0, meio, alto = tamanho - 1;//limite inferior do intervalo de busca (primeiro índice), limite superior do intervalo de busca (último índice)

    //repete enquanto o intervalo for válido e o elemento não foi achado ainda
    while((baixo <= alto) && (achou == false))
    {
        meio = (baixo + alto) / 2; //índice do elemento central do intervalo atual

        if (x < vetor[meio]) //x está na metade esquerda do intervalo
        {
            alto = meio - 1; //descarta a metade direta, nova busca vai até meio - 1
        }
        else
        {
            if (x > vetor[meio]) //x está metade direita do intervalo
            {
                baixo = meio + 1; //descarta a metade esquerda, nova busca com meio + 1
            }
            else //x == vetor[meio]: elemento encontrado
            {
                achou = true;
            }
        }
    }

    /* ==================== MODIFICAÇÃO SOLICITADA ===================== */
    if (achou == true)
    {
        return meio; //pesquisa bem-sucedida
    }
    else
    {
        //tratamento para valores menores que o menor vetor
        if (alto < 0)
        {
            return -1;
        }
        //tratamento para valores maiores que maior do vetor
        else if (baixo >= tamanho)
        {
            return tamanho; //"N"
        }
        //o valor ficaria entre alto e baixo
        else
        {
            return alto;
        }
    }
}

//função principal
int main()
{
    int vetor[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int tamanho = 8;

    //caso 1 - elemento encontrado - esperar: 3
    cout << binaria_modificada(vetor, tamanho, 3) << "\n";

    //caso 2 - entre dois elementos - esperar: 2
    cout << binaria_modificada(vetor, tamanho, 10) << "\n";

    //caso 3 - menor que tudo: -1
    cout << binaria_modificada(vetor, tamanho, 0) << "\n";

    //caso 4 - maior que tudo: 8
    cout << binaria_modificada(vetor, tamanho, 9) << "\n";

    return 0;
}