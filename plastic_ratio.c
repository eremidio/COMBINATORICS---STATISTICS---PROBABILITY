//VAMOS CRIAR UM PROGRAMA PARA TESTAR AS ROTINAS CRIADAS NO ARQUIVO plastic_ratio.h
//COMPILAR ESTE PROGRAMA COM O COMANDO: gcc -o plastic_ratio plastic_ratio.c -lgmp -lm


//Cabeçalho
#include"plastic_ratio.h"


//Função principal
int main(){

  //Variáveis locais
  mpf_t rho;
  mpf_init2(rho, 4096);


  //Procedimento
    //Computando a razão plástica em termos de funções hiperbólicas
    printf("[Em termos de funções hiperbólicas- double] ρ: %.9Lf\n", plastic_ratio);

    //Computando a razão plástica usando recursão e a biblioteca gmp
    compute_plastic_ratio(rho);
    printf("[Usando recursão e a biblioteca gmp] ρ: ");
    gmp_printf("%.500Ff\n", rho);

    //Limpando o cachê de memória
    mpf_clear(rho);

  //Finalizando a aplicação
  return 0;

}
