/* * * * * * * * * * * * * * * * * * * * * * * * *
 *                                               *
 * Nome : Rafael Escaleira Ferreira dos Santos.  *
 * Universidade Federal do Mato Grosso do Sul    *
 * Disciplina : Estrutura de Dados e Programação *
 *                                               *
 * * * * * * * * * * * * * * * * * * * * * * * * */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <time.h>
#include "abb.h"

/* * * * * * * * * Árvore de Busca Binária (ABB) * * * * * * * * */

int compara (const void * a, const void * b) {
    
    return (* (treg *)a).id - (* (treg *)b).id;
    
}

treg * aloca_reg (int id) {
    
    treg * aux = (treg *) malloc (sizeof (treg));
    aux -> id = id;
    
    return aux;
    
}

void abb_constroi (tarv * parv, int (* cmp) (const void * a, const void * b)) {

    parv -> raiz = NULL; 
    parv -> compara = cmp;

}

int _abb_insere (tarv * parv, tnode * * pnode, void * preg) {

    int ret = 1;

    if (* pnode == NULL) {

        * pnode = (tnode *) malloc (sizeof (tnode));

        if (* pnode == NULL) {
            ret = 0;
        }

        else {

            (* pnode) -> reg = preg;
            (* pnode) -> esq = NULL;
            (* pnode) -> dir = NULL;

        }

    }

    else {

        if (parv -> compara (((* pnode) -> reg), preg) > 0) {

            ret = _abb_insere (parv, &((* pnode) -> esq), preg);

        }

        else {

            ret = _abb_insere (parv, &((* pnode) -> dir), preg);

        }

    }

    return ret;

}


int abb_insere (tarv * parv, void * preg) {

    return _abb_insere (parv, &(parv -> raiz), preg);

}

void * _abb_busca (tarv * parv, tnode * * pnode, void * preg) {

    void * ret;

    if (* pnode == NULL) {

        ret = NULL;

    }

    else if (parv -> compara (((* pnode) -> reg), preg) == 0) {

        ret = (* pnode) -> reg;

    }

    else {

        if (parv -> compara (((* pnode) -> reg), preg) > 0) {

            ret = _abb_busca (parv, &((* pnode) -> esq), preg);

        }

        else {

            ret = _abb_busca(parv,&((*pnode) -> dir), preg);

        }

    }

    return ret;

}

void * abb_busca (tarv * parv, void * preg) {

    return _abb_busca (parv, &(parv -> raiz), preg);

}


tnode * * abb_busca_pont (tarv * parv, tnode * * pnode, void * preg) {

    tnode * * ret;

    if (* pnode == NULL) {

        ret = NULL;

    }

    else if (parv -> compara ((* pnode) -> reg, preg) == 0) {

        ret = pnode;

    }

    else {

        if (parv -> compara (((* pnode) -> reg), preg) > 0) {

            ret = abb_busca_pont (parv, &((* pnode) -> esq), preg);

        }

        else {

            ret = abb_busca_pont (parv, &((* pnode) -> dir), preg);

        }

    }

    return ret;

}

int _abb_remove (tnode * * pnode) {

    int ret = 0;
    tnode * aux;

    if (* pnode != NULL) {

        /* Caso 1 */

        if (((* pnode) -> esq == NULL) && (* pnode) -> dir == NULL) {

            free ((* pnode) -> reg);
            free (* pnode);
            * pnode = NULL;
            ret = 1;

        }

        /* Caso 2 */

        else if ((* pnode) -> esq == NULL && (* pnode) -> dir != NULL) {

            free ((* pnode) -> reg);
            aux = * pnode;
            * pnode = (* pnode) -> dir;
            free (aux);
            ret = 1;

        }

        else if ((* pnode) -> esq != NULL && (* pnode) -> dir == NULL) {

            free ((* pnode) -> reg);
            aux = * pnode;
            * pnode = (* pnode) -> esq;
            free (aux);
            ret = 1;

        }

        /*Caso 3 */

        else {

            /* Sucessor */

            aux = (* pnode) -> dir;
            tnode * * paux = &((* pnode) -> dir);

            while (aux -> esq != NULL) {

                paux = &(aux -> esq);
                aux = aux -> esq;

            }

            free ((* pnode) -> reg);
            (* pnode) -> reg = aux -> reg;
            * paux = aux -> dir;
            free (aux);
            ret = 1;

        }

    }

    return ret;

}

