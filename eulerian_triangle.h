//VAMOS CRIAR UM PROGRAMA QUE COMPUTA NÚMEROS EULERIANOS DE FORMA RECURSIVA

/*

NÚMEROS EULERIANOS A(n,k), DENOTADOS TAMBÉM POR <n, k>, FORMAM UMA SEQUÊNCIA NÚMÉRICA QUE POSSUI INTERPRETAÇÕES EM
ANÁLISE COMBINATÓRIA. A(n,k) REPRESENTA O NÚMERO DE PERMUTAÇÕES DE n ELEMENTOS COM k ASCEDENTES (UM ASCEDENTE É 
PAR DE ELEMENTOS VIZINHOS {..,a ,b , ...} EM UMA PERMUTAÇÃO TAIS QUE b>a). DESTA INTERPRETAÇÃO É ÓBVIO QUE PARA
n FIXO ΣA(n,k)=n! COM k=1, 2, ..., n. 

ESTA SEQUÊNCIA NÚMERICA ENCODA OS COEFICIENTES DOS CHAMADOS POLINÔMIOS EULERIANOS. OS POLINÔMIOS EULERIANOS A(n, t)
SÃO DEFINIDOS PELA FUNÇÃO GERADORA EXPONENCIAL ΣA(n, t){(x^n)/n!}={t-1}/{t-exp((t-1)x)}.

NÚMEROS EULERIANOS PODEM SER COMPUTADOS PELA FÓRMULA A(n, k)=Σ {(-1)^i} C(n+1, i){(k+1-i)^n}. ELES SATISFAZEM A
RELAÇÃO RECURSIVA A(n, k)=(n-k)A(n-1,k-1)+(k+1)A(n-1, k). ESTA FÓRMULA EM PARTCULAR PERMITE COMPUTAR OS NÚMEROS
EULERIANOS USANDO UMA CONSTRUÇÃO GEOMÉTRICA SIMILAR A DO TRIÂNGULO DE PASCAL.

NÚMEROS EULERIANOS POSSUI ALGUMAS APLICAÇÕES IMPORTANTES COMO NA INTENGRAL DA FUNBÇÇÃO sen(x)/x, ALÉM DE ESTAR
RELACIONADA COM OUTRAS SEQUÊNCIAS IMPORTANTES COMO OS NÚMEROS DE BERNOULLI. ELES PODEM SER CONSIDERADOS UMA
GENERALIZAÇÃO DOS COEFICIENTESM BINOMIAIS USUAIS


PARA MAIORES INFORMAÇÕES: https://mathworld.wolfram.com/EulerianNumber.html
                          https://en.wikipedia.org/wiki/Eulerian_number#Basic_properties
                          Concrete Mathematics: A Foundation for Computer Science by Ronald Graham, Donald Knuth, et al.      


*/ 


//**********************************************************************************************************
//CABEÇALHO
#ifndef EULERIAN_TRIANGLE_H
#define EULERIAN_TRIANGLE_H
#include<vector>
#include<iostream>
#include<stdint.h>


//**********************************************************************************************************
//DECLARAÇÃO DE FUNÇÕES
template<typename T>
std::vector<std::vector<T>> compute_eulerian_triangle(int64_t);


//**********************************************************************************************************
//FUNÇÃO
//Função que computa osnúmeros Eulerianos recursivamente
template<typename T>
std::vector<std::vector<T>> compute_eulerian_triangle(int64_t n){


  //Variáveis locais
  std::vector<std::vector<T>> euler_triangle;
  std::vector<T> zero_line={1}, one_line={1,1};
  int64_t i, j;


  //Procedimentos
    //Casos bases
    euler_triangle.push_back(zero_line);
    if(n==0) return euler_triangle;
    euler_triangle.push_back(zero_line);
    if(n==1) return euler_triangle;
    euler_triangle.push_back(one_line);
    if(n==2) return euler_triangle;


    //Caso geral: computando recursivamente os elementos do triângulo de Euler
    for(i=3; i<n; ++i){

      std::vector<T> next_line;//Próxima linha do triângulo de Euler
      next_line.push_back(1);
      
      for(j=1; j<i; ++j){
        if((j+1)==i){
          next_line.push_back(1);
          euler_triangle.push_back(next_line); 
          continue;
        }

        T element= (i-j)*euler_triangle[i-1][j-1]+(j+1)*euler_triangle[i-1][j];
        next_line.push_back(element);
      };

    }


  //Resultado
  return euler_triangle;

};


//**********************************************************************************************************
//FIM DO HEADER
#endif
