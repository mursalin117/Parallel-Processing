#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("bernstein_input.txt", "r", stdin);
    int n;
    cin >> n;
    cout << n << endl;
    getchar();
    string str;
    getline(cin, str);
    cout << str << endl;
    vector <vector<char>> ip(n);
    vector <vector<char>> op(n);
    cout << ip.size() << endl;
    cout << ip.size() << endl;

    int x = 0, y = 0;
    int i, j; 
    for (i = 0; i < str.size(); i++){
        if (str[i] == ':') {
            // cout << str[i] << endl;
            for (j = i+2; ; j++) {
                // cout << str[j] << " ";
                if (str[j] == '\0' || str[j] == ';') {
                    break;
                }
                if (str[j] >= 'A' && str[j] <= 'Z') {
                    // cout << str[j] << endl;
                    if (str[j+1] == ':' && str[j+2] == '=') {
                        op[x].push_back(str[j]);
                    }
                    else {
                        ip[y].push_back(str[j]);
                    } 
                }
            }
            // cout << endl;
            x++;
            y++;
            i = j-1;
        }
    }
    
    // for (i = 0; i < n; i++) {
    //     for (j = 0; j < ip[i].size(); j++) {
    //         cout << ip[i][j] << " ";
    //     }
    //     cout << endl;
    //     for (j = 0; j < op[i].size(); j++) {
    //         cout << op[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    // set<int>s;

    for (i = 0; i < n-1; i++) {
        for (j = i + 1; j < n; j++) {
            int cnt = 0;
            // cout << "te" << endl;
            for (int k = 0; k < ip[i].size(); k++) {
                if (ip[i][k] == op[j][0]) {
                    cnt++;
                }
            }
            if (cnt > 0) {
                continue;
            }
            // cout << "te2" << endl;
            cnt = 0;
            for (int k = 0; k < ip[i].size(); k++) {
                if (ip[j][k] == op[i][0]) {
                    cnt++;
                }
            }
            if (cnt > 0) {
                continue;
            }
            // cout << "te3" << endl;
            if (op[i][0] == op[j][0]) {
                continue;
            }
            // s.insert(i);
            // s.insert(j);
            cout << "P" << i+1 << " P" << j+1 << endl;
        }
    }

    // for (auto item : s) {
    //     cout << item << endl;
    // }

    return 0;
}