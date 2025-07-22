//VAMOS CRIAR UM PROGRAMA PARA TESTAR AS ROTINAS CRIADAS NO ARQUIVO chebyshev_polynomials_generating_function.h
//COMPILAR ESTE PROGRAMA COM O COMANDO: g++ -o chebyshev_polynomials_generating_function chebyshev_polynomials_generating_function.cpp -O2


//Cabeçalho
#include"chebyshev_polynomials_generating_function.h"
using namespace std;


//Função principal
int main(){

  //Variáveis locais
  int64_t n;

  //Procedimentos
    //Recebendo input do usuário
    cout<<"[Inteiro] n: ";
    cin>> n;

    //Computando a função geradora dos polinômios de Chebyshev do primeiro tipo
    bivariate_polynomial<int64_t> first_cheby_generating_function = compute_first_kind_chebyshev_polynomial_generating_function<int64_t>(n);
    cout<<"[Função geradora dos polinômios de Chebyshev do primeiro tipo] F(x, y)= "<<first_cheby_generating_function.algebraic()<<"\n\n";

    for(int64_t j=0; j<=n; ++j){
      polynomial<int64_t> Tn=bivariate_univariate_polynomial_conversion<int64_t>(first_cheby_generating_function, j);
      cout<<"T("<<j<<", x) = "<<Tn.algebraic()<<'\n';
    }

    //Computando a função geradora dos polinômios de Chebyshev do segundo tipo
    bivariate_polynomial<int64_t> second_cheby_generating_function = compute_second_kind_chebyshev_polynomial_generating_function<int64_t>(n);
    cout<<"[Função geradora dos polinômios de Chebyshev do segundo tipo] F(x, y)= "<<second_cheby_generating_function.algebraic()<<"\n\n";

    for(int64_t j=0; j<=n; ++j){
      polynomial<int64_t> Un=bivariate_univariate_polynomial_conversion<int64_t>(second_cheby_generating_function, j);
      cout<<"U("<<j<<", x) = "<<Un.algebraic()<<'\n';
    }


  //Finalizando a aplicação
  return 0;

}
