//VAMOS CRIAR UM PROGRAMA QUE IMPLEMENTA ROTINAS PARA COMPUTAR FUNÇÕES GERADORAS DE QUADRDADOS E CUBOS PERFEITOS

/*

A SEQUÊNCIA DE NÚMEROS QUADRADOS PERFEITOS 1, 4, 9, 16,... E A SEQUÊNCIA DE CUBOS PERFEITOS 1, 8, 27, 64, ... PODE SER
OBTIDA POR MEIOS DAS SEGUINTES FUNÇÕES GERADORAS: Σ n²{x^n}= [x(x+1)]/[(1-x)³] E Σ n³{x^n}= [x(x²+4x+1)]/[(1-x)⁴].

TAIS IDENTIDADES PODEM SER OBTIDAS A PARTIR DA SÉRIE FORMAL GEOMÉTRICA Σ {x^(n+1)}=[x/(1-x)], n=0,1,2,... DERTIVANDO A
SÉRIE E ISOLANDO-SE OS TERMOS Σ n²{x^n} E Σ n³{x^n} APÓS AS MANIPULAÇÕES ALGÉBRICAS CORRESPONDENTES. TAL PROCEDIMENTO 
É FACILMENTE GENERALIZADO PARA QUAISQUER TERMOS DA FORMA n^q COM q INTEIRO.

PARA MAIORES INFORMAÇÕES: https://mathworld.wolfram.com/GeneratingFunction.html


*/



//************************************************************************************************************************
//CABEÇALHO
#ifndef SQUARE_CUBE_GENERATING_FUNCTION_H
#define SQUARE_CUBE_GENERATING_FUNCTION_H
#include"sparse_polynomials.h"

//************************************************************************************************************************
//DECLARAÇÃO DE FUNÇÕES
template<typename T>
polynomial<T> compute_perfect_square_generating_function(uint64_t);

template<typename T>
polynomial<T> compute_perfect_cube_generating_function(uint64_t);

//************************************************************************************************************************
//FUNÇÕES
//Função que computa uma uma aproximação polinomial da sequência de quadrados perfeitos de inteiros não negativos
template<typename T>
polynomial<T> compute_perfect_square_generating_function(uint64_t n){

  //Variáveis locais
  polynomial<T> result, multiplier, adder;
  univariate_monomial<T> poly_term;


  //Procedimentos
    //Ajuste dos polinômios base usados no cálculo
    poly_term.coefficient=1;  poly_term.power=1;
    result.monomials.insert({poly_term.power, poly_term});
    poly_term.coefficient=1;  poly_term.power=2;
    result.monomials.insert({poly_term.power, poly_term}); //p(x)=x^2+x

    adder=result; 

    poly_term.coefficient=1;  poly_term.power=3;
    multiplier.monomials.insert({poly_term.power, poly_term});
    poly_term.coefficient=(-3);  poly_term.power=2;
    multiplier.monomials.insert({poly_term.power, poly_term});
    poly_term.coefficient=3;  poly_term.power=1;
    multiplier.monomials.insert({poly_term.power, poly_term});//p(x)=x^3-3x^2+3x


    //Loop principal
    for(uint64_t i=0; i<=n; ++i){
      adder = adder*multiplier;
      result = result+ adder;
      
      //Removendo termos com expoentes elevados
      if((result.degree())>(n+30)){
        for(auto it=result.monomials.begin(); it!=result.monomials.end();){
          if((it->first)>n)
            it = result.monomials.erase(it);
          else break;
        }

        for(auto it=adder.monomials.begin(); it!=adder.monomials.end();){
          if((it->first)>n)
            it = adder.monomials.erase(it);
          else break;
        }

      }

    };//Fim do loop principal

    //Removendo termos com expoentes elevados
    for(auto it=result.monomials.begin(); it!=result.monomials.end();){
      if((it->first)>n) it = result.monomials.erase(it);
      else break;
    }


  //Resultado
  return result;

};

//Função que computa uma uma aproximação polinomial da sequência de cubos perfeitos de inteiros não negativos
template<typename T>
polynomial<T> compute_perfect_cube_generating_function(uint64_t n){

  //Variáveis locais
  polynomial<T> result, multiplier, adder;
  univariate_monomial<T> poly_term;


  //Procedimentos
    //Ajuste dos polinômios base usados no cálculo
    poly_term.coefficient=1;  poly_term.power=3;
    result.monomials.insert({poly_term.power, poly_term});
    poly_term.coefficient=4;  poly_term.power=2;
    result.monomials.insert({poly_term.power, poly_term});
    poly_term.coefficient=1;  poly_term.power=1;
    result.monomials.insert({poly_term.power, poly_term}); //p(x)=x^3+4x^2+x

    adder=result; 

    poly_term.coefficient=(-1);  poly_term.power=4;
    multiplier.monomials.insert({poly_term.power, poly_term});
    poly_term.coefficient=4;  poly_term.power=3;
    multiplier.monomials.insert({poly_term.power, poly_term});
    poly_term.coefficient=(-6);  poly_term.power=2;
    multiplier.monomials.insert({poly_term.power, poly_term});
    poly_term.coefficient=4;  poly_term.power=1;
    multiplier.monomials.insert({poly_term.power, poly_term});//p(x)=-x^4+4x^3-6x^2+4x

    //Loop principal
    for(uint64_t i=0; i<=n; ++i){
      adder = adder*multiplier;
      result = result+ adder;
      
      //Removendo termos com expoentes elevados
      if((result.degree())>(n+30)){
        for(auto it=result.monomials.begin(); it!=result.monomials.end();){
          if((it->first)>n)
            it = result.monomials.erase(it);
          else break;
        }

        for(auto it=adder.monomials.begin(); it!=adder.monomials.end();){
          if((it->first)>n)
            it = adder.monomials.erase(it);
          else break;
        }

      }

    };//Fim do loop principal

    //Removendo termos com expoentes elevados
    for(auto it=result.monomials.begin(); it!=result.monomials.end();){
      if((it->first)>n) it = result.monomials.erase(it);
      else break;
    }


  //Resultado
  return result;

};



//************************************************************************************************************************
//FIM DO HEADER
#endif

