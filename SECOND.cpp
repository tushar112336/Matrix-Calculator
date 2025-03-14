#include <iostream>
#include <fstream>
using namespace std;

class MATRIX {
private:
    int rows, cols, i, j, k;
    int a[5][5], b[5][5], result[5][5];

public:
    void input() {
        ofstream file("SAVE.txt", ios::app);
        if (!file) {
            cout << "Error opening file FIRST.txt!" << endl;
            return;
        }
        cout << "Enter number of rows: ";
        cin >> rows;
        cout << "Enter number of columns: ";
        cin >> cols;

        cout << "Enter First Matrix: " << endl;
        for (i = 0; i < rows; i++) {
            for (j = 0; j < cols; j++) {
                cout << "Element at (" << i << "," << j << "): ";
                cin >> a[i][j];
                file << a[i][j] << " ";
            }
            file << endl;
        }
        file << endl;

        cout << "Enter Second Matrix: " << endl;
        for (i = 0; i < rows; i++) {
            for (j = 0; j < cols; j++) {
                cout << "Element at (" << i << "," << j << "): ";
                cin >> b[i][j];
                file << b[i][j] << " ";
            }
            file << endl;
        }
        file << endl;
        file.close();
    }

    void saveData(string operation) {
        ofstream file("SAVE.txt", ios::app);
        if (!file) {
            cout << "Error opening file Matrix.txt!" << endl;
            return;
        }
        file << operation << " Result: " << endl;
        for (i = 0; i < rows; i++) {
            for (j = 0; j < cols; j++) {
                file << result[i][j] << " ";
            }
            file << endl;
        }
        file << endl;
        file.close();
        cout << "Result Stored Successfully!" << endl << endl;
    }

    void additionMatrix() {
        cout << "Addition Result: " << endl;
        for (i = 0; i < rows; i++) {
            for (j = 0; j < cols; j++) {
                result[i][j] = a[i][j] + b[i][j];
                cout << result[i][j] << " ";
            }
            cout << endl;
        }
        saveData("Addition");
    }

    void subtractionMatrix() {
        cout << "Subtraction Result: " << endl;
        for (i = 0; i < rows; i++) {
            for (j = 0; j < cols; j++) {
                result[i][j] = a[i][j] - b[i][j];
                cout << result[i][j] << " ";
            }
            cout << endl;
        }
        saveData("Subtraction");
    }

    void multiplicationMatrix() {
        cout << "Multiplication Result: " << endl;
        if (cols != rows) {
            cout << "Matrix Multiplication is not possible!" << endl;
            return;
        }
        for (i = 0; i < rows; i++) {
            for (j = 0; j < cols; j++) {
                result[i][j] = 0;
                for (k = 0; k < cols; k++) {
                    result[i][j] += a[i][k] * b[k][j];
                }
                cout << result[i][j] << " ";
            }
            cout << endl;
        }
        saveData("Multiplication");
    }

    void transposeMatrix() {
        cout << "Transpose of First Matrix: " << endl;
        for (i = 0; i < cols; i++) {
            for (j = 0; j < rows; j++) {
                result[i][j] = a[j][i];
                cout << result[i][j] << " ";
            }
            cout << endl;
        }
        saveData("Transpose of First Matrix");

        cout << "Transpose of Second Matrix: " << endl;
        for (i = 0; i < cols; i++) {
            for (j = 0; j < rows; j++) {
                result[i][j] = b[j][i];
                cout << result[i][j] << " ";
            }
            cout << endl;
        }
        saveData("Transpose of Second Matrix");
    }
};

int main() {
    MATRIX rag;
    int choice;
    do {
        cout << "---MATRIX OPERATION MENU---" << endl;
        cout << "1. Input Matrix" << endl;
        cout << "2. Addition Matrix" << endl;
        cout << "3. Subtraction Matrix" << endl;
        cout << "4. Multiplication Matrix" << endl;
        cout << "5. Transpose Matrix" << endl;
        cout << "6. EXIT" << endl;
        cout << "Enter Your Choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                rag.input();
                break;
            case 2:
                rag.additionMatrix();
                break;
            case 3:
                rag.subtractionMatrix();
                break;
            case 4:
                rag.multiplicationMatrix();
                break;
            case 5:
                rag.transposeMatrix();
                break;
            case 6:
                cout << "---EXITING PROGRAM---" << endl;
                break;
            default:
                cout << "INVALID CHOICE" << endl;
        }
    } while (choice != 6);
    return 0;
}
