/* 
1) SENDO P UM PONTEIRO, QUAL A DIFERENÇA ENTRE:
A) P++;
B) (*P)++;
C)*(P++);

FAÇA UM PROGRAMA EXEMPLO QUE ILUSTRE ESTAS DIFERENÇAS E ADICIONE
COMENTÁRIO AO CÓDIGO DE MODO A EXPLICÁ-LAS.
*/

//biblioteca
#include <iostream>

using namespace std;

int main()
{
    int vetor[4] = {10, 20, 30}; //vetor com 3 números
    int *p = vetor; //ponteiro 'p' recebe o endereço de 'vetor'

    cout << "Inicio: p aponta para o valor: " << *p << endl; //saída será 10

    p++; //é movido para o próximo endereço - próxima posição de vetor.
    cout << "p++: " << *p << endl; //saída será 20

    (*p)++; //endereço atual e somamos +1 diretamente ao conteúdo de dentro.
    cout << "(*p)++: " << *p << endl; //saída será 21

    int aux = *(p++); //[*] lê o valor atual do endereço e guarda na váriavel aux e depois [p++] o ponteiro avança para o próximo endereço
    cout << "'*'(p++) = " << aux << endl; //saída será 21
    cout << "*'(p++)': " << *p << endl; //saída será 30

    return 0;
}