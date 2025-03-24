//VAMOS CRIARUM PROGRAMA PARA COMPUTAR NÚMEROS DE STIRLING DO PRIMEIRO E SEGUNDO TIPO USANDO RELAÇÕES RECURSIVAS

/*

NÚMEROS DE STIRLING DO PRIMEIRO E SEGUNDO TIPO PODEM SER COMPUTADOS USANDO RELAÇÕES RECURSIVAS VALENDO-SE DE
UM CONSTRUTO GEOMÉTRICO SIMILAR AO TRIÂNGULO DE PASCAL. AS ENTRADAS PODEM COMPUTADAS POR MEIO DAS RELAÇÕES:
[(n+1), k]=n[n, k]+[n, (k-1)]; {(n+1), k} = k{n, k}+{n, (k-1)}; PARA NÚMEROS DE STIRLING DO PRIMEIRO E DO
SEGUNDO TIPO RESPECTIVAMENTE.

PARA MAIORES INFORMAÇÕES: https://en.wikipedia.org/wiki/Stirling_number
                          https://en.wikipedia.org/wiki/Stirling_numbers_of_the_first_kind
                          https://en.wikipedia.org/wiki/Stirling_numbers_of_the_second_kind#Recurrence_relation
                          https://en.wikipedia.org/wiki/Touchard_polynomials 

*/ 


//****************************************************************************************************************
//CABEÇALHO
#ifndef STIRLING_TRIANGLE_H
#define STIRLING_TRIANGLE_H
#include<vector>
#include<iostream>
#include<stdint.h>


//****************************************************************************************************************
//DECLARAÇÕES DE FUNÇÕES
template<typename T>
std::vector<std::vector<T>> compute_stirling_triangle_first_kind(int64_t);

template<typename T>
std::vector<std::vector<T>> compute_stirling_triangle_second_kind(int64_t);

//****************************************************************************************************************
//FUNÇÕES
//Função que computa números de Stirling do primeiro tipo usando relações recursivas
template<typename T>
std::vector<std::vector<T>> compute_stirling_triangle_first_kind(int64_t n){

  //Variáveis locais
  std::vector<std::vector<T>> stirling_triangle;
  std::vector<T> zero_line={1}, one_line={0,1}, two_line={0,1,1};
  int64_t i, j;


  //Procedimentos
    //Casos bases: n<3
    stirling_triangle.push_back(zero_line); 
    if(n==0) return stirling_triangle;
    stirling_triangle.push_back(one_line); 
    if(n==1) return stirling_triangle;
    stirling_triangle.push_back(two_line); 
    if(n==2) return stirling_triangle;

    //Adicionando demais linhas:
    for(i=3; i<=n; ++i){
      std::vector<T> next_line;

      next_line.push_back(0);
      for(j=1; j<i; ++j){
        T s_ij=((i-1)*stirling_triangle[i-1][j])+stirling_triangle[i-1][j-1];
        next_line.push_back(s_ij);
      }
      next_line.push_back(1);

      stirling_triangle.push_back(next_line);  

    }


  //Resultado
  return stirling_triangle;

};


//Função que computa números de Stirling do segundo tipo usando relações recursivas
template<typename T>
std::vector<std::vector<T>> compute_stirling_triangle_second_kind(int64_t n){

  //Variáveis locais
  std::vector<std::vector<T>> stirling_triangle;
  std::vector<T> zero_line={1}, one_line={0,1}, two_line={0,1,1};
  int64_t i, j;


  //Procedimentos
    //Casos bases: n<3
    stirling_triangle.push_back(zero_line); 
    if(n==0) return stirling_triangle;
    stirling_triangle.push_back(one_line); 
    if(n==1) return stirling_triangle;
    stirling_triangle.push_back(two_line); 
    if(n==2) return stirling_triangle;

    //Adicionando demais linhas:
    for(i=3; i<=n; ++i){
      std::vector<T> next_line;

      next_line.push_back(0);
      for(j=1; j<i; ++j){
        T s_ij=(j*stirling_triangle[i-1][j])+stirling_triangle[i-1][j-1];
        next_line.push_back(s_ij);
      }
      next_line.push_back(1);

      stirling_triangle.push_back(next_line);  

    }


  //Resultado
  return stirling_triangle;

};


//****************************************************************************************************************
//FIM DO  HEADER
#endif
