//VAMOS CRIAR UM PROGRAMA PARA TESTAR AS ROTINAS CRIADAS NO ARQUIVO pascal_triangle_recursive.h
//COMPILAR ESTE PROGRAMA COM O COMANDO: g++ -o pascal_triangle_recursive pascal_triangle_recursive.cpp -O2


//Cabeçalho
#include"pascal_triangle_recursive.h"
#include<iostream>
using namespace std;


//Função principal
int main(){

  //Variáveis locais
  int64_t n;


  //Procedimentos
    //Recebendo input do usuário
    cout<<"[Inteiro] n: ";
    cin>> n;


    //Computando o triângulo de números eulerianos
    vector<vector<uint64_t>> pascal_triangle = generate_pascal_triangle_recursively<uint64_t>(n);

    cout<<"Triângulo de pascal: \n";
    for(auto line: pascal_triangle){
      for (auto c:line) cout<<c<<" ";
      cout<<'\n';
  
    }
    cout<<'\n';


  // Finalizando a aplicação
  return 0;

}
