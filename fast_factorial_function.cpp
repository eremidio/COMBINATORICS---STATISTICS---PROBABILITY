//VAMOS CRIAR UM PROGRAMA PARA TESTAR AS ROTINAS CRIADAS NO ARQUIVO fast_factorial_function.h
//COMPILAR ESTE PROGRAMA COM O COMANDO: g++ -o fast_factorial_function fast_factorial_function.cpp -lboost_system -O2


//Cabeçalho
#include"fast_factorial_function.h"
using namespace std;

//Função principal
int main(){

  //Variáveis locais
  int32_t n;


  //Procedimentos
    //Recebendo input do usuário
    cout<<"[Inteiro] n: ";
    cin>> n;

    //Computando n!
    cpp_int fact=p_adic_factorial(n);
    cout<<n<<"! = "<<fact<<'\n';


  //Finalizando a aplicação
  return 0;

}
