//VAMOS CRIAR UM PROGRAMA QUE GERA COMBINAÇÕES EM UM CONJUNTO USANDO GRAY-CODES

/*

UM GRAY-CODE É UMA STRING BINÁRIA QUE ENCODA INFORMAÇÕES SOBRE UM CONJUNTO DE ELEMENTOS. TAIS 
STRINGS BINÁRIAS PODEM SER USADAS PARA COMPUTAR COMBINAÇÕES EM UM CONJUNTO DA SEGUINTE FORMA:
TOMANDO VALORES DE 1 ATÉ (2^n)-1 , ONDE n É O NÚMERO DE ELEMENTOS DO CONJUNTO; CONSIDERAMOS AS
STRINGS BINÁRIAS QUE CONTÉM UM NÚMERO k≲ n DE BITS 1. INDEXANDO OS ELEMENTOS DO CONJUNTO POR
1-> INCLUSO E 0-> EXCLUSO, TEMOS EXATAMENTE AS COMBINAÇÕES DE k ELEMENTOS DESSE CONJUNTO. TAL
PROCESSO NÃO É VANTAJOSO PARA CONJUNTOS DE MUITOS ELEMENTOS n>40, PORÉM TEM A VANTAGEM DE TER
UM BAIXO REQUERIMENTO DE MEMÓRIA, POIS APENAS OS VALORES QUE CORRESPONDENTES A COMBINAÇÕES
PRECISAM SER ESTOCADOS.


PARA MAIORES INFORMAÇÕES: https://www.baeldung.com/cs/generate-k-combinations

*/ 



//**************************************************************************************************
//CABEÇALHO
#ifndef COMBINATION_GRAY_CODE_H
#define COMBINATION_GRAY_CODE_H
#include<iostream>
#include<bitset>
#include<vector>
#include<cmath>


//**************************************************************************************************
//CLASSE DO ALGORITMO
template<typename T>
class combination_class{
    public:

  //Membros da classe
  uint64_t bit_setter;
  std::vector<uint64_t> combination_vector;
  std::vector<T> element_vector;
  int n, k;

  //Procedimentos
  void run();
  void setup();
  void compute_combinations();
  void show_combinations();

};


//**************************************************************************************************
//MÉTODOS DA CLASSE
//Função que printa uma combinação de elementos
template<typename T>
void combination_class<T>::show_combinations(){

  //Variáveis locais
  int bit_position;


  //Procedimentos
    //Loop principal: iterando sobre valores numéricos que encodam combinações de k elementos
    for(auto n:combination_vector){

      bit_position=0;
      std::cout<<"{ ";

      while(n>0){

        if(n&1){
          std::cout<<element_vector[bit_position]<<", ";        
        }

        bit_position++;
        n>>=1;

      }  
      std::cout<<"}\n";

    };//Fim do loop principal

};


//Função que computa combinações testando a quantidade de bits em string binárias
template<typename T>
void combination_class<T>::compute_combinations(){

  //Loop principal: iterando sobre possíveis strings binárias de n elemntos com k bits 1
  for(uint64_t i=1; i<=bit_setter; ++i){

    std::bitset<64> bit_string(i);
    if(bit_string.count()==k) combination_vector.push_back(i); 

  }

};



//Função que recebe input do usuário
template<typename T>
void combination_class<T>::setup(){

  //Definindo o número de elementos do conjunto e de cada combinação
  std::cout<<"[Número de elementos no conjunto] n: ";
  std::cin>>n;
  std::cout<<"[Número de elementos em cada combinação] k: ";
  std::cin>>k;

  bit_setter=static_cast<uint64_t>(pow(2, n)-1);


  //Definindo elemntos do conjunto
  for(int i=0; i<n; ++i){
    T element;
    std::cout<< (i+1)<<"º elemento do conjunto: ";
    std::cin>> element;
    element_vector.push_back(element);

  };


};


//Função principal do algoritmo
template<typename T>
void combination_class<T>::run(){

  //Recebendo input do usuário
  setup();
  
  //Computando combinações
  compute_combinations();

};


//**************************************************************************************************
//FIM DO HEADER
#endif
