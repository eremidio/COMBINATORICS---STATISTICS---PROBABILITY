//VAMOS CRIAR UM PROGRAMA PARA COMPUTAR NÚMEROS POLIGONAIS USANDO FUNÇÕES GERADORAS

/*

A SEQUÊNCIA DE NÚMEROS POLIGONAIS P(s, n) DEFINIDA PELA RELAÇÃO P(s, n)={(s-2)(n^2)-(s-4)n}/2 PARA n=0,1,2,3,....
DENOTA O NÚMERO DE ARRANJOS DE PONTOS EM UM POLÍGONO DE s LADOS CONTENDO ARESTAS DE n PONTOS . CASOS PARTICULARES
INCLUEM OS QUADRADOS PERFEITOS, NÚMEROS TRIANGULARES, NÚMEROS PENTAGONAIS, NÚMEROS HEXAGONAIS, ENTRE OUTROS.

MUITAS SEQUÊNCIAS DESTA NATUREZA SÃO RECORRENTES EM PROBLEMAS DE ANÁLISE COMBINATÓRIA (NA QUAL APERECE COMO
SOLUÇÃO DE CERTOS ALGORITMOS) E TEORIA DE NÚMEROS. UM IMPORTANTE TEOREMA DEVIDO A FERMAT CONSISTE NA OBSERVAÇÃO
DE QUE INTEIROS POSITIVOS PODEM SER EXPRESSOS COMO A SOMA DE NO MÁXIMO n NÚMEROS n-GONAIS. DESTA FORMA, NÚMEROS
INTEIROS PODEM SER ESCRITOS COMO A SOMA DE NO MÍNIMO TRÊS NÚMEROS TRIANGULARES, CINCO NÚMEROS PENTAGONAIS, ETC.
OS NÚMEROS n-GONAIS FORMAM UMA BASE ADITIVA PARA O CONJUNTO DOS NÚMEROS INTEIROS. PARA OS CASOS n<8 ALGUMAS
RESTRIÇÕES QUANTO A EXISTÊNCIA DESSAS REPRESENTAÇÕES SÃO IMPOSTAS.

A SEQUÊNCIA DE NÚMEROS POLIGONAIS PODE SER COMPUTADA POR MEIO DA SEGUINTE FUNÇÃO GERADORA
Σ P(s, n){x^n}=[(n-3)(x^2)+x]/[(1-x)^3]. TAL IDENTIDADE PERMITE COMPUTAR ESTA SEQUÊNCIA PARA UM PEQUENO INTERVALO
RAPIDAMENTE, PROVIDO DE EFICIENTE ROTINAS PARA ARITMÉTICA POLINOMIAL.


PARA MAIORES INFORMAÇÕES: https://mathworld.wolfram.com/PolygonalNumber.html
                          https://en.wikipedia.org/wiki/Fermat_polygonal_number_theorem

*/


//**************************************************************************************************
//CABEÇALHO
#ifndef POLYGONAL_NUMBERS_GENERATING_FUNCTION_H
#define POLYGONAL_NUMBERS_GENERATING_FUNCTION_H
#include"sparse_polynomials.h"


//**************************************************************************************************
//DECLARAÇÃO DE FUNÇÕES
template<typename T>
polynomial<T> compute_polygonal_number_generating_function(uint64_t, int);


//**************************************************************************************************
//FUNÇÕES
//Função que computa uma aproximação polinomial para a sequência de números poligonais P(s,n)
template<typename T>
polynomial<T> compute_polygonal_number_generating_function(uint64_t n, int s){

  //Variáveis locais
  polynomial<T> result, multiplier, adder;
  univariate_monomial<T> poly_term;


  //Procedimentos
    //Ajuste dos polinômios base usados no cálculo
    poly_term.coefficient=(s-3);  poly_term.power=2;
    result.monomials.insert({poly_term.power, poly_term});
    poly_term.coefficient=1;  poly_term.power=1;
    result.monomials.insert({poly_term.power, poly_term});//p(x)=(s-3)x^2+x

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



//**************************************************************************************************
//FIM DO HEADER
#endif
