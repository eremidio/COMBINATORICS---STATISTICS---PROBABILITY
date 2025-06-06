//VAMOS CRIAR UMA ROTINA PARA COMPUTAR NÚMEROS DE CATALAN DE FORMA RECURSIVA 

/*

NÚMEROS DE CATALAN SÃO UMA SEQUÊNCIA DE INTEIROS DEFINIDO PELA FÓRMULA C(n)={1/(n+1)}c(2n,n), ONDE c(2n, n) DENOTA O COEFICIENTE 
BINOMIAL. ESTA FÓRMULA PODE SER REESCRITA COMO C(n)=c(2n,n)-c(2n, n+1). 

ESTA SEQUÊNCIA PODE SER OBTIDA RECURSIVAMENTE USANDO AS RELAÇÕES: C(n)=ΣC(n-i)C(i-1) COM i=1,2,3,...,n E C(0)=1, OU 
C(n)={2(2n-1)/(n+1)}C(n-1) COM C(0)=1. QUANDO n-> ∞, VALE A FÓRMULA ASSINTÓTICA C(n)≃ (4^n)/{n^(3/2)√π}.

ESTA SEQUÊNCIA APARECE EM MUITOS PROBLEMAS DE ANÁLISE COMBINATÓRIA COMO: CONTAGEM DE PALAVRAS DE DYCK, ENUMERAÇÃO DE ÁRVORES 
BINÁRIAS COMPLETAS CONTENDO UM NÚMERO ESPECÍFICO DE NÓS, ENUMERAÇÃO DE PARTIÇÕES DE UM POLÍGONO REGULAR EM TRIÂNGULOS,
ENUMERAÇÃO DOS CAMINHOS POSSÍVEIS CONECTANDO DIAGONAIS EM UMA MALHA QUADRADA, ENTRE OUTROS.

A FUNÇÃO GERADORA DA SEQUÊNCIA DE NÚMEROS DE CATALAN É f(x)={1-√(1-4x)}/{2x}=Σ{(-1)^n}C(n)x^n (O DENOMINADOR PODE SER EXPANDIDO
USANDO-SE SÉRIES DE TAYLOR). ESTA FÓRMULA PODE SER FACILMENTE DEMONSTRADA USANDO-SE A TEORIA DE SÉRIES INFINITAS E A PRIMEIRA
DAS IDENTIDADES RECURSIVAS LISTADAS ACIMA.


PARA MAIORES INFORMAÇÕES: https://en.wikipedia.org/wiki/Catalan_number
                          https://mathworld.wolfram.com/CatalanNumber.html
                          https://cp-algorithms.com/combinatorics/catalan-numbers.html

*/


//********************************************************************************************************************************
//CABEÇALHO
#ifndef CATALAN_NUMBERS_H
#define CATALAN_NUMBERS_H
#include<vector>
#include<string>
#include<stdint.h>
#include<iostream>


//********************************************************************************************************************************
//DECLARAÇÃO DE FUNÇÕES
template<typename T>
std::vector<T> generate_catalan_number_vector(int64_t);

template<typename T>
void dyck_word_catalan_number_representation(T, T, T, T, std::string);


//********************************************************************************************************************************
//FUNÇÕES
//Função que computa um vetor de números de Catalan usando relações recursivas
template<typename T>
std::vector<T> generate_catalan_numbers_recursive(int64_t n){

  //Variáveis locais
  std::vector<T> catalan_vector;
  T sum=0;


  //Procedimentos
    //Ajuste de variáveis
    catalan_vector.reserve(n+1);
    catalan_vector.push_back(1); 

    
    //Loop principal cálculo recursivo dos números de Catalan 
    for(int64_t k=1; k<=n; ++k){
      
      sum=0;
      for(int64_t l=1; l<=k; ++l){
        sum=sum+(catalan_vector[l-1]*catalan_vector[k-l]);
      }

      catalan_vector.push_back(sum);    

    };


  //Resultado
  return catalan_vector;

};


//Função que representa número de Catalan usando palavras de Dyck usando pares de parêtenses
template<typename T>
void dyck_word_catalan_number_representation(T n, T current, T open_counter, T close_counter,std::string dyck_word){

  //Procedimentos
    //Loop principal: gerando representações recursivamente
    if(current==(n<<1)){
      std::cout<< dyck_word<<'\n';
      return;
    }

    if(open_counter<n)
      dyck_word_catalan_number_representation(n, current+1, open_counter+1, close_counter, dyck_word+'(');

    if(close_counter<open_counter)
      dyck_word_catalan_number_representation(n, current+1, open_counter, close_counter+1, dyck_word+')');

};

//********************************************************************************************************************************
//FIM DO HEADER
#endif
