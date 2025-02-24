//VAMOS CRIAR UM PROGRAMA PARA TESTAR AS ROTINAS CRIADAS NO ARQUIVO mergesort.hpp
//COMPILAR ESTE PROGRAMA COM O COMANDO: g++ -o mergesort mergesort.cpp



//Cabeçalho
#include<iostream>
#include<array>
#include<cstdlib>
#include<ctime>
#include"mergesort.hpp"
using namespace std;



//Função principal
int main(){

  //Semente para geração de números aleatórios
  srand(time(NULL));

  //Variáveis  locais
  int n, i;


  //Procedimento
    //Recebendo  input do usuário
    cout<<"[Números de elementos no array de inteiros]: ";
    cin>>n;

    //Definindo um array de inteiros usando um gerador de  números aleatórios
    int * lista=new int[n];
    for(i=0; i<n; i++) lista[i]=rand()%1000000;
                 

    //Ordenando elementos no array
    mergesort::mergesort<int>(lista, 0, n-1);

    //Exibindo elementos ordenados
    for(i=0; i<n; i++)
      cout<<"lista["<<i<<"]= "<< lista[i]<< endl;
  
    //Limpando o cachê de memória
    delete []lista;

  //Finalizando aaplicação
  return 0;

}

