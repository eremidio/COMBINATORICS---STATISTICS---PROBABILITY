//VAMOS CRIAR UM PROGRAMA PARA TESTAR AS ROTINAS CRIADAS NO ARQUIVO q_analog_cobinatorics.h
//COMPILAR ESTE PROGRAMA COM O COMANDO: g++ -o q_analog_combinatorics q_analog_combinatorics.cpp


//Cabeçalho
#include"q_analog_combinatorics.h"
using namespace std;


//Função principal
int main(){

  //Variáveis locais
  polynomial<int64_t> q_fact, q_bin;
  int64_t n, m, factorial, binomial_coefficient;

  //Procedimentos 
    //Recebendo input do usuário
    cout<<"[Inteiro] n: "; cin>>n;
    cout<<"[Inteiro] m(<n): "; cin>>m;


    //Cálculando o q-fatorial
    q_fact=q_factorial<int64_t>(n);
    cout<<"\n["<<n<<"](q): ";

    for(auto it=q_fact.monomials.begin(); it!=q_fact.monomials.end(); ++it){
      cout<<"("<<it->second.coefficient<<")q^";
      cout<<it->second.power;
      if(it->second.power>0) cout<<"+";
    }
    cout<<"\n\n";
    
    factorial=polynomial_evaluation<int64_t, int64_t>(q_fact, 1);
    cout<<n<<"! = "<<factorial<<'\n';


    //Calculando os coeficientes gaussianos
    q_bin=q_binomial_coefficient<int64_t>(n, m);
    cout<<"\n["<<n<<", "<<m<<"](q): ";

    for(auto it=q_bin.monomials.begin(); it!=q_bin.monomials.end(); ++it){
      cout<<"("<<it->second.coefficient<<")q^";
      cout<<it->second.power;
      if(it->second.power>0) cout<<"+";
    }
    cout<<"\n\n";
    
    binomial_coefficient=polynomial_evaluation<int64_t, int64_t>(q_bin, 1);
    cout<<"C("<<n<<", "<<m<<") = "<<binomial_coefficient<<'\n';


  //Finalizando a aplicação
  return 0;  

}

