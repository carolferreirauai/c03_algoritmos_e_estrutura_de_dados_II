/*
LIST - SUPERMERCADO

UM GERENTE DE SUPERMERCADO POSSUI DUAS LISTAS, SENDO A PRIMEIRA COM OS CÓDIGOS DE PRODUTOS QUE ESTÃO NO ESTOQUE, 
E A SEGUNDA COM OS CÓDIGOS DOS PRODUTOS QUE JÁ ESTÃO DISPONÍVEIS PARA VENDA.

SEMPRE QUE UM PRODUTO NOVO CHEGA, PRIMEIRO ELE É ADICIONADO NO ESTOQUE, E DEPOIS É MOVIDO PARA VENDA, À MEDIDA 
EM QUE OS PRODUTOS VÃO SENDO VENDIDOS.

ELE PRECISA DE ALGUÉM PARA GERENCIAR ESSAS LISTAS E CONTRATOU VOCÊ PARA O SERVIÇO.

ENTRADA: A PRIMEIRA LINHA CONTÉM UM ÚNICO INTEIRO N, QUE CORRESPONDE AO NÚMERO DE OPERAÇÕES.
DEPOIS SEGUEM-SE N LINHAS, SENDO QUE CADA LINHA CORRESPONDE A UMA OPERAÇÃO.
SE O PRIMEIRO NÚMERO DA LINHA FOR 1, VOCÊ DEVERÁ LER O CÓDIGO DO PRODUTO E COLOCÁ-LO NO ESTOQUE;
SE FOR 2, VOCÊ DEVERÁ PEGAR UM ELEMENTO DO ESTOQUE E COLOCÁ-LO PARA VENDA.

SAÍDA: A SAÍDA DEVERÁ MOSTRAR QUAIS ELEMENTOS ESTÃO NO ESTOQUE E QUAIS ESTÃO DISPONÍVEIS PARA VENDA.
*/
//biblioteca
#include <iostream>
#include <list>

using namespace std;

//função principal
int main()
{
    //declaração de variaveis
    list<int> produto_estoque;
    list<int> produto_vendas;
    int N; //números de operação
    int operacao; //qual operacao
    int codigo; //codigo do produto
    list<int>::iterator p; //ponteiro

    //entrada de dados
    cin >> N; //ler as quantidades de operações

    //desenvolvimento
    for (int i = 0; i < N; i++)
    {
        cin >> operacao; //1 ou 2
        
        if(operacao == 1)
        {
            //primeiro adiciona ele no estoque
            cin >> codigo; //ler o código
            produto_estoque.push_back(codigo); //inseri na lista do estoque forma pilhas
        }
        else if (operacao == 2)
        {
            //depois movido para venda
            if(!produto_estoque.empty()) //se tiver elementos
            {
                codigo = produto_estoque.front(); //primeiro produto do estoque
                produto_estoque.pop_front(); //remove o produto do inicio
                produto_vendas.push_front(codigo); //adiciona o produto na lista de vendas
            }
        }
    }

    //saída de dados
    cout << "Estoque: ";
    //ler a lista
    for(p = produto_estoque.begin(); p != produto_estoque.end(); p++)
    {
        cout << *p << " ";
    }
    cout << endl;

    cout << "Venda: ";
    for(p = produto_vendas.begin(); p != produto_vendas.end(); p++)
    {
        cout << *p << " ";
    }
    cout << endl;

    //liberar memória
    while(!produto_estoque.empty())
    {
        produto_estoque.pop_front();
    }
    
    while(!produto_vendas.empty())
    {
        produto_vendas.pop_front();
    }
    return 0;
}