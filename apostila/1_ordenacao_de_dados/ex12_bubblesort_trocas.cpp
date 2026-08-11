/*
12. MODIFIQUE A FUNÇÃO QUE IMPLEMENTA O ALGORITMOS BUBBLE SORT, DE MODO QUE ESTE
RETORNE O NÚMERO DE TROCAS REALIZADAS ATÉ A ORDENAÇÃO FINAL DO VETOR.
*/
//1° MODIFICAÇÃO: mudar a função de void para int
int bubblesort(int vetor[], int tamanho)
{
    int trabalho; //váriavel auxiliar
    int j; //contadores

    //2° MODIFICAÇÃO: criar uma váriavel que vai contar as trocas
    int num_trocas = 0;

    bool troca = true; //começa com true para forçar a entrada do while
    int limite = tamanho - 1; //limite é o penúltimo índice

    //loop roda enquanto houver trocas acontecendo
    while(troca)
    {
        troca = false; //assume inicalmente o vetor já ordenado

        //percorre o vetor do ínicio até a posição 'limite'
        for (int i = 0; i < limite; i++)
        {
            //se o elemento atual for maior que o vizinho da direta
            //fora da ordenação
            if(vetor[i] > vetor[i + 1])
            {
                //inverte a posição dos dois elementos
                trabalho = vetor[i];
                vetor[i] = vetor[i + 1];
                vetor[i + 1] = trabalho;

                j = i; //guarda a posição
                troca = true; //avisa o 'while' que uma troca foi feita

                //3° MODIFICAÇÃO: toda vez que 'if' for verdadeiro e os elementos trocarem, o num_trocas com mais 1
                num_trocas++;
            }
        }

        //otimização: os elementos depois 'j' já estão ordenados
        //então, na próxima rodada, o 'for' só precisa ir até 'j'
        limite = j;
    }
    //4° MODIFICAÇÃO: a função retornaram o total de quantidades de troca
    return num_trocas;
}