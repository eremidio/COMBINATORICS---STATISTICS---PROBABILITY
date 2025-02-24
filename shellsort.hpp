//VAMOS CRIAR UM PROGRAMA QUE IMPLEMENTA O ALGORITMO SHELLSORT PARA ORDENAR ELEMENTOS EM UM ARRAY


//************************************************************************************************************************
//CABEÇALHO
#ifndef SHELLSORT_H
#define SHELLSORT_H
#include<utility>
#include<algorithm>
 
//************************************************************************************************************************
//FUNÇÕES
namespace shellsort{

//Função que implementa o algoritmo shellsort
template<class T>
void shellsort(T array[], int n){

  //Variáveis locais
  int gap, i ,j;


   //Procedimento
   for(gap=n/2; gap>0; gap/=2){

     for(i=gap; i<n; ++i){
  
       for(j=i-gap; j>=0; j-=gap){
         if(array[j]>array[j+gap])
           std::swap(array[j], array[j+gap]);
         else  continue;
       };

      };

    };

};

                   }//Fim do namespace shellsort


//************************************************************************************************************************
//FIM DO HEADER
#endif

