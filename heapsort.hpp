//VAMOS CRIAR UM PROGRAMA  EM C++ QUE IMPLEMENTA O ALGORITMO HEAPSORT PARA ORDENAR ELEMENTOS EM UM ARRAY

/*

NOTA: HEAPS SÃO ÁRVORES BINÁRIAS COMPLETAS NAS QUAIS OS ELEMENTOS QUE SE RAMIFICAM A PARTIR DE CADA NÓ ESTÃO EM ORDEM CRESCENTE
(MIN HEAP) OU ORDEM DECRESCENTE (MAX HEAP) SENDO MUITO ÚTEIS PARA IMPLEMENTAR QUEUES COM ORDEMDE PRIORIDADES.

PARA MAIORES INFORMAÇÕES: https://en.wikipedia.org/wiki/Heap_(data_structure)


*/


//************************************************************************************************************************
//CABEÇALHO
#ifndef HEAPSORT_H
#define HEAPSORT_H
#include<cmath>

//************************************************************************************************************************
//FUNÇÕES

namespace heapsort{


//Função que muda dois elementos em um array de posição
template<typename T>
void swap_elements(T array[], int i, int j){

  //Variáveis locais
  T temp;
  
    //Procedimento
    temp=array[i];
    array[i]=array[j];
    array[j]=temp;

};

//Funções auxiliares de conversão de indexes para localizar indexes na heap a ser construída
int parent(int i){
  return std::floor((i-1)/2);
};

int leftchild(int i){
  return (2*i)+1;
};

int rightchild(int i){
  return (2*i)+2;
};

//Função auxiliar que ajusta os elementos em um array de modo a satisfazer a propriedade heap em ordem descrescente
template<typename T>
void siftdown(T array[], int start, int end){

  //Variáveis locais
  int swap, child, root;


  //Procedimentos
    //Ajuste de variáveis
    root=start;

    //Loop principal
    while(leftchild(root)<end){

      //Ajustando variáveis
      child=leftchild(root);//Bifurcação esquerda da raíz da heap
      swap=root;//Mantém controle do nó que deve ser reposicionado no heap

      //Checando se há um nó fora de posição
      if(array[child]>array[swap])  swap=child;
      if((child+1)<end && array[child+1]>array[swap]) swap=(child+1);

      //Caso o maior elemento esteja alocado na raíz do heap este procedimento é encerrado
      if(swap ==root) return;

      //Caso contrário os nós no heap são reposicionados na ordem correta
      else{
        swap_elements(array, root, swap);
        root=swap;
      };

    };

};

//Função que produz uma heap em que os elementos de maiores elementos estão alocados em ordem decrescente
template<typename T>
void heapfy(T array[], int n){

  //Variáveis locais
  int start;

  //Procedimentos
    //Localizando o nó de ordem superior ao qual o último elemento do array está associado
    start=parent((n-1));

    //Loop principal que irá alocar os elementos do array em ordem de modo a satisfazer a propriedade heap
    while(start>=0){
      siftdown(array, start, (n-1));
      start-=1;
   };

};

//Função que implementa o algoritmo heapsort
template<typename T>
void heapsort(T array[], int n){

  //Variáveis locais
  int end=(n-1);


  //Procedimento
    //Construido uma heap a partir do array de elementos
    heapfy(array, n);

    //Loop principal: os elementos acima do index end são colocados em ordem (do fim chegando ao começo devido ao fato de usar uma max heap)
    while(end>=0){

      //O elemento máximo da heap está no index 0
      swap_elements(array, 0, end);
  
      //Reduzindo o tamanho da heap
      end-=1;

      //Restauarando a propriedade que caracteriza uma max heap
      siftdown(array, 0, end);
    };


    //Ajuste fino
    if(array[2]<array[1]) swap_elements(array, 1, 2);
    if(array[1]<array[0]) swap_elements(array, 0, 1);

};


                  }//Fim do namespace heapsort




//************************************************************************************************************************
//FIM DO HEADER
#endif




