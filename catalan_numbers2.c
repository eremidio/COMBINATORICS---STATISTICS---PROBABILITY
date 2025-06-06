//VAMOS CRIAR UM PROGRAMA PARA TESTAR AS ROTINAS CRIADAS NO ARQUIVO catalan_numbers2.h
//COMPILAR ESTE PROGRAMA COM O COMANDO: gcc -o catalan_numbers2 catalan_numbers2.c -O2 -lgmp


//Cabeçalho
#include"catalan_numbers2.h"
#include<stdio.h>


//Função principal
int main(){

  //Variáveis locais
  int64_t n;


  //Procedimentos
    //Recebendo input dos usuários
    printf("[Inteiro] n: ");
    if(scanf("%li", &n)!=1) return 0;


    //Computando o n-ésimo número de Catalan
    mpz_t catalan_number;
    mpz_init(catalan_number);

    compute_nth_catalan_number(n, catalan_number);
    printf("C(%li) = ", n); gmp_printf("%Zd\n", catalan_number);

    //Limpando o cachê de memória
    mpz_clear(catalan_number);
    
 
  //Finalziando a aplicação
  return 0;

}
