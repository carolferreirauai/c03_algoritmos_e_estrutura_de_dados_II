/*
3. REIMPLEMENTE OS ALGORITMOS DE BUSCA SEQUENCIAL E BUSCA BINÁRIA PARA LISTAS
CIRCULAMENTE LIGADAS.
*/
noptr buscasequencial_circular(noptr ultimo, int x)
{
    if(ultimo == NULL)
        return NULL;
    
    noptr p = ultimo -> next; //começa do primeiro nó
    do 
    {
        if (p -> info == x)
            return p;
    }while(p != ultimo -> next); //para quando der uma volta completa

    return NULL;
}