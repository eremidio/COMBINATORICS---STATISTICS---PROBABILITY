//VAMOS CRIAR UM PROGRAMA QUE IMPLEMENTA O ALGORITMO INSERTIONSORT PARA ORDENAR ELEMENTOS EM UM ARRAY


//************************************************************************************************************************
//CABEÇALHO
#ifndef INSERTIONSORT_H
#define INSERTIONSORT_H
#include<utility>
#include<algorithm>
 
//************************************************************************************************************************
//FUNÇÕES
namespace insertionsort{

//Função que implementa o algoritmo insertionsort
template<class T>
void insertionsort(T array[], int n){

  //Variáveis auxiliares
  int i, j;

    //Procedimentos executáveis
    if(n>=2){
      for (i=1; i<=n-1; i++){
        for(j=0; j<i; j++){
          if(array[i]<array[j]){
            std::swap(array[i],array[j]); continue;
          };
        };

      };
    };

};


                       }//Fim do namespace insertionsort

//************************************************************************************************************************
//FIM DO HEADER
#endif


