/*
REC - POTÊNCIA

PODEMOS CALCULAR A^N PARA N > 0, USANDO A SEGUINTE EXPRESSÃO:

A^N = 1,         N = 0
      A x A^N-1, N > 0

FAÇA UM PROGRAMA QUE LEIA DOIS NÚMEROS INTEIROS A E N, E RETORNE O VALOR DE A^N.
O CÁLCULO DEVE SER FEITO USANDO UMA FUNÇÃO RECURSIVA.

ENTRADA: A ENTRADA CONSISTE DE DOIS NÚMEROA INTEIROS A E N.

SAÍDA: O PROGRAMA DEVE MOSTRA O VALOR DE A^N.
*/
//biblioteca
#include <iostream>
#include <cmath> //biblioteca matemática

using namespace std;

//função recursiva
int potencia(int a, int n)
{
    //se o expoente for 0
    if(n == 0) //condição de parada
    {
        //retornara a 1
        return 1;
    }
    else //chamada recursiva
    {
        return a * potencia(a, n - 1);
    }
}

//função principal
int main()
{
    //declaração de váriaveis
    int a; //base
    int n; //expoente

    //entrada de dados
    //lê a base e o expoentes
    cin >> a >> n;

    //desenvolvimento
    //chama a função recursiva
    int resultado = potencia(a, n);

    //saida de dados
    cout << resultado << endl;

    return 0;
}