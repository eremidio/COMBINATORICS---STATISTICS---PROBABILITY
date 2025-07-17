//VAMOS CRIAR UM PROGRAMA QUE IMPLEMENTA ROTINAS PARA CALCULAR NÚMEROS TRIANGULARES USANDO FUNÇÕES GERADORAS

/*

A SEQUÊNCIA DE NÚMEROS TRIANGULARES É DEFINIDA PELA RELAÇÃO T(n)=[n(n+1)]/2, PARA n=0,1,2... T(n) REPRESENTA O NÚMERO DE 
DE PONTOS EM UM ARRANJO TRIANGULAR DE n LINHAS DE PONTOS.

TAL SEQUÊNCIA NÚMERICA É RECORRENTE EM UMA SÉRIE DE PROBLEMAS EM ANÁLISE COMBINATÓRIA E EM TEORIA DE NÚMEROS COMO O
PROBLEMA DE CONTAGEM DE APERTOS DE MÃO, CONTAGEM DE ARESTAS EM GRAFOS COMPLETAMENTE CONECTADOS, ENTRE OUTROS.

COMO UM CASO PARTICULAR DO TEOREMA DE DECOMPOSIÇÃO DE INTEIROS EM SOMA DE NÚMEROS N-GONAIS DE FERMAT, É SABIDO QUE
INTEIROS PODEM SER DECOMPOSTOS EM NÚMEROS TRANGULARES. A CONTAGEM DE REPRESETAÇÕES DE UMA INTEIRO COMO A SOMA DE UM 
NÚMERO FIXO DE NÚMEROS TRIANGULARES ESTÁ DIRETAMENTE CONECTADO A TEORIA DAS FUNÇÕES THETA DE RAMANUJAN.

NÚMEROS TRIANGULARES PODEM SER FACILMENTE COMPUTADOS A PARTIR DA FUNÇÃO GERADORA Σ T(n){x^n}= {x/[(1-x)^3]}. TAL 
FUNÇÃO GERADORA É FACILMENTE DEMONSTRADA A PARTIR DA DEFINIÇÃO DE T(n) E DE MANIPULAÇÃO ALGÉBRICA DE SÉRIES DE POTÊNCIA
FORMAIS. ELA PERMITE COMPUTAR T(n) DE FORMA EFICIENTE EM UM INTERVALO PROVIDO DE EFICIENTES ROTINAS PARA ARITMÉTICA 
POLINOMIAL.

PARA MAIORES INFORMAÇÕES: https://github.com/eremidio/COMBINATORICS---STATISTICS---PROBABILITY/blob/main/square_cube_generating_function.h
                          https://en.wikipedia.org/wiki/Triangular_number
                          https://proofwiki.org/wiki/Generating_Function_for_Triangular_Numbers

*/


//****************************************************************************************************************************
//CABEÇALHO
#ifndef TRIANGULAR_NUMBER_GENERATING_FUNCTION_H
#define TRIANGULAR_NUMBER_GENERATING_FUNCTION_H
#include"sparse_polynomials.h"


//****************************************************************************************************************************
//DECLARAÇÃO DE FUNÇÕES
template<typename T>
polynomial<T> compute_triangular_number_generating_function(uint64_t);


//****************************************************************************************************************************
//FUNÇÕES
//Função que computa uma aproximação polinomial da função geradora de números triângulares
template<typename T>
polynomial<T> compute_triangular_number_generating_function(uint64_t n){

  //Variáveis locais
  polynomial<T> result, multiplier, adder;
  univariate_monomial<T> poly_term;


  //Procedimentos
    //Ajuste dos polinômios base usados no cálculo
    poly_term.coefficient=1;  poly_term.power=1;
    result.monomials.insert({poly_term.power, poly_term});//p(x)=x

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


//****************************************************************************************************************************
//FIM DO  HEADER
#endif
