//VAMOS CRIAR UM PROGRAMA PARA TESTAR AS ROTINAS CRIADAS NO ARQUIVO catalan_numbers.h
//COMPILAR ESTE PROGRAMA COM O COMANDO: g++ -o catalan_numbers catalan_numbers.cpp -O3 -lboost_system


//Cabeçalho
#include"catalan_numbers.h"
#include<boost/multiprecision/cpp_int.hpp>
#include<boost/cstdint.hpp>
using namespace boost::multiprecision;
using namespace std;


//Função principal
int main(){

  //Variáveis locais
  int64_t n;

  //Procedimentos
    //Recebendo input do usuário
    cout<<"[Inteiro] n:";
    cin>>n;

    //Computando a sequência de números de Catalan recursivamente
    std::vector<cpp_int> catalan_vector=generate_catalan_numbers_recursive<cpp_int>(n);
    
    for(auto i=0; i<catalan_vector.size(); ++i){
      cout<<"C("<<i<<") = "<<catalan_vector[i]<<", ";
    }
    cout<<"...\n";


    //Recebendo input do usuário
    cout<<"[Inteiro] n:";
    cin>>n;


    //Representando o n-ésimo número de Catalan usando palavras de Dyck
    string dyck_word=""/*Parâmetro fixo*/;

    cout<<"\nRepresentação do "<<n<<"-ésimo número de Catalan usando palavras de Dyck:\n";
    dyck_word_catalan_number_representation<int64_t>(n, 0/*Parâmetro fixo*/, 0/*Parâmetro fixo*/, 0/*Parâmetro fixo*/, dyck_word/*Parâmetro fixo*/);


  //Finalizando a aplicação
  return 0;

}
