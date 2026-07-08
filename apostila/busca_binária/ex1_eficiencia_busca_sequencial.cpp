/*
1. EFICIÊNCIA DA BUSCA SEQUENCIAL PODE SER AUMENTADA SE COLOCARMOS NAS POSIÇÕES
INICIAIS OS ELEMENTOS QUE OCORREM COM MAIOR FRENQUÊNCIA. PARA ISTO, DUAS
ESTRATÉGIAS SÃO UTILIZADAS:

(A) MOVER-PARAA-FRENTE: SEMPRE QUE UMA PESQUISA TIVER êXITO, O ELEMENTO
ENCONTRADO É MOVIDO PARA O INICIO DA LISTA.

(B) TRANSPOSIÇÃO: SEMPRE QUE UMA PESQUISA TIVER ÊXITO, O ELEMENTO ENCONTRADO
TROCA DE LUGAR COM SEU ANTECESSOR.

ESCREVA FUNÇÕES QUE IMPLEMENTEM ESTAS DUAS ESTRATÉGIAS
*/
//(A)
int sequencial_moverparafrente(int vetor[], int tamanho, int x)
{
    for (int i = 0; i < tamanho; i++)
    {
        if(vetor[i] == x)
        {
            //achou, salva e desloca
            int temp = vetor[i];

            for(int j = i; j > 0; j--)
            {
                vetor[j] = vetor[j - 1];
            }
            vetor = temp; //move para frente
            return 0;
        }
    }
    return -1;
}

//(B)
int sequencial_transposicao(int vetor[], int tamanho, int x)
{
    for (int i = 0; i < tamanho; i++)
    {
        //se não for o primeiro, troca com o anterior
        if(i > 0)
        {
            int temp = vetor[i];
            vetor[i] = vetor[i - 1];
            vetor[i - 1] = temp;
            return i - 1; //retorna a nova posição
        }
        return i; 
    }
    return -1;
}