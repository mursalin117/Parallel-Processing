#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("bernstein_input2.txt", "r", stdin);
    vector<string>str;
    string s;
    while (getline(cin, s)) {
        // cout << s << endl;
        str.push_back(s);
    }

    vector <vector<char>> ip(str.size());
    vector <char> op;
    int x = 0;

    for (int i = 0; i < str.size(); i++) {
        for (int j = 0; j < str[i].size(); j++) {
            int k;
            if (str[i][j] == ':') {
                for (k = j+1; str[i][k] != ';' && str[i][k] != '\0'; k++) {
                    // cout << str[i][k] << " ";
                    if (str[i][k] >= 'A' && str[i][k] <= 'Z') {
                        if (str[i][k+1] == ':' && str[i][k+2] == '=') {
                            op.push_back(str[i][k]);
                            k += 2;
                        }
                        else {
                            ip[x].push_back(str[i][k]);
                            k += 1;
                        }
                    }
                }
                // cout << endl;
                x++;
                j = k-1;
            }
            
        }
    }

    // for (int i = 0; i < str.size(); i++) {
    //     for (int j = 0; j < ip[i].size(); j++) {
    //         cout << ip[i][j] << " ";
    //     }
    //     cout << endl;
        
    //     cout << op[i] << endl;
    // }


    for (int i = 0; i < str.size()-1; i++) {
        for (int j = i + 1; j < str.size(); j++) {
            int cnt = 0;
            for (int k = 0; k < ip[i].size(); k++) {
                if (ip[i][k] == op[j]) {
                    cnt++;
                }
            }
            if (cnt > 0) {
                cout << "P" << i+1 << " to P" << j+1 << " : P" << j+1 << " is anti-dependent to P" << i+1 << endl;
                continue; 
            }
            // cnt = 0;
            for (int k = 0; k < ip[j].size(); k++) {
                if (ip[j][k] == op[i]) {
                    cnt++;
                }
            }
            if (cnt > 0) {
                cout << "P" << i+1 << " to P" << j+1 << " : P" << j+1 << " is flow-dependent to P" << i+1 << endl;
                continue; 
            }
            if (op[i] == op[j]) {
                cout << "P" << i+1 << " to P" << j+1 << " : P" << j+1 << " is output-dependent to P" << i+1 << endl;
                continue;
            }
            cout << "P" << i+1 << " to P" << j+1 << " : independent" << endl;
        }
    }

    return 0;
}