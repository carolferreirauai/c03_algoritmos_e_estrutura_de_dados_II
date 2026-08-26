/*
17. A PROFESSORA LÚ DESEJA ARMAZENAR AS NOTAS DOS ALUNOS DE FORMA A CALCULAR RAPIDAMENTE
A MÉDIA DA TURMA. PARA ISTO, PENSOU EM GUARDÁ-LAS EM UMA LISTA LIGADA
CUJO NÓ DE CABEÇALHO JÁ MOSTRAR A MÉDIA DAS NOTAS. IMPLEMENTE UMA FUNÇÃO QUE,
AO INSERIR UMA NOVA NOTA NA LISTA, ATUALIZE AUTOMATICAMENTE O NÓ DO CABEÇALHO.
*/

//biblioteca
#include <iostream>
#include <list> //necessario para listas

using namespace std;

//função inicialização
void inicializar(list<double> &lista)
{
    lista.clear();
    lista.push_back(0.0); //cabeçalho começa com média zero
}

//retorna a média
double media(list<double> &lista)
{
    return lista.front(); //tempo constantes
}

//função inserir
void inserir(list<double> &lista, double nota)
{
    double quantidades = lista.size() - 1; //tamanho da lista
    double media_anterior = lista.front(); 

    //formula matematica
    double nova_media = (media_anterior * quantidades + nota) / (quantidades + 1);

    //inserer a nota
    list<double>::iterator p = lista.begin();
    p++;
    lista.insert(p, nota);

    //atualizar a media
    lista.front() = nova_media;
}

//função auxiliar para imprimir
void imprimir(list<double> &lista)
{
    list<double>::iterator p = lista.begin();

    //mostrar a média
    cout << "Media(" << *p << ") -> Notas dos alunos: [";
    p++;

    for(;p != lista.end(); p++)
    {
        cout << *p << " ";
    }
    cout << "]" << endl;
}

//função principal
int main()
{
    //declaração de variaveis
    list<double> lista;
    //chamar a função
    inicializar(lista);
    int quantidades;
    double notas;

    //entrada de dados
    cin >> quantidades;

    for(int i = 0; i < quantidades; i++)
    {
        cin >> notas;

        //chamar a função
        inserir(lista, notas);
    
        imprimir(lista);
    }

    //saida de dados
    //chamar uma função
    cout << "Media Final: " << media(lista) << endl;

    return 0;
}