//VAMOS CRIAR UM PROGRAMA QUE COMPUTA A SUPER RAZÃO DE PRATA USANDO RELAÇÕES RECURSIVAS

/*

A SUPER RAZÃO DE PRATA ζ É DEFINIDA COMO A ÚNICA SOLUÇÃO REAL DO POLINÔMIO p(x)=x³-2x²-1. POR SER DEFINIDA COMO A RAÍZ DE UM
POLINÔMIO DE TERCEIRO GRAU ASSIM COMO A RAZÃO PLÁSTICA ρ, AMBAS DAS CONSTANTES COMPARTILHAM MUITAS PROPRIEDADES EM COMUM
SATISFAZENDO IDENTIDADES SEMELHANTES. AMBAS DAS CONSTANTES PERTENCEM AO CONJUNTO DOS NÚMEROS DE PISOT.

AS SEGUINTES FÓRMULAS SÃO ÚTEIS PARA SE COMPUTAR ζ:
PARA 1/ζ: x=(2x³+1)/(3x²+2)
PARA 1/ζ: x= √[(-1)+√(1+x)]
EM TERMOS DE FUNÇÕES HIPERBÓLICAS: 1/ζ=(-2)√(2/3){sinh[(1/3)arsinh(((-3/4)√(3/2))]}


PARA MAIORES INFORMAÇÕES: https://en.wikipedia.org/wiki/Supersilver_ratio#
                          https://en.wikipedia.org/wiki/Silver_ratio

*/ 


//*******************************************************************************************************************************************
//CABEÇALHO
#ifndef SUPER_SILVER_RATIO_H
#define SUPER_SILVER_RATIO_H
#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<math.h>
#include<gmp.h>


//CONSTANTE GLOBAL
const long double super_silver_ratio=sqrt(1.5)/((-2)*(sinh((1.0/3.0)*asinh((-0.75)*sqrt(1.5)))));


//*******************************************************************************************************************************************
//DECLARAÇÃO DE FUNÇÕES
void compute_super_silver_ratio(mpf_t);


//*******************************************************************************************************************************************
//FUNÇÕES
//Função que computa a super razão de prata usando relações recursivas
void compute_super_silver_ratio(mpf_t super_silver_ratio){

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

    //Loop principal: computando a super razão de prata usando a relação recursiva
    for(int i=0; i<1000; ++i){
      mpf_add(v1, one, x);
      mpf_sqrt(v2, v1);
      mpf_sub(v3, v2, one);
      mpf_sqrt(x, v3);
  
    };
 
  //Resultado
  mpf_div(super_silver_ratio, one, x);

  
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
