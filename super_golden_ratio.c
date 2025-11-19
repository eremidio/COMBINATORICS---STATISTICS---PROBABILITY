//VAMOS CRIAR UM PROGRAMA PARA TESTAR AS ROTINAS CRIADAS NO ARQUIVO super_golden_ratio.h
//COMPILAR ESTE PROGRAMA COM O COMANDO: gcc -o super_golden_ratio super_golden_ratio.c -lm -lgmp


//Cabeçalho
#include"super_golden_ratio.h"


//Função principal
int main(){

  //Variáveis locais
  mpf_t psi;
  mpf_init2(psi, 4096);


  //Procedimento
    //Computando a super razão de ouro em termos de funções hiperbólicas
    printf("[Em termos de funções hiperbólicas- double] ψ: %.10Lf\n", super_golden_ratio);

    //Computando a super razão de ouro usando recursão e a biblioteca gmp
    compute_super_golden_ratio(psi);
    printf("[Usando recursão e a biblioteca gmp] ψ: ");
    gmp_printf("%.500Ff\n", psi);

    //Limpando o cachê de memória
    mpf_clear(psi);

  //Finalizando a aplicação
  return 0;

}
