//VAMOS CRIAR UMA ROTINA PARA COMPUTAR NÚMEROS DE CATALAN USANDO COEFICIENTES BINOMIAIS

/*

PARA MAIORES INFORMAÇÕES: https://github.com/eremidio/COMBINATORICS---STATISTICS---PROBABILITY/blob/main/catalan_numbers.h

*/


//********************************************************************************************************************************
//CABEÇALHO
#ifndef CATALAN_NUMBERS2_H
#define CATALAN_NUMBERS2_H
#include<stdint.h>
#include<stdlib.h>
#include<stdio.h>
#include<gmp.h>


//********************************************************************************************************************************
//DECLARAÇÃO DE FUNÇÕES
void compute_nth_catalan_number(int64_t, mpz_t);

//********************************************************************************************************************************
//FUNÇÕES
//Função que computa o i-ésimo número de Catalan
void compute_nth_catalan_number(int64_t n, mpz_t catalan_number){


  //Variáveis locais
  mpz_t r, v1, v2, v3, v4, v5;
  

  //Procedimentos
    //Inicializando variáveis GMP
    mpz_init(r); mpz_init(v1);
    mpz_init(v2); mpz_init(v3);
    mpz_init(v4); mpz_init(v5);
    mpz_set_ui(r, 1);

    
    //Loop principal: computando o coeficiente binomial c(2n, n)
    for(int64_t i=1; i<=n; ++i){

      mpz_set_si(v2, (n+i));
      mpz_set_si(v3, i);    

      mpz_mul(v4, r, v2);
      mpz_div(v5, v4, v3);

      mpz_set(r, v5);
 
    }

    //Calculando o n-ésimo número de Catalan C(n)={1/(n+1)}c(2n, n)
    mpz_set_si(v1, (n+1));
    mpz_div(catalan_number, r, v1);

    //Limpando o cachê de memória
    mpz_clear(r); mpz_clear(v1);
    mpz_clear(v2); mpz_clear(v3);
    mpz_clear(v4); mpz_clear(v5);

};


//********************************************************************************************************************************
//FIM DO HEADER
#endif 
