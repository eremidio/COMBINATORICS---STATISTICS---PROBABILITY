//VAMOS CRIAR UM PROGRAMA QUE TESTA AS ROTINAS CRIADAS NO ARQUIVO chebyshev_polynomials.h
//COMPILAR ESTE PROGRAMA COM O COMANDO: g++ -o chebyshev_polynomials chebyshev_polynomials.cpp -O2


//Cabeçalho
#include"chebyshev_polynomials.h"
#include<boost/multiprecision/cpp_int.hpp>
#include<boost/cstdint.hpp>
using namespace boost::multiprecision;
using namespace std;


//Função principal
int main(){

  //Variáveis locais
  int n;

  //Procedimentos
    //Recebendo input do usuário
    cout<<"[Inteiro] n:";
    cin>>n;

    //Computando polinômios de Chebyshev usando recursão (pequenos valores de n)
    cout<<"Fórmula recursiva.\n";
    polynomial<int64_t> Tn=compute_chebyshev_polynomial_first_kind_recursive<int64_t>(n);
    polynomial<int64_t> Un=compute_chebyshev_polynomial_second_kind_recursive<int64_t>(n);

    cout<<"T("<<n<<", x)= "<<Tn.algebraic()<<'\n';
    cout<<"U("<<n<<", x)= "<<Un.algebraic()<<'\n';


    //Computando polinômio usando exponenciação de polinômios
    int64_t n_=n;

    polynomial<int64_t> Tn1=compute_chebyshev_polynomial_first_kind_fast<int64_t>(n_);
    polynomial<int64_t> Un1=compute_chebyshev_polynomial_second_kind_fast<int64_t>(n_);

    cout<<"\nFórmula usando exponenciação polynomial.\n";
    cout<<"T("<<n_<<", x)= "<<Tn1.algebraic()<<'\n';
    cout<<"U("<<n<<", x)= "<<Un1.algebraic()<<'\n';


  //Finalizando a aplicação
  return 0;

}
