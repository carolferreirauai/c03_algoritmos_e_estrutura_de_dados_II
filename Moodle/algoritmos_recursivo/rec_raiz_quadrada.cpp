/*
REC - RAIZ QUADRADA

DADO UM NÚMERO REAL POSITIVO X, PODEMOS CALCULAR SQRT(X) USANDO O SEGUINTE ALGORITMOS RECURSIVO:

RAIZ(X, X_0, E) = X_0,                                    |X^2 && X_0 - X| <= E
                  RAIZ(X, (X^2 && X_0 + X) / 2 * X_0, E), CASO CONTRÁRIO
ONDE:
- X: É O NÚMERO DO QUAL SE QUER CALCULAR A RAIZ
- X_0: É UMA ESTIMATIVA INICIAL PARA SQRT(X)
- E: É UM LIMITANTE SUPERIOR PARA O ERRO

FAÇA UM PROGRAMA QUE LEIA OS VALORES DE X, X_0, E E, E RETORNE O VALOR SQRT(X), COM 4 CASAS DECIMAIS. VOCÊ PODE ASSUMIR
QUE ESTES VALORES SERÃO SEMPRE POSITIVOS.

O CÁLCULO DEVE SER FEITO USANDO UMA FUNÇÃO RECURSIVA.

ENTRADA: A ENTRADA CONSISTE 3 VALORES REAIS E POSITIVOS, CORRESPONDENTES A X, X_0 E E.

SAIDA: O PROGRAMA DEVE MOSTRAR O VALOR DE SQRT(0), COM A PRECISÃO DESEJADA.
*/
//biblioteca
#include <iostream>
#include <cmath> //biblioteca para funções matemáticas
#include <iomanip> //biblioteca para setprecision

using namespace std;

//função recursiva
float raizquadrada(float x, float x_0, float e)
{
    //condição de parada
    if((pow(x_0,2) - x) >= -e && (pow(x_0, 2) - x) <= e) //modulo >= -1 && <= 1
    {
        return x_0;
    }
    //chamada recursiva
    else
    {
        return raizquadrada(x, ((pow(x_0, 2) + x) / (2 * x_0)), e);
    }
}

int main()
{
    //declaração de variáveis
    float x; //calcular raiz
    float x_0; //estimativa inicial da sqrt(x)
    float e; //limitante superior de erro

    //entrada de dados
    //ler os valores
    cin >> x >> x_0 >> e;

    //desenvolvimento
    //chama a função
    double resultado = raizquadrada(x, x_0, e);

    //saída de dados
    cout << fixed << setprecision(4) << resultado << endl;

    return 0;
}