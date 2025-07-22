//VAMOS CRIAR UM PROGRAMA PARA COMPUTAR POLINÔMIOS DE CHEBYSHEV

/*

OS POLINÔMIOS DE CHEBYSHEV SÃO UMA SEQUÊNCIA DE POLINÔMIOS MUITO IMPORTANTE EM MATEMÁTICA QUE SÃO DEFINIDOS PELAS RELAÇÕES 
TRIGONOMÉTRICAS PARA n INTEIRO E x REAL T(n, cos(x)) = cos(nx) e U(n, cos(x))sen(x) = sen((n+1)x). ALTERNATIVAMENTE ELES
PODEM SER DEFINIDOS PELAS RELAÇÕES DE RECORRÊNCIA T(0, x) =1, T(1, x) = x, T(n+1, x) = 2x.T(n, x)-T(n-1, x) E U(0, x) =1,
U(1, x) = 2x, U(n+1, x) = 2x.U(n, x)-U(n-1, x). TAIS POLINÔMIOS SÃO SOLUÇÕES DA EQUAÇÃO DIFERENCIAL (COM n = 0,1,2,3,...)
[1-x^2]p''(x)-[x]p'(x)+[n^2]p(x)=0.

UMA FORMA EFICIENTE DE COMPUTAR ESTA SEQUÊNCIA POLINOMIAL É USANDO AS RELAÇÕES: T(n, x)= [(x-ξ)^n+(x+ξ)^n]/2 E
U(n, x)= [(x-ξ)^(n+1)-(x+ξ)^(n+1)]/[2ξ], ONDE ξ =(x^2-1)^(1/2). TAIS FÓRMULAS PERMITEM COMPUTAR OS POLINÔMIOS DE 
CHEBYSHEV USANDO EXPONENCIAÇÃO POR QUADRADOS. TAIS FÓRMULAS SÃO DECORRENTES DO FATO DE POLINÔMIOS DE CHEBYSHEV SEREM 
COMPUTÁVEIS USANDO-SE SEQUÊNCIAS DE LUCAS DO PRIMEIRO E SEGUNDO TIPO.

OS POLINÔMIOS DE CHEBYSHEV SÃO IMPORTANTES EM UMA SÉRIE DE APLICAÇÕES: EM TEORIA DE APROXIMAÇÕES, POR EXEMPLO, OS PONTOS
ÓTIMOS PARA INTERPOLAÇÃO DE POLINÔMIOS PODEM SER CALCULADOS USANDO-SE RAÍZES DESTES POLINÔMIOS; EM TEORIA DE NÚMEROS
ELES SÃO ÚTEIS NO ESTUDO DE CORPOS FINITOS; ENTRE OUTRAS. POLINÔMIOS DE CHEBYSHEV FORMAM UMA SEQUÊNCIA ORTOGONAL DE
POLINÔMIOS E SÃO ÚTEIS PARA COMPUTAR APROXIMAÇÕES DE FUNÇÕES "BEM COMPORTADAS" EM ALGORITMOS COMO A TRANSFORMADA DE 
FOURIER RÁPIDA, ALGORITMOS DE COMPRESSÃO DE DADOS, ETC.


PARA MAIORES INFORMAÇÕES: https://kth-nek5000.github.io/kthNekBook/_md/spectral/chebyshev.html
                          https://en.wikipedia.org/wiki/Chebyshev_polynomials#Definitions
                          https://www.mhtlab.uwaterloo.ca/courses/me755/web_chap6.pdf


*/


//*****************************************************************************************************************************
//CABEÇALHO
#ifndef CHEBYSHEV_POLYNOMIALS_H
#define CHEBYSHEV_POLYNOMIALS_H
#include"sparse_polynomials.h"


//*****************************************************************************************************************************
//CLASSES E MÉTODOS AUXILIARES USADOS NO ALGORITMO
//Estrututa usada para computar os polinômios de Chebyshev
template<typename T>
struct chebyshev_struct{
  polynomial<T> a;
  polynomial<T> b;
  polynomial<T> d;

};


//Função que gera o polinômio p(x)=x^2-1
template<typename T>
polynomial<T> generate_chebyshev_d_polynomial(){

  //Variáveis locais
  polynomial<T> result;
  univariate_monomial<T> poly_term;


  //Procedimentos
    //Definindo os termos do polinômios
    poly_term.coefficient=(-1);  poly_term.power=0;
    result.monomials.insert({poly_term.power, poly_term});
    poly_term.coefficient=1;  poly_term.power=2;
    result.monomials.insert({poly_term.power, poly_term});

  //Resultado
  return result;

};


