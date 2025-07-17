//VAMOS CRIAR UM PROGRAMA QUE TESTA AS ROTINAS CRIADAS NO ARQUIVO triangular_number_generating_function.h
//COMPILAR ESTE PROGRAMA COM O COMANDO: g++ -o triangular_number_generating_function triangular_number_generating_function.cpp -O2


//Cabeçalho
#include"triangular_number_generating_function.h"
using namespace std;


//Função principal
int main(){

  //Variáveis locais
  uint64_t n;
  

  //Procedimento
    //Recebendo input do usuário
    cout<<"[Inteiro] n: ";
    cin>>n;

    //Computando a parcial da função geradora dos n primeiros números triangulares
    polynomial<int64_t> triangular_generating_function = compute_triangular_number_generating_function<int64_t>(n);
    cout<<"[Parcial da função geradora dos "<<n<<"-ésimos primeiros números triangulares] p(x) = ...+ "
        <<triangular_generating_function.algebraic()<<"\n\n";

    cout<<n<<"-ésimos primeiros números triangulares: ";
    for(auto it=triangular_generating_function.monomials.begin(); it!=triangular_generating_function.monomials.end(); ++it)
      cout<<"T("<<it->first<<")= "<<it->second.coefficient<<", ";
    cout<<"...\n";


  //Resultado
  return 0;

} 
