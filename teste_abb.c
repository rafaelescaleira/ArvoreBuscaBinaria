/* * * * * * * * * * * * * * * * * * * * * * * * *
 *                                               *
 * Nome : Rafael Escaleira Ferreira dos Santos.  *
 * Universidade Federal do Mato Grosso do Sul    *
 * Disciplina : Estrutura de Dados e Programação *
 *                                               *
 * * * * * * * * * * * * * * * * * * * * * * * * */

#include <stdio.h>
#include <stdlib.h>
#include "abb.h"

int main (void) {

	cor_texto (ciano);
    printf ("\n\t* * * * * * * * ");
    estilo_texto (resetar);

    cor_texto (amarelo);
    printf ("CONFERE FUNCIONAMENTO");
    estilo_texto (resetar);

    cor_texto (ciano);
    printf (" * * * * * * * *\n\t*                                                   *\n");
    estilo_texto (resetar);

    teste_constroi_abb ();
	teste_insere_abb ();
	teste_busca_abb ();
	teste_remove_abb ();

	cor_texto (ciano);
    printf ("\t*                                                   *\n\t* * * * * * * * * * * * * * * * * * * * * * * * * * *\n\n");
    estilo_texto (resetar);

    teste_tempo_execucao (1000000);

}
