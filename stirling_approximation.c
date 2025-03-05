//VAMOS CRIAR UM PROGRAMA PARA TESTAR AS FUNÇÕES CRIADAS NO ARQUIVO stirling_approximation.h
//COMPILAR ESTE PROGRAMA COM O COMANDO: gcc -o stirling_approximation stirling_approximation.c -lgmp



//Cabeçalho
#include"stirling_approximation.h"


//Função principal
int main(){

  //Variáveis locais
  int64_t n;

  //Procedimentos
    //Recebendo input do usuário
    printf("[Inteiro] n: ");
    if(scanf("%li",&n) !=1) return 0;

    //Calculando o fatorial exato de n
    exact_factorial(n);

    //Calculando a aproximação via fórmula de Stirling
    stirling_approximation(n);


  //Finalizando a aplicação
  return 0;

}