int abb_remove (tarv * parv, void * preg) {

    int ret = 0;
    tnode * * aux = abb_busca_pont (parv, &(parv -> raiz), preg);

    if (aux != NULL) {

        ret = _abb_remove (aux);

    }

    return ret;

}

void _abb_destroi (tnode * pnode) {

    if (pnode != NULL) {

        _abb_destroi (pnode -> esq);
        _abb_destroi (pnode -> dir);
        free (pnode -> reg);
        free (pnode);

    }

}

int abb_destroi (tarv * parv) {

    int ret = 0;

    if (parv -> raiz != NULL) {

        _abb_destroi (parv -> raiz);
        ret = 1;

    }

    return ret;

}

void free_node_abb (tnode * raiz) {
    
    if (raiz != NULL) {
        
        free_node_abb (raiz -> dir);
        free (raiz -> reg);
        free (raiz);
        free_node_abb(raiz -> esq);
        
    }

}

void imprime_arvore_abb (tnode * raiz, int profundidade, int elemento_inserido) {
    
    int anda = 3;
    int i;
    
    if (raiz != NULL) {
        
        imprime_arvore_abb (raiz -> dir, profundidade + anda, elemento_inserido);
        
        for (i = 0; i < profundidade; i ++) {
            
            printf (" ");
            
        }
        
        if ((*(treg *)(raiz -> reg)).id == elemento_inserido) {
            
            cor_texto (verde);
            //estilo_texto (piscar);
            estilo_texto (negrito);
            
        }
        
        else {
            
            estilo_texto (verde);
            
        }
        
        printf ("%d\n", (*(treg *)(raiz -> reg)).id);
        estilo_texto (verde);
        imprime_arvore_abb (raiz -> esq, profundidade + anda, elemento_inserido);
        
    }
    
}

void pre_ordem (tnode * pnode) {
    
    if (pnode != NULL) {
        
        printf ("%d ", (* (treg *) (pnode -> reg)).id);
        pre_ordem (pnode -> esq);
        pre_ordem (pnode -> dir);
        
    }
    
}

void in_ordem (tnode * pnode) {
    
    if (pnode != NULL) {
        
        in_ordem (pnode -> esq);
        printf ("%d ", (* (treg *) (pnode -> reg)).id);
        in_ordem (pnode -> dir);
        
    }
    
}

void pos_ordem (tnode * pnode) {
    
    if (pnode != NULL) {
        
        pos_ordem (pnode -> esq);
        pos_ordem (pnode -> dir);
        printf ("%d ",(* (treg *) (pnode -> reg)).id);
        
    }

}

/* * * * * * * * * * * * * * * Funções de Teste * * * * * * * * * * * * * * */

void teste_constroi_abb () {

    int a, b;
    tarv arv;

    abb_constroi (&arv, &compara);

    a = 10;
    b = 20;

    assert (arv.raiz == NULL);
    assert (arv.compara (&a, &b) == - 10);
    assert (arv.compara (&b, &a) == 10);
    assert (arv.compara (&b, &b) == 0);
    assert (arv.compara (&a, &a) == 0);

    abb_destroi (&arv);

    cor_texto (ciano);
    printf("\t*");
    estilo_texto (resetar);

    cor_texto (vermelho);
    printf("         * ");
    estilo_texto (resetar);

    printf ("Construção ABB ");
    cor_texto (verde);
    printf("                OK");
    estilo_texto (resetar);

    cor_texto (ciano);
    printf("       *\n");
    estilo_texto (resetar);

}

