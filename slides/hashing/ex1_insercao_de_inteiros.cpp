/*
1. FAÇA UM CÓDIGO EM C++ PARA INSERÇÃO DE DADOS EM UM VETOR DE
TAMANHO N, A SER DEFINIDO NA ENTRADA DO PROGRAMA. UTILIZE O MÉTODO DA DIVISÃO PARA
CÁLCULO DO HASHING DE CADA CHAVE INSERIDA.
*/
//bibliotecas
#include <iostream>
#include <cmath> //necessário para a divisão
#include <locale.h> //corregir o português

using namespace std;

//função hash

int hash_inteiros(int chave, int tamanho)
{
    //se a chave for negativa, aplicamos a regra h(k) = (k % m) + m
    if (chave < 0)
    {
        return (chave % tamanho) + tamanho;
    }
    
    //método da divisão padrão: h(k) = k % m
    return chave % tamanho;
}

int main()
{
    //declaração de váriaveis
    setlocale(LC_ALL, "Portuguese");
    int n; //tamanho do vetor
    int quantidade_chaves; //quantidade de chaves
    int tabela_hash[100]; //vetor com 100 de elementos
 
    //entrada de dados
    //ler o tamanho do vetor
    cout << "Digite o tamanho do vetor: ";
    cin >> n;

    //desenvolvimento
    //inicializamos as posições válidas (0 até n) com -1 (indicando vazio)
    for (int i = 0; i < n; i++)
    {
        tabela_hash[i] = -1;
    }

    //ler a quantidade de chave
    cout << "Quantas chaves deseja inserir? ";
    cin >> quantidade_chaves;

    //processo de inserção
    for (int i = 0; i < quantidade_chaves; i++)
    {
        int chave;

        cout << "Digite a chave: ";
        cin >> chave;

        //calcula a posição usando a função hash
        int posicao = hash_inteiros(chave, n);

        //insere a chave na tabela
        tabela_hash[posicao] = chave;
        
        //saída de dados
        cout << "Chave: " << chave << " mapeada para o índice " << posicao << "!" << endl;
    }

    return 0;
}