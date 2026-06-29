/*
2. CRIE UMA FUNÇÃO EM C++ PARA INSERÇÃO DE STRINGS EM UMA TABELA HASH.
UTILIZE O MÉTODO DA SOMA DE CARACTERES PARA GERAR O VALOR DE K INTEIRO ANTES DO CÁLCULO
HASHING COM MÉTODO DA DIVISÃO.
*/

//biblioteca
#include <iostream>
#include <string>

using namespace std;

//função hash para string
int hash_string(string texto, int tamanho)
{
    int chave = 0; //chave começa vazia
    int i = 0; //começa pela letra no indice 0

    //enquantom a letra atual não for caractere nulo
    while (texto[i] != '\0')
    {
        //ao somar um char em um int, pega o valor da tabela ASCII
        chave += texto[i];
        i++; //avançar a próxima letra
    }
    //depois de somar tudo e encontrar o valor de k inteiro, aplica a divisão
    return chave % tamanho;
}

//função principal
int main()
{
    //declaração de váriaveis
    int m = 12; //tamanho lógico
    string tabela_hash[100]; //vetor com 100 elemento
    string nome;

    //entrada de dados
    for(int i = 0; i < m; i++)
    {
        tabela_hash[i] = "";
    }

    cout << "Digite um nome, ao terminar escreve fim: ";

    //enquanto o nome for diferente de fim
    while (cin >> nome && nome != "fim")
    {
        //desenvolvimento
        //calcular a posição da string
        int posicao = hash_string(nome, m);

        //guardar o nome na tabela
        tabela_hash[posicao] = nome;

        //saída de dados
        cout << "O nome " << nome << " foi mapeado para o índice " << posicao << endl;
        cout << "Digite o próximo nome: ";
    }

    return 0;
}