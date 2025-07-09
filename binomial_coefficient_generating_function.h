//VAMOS CRIAR UM PROGRAMA QUE COMPUTA COEFICIENTES BINOMIAIS USANDO FUNÇÕES GERADORAS 

/*

EXISTEM VARIÁVEIS FUNÇÕES GERADORAS EM DUAS VARIÁVEIS PARA SE COMPUTAR COEFICIENTES BINOMIAIS.
EXEMPLOS INCLUEM AS FUNÇÕES: Σ C(n, k){x^k}{y^n}= 1/{1-y-xy} E 
ΣC(n, k)[{x^k}{y^n}]/[n!]=exp(y+xy).

TAIS FUNÇÕES PODEM SER USADAS PARA SE COMPUTAR COEFICIENTES BINOMIAIS EM INTERVALOS PEQUENOS
PROVIDO DE EFICIENTES ROTINAS PARA ARITMÉTICA POLINOMIAL.

PARA MAIORES INFORMAÇÕES: https://en.wikipedia.org/wiki/Generating_function


*/


//***********************************************************************************************************************************
//CABEÇALHO
#ifndef BINOMIAL_COEFFICIENT_GENERATING_FUNCTION_H
#define BINOMIAL_COEFFICIENT_GENERATING_FUNCTION_H
#include"bivariate_polynomials.h"


//***********************************************************************************************************************************
//DECLARAÇÕES DE FUNÇÕES
template<typename T>
bivariate_polynomial<T> compute_binomial_coefficients_generating_function(int64_t);


//***********************************************************************************************************************************
//FUNÇÕES
//Função que aroxima afunção geradora dos coeficientes binomiais por um polinômio de duas variáveis
template<typename T>
bivariate_polynomial<T> compute_binomial_coefficients_generating_function(int64_t n){

  //Variáveis locais
  bivariate_polynomial<T> result, mul1, mul2;
  bivariate_monomial<T> poly_bv_term;

  
  //Procedimentos
    //Adicionando os primeiros elementos ao resultado
    poly_bv_term.coefficient=1; poly_bv_term.x_valuation=0; poly_bv_term.y_valuation=0;
    poly_bv_term.valuation=cantor_pairing_function(poly_bv_term.x_valuation, poly_bv_term.y_valuation);
    result.monomials.insert({poly_bv_term.valuation, poly_bv_term});

    //Definindo polinômios intermediários usados no cálculo
    poly_bv_term.coefficient=1; poly_bv_term.x_valuation=0; poly_bv_term.y_valuation=1;
    poly_bv_term.valuation=cantor_pairing_function(poly_bv_term.x_valuation, poly_bv_term.y_valuation);
    mul1.monomials.insert({poly_bv_term.valuation, poly_bv_term});

    poly_bv_term.coefficient=1; poly_bv_term.x_valuation=1; poly_bv_term.y_valuation=1;
    poly_bv_term.valuation=cantor_pairing_function(poly_bv_term.x_valuation, poly_bv_term.y_valuation);
    mul1.monomials.insert({poly_bv_term.valuation, poly_bv_term});


    mul2=mul1;

    //Loop principal: computando parciais das função geradora dos coeficientes binomiais
    for(int64_t i=1; i<=n; ++i){

      result=result+mul2;
      mul2=mul2*mul1;

    };

  
  //Resultado
  return result;

};


//***********************************************************************************************************************************
//FIM DO HEADER
#endif
