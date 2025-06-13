//VAMOS CRIAR UM PROGRAMA QUE COMPUTA NÚMEROS EULERIANOS USANDO COEFICIENTES BINOMIAIS

/*

PARA MAIORES INFORMAÇÕES: https://github.com/eremidio/COMBINATORICS---STATISTICS---PROBABILITY/blob/main/eulerian_triangle.h

*/


//********************************************************************************************************************
//CABEÇALHO
#ifndef EULERIAN_NUMBER_H
#define EULERIAN_NUMBER_H
#include<stdlib.h>
#include<stdint.h>
#include<stdio.h>
#include<gmp.h>


//********************************************************************************************************************
//DECLARAÇÃO DE FUNÇÕES
void binomial_coefficient(int64_t n, int64_t m, mpz_t C);
void compute_eulerian_number(int64_t n, int64_t k, mpz_t A_nk);


//********************************************************************************************************************
//FUNÇÔES
//Função quem computa coeficientes binomiais 
void binomial_coefficient(int64_t n, int64_t m, mpz_t C){

  //Restrição
  if(m>n){
    printf("Argumentos inválidos.\n");
    return;
  }

  //Variáveis locais
  mpz_t r, v1, v2, v3, v4, v5;
  int64_t k=(n-m);


  //Procedimentos

    //Inicializando variáveis GMP
    mpz_init(r); mpz_init(v1);
    mpz_init(v2); mpz_init(v3);
    mpz_init(v4); mpz_init(v5);
    mpz_set_ui(r, 1);

    
    //Loop principal
    for(int64_t i=1; i<=k; ++i){

      mpz_set_si(v2, (m+i));
      mpz_set_si(v3, i);    

      mpz_mul(v4, r, v2);
      mpz_div(v5, v4, v3);

      mpz_set(r, v5);
  

    }

    //Resultado
    mpz_set(C, r);


    //Limpando o cachê de memória
    mpz_clear(r); mpz_clear(v1);
    mpz_clear(v2); mpz_clear(v3);
    mpz_clear(v4); mpz_clear(v5);

};

//Função que computa números Eulerianos
void compute_eulerian_number(int64_t n, int64_t k, mpz_t A_nk){

  //Variáveis locais
  mpz_t v1, v2, v3, v4, v5, sum, one, N;
  int64_t j;
  

  //Inicializando variáveis gmp
  mpz_init(v1); mpz_init(v2); mpz_init(v3); 
  mpz_init(v4); mpz_init(v5); mpz_init(sum); 


  //Procedimento
    //Ajuste de variáveis

    mpz_set_si(sum, 0);



    //Loop principal: calculando as parcelas da soma
    for(j=0; j<=(k+1); ++j){

      binomial_coefficient((n+1), j, v1);
      mpz_set_si(v2, (k-j+1));
      mpz_pow_ui(v3, v2, n);

      mpz_mul(v4, v1, v3);    

      if(j&1) mpz_sub(v5, sum, v4);
      else mpz_add(v5, sum, v4);
      mpz_set(sum, v5);

   }


  //Resultado
  mpz_set(A_nk, sum);


  //Limpando o cachê de memória
  mpz_clear(v1); mpz_clear(v2); mpz_clear(v3); 
  mpz_clear(v4); mpz_clear(v5); mpz_clear(sum);


};


//********************************************************************************************************************
//FIM DO HEADER
#endif
