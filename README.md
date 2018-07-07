Árvore de Busca Binária (Genérica)
==================================
Esse repositório possui funções implementadas em linguagem C.
Segue a lista das funções :

* Inserção;
* Remoção;
* Busca;

Instruções para Compilação
--------------------------
Para compilar `` abb.c `` com `` teste_abb.c `` , ou seja, caso deseja testar o código de `` abb.c `` :

* `` ~$ gcc abb.c teste_abb.c -Wall -std=c99 -pedantic ``

Para compilar `` abb.c `` com `` main.c `` , ou seja, caso deseja executar o código e realizar seus próprios testes :

* `` ~$ gcc abb.c main.c -Wall -std=c99 -pedantic ``

Instruções para Execução
------------------------
Para executar o arquivo já compilado com `` teste_abb.c `` :

* `` ~$ ./a.out ``

Para executar o arquivo já compilado com `` main.c `` :

* `` ~$ ./a.out ``
* `` ~$ ./a.out < arquivo_entrada.txt ``

Desempenho da Árvore de Busca Binária
-------------------------------------

Quanto tempo gastam os algoritmos de busca, inserção e remoção ? É claro que esse tempo é limitado pelo número de nós, digamos n, da árvore (pois nenhum nó é visitado mais que 3 vezes). Mas esta é uma resposta muito grosseira. Eis uma resposta mais fina: no pior caso, qualquer dos algoritmos gasta uma quantidade de tempo proporcional à altura da árvore.

Conclusão: interessa trabalhar sempre com árvores balanceadas, ou seja, árvores que têm altura próxima a log n, isto é, árvores em que todas as folhas têm aproximadamente a mesma profundidade.

Infelizmente não é fácil fazer isso. A altura da árvore é sujeita a chuvas e trovoadas. É muito fácil construir um exemplo em que uma árvore começa com altura próxima de log n mas depois de algumas inserções azaradas fica com altura muito mais próxima de n-1 (claro que o valor de n muda ao longo desse processo).

Os algoritmos de inserção e remoção descritos acima não produzem árvores balanceadas. Se a função insere for repetidamente aplicada a uma árvore balanceada, o resultado pode ser uma árvore bastante desbalanceada. Algo análogo pode acontecer depois de uma sequência de chamadas da função remove.

Para enfrentar essa situação é preciso inventar algoritmos bem mais sofisticados e complexos de inserção e remoção; esses algoritmos fazem um rebalanceamento da árvore após cada inserção e cada remoção. Vou apenas citar dois termos técnicos pitorescos: há um pacote de algoritmos de inserção e remoção que produz árvores AVL; há um outro pacote que produz árvores rubro-negras.

Execução do Programa (Teste)
----------------------------
![grab-landing-page](https://j.gifs.com/APGABz.gif)

Execução do Programa (Principal)
--------------------------------
![grab-landing-page](https://j.gifs.com/xvE9Pr.gif)
