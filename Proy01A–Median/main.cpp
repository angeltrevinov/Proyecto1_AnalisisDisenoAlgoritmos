/*
  Angel Odiel Treviño Villanueva A01336559
  Noe Amador Campos Castillo    A00820323
  Proyecto: 1A  Fecha: 5/Marzo  Materia: Analisis y Diseños de Algoritmos
*/

#include <iostream>
#include <climits>
#include <vector>
#include <iomanip>

using namespace std;

//Funtion to fill the arrays
void fillArray(int iN, int iArr[]){

    for(int iI = 0; iI < iN; iI++){
      cin >> iArr[iI];
    }
}

//Funtion to get the median of an specific range
double getMedian(int iArr[],int iBottom,int iTop){
  /*Get the length of the separation, the difference between the
  beggining and the end*/
  int iLen = iTop - iBottom+1;


  return (iArr[iBottom + iLen/2] + iArr[iBottom+ iLen/2-1])/2;
}

//Function that return the median of the arrays as one
double Median (int iArr1[], int iArr2[], int iN, int iBottom1, int iTop1,
  int iBottom2, int iTop2){

      //If the arrays length is one (Index 1)
      if(iTop1 == iBottom1){
          return (iArr1[iBottom1] + iArr2[iBottom2])/2;
      }

      // Their length is two
      if(iTop1 - iBottom1 == 1){
          //Get the maximum number of the bottom and the and the minimum of the top
          //And return and return their sum divided by two
          return (double)(max(iArr1[iBottom1], iArr2[iBottom2]) +
                min(iArr1[iTop1], iArr2[iTop2]))/2;
      }

      // Get in the median of the first array
      double iMid1 = getMedian(iArr1,iBottom1,iTop1);
      // Get the median of the second array
      double iMid2 = getMedian(iArr2,iBottom1,iTop2);

      // You are too far from the left
      if(iMid1 <= iMid2){

          if((iTop1-iBottom1 + 1) % 2 == 0){
              return Median(iArr1, iArr2, iN, (iTop1+iBottom1)/2, iTop1, iBottom2,
              (iTop2+iBottom2)/2 + 1);

          }else{
              return Median(iArr1, iArr2, iN, (iTop1+iBottom1)/2, iTop1, iBottom2,
              (iTop2+iBottom2)/2);
          }
      // You are too far from the right
      }else{

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
  vector <double> vRespuestas;
  int iCases;           // Number of cases
  cin >> iCases;        // Read the number of cases

  int iN;               // The size of each iArray
  int iCont = 1;        // To know in what Case we are

  while( iCont <= iCases){      //Loop to make all the cases
    cin >> iN;                  // Read the arrays size
    int iiArr1[iN];             // To store the data of the first iArray
    int iiArr2[iN];             // To store the data of the second iArray

    //Call the function to fill the arrays
    fillArray(iN, iiArr1);
    fillArray(iN, iiArr2);

    /*Sends both arrays with their sizes and bottoms and tops to start
    the recursive function*/
    vRespuestas.push_back(Median(iiArr1, iiArr2, iN, 0 , iN-1, 0, iN-1));

    iCont++;        //Add one to the counter
  }

  // Print the answers
  for(int iI = 0; iI < iCases; iI++){
    cout << "Median case " <<iI + 1<< ": ";
    cout << fixed << setprecision(2) << vRespuestas[iI] <<endl;
  }

  return 0;
}
