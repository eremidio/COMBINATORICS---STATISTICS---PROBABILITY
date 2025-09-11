//VAMOS CRIAR UM PROGRAMA PARA COMPUTAR A FUNÇÃO W DE LAMBERT NO RAMO PRINCIPAL

/*

PARA UM NÚMERO COMPLEXO z, A FUNÇÃO W DE LAMBERT É DEFINIDA PELA RELAÇÃO W(z)e^{W(z)}=z. TAL FUNÇÃO É MULTIRAMIFICADA DE FORMA QUE
PARA UM MESMO ARGUMENTO MÚLTIPLOS VALORES W(k, z) PARA k = ...,-2,-1, 0, 1, 2, ... PODEM SER ASSOCIADOS. DE FORMA GERAL O
COMPORTAMENTO DA FUNÇÃO W(k, z) É COMPLICADO, EMBORA ALGUNS RESULTADOS GERAIS COMO O FATO DA FUNÇÃO SER INJETIVA E DISJUNTA PARA 
TODO ARGUMENTO COMPLEXO z POSSAM SER ESTABELECIDOS. DE GRANDE INTERESSE EM APLICAÇÕES É O CASO NO QUAL O ARGUMENTO DA FUNÇÃO z É
REAL, NESTE CASO APENAS W(0, z) DEFINIDO PARA z≳0 E W(-1, z) DEFINIDO PARA (-1)/e<z<0 (e É O NÚMERO DE EULER) SÃO SIGNICATIVOS.
Ω= W(0, 1) É DENOMINADA CONSTANTE OMEGA, UM ANÁLOGO DA RAZÃO DE OURO PARA A FUNÇÃO EXPONENCIAL.

PARA O RAMO PRINCIPAL DA FUNÇÃO (k=0) EXISTEM FÓRMULAS PARA SE COMPUTAR A DERIVADA DERIVADA DE QUALQUER ORDEM DA FUNÇÃO W(z), UMA
SÉRIE DE RELAÇÕES ENVOLVENDO INTEGRAIS DESSA FUNÇÃO PODE SER FACILMENTE OBTIDA A PARTIR DE SUA DEFINIÇÃO. PARA COMPUTAR  W(0, z) E
W(-1, z), EXISTEM VÁRIOS MÉTODOS BASEADOS EM DIFERENTES TÉCNICAS COMO EXPANSÃO EM SÉRIES DE POTÊNCIAS ENVOLVENDO O LOGARITMOS DO
ARGUMENTO DA FUNÇÃO (Li1=ln(z) E Li2=ln(ln(z))), EXPANSÃO EM FRAÇÕES CONTINUADAS, RECURSÃO BASEADA NO MÉTODO DE NEWTON-RAPHSON (OU
HALLEY) E NAS FÓRMULAS PARA AS DERIVADAS DE VÁRIAS ORDENS [W'(z), W''(z), ...] DA FUNÇÃO W, ENTRE OUTROS.

TAL FUNÇÃO É RECORRENTE EM DIVERSAS ÁREAS DA MATEMÁTICA COMO ESTATÍSTICA, EQUAÇÕES DIFERENCIAIS, ÁLGEBRA, ENTRE OUTRAS; ALÉM DE
TER DIVERSAS APLICAÇÕES EM FÍSICA (MECÂNICA QUÂNTICA, MECÂNICA DOS FLUÍDOS, MECÂNICA ESTATÍSTICA, ENTRE OUTROS), BIOQUÍMICA
(DINÂMICA DA CINÉTICA QUÍMICA DE ENZIMAS), ENTRE OUTRAS ÁREAS DA CIÊNCIA.


PARA MAIORES INFORMAÇÕES: https://en.wikipedia.org/wiki/Lambert_W_function
                          https://mathworld.wolfram.com/LambertW-Function.html
                          https://mathworld.wolfram.com/OmegaConstant.html
                          https://en.wikipedia.org/wiki/Liouvillian_function

*/


//*********************************************************************************************************************************
//CABEÇALHO
#ifndef LAMBERT_W_FUNCTION_H
#define LAMBERT_W_FUNCTION_H
#include<stdlib.h>
#include<assert.h>
#include<math.h>

//CONSTANTES GLOBAIS
const double LAMBERT_W_BOUND=1E-9;
const double LAMBERT_W_MAX_ITER=1000;


//*********************************************************************************************************************************
//DECLARAÇÃO DE FUNÇÕES
double lambert_w_function_continued_recursive(double);


//*********************************************************************************************************************************
//FUNÇÕES
//Função que computa W(0, z) usando o método de Halley
double lambert_w_function_continued_recursive(double x){

  //Caso base
  if (x == 0.0) return 0.0;


  //Variáveis locais
  double w = (x < 1.0) ? x : log(x);

  //Procedimentos
    //Loop principal
    for(int i=0; i<LAMBERT_W_MAX_ITER; ++i){

      double e = exp(w);
      double we = w * e;
      double diff = we - x;
      double denom = e * (w + 1.0) - ((w + 2.0) * diff) / (2.0 * w + 2.0);
      double w_new = w - diff / denom;

      if (fabs(w_new - w) < LAMBERT_W_BOUND)  return w_new;
      w = w_new;

    };


  //Resultado
  return w;

};

//*********************************************************************************************************************************
//FIM DO HEADER
#endif
