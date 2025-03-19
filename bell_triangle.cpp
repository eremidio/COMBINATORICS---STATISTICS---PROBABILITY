//VAMOS CRIAR UM PROGRAMA QUE TESTA AS ROTINAS CRIADAS NO ARQUIVO bell_triangle.h
//COMPILAR ESTE PROGRAMA COM O COMANDO: g++ -o bell_triangle bell_triangle.cpp 


//Cabeçalho
#include"bell_triangle.h"
using namespace std;


//Função principal
int main(){

  //Variáveis locais
  int64_t n;


  //Procedimentos
    //Recebendo input do usuário
    cout<<"[Inteiro] n: ";
    cin>>n;

    //Computando os números de Bell
    std::vector<uint64_t> bell_set=compute_bell_numbers<uint64_t>(n, Yes);

    cout<<"Sequência de números de Bell: ";
    for(auto e:bell_set) cout<<e<<", ";
    cout<<"...\n";

  //Finalizando a aplicação
  return 0;

}

