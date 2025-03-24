//VAMOS CRIAR UM PROGRAMA PARA TESTAR AS ROTINAS CRIADAS NO ARQUIVO stirling_numbers_first_kind.h
//COMPILAR ESTE PROGRAMA COM O COMANDO: g++ -o stirling_numbers_first_kind stirling_numbers_first_kind.cpp


//Cabeçalho
#include"stirling_numbers_first_kind.h"
using namespace std;


//Função principal
int main(){

  //Variáveis locais
  polynomial<int64_t> falling_factorial, rising_factorial;
  std::vector<int64_t> stirling_vector;
  int64_t n;


  //Procedimento
    //Recebendo input do usuário
    cout<<"[Inteiro] n: ";
    cin>>n;


    //Computando os fatoriais ascendente e descedente
    falling_factorial=compute_falling_factorial<int64_t>(n);
    rising_factorial=compute_rising_factorial<int64_t>(n);

    cout<<"x(+, "<<n<<") = "<<rising_factorial.algebraic()<<'\n';
    cout<<"x(-, "<<n<<") = "<<falling_factorial.algebraic()<<'\n';


    //Computando os números de Stirling do primeiro tipo
    stirling_vector = compute_signed_stirling_numbers_first_kind<int64_t>(10);

    for(int64_t j=0; j<=10; ++j) cout<<"s(10, "<<j<<")= "<<stirling_vector[j]<<", ";
    cout<<"...\n";


  //Finalizando a aplicação
  return 0;

}


