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

//Function that realize the traditional Multplication of Matrix's
vector<vector<int>> traditionalMethod(int iN, vector<vector<int>> vA, vector<vector<int>> vB){

    vector<vector<int>> vTemp(iN, vector<int>(iN));         //Auxiliar Matrix

    for(int iI = 0; iI < iN; iI++){
        for(int iJ = 0; iJ < iN; iJ++){
            for(int iK = 0; iK < iN; iK++){
                vTemp[iI][iJ] += vA[iI][iK] * vB[iK][iJ];   //Multipliy the values and add to the actual position
            }
        }
    }

    return vTemp;                                           //Return the temporal matrix
}

//If N is odd, a column and a line of 0 must be added to could use the Strassen algorithm
void oddIN(vector<vector<int>> &vV, int iN){
    vV.push_back(vector<int>(iN));

    for(int iC = 0; iC < iN-1; iC++){
        vV[iC].push_back(1);
    }

    for(int iS = 0; iS < iN; iS++){
        vV[iN-1][iS] = 1;
    }


}

/*  A[X1][Y1]                 A[X1][Y2]
    A[X2][Y1]                 A[X2][Y2]
*/

void strassenAlgorithm(int iX, int iY,  vector<vector<int>> vA, vector<vector<int>> vB, vector<vector<int>> &vC){
    int iM1 = (vA[iX][iY] + vA[iX+1][iY+1]) * (vB[iX][iY] + vB[iX+1][iY+1]);
    int iM2 = (vA[iX+1][iY] + vA[iX+1][iY+1]) * vB[iX][iY];
    int iM3 = vA[iX][iY] * (vB[iX][iY+1] - vB[iX+1][iY+1]);
    int iM4 = vA[iX+1][iY+1] * (vB[iX+1][iY] - vB[iX][iY]);
    int iM5 = (vA[iX][iY] + vA[iX][iY+1]) * vB[iX+1][iY+1];
    int iM6 = (vA[iX+1][iY] - vA[iX][iY]) * (vB[iX][iY] + vB[iX][iY+1]);
    int iM7 = (vA[iX][iY+1] - vA[iX+1][iY+1]) * (vB[iX+1][iY] + vB[iX+1][iX+1]);

    vC[iX][iY] = iM1 + iM4 - iM5 + iM7;
    vC[iX][iY+1] = iM3 + iM5;
    vC[iX+1][iY] = iM2 + iM4;
    vC[iX+1][iY+1] = iM1 + iM3 - iM2 + iM6;

}

//Function to devide the matrix in submatrix's and call the function with the
//Strassen algorithm to fill the new matrix
vector<vector<int>> divideMatrix(int iN, vector<vector<int>> vA, vector<vector<int>> vB){

    if(iN%2 != 0){
        iN++;
        oddIN(vA, iN);
        oddIN(vB, iN);
    }

    vector<vector<int>> vC(iN, vector<int>(iN));

    for(int iY = 0; iY < iN; iY+=2){
        for(int iX = 0; iX < iN; iX+=2){
            strassenAlgorithm(iX, iY, vA, vB, vC);
        }
    }

    return vC;
}



int main(){
    int iN;                     //The number of Rows X Columns of the matrix's

    cin >> iN;

    vector<vector<int>> vA(iN, vector<int>(iN));
    vector<vector<int>> vB(iN, vector<int>(iN));
    vector<vector<int>> vC(iN, vector<int>(iN));

    fillMatrix(vA);
    fillMatrix(vB);

    cout << "Traditional:" << endl;
    printMatrix(iN, traditionalMethod(iN, vA, vB));
    cout << "Scalar Multiplications: " << pow(iN,3) << endl;
    cout << endl;

    cout << "Strassen:" << endl;
    printMatrix(iN, divideMatrix(iN, vA, vB));
    cout << "Scalar Multiplications: " << floor(pow(iN, 2.81)) + 7 << endl;
    cout << endl;








    return 0;
}
