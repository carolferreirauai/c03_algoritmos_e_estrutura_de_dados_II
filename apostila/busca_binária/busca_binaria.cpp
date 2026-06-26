//biblioteca
#include <iostream>

using namespace std;

//busca binária em vetor ordenado
int binaria (int vetor[], int tamanho, int x) //vetor ordenado onde a buaca será feita, quantidade de elementos do vetor, valor a ser procurado
{
    bool achou;
    int baixo, meio, alto;

    baixo = 0; //limite inferior do intervalo de busca (primeiro índice)
    alto = tamanho - 1; //limite superior do intervalo de busca (último índice)
    achou = false; //controle: indica se o elemento foi encontrado

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
    if (achou == true)
    {
        return meio; //retorna o índice onde x foi encontrado
    }
    else
    {
        return -1; //x não existe no vetor
    }
}