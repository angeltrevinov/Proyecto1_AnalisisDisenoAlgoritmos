/*
  Angel Odiel Treviño Villanueva A01336559
  Noe Amador Campos Castillo    A00820323
  Proyecto: 1A  Fecha: 5/Marzo  Materia: Analisis y Diseños de Algoritmos
*/

#include <iostream>

using namespace std;

//binary search to know the position where the number needs to be inserted
int BinarySearch(int iArr[], int iData, int iBottom, int iTop){
  if(iTop <= iBottom){
    return (iData > iArr[iBottom])?  (iBottom + 1): iBottom;
  }

  int iMiddle = (iBottom+iTop)/2; //find the middle

   if(iData == iArr[iMiddle]){ // found the position in the middle of the array
     return iMiddle+1;
   }

   if(iData > iArr[iMiddle]){//go to the right
     return BinarySearch(iArr, iData, iMiddle+1, iTop);
   }else{//go to the lefth
     return BinarySearch(iArr, iData, iBottom, iMiddle-1);
   }
}

//sorting the array with the insertionSort method
void InsertionSort(int iArr[], int iN){ // sending the array and the size
  int iPos; //find the position where the data needs to be inserted
  int iJ; // to move in the array
  for(int iI = 1; iI < iN; iI++){
    iJ = iI-1;
    iPos = BinarySearch(iArr, iArr[iI], 0, iJ); // find the location where it needs to be inserted
    while(iJ >= iPos){
      iArr[iJ+1] = iArr[iJ];
      iJ--;
    }
    iArr[iJ+1] = iArr[iI];
  }
}

int main(){

  int iCases; // number of cases
  cin >> iCases;
  int iN; // the size of the arrays
  int iCont = 1; // to know in what Case we are
  while( iCont <= iCases){
    cin >> iN;
    iN *= 2; // to double the size
    int iArr[iN]; // to store the data of each array in just one

    //fill the array with the information given by the user
    for(int iI = 0; iI < iN; iI++){
      cin >> iArr[iI];
    }

    InsertionSort(iArr, iN); //uses Binary Insertion Sort

    for(int i = 0; i < iN; i++){
      cout << iArr[i] << " ";
    }
    cout << endl;
    double iMedian = (iArr[iN/2] + iArr[iN/2 + 1]) /2;
    cout << "Median Case "<<iCont<<": "<< iMedian <<endl;

    iCont++;
  }

  return 0;
}