//FUNÇÕES ENVOLVENDO ARITMÉTICA POLINOMIAIS
template<typename T>
struct chebyshev_struct<T> chebyshev_multiplication(struct chebyshev_struct<T>& cheby1, struct chebyshev_struct<T>& cheby2){

  //Variáveis locais
  struct chebyshev_struct<T> result;
  polynomial<T> temp1, temp2, temp3;

  //Procedimentos
    //Computando as parcelas do resultado
    //1ª parcela
    temp1=cheby1.a*cheby2.a;
    temp2=cheby1.b*cheby2.b;
    temp3=temp2*cheby2.d;
    result.a=temp1+temp3;

    //2ª parcela
    temp1=cheby1.a*cheby2.b;
    temp2=cheby1.b*cheby2.a;
    result.b=temp1+temp2;

    //Discriminante 
    result.d=cheby1.d;


  //Resultado
  return result;
  
};


template<typename T>
struct chebyshev_struct<T> chebyshev_exponentiation(struct chebyshev_struct<T>& cheby1, T exponent){

  //Variáveis globais
  struct chebyshev_struct<T> result;
  univariate_monomial<T> poly_term;

  //Ajuste de variáveis
  poly_term.coefficient=1; poly_term.power=0;
  (result.a).monomials.insert({poly_term.power, poly_term});
  poly_term.coefficient=0; poly_term.power=0;
  (result.b).monomials.insert({poly_term.power, poly_term});
  (result.d)=generate_chebyshev_d_polynomial<T>();


  //Caso base: e=0
  if(exponent==0) return result;
  
  //Caso base: e=1
  if(exponent==1){
    result.a=cheby1.a; result.b=cheby1.b; result.d=cheby1.d;
    return result;
  };

 

  //Caso geral:
  //Variáveis locais
  struct chebyshev_struct<T> q;


  //Procedimentos
    //Ajuste de variáveis
    q.a=cheby1.a; q.b=cheby1.b; q.d=cheby1.d;

    //Loop principal iterando
    while(exponent>0){

      //Checando a paridade do bit em questão
      if(exponent&1) result=chebyshev_multiplication<T>(result, q);

      //Ajuste de variáveis
      exponent>>=1;
      q=chebyshev_multiplication<T>(q, q);

    }
    

  //Resultado
  return result;

};


//*****************************************************************************************************************************
//DECLARAÇÃO DE FUNÇÕES
template<typename T>
polynomial<T> compute_chebyshev_polynomial_first_kind_recursive(int);

template<typename T>
polynomial<T> compute_chebyshev_polynomial_second_kind_recursive(int);

template<typename T>
polynomial<T> compute_chebyshev_polynomial_first_kind_fast(T);

template<typename T>
polynomial<T> compute_chebyshev_polynomial_second_kind_fast(T);


//*****************************************************************************************************************************
//FUNÇÕES
//Função que computa polinômios de Chebyshev do primeiro tipo recursivamente
template<typename T>
polynomial<T> compute_chebyshev_polynomial_first_kind_recursive(int n){

  //Variáveis locais
  polynomial<T> t0, t1, t2, p;
  univariate_monomial<T> poly_term;


  //Procedimentos
    //Ajuste de polinômios
    poly_term.coefficient=1; poly_term.power=0;
    t0.monomials.insert({poly_term.power, poly_term});//p(x)=1
    poly_term.coefficient=1; poly_term.power=1;
    t1.monomials.insert({poly_term.power, poly_term});//p(x)=x
    poly_term.coefficient=2; poly_term.power=1;
    p.monomials.insert({poly_term.power, poly_term});//p(x)=2x



    //Casos bases:
    if(n==0) return t0;
    if(n==1) return t1;

    //Loop principal
    for(int i=2; i<=n; ++i){
      polynomial<T> temp=p*t1;
      t2=temp-t0;

      //Atualizando variáveis para a próxima iteração
      t0=t1;
      t1=t2;
  
    }


  //Resultado
  return t2;

};


