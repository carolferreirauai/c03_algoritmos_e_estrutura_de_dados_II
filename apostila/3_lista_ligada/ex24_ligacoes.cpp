/*
24. UM SISTEMA DE TARIFAÇÃO TELEFÔNICA MEDE O TEMPO GASTO EM LIGAÇÕES LOCAIS, INTERURBANAS
E INTERNACIONAIS, E CALCULA A CONTA TOTAL A SER PAGA PELO USUÁRIO. SUPONDO
QUE O CUSTO DE UMA LIGAÇÃO LOCAL SEJA DE R$0,05/MIN, FAÇA UM PROGRAMA QUE LEIA
OS SEGUINTES DADOS DE VÁRIOS USUÁRIOS:

(A) NOME
(B) NÚMERO DO TELEFONE
(C) NÚMERO DE MINUTOS EM LIGAÇÕES LOCAIS

E OS ARMAZENE EM UMA LISTA LIGADA, JUNTAMENTE COM O VALOR TOTAL DA CONTA (VOCÊ
DEVE APRESENTAR A STRUCT NO NÓ).

DEPOIS O PROGRAMA DEVE SOLTAR UMA LISTRAGEM COM NOME DO USUÁRIO, NÚMERO DO
TELEFOMNE E TOTAL DA CONTA, DA SEGUINTE MANEIRA:

ANA 34719001 R$100,00
BETO 34719222 R$70,00

BASEIE SEU PROGRAMA NAS FUNÇÕES PUSH E POP.
*/

//biblioteca
#include <iostream>
#include <list> //necessario para listas
#include <iomanip> //necessario para formatar as duas casas decimais

using namespace std;

//definição da struct
struct usuario
{
    char nome[100];
    char telefone[30];
    int minutos;
    float total;
};

//função push - insere um novo usuário no topo da pilha
void push(list<usuario> &lista, usuario novo_usuario)
{
    lista.push_front(novo_usuario); //insere na frente
}

//função pop - remove o usuário do topo da pilha e devolve os dados
bool pop(list<usuario> &lista, usuario &usuario_removido)
{
    if(lista.empty())
    {
        return false; //pilha vazia
    }

    usuario_removido = lista.front(); //recupera o usuário
    lista.pop_front(); //remove
    return true; //sucesso
}

//função principal
int main()
{
    //declaração de variáveis
    list<usuario> pilha;
    usuario novo;
    int quantidades;

    //entrada de dados
    //quantidades
    cout << "Quantidade: ";
    cin >> quantidades;

    //cadastro
    for(int i = 0; i < quantidades; i++)
    {
        cout << "Nome: ";
        cin >> ws;
        cin.getline(novo.nome, 100);

        cout << "Telefone: ";
        cin >> ws;
        cin.getline(novo.telefone, 30);

        cout << "Minutos locais utilizados: ";
        cin >> novo.minutos;

        novo.total = novo.minutos * 0.05;

        //chama a função push
        push(pilha, novo);
    }

    //saida de dados
    cout << fixed << setprecision(2);
    usuario auxiliar;
    while(!pilha.empty())
    {
        if(pop(pilha, auxiliar))
        {
            cout << auxiliar.nome << endl;
            cout << auxiliar.telefone << endl;
            cout << auxiliar.total << endl;
        }
    }
    return 0;
}