/*
  Angel Odiel Treviño Villanueva A01336559
  Noe Amador Campos Castillo    A00820323
  Proyecto: 1A  Fecha: 5/Marzo  Materia: Analisis y Diseños de Algoritmos
*/

#include <iostream>

using namespace std;

int main(){

  int iCases; // number of cases
  cin >> iCases;
  int iN; // the size of each array
  int iCont = 1; // to know in what Case we are
  while( iCont <= iCases){
    cin >> iN;
    int iArr1[iN]; // to store the data of the first Array
    int iArr2[iN]; // to store the data of the second Array

    //filling both arrays with the information given by the user
    for(int iI = 0; iI < iN; iI++){
      cin >> iArr1[iI];
    }

    for(int iI = 0; iI < iN; iI++){
      cin >> iArr2[iI];
    }
    
    //cout << "Median Case "<<iCont<<": "<< iMedian <<endl;

    iCont++;
  }

  return 0;
}
