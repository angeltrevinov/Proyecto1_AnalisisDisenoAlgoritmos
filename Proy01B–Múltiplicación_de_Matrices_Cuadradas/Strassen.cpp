/*
  Noe Amador Campos Castillo    A00820323
  Angel Odiel Treviño Villanueva A01336559
  Proyecto: 1B Strassen  Fecha: 5/Marzo  Materia: Analisis y Diseños de Algoritmos
*/

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

//Function to fill a matrix
void fillMatrix(vector<vector<int>> &vV, int iN){
    vector<int> vTemp;
    int iT;
    for(int iC = 0; iC < iN; iC++){
        for(int iJ = 0; iJ < iN; iJ++){
            cin >> iT;
            vTemp.push_back(iT);
        }
        vV.push_back(vTemp);
        vTemp.clear();
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

//Function that add the needed rows and columns if iN it is not Base 2
void notBase2(int iN, vector<vector<int>> &vV){
    int iBase = ceil(log2(iN));

    //Add the missing Columns
    for(int iI = 0; iI < iN; iI++){
        for(int iJ = iN; iJ < pow(2, iBase); iJ++){
            vV[iI].push_back(0);
        }
    }

    //Add the missing rows
    for(int iC = iN; iC < pow(2, iBase); iC++){
        vV.push_back(vector<int>(pow(2, iBase)));
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
        //Auxiliar Matrices to store the results of the Add and Substract operations
        vector<vector<int>> vAA(iN, vector<int>(iN));
        vector<vector<int>> vBB(iN, vector<int>(iN));

        //The submatrices of the A and B Matrices
        vector<vector<int>> vA11(iN, vector<int>(iN));
        vector<vector<int>> vA12(iN, vector<int>(iN));
        vector<vector<int>> vA21(iN, vector<int>(iN));
        vector<vector<int>> vA22(iN, vector<int>(iN));

        vector<vector<int>> vB11(iN, vector<int>(iN));
        vector<vector<int>> vB12(iN, vector<int>(iN));
        vector<vector<int>> vB21(iN, vector<int>(iN));
        vector<vector<int>> vB22(iN, vector<int>(iN));

        //The Submatrices of the Strassen Algorithm
        vector<vector<int>> vC11(iN, vector<int>(iN));
        vector<vector<int>> vC12(iN, vector<int>(iN));
        vector<vector<int>> vC21(iN, vector<int>(iN));
        vector<vector<int>> vC22(iN, vector<int>(iN));

        //The matrices that represent the M1 to M7
        vector<vector<int>> vM1(iN, vector<int>(iN));
        vector<vector<int>> vM2(iN, vector<int>(iN));
        vector<vector<int>> vM3(iN, vector<int>(iN));
        vector<vector<int>> vM4(iN, vector<int>(iN));
        vector<vector<int>> vM5(iN, vector<int>(iN));
        vector<vector<int>> vM6(iN, vector<int>(iN));
        vector<vector<int>> vM7(iN, vector<int>(iN));

        iN /= 2;
        fillSubMatrices(iN, vA11, vA12, vA21, vA22, vA, vB11, vB12, vB21,
                vB22, vB);

        /* | A11     A12 |   | B11     B12 |        | C11     C12 |
           |             | X |             |    =   |             |
           | A21     A22 |   | B21     B22 |        | C21     C22 |
        */
            //CALCULATE FROM M1 TO M7 (USING THE ADD AND SUBTRACT METHODS)

        //Calculate M1 = (a11 + a22) * (b11 + b22)
        addMatrix(iN, vA11, vA22, vAA);
        addMatrix(iN, vB11, vB22, vBB);
        strassenMethod(iN, vAA, vBB, vM1);

        //Calculate M2 = (a21 + a22) * b11
        addMatrix(iN, vA21, vA22, vAA);
        strassenMethod(iN, vAA, vB11, vM2);

        //Calculate M3 = a11 * (b12 - b22)
        substractMatrix(iN, vB12, vB22, vBB);
        strassenMethod(iN, vA11, vBB, vM3);

        //Calculate M4 = a22 * (b21 - b11)
        substractMatrix(iN, vB21, vB11, vBB);
        strassenMethod(iN, vA22, vBB, vM4);

        //Calculate M5 = (a11 + a12) * b22
        addMatrix(iN, vA11, vA12, vAA);
        strassenMethod(iN, vAA, vB22, vM5);

        //Calculate M6 = (a21 - a11) * (b11 + b12)
        substractMatrix(iN, vA21, vA11, vAA);
        addMatrix(iN, vB11, vB12, vBB);
        strassenMethod(iN, vAA, vBB, vM6);

        //Calculate M7 = (a12 - a22) * (b21 + b22)
        substractMatrix(iN, vA12, vA22, vAA);
        addMatrix(iN, vB21, vB22, vBB);
        strassenMethod(iN, vAA, vBB, vM7);

                                    //CALCULATE FROM C11 TO C22

        //Calculate C11 = M1 + M4 - M5 + M7
        addMatrix(iN, vM1, vM4, vAA);
        substractMatrix(iN, vM7, vM5, vBB);
        addMatrix(iN, vAA, vBB, vC11);

        //Calculate C12 = M3 + M5
        addMatrix(iN, vM3, vM5, vC12);

        //Calculate C21 = M2 + M4
        addMatrix(iN, vM2, vM4, vC21);

        //Calculate C22 = M1 + M3 - M2 + M6
        substractMatrix(iN, vM1, vM2, vAA);
        addMatrix(iN, vM3, vM6, vBB);
        addMatrix(iN, vAA, vBB, vC22);

        //Fill the resultant Matrix of the multiplication
        for(int iI = 0; iI < iN; iI++) {
           for(int iJ = 0; iJ < iN; iJ++) {

              vC[iI][iJ] = vC11[iI][iJ];
              vC[iI][iJ + iN] = vC12[iI][iJ];
              vC[iI + iN][iJ] = vC21[iI][iJ];
              vC[iI + iN][iJ + iN] = vC22[iI][iJ];
           }
        }

    }
}



int main(){
    int iN;                     //The number of Rows X Columns of the matrix's

    cin >> iN;                  //Read the number

    vector<vector<int>> vA;
    vector<vector<int>> vB;         //The matrices that will be multiplied
    vector<vector<int>> vT(iN, vector<int>(iN));    //The resultant matrix with the traditional method
    vector<vector<int>> vS(iN, vector<int>(iN));    //The resultant matrix with the Strassen method

    fillMatrix(vA, iN);
    fillMatrix(vB, iN);                         //Fill the matrices

    cout << "\nTraditional:" << endl;
    traditionalMethod(iN, vA, vB, vT);      //Call the traditional method
    printMatrix(iN, vT);                    //Print the resultant matrix
    cout << "Scalar Multiplications: " << pow(iN,3) << endl;
    cout << endl;

    cout << "Strasse:" << endl;
    //Check if iN is not Base 2, and in that case call the function to make it
    if(fmod(log2(iN), 1) != 0.0){
        notBase2(iN, vA);
        notBase2(iN, vB);
        notBase2(iN, vS);
    }
    //Call the Strassen Method
    strassenMethod(pow(2, ceil(log2(iN))), vA, vB, vS);
    //Print the resultant matrix
    printMatrix(iN, vS);
    //When iN it is not base 2, it will anywaya print the number of Scalar
    //multiplications that the method realize with the correct iN base 2
    cout << "Scalar Multiplications: " << floor(pow(pow(2, ceil(log2(iN))), 2.81)) + 7 << endl;

    return 0;
}
