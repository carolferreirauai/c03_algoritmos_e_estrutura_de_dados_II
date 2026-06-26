#include <iostream>
#include "busca.h" //incluir a biblioteca

using namespace std;

//função principal
int main()
{
    //declaração de váriaveis
    int valor; //100 elementos
    int vetor[100]; //números inteiros
    int quantidade = 0; //quantidades
    float x; //o valor que busca no final

    //entrada de dados
    cin >> valor; //ler o valores

    //desenvolvimento
    //armazenar em um vetor
    while(valor != -1)
    {
        vetor[quantidade] = valor; //guarda o número no vetor
        quantidade++; //aumentar a quantidade de elemento
        cin >> valor; //ler o próximo número
    }    

    //entrada de dados
    //ler o número x, o número procurado
    cin >> x;

    //desenvolvimento
    //pesquisa sequencial para verificar x entá ou não no vetor.
    int posicao = sequencial(vetor, quantidade, x); //chama a função

    //se encontrar no vetor, o programa indica a posição onde o mesmo foi encontrado.
    //saida de dados
    if (posicao != -1)
    {
        cout << x << " encontrado na posição " << posicao << endl;
    }
    else
    {
        cout << x << " não encontrado" << endl;
    }

    return 0;
}
