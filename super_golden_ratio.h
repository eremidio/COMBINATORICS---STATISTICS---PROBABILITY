//VAMOS CRIAR UM PROGRAMA PARA COMPUTAR A SUPER RAZÃO DE OURO USANDO RELAÇÕES RECURSIVAS


/*

A SUPER RAZÃO DE OURO ψ É DEFINIDA COMO A ÚNICA SOLUÇÃO REAL DO POLINÔMIO p(x)=x³-x²-1. POR SER DEFINIDA COMO A RAÍZ DE UM
POLINÔMIO DE TERCEIRO GRAU ASSIM COMO A RAZÃO PLÁSTICA ρ, AMBAS DAS CONSTANTES COMPARTILHAM MUITAS PROPRIEDADES EM COMUM 
SATISFAZENDO IDENTIDADES SEMELHANTES. AMBAS DAS CONSTANTES PERTENCEM AO CONJUNTO DOS NÚMEROS DE PISOT.

AS SEGUINTES FÓRMULAS SÃO ÚTEIS PARA SE COMPUTAR ψ:
PARA 1/ψ: x=(2x³+1)/(3x²+1)
PARA 1/ψ: x=(x²+1)^(1/3)
EM TERMOS DE FUNÇÕES HIPERBÓLICAS: 1/ψ = (2/√3){sinh[(1/3)arsinh((3√3)/2)]}

PARA MAIORES INFORMAÇÕES: https://en.wikipedia.org/wiki/Supergolden_ratio#
                          https://en.wikipedia.org/wiki/Pisot–Vijayaraghavan_number#Small_Pisot_numbers
                          https://github.com/eremidio/COMBINATORICS---STATISTICS---PROBABILITY/blob/main/plastic_ratio.h


*/

//*******************************************************************************************************************************************
//CABEÇALHO
#ifndef SUPER_GOLDEN_RATIO_H
#define SUPER_GOLDEN_RATIO_H
#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<math.h>
#include<gmp.h>


//CONSTANTE GLOBAL
const long double super_golden_ratio=(sqrt(3.0)/2.0)/(sinh((1.0/3.0)*asinh(3*sqrt(3)/2)));


//*******************************************************************************************************************************************
//DECLARAÇÃO DE FUNÇÕES
void compute_super_golden_ratio(mpf_t);


//*******************************************************************************************************************************************
//FUNÇÕES
//Função que computa a super razão de ouro usando o método de Newton-Raphson
void compute_super_golden_ratio(mpf_t super_golden_ratio){

  //Variáveis locais
  mpf_t v1, v2, v3, num, den, x, one, two, three;
  mpf_init2(v1, 4096);
  mpf_init2(v2, 4096);
  mpf_init2(v3, 4096);
  mpf_init2(num, 4096);
  mpf_init2(den, 4096);
  mpf_init2(x, 4096);
  mpf_init2(one, 4096);
  mpf_init2(two, 4096);
  mpf_init2(three, 4096);


  //Procedimento
    //Ajuste de variáveis
    mpf_set_d(one, 1.0);
    mpf_set_d(two, 2.0);
    mpf_set_d(three, 3.0);
    mpf_set_d(x, 10.0);


    //Loop principal: computando a super razão de ouro 
    for(int i=0; i<1000; ++i){

      //Numerador
      mpf_pow_ui(v1, x, 3);
      mpf_mul(v2, v1, two);
      mpf_add(v3, v2, one);
      mpf_set(num, v3);

      //Denominador
      mpf_pow_ui(v1, x, 2);
      mpf_mul(v2, v1, three);
      mpf_add(v3, v2, one);
      mpf_set(den, v3);

      //Atualizando variáveis      
      mpf_div(x, num, den);

    }

    //Resultado
    mpf_div(super_golden_ratio, one, x);

  
  //Limpando o cachê de mémoria
  mpf_clear(x);
  mpf_clear(one);
  mpf_clear(two);
  mpf_clear(three);
  mpf_clear(v1);
  mpf_clear(v2);
  mpf_clear(v3);
  mpf_clear(num);
  mpf_clear(den);

};

//*******************************************************************************************************************************************
//FIM DO HEADER
#endif
