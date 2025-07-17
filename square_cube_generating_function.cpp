//VAMOS CRIAR UM PROGRAMA PARA TESTAR AS ROTINAS CRIADAS NO ARQUIVO square_cube_generating_function.h
//COMPILAR ESTE PROGRAMA COMO COMANDO: g++ -o square_cube_generating_function square_cube_generating_function.cpp -O2


//Cabeçalho
#include"square_cube_generating_function.h"
using namespace std;


//Função principal
int main(){

  //Variáveis locais
  uint64_t n;
  

  //Procedimento
    //Recebendo input do usuário
    cout<<"[Inteiro] n: ";
    cin>>n;

    //Computando a parcial da função geradora dos n primeiros quadrados perfeitos
    polynomial<int64_t> squares_generating_function = compute_perfect_square_generating_function<int64_t>(n);
    cout<<"[Parcial da função geradora dos "<<n<<"-ésimos primeiros quadrados perfeitos] p(x) = ...+ "
        <<squares_generating_function.algebraic()<<"\n\n";

    cout<<n<<"-ésimos primeiros quadrados perfeitos]: ";
    for(auto it=squares_generating_function.monomials.begin(); it!=squares_generating_function.monomials.end(); ++it)
      cout<<it->second.coefficient<<", ";
    cout<<"...\n";


    //Computando a parcial da função geradora dos n primeiros cubos perfeitos
    polynomial<int64_t> cubes_generating_function = compute_perfect_cube_generating_function<int64_t>(n);
    cout<<"\n[Parcial da função geradora dos "<<n<<"-ésimos primeiros cubos perfeitos] q(x) = ...+ "
        <<squares_generating_function.algebraic()<<"\n\n";

    cout<<n<<"-ésimos primeiros cubos perfeitos]: ";
    for(auto it=cubes_generating_function.monomials.begin(); it!=cubes_generating_function.monomials.end(); ++it)
      cout<<it->second.coefficient<<", ";
    cout<<"...\n";



  //Resultado
  return 0;

} 
