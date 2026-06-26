int sequencial(int vetor[], int tamanho, int x)
{
    //indica se achamos o número
    bool achou = false; // var aux p/ busca
    //'i' começa com indice 0, primeira posição do vetor
    int i = 0;          // contador

    //loop repete enquanto 'achou' for falso e 'i' não ultrapasse o tamanho
    while (achou == false && i < tamanho)
    {
        //1° - testar se a posição atual do vetor é igual a 'x' e guardar no vetor
        //2° - o comando 'i++' aumenta o contador logo após o teste
        achou = vetor[i++] == x;
    }
    //o laço terminou
    if (achou)
    {
        //se achou == verdadeiro, ele retornará a posição.
        return (i - 1);
    }
    else
    {
        //se percorreu e o achou == falso, ele retornará -1.
        return -1;
    }
}
