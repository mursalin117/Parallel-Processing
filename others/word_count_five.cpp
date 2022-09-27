#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("text_for_5.txt", "r", stdin);

    map <string, int> mymap;
    string s;
    while(getline(cin, s)) {
        mymap[s]++;
    }
    vector <string, int> res (mymap.begin(), mymap.end())
    return 0;
}