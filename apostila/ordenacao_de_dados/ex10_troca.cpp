/*
10. OS EXERCÍCIOS DE ORDENAÇÃO APRESENTADOS ATÉ AGORA SOLICITAM O DESENVOLVIMENTO DE 
UMA ORDENAÇÃO QUE PODE SER CLASSIFICADA COMO DESTRUTIVA, PORQUE O VETOR ORIGINAL
É DESTRUÍDO E SUBSTITUÍDO POR SUA VERSÃO ORDENADA. UMA BOA ALTERNATIVA É CRIAR
UM VETOR AUXILIAR CUJOS ÍNDICES REPRESENTAM A POSIÇÃO DOS ELEMENTOS NO VETOR A SER
ORDENADO. FAÇA UM PROGRAMA EM C++ QUE USE O VETOR AUXILIAR PARA IMPLEMENTAR
O MÉTODO DE ORDENAÇÃO POR SELEÇÃO DIRETA.
*/
void selecaoindireta(int vetor[], int indice[], int tamanho)
{
    //inicializa o vetor de índice
    for (int i = 0; i < tamanho; i++)
    {
        indice[i] = i;
    }

    //processo de seleção direta apenas nos índices
    //vai do início até o penúltimo elemento
    for (int i = 0; i < (tamanho - 1); i++)
    {
        int menor = i; //guarda a posição do menor elemento encontrado

        //começa no elemento seguinte ao 'i'
        for (int j = i + 1; j< tamanho; j++)
        {
            //comparar os valores originais guiando-se pelo índice
            if(vetor[indice[j]] < vetor[indice[menor]])
            {
                menor = j; //se o valor real for menor, guardamos essa nova posição
            }
        }


        //trocar apenas os indices, os dados reais ficam parados
        int aux = indice[i];
        indice[i] = indice[menor];
        indice[menor] = aux;
    }
}