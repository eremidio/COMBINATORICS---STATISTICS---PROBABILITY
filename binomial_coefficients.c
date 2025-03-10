//VAMOS CRIAR UM PROGRAMA PARA TESTAR AS ROTINAS CRIADAS NO ARQUIVO binomial_coefficients.h
//COMPILAR ESTE PROGRAMA COM O COMANDO: gcc -o binomial_coefficients binomial_coefficients.c -lgmp


//Cabeçalho
#include"binomial_coefficients.h"


//Função principal
int main(){

  //Variáveis locais
  int64_t n, m;

  //Procedimentos
    //Recebendo input dos usuários
    printf("[Inteiro] n: ");
    scanf("%li", &n);
    printf("[Inteiro] m(<n): ");
    scanf("%li", &m);

    //Computando o coeficiente binomial C(n, m)
    binomial_coefficient(n, m);
 

  //Finalziando a aplicação
  return 0;

}
