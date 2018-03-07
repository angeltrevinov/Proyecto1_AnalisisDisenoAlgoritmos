/*
  Noe Amador Campos Castillo    A00820323
  Angel Odiel Treviño Villanueva A01336559
  Proyecto: 1A  Fecha: 5/Marzo  Materia: Analisis y Diseños de Algoritmos
*/

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

//Function to fill a matrix
void fillMatrix(vector<vector<int>> &vV){

    for(int iC = 0; iC < vV.size(); iC++){
        for(int iJ = 0; iJ < vV.size(); iJ++){
            cin >> vV[iC][iJ];
        }
    }
}

//Function to print a Matrix
void printMatrix(int iN, vector<vector<int>> vV){

    for(int iC = 0; iC < iN; iC++){
        for(int iJ = 0; iJ < iN; iJ++){
            cout << vV[iC][iJ] << " ";
        }
        cout << endl;
    }
}

//Function that realize the traditional Matrices Multplication
void traditionalMethod(int iN, vector<vector<int>> vA, vector<vector<int>> vB, vector<vector<int>> &vC){

    for(int iI = 0; iI < iN; iI++){
        for(int iJ = 0; iJ < iN; iJ++){
            for(int iK = 0; iK < iN; iK++){
                vC[iI][iJ] += vA[iI][iK] * vB[iK][iJ];   //Multipliy the values and add to the actual position
            }
        }
    }
}

//Add the two matrices received in the desired range
void addMatrix(int iN, int iX, int iY, vector<vector<int>> vA, vector<vector<int>> vB, vector<vector<int>> &vQ){

    for(int iI = iX; iI < iN; iI++){
        for(int iJ = iY; iJ < iN; iJ++){
            vQ[iI][iJ] = vA[iI][iJ] + vB[iI][iJ];
        }
    }
}

//Substract the two matrices received in the desired range
void substractMatrix(int iN, int iX, int iY, vector<vector<int>> vA, vector<vector<int>> vB, vector<vector<int>> &vQ){

    for(int iI = iX; iI < iN; iI++){
        for(int iJ = iY; iJ < iN; iJ++){
            vQ[iI][iJ] = vA[iI][iJ] - vB[iI][iJ];
        }
    }
}



int main(){
    int iN;                     //The number of Rows X Columns of the matrix's

    cin >> iN;

    vector<vector<int>> vA(iN, vector<int>(iN));
    vector<vector<int>> vB(iN, vector<int>(iN));    //The matrix that will be multiplied
    vector<vector<int>> vC(iN, vector<int>(iN));    //The resultant matrix

    fillMatrix(vA);
    fillMatrix(vB);                         //Read the values of each matrix

    cout << "Traditional:" << endl;
    traditionalMethod(iN, vA, vB, vC);      //Call the traditional method
    printMatrix(iN, vC);                    //Print the resultant matrix
    cout << "Scalar Multiplications: " << pow(iN,3) << endl;
    cout << endl;




    return 0;
}
