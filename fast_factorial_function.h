//VAMOS CRIAR UM PROGRAMA QUE AVALIA O FATORIAL DE UM INTEIRO USANDO VALUAÇÕES P-ÁDICAS

/*

A VALUAÇÃO P-ÁDICA DE UM INTEIRO n EM RELAÇÃO A UM PRIMO p DENOTADA POR ν(p, n) CORRESPONDE AO
MAIOR EXPOENTE e TAL QUE p^e DIVIDE n.

SEJA n!=1x2x...x(n-1)xn, O FATORIAL DE n. ν(n, p)=|_n/p_|, POIS NO INTERVALO {1,2,...,n} HÁ
|_n/p_| NÚMEROS QUE NÃO DIVIDEM n, SIMILARMENTE ν(n, p²)=|_n/p²_|, E ASSIM SUCESSIVAMENTE.
CONCLUÍ-SE QUE n! CONTÉM a(p)=|_n/p_|+|_n/p²_|+...+|_n/(p^s)_| FATORES PRIMOS p, ONDE s É TAL
QUE p^(s+1)>n.

TAL INFORMAÇÃO PODE SER EMPREGADA PARA REDUZIR O NÚMERO DE MULTIPLICAÇÕES USADAS PARA COMPUTAR
n!, USANDO -SE TECNICAS COMO A EXPONENCIAÇÃO BINÁRIA, POIS n!={p1^a(p1)}x{p2^a(p2)}x...,
PROVIDO UMA LISTA DE NÚMEROS PRIMOS ATÉ n (COMPUTADA USANDO UMA PENEIRA DE ERATÓSTENES, POR
EXEMPLO).


PARA MAIORES INFORMAÇÕES: Mathematics: Its contents, its methods and its meaning, by A. N. Kolmogorov et all
PARA UMA TÉCNICA MAIS EFICIENTE PARA SE COMPUTAR FATORIAIS CONSULTAR O ARTIGO: http://www.luschny.de/math/factorial/SwingIntro.pdf

*/


//********************************************************************************************************************************
//CABEÇALHO
#ifndef FAST_FACTORIAL_FUNCTION_H
#define FAST_FACTORIAL_FUNCTION_H
#include<iostream>
#include<fstream>
#include<vector>
#include<boost/multiprecision/cpp_int.hpp>
#include<boost/cstdint.hpp>
using namespace boost::multiprecision;


//********************************************************************************************************************************
//DECLARAÇÃO DE FUNÇÕES
std::vector<int32_t> fill_prime_buffer();
cpp_int factorial_bin_pow(int32_t, int);
cpp_int p_adic_factorial(int32_t);


//********************************************************************************************************************************
//FUNÇÕES
//Função que preenche um buffer de primos até 5x10⁶
std::vector<int32_t> fill_prime_buffer(){

  //Variáveis locais
  std::vector<int32_t> prime_vector;
  int32_t prime;

  
  //Procedimentos
    //Abrindo arquivo para leitura
    std::ifstream prime_file;
    prime_file.open("prime_list.txt", std::ios::in);

    //Lendo a lista de primos
    if(prime_file.is_open()){
      while(prime_file>>prime) prime_vector.push_back(prime);
    }
    
  //Resultado
  return prime_vector;

};

//Função que calcula uma exponencial 
cpp_int factorial_bin_pow(int32_t a, int b){

  //Variáveis locais
  cpp_int result=1, q=a;


  //Procedimentos
    //Loop sobre os bits do expoente
    while(b>0){

      if(b&1) result=result*q;
      q=q*q;
      b>>=1;

    };

  //Resultado
  return result;

};

//Função que computa o fatorial de um número n
cpp_int p_adic_factorial(int32_t n){

  //Variáveis locais
  cpp_int fact=1;
  std::vector<int32_t> prime_list=fill_prime_buffer();
  int32_t current_prime;
  int p_adic_valuation=0;


  //Procedimentos
    //Loop sobre o buffer de números primos
    for(int32_t i=0; prime_list[i]<=n; ++i){

      current_prime=prime_list[i];
      int p_adic_valuation=0;

      //Computando a função a(p)
      while(current_prime<=n){
        p_adic_valuation = p_adic_valuation+(n/current_prime);
        current_prime = current_prime*prime_list[i];
      }      

      fact=fact*factorial_bin_pow(prime_list[i], p_adic_valuation);


    };//Fim do loop principal
    
  //Resultado
  return fact;

};


//********************************************************************************************************************************
//FIM DO HEADER
#endif
