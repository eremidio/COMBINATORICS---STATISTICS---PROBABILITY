//VAMOS CRIAR UM PROGRAMA PARA TESTAR AS ROTINAS CRIADAS NO ARQUIVO polygonal_numbers_generating_function.h
//COMPILAR ESTE PPROGRAMA COM O COMANDO: g++ -o polygonal_numbers_generating_function polygonal_numbers_generating_function.cpp -O2


//Cabeçalho
#include"polygonal_numbers_generating_function.h"
using namespace std;


//Função principal
int main(){

  //Variáveis locais
  uint64_t n;
  int s=6; //Parâmetro fixo para a sequência de números hexagonais

  //Procedimento
    //Recebendo input do usuário
    cout<<"[Inteiro] n: ";
    cin>>n;

    //Computando a parcial da função geradora dos n primeiros números triangulares
    polynomial<int64_t> hexagonal_generating_function = compute_polygonal_number_generating_function<int64_t>(n, s);
    cout<<"[Parcial da função geradora dos "<<n<<"-ésimos primeiros números hexagonais] p(x) = ...+ "
        <<hexagonal_generating_function.algebraic()<<"\n\n";

    cout<<n<<"-ésimos primeiros números hexagonais: ";
    for(auto it=hexagonal_generating_function.monomials.begin(); it!=hexagonal_generating_function.monomials.end(); ++it)
      cout<<"H("<<it->first<<")= "<<it->second.coefficient<<", ";
    cout<<"...\n";


  //Resultado
  return 0;

}
  
