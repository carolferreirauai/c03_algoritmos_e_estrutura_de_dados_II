/*
- CRIE EM PROGRAMAÇÃO EM C/C++ QUE PERMITA AO USUÁRIO CRIAR UMA PILHA DE
INTEIROS DO TAMANHO QUE ELE DESEJAR. EM SEGUIDA MOSTRE UM MENU DE 
OPÇÕES QUE PERMITA AO USUÁRIO REALIZAR AS SEGUINTES OPERAÇÕES:
    A) EMPILHAR (PUSH) NÚMEROS NA PILHA;
    B) DESEMPILHAR (POP) NÚMEROS DA PILHA;
    C) MOSTRAR O NÚMERO NO TOPO (TOP) DA PILHA;
    D) SAIR DO PROGRAMA.
DICAS:
- UTILIZE AS FUNÇÕES VISTAS ANTERIORMENTE PARA AUXILIAR NA CONSTRUÇÃO DO PROGRAMA.
- ANTES DE REALIZAR O PUSH OU POP DE ELEMENTOS, VERIFIQUE SE A PILHA ESTÁ CHEIA OU
VAZIA, RESPECTIVAMENTE, E AVISE O USUÁRIO CASO ISTO ACONTEÇA.
*/
//biblioteca
#include <iostream>
#include <list>

using namespace std;

//função com estrutura da pilha
struct pilha
{
    int *dados; //ponteiro para vetor alocado dinamicamente
    int topo; //indice que marca onde está o topo da pilha
    int capacidade; //tamanho máximo
};

//inicializar a pilha
void init(pilha &p, int capacidade_desejada)
{
    p.capacidade = capacidade_desejada;
    p.dados = new int[p.capacidade]; //alocação dinâmicas
    p.topo = -1; //-1 significa que a pilha está vazia
}

//verificar
bool isEmpty(pilha p)
{
    return (p.topo == -1); //-1, está vazia
}
bool isFull(pilha p)
{
    return (p.topo == p.capacidade - 1);
}

//empilhar
void push(pilha &p, int valor)
{
    //verificar
    if(!isFull(p))
    {
        p.topo++; //o topo sobre um degrau
        p.dados[p.topo] = valor; //guardamos o valor na nova posição
    }
}

//desempilhar
int pop(pilha &p)
{
    if(!isEmpty(p))
    {
        int valor_removido = p.dados[p.topo];
        p.topo--; //o topo desce um degrau
        return valor_removido;
    }
    return -1; //erro, está vazia
}

//mostrar o topo
int top(pilha p)
{
    if(!isEmpty(p))
    {
        return p.dados[p.topo];
    }
    return -1;
}

//função principal
int main()
{
    pilha pilhas;
    int tamanho, opcao, valor;

    //criando a pilha com o tamanho desejado
    cout << "Digite o tamanho da pilha: ";
    cin >> tamanho;
    init(pilhas, tamanho);

    //menu
    do
    {
        cout << " === MENU === " << endl;
        cout << "1. Empilhar (Push)" << endl;
        cout << "2. Desempilhar (Pop)" << endl;
        cout << "3. Mostrar o topo (Top)" << endl;
        cout << "4. Sair" << endl;
        cout << "Escolha uma opção: ";
        cin >> opcao;

        switch (opcao)
        {
            //empilhar
            case 1:
                if(isFull(pilhas))
                {
                    cout << "ERRO!" << endl;
                }
                else
                {
                    cout << "Digite o valor para empilhar: ";
                    cin >> valor;
                    push(pilhas, valor);
                    cout << "Valor " << valor << " empilhado com sucesso!" << endl;
                }
                break;

            //desempilhar
            case 2:
                if(isEmpty(pilhas))
                {
                    cout << "ERRO!" << endl;
                }
                else
                {
                    valor = pop(pilhas);
                    cout << "Valor " << valor << " desempilhando com sucesso!" << endl;
                }
                break;

            //mostrar topo
            case 3:
                if(isEmpty(pilhas))
                {
                    cout << "AVISO: A pilha está vazia!" << endl;
                }
                else
                {
                    cout <<"O elemento no topo é: " << top(pilhas) << endl;
                }
                break;

            //sair
            case 4:
                cout << "Encerrando programa..." << endl;
                break;
            
            default:
                cout << "Opção inválida!" << endl;
                break;
        }
    } while (opcao != 4);

    //liberar memória
    delete[] pilhas.dados;

    return 0;
}