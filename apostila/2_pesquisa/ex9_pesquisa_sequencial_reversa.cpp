/*
9 - FAÇA UMA FUNÇÃO QUE IMPLEMENTE O ALGORITMO DE BUSCA SEQUENCIAL, PARTINDO DO 
FINAL DO VETOR AO INVÉS DO INÍCIO.
*/

//biblioteca
#include <iostream>

using namespace std;

//função busca sequencial reversa
int busca_sequencial_reversa(int vetor[], int tamanho, int x)
{
    for (int i = tamanho - 1; i >= 0; i--)
    {
        //se o valor atual for igual a 'x' a busca deu certo.
        if (vetor[i] == x)
        {
            //returna o indice do número encontrado
            return i;
        }
    }
    
    return -1;
}

//função principal
int main()
{
    //declaração variável
    int vetor[101];
    int tamanho;
    int elemento_procurado;

    //entrada de dados
    cin >> tamanho;
    for (int i = 0; i < tamanho; i++)
    {
        cin >> vetor[i];
    }
    cin >> elemento_procurado;

    //função busca sequencial reversa
    int resultado = busca_sequencial_reversa(vetor, tamanho, elemento_procurado);

    //saída de dados
    if (resultado != -1)
    {
        cout << "Elemento " << elemento_procurado << " encontrado no indice: " << resultado << endl;
    }
    else
    {
        cout << "Elemento nao encontrado no vetor" << endl;
    }

    return 0;
}