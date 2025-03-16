//VAMOS CRIAR UM PROGRAMA COM ROTINAS PARA COMPUTAR O TRIÂNGULO DE PASCAL

/*

O TRIÂNGULO DE PASCAL É UMA CONSTRUÇÃO GEOMÉTRICA QUE ENCODA OS COEFICIENTES BINOMIAIS DEFINOS PELA
RELAÇÃO C(n, m)=n!/[m!(n-m)!], ONDE N!=1x2x...x(N-1)xN. ESTES COEFICIENTES SÃO GERADOS PELA FUNÇÃO
GERADORA G(x)=(x+a)^n=ΣC(n,i)x^(n-1)a^i, PARA i=0,1,...,n.

PARA MAIORES INFORMAÇÕES: https://en.wikipedia.org/wiki/Pascal%27s_triangle?wprov=srpw1_0
                          https://en.wikipedia.org/wiki/Convolution_power

*/ 


//***********************************************************************************************************
//CABEÇALHO
#ifndef PASCAL_TRIANGLE_H
#define PASCAL_TRIANGLE_H
#include"convolution.h"


//***********************************************************************************************************
//DECLARAÇÃO DE FUNÇÕES
template<typename T>
std::vector<T> compute_nth_row(int64_t);

template<typename T>
std::vector<std::vector<T>> generate_pascal_triangle(int64_t);


//***********************************************************************************************************
//FUNÇÕES
//Função que gera a n-ésima linha do triângulo de Pascal
template<typename T>
std::vector<T> compute_nth_row(int64_t n){

  //Variáveis locais
  std::vector<T> q={1,1};
  std::vector<T> result={1};

  //Procedimentos
    //Casos bases: n=1,2
    if(n==1) return result;
    if(n==2) return q;

    //Loop principal: interando sobre os bits de n
    while(n>0){

      //Checando a paridade do bit
      if(n&1) result = convolution<T>(result, q);


      //Atualizando variáveis para a próxima iteração 
      n>>=1;
      q=convolution<T>(q, q);
        
    };

  //Resultado
  return result;
    

};


//Função que computa recursivamente os elementos do triângulo de Pascal
template<typename T>
std::vector<std::vector<T>> generate_pascal_triangle(int64_t n){

  //Variáveis locais
  std::vector<std::vector<T>> pascal_triangle;
  std::vector<T> first={1}, q={1,1}, next_line={1,1};


  //Procedimentos
    //Casos bases: n=1,2
    pascal_triangle.push_back(first);
    if(n==1) return pascal_triangle;
      
    pascal_triangle.push_back(q);   
    if(n==2)  return pascal_triangle;

    //Caso geral: computando as demais linhas usando convoluções
    n-=2;

    while(n>0){
      next_line=convolution<T>(next_line, q);
      pascal_triangle.push_back(next_line);
      n--; 

    };


  //Resultado
  return pascal_triangle;

};


//***********************************************************************************************************
//FIM DO HEADER
#endif
