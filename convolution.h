//VAMOS CRIAR UM PROGRAMA QUE CALCULA A CONVOLUÇÃO DE DOIS CONJUNTOS

/*

A CONVOLUÇÃO  DE DOIS CONJUNTOS A, B CORRESPONDE A UMA ESPÉCIE DE PRODUTOS DE DOIS CONJUNTOS.
DADOS DOIS CONJUNTOS A=(A(0), A(1), ..., A(n)) E B=(B(0), B(1),..., B(m)). A CONVOLUÇÃO DE A
COM B DENOTADA POR A*B É O CONJUNTO:
A*B={A(0)*B(m), A(0)*B(m-1)+A(1)*B(m), ..., A(n-1)*B(0)+A(n)*B(1), A(n)*B(0)}

SE A POSSUIR n ELEMENTOS  E B m ELEMENTOS A CONVOLUÇÃO A*B, POSSUI m+n-1 ELEMENTOS NO TOTAL.

EXISTEM VÁRIAS APLICAÇÕES DESTE CONCEITOS EM MATEMÁTICA:  DADOS O CONJUNTOS A E B DE
COEFICIENTES DE DOIS POLINÔMIOS, A CONVOLUÇÃO A*B NOS DÁ OS COEFICIENTES DOS PRODUTOS DESTES
POLINÔMIOS. SE A SOMA DOS ELEMENTOS DE UM CONJUNTO É IGUAL A 1, A CONVOLUÇÃO A*B CORRESPONDE
A UM MÉDIA PONDERADA DADA UMA DISTRIBUIÇÃO DE PROBABILIDADES ESPECIFICADAS PELOS ELEMENTOS DO
COJUNTO CUJA SOMA É 1.

ESTE CONCEITO É GENERALIZADO PARA CONJUNTOS E FUNÇÕES CONTÍNUAS E É DE IMPORTÂNCIA EM VARIÁS
ÁREAS COMO: TRANSFORMADAS INTEGRAIS, ESTATÍSTICA, ENTRE OUTRAS.

PARA MAIORES INFORMAÇÕES: https://en.wikipedia.org/wiki/Convolution

*/

//***************************************************************************************************************************
// CABEÇALHO
#if !defined CONVOLUTION_H
#define CONVOLUTION_H
#include <iostream>
#include <vector>


//***************************************************************************************************************************
//DECLARAÇÃO DE FUNÇÕES
template<typename T>
std::vector<T> convolution(std::vector<T>&, std::vector<T>&);


//***************************************************************************************************************************
//FUNÇÕES
//Função que calcula a convolução de dois conjuntos
template<typename T>
std::vector<T> convolution(std::vector<T>& set1, std::vector<T>& set2){


  //Variáveis locais
  std::vector<T> convoluted_set;
  size_t MAX1=(set1.size()-1), MAX2=(set2.size()-1); //Maior index válido para os elementos dos dois conjuntos
  size_t MAX_CONVOLUTED=MAX1+MAX2+1;//Tamanho final do conjunto após a convolução
  size_t i, j, k;
  

  //Procedimentos
    //Loop principal
    for(k=0; k<MAX_CONVOLUTED; ++k){  /*k  determina os se o intervalo de indexes válidos para o conjunto convoluto*/
      
      T element=0;  //Elemento ser adicionado no conjunto

      for(i=0; i<=k; ++i){  /*i indexa os elementos do conjunto 1*/
        j=k-i;/*j indexa os elementos do conjunto 2*/
        if(i<=MAX1 && j<=MAX2) element+=(set1[i]*set2[j]);//Checando se os indexes estão dentro dos limites válidos
      };

      convoluted_set.push_back(element);

    };//Fim do loop principal


  //Resultado
  return convoluted_set;


};



//***************************************************************************************************************************
//FIM DO HEADER
#endif
