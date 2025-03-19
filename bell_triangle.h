//VAMOS CRIAR UM PROGRAMA QUE COMPUTA OS CHAMADOS NÚMEROS DE BELL USANDO TRIÂNGULOS DE BELL

/*

DADO UM CONJUNTO DE ELEMENTOS, DIGAMOS {a, b, c}, PARTIÇÕES DE UM CONJUNTO SÃO CONJUNTOS DE SUBCONJUNTOS NÃO VAZIOS DESTE 
CONJUNTOS QUE SATISFAZEM A SEGUINTES CONDIÇÕES:
1. OS SUBCONJUNTOS NÃO SÃO VAZIOS.
2. A INTERSEÇÃO DE SUBCONJUNTOS É NULA.

NESTE EXEMPLO COM TRÊS ELEMENTOS A PARTIÇÃO É DADA POR: {{a},{b},{c}}; {{a, b},{c}}; {{a, c},{b}}; {{b, c},{a}};
{{a, b, c}}.


O NÚMERO DE PARTIÇÕES DE UM CONJUNTO COM n ELEMENTOS É CHAMADO DE NÚMERO DE BELL B(n). NESTE  EXEMPLO B(3)=5.

OS NÚMEROS DE BELL PODEM SER DEFINIDOS RECURSIVAMENTE POR MEIO DA RELAÇÃO:
B(n)=Σ C(n,k)B(k), ONDE C(n,k) COM n<k DENOTA  A COMBINAÇÃO SIMPLES DE k ELEMENTOS EM UM CONJUNTO DE n ELEMENTOS
OS PRIMEIROS TERMOS DA SEQUÊNCIA DE BELL SÃO 1, 1, 2, ...

NÚMEROS DE BELL PODEM SER COMPUTADOS USANDO-SE UMA CONSTRUÇÃO GEOMÉTRICA DENOMINADA TRIÂNGULOS DE BELL, SIMILAR AO TRIÂNGULO
DE PASCAL QUE ENCODA OS COEFICIENTES BINOMIAIS. TAL MÉTODDO É PARTICULAMENTE ÚTIL PARA COMPUTAR NÚMEROS DE BELL EM BLOCOS.
TRIÂNGULOS DE BELL TAMBÉM SÃO DENOMINADOS ARRAY DE AITKEN'S OU TRIÂNGULOS DE PEIRCE.

NÚMEROS DE BELL APARECEM EM OUTRAS ÁREAS DA MATEMÁTICA COMO TEORIA DE NÚMEROS NA CONTAGEM DE PARTIÇÕES MULTIPLICATIVAS
DIFERENTES DE INTEIROS SEM FATORES PRIMOS REPETIDOS, EM ANÁLISE COMBINATÓRIA EM PROBLEMAS ENVOLVENDO PERMUTAÇÕES, ETC.


PARA MAIORES INFORMAÇÕES: https://en.wikipedia.org/wiki/Bell_number
                          https://en.wikipedia.org/wiki/Partition_of_a_set
                          https://oeis.org/A000110

*/



//*************************************************************************************************************************
//CABEÇALHO
#ifndef BELL_TRIANGLE_H
#define BELL_TRIANGLE_H
#include<vector>
#include<stdint.h>
#include<iostream>


//CONSTANTES
enum show_bell_triangle{Yes, No};


//*************************************************************************************************************************
//DECLARAÇÃO DE FUNÇÕES
template<typename T>
std::vector<T> compute_bell_numbers(int64_t, enum show_bell_triangle);


//*************************************************************************************************************************
//FUNÇÕES
//Função que computa os números de Bell em um intervalo
template<typename T>
std::vector<T> compute_bell_numbers(int64_t n,  enum show_bell_triangle x){

  //Variáveis locais
  std::vector<std::vector<T>> bell_triangle;
  std::vector<T> bell_number_set;
  int64_t k=0;

  //Procedimento
    //Adicionando a primeira linha
    std::vector<T> line1={1};
    bell_number_set.push_back(1);
    bell_triangle.push_back(line1);
    k++;

    //Adicionando as outras linhas do trângulo de Bell
    for(int64_t i=k; i<=n; ++i){
      std::vector<T> next_line;
      next_line.resize(k+1);
      next_line[0]=bell_triangle[k-1][k-1];

      bell_number_set.push_back(next_line[0]);
      for(int64_t j=1; j<=k; ++j) next_line[j]=next_line[j-1]+bell_triangle[k-1][j-1];

      bell_triangle.push_back(next_line);
      k++;     

    }

    //Exibindo o triângulo de Bell
    if(x==Yes){
      std::cout<<"Triângulo de Bell:\n";
      for(auto line:bell_triangle){
        for(auto e:line) std::cout<<e<<" ";
        std::cout<<'\n';
      }
      std::cout<<'\n';
    };



  //Resultado
  return bell_number_set;

};

//*************************************************************************************************************************
//FIM DO HEADER 
#endif
