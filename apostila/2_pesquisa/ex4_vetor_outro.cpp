/*
4. SUPONHA QUE UMA TABELA ORDENADA ESTEJA ARMAZENADA COMO UMA LISTA CIRCULAR
COM DOI PONTEIROS EXTERNOS: VETOR E OUTRO, QUE SEGUEM AS SEGUINTES REGRAS:
- VETOR APONTA SEMPRE PARA O NÓ COM O MENOR ELEMENTO
- OUTRO APONTA INICIALMENTE PARA O MESMO NÓ QUE VETOR, MAS DEPOIS APONTA
PARA O ÚLTIMO ELEMENTO ENCONTRADO.
- SE UMA BUSCA FOR MAL-SUCEDIDA, OUTRO APONTA NOVAMENTE PARA O MESMO NÓ
QUE O VETOR.

FAÇA UMA FUNÇÃO EM C++ QUE IMPLEMENTE ESTE MÉTODO E RETORNE UM PONTEIRO
PARA O NÓ RECUPERADO, OU UM PONTEIRO NULO, SE A BUSCA FOR MAL-SUCEDIDA.
SE A TABELA ESTÁ ORDENADA, EXPLIQUE COMO O PONTEIRO OUTRO AJUDA A REDUZIR O
NÚMERO DE COMPARAÇÕES NUMA BUSCA.
*/
noptr busca_otimizada(noptr vetor, noptr &outro, int x)
{
    if (vetor == NULL)
        return NULL;
    noptr p;

    if(x >= outro -> info)
        p = outro; //começa do meio do caminho
    else
        p = vetor; //começa do inicí

    do
    {
        if (p -> info == x)
        {
            outro = p; //atualizar a marcação
            return p;
        }

        if(p -> info > x)
            break; //como está ordenada, se passou de 'x', não acha mais.
        
        p = p -> next;
    } while (p != vetor);

    outro = vetor; //busca mal-sucedida, reseta
    return NULL;
}