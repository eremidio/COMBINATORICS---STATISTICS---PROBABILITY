//VAMOS CRIAR UM PROGRAMA PARA TESTAR AS RORINAS CRIADAS NO ARQUIVO set_partition.hpp
//COMPILAR ESTE PROGRAMA COM O COMANDO: g++ -o set_partition set_partition.cpp 

// Cabeçalho
#include "set_partition.h"
using namespace std;


// Função principal
int main() {

  //Instanciando um objeto da classe
  set_partition_class<char> my_sp;


  //Executando o algoritmo
  my_sp.run();  

  // Finalizando a aplicação
  return 0;
}
