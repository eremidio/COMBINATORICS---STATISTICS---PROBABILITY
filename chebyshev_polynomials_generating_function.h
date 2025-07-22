//VAMOS CRIAR UM PROGRAMA QUE COMPUTA POLINÔMIOS DE CHEBYSHEV USANDO FUNÇÕES GERADORAS

/*

POLINÔMIOS DE CHEBYSHEV PODEM SER EXPRESSOS POR MEIO DE SEQUÊNCIAS DE LUCAS DOS PRIMEIRO E SEGUNDO TIPO. DESTA FORMA AS 
SEQUÊNCIAS DE POLINÔMIOS U(n, x) E T(n, x) PODEM SER OBTIDAS POR MEIO DE FUNÇÕES GERADORAS SIMILARES AS FUNÇÕES 
GERADORAS PARA OS TERMOS DE SEQUÊNCIAS DE LUCAS. MAIS ESPECIFICAMENTE VALE AS SEGUINTES IDENTIDADES PARA n INTEIRO:

Σ T(n, x){x^n}={1-tx}/{1-2tx+t²}
Σ U(n, x){x^n}={1}/{1-2tx+t²}

TAIS IDENTIDADES SÃO ÚTEIS PARA COMPUTAR TERMOS DE AMBAS DAS SEQUÊNCIAS EM PEQUENOS INTERVALOS PROVIDO DE EFICIENTES 
ROTINAS PARA ARITMÉTICA POLINOMIAL.

PARA MAIORES INFORMAÇÕES: https://mathworld.wolfram.com/ChebyshevPolynomialoftheFirstKind.html
                          https://mathworld.wolfram.com/ChebyshevPolynomialoftheSecondKind.html
                          https://en.wikipedia.org/wiki/Chebyshev_polynomials#Explicit_expressions

*/ 


//************************************************************************************************************************
//CABEÇALHO
#ifndef CHEBYSHEV_POLYNOMIAL_GENERATING_FUNCTION_H
#define CHEBYSHEV_POLYNOMIAL_GENERATING_FUNCTION_H
#include"bivariate_univariate_polynomial_conversion.h"


//************************************************************************************************************************
//DECLARAÇÃO DE FUNÇÕES
template<typename T>
bivariate_polynomial<T> compute_first_kind_chebyshev_polynomial_generating_function(int64_t);

template<typename T>
bivariate_polynomial<T> compute_second_kind_chebyshev_polynomial_generating_function(int64_t);


//************************************************************************************************************************
//FUNÇÕES
//Função que computa uma aproximação polinomial para a função geradora de polinômios de Chebyshev do primeiro tipo
template<typename T>
bivariate_polynomial<T> compute_first_kind_chebyshev_polynomial_generating_function(int64_t n){

  //Variáveis locais
  bivariate_polynomial<T> result, multiplier, p1;
  bivariate_monomial<T> poly_bv_term;


  //Procedimentos
    //Computando os polinômios intermediários usados no cálculo
    poly_bv_term.coefficient=(-1); poly_bv_term.x_valuation=1; poly_bv_term.y_valuation=1;
    poly_bv_term.valuation=cantor_pairing_function(poly_bv_term.x_valuation, poly_bv_term.y_valuation);
    result.monomials.insert({poly_bv_term.valuation, poly_bv_term});
    poly_bv_term.coefficient=1; poly_bv_term.x_valuation=0; poly_bv_term.y_valuation=0;
    poly_bv_term.valuation=cantor_pairing_function(poly_bv_term.x_valuation, poly_bv_term.y_valuation);
    result.monomials.insert({poly_bv_term.valuation, poly_bv_term});//p(x, y)=1-xy

    p1=result;

    poly_bv_term.coefficient=(-1); poly_bv_term.x_valuation=0; poly_bv_term.y_valuation=2;
    poly_bv_term.valuation=cantor_pairing_function(poly_bv_term.x_valuation, poly_bv_term.y_valuation);
    multiplier.monomials.insert({poly_bv_term.valuation, poly_bv_term});
    poly_bv_term.coefficient=2; poly_bv_term.x_valuation=1; poly_bv_term.y_valuation=1;
    poly_bv_term.valuation=cantor_pairing_function(poly_bv_term.x_valuation, poly_bv_term.y_valuation);
    multiplier.monomials.insert({poly_bv_term.valuation, poly_bv_term});//p(x, y)=2xy-y²

    //Loop principal
    for(int64_t i=0; i<=n; ++i){
      p1=p1*multiplier;
      result=result+p1;
    }


  //Resultado
  return result;

};

//Função que computa uma aproximação polinomial para a função geradora de polinômios de Chebyshev do segundo tipo
template<typename T>
bivariate_polynomial<T> compute_second_kind_chebyshev_polynomial_generating_function(int64_t n){

  //Variáveis locais
  bivariate_polynomial<T> result, multiplier, p1;
  bivariate_monomial<T> poly_bv_term;


  //Procedimentos
    //Computando os polinômios intermediários usados no cálculo
    poly_bv_term.coefficient=1; poly_bv_term.x_valuation=0; poly_bv_term.y_valuation=0;
    poly_bv_term.valuation=cantor_pairing_function(poly_bv_term.x_valuation, poly_bv_term.y_valuation);
    result.monomials.insert({poly_bv_term.valuation, poly_bv_term});//p(x, y)=1

    p1=result;

    poly_bv_term.coefficient=(-1); poly_bv_term.x_valuation=0; poly_bv_term.y_valuation=2;
    poly_bv_term.valuation=cantor_pairing_function(poly_bv_term.x_valuation, poly_bv_term.y_valuation);
    multiplier.monomials.insert({poly_bv_term.valuation, poly_bv_term});
    poly_bv_term.coefficient=2; poly_bv_term.x_valuation=1; poly_bv_term.y_valuation=1;
    poly_bv_term.valuation=cantor_pairing_function(poly_bv_term.x_valuation, poly_bv_term.y_valuation);
    multiplier.monomials.insert({poly_bv_term.valuation, poly_bv_term});//p(x, y)=2xy-y²

    //Loop principal
    for(int64_t i=0; i<=n; ++i){
      p1=p1*multiplier;
      result=result+p1;
    }


  //Resultado
  return result;

};


//************************************************************************************************************************
//FIM DO HEADER
#endif

