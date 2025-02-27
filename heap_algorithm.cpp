//VAMOS CRIAR UM PROGRAMA QUE TESTA A SROTINAS CRIADAS NO ARQUIVO heap_algorithm.hpp
//COMPILAR ESTE PROGRAMA COM O COMANDO: g++ -o heap_algorithm heap_algorithm.cpp -O2

//Cabeçalho
#include"heap_algorithm.hpp"

//Função principal
int main(){

  //Instanciando um objeto da classe
  heap_algorithm<char> trial;
  trial.run();

  //Finalizando a aplicação
  return 0;

}

