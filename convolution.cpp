//VAMOS CRIAR UM PROGRAMA QUE TESTA AS ROTINAS CRIADAS NO ARQUIVO convolution.h
//COMPILAR ESTE PROGRAMA COM O COMANDO: g++ -o convolution convolution.cpp

// Cabeçalho
#include "convolution.h"
using namespace std;

//Função principal
int main() {

  //Variáveis locais
  vector<int> set1, set2;
  size_t size1, size2;
  int e;

  //Procedimentos
    //Recebendo input do usuário:
    cout<<"[Inteiro] Número de elementos do conjunto 1: ";
    cin>>size1;
    cout<<"[Inteiro] Número de elementos do conjunto 2: ";
    cin>>size2;

    for(size_t i=0; i<size1; ++i){
      cout<<"[Inteiro] "<<(i+1)<<"º elemento do conjunto  1: ";
      cin>>e;
      set1.push_back(e);
    }

    for(size_t i=0; i<size2; ++i){
      cout<<"[Inteiro] "<<(i+1)<<"º elemento do conjunto 2: ";
      cin>>e;
      set2.push_back(e);
    }

    //Exibindo os conjuntos
    cout<<"Conjunto 1: { "; for(auto e1:set1) cout<<e1<<","; cout<<" }\n";
    cout<<"Conjunto 2: { "; for(auto e2:set2) cout<<e2<<","; cout<<" }\n";

    //Calculando a convolução dos dois conjuntos
    vector<int> convoluted_set=convolution<int>(set1, set2);
    cout<<"[Convolução] Conjunto 3: { "; for(auto e3:convoluted_set) cout<<e3<<","; cout<<" }\n";
  



  // Finalizando a aplicação
  return 0;
}
