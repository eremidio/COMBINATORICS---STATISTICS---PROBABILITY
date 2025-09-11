//VAMOS CRIAR UM PROGRAMA PARA TESTAR AS ROTINAS CRIADAS NO ARQUIVO lambert_w_function.h
//COMPILAR ESTE PROGRAMA COM O COMANDO: gcc -o lambert_w_function lambert_w_function.c -lm -O2


//Cabeçalho
#include"lambert_w_function.h"
#include<stdio.h>


//Função principal
int main(){

  //Variáveis locais
  double z;

  //Procedimento
    //Recebendo input do usuário
    printf("[Real] z: ");
    if(scanf("%lf", &z)!=1) return 0;

    //Calculando W(0, z) usando o método de Halley
    double W0_z=lambert_w_function_continued_recursive(z);
    printf("[ramo principal, via aproximação de Halley] W(0, %.2lf)=%.9lf\n", z, W0_z);


  //Finalizando a aplicação
  return 0;
}
