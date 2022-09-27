#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("text_for_2.txt", "r", stdin);

    int m, n1;
    cin >> m >> n1;
    vector <vector<int>> mat1(m, vector<int>(n1));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n1; j++) {
            scanf("%d", &mat1[i][j]); 
        }
    }

    int n2, p;
    cin >> n2 >> p;
    vector <vector<int>> mat2(n2, vector<int>(p));
    for (int i = 0; i < n2; i++) {
        for (int j = 0; j < p; j++) {
            scanf("%d", &mat2[i][j]); 
        }
    }

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