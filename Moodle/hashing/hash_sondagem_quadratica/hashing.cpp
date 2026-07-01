/*
HASH - SONDAGEM QUADRÁTICA

USANDO A FUNÇÃO HASH_AUX(), FAÇA UMA FUNÇÃO QUE IMPLEMENTE A SONDAGEM QUADRÁTICA, DADA POR:
H(K, I, M) = (H'(K,M) + C1_I + C2_I^2) MOD M

ESTA FUNÇÃO DEVE TER SEGUINTE CABEÇALHO:
INT HASH2(INT K, INT I, INT M, INT C1, INT C2)

ONDE K É A CHAVE A SER INSERIDA, M É O TAMANHO DA TABELA HASH, E O I É O NÚMERO DA TENTIVA.

DEPOIS FAÇA UM PROGRAMA QUE LEIA OS VALOR DE K, M, C1 E C2 E FAÇA USO DESTA FUNÇÃO PARA RETORNAR AS
POSIÇÕES DA SONDAGEM QUADRÁTICA.

ENTRADA: A ENTRADA CONSISTE UMA ÚNICA LINHA COM 4 INTEIROS, CORRESPONDENTES AOS VALORES DE K, M, C1 E C2,
RESPECTIVAMENTE.

SAÍDA: NA SAÍDA, O PROGRAMA DEVE MOSTRAR TODAS AS POSIÇÕES DA SONDAGEM QUADRÁTICA PARA ENTRADAS DADAS.
*/
//biblioteca
#include <iostream>
#include <cmath>
#include "hashing.h"

using namespace std;

//função hash_aux
int hash_aux(int k, int m)
{
    //metodo da divisão
    int h = k % m;

    //número negativo
    if (h < 0)
    {
        return h += m;
    }
    else
    {
        return h;
    }
}

//função hash - sondagem quadrática
int hash2(int k, int i, int m, int c1, int c2)
{
    return (hash_aux(k, m) + c1 * i + c2 * i * i) % m;
}

//função principal
int main()
{
    //declaração de váriaveis
    int k, m, c1, c2;

    //entrada de dados
    //ler as 4 variáveis por linhas
    while(cin >> k >> m >> c1 >> c2)
    {
        //desenvolvimento
        for(int i = 0; i < m; i++)
        {
            //chama a função
            int resultado = hash2(k, i, m, c1, c2);

            //saída de dados
            //imprime a posição
            cout << resultado << " ";
        }

        cout << endl;
    }
    return 0;
}