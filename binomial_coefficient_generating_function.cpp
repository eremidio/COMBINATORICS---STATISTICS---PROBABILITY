//VAMOS CRIAR UM PROGRAMA PARA TESTA AS ROTINAS CRIADAS NO ARQUIVO binomial_coefficient_generating_function.h
//COMPILAR ESTEPROGRAMA COMO COMANDO: g++ -o binomial_coefficient_generating_function binomial_coefficient_generating_function.cpp -O2


//Cabeçalho
#include"binomial_coefficient_generating_function.h"
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
    cout<<"[Inteiro] n: ";
    cin>>n;

    //Computando os coeficientes binomiais
    bivariate_polynomial<cpp_int> bc_generating_function=compute_binomial_coefficients_generating_function<cpp_int>(n);

    for(auto  it=bc_generating_function.monomials.begin(); it!=bc_generating_function.monomials.end(); ++it)
      cout<<"C("<<it->second.y_valuation<<", "<<it->second.x_valuation<<")= "<<it->second.coefficient<<", ";
    cout<<'\n';


  //Finalizando a aplicação
  return 0;
  
}
