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
void traditionalMethod(int iN, vector<vector<int>> vA, vector<vector<int>> vB,
     vector<vector<int>> &vC){

    for(int iI = 0; iI < iN; iI++){
        for(int iJ = 0; iJ < iN; iJ++){
            for(int iK = 0; iK < iN; iK++){
                vC[iI][iJ] += vA[iI][iK] * vB[iK][iJ];   /*Multipliy the values
                                                and add to the actual position*/
            }
        }
    }
}

//Add the two matrices received in the desired range
void addMatrix(int iN, vector<vector<int>> vA, vector<vector<int>> vB,
    vector<vector<int>> &vQ){

    for(int iI = 0; iI < iN; iI++){
        for(int iJ = 0; iJ < iN; iJ++){
            vQ[iI][iJ] = vA[iI][iJ] + vB[iI][iJ];
        }
    }
}

//Substract the two matrices received in the desired range
void substractMatrix(int iN, vector<vector<int>> vA, vector<vector<int>> vB,
    vector<vector<int>> &vQ){

    for(int iI = 0; iI < iN; iI++){
        for(int iJ = 0; iJ < iN; iJ++){
            vQ[iI][iJ] = vA[iI][iJ] - vB[iI][iJ];
        }
    }
}

/*Function to fill all the submatrices and make easier call the Add and
Substract methods*/
void fillSubMatrices(int iN2, vector<vector<int>> &vA11, vector<vector<int>> &vA12,
vector<vector<int>> &vA21, vector<vector<int>> &vA22, vector<vector<int>> vA,
vector<vector<int>> &vB11, vector<vector<int>> &vB12, vector<vector<int>> &vB21,
vector<vector<int>> &vB22, vector<vector<int>> vB){

    for(int iI = 0; iI < iN2; iI++){
        for(int iJ = 0; iJ < iN2; iJ++){
              vA11[iI][iJ] = vA[iI][iJ];
              vA12[iI][iJ] = vA[iI][iJ + iN2];
              vA21[iI][iJ] = vA[iI + iN2][iJ];
              vA22[iI][iJ] = vA[iI + iN2][iJ + iN2];

              vB11[iI][iJ] = vB[iI][iJ];
              vB12[iI][iJ] = vB[iI][iJ+iN2];
              vB21[iI][iJ] = vB[iI+iN2][iJ];
              vB22[iI][iJ] = vB[iI+iN2][iJ+iN2];
        }
    }
}