//Função que computa polinômios de Chebyshev do segundo tipo recursivamente
template<typename T>
polynomial<T> compute_chebyshev_polynomial_second_kind_recursive(int n){

  //Variáveis locais
  polynomial<T> t0, t1, t2, p;
  univariate_monomial<T> poly_term;


  //Procedimentos
    //Ajuste de polinômios
    poly_term.coefficient=1; poly_term.power=0;
    t0.monomials.insert({poly_term.power, poly_term});//p(x)=1
    poly_term.coefficient=2; poly_term.power=1;
    t1.monomials.insert({poly_term.power, poly_term});//p(x)=2x
    poly_term.coefficient=2; poly_term.power=1;
    p.monomials.insert({poly_term.power, poly_term});//p(x)=2x



    //Casos bases:
    if(n==0) return t0;
    if(n==1) return t1;

    //Loop principal
    for(int i=2; i<=n; ++i){
      polynomial<T> temp=p*t1;
      t2=temp-t0;

      //Atualizando variáveis para a próxima iteração
      t0=t1;
      t1=t2;
  
    }


  //Resultado
  return t2;

};


//Função que computa polinômios de Chebyshev do primeiro tipo usando exponenciação de polinômios
template<typename T>
polynomial<T> compute_chebyshev_polynomial_first_kind_fast(T n){

  //Variáveis locais
  struct chebyshev_struct<T> cheby1, cheby2, cheby_pn1, cheby_pn2;
  univariate_monomial<T> poly_term;


  //Procedimentos
    //Ajuste de variáveis
    poly_term.coefficient=1; poly_term.power=1;
    (cheby1.a).monomials.insert({poly_term.power, poly_term});//p(x)=x
    poly_term.coefficient=(-1); poly_term.power=0;
    (cheby1.b).monomials.insert({poly_term.power, poly_term});//p(x)=(-1)
    (cheby1.d)=generate_chebyshev_d_polynomial<T>();//p(x)=x^2-1

    poly_term.coefficient=1; poly_term.power=1;
    (cheby2.a).monomials.insert({poly_term.power, poly_term});//p(x)=x
    poly_term.coefficient=1; poly_term.power=0;
    (cheby2.b).monomials.insert({poly_term.power, poly_term});//p(x)=1
    (cheby2.d)=generate_chebyshev_d_polynomial<T>();//p(x)=x^2-1

    //Computando potências dos polinômios
    cheby_pn1=chebyshev_exponentiation<T>(cheby1, n);
    cheby_pn2=chebyshev_exponentiation<T>(cheby2, n);

    //Computando o resultado
    polynomial<T> result=(cheby_pn1.a)+(cheby_pn2.a);
    for(auto& pair:result.monomials) pair.second.coefficient>>=1;


  //Resultado
  return result;

};


//Função que computa polinômios de Chebyshev do segundo tipo usando exponenciação de polinômios
template<typename T>
polynomial<T> compute_chebyshev_polynomial_second_kind_fast(T n){

  //Variáveis locais
  struct chebyshev_struct<T> cheby1, cheby2, cheby_pn1, cheby_pn2;
  univariate_monomial<T> poly_term;


  //Procedimentos
    //Ajuste de variáveis
    poly_term.coefficient=1; poly_term.power=1;
    (cheby1.a).monomials.insert({poly_term.power, poly_term});//p(x)=x
    poly_term.coefficient=1; poly_term.power=0;
    (cheby1.b).monomials.insert({poly_term.power, poly_term});//p(x)=1
    (cheby1.d)=generate_chebyshev_d_polynomial<T>();

    poly_term.coefficient=1; poly_term.power=1;
    (cheby2.a).monomials.insert({poly_term.power, poly_term});//p(x)=x
    poly_term.coefficient=(-1); poly_term.power=0;
    (cheby2.b).monomials.insert({poly_term.power, poly_term});//p(x)=-1
    (cheby2.d)=generate_chebyshev_d_polynomial<T>();


    //Computando potências dos polinômios
    cheby_pn1=chebyshev_exponentiation<T>(cheby1, n+1);
    cheby_pn2=chebyshev_exponentiation<T>(cheby2, n+1);


    //Computando o resultado
    polynomial<T> result=(cheby_pn1.b)-(cheby_pn2.b);
    for(auto& pair:result.monomials) pair.second.coefficient>>=1;


  //Resultado
  return result;

};


//*****************************************************************************************************************************
//FIM DO HEADER
#endif
