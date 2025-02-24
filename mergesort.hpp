//VAMOS CRIAR UM PROGRAMA QUE IMPLEMENTA O ALGORITMO MERGESORT PARA ORDENAR ELEMENTOS EM UM ARRAY

//**************************************************************************************************************************
//CABEÇALHO
#ifndef MERGESORT_H
#define MERGESORT_H
#include<iostream>

//**************************************************************************************************************************
//FUNÇÕES
namespace mergesort{


//Função que particiona um array em dois subarrays e combina os seus valores
template<typename T>
void merge(T array[], int left, int mid, int right){

  //Gerando dois subarrays para alocar os elementos do array principal
  T subarray1[mid - left + 1];
  T subarray2[right - mid];

  //Alocando os elmentos do array prncipal nos subarays
  for(int i = 0; i<(mid-left+1); ++i)
  subarray1[i] = array[(left + i)];

  for(int j = 0; j<(right-mid); ++j)
    subarray2[j] = array[(mid + 1 + j)];


  //Combinandos os subarray com os elementos em ordem crescente
    //Variáveis locais
    int k=0, l=0, m=left;

    //Procedimentos
    while(k<(mid-left+1) && l<(right-mid)){
      if(subarray1[k]<=subarray2[l]){
        array[m] = subarray1[k];
        ++k;
      }
      else{
        array[m] = subarray2[l];
        ++l;
      };
      ++m;
    };

    //Adicionando os elementos remanescentes
    while(k<(mid-left+1)){
      array[m] = subarray1[k];
      ++k;
      ++m;
    };

    while(l<(right-mid)){
      array[m] = subarray2[l];
      ++l;
      ++m;
    };


};

//Função principal do algoritmo
template<typename T>
void mergesort(T array[], int left , int right){

  //Caso base o array contém menos de dois elementos
  if(left>= right) return;

  //Caso geral: divide-se o array em dois subarrays
    //Variáveis locais
    int mid = (right+left)/2;

    //Chamada recursiva do algoritmo
    mergesort(array, left, mid);
    mergesort(array, mid+1, right);

    //Combinando dois subarray em um único array
    merge(array, left, mid, right);

};

                   }//Fim do namespace mergesort


//**************************************************************************************************************************
//FIM DO HEADER
#endif
