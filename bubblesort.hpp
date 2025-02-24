//VAMOS CRIAR UM PROGRAMA QUE IMPLEMENTA O ALGORITMO BUBBLESORT PARA ORDENAR ELEMENTOS EM UM ARRAY


//************************************************************************************************************************
//CABEÇALHO
#ifndef BUBBLESORT_H
#define BUBBLESORT_H
#include<utility>
#include<algorithm>
 
//************************************************************************************************************************
//FUNÇÕES
namespace bubblesort{

template<class T>
void bubblesort(T array[], int n){

  //Definição de variáveis auxialiares
  int i , j;

    //Procedimentos
    if (n>=2){
      for(i=0; i<n;i++){
        for(j=1;i+j<n; j++){
          if(array[i]>array[i+j]){
            std::swap(array[i], array[i+j]);
          };
        };
      };
    };

};



                   }//Fim do namespace bubblesort


//************************************************************************************************************************
//FIM DO HEADER
#endif

