//VAMOS CRIAR UM PROGRAMA PARA IMPLEMENTAR O ALGORITMO QUICKSORT PARA ORDENAR ELEMENTOS EM UM ARRAY 

//**************************************************************************************************************************
//CABEÇALHO
#ifndef QUICKSORT_H
#define QUICKSORT_H
#include<iostream>

//**************************************************************************************************************************
//FUNÇÕES

namespace quicksort{ 
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


template<typename T>
void quicksort(T array[], int left, int right){

  //Variáveis locais
  int i , last;

  //Procedimentos
    //Caso base: o array contém somente 2 elementos no máximo
    if(left>=right) return;

    //Caso geral:
      //Selecionandoo elemento pivotal e o movendo para a posição inicial
      swap_elements(array, left, (left+right)/2);
      last=left;

      //Iterando sobre uma partição de left+1, ..., right separando os lementos em duas sublistas maiores ou menores que um dado elemento pivotal
      for(i = left+1; i<=right; ++i){
        if(array[i]<array[left])
          swap_elements(array, ++last, i);
      };

      //Retornando o elemento pivotal a sua posição original
      swap_elements(array, left, last);


    //Chamada recursiva do algoritmo
    quicksort(array, left, last-1);
    quicksort(array, last+1, right);

};

                   }//Fim do namespace quicksort


//**************************************************************************************************************************
//FIM DO HEADER
#endif 
