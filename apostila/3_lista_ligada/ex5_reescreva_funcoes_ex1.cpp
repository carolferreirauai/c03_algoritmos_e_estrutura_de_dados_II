/*
5. REESCREVA AS FUNÇÕES DO EXERCÍCIOS 1 PRESSUPONDO QUE CADA LISTA CONTENHA UM NÓ
DE CABEÇALHO COM O NÚMERO DE ELEMENTOS DA LISTA.
*/
#include <iostream>
#include <list> //necessário para listas

using namespace std;

//função inicialização
void inicializar(list<int> &lista)
{
    lista.clear();
    lista.push_back(0);
}

//(a) retornar o número de elementos da lista
int obter_tamanho(list<int> &lista)
{
    return lista.front(); //retorna o valor do cabeçalho
}

//(c) eliminar o n-ésimo elemento da lista
bool eliminar_nesimo(list<int> &lista, int n)
{
    int tamanho = obter_tamanho(lista);
    
    if(n <= 0 || n > tamanho)
    {
        return false; //posição invalida
    }

    list<int>::iterator p = lista.begin();

    //avançamos n posições
    for (int i = 0; i < n; i++)
    {
        p++;
    }

    lista.erase(p); //remove
    lista.front()--;
    return true;
}

//(g) inserir um nó depois
bool inserir_depois(list<int> &lista, int n, int x)
{
    int tamanho = obter_tamanho(lista);

    if(n < 0 || n > tamanho)
    {
        return false;
    }

    list<int>::iterator p = lista.begin();

    //varrer até a posição 'n'
    for(int i = 0; i < n; i++)
    {
        p++;
    }

    //inserir imediatamente após posição
    p++;
    lista.insert(p, x);
    lista.front()++;
    return true;
}

//(h) verificar se existe um valor x
bool verificar(list<int> &lista, int x)
{
    list<int>::iterator p = lista.begin();
    p++;

    for(; p != lista.end(); p++)
    {
        if (*p == x)
        {
            return true;
        }
    }

    return false;
}

//(j) inverter uma lista
void inverter(list<int> &lista)
{
    int tamanho = obter_tamanho(lista);

    //nada inverter
    if(tamanho <= 1)
    {
        return;
    }

    list<int> auxiliar;
    list<int>::iterator p = lista.end();

    //varre a lista de trás para frente
    while(p != ++lista.begin())
    {
        p--;
        auxiliar.push_back(*p);
    }

    //limpa a lista antiga e reconstrói
    lista.clear();
    lista.push_back(tamanho);

    //insere ps elementos
    for (p = auxiliar.begin(); p != auxiliar.end(); p++)
    {
        lista.push_back(*p);
    }
}

//função imprimir
void imprimir(list<int> &lista)
{
    list<int>::iterator p = lista.begin();

    cout << "Cabecalho (Contador: " << *p << ") -> Elementos reais: [";

    p++;
    for(; p != lista.end(); p++)
    {
        cout << *p << " ";
    }
    cout << "]" << endl;
}

//função principal 
int main()
{
    //declaração de variaveis
    list<int> lista;
    inicializar(lista);
    int quantidades, numeros;
    int valor_extra = 99;

    //entrada de dados
    cin >> quantidades;
    for(int i = 0; i < quantidades; i++)
    {
        cin >> numeros;
        inserir_depois(lista, 0, numeros);
    }

    //saida de dados, chamando a função imprimir
    imprimir(lista);

    cout << "Inserido " << valor_extra << " apos a 2a posicao real..." << endl;
    inserir_depois(lista, 2, valor_extra);
    imprimir(lista);

    cout << "Eliminando o 1o elemento real..." << endl;
    eliminar_nesimo(lista, 1);
    imprimir(lista);

    cout << "Invertendo" << endl;
    inverter(lista);
    imprimir(lista);

    return 0;
}