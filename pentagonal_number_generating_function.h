//VAMOS CRIAR UM PROGRAMA PARA COMPUTAR NÚMEROS PENTAGONAIS USANDO FUNÇÕES GERADORAS

/*
A SEQUÊNCIA DE NÚMEROS PENTAGONAIS É DEFINIDA PELA RELAÇÃO P(n)= {n(3n-1)}/2, n=0,1,2,3,... TAL SEQUÊNCIA CORRESPONDE AO
NÚMERO DE PONTOS EM UM CONJUNTO DE PENTÁGONOS SOPBREPOSTOS.

ESTA SEQUÊNCIA NÚMERICA (ASSIM COMO OS NÚMEROS TRIANGULARES) APARECE NA SOLUÇÃO DE VÁRIOS PROBLEMAS EM ANÁLISE
COMBINATÓRIA. ALGUMAS GENERALIZAÇÕES DESTES CONCEITOS SÃO ÚTEIS EM TEORIA DE NÚMEROS, PARTICULARMENTE NA TEORIA DAS
PARTIÇÕES.

NÚMEROS PENTAGONAIS PODEM SER FACILMENTE COMPUTADOS A PARTIR DA FUNÇÃO GERADORA Σ T(n){x^n}= {[2(x^2)+x]/[(1-x)^3]}. TAL 
FUNÇÃO GERADORA É FACILMENTE DEMONSTRADA A PARTIR DA DEFINIÇÃO DE P(n) E DE MANIPULAÇÃO ALGÉBRICA DE SÉRIES DE POTÊNCIA
FORMAIS. ELA PERMITE COMPUTAR P(n) DE FORMA EFICIENTE EM UM INTERVALO PROVIDO DE EFICIENTES ROTINAS PARA ARITMÉTICA 
POLINOMIAL.


PARA MAIORES INFORMAÇÕES: https://en.wikipedia.org/wiki/Pentagonal_number
                          https://math.stackexchange.com/questions/2184058/finding-the-generating-function-for-pentagonal-numbers
                          https://mathworld.wolfram.com/PentagonalNumber.html
                          https://en.wikipedia.org/wiki/Hexagonal_number

*/


//***********************************************************************************************************************************
//CABEÇALHO
#ifndef PENTAGONAL_NUMBER_GENERATING_FUNCTION_H
#define PENTAGONAL_NUMBER_GENERATING_FUNCTION_H
#include"sparse_polynomials.h"


//***********************************************************************************************************************************
//DECLARAÇÃO DE FUNÇÕES
template<typename T>
polynomial<T> compute_pentagonal_number_generating_function(uint64_t);


//***********************************************************************************************************************************
//FUNÇÕES
//Função que computa uma aproximação polinomial da função geradora de números pentagonais
template<typename T>
polynomial<T> compute_pentagonal_number_generating_function(uint64_t n){

  //Variáveis locais
  polynomial<T> result, multiplier, adder;
  univariate_monomial<T> poly_term;


  //Procedimentos
    //Ajuste dos polinômios base usados no cálculo
    poly_term.coefficient=2;  poly_term.power=2;
    result.monomials.insert({poly_term.power, poly_term});
    poly_term.coefficient=1;  poly_term.power=1;
    result.monomials.insert({poly_term.power, poly_term});//p(x)=2x^2+x

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
      if((i&31)<1){
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


//***********************************************************************************************************************************
//FIM DO HEADER
#endif










