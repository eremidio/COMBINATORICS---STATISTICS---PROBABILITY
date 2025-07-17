//VAMOS CRIAR UM PROGRAMA PARA TESTAR AS ROTINAS CRIADAS NO ARQUIVO pentagonal_number_generating_function.h
//COMPILAR ESTE PROGRAMA COM O COMANDO: g++ -o pentagonal_number_generating_function pentagonal_number_generating_function.cpp -O2


//Cabeçalho
#include"pentagonal_number_generating_function.h"
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
    polynomial<int64_t> pentagonal_generating_function = compute_pentagonal_number_generating_function<int64_t>(n);
    cout<<"[Parcial da função geradora dos "<<n<<"-ésimos primeiros números pentagonais] p(x) = ...+ "
        <<pentagonal_generating_function.algebraic()<<"\n\n";

    cout<<n<<"-ésimos primeiros números pentagonais: ";
    for(auto it=pentagonal_generating_function.monomials.begin(); it!=pentagonal_generating_function.monomials.end(); ++it)
      cout<<"P("<<it->first<<")= "<<it->second.coefficient<<", ";
    cout<<"...\n";


  //Resultado
  return 0;

} 
