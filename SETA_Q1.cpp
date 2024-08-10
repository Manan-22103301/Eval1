#include <iostream>
#include <vector>

using namespace std;

int Find_determinant(const vector<vector<int>>& matrix, int size) {

    if (size == 1)
    {
        return matrix[0][0];
    }
    else if (size == 2) {
        return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
    }

    int det = 0;

    vector<vector<int>> submatrix(size - 1, vector<int>(size - 1));

    for (int x = 0; x<size;x++) {

        for (int i = 1; i <size;i++)
        {
            int sub_col = 0;
            for (int j = 0; j < size;j++)
            {
                if (j == x) continue;
                submatrix[i - 1][sub_col++] = matrix[i][j];
            }
        }


        int cofactor = (x % 2 == 0 ? 1 : -1) * matrix[0][x];
        det += cofactor * Find_determinant(submatrix, size - 1);
    }

    return det;
}


int main()
{
    int size;
    cout << "Enter the size of the matrix: ";
    cin >> size;

    if (size < 1)
    {
        cout << "Matrix size should be greater than 1"<<endl;
        return 1;
    }

   vector<vector<int>> matrix(size, vector<int>(size));
   cout << "Enter the elements of the " << size << "x" << size << " matrix:\n";
    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size; ++j)
        {
            cin >> matrix[i][j];
        }
    }
    cout<<"The given matrix is : "<<endl;
    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size; ++j)
        {
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }


    int det = Find_determinant(matrix, size);

    cout << "The determinant of the matrix is: " << det << endl;

    return 0;
}
