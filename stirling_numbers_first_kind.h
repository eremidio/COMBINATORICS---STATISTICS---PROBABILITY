//VAMOS CRIAR UM PROGRAMA PARA COMPUTAR OS NÚMEROS DE STIRLING DO PRIMEIRO TIPO USANDO FUNÇÕES GERADORAS

/*

OS NÚMEROS DE STIRLING DO PRIMEIRO TIPO s(n,k) SÃO DEFINIDOS COMO OS COEFICIENTES DE EXPANSÃO DO POLINÔMIO FATORIAL
ASCENDENTE OU DESCENDENTE (SÍMBOLOS DE POCHHAMMER) p(-, x)= x(x-1)...(x-n+1) = Σ s(n,k)(x^k), RESPECTIVAMENTE
p(+, x)= x(x+1)...(x+n-1) = Σ s(n,k)(x^k)..

|s(n,k)| REPRESENTA O NÚMERO DE PERMUTAÇÕES DE n ELEMENTOS COM k CICLOS DISJUNTOS. POR EXEMPLO, SEJA O CONJUNTO
{1,2,3}. O TOTAL DE PERMUTAÇÕES DOS ELEMENTOS DESTE CONJUNTO É IGUAL A 3!=6. DESTAS HÁ UMA PERMUTAÇÃO COM CICLO 3
(123) A IDENTIDADE, PORTANTO s(3,3)=1, TRÊS PERMUTAÇÕES DE CICLO 2 (1)(23)--> {1,3,2}; (2)(13)--> {3,2,1}; (3)(12)-->
{2,1,3} E DUAS PERMUTAÇÕES DE CICLO 1 (132) --> {3,1,2} E (231) --> {2,3,1}.

OS NÚMEROS DE STIRLING DE PRIMEIRO TIPO POSSUEM RELAÇÃO DIRETA COM NÚMEROS DE STIRLING DE SEGUNDO TIPO E APARECEM EM
UM CONJUNTO DE RELAÇÕES IMPORTANTES ENVOLVENDO FUNÇÕES MATEMÁTICAS COMO A FUNÇÃO DE HURWITZ E A FUNÇÃO ZETA DE
RIEMANN, ALÉM DE SEREM RECORRENTES EM INÚMEROS PROBLEMAS DE ANÁLISE COMBINATÓRIA. PARA UMA LISTA MAIS COMPLETA DE 
RELAÇÕES E APLICAÇÕES VER REFERÊNCIAS.


PARA MAIORES INFORMAÇÕES: https://en.wikipedia.org/wiki/Stirling_numbers_of_the_first_kind
                          https://en.wikipedia.org/wiki/Stirling_number


*/



//****************************************************************************************************************
//CABEÇALHO
#ifndef STIRLING_NUMBER_FIRST_KIND_H
#define STIRLING_NUMBER_FIRST_KIND_H
#include"sparse_polynomials.h"
#include<algorithm>


//****************************************************************************************************************
//DECLARAÇÃO DE FUNÇÕES
template<typename T>
polynomial<T> compute_falling_factorial(int64_t);

template<typename T>
polynomial<T> compute_rising_factorial(int64_t);

template<typename T>
std::vector<T> compute_signed_stirling_numbers_first_kind(int64_t);

template<typename T>
std::vector<T> compute_unsigned_stirling_numbers_first_kind(int64_t);


//****************************************************************************************************************
//FUNÇÕES 
//Função que computa o polinômio fatorial descedente
template<typename T>
polynomial<T> compute_falling_factorial(int64_t n){

  //Variáveis locais
  polynomial<T> falling_factorial;
  univariate_monomial<T> poly_term;


  //Procedimentos
    //Adicionando o primeiro termo
    poly_term.power=1; poly_term.coefficient=1;
    falling_factorial.monomials.insert({poly_term.power, poly_term});

    //Calculando os demais termos
    for(int64_t i=1; i<n; ++i){
      polynomial<T> multiplier;

      poly_term.power=1; poly_term.coefficient=1;
      multiplier.monomials.insert({poly_term.power, poly_term});
      poly_term.power=0; poly_term.coefficient=((-1)*i);
      multiplier.monomials.insert({poly_term.power, poly_term});

      falling_factorial=falling_factorial*multiplier;    

    };

  //Resultado
  return falling_factorial;

};


//Função que computa o polinômio fatorial ascedente (símbolo de Pochhammer)
template<typename T>
polynomial<T> compute_rising_factorial(int64_t n){

  //Variáveis locais
  polynomial<T> rising_factorial;
  univariate_monomial<T> poly_term;


  //Procedimentos
    //Adicionando o primeiro termo
    poly_term.power=1; poly_term.coefficient=1;
    rising_factorial.monomials.insert({poly_term.power, poly_term});

    //Calculando os demais termos
    for(int64_t i=1; i<n; ++i){
      polynomial<T> multiplier;

      poly_term.power=1; poly_term.coefficient=1;
      multiplier.monomials.insert({poly_term.power, poly_term});
      poly_term.power=0; poly_term.coefficient=i;
      multiplier.monomials.insert({poly_term.power, poly_term});

      rising_factorial=rising_factorial*multiplier;    

    };

  //Resultado
  return rising_factorial;

};

//Função que computa os números de Stirling do primeiro tipo usando funções geradoras
template<typename T>
std::vector<T> compute_signed_stirling_numbers_first_kind(int64_t n){

  //Variáveis locais
  polynomial<T> stirling_polynomial= compute_falling_factorial<T>(n);
  std::vector<T> stirling_vector;


  //Procedimentos
    //Caso base 
    if(n==0){
      stirling_vector.push_back(1);
      return stirling_vector;
    }

     
    //Calculando os números de Stirling
    for(auto it=stirling_polynomial.monomials.begin(); it!=stirling_polynomial.monomials.end(); ++it){
      T s_nk=it->second.coefficient;
      stirling_vector.push_back(s_nk);
    }
    stirling_vector.push_back(static_cast<T>(0));
    std::reverse(stirling_vector.begin(), stirling_vector.end());

  //Resultado
  return stirling_vector;

};


//Função que computa os números de Stirling do primeiro tipo sem sinal usando funções geradoras
template<typename T>
std::vector<T> compute_unsigned_stirling_numbers_first_kind(int64_t n){

  //Variáveis locais
  polynomial<T> stirling_polynomial= compute_rising_factorial<T>(n);
  std::vector<T> stirling_vector;


  //Procedimentos
    //Caso base 
    if(n==0){
      stirling_vector.push_back(1);
      return stirling_vector;
    }

     
    //Calculando os números de Stirling 
    for(auto it=stirling_polynomial.monomials.begin(); it!=stirling_polynomial.monomials.end(); ++it){
      T s_nk=it->second.coefficient;
      stirling_vector.push_back(s_nk);
    }
    stirling_vector.push_back(static_cast<T>(0));
    std::reverse(stirling_vector.begin(), stirling_vector.end());

  //Resultado
  return stirling_vector;

};



//****************************************************************************************************************
//FIM DO HEADER
#endif
