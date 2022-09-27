#include <bits/stdc++.h>

using namespace std;

int main() {
    vector <vector<int>> mat1, mat2;
    mat1 = {
        {2, 2, 2},
        {2, 2, 2},
        {2, 2, 2}
    };
    mat2 = {
        {4, 4, 4},
        {4, 4, 4},
        {4, 4, 4}
    };

    int m = mat1.size();
    int n1 = mat1[0].size();
    int n2 = mat2.size();
    int p = mat2[0].size();

    if (n1 == n2) {
        vector <vector<int>> res;
        vector<int>tempVec;
        for (int i = 0; i < m; i++) {
            for (int k = 0; k < p; k++) {
                int temp = 0;
                for (int j = 0; j < n1; j++) {
                    temp += mat1[i][j] * mat2[j][k];
                }
                tempVec.push_back(temp);
            }
            res.push_back(tempVec);
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < p; j++) {
                cout << res[i][j] << " ";
            }
            cout << endl;
        }
    }
    else {
        cout << "Impossible matrix multiplication" << endl;
    }

    return 0;
}