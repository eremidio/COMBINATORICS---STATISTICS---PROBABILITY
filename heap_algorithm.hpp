//VAMOS CRIAR UM PROGRAM QUE IMPLMENTA O ALGORITMO DE HEAP PARA GERA PERMUTAÇÕES EM UM CONJUNTO


/*
  
O ALGORITMO DE HEAP É UM EFICIENTE ALGORITMO PARA GERAR PERMUTAÇÕES (ORDENAÇÕES DE ELEMENTOS) EM
UM CONJUNTO. PARA CONJUNTOS COM n ELEMENTOS O NÚMERO TOTAL DE PERMUTAÇÕES É IGUAL A n!.

PARA REFERÊNCIAS: https://sedgewick.io/wp-content/uploads/2022/03/2002PermGeneration.pdf
                  https://en.wikipedia.org/wiki/Heap%27s_algorithm
*/

//******************************************************************************************************************
//CABEÇALHO
#ifndef HEAP_PERMUTATION_H
#define HEAP_PERMUTATION_H
#include<algorithm>
#include<vector>
#include<utility>
#include<iostream>


//******************************************************************************************************************
//CLASSE DO ALGORITMO
template<typename T>
class heap_algorithm{
    public:

  //Membros da classe
  std::vector<T> basic_set;
  std::vector<T> index_vector;
  int set_size;


  //Métodos da classe
  void run();
  void setup();
  void print_permutation();
  void generate_permutations();

};




//******************************************************************************************************************
//MÉTODOS DA CLASSE
//Função principal
template<typename T>
void heap_algorithm<T>::run(){

  //Recebendo input do usuário
  setup();

  //Gerando permutações e printando-as na tela
  generate_permutations();

};

//Função que recebe input do usuário
template<typename T>
void heap_algorithm<T>::setup(){

  //Variáveis locais 
  T element;

  //Procedimentos
    //Recebendo input do usuário
    std::cout<<"[Inteiro] Número de elementos no conjunto: ";
    std::cin>>set_size;
  
    basic_set.resize(0);//Ajuste de variáveis

    for(int i=0; i<set_size; ++i){
      std::cout<<(i+1)<<"º elemento: ";
      std::cin>>element;
      basic_set.push_back(element);
    };

    //Printando a partição inicial
    std::cout<<"\n";
    print_permutation();

};


//Função que printa permutações 
template<typename T>
void heap_algorithm<T>::print_permutation(){


  int i=0;//Variável de controle
  std::cout<<"{";
  for(auto y:basic_set){

    if(i==(basic_set.size()-1)){
      std::cout<<y;
      std::cout<<"}\n";
      break;
    }
    else
      std::cout<<y<<",";
      ++i;


    };

};


//Função que implmenta o algoritmo de Heap e gera permutações de um conjunto
template<typename T>
void heap_algorithm<T>::generate_permutations(){

  //Variáveis locais
  int i;

  
  //Procedimento
    //Ajuste do vetor de indexes
    index_vector.resize(0);

    for(int i =0; i<set_size; ++i)
      index_vector.push_back(0);
      i=1;

      //Loop principal
      while(i<set_size){
        if(index_vector[i]<i){
          if(i%2==0) std::swap(basic_set[0], basic_set[i]);
          else std::swap(basic_set[index_vector[i]], basic_set[i]);
          print_permutation();
          index_vector[i]=index_vector[i]+1;
          i=1;
        }

        else{
          index_vector[i]=0;
          ++i;
        };

    };
     
};


//******************************************************************************************************************
//FIM DO HEADER
#endif

