//VAMOS CRIAR UM PROGRAMA QUE COMPUTA OS COEFICIENTES BINOMIAIS NO TRIÂNGULO DE PASCAL DE FORMA RECURSIVA
  
/*

PARA MAIORES INFORMAÇÕES: https://github.com/eremidio/COMBINATORICS---STATISTICS---PROBABILITY/blob/main/pascal_triangle.h

*/ 


//******************************************************************************************************
//CABEÇALHO
#ifndef PASCAL_TRIANGLE_RECURSIVE_H
#define PASCAL_TRIANGLE_RECURSIVE_H
#include<stdint.h>
#include<vector>


//******************************************************************************************************
//DECLARAÇÃO DE FUNÇÕES
template<typename T>
std::vector<std::vector<T>> generate_pascal_triangle_recursively(int64_t);


//******************************************************************************************************
//FUNÇÕES

//Função que 
template<typename T>
std::vector<std::vector<T>> generate_pascal_triangle_recursively(int64_t n){


  //Variáveis locais
  std::vector<std::vector<T>> pascal_triangle;
  std::vector<T> first_row={1}, second_row={1,1};
  int64_t i, j;


  //Procedimentos
    //Casos bases: n≲2
    if(n<1) return pascal_triangle;
    pascal_triangle.push_back(first_row);
    if(n==1) return pascal_triangle;
    pascal_triangle.push_back(second_row);
    if(n==2) return pascal_triangle;

    //Loop principal: adicionando as demais linhas recursivamente
    for(i=2; i<n; ++i){

      //Adicionando elementos da próxima linha
      std::vector<T> next_row={1};
      for(int64_t j=1; j<i; ++j) next_row.push_back((pascal_triangle[i-1][j]+pascal_triangle[i-1][j-1]));
      next_row.push_back(1);

      //Adicionando a próxima linha
      pascal_triangle.push_back(next_row);
 

    };//Fim do loop principal


  //Resultado
  return pascal_triangle;

};

//******************************************************************************************************
//FIM DO HEADER
#endif