void teste_insere_abb () {

    int v[] = {30, 15, 50, 7, 20, 35, 55};
    int n = sizeof(v) / sizeof(v[0]);
    int i;
    tarv arv;

    abb_constroi (&arv, &compara);
    
    for (i = 0; i < n; i ++) {

        abb_insere (&arv, aloca_reg (v[i]));

    }
    
    tnode * pnode = arv.raiz;
    treg * aux = (treg *) malloc (sizeof (treg));

    aux -> id = 30;
    assert (compara (pnode -> reg, aux) == 0);
    aux -> id = 15;
    assert (compara (pnode -> esq -> reg, aux) == 0);
    aux -> id = 50;
    assert (compara (pnode -> dir -> reg, aux) == 0);
    aux -> id = 7 ;
    assert (compara (pnode -> esq -> esq -> reg, aux) == 0);
    aux -> id = 20;
    assert (compara (pnode -> esq -> dir -> reg, aux) == 0);
    aux -> id = 35;
    assert (compara (pnode -> dir -> esq -> reg, aux) == 0);
    aux -> id = 55;
    assert (compara (pnode -> dir -> dir -> reg, aux) == 0);

    assert (pnode -> esq -> esq -> esq == NULL);
    assert (pnode -> esq -> esq -> dir == NULL);
    assert (pnode -> esq -> dir -> esq == NULL);
    assert (pnode -> esq -> dir -> dir == NULL);
    assert (pnode -> dir -> esq -> esq == NULL);    
    assert (pnode -> dir -> esq -> dir == NULL);    
    assert (pnode -> dir -> dir -> dir == NULL);
    assert (pnode -> dir -> dir -> esq == NULL);
    
    abb_destroi (&arv);

    cor_texto (ciano);
    printf("\t*");
    estilo_texto (resetar);

    cor_texto (vermelho);
    printf("         * ");
    estilo_texto (resetar);

    printf ("Inserção ABB ");
    cor_texto (verde);
    printf("                  OK");
    estilo_texto (resetar);

    cor_texto (ciano);
    printf("       *\n");
    estilo_texto (resetar);

}

void teste_busca_abb () {

    int v[] = {30, 15, 50, 7, 20, 35, 55};
    int n = sizeof(v) / sizeof(v[0]);
    int i;
    tarv arv;

    abb_constroi (&arv, &compara);
    
    for (i = 0; i < n; i ++) {

        abb_insere (&arv, aloca_reg (v[i]));

    }
   
    tnode * pnode = arv.raiz;
    treg * aux = (treg *) malloc (sizeof (treg));
    treg * aux_busca = (treg *) malloc (sizeof (treg));

    aux -> id = 0;

    aux_busca = abb_busca (&arv, aux);
    assert (aux_busca == NULL);

    aux -> id = 30;

    aux_busca = abb_busca (&arv, aux);
    assert (compara (pnode -> reg, aux_busca) == 0);

    aux -> id = 15;

    aux_busca = abb_busca (&arv, aux);
    assert (compara (pnode -> esq -> reg, aux_busca) == 0);

    aux -> id = 50;

    aux_busca = abb_busca (&arv, aux);
    assert (compara (pnode -> dir -> reg, aux_busca) == 0);

    aux -> id = 7;

    aux_busca = abb_busca (&arv, aux);
    assert (compara (pnode -> esq -> esq -> reg, aux_busca) == 0);

    aux -> id = 20;

    aux_busca = abb_busca (&arv, aux);
    assert (compara (pnode -> esq -> dir -> reg, aux_busca) == 0);

    aux -> id = 35;

    aux_busca = abb_busca (&arv, aux);
    assert (compara (pnode -> dir -> esq -> reg, aux_busca) == 0);

    aux -> id = 55;

    aux_busca = abb_busca (&arv, aux);
    assert (compara (pnode -> dir -> dir -> reg, aux_busca) == 0);

    cor_texto (ciano);
    printf("\t*");
    estilo_texto (resetar);

    cor_texto (vermelho);
    printf("         * ");
    estilo_texto (resetar);

    printf ("Busca ABB ");
    cor_texto (verde);
    printf("                     OK");
    estilo_texto (resetar);

    cor_texto (ciano);
    printf("       *\n");
    estilo_texto (resetar);

}

