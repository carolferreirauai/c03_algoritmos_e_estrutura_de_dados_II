/*
2) QUAL O VALOR DA VARIÁVEL Y NO FINAL DA EXECUÇÃO DO CÓDIGO A SEGUIR?
ESCREVA UM COMENTÁRI EM CADA COMANDO DE ATRIBUIÇÃO, EXPLICANDO O
QUE ELE FAZ E O VALOR DA VARIÁVEL À ESQUERDA DO '=' APÓS SUA EXECUÇÃO.
*/
//biblioteca
#include <iostream>

using namespace std;

int main()
{
    //declaração de variáveis
    int y, *p, x; //2 variável inteiras e 1 ponteiros

    //entrada de dados
    y = 0; //'y' recebe um valor 0
    p = &y; //ponteiro 'p' recebe o endereço de memória da variável 'y'
    x = *p; //'x' recebe a cópia do valor guardado no endereço apontado
    x = 4; //'x' recebe um valor 4

    //operações
    (*p)++; //ponteiro 'p' acessa a váriavel 'y' e soma +1 ao seu conteúdo
    x--; //'x' é decrementado volta 1
    (*p) += x; //ponteiro 'p' acessa a 'y' e soma a ele o valor atual de 'x'


    //saida de dados
    cout << "y = " << y << endl; //saída o valor final de y

    return 0;
}