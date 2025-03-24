//VAMOS CRIAR UM PROGRAMA PARA TESTAR AS ROTINAS CRIADAS NO ARQUIVO stirling_triangle.h
//COMPILAR ESTE PROGRAMA COM O COMANDO: g++ -o  stirling_triangle stirling_triangle.cpp


//Cabeçalho
#include"stirling_triangle.h"
using namespace std;


//Função principal
int main(){

  //Variáveis locais
  int64_t n;


  //Procedimentos
    //Recebendo input do usuário
    cout<<"[Inteiro] n: ";
    cin>> n;


    //Computando o triângulo de números de Stirling do primeiro tipo
    vector<vector<uint64_t>> stirling_triangle1 = compute_stirling_triangle_first_kind<uint64_t>(n);

    cout<<"Triângulo de números de Stirling do primeiro tipo: \n";
    for(auto line: stirling_triangle1){
      for (auto c:line) cout<<c<<" ";
      cout<<'\n';
  
    }
    cout<<'\n';

    //Computando o triângulo de números de Stirling do segundo tipo
    vector<vector<uint64_t>> stirling_triangle2 = compute_stirling_triangle_second_kind<uint64_t>(n);

    cout<<"Triângulo de números de Stirling do segundo tipo: \n";
    for(auto line: stirling_triangle2){
      for (auto c:line) cout<<c<<" ";
      cout<<'\n';
  
    }
    

  // Finalizando a aplicação
  return 0;

}
