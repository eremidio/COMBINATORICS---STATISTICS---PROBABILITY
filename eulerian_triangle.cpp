//VAMOS CRIAR UM PROGRAMA QUE TESTA AS ROTINAS CRIADAS NO ARQUIVO eulerian_triangle.h
//COMPILAR ESTE PROGRAMA COM O COMANDO: g++ -o eulerian_triangle  eulerian_triangle.cpp -O2


//Cabeçalho
#include"eulerian_triangle.h"
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
    vector<vector<uint64_t>> euler_triangle = compute_eulerian_triangle<uint64_t>(n);

    cout<<"Triângulo de números eulerianos: \n";
    for(auto line: euler_triangle){
      for (auto c:line) cout<<c<<" ";
      cout<<'\n';
  
    }
    cout<<'\n';


  // Finalizando a aplicação
  return 0;

}