void teste_remove_abb () {

    int v[] = {30, 15, 50, 7, 20, 35, 55};
    int n = sizeof(v) / sizeof(v[0]);
    int i;
    tarv arv;

    abb_constroi (&arv, &compara);
    
    for (i = 0; i < n; i ++) {

        abb_insere (&arv, aloca_reg (v[i]));

    }
    
    tnode * pnode = arv.raiz;
    treg * aux = (treg *) malloc (sizeof (treg));

    aux -> id = 0 ;

    assert (abb_remove (&arv, aux) == 0);
    
    aux -> id = 55;

    assert (abb_remove (&arv, aux) == 1);
    assert (pnode -> dir -> dir == NULL);
    
    aux -> id = 30;

    assert (compara (pnode -> reg, aux) == 0);

    aux -> id = 15;

    assert (compara (pnode -> esq -> reg, aux) == 0);

    aux -> id = 50;

    assert (compara (pnode -> dir -> reg, aux) == 0);

    aux -> id = 7;

    assert (compara (pnode -> esq -> esq -> reg, aux) == 0);

    aux -> id = 20;

    assert (compara (pnode -> esq -> dir -> reg, aux) == 0);

    aux -> id = 35;

    assert (compara (pnode -> dir -> esq -> reg, aux) == 0);
    assert (pnode -> esq -> esq -> esq == NULL);
    assert (pnode -> esq -> esq -> dir == NULL);
    assert (pnode -> esq -> dir -> esq == NULL);
    assert (pnode -> esq -> dir -> dir == NULL);
    assert (pnode -> dir -> esq -> esq == NULL);    
    assert (pnode -> dir -> esq -> dir == NULL);    

    aux -> id = 15;

    assert (abb_remove (&arv, aux) == 1);
    assert (pnode -> esq -> dir == NULL);
    
    aux -> id = 30;

    assert (compara (pnode -> reg, aux) == 0);

    aux -> id = 20;

    assert (compara (pnode -> esq -> reg, aux) == 0);

    aux -> id = 50;

    assert (compara (pnode -> dir -> reg, aux) == 0);

    aux -> id = 7;

    assert (compara (pnode -> esq -> esq -> reg, aux) == 0);

    aux -> id = 35;

    assert (compara (pnode -> dir -> esq -> reg, aux) == 0);
    assert (pnode -> esq -> esq -> esq == NULL);
    assert (pnode -> esq -> esq -> dir == NULL);
    assert (pnode -> dir -> esq -> esq == NULL);    
    assert (pnode -> dir -> esq -> dir == NULL);    
 
    abb_insere (&arv, aloca_reg (40));

    aux -> id = 30;

    assert (abb_remove (&arv, aux) == 1);

    aux -> id = 35;

    assert (compara (pnode -> reg, aux) == 0);

    aux -> id = 20;

    assert (compara (pnode -> esq -> reg, aux) == 0);

    aux -> id = 50;

    assert (compara (pnode -> dir -> reg, aux) == 0);

    aux -> id = 7;

    assert (compara (pnode -> esq -> esq -> reg, aux) == 0);

    aux -> id = 40;

    assert (compara (pnode -> dir -> esq -> reg, aux) == 0);
    assert (pnode -> esq -> esq -> esq == NULL);
    assert (pnode -> esq -> esq -> dir == NULL);
    assert (pnode -> dir -> esq -> esq == NULL);    
    assert (pnode -> dir -> esq -> dir == NULL);    
    assert (pnode -> esq -> dir  == NULL);
    assert (pnode -> dir -> dir  == NULL);

    aux -> id = 20;

    assert (abb_remove (&arv, aux) == 1);

    aux -> id = 35;

    assert (compara (pnode -> reg, aux) == 0);

    aux -> id = 7;

    assert (compara (pnode -> esq -> reg, aux) == 0);

    aux -> id = 50;

    assert (compara (pnode -> dir -> reg, aux) == 0);

    aux -> id = 40;

    assert (compara (pnode -> dir -> esq -> reg, aux) == 0);
    assert (pnode -> esq -> esq == NULL);
    assert (pnode -> esq -> dir == NULL);
    assert (pnode -> dir -> esq -> esq == NULL);    
    assert (pnode -> dir -> esq -> dir == NULL);    

    aux -> id = 50;

    assert (abb_remove (&arv, aux) == 1);

    aux -> id = 35;

    assert (compara (pnode -> reg, aux) == 0);

    aux -> id = 7;

    assert (compara (pnode -> esq -> reg, aux) == 0);

    aux -> id = 40;

    assert (compara (pnode -> dir -> reg, aux) == 0);

    assert (pnode -> esq -> esq == NULL);
    assert (pnode -> esq -> dir == NULL);
    assert (pnode -> dir -> esq == NULL);    
    assert (pnode -> dir -> dir == NULL);    

    aux -> id = 35;

    assert (abb_remove (&arv, aux) == 1);

    aux -> id = 40;

    assert (compara (pnode -> reg, aux) == 0);

    aux -> id = 7 ;

    assert (compara (pnode -> esq -> reg, aux) == 0);
    assert (pnode -> esq -> esq == NULL);
    assert (pnode -> esq -> dir == NULL);
    assert (pnode -> dir == NULL);    

    aux -> id = 40;

    assert (abb_remove (&arv, aux) == 1);

    aux -> id = 7 ;

    assert (compara (arv.raiz -> reg, aux) == 0);
    assert (arv.raiz -> esq == NULL);
    assert (arv.raiz -> dir == NULL);    

    aux -> id = 7;

    assert (abb_remove (&arv, aux) == 1);
    assert (arv.raiz == NULL);
    assert (abb_destroi (&arv) == 0);

    cor_texto (ciano);
    printf("\t*");
    estilo_texto (resetar);

    cor_texto (vermelho);
    printf("         * ");
    estilo_texto (resetar);

    printf ("Remoção ABB ");
    cor_texto (verde);
    printf("                   OK");
    estilo_texto (resetar);

    cor_texto (ciano);
    printf("       *\n");
    estilo_texto (resetar);

}

