//VAMOS CRIAR UM PROGRAMA QUE COMPUTA A RAZÃO PLÁSTICA USANDO RELAÇÕES RECURSIVAS

/*

A RAZÃO PLÁSTICA ρ É DEFINIDA COMO A ÚNICA RAÍZ REAL DO POLINÔMIO p(x)=x³-x-1. USANDO O MÉTODO DE NEWTON-RAPHSON PODE-SE COMPUTAR ESTA
CONSTANTE DE FORMA RECURSIVA POR MEIO DA IDENTIDADE x=(2x³+1)/(3x²-1). É POSSÍVEL COMPUTAR ρ USANDO SUA EXPANSÃO EM FRAÇÕES INFINITAS
ENVOLVENDO RADICAIS x=√(1+1/x). 

A RAZÃO PLÁSTICA, TAL COMO A RAZÃO DE OURO φ APARECE EM VÁRIAS CONSTRUÇÕES GEOMÉTRICAS COMO NA PARTIÇÃO DE QUADRADOS NA PROPORÇÃO 1:3;
NA CONSTRUÇÃO DA ESPIRAL PLÁSTICA E DO PENTÁGONO PLÁSTICO; ALÉM DE SER EMPREGADA EM CERTOS ALGORITMOS DE INTERPOLAÇÃO POLINOMIAL.

A CONSTANTE ρ É USADA NA CONSTRUÇÃO DE CERTAS SEQUÊNCIAS NÚMERICAS (VAN DER LAAN, PERRIN) QUE PODEM SER USADAS EM TESTES DE
PRIMALIDADE E ESTÁ CONECTADA DIRETAMENTE A FUNÇÕES MODULARES COMO A FUNÇÃO INVARIANTE j(τ), A FUNÇÃO f(τ) DE RAMANUJAN-WEBER, A FUNÇÃO
ETA η(τ) DE DEDEKIND E A FUNÇÃO MODULAR λ(τ). EXISTE UMA EXPRESSÃO EXATA PARA ρ EM TERMOS DE FUNÇÕES HIPERBÓLICAS
ρ=(2√3){cosh[(1/3)acosh((3√3)/2)]}.


PARA MAIORES INFORMAÇÕES: https://en.wikipedia.org/wiki/Plastic_ratio#Properties


*/


//*******************************************************************************************************************************************
//DECLARAÇÃO DE FUNÇÕES
#ifndef PLASTIC_RATIO_H
#define PLASTIC_RATIO_H
#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<math.h>
#include<gmp.h>


//CONSTANTE GLOBAL
const long double plastic_ratio=(2.0/sqrt(3.0))*cosh((1.0/3.0)*acosh(3*sqrt(3)/2));


//*******************************************************************************************************************************************
//DECLARAÇÃO DE FUNÇÕES
void compute_plastic_ratio(mpf_t);


//*******************************************************************************************************************************************
//FUNÇÕES
//Função que computa a razão plástica
void compute_plastic_ratio(mpf_t plastic_ratio){

  //Variáveis locais
  mpf_t v1, v2, v3, x, one;
  mpf_init2(v1, 4096);
  mpf_init2(v2, 4096);
  mpf_init2(v3, 4096);
  mpf_init2(x, 4096);
  mpf_init2(one, 4096);



  //Procedimento
    //Ajuste de variáveis
    mpf_set_d(one, 1.0);
    mpf_set_d(x, 10.0);

    //Loop principal: computando a razão plástica usando a relação recursiva
    for(int i=0; i<1000; ++i){
      mpf_div(v1, one, x);
      mpf_add(v2, one, v1);
      mpf_sqrt(v3, v2);
      mpf_set(x, v3);
  
    };
 
  //Resultado
  mpf_set(plastic_ratio, v3);

  
  //Limpando o cachê de mémoria
  mpf_clear(x);
  mpf_clear(one);
  mpf_clear(v1);
  mpf_clear(v2);
  mpf_clear(v3);

};


//*******************************************************************************************************************************************
//FIM DO HEADER
#endif
