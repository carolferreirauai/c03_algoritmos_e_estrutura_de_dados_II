/*
FAÇA UMA FUNÇÃO QUE RECEBA DUAS VARIÁVEIS DO TIPO FLOAT E INVERTA OS
SEUS VALORES.

EXEMPLOS: SE X = 2.4 E Y = 3.2, APÓS A EXECUÇÃO DA FUNÇÃO, DEVEMOS TER 
X = 3.2 E Y = 2.4

- VOIDE INVERTE(FLOAT X, FLOAT Y) //O QUE DEVE SER MUDADO AQUI
*/
//biblioteca
#include <iostream>

using namespace std;

//função inverter
void inverte(float *x, float *y) //[*] para indicar que são ponteiros, recebem endereço de memória
{
    float aux = *x; //guardaram endereço de 'x' (*x - operador de derreferência)

    *x = *y; //o valor guardado 'y' é cópiado para 'x'

    *y = aux; //o valor salvo em 'aux' e guardado em 'y'
}

//função principal
int main()
{
    //declaração de váriaveis, como o exemplo
    float a = 2.4;
    float b = 3.2;

    cout << "antes de chamar a função: a = " << a << " e b = " << b << endl;

    //chamar a função
    inverte(&a, &b); //& extrair o endereço de memória de a e b.

    cout << "depois de chamar a função: a = " << a << " e b = " << b << endl;

    return 0;
}