//VAMOS CRIAR UM PROGRAMA PARA TESTAR AS ROTINAS CRIADAS NO ARQUIVO eulerian_number.h 
//COMPILAR ESTE PROGRAMA COM O COMANDO: gcc -o eulerian_number eulerian_number.c -O2 -lgmp


//Cabeçalho
#include"eulerian_number.h"
#include<stdio.h>


//Função principal
int main(){

  //Variáveis locais
  int64_t n, k;


  //Procedimentos
    //Recebendo input dos usuários
    printf("[Inteiro] n: ");
    if(scanf("%li", &n)!=1) return 0;
    printf("[Inteiro] k: ");
    if(scanf("%li", &k)!=1) return 0;



    //Computando o n-ésimo número de Catalan
    mpz_t eulerian_number;
    mpz_init(eulerian_number);

    compute_eulerian_number(n, k, eulerian_number);
    printf("A(%li, %li) = ", n, k); gmp_printf("%Zd\n", eulerian_number);

    //Limpando o cachê de memória
    mpz_clear(eulerian_number);
    
 
  //Finalizando a aplicação
  return 0;


}
