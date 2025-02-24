//VAMOS CRIAR UM PROGRAMA QUE IMPLMENTA O ALGORITMO SELECTION SORT PARA ORDENAR ELEMENTOS EM UM ARRAY


//***************************************************************************************************************************
//CABEÇALHO
#ifndef SELECTION_SORT_H
#define SELECTION_SORT_H

//***************************************************************************************************************************
//FUNÇÕES
namespace selectionsort{

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
void selectionsort(T array[], int n){

  //Variáveis locais
  int i, j;
  T minimum;

  //Procedimento
    //Loop principal
    for(i=0; i<n; ++i){
  
      //Selecionando o menor elemento
      minimum=array[i];
    
      //Iterando para encontrar o menor elemento do array
      for(j=i; j<n; ++j){
        if(array[j]<minimum){
          minimum=array[j];
          swap_elements(array, i, j);
        };

      };

    };

};

                       }//Fim do namespace selectionsort




//***************************************************************************************************************************
//FIM DO HEADER
#endif

