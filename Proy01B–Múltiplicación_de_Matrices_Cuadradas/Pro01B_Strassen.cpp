/*
  Noe Amador Campos Castillo    A00820323
  Angel Odiel Treviño Villanueva A01336559
  Proyecto: 1B  Fecha: 5/Marzo  Materia: Analisis y Diseños de Algoritmos
*/

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;


void fillMatrix(vector<vector<int>> &vV){

    for(int iC = 0; iC < vV.size(); iC++){
        for(int iJ = 0; iJ < vV.size(); iJ++){
            cin >> vV[iC][iJ];
        }
    }
}

void printMatrix(vector<vector<int>> vV){

    for(int iC = 0; iC < vV.size(); iC++){
        for(int iJ = 0; iJ < vV.size(); iJ++){
            cout << vV[iC][iJ] << " ";
        }
        cout << endl;
    }
}

vector<vector<int>> traditionalMultiplication(int iN, vector<vector<int>> vA, vector<vector<int>> vB){
    vector<vector<int>> vTemp(iN, vector<int>(iN));

    for(int iI = 0; iI < iN; iI++){
        for(int iJ = 0; iJ < iN; iJ++){
            for(int iK = 0; iK < iN; iK++){
                vTemp[iI][iJ] =
            }
        }
    }
}

int main(){
    int iN;

    cin >> iN;

    vector<vector<int>> vA(iN, vector<int>(iN));
    vector<vector<int>> vB(iN, vector<int>(iN));

    fillMatrix(vA);
    fillMatrix(vB);

    cout << "Traditional:" << endl;
    printMatrix(vA);// traditionalMultiplication(vA, vB));
    cout << "Scalar Multiplications: " << pow(iN,3) << endl;
    cout << endl;

    cout << "Strasse:" << endl;





    return 0;
}