//The function with the Stressen Algorithm
void strassenMethod(int iN, vector<vector<int>> vA,
     vector<vector<int>> vB, vector<vector<int>> &vC){

    //Check if it is the case base
    if(iN == 2){
        traditionalMethod(2, vA, vB, vC);

    }else{
        //The submatrices of the A and B Matrices
        vector<vector<int>> vA11(iN, vector<int>(iN));
        vector<vector<int>> vA12(iN, vector<int>(iN));
        vector<vector<int>> vA21(iN, vector<int>(iN));
        vector<vector<int>> vA22(iN, vector<int>(iN));

        vector<vector<int>> vB11(iN, vector<int>(iN));
        vector<vector<int>> vB12(iN, vector<int>(iN));
        vector<vector<int>> vB21(iN, vector<int>(iN));
        vector<vector<int>> vB22(iN, vector<int>(iN));

        fillSubMatrices(iN/2, vA11, vA12, vA21, vA22, vA, vB11, vB12, vB21,
        vB22, vB);

        //The Submatrices of the Strassen Algorithm
        vector<vector<int>> vC11(iN, vector<int>(iN));
        vector<vector<int>> vC12(iN, vector<int>(iN));
        vector<vector<int>> vC21(iN, vector<int>(iN));
        vector<vector<int>> vC22(iN, vector<int>(iN));

        //Auxiliar Matrices to store the results of the Add and Substract operations
        vector<vector<int>> vAA(iN, vector<int>(iN));
        vector<vector<int>> vBB(iN, vector<int>(iN));

        //The matrices that represent the M1 to M7
        vector<vector<int>> vM1(iN, vector<int>(iN));
        vector<vector<int>> vM2(iN, vector<int>(iN));
        vector<vector<int>> vM3(iN, vector<int>(iN));
        vector<vector<int>> vM4(iN, vector<int>(iN));
        vector<vector<int>> vM5(iN, vector<int>(iN));
        vector<vector<int>> vM6(iN, vector<int>(iN));
        vector<vector<int>> vM7(iN, vector<int>(iN));

        /* | A11     A12 |   | B11     B12 |        | C11     C12 |
           |             | X |             |    =   |             |
           | A21     A22 |   | B21     B22 |        | C21     C22 |
        */
        //CALCULATE FROM M1 TO M7 (USING THE ADD AND SUBTRACT METHODS)

        //Calculate M1 = (a11 + a22) * (b11 + b22)
        addMatrix(iN/2, vA11, vA22, vAA);
        addMatrix(iN/2, vB11, vB22, vBB);
        strassenMethod(iN/2, vAA, vBB, vM1);

        //Calculate M2 = (a21 + a22) * b11
        addMatrix(iN/2, vA21, vA22, vAA);
        strassenMethod(iN/2, vAA, vB11, vM2);

        //Calculate M3 = a11 * (b12 - b22)
        substractMatrix(iN/2, vB12, vB22, vBB);
        strassenMethod(iN/2, vA11, vBB, vM3);

        //Calculate M4 = a22 * (b21 - b11)
        substractMatrix(iN/2, vB21, vB11, vBB);
        strassenMethod(iN/2, vA22, vBB, vM4);

        //Calculate M5 = (a11 + a12) * b22
        addMatrix(iN/2, vA11, vA12, vAA);
        strassenMethod(iN/2, vAA, vB22, vM5);

        //Calculate M6 = (a21 - a11) * (b11 + b12)
        substractMatrix(iN/2, vA21, vA11, vAA);
        addMatrix(iN/2, vB11, vB12, vBB);
        strassenMethod(iN/2, vAA, vBB, vM6);

        //Calculate M7 = (a12 - a22) * (b21 + b22)
        substractMatrix(iN/2, vA12, vA22, vAA);
        addMatrix(iN/2, vB21, vB22, vBB);
        strassenMethod(iN/2, vAA, vBB, vM7);

        //CALCULATE FROM C11 TO C22

        //Calculate C11 = M1 + M4 - M5 + M7
        addMatrix(iN/2, vM1, vM4, vAA);
        substractMatrix(iN/2, vM7, vM5, vBB);
        addMatrix(iN/2, vAA, vBB, vC11);

        //Calculate C12 = M3 + M5
        addMatrix(iN/2, vM3, vM5, vC12);

        //Calculate C21 = M2 + M4
        addMatrix(iN/2, vM2, vM4, vC21);

        //Calculate C22 = M1 + M3 - M2 + M6
        substractMatrix(iN/2, vM1, vM2, vAA);
        addMatrix(iN/2, vM3, vM6, vBB);
        addMatrix(iN/2, vAA, vBB, vC22);

        //Set the result to C[][N]
        for(int iI = 0; iI < iN/2; iI++) {
           for(int iJ = 0; iJ < iN/2; iJ++) {
              vC[iI][iJ] = vC11[iI][iJ];
              vC[iI][iJ + iN/2] = vC12[iI][iJ];
              vC[iI + iN/2][iJ] = vC21[iI][iJ];
              vC[iI + iN/2][iJ + iN/2] = vC22[iI][iJ];
           }
        }

    }
}



int main(){
    int iN;                     //The number of Rows X Columns of the matrix's

    cin >> iN;

    vector<vector<int>> vA(iN, vector<int>(iN));
    vector<vector<int>> vB(iN, vector<int>(iN));    //The matrix that will be multiplied
    vector<vector<int>> vT(iN, vector<int>(iN));    //The resultant matrix
    vector<vector<int>> vS(iN, vector<int>(iN));

    fillMatrix(vA);
    fillMatrix(vB);                         //Read the values of each matrix

    cout << "Traditional:" << endl;
    traditionalMethod(iN, vA, vB, vT);      //Call the traditional method
    printMatrix(iN, vT);                    //Print the resultant matrix
    cout << "Scalar Multiplications: " << pow(iN,3) << endl;
    cout << endl;

    cout << "Strassen:" << endl;
    strassenMethod(iN, vA, vB, vS);
    printMatrix(iN, vS);
    cout << "Scalar Multiplications: " << floor(pow(iN, 2.81)) + 7 << endl;
    cout << endl;




    return 0;
}
