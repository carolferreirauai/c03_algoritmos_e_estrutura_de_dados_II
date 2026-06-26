#include <iostream>
#include "busca.h" //inclui biblioteca com função de busca binária

using namespace std;

int main()
{
    //declaração de váriaveis
    int valor; //número de inteiros
    int vetor[20]; //vetor com 20 elementos
    int id; //identificação
    int tamanho = 0; //quantidades

    //entrada de dados
    cin >> valor; //ler os números inteiros

    //desenvolvimento
    //loop, enquanto o valor for diferente de -1, ele continua
    //armazenar o vetor
    while (valor != -1)
    {
        vetor[tamanho] = valor; //guardar o valor
        tamanho++;
        cin >> valor;
    }

    //entrada de dados
    //após digitar -1, irá ler a identificação
    cin >> id;

    //chama a função
    int acesso = binaria(vetor, tamanho, id);

    //saída de dados
    //se o resultado for -1, porque achou o id no vetor
    if (acesso != -1)
    {
        cout << "Possui acesso" << endl;
    }
    else
    {
        //se a função retornar -1, o id não possui acesso
        cout << "Não possui acesso" << endl;
    }

    return 0;
}