/*
2. FAÇA UM PROGRAMA QUE CRIE UMA LISTA LIGADA E INSIRA ALGUNS NÓS NA MESMA (VOCÊ
PODE USAR A FUNÇÃO PUSH PARA FAZER ISSO). DEPOIS O PROGRAMA DEVE PEDIR AO USUÁRIO
QUE DIGITE O VALOR QUE OS NÓS A SEREM ELIMINADOS DEVE CONTER, E CHAMAR A FUNÇÃO
REMOVETUDO PARA EXECUTAR A TAREFA.
*/
//biblioteca
#include <iostream>
#include <list> //necessaria para listas

using namespace std;

//função removetudo
void remove_tudo(list<int> &lista, int x)
{
    list<int>::iterator p = lista.begin(); //ponteiro

    //varrer a lista
    while(p != lista.end())
    {
        if (*p == x)
        {
            p = lista.erase(p); //remove o elemento da lista
        }
        else
        {
            p++;
        }
    }   
}

//função principal
int main()
{
    //declaração de váriaveis
    list <int> minha_lista;
    int quantidade, valor, valor_eliminar;

    //entrada de dados
    cout << "Quantos numeros deseja inserir na lista? ";
    cin >> quantidade;

    cout << "Digite os numeros para preencher a lista: " << endl;
    for (int i = 0; i < quantidade; i++)
    {
        cin >> valor;
        minha_lista.push_back(valor); //insere o numero no final da lista
    }
    
    //desenvolvimento
    cout << "Lista atual: " << endl;
    for (list<int>::iterator p = minha_lista.begin(); p != minha_lista.end(); ++p)
    {
        cout << *p << " ";
    }
    cout << endl;

    cout << "Digite o valor que deseja remover de toda a lista: ";
    cin >> valor_eliminar;

    //chamar a função para deletar
    remove_tudo(minha_lista, valor_eliminar);

    //saida de dados
    cout << "Lista apos remocao de todos os " << valor_eliminar << ": ";
    for (list<int>::iterator p = minha_lista.begin(); p != minha_lista.end(); ++p)
    {
        cout << *p << " ";
    }
    cout << endl;

    //liberar memória
    while(!minha_lista.empty())
    {
        minha_lista.pop_front();
    }

    return 0;
}