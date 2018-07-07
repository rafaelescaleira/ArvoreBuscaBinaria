/* * * * * * * * * * * * * * * * * * * * * * * * *
 *                                               *
 * Nome : Rafael Escaleira Ferreira dos Santos.  *
 * Universidade Federal do Mato Grosso do Sul    *
 * Disciplina : Estrutura de Dados e Programação *
 *                                               *
 * * * * * * * * * * * * * * * * * * * * * * * * */

#ifndef _ABB_H_
#define _ABB_H_

/* * * * * * * * * * * Cores * * * * * * * * * * */

#define cor_texto(cor) cor
#define estilo_texto(estilo_texto_) estilo_texto_

/* * * * * * * * * Cor do Texto * * * * * * * * * */

#define preto printf("\033[30m") 
#define vermelho printf("\033[31m") 
#define verde printf("\033[32m") 
#define amarelo printf("\033[33m") 
#define azul printf("\033[34m") 
#define magenta printf("\033[35m") 
#define ciano printf("\033[36m") 
#define branco printf("\033[37m") 
#define normal printf("\033[39m") 

/* * * * * * * * Estilo do Texto * * * * * * * * */

#define negrito printf("\033[1m")
#define fosco printf("\033[2m")
#define estilo_normal printf("\033[22m")
#define resetar printf("\033[0m")
#define sublinhado printf("\033[4m")
#define piscar printf("\033[5m")
#define italico printf("\033[3m")
#define negativo printf("\033[7m")

/* * * * * * * * * * Registros * * * * * * * * * */

typedef struct _reg{
    
    int id;
    int idade;
    int RGA;
    
} treg;

typedef struct _node {

    void * reg;
    struct _node * esq;
    struct _node * dir;

} tnode;

typedef struct _arv {

    tnode * raiz;
    int (* compara)(const void * a, const void * b);

} tarv;

/* * * * * * * * * Funções * * * * * * * * * * */

int compara (const void * a, const void * b);

treg * aloca_reg (int id);

void abb_constroi (tarv * parv, int (* cmp) (const void * a, const void * b));

int abb_insere (tarv * parv, void * preg);

int abb_remove (tarv * parv, void * preg);

void free_node_abb (tnode * raiz);

void imprime_arvore_abb (tnode * raiz, int profundidade, int elemento_inserido);

void pre_ordem (tnode * pnode);

void in_ordem (tnode * pnode);

void pos_ordem (tnode * pnode);

/* * * * * * * Funções (Teste) * * * * * * * */

void teste_constroi_abb ();

void teste_insere_abb ();

void teste_busca_abb ();

void teste_remove_abb ();

void teste_tempo_execucao (int n);

#endif
