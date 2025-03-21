//VAMOS CRIAR UM PROGRAMA QUE CRIA PARTIÇÕES DE UM CONJUNTO 

/*
DADO UM CONJUNTO DE ELEMENTOS, DIGAMOS {a, b, c}, PARTIÇÕES DE UM CONJUNTO SÃO CONJUNTOS DE SUBCONJUNTOS NÃO VAZIOS DESTE 
CONJUNTOS QUE SATISFAZEM A SEGUINTES CONDIÇÕES:
1. CADA ELEMENTO ESTÁ EM UM ÚNICO SUBCONJUNTO.
2. A INTERSEÇÃO DE SUBCONJUNTOS É NULA.

NESTE EXEMPLOS COM TRÊS ELEMENTOS A PARTIÇÃO É DADA POR: {{a},{b},{c}}; {{a, b},{c}}; {{a, c},{b}}; {{b, c},{a}};
{{a, b, c}}.

O NÚMERO DE PARTIÇÕES DE UM CONJUNTO COM n ELEMENTOS É CHAMADO DE n-ÉSIMO NÚMERO DE BELL. NESTE  EXEMPLO B(3)=5.
PARA UMA VERSÃO OTIMIZADA VER ARTIGO NAS REFERÊNCIAS.

PARA MAIORES INFORMAÇÕES: https://en.wikipedia.org/wiki/Partition_of_a_set
                          https://www.ideserve.co.in/learn/set-partition-problem-recursion
                          https://academic.oup.com/comjnl/article-abstract/31/3/283/417197?redirectedFrom=PDF

*/

//*********************************************************************************************************************************************
//CABEÇALHO
#ifndef SET_PARTITION_H
#define SET_PARTITION_H
#include<iostream>
#include<vector>


//*********************************************************************************************************************************************
//CLASSE DO ALGORITMO
template<typename T>
class set_partition_class{
    public:

  //Membros da classe
  std::vector<int> code_word;
  std::vector<T> element_set;
  int n;


  //Métodos da classe
  void setup();
  void print_partition();
  void generate_partitions(int, int);
  void run();

};


//*********************************************************************************************************************************************
//MÉTODOS DA CLASSE
//Função principaldo algoritmo
template<typename T>
void set_partition_class<T>::run(){

  //Recebendo input do usuário e ajustando variáveis 
  setup();
  std::cout<<'\n';

  //Gerando as partições recursivamente
  generate_partitions(0,1);

};


//Função que recebe input do usuário e ajusta parâmetros do algoritmo
template<typename T>
void set_partition_class<T>::setup(){

  //Variáveis locais
  T element;

  //Definindo o número de conjuntos do elemento
  std::cout<<"[Número de elemntos no algoritmo] n: ";
  std::cin>>n;

  //Definindo os elementos do conjunto e o vetor de indexes de subconjuntos
  for(int i=0; i<n; ++i){

    std::cout<<(i+1)<<"º elemento do conjunto: ";
    std::cin>>element;

    element_set.push_back(element);
    code_word.push_back(0);//Vetor de indexes de subconjuntos nos quais elementos

  };

};

//Função que printa uma partição
template<typename T>
void set_partition_class<T>::print_partition(){

  //Loop: principal iterando sobre os indexes de subconjuntos
  std::cout<<"{";

  for(int i=0; i<n; ++i){//i é o index do subconjunto
    std::cout<<"{";
    for(int j=0; j<n; ++j){//j indexa os elementos do conjunto original
      if(code_word[j]==i) std::cout<< element_set[j]<<", ";
    }
    std::cout<<"}, ";

  }
  std::cout<<"}\n";

};

//Função que gera as partições de forma recursiva
template<typename T>
void set_partition_class<T>::generate_partitions(int m, int p){

  //Caso base
  if(p>=n){
     print_partition();
     return;
  }


  //Loop principal: gerando partições de forma recursiva
  for(int i=0; i<=m; ++i){
    code_word[p]=i;
    generate_partitions(m, p+1);
  }

  code_word[p]=(m+1);
  generate_partitions((m+1), (p+1));


};


//*********************************************************************************************************************************************
//FIM DO HEADER
#endif
