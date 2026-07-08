/*
2. REIMPLEMENTE OS ALGORITMOS DE BUSCA SEQUENCIAL E BUSCA BINÁRIA PARA LISTA LIGADAS.
*/
noptr buscasequencial_lista(noptr lista, int x)
{
    for(noptr p = lista; p != NULL; p = p -> next)
    {
        if(p -> info == x)
            return p; //achou
    }
    return NULL; //não achou
}

/*
Busca Binária: Aqui temos um problema clássico. A busca binária exige que você "salte" 
diretamente para o elemento central do vetor calculando (baixo + alto) / 2. Em 
uma lista ligada simples, nós não temos acesso direto ao "meio" teŕıamos que caminhar 
um por um até a metade, perdendo totalmente a eficiência que faz a busca binária ser tão 
rápida. Portanto, na prática, não se aplica busca binária padrão em listas ligadas simples.
*/