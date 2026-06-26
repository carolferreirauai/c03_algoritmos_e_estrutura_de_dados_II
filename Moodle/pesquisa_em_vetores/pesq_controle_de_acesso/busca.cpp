int binaria(int vetor[],int tamanho, int x)
{
    //váriavel para avisar se encontrou x ou não
    bool achou; // var aux p/ busca
    //ponteiros que vão marcar limites
    int baixo, meio, alto; // var aux

    baixo = 0; // o limite de 'baixo' começa no primeiro índice do vetor
    alto = tamanho-1; //o limite de 'alto' começa no último indice
    achou = false; //não achou nada

    //o loop repete enquanto o limite de 'baixo' não ultrapassa o de 'alto'
    // e não tiver achado
    while ((baixo <= alto) && (achou == false))
    {
        meio = (baixo + alto) / 2; //1° - calcular o meio exato
        
        //2° - o número procurado (x) é menor que o número do meio?
        if (x < vetor[meio])
        {
            //se for, o 'x' está a esquerda, direta lixo.
            alto = meio - 1;
        }
        else
        {
            //3° - o número procurado (x) é maior que o número do meio?
            if (x > vetor[meio])
            {
                //se for, o 'x' está a direita, esquerda lixo
                baixo = meio + 1;
            }
            else
            {
                //4° - se não for menor e nem menor, é porque é igual.
                achou = true;
            }
        }

    //loop terminou, verificar os motivos
    }
    if (achou)
    {
        return meio; //se achou, devolve a posição
    }
    else
    {
        return -1; //se não achou, retorna -1
    }
}