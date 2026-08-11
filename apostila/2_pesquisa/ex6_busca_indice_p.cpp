/*
6. SEJA UM VETOR ORDENADO, E O SEGUINTE MÉTODO DE PESQUISA:
- SUPONHA QUE UMA VARIÁVEL P ARMAZENA O ÍNDICE DO ÚLTIMO ELEMENTO ENCONTRADO
- A BUSCA COMEÇA SEMPRE NA POSIÇÃO INDICADA POR P, MAS PODE PROSSEGUIR EM
AMBAS AS DIREÇÕES

ESCREVA UMA FUNÇÃO QUE IMPLEMENTE ESTE MÉTODO DE BUSCA. A SUA FUNÇÃO DEVE
TER O SEGUINTE CABEÇALHO.

INT BUSCA (INT VETOR[], INT TAMANHO, INT P, INT X)

NO CASO DE UMA BUSCA BEM SUCEDIDA, A FUNÇÃO DEVE RETORNAR A POSIÇÃO EM QUE O
ELEMENTO X FOI ENCONTRADO. CASO CONTRÁRIO, ELA DEVE RETORNAR O VALOR -1.
*/
//biblioteca
#include <iostream>

using namespace std;

//função busca
int busca(int vetor[], int tamanho, int p, int x)
{
    //caso base: o elemento procurado está na posição de partida 'p'
    if (vetor[p] == x)
    {
        return p;
    }

    //direção
    if(x > vetor[p])
    {
        //se 'x' for maior, procura na frente
        for(int i = p + 1; i < tamanho; i++)
        {
            //encontrado, retorna o indice atual
            if(vetor[i] == x)
            {
                return i;
            }

            //otimização
            if(vetor[i] > x)
            {
                break;
            }
        }
    }
    
    else
    {
        //se 'x' for menor, procuramos trás
        for(int i = p - 1; i >= 0; i--)
        {
            //encontrada, retorna indice atual
            if(vetor[i] == x)
            {
                return i;
            }

            //otimização
            if(vetor[i] < x)
            {
                break;
            }
        }
    }

    //se não encontrou nada, retorna -1
    return -1;
}

//função principal
int main()
{
    //declaração de variáveis
    int vetor[101];
    int tamanho;
    int p;
    int elemento_procurado;

    //entrada de dados
    cin >> tamanho; //tamanho do vetor
    for(int i = 0; i < tamanho; i++)
    {
        cin >> vetor[i]; //inserir no vetor
    }
    cin >> p; //indice a ser buscado
    cin >> elemento_procurado;

    int resultado = busca(vetor, tamanho, p, elemento_procurado);

    if (resultado != -1)
    {
        cout << "elemento " << elemento_procurado << " encontrado no indice: " << resultado << endl; 
    }
    else
    {
        cout << "elemento nao encontrado" << endl;
    }
    
    return 0;
}