//VAMOS CRIAR UM PROGRAMA QUE CALCULA A APROXIMAÇÃO DE STIRLING PARA A FUNÇÃO FATORIAL 

/*
A APROXIMAÇÃO DE STIRLING CONSISTE EM UMA SÉRIE DE FÓRMULAS USADA PARA A APROXIMAR A FUNÇÃO GAMA Γ(x) SENDO
PARTICULARMENTE ÚTIL PARA CALCULAR VALORES APROXIMADOS DA FUNÇÃO FATORIAL n! ESSA FÓRMULA CONVERGE 
RAPIDAMENTE MESMO PARA PEQUENOS VALORES DE n.

PARA MAIORES INFORMAÇÕES: https://en.wikipedia.org/wiki/Stirling%27s_approximation
 

*/


//*************************************************************************************************************
//CABEÇALHO
#ifndef STIRLING_APPROXIMATION_H
#define STIRLING_APPROXIMATION_H
#include<stdint.h>
#include<stdlib.h>
#include<stdio.h>
#include<gmp.h>


//*************************************************************************************************************
//DECLARAÇÃO DE FUNÇÕES
void exact_factorial(int64_t);
void stirling_approximation(int64_t);


//*************************************************************************************************************
//FUNÇÕES
//Função que computa o valor exato do fatorial de um número
void exact_factorial(int64_t  n){

  //Variáveis locais
  int64_t N=n;
  mpz_t result;
  mpz_init(result);
  mpz_set_ui(result, 1);


  //Procedimento
    //Loop principal
    while(n>0){
      mpz_mul_ui(result, result, n);
      n--;

    };

  //Resultado
  printf("%li!= ", N);  gmp_printf("%Zd\n", result);
  
  //Limpando o cachê de memória
  mpz_clear(result);


};


//Função que calcula a aproximação de Stirling para a função fatorial
void stirling_approximation(int64_t n){

  //Ajuste da precisão padrão
  mpf_set_default_prec(25);

  //Variáveis locais
  const char* pi_string = "3.14159265358979323846264338327950";
  const char* e_string = "2.7182818284590452353602874713527";
  mpf_t pi, two, float_n, two_pi_root_square, e, q, result, result1, result2;
  mpf_t error, q1, q2, den1, den2, num1, num2, c1, c2, c3, n_square;
  double b=2.0, n_=(n*1.0);

  //Procedimentos 
    //Inicializando variáveis
    mpf_init2(pi, 256);
    mpf_init2(two_pi_root_square, 256);
    mpf_init2(e, 256);
    mpf_init2(q, 256);
    mpf_init2(two, 256);
    mpf_init2(result, 256);
    mpf_init2(result1, 256);
    mpf_init2(result2, 256);
    mpf_init2(float_n , 256);

    mpf_init2(error , 256);
    mpf_init2(q1 , 256);
    mpf_init2(q2 , 256);
    mpf_init2(num1 , 256);
    mpf_init2(num2 , 256);
    mpf_init2(den1 , 256);
    mpf_init2(den2 , 256);
    mpf_init2(c1, 256);
    mpf_init2(c2, 256);
    mpf_init2(c3, 256);
    mpf_init2(n_square, 256);


    //Constantes
    mpf_set_str(pi, pi_string, 10);
    mpf_set_str(e, e_string, 10);
    mpf_set_d(two, b);
    mpf_set_d(float_n, n_);

    //Calculando as parcelas da equação
    mpf_mul(two_pi_root_square, pi, two);
    mpf_mul(two_pi_root_square, two_pi_root_square, float_n);
    mpf_sqrt(result1, two_pi_root_square);


    mpf_div(q, float_n, e); 
    mpf_pow_ui(result2, q, n);     

    mpf_mul(result, result1, result2);
  
    printf("[Aproximação via fórmula de Stirling] %li! = ", n);  gmp_printf("%.Ff\n", result);


    //Cálculo do erro
    //Inicializando constantes no cálculo do erro O(n²)
    mpf_set_d(c1, 12.0);
    mpf_set_d(c2, 288.0);
    mpf_set_d(num1, 1.0);
    mpf_set_d(num2, 1.0);


    //Calculando as parcelas
    mpf_mul(den1, c1, float_n);
    mpf_mul(n_square, float_n, float_n);
    mpf_mul(den2, c2, n_square);
    mpf_div(q1, num1, den1);
    mpf_div(q2, num2, den2);
    mpf_add(c3, q1, q2);
    mpf_mul(error, c3, result);

    printf("Erro na aproximação de Stirling até ordem O(n²) : ");  gmp_printf("%.Ff\n", error);




  //Limpando o cachê de memória
  mpf_clear(pi);
  mpf_clear(e);
  mpf_clear(two_pi_root_square);
  mpf_clear(q);
  mpf_clear(two);
  mpf_clear(result);
  mpf_clear(result1);
  mpf_clear(result2);
  mpf_clear(error);
  mpf_clear(q1);
  mpf_clear(q2);
  mpf_clear(num1);
  mpf_clear(num2);
  mpf_clear(den1);
  mpf_clear(den2);
  mpf_clear(c1);
  mpf_clear(c2);
  mpf_clear(c3);
  mpf_clear(n_square);


};


//*************************************************************************************************************
//FIM DO HEADER
#endif
