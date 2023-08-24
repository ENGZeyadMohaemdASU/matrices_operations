#include <iostream>
#include <cmath>
#include <string>
#include <vector>
using namespace std;
//void get_matrix(vector<vector <int>>& matrix_1, vector<vector <int>>& matrix_2, int rows_1, int cols_1, int rows_2, int cols_2)
//--------------------------
void get_matrix_1(vector<vector <int>>& matrix_1, int rows_1, int cols_1);
void get_matrix_2(vector<vector <int>>& matrix_2, int rows_2, int cols_2);
void addition(vector<vector <int>>& matrix_1, vector<vector <int>>& matrix_2, int rows_1, int cols_1, int rows_2, int cols_2);
void subtraction(vector<vector <int>>& matrix_1, vector<vector <int>>& matrix_2, int rows_1, int cols_1, int rows_2, int cols_2);
void multiplication(vector<vector <int>>& matrix_1, vector<vector <int>>& matrix_2, int rows_1, int cols_1, int rows_2, int cols_2);
double matrix_1_det(vector<vector <int>>& matrix_1, int rows_1, int cols_1);
double matrix_2_det(vector<vector <int>>& matrix_1, int rows_2, int cols_2);
void matrix_print(vector<vector <int>>& matrix, int rows, int cols);
//--------------------------
//--------------------------
//--------------------------
int main()
{

    int rows_1, cols_1, rows_2, cols_2;
    cout << "Enter the dimension of matrix 1 : " << endl;
    cin >> rows_1 >> cols_1;
    cout << "Enter the dimension of matrix 2 : " << endl;
    cin >> rows_2 >> cols_2;
    vector<vector<int>> matrix_1(rows_1, vector<int>(cols_1));
    vector<vector<int>> matrix_2(rows_2, vector<int>(cols_2));
    cout << "Enter the elements of matrix 1 : " << endl;
    get_matrix_1(matrix_1, rows_1, cols_1);
    cout << "Enter the elements of matrix 2 : " << endl;
    get_matrix_2(matrix_2, rows_2, cols_2);
    char operation;
    while (true)
    {
        cout << "choose operation +, - ,* ,d _for determenant _  or enter q to quit" << endl;

        cin >> operation;
        if (operation == '+')
        {
            cout << "the addition of matricies is : " << endl;
            addition(matrix_1, matrix_2, rows_1, cols_1, rows_2, cols_2);
            cout << endl;
        }
        else if (operation == '-')
        {
            cout << "the subtraction of matricies is : " << endl;
            subtraction(matrix_1, matrix_2, rows_1, cols_1, rows_2, cols_2);
            cout << endl;
        }
        else if (operation == '*')
        {
            cout << "the multiplication of matricies is : " << endl;
            multiplication(matrix_1, matrix_2, rows_1, cols_1, rows_2, cols_2);
            cout << endl;
        }
        else if (operation == 'd')
        {
            cout << "the determenant of matrix 1 is : " << endl;
            cout << matrix_1_det(matrix_1, rows_1, cols_1);
            cout << endl;
            cout << "the determenant of matrix 2 is : " << endl;
            cout << matrix_2_det(matrix_2, rows_2, cols_2);
            cout << endl;
        }
        else if (operation == 'q')
        {
            cout << "have a nice day !";
            break;
        }

        else {

            cout << "wrong input";
            break;
        }
    }
    return 0;

}
//--------------------------
//--------------------------
//--------------------------
void get_matrix_1(vector<vector <int>>& matrix_1, int rows_1, int cols_1)
{
    for (int i = 0; i < rows_1; i++)
    {
        for (int j = 0; j < cols_1; j++) cin >> matrix_1[i][j];
    }

}
void get_matrix_2(vector<vector <int>>& matrix_2, int rows_2, int cols_2)
{
    for (int i = 0; i < rows_2; i++)
    {
        for (int j = 0; j < cols_2; j++) cin >> matrix_2[i][j];
    }
}
void addition(vector<vector <int>>& matrix_1, vector<vector <int>>& matrix_2, int rows_1, int cols_1, int rows_2, int cols_2)
{
    int rows = rows_1;
    int cols = cols_1;
    if (rows_1 != rows_2 && cols_1 != cols_2)
    {
        cout << "Matrecies must be same size to be added " << endl;
    }
    else
    {
        vector<vector<int>> sum(rows, vector<int>(cols, 0));
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++) sum[i][j] = matrix_1[i][j] + matrix_2[i][j];
        }
        matrix_print(sum, rows, cols);
    }
}
void subtraction(vector<vector <int>>& matrix_1, vector<vector <int>>& matrix_2, int rows_1, int cols_1, int rows_2, int cols_2)
{
    int rows = rows_1;
    int cols = cols_1;
    if (rows_1 != rows_2 && cols_1 != cols_2)
    {
        cout << "Matrecies must be same size to be subtracted "<<endl;
    }
    else
    {
        vector<vector<int>> sub(rows, vector<int>(cols, 0));
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++) sub[i][j] = matrix_1[i][j] - matrix_2[i][j];
        }
        matrix_print(sub, rows, cols);
    }

}
void multiplication(vector<vector <int>>& matrix_1, vector<vector <int>>& matrix_2, int rows_1, int cols_1, int rows_2, int cols_2)
{
    int rows = rows_1;
    int cols = cols_2;
    if (cols_1 != rows_2) cout << "matricies can\'t be multiplied .";
    else {
        vector<vector<int>> multi(rows, vector<int>(cols, 0));
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                for (int k = 0; k < cols_1; k++)
                    multi[i][j] += matrix_1[i][k] * matrix_2[k][j];
            }
        }
        matrix_print(multi, rows, cols);

    }
}
double matrix_1_det(vector<vector <int>>& matrix_1, int rows_1, int cols_1)
{
    double det = 0;
    if (cols_1 != rows_1) cout << "matrix has no determinant  .";
    else if (rows_1 == 2 && cols_1 == 2) det = (matrix_1[0][0] * matrix_1[1][1]) - (matrix_1[0][1] * matrix_1[1][0]);
    else if (rows_1 == 1 && cols_1 == 1)det = matrix_1[0][0];

    else
    {
        for (int i = 0; i < rows_1; i++) {
            vector<vector<int>> submatrix(rows_1 - 1, vector<int>(cols_1 - 1));


            for (int j = 1; j < rows_1; j++) {
                for (int k = 0, l = 0; k < cols_1; k++) {
                    if (k != i) {
                        submatrix[j - 1][l] = matrix_1[j][k];
                        l++;
                    }
                }
            }


            det += (i % 2 == 0 ? 1 : -1) * matrix_1[0][i] * matrix_1_det(submatrix, rows_1 - 1, cols_1 - 1);
        }
    }
    return det;


}
double matrix_2_det(vector<vector <int>>& matrix_1, int rows_2, int cols_2) {
    double det = 0;
    if (cols_2 != rows_2)
    {
        cout << "matrix has no determinant  .";
        return NULL;
    }
    else if (rows_2 == 2 && cols_2 == 2) det = (matrix_1[0][0] * matrix_1[1][1]) - (matrix_1[0][1] * matrix_1[1][0]);
    else if (rows_2 == 1 && cols_2 == 1)det = matrix_1[0][0];

    else
    {
        for (int i = 0; i < rows_2; i++) {
            vector<vector<int>> submatrix(rows_2 - 1, vector<int>(cols_2 - 1));


            for (int j = 1; j < rows_2; j++) {
                for (int k = 0, l = 0; k < cols_2; k++) {
                    if (k != i) {
                        submatrix[j - 1][l] = matrix_1[j][k];
                        l++;
                    }
                }
            }


            det += (i % 2 == 0 ? 1 : -1) * matrix_1[0][i] * matrix_2_det(submatrix, rows_2 - 1, cols_2 - 1);
        }
    }
    return det;


}
void matrix_print(vector<vector <int>>& matrix, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++) cout << matrix[i][j] << " ";
        cout << endl;
    }

}
