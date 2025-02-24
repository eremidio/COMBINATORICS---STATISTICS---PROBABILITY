//VAMOS CRIAR UM PROGRAMA QUE IMPLEMENTA ROTINAS PARA SE CALCULAR COEFICIENTES GAUSSIANOS E COEFICIENTES BINOMIAIS


/*

SEJA q(n) = (q; q)(n) = Π{1-(q^k)} k=1,2,..., n; OS SÍMBOLOS DE Q-POCHHAMMER. OS COEFICIENTES GAUSSIANOS (OU
COEFICIENTES Q-BINOMIAIS) SÃO DEFINIDOS PELA FÓRMULA [n, m] = {q(n)}/{q(m)q(n-m)}. NO LIMITE q->1 A SEGUINTE
RELAÇÃO É VÁLIDA [n, m]=C(n, m), ONDE C(n,m) DENOTA O COEFICIENTE BINOMIAL C(n,m) = n!/[m!(n-m)!].

OS COEFICIENTES GAUSSIANOS SATISFAZEM IDENTIDADES ANÁLOGAS AOS COEFICIENTES BINOMIAIS ORDINÁRIOS, POR EXEMPLO,
A IDENTIDADE DE PASCAL [n,m]=(q^m)[(n-1), m]+[(n-1), (m-1)].

CORRESPODENDO A DEFINIÇÃO USUAL DE FATORIAL n!=1.2.3...(n-1).n, PODEMOS DEFINIR O Q-FATORIAL PELA IDENTIDADE: 
[n](q)=(1+q)(1+q+q²)...(1+q+...+q^[n-1]). DESTA  DEFINIÇÃO É ÓBVIO A CORRESPONDÊNCIA NO LIMITE q->1: [n](q)=n!.

O USO DE SÍMBOLOS DE Q-POCHHAMMER SÃO ÚTEIS EM MANIPULAÇÕES SÍMBÓLICAS EM PROBLEMAS DE ANÁLISE COMBINATÓRIA.

PARA MAIORES INFORMAÇÕES: Number Theory in the Spirit of Ramanujan by Bruce C. Berndt
                          https://mathworld.wolfram.com/q-Factorial.html
                          https://mathworld.wolfram.com/q-BinomialCoefficient.html


*/


//****************************************************************************************************************
//CABEÇALHO
#ifndef Q_ANALOG_COMBINATORICS_H
#define Q_ANALOG_COMBINATORICS_H
#include"q_pochhammer_symbol.h"
#include<assert.h>


//****************************************************************************************************************
//DECLARAÇÃO DE FUNÇÕES
template<typename T>
polynomial<T> q_factorial(int64_t);

template<typename T>
polynomial<T> q_binomial_coefficient(int64_t, int64_t);

//****************************************************************************************************************
//FUNÇÃO
//Função que calcula o q-fatorial [n](q)
template<typename T>
polynomial<T> q_factorial(int64_t n){

  //Variáveis locais
  polynomial<T> q_factorial, q_partial;
  univariate_monomial<T> q_term;


  //Procedimentos
    //Calculando o primeiro termo da sequência (1+q)
    q_term.coefficient=1;  q_term.power=0;
    q_factorial.monomials.insert({q_term.power, q_term});
    q_term.coefficient=1;  q_term.power=1;
    q_factorial.monomials.insert({q_term.power, q_term});

    //Adicionando mais termos da sequência
    q_partial= q_factorial;
    if(n==1) return q_factorial;  

    for(int64_t i=2; i<n; ++i){

      q_term.coefficient=1;  q_term.power=q_term.power+1;
      q_partial.monomials.insert({q_term.power, q_term});

      q_factorial=q_factorial*q_partial;

    };

  //Resultado
  return q_factorial;

};


//Função que calcula os coeficients q-binomiais
template<typename T>
polynomial<T> q_binomial_coefficient(int64_t n, int64_t m){

  //Restrição
  assert(n>=0 && m>=0);
  
  //Caso base
  if(n<m){
    polynomial<T> q_symbol;
    univariate_monomial<T> q_term;
    q_symbol.monomials.insert({q_term.power, q_term});
    return q_symbol;
  }

  //Variáveis locais
  polynomial<T> qn=compute_q_pochhammer_symbol<T>(n);
  polynomial<T> qm=compute_q_pochhammer_symbol<T>(m);
  polynomial<T> qnm=compute_q_pochhammer_symbol<T>(n-m);


  //Procedimentos
    //Calculando o coeficiente gaussiano [n, m] = {q(n)}/{q(m)q(n-m)}
    qn=qn/qm;
    qn=qn/qnm;

  //Resultado
  return qn;

};

//****************************************************************************************************************
//FIM DO HEADER
#endif
