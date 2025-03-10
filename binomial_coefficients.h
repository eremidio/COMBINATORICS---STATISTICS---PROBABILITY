//VAMOS CRIAR UM PROGRAMA QUE COMPUTA COEFICIENTES BINOMIAIS 

/*

O COEFICIENTE BINOMIAL C(n,m) É DEFINIDO PELA RELAÇÃO C(n,m)=n!/[m!(n-m)!].
ESTA RELAÇÃO PODE SER SIMPLICADA USANDO O FATO DE QUE n!/m!=(m+1)(m+2)...(n-1)n PARA n>m. USANDO ESSA RELAÇÃO PODEMOS SIMPLIFICAR
O CÁLCULO DE C(n,m), TOMANDO C(n,m)=(m+1)(m+2)...(n-1)n/(n-m)!=[(m+1)/1][(m+2)/2]...[(m+(n-m))/(n-m)]. OU SEJA C(n,m)= Π[(n+i)/i]
= Π[1+(n/i)] PARA i=1,2,3,...,(n-k). PODEMOS USAR A RELAÇÃO C(n, m)= C(n, (n-m)) PARA MINIMIZAR O NÚMERO DE OPERAÇÕES.

TAL PROCEDIMENTO TEM A VANTAGEM DE REDUZIR O NÚMERO DE MULTIPLICAÇÕES NECESSÁRIOS PARA COMPUTAR C(n, m) E EVITAR PROBLEMAS COMO
OVERFLOW EM CÁLCULOS INTERMEDIÁRIOS. TAIS FÓRMULAS PODEM SER USADAS PARA CÁLCULOS EXATOS OU PARA APROXIMAÇÕES USANDO APROXIMAÇÕES
DE NÚMEROS REAIS.

PARA MAIORES INFORMAÇÕES: https://www.ime.usp.br/~cris/aulas/20_2_122/programas/binomial/s667_binomial.pdf


*/


//********************************************************************************************************************
// CABEÇALHO
#ifndef BINOMIAL_COEFFICIENT_H
#define BINOMIAL_COEFFICIENT_H
#include<gmp.h>
#include<stdint.h>
#include<stdio.h>

//********************************************************************************************************************
//DECLARAÇÃO DE FUNÇÕES
void binomial_coefficient(int64_t, int64_t);


//********************************************************************************************************************
//FUNÇÕES
//Função que computa coeficientes binomiais
void binomial_coefficient(int64_t n, int64_t m){

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

    //Exibindo o resultado do cálculo
    printf("C(%li, %li) = ", n, m); gmp_printf("%Zd\n", r);



    //Limpando o cachê de memória
    mpz_clear(r); mpz_clear(v1);
    mpz_clear(v2); mpz_clear(v3);
    mpz_clear(v4); mpz_clear(v5);

};


//********************************************************************************************************************
//FIM DO HEADER
#endif