void teste_tempo_execucao (int n) {

	clock_t inicio, fim;
    double tempo [2], insersao [4], remocao [4];
    tarv arv;
    treg * aux;
    int i, * v;

    srand (time (NULL));

    v = (int *) malloc (n * sizeof (int));
    
    for (i = 0; i < n; i ++) {

    	* (v + i) = rand () % (n * 4);

    }
    
    cor_texto (ciano);
    printf ("\t* * * * * * * * ");
    estilo_texto (resetar);

    cor_texto (amarelo);
    printf("TEMPO DE EXECUÇÃO (TESTE)");
    estilo_texto (resetar);

    cor_texto (ciano);
    printf (" * * * * * *\n");
    printf("\t*                                                   *\n");
    printf ("\t*           ");
    estilo_texto (resetar);

    cor_texto (vermelho);
    printf("Quantidade de Elementos : %d", n);
    estilo_texto (resetar);

    cor_texto (ciano);
    printf ("\t    *\n");
    printf("\t*                                                   *\n");
    estilo_texto (resetar);

    /* Árvore de Busca Binária */

    abb_constroi (&arv, &compara);

    aux = (treg *) malloc (sizeof (treg));
    inicio = clock ();

    for (i = 0; i < n; i ++) {

        abb_insere (&arv, aloca_reg (* (v + i)));

    }

    fim = clock ();
    tempo [0] = ( (double) (fim - inicio) ) / CLOCKS_PER_SEC;

    inicio = clock ();

    for (i = 0; i < n; i ++) {

        aux = arv.raiz -> reg;
        abb_remove (&arv, aloca_reg (aux -> id));

    } 

    fim = clock ();
    tempo [1] = ( (double) (fim - inicio) ) / CLOCKS_PER_SEC;

    insersao [0] = tempo [0];
    remocao [0] = tempo [1];

    free_node_abb (arv.raiz);

    cor_texto (ciano);
    printf("\t*");
    estilo_texto (resetar);

    cor_texto (verde);
    printf ("\t  * ");
    cor_texto (magenta);
    printf ("ABB ");
    estilo_texto (resetar);
    printf ("Inserção : %.6lf segundos\t", insersao [0]);

    cor_texto (ciano);
    printf("    *\n");
    estilo_texto (resetar);

    cor_texto (ciano);
    printf("\t*");
    estilo_texto (resetar);

    cor_texto (verde);
    printf ("\t  * ");
    cor_texto (magenta);
    printf ("ABB ");
    estilo_texto (resetar);
    printf ("Remoção  : %.6lf segundos\t", remocao [0]);

    cor_texto (ciano);
    printf("    *\n");
    estilo_texto (resetar);

    cor_texto (ciano);
    printf("\t*                                                   *\n");
    printf("\t* * * * * * * * * * * * * * * * * * * * * * * * * * *\n\n");
    estilo_texto (resetar);

    free (v);

}
