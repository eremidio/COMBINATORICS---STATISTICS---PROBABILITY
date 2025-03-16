//VAMOS CRIAR UM PROGRAMA QUE TESTA AS ROTINAS CRIADAS NO ARQUIVO pascal_triangle
//COMPILAR ESTE PROGRAMA COM O COMANDO: g++ -o pascal_triangle pascal_triangle.cpp -lboost_system -O2

// Cabeçalho
#include"pascal_triangle.h"
#include<boost/multiprecision/cpp_int.hpp>
#include<boost/cstdint.hpp>
using namespace boost::multiprecision;
using namespace std;


// Função principal
int main() {

  //Variáveis locais
  int64_t n;


  //Procedimentos
    //Recebendo input do usuário
    cout<<"[Inteiro] n: ";
    cin>> n;

    //Computando a n-ésima linha do triângulo de Pascal
    vector<cpp_int> pascal_line=compute_nth_row<cpp_int>(n);

    cout<<n<<"ª linha do triângulo de Pascal: ";
    for(auto e:pascal_line) cout<<e<<", ";
    cout<<"...\n";


    //Recebendo input do usuário
    cout<<"[Inteiro] número de linhas no triângulo de Pascal: ";
    cin>> n;

    //Computando o triângulo de Pascal
    vector<vector<cpp_int>> pascal_triangle=generate_pascal_triangle<cpp_int>(n);

    for(auto line: pascal_triangle){
      for (auto c:line) cout<<c<<" ";
      cout<<'\n';
  
    }

    
  // Finalizando a aplicação
  return 0;
}
