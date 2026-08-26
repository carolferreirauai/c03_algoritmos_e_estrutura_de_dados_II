/*
10. O RAIL FENCE, CUJA TRADUÇÃO LITERAL É “PALIÇADA”, É UMA CIFRA DE TRANSPOSIÇÃO
GEOMÉTRICA QUE FOI MUITO UTILIZADA NA GUERRA DE SECESSÃO NORTE-AMERICANA (1861-
1865), QUANDO TANTO OS CONFEDERADOS QUANTO OS FEDERALISTAS A UTILIZARAM PARA
CIFRAR MENSAGENS.

SEU FUNCIONAMENTO É BASTANTE SIMPLES, E CONSISTE EM USAR UM PADRÃO FIXO EM
ZIG-ZAG. DIGAMOS QUE A MENSAGEM “LULINHA PAZ E AMOR” DEVA SER CIFRADA COM
UMA RAIL FENCE DE DUAS LINHAS:

L     L     N     A     A     E     M     R
   U     I     H     P     Z     A     O

O TEXTO CIFRADO RESULTANTE É OBTIDO PELA SEQUÊNCIA DE LINHAS, OU SEJA: LLNAAEMR UIHPZAO.
CIFRANDO-SE O MESMO TEXTO COM UMA RAIL FENCE DE 3 NÍVEIS OBTEMOS LNAM
UIHPZAO LAER. VEJA ABAIXO:

L           N           A           M
   U     I     H     P     Z     A     O
      L           A           E           R

UMA DAS ETAPAS DA CODIFICAÇÃO DESTE ALGORITMO CONSISTE EM GERAR A SEQUÊNCIA
DAS LINHAS EM QUE AS LETRAS SERÃO ARMAZENADAS. PARA UMA RAIL FENCE DE 3 LINHAS,
DEVEMOS GERAR A SEQUÊNCIA:

1 2 3 2 1 2 3 2 1 2 3 2 1 2 3 2 1 . . .

E PARA UMA RAIL FENCE DE 4 LINHAS:

1 2 3 4 3 2 1 2 3 4 3 2 1 2 3 4 3 2 1 . . .

FAÇA UMA FUNÇÃO QUE TOME COMO ENTRADAS O NÚMERO DE LINHAS DA RAIL FENCE (N),
E O COMPRIMENTO DA STRING A SER CODIFICADA (COMP) E MOSTRE NA TELA A SEQUÊNCIA
DE LINHAS CORRESPONDENTE, DE TAMANHO COMP. A FUNÇÃO DEVE USAR UMA LISTA LIGADA
CIRCULAR PARA GERAR A SEQUÊNCIA DE NÚMEROS.

POR EXEMPLO, SE N=3 E COMP=6, A FUNÇÃO DEVE IMPRIMIR:

1 2 3 2 1 2

O CABEÇALHO DA FUNÇÃO DEVE SER: VOID GERASEQUENCIA(INT N,INT COMP)

VOCÊ PODE CONSIDERAR QUE AS FUNÇÕES PUSH(NOPTR &LISTA,INT X) E INSERE(NOPTR
&LISTA, INT X) ESTÃO DISPONÍVEIS.
*/

//biblioteca
#include <iostream>
#include <list> //necessária para lista

using namespace std;

void gerar_sequencia(int n, int comp)
{
    //validação de segurança para evitar loops infinitos ou erros
    if(n <= 0 || comp <= 0)
    {
        return;
    }

    list<int> lista_circular;

    if(n == 1)
    {
        lista_circular.push_back(1);
    }
    else
    {
        //criar uma lista zig-zag
        for(int i = 1; i <= n; i++)
        {
            lista_circular.push_back(i);
        }

        //adiciona descendo
        for(int i = n - 1; i >= 2; i--)
        {
            lista_circular.push_back(i);
        }
    }

    //criar o iterator
    list<int>::iterator p = lista_circular.begin();

    //mostrar a quantidade 'comp' de numeros solicitados
    for(int i = 0; i < comp; i++)
    {
        cout << *p << " ";
        p++; //avançar

        if(p == lista_circular.end())
        {
            p = lista_circular.begin();
        }
    }
    cout << endl;
}

//função principal
int main()
{
    //declaração de variaveis
    int n, comp;

    //entrada de dados
    cin >> n >> comp;

    //chamar a função circular
    gerar_sequencia(n, comp);

    return 0;
}