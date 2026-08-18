/*
1 - IMPLEMENTE FUNÇÕES PARA EXECUTAR AS SEGUINTES TAREFAS:
(A) RETORNAR O NÚMERO DE ELEMENTO DE UMA LISTA.
(B) GERAR UMA LISYTA RESULTANTE DA CONCATENAÇÃO DE OUTRAS DUAS.
(C) ELIMINAR O N-ÉSIMO ELEMENTO DE UMA LISTA.
(D) RETORNAR A SOMA DOS ELEMENTOS DE UMA LISTA.
(E) DADOS DOIS NÓS, INVERTER AS POSIÇÕES DOS MESMOS. (DICA: NÃO PRECISA INVERTER
AS POSIÇÕES, APENAS OS CONTEÚDOS DOS CAMPOS INFO).
(F) DESLOCAR UM NÓ APONTADO POR P, N POSIÇÕES À FRENTE.
(G) INSERIR UM NÓ DEPOIS DO N-ÉSIMO ELEMENTO DE UMA LISTA.
(H) VERIFICAR SE EXISTE UM NÓ CUJO CAMPO INFO CONTÉM UM DETERMINADO VALOR X.
(I) FAZER UMA CÓPIA DE UMA LISTA.
(J) INVERTER UMA LISTA.
(K) FORMAR UMA LISTA CONTENDO A UNIÃO DOS ELEMENTOS DE DUAS LISTAS.
(L) FORMAR UMA LISTA CONTENDO A INTERSECÇÃO DE DUAS LISTAS.
(M) CRIAR UMA SEGUNDA CÓPIA DE UMA LISTA.
(N) COMBINAR DUAS LISTAS ORDENADAS EM UMA ÚNICA LISTA ORDENADA.
*/
struct no
{
    int info;
    no *next;
};
typedef no* noptr; //ponteiro inteligente

// =========== (A) ========== //
int contar_elementos(noptr lista)
{
    int contador = 0;
    noptr p = lista; //inicio

    while (p !=  NULL)
    {
        contador++;
        p = p -> next; //um passo a frente
    }
    
    return contador;
}

// =========== (B) ========== //
noptr concatenar (noptr lista1, noptr lista2)
{
    noptr nova_lista = NULL;
    noptr p1 = lista1;
    noptr p2 = lista2;
    noptr ultimo = NULL; //guarda o final para inserções eficientes em o(1)

    //copia todos os nós da lista 1
    while (p1 != NULL)
    {
        noptr novo = new no;
        novo -> info = p1 -> info;
        novo -> next = NULL;

        if(nova_lista == NULL)
            nova_lista = novo;
        else
            ultimo -> next = novo;
        
        ultimo = novo;
        p1 = p1 -> next;
    }

    //copia todos os nós da lista 2
    while (p2 != NULL)
    {
        noptr novo = new no;
        novo -> info = p2 -> info;
        novo -> next = NULL;

        if (nova_lista == NULL)
            nova_lista = novo;
        else
            ultimo -> next = novo;

        ultimo = novo;
        p2 = p2 -> next;
    }

    return nova_lista;
}

// =========== (C) ========== //
int eliminar_nesimo (noptr &lista, int n)
{
    if (lista == NULL || n <= 0)
        return -1; //lista vazia ou posição inválida
    
    noptr p = lista;

    //caso especiais - remover o primeiro nó (n = 1)
    if (n == 1)
    {
        lista = lista -> next; //começa no segundo nó
        delete p; //deleta o antigo primeira da memória
        return 0;
    }

    //navegar até achar o predecessor do nó
    for (int i = 1; p != NULL && i < n - 1; i++)
    {
        p = p -> next;
    }

    //indice fora do limite
    if (p == NULL || p -> next == NULL)
        return -1;
    
    noptr remover = p -> next; //identifica o nó 'n'
    p -> next = remover -> next; //predecessor aponta para o sucessor
    delete remover; //delete da memória
    return 0;
}

// =========== (D) ========== //
int soma_elementos (noptr lista)
{
    int soma = 0;
    noptr p = lista;

    while (p != NULL);
    {
        soma += o -> info;
        p = p -> next;
    }

    return soma;
}

// =========== (E) ========== //
void inverter_nos (noptr p1, noptr p2)
{
    if (p1 != NULL && p2 != NULL)
    {
        int temp = p1 -> info;
        p1 -> info = p2 -> info;
        p2 -> info = temp;
    }
}

// =========== (F) ========== //
void deslocar_frente (noptr &lista, noptr p, int n)
{
    if (lista == NULL || p == NULL || n <= 0)
        return;
    
    //encontrar o predecessor de 'p'
    noptr pred = NULL;
    noptr atual = lista;
    
    while (atual != NULL && atual != p)
    {
        pred = atual;
        atual = atual -> next;
    }

    //'p' não foi encontrado
    if (atual == NULL)
        return;

    //desconecta o nó
    if (pred == NULL)
        lista = p -> next; //p era o primneiro
    else
        pred -> next = p -> next;
    
    //caminhar 'n' posição da frente
    noptr marcador = p -> next;
    if (pred == NULL)
        marcador = lista;
    
    if (marcador == NULL)
    {
        if (lista == NULL)
        {
            lista = p;
            p -> next = NULL;
        }
        else
        {
            noptr r = lista;
            
            while (r -> next != NULL)
            {
                r = r -> next;
            }

            r -> next = p;
            p -> next = NULL;
        }
        return;
    }

    //'n - 1' saltos para frentes
    for (int i = 0; marcador -> next != NULL && i < n - 1; i++)
    {
        marcador = marcador -> next;
    }

    //insere 'p' após o nó
    p -> next = marcador -> next;
    marcador -> next = p;
}

// =========== (G) ========== //
void inserir_depois_nesimo (noptr &lista, int n, int x)
{
    if (lista == NULL || n <= 0)
        return;
    
    noptr p = lista;

    //caminha até encontrar o nó
    for (int i = 1; p != NULL && i < n; i++)
    {
        p = p -> next;
    }

    //se o nó destino foi encontrado, insere á direita
    if (p != NULL)
    {
        noptr novo = new no;
        novo -> info = x;

        novo -> next = p -> next;
        p -> next = novo;
    }
}
// =========== (H) ========== //
bool verificar_existencia (noptr lista, int x)
{
    noptr p = lista;

    while (p != NULL)
    {
        if (p -> info == x)
            return true; //achou
        p = p -> next;
    }
    return false; //não achou
}

// =========== (I) ========== //
noptr copiar_lista(noptr lista)
{
    if (lista == NULL)
        return NULL;
    noptr novalista = NULL;
    noptr p = lista;
    noptr ultimo = NULL;

    while (p != NULL)
    {
        noptr novo = new no;
        novo -> info = p -> info;
        novo -> next = NULL;

        if (novalista == NULL)
            novalista = novo;
        else
            ultimo -> next = novo;
        
        ultimo = novo; //atualizar quem é o último
        p = p -> next;
    }
    return novalista;
}
// =========== (J) ========== //
void inverter_lista(noptr &lista)
{
    noptr anterior = NULL; //nó anterior
    noptr atual = lista; //sendo alterado agora
    noptr proximo = NULL; //salva o resto da lista antes de inverter o ponteiro

    while (atual != NULL)
    {
        proximo = atual -> next; //guarda o que vem depois
        atual -> next = anterior; //inverter o elo fisico

        //caminha com os ponteiros auxiliares uma posição para a frente
        anterior = atual;
        atual = proximo;
    }
    lista = anterior; //o novo começo passa a ser o antigo
}

// =========== (K) ========== //
noptr uniao_listas (noptr lista1, noptr lista2)
{
    //criamos uma cópia da primeira lista
    noptr resultado = copiar_lista(lista1);
    noptr p2 = lista2;

    //insere os elementos da lista 2
    while (p2 != NULL)
    {
        if (!verificar_existencia(resultado, p2 -> info))
        {
            noptr novo = new no;
            novo -> info = p2 -> info;
            novo -> next = resultado //coloca no inicio do resultado
            resultado = novo;
        }
        p2 = p2 -> next;
    }
    return resultado;
}

// =========== (L) ========== //
noptr interseccao_listas (noptr lista1, noptr lista2)
{
    noptr resultado = NULL;
    noptr p1 = lista1;

    while (p1 != NULL)
    {
        //se pertence á lista 2 e ainda não foi colocado na nossa resposta
        if(verificar_existencia (lista2, p1 -> info) && !verificar_existencia(resultado, p1 -> info))
        {
            noptr novo = new no;
            novo -> info = p1 -> info;
            novo -> next = resultado; //insere no inicio
            resultado = novo;
        }
        p1 = p1 -> next;
    }
    return resultado;
}

// =========== (M) ========== //
noptr copiar_lista_segundavia (noptr lista)
{
    //chamar o item I
    return (copiar_lista(lista));
}

// =========== (N) ========== //
noptr mesclar_listas_ordenadas(noptr lista1, noptr lista2)
{
    noptr resultado = NULL;
    noptr p1 = lista1;
    noptr p2 = lista2;
    noptr ultimo = NULL;

    while(p1 != NULL && p2 != NULL)
    {
        noptr novo = new no;

        //escolher o menor
        if(p1 -> info <= p2 -> info)
        {
            novo -> info = p1 -> info;
            p1 = p1 -> next; //avança lista 1
        }
        else
        {
            novo -> info = p2 -> info;
            p2 = p2 -> next; //avança lista 2
        }

        novo -> next = p2 - > info;

        if(resultado == NULL)
            resultado = novo;
        else
            ultimo -> next = novo;
        
        ultimo = novo;
    }

    //se a lista 2 acabou primeiro, esvazia o resto da lista 1
    while (p1 != NULL)
    {
        noptr novo = new no;
        novo -> info = p1 -> info;
        novo -> next = NULL;
        ultimo -> next = novo;
        ultimo = novo;
        p1 = p1 -> next;
    }

    //lista 1 acabou primeiro, esvazia o resto da lista 2
    while (p2 != NULL)
    {
        noptr novo = new no;
        novo -> info = p2 -> info;
        novo -> next = NULL;
        ultimo -> next = novo;
        ultimo = novo;
        p2 = p2 -> next;
    }

    return resultado;
}