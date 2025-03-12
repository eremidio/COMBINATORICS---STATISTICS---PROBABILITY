//VAMOS CRIAR UM PROGRAMA PARA TESTAR AS ROTINAS CRIADAS NO ARQUIVO combinations.h 
//COMPILAR ESTE PROGRAMA COM O COMANDO: g++ -o combinations combinations.cpp



//Cabeçalho
#include"combinations.h"
using namespace std;


//Função principal
int main(){

  //Inicializando um elemento da classe
  combination_class<char> trial;

  //Executando o algoritmo de gerar combinações
  trial.run();
  cout<<"\n";

  //Exibindo combinações
  trial.show_combinations();

  //Finalizando a aplicação
  return 0;

}
