/*
11. SEJA O PROGRAMA ABAIXO:

STRUCT NO
{
    INT CAMPO1;
    NO *CAMPO2;
};
TYPEDEF NO* NOPTR;

VOID MISTERIO(NOPTR E)
{
    WHILE (E != NULL)
    {
        COUT << E->CAMPO1 << ENDL;
        E = E->CAMPO2;
    }
}

INT MAIN()
{
    NOPTR P1, P2, PW;

    P1 = NEW NO;
    P1->CAMPO1 = 5;
    P1->CAMPO2 = NULL;
    PW = NEW NO;
    PW->CAMPO1 = 7;
    PW->CAMPO2 = P1->CAMPO2;
    P1->CAMPO2 = PW;
    P2 = NEW NO;
    P2->CAMPO2 = PW->CAMPO2;
    P2->CAMPO1 = 15;
    PW->CAMPO2 = P2;

    MISTERIO(P1);

    RETURN 0;
}

(A) DESENHE A LISTA LIGADA GERADA POR ESTE PROGRAMA.
(B) O QUE SERÁ IMPRESSO NA TELA?
*/

/* ========== (A) ==========
       +------------+       +------------+       +-------------+
p1 --> | campo1: 5  |       | campo1: 7  |       | campo1: 15  |
       | campo2: -----------| campo2: -----------| campo2: NULL|
       +------------+       +------------+       +-------------+
                                  ^                     ^
                                  |                     |
                                  pw                    p2

========== (B) ==========
5
7
15
*/