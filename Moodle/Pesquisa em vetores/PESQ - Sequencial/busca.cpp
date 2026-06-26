int sequencial(int vetor[], int tamanho, int x)
{
    //declaração de váriaveis
    //'achou' começa como falso, pois ainda nem começamos a procurar
    bool achou = false; //var aux p/ busca
    //'i' é o nosso contador que vai de 0 até o final do vetor
    int i = 0;//contador

    //desenvolvimento
    //loop roda enquanto não achou (achou == false) e o 'i' for menor que o tamanho
    while (achou == false && i < tamanho)
    {
        //1° - testa vetor[i] == a 'x' e guarda o resultado (verdadeiro ou falso) no 'achou'
        //2° - o 'i++' faz com que o 'i' aumenta mais 1, logo após a leitura.
        achou = vetor[i++] == x; 
    }
    //se o laço terminou e o 'achou == true'
    if (achou)
    {
        return (i - 1); //retorna 'i--', pois precisa retornar a posição correta
    }
    else
    {
        //se terminou o laço e não achou, retorna -1 indicado falha
        return -1;
    }
}