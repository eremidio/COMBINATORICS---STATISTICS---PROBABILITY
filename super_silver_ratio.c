//VAMOS CRIAR UM PROGRAMA PARA TESTAR AS ROTINAS CRIADAS NO ARQUIVO super_silver_ratio.h
//COMPILAR ESTE PROGRAMA COM O COMANDO: gcc -o super_silver_ratio super_silver_ratio.c -lm -lgmp


//Cabeçalho
#include"super_silver_ratio.h"


//Função principal
int main(){

  //Variáveis locais
  mpf_t zeta;
  mpf_init2(zeta, 4096);


  //Procedimento
    //Computando a super razão de prata em termos de funções hiperbólicas
    printf("[Em termos de funções hiperbólicas- double] ζ: %.9Lf\n", super_silver_ratio);

    //Computando a super razão de prata usando recursão e a biblioteca gmp
    compute_super_silver_ratio(zeta);
    printf("[Usando recursão e a biblioteca gmp] ζ: ");
    gmp_printf("%.500Ff\n", zeta);

    //Limpando o cachê de memória
    mpf_clear(zeta);

  //Finalizando a aplicação
  return 0;

}
