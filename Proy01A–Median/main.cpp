/*
  Angel Odiel Treviño Villanueva A01336559
  Noe Amador Campos Castillo    A00820323
  Proyecto: 1A  Fecha: 5/Marzo  Materia: Analisis y Diseños de Algoritmos
*/

#include <iostream>
#include <climits>

using namespace std;

double getMedian(int iArr[],int iBottom,int iTop){
  int iLen = iTop - iBottom+1; // get the length of the separation
  return (iArr[iBottom + iLen/2] + iArr[iBottom+ iLen/2-1])/2;
}

double Median (int iArr1[], int iArr2[], int iN, int iBottom1, int iTop1,
  int iBottom2, int iTop2){

      if(iTop1 == iBottom1){//  the top and bottom are in the same position
          return (iArr1[iBottom1] + iArr2[iBottom2])/2;
      }

      if(iTop1 - iBottom1 == 1){ // their length is just one, so calculate the median
          return (double)(max(iArr1[iBottom1], iArr2[iBottom2]) + min(iArr1[iTop1],
            iArr2[iTop2]))/2;
      }

      double iMid1 = getMedian(iArr1,iBottom1,iTop1); // get in the median for the first array
      double iMid2 = getMedian(iArr2,iBottom1,iTop2); // get the median for the second array
      if(iMid1 <= iMid2){ // you are too far from the left
          if((iTop1-iBottom1 + 1) % 2 == 0){
              return Median(iArr1, iArr2, iN, (iTop1+iBottom1)/2, iTop1, iBottom2,
              (iTop2+iBottom2)/2 + 1);
          }else{
              return Median(iArr1, iArr2, iN, (iTop1+iBottom1)/2, iTop1, iBottom2,
              (iTop2+iBottom2)/2);
          }
      }else{ // you are too far from the right
          if((iTop1-iBottom1 + 1) % 2 == 0){
              return Median(iArr1, iArr2, iN, iBottom1, (iTop1+iBottom1)/2 + 1,
              iBottom2 = (iTop2+iBottom2)/2, iTop2);
          }else{
              return Median(iArr1, iArr2, iN, iBottom1, (iTop1+iBottom1)/2,
              iBottom2 = (iTop2+iBottom2)/2, iTop2);
          }
      }
}

int main(){

  int iCases; // number of cases
  cin >> iCases;
  int iN; // the size of each iArray
  int iCont = 1; // to know in what Case we are
  while( iCont <= iCases){
    cin >> iN;
    int iiArr1[iN]; // to store the data of the first iArray
    int iiArr2[iN]; // to store the data of the second iArray

    //filling both iArrays with the information given by the user
    for(int iI = 0; iI < iN; iI++){
      cin >> iiArr1[iI];
    }

    for(int iI = 0; iI < iN; iI++){
      cin >> iiArr2[iI];
    }

    //sends both arrays with their sizes and bottoms and tops to start the recursive function
    cout << "iMidian Case "<<iCont<<": "<< Median(iiArr1, iiArr2, iN, 0 ,
      iN-1, 0, iN-1) << endl;

    iCont++;
  }
  return 0;
}
