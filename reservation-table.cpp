#include <bits/stdc++.h>

using namespace std;

// function for calculating forbidden latency
vector <int> forbiddenLatency(vector <vector<int>> &arr) {
    set <int> s;
    int row = arr.size();
    int col = arr[0].size();

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col-1; j++) {
            for (int k = j+1; k < col; k++) {
                if (arr[i][j] && arr[i][k]) {
                    s.insert(k-j);
                }
            }
        }
    }
    vector <int> res(s.begin(), s.end());
    return res;
}

// function for calculating permissible latency
vector <int> permissibleLatency(vector <int> &fl, int col) {
    vector <int> res;
    for (int i = 0, j = 0; i < col; i++) {
        if (i == fl[j]-1) {
            j++;
        } 
        else {
            res.push_back(i+1);
        }
    }
    return res;
}

// function for calculating collision vector
vector <int> collisionVector(vector<int> &fl) {
    int maxFLVal = fl[fl.size()-1];
    vector <int> res(maxFLVal);
    for (int i = 0, j = 0; i < maxFLVal; i++) {
        if (i == fl[j]-1) {
            res[i] = 1;
            j++;
        }
        else {
            res[i] = 0; 
        }
    }
    return res;
}

// function for generating task table and collision detection
void taskTable (vector<vector<int>> &arr, vector<int> &assign) {
    // task initiation
    int i, j, k;
    int row = arr.size();
    int col = arr[1].size();
    int n = assign.size();
    vector <vector<int>> vec(row, vector<int>(col*5, 0));
    for (j = 0; j < col; j++) {
        for (i = 0; i < row; i++) {
            for (k = 0; k < n; k++) {
                if (arr[i][j]) {
                    if (vec[i][j+assign[k]-1] == 0) {
                        vec[i][j+assign[k]-1] = k+1;
                    }
                    else {
                        cout << "Collision found!!!" << endl;
                        cout << "task-" << k+1 << " collides with task-" << vec[i][j+assign[k]-1] << endl;
                        cout << "at stage " << i+1 << " and time " << j+assign[k] << endl;
                        return;
                    }
                }
            }
        }
    }

    cout << "Task table" << endl;
    for (i = 0; i < vec.size(); i++) {
        for (j = 0; j < vec[i].size(); j++) {
            cout << vec[i][j] << " ";
        }
        cout << endl;
    }
    
    cout << "No collision found" << endl;
}

// function for state diagram calculation
void stateDiagram(vector<int> &cv) {
    map <int, vector<int>> graph;
    
    int icv = 0;
    int len = cv.size();
    for (int i = 0; i < len; i++) {
        icv = (icv * 2 + cv[len-i-1]);
    }
    
    queue<int>q;
    q.push(icv);
    vector<int>res;
    res.push_back(icv);
    
    while (!q.empty()){
        int x = q.front();
        for (int i = 0; i <= len; i++) {
            int temp = x;
            if (!(temp & 1<<i)) {
                temp = icv | (temp>>(i+1));
                // cout << x << " " << i+1 << " " << temp << " " << graph[x].size() << endl;
                int check = count(res.begin(), res.end(), temp);
                if (check == 0) {
                    q.push(temp);
                    res.push_back(temp);
                }
                graph[x].push_back(i+1);
                graph[x].push_back(temp);
            }
        }
        // cout << q.size() << endl;
        // cout << "------------" << endl;
        q.pop();
    }
    
    // showing the state transition
    cout <<  "State Diagram:" << endl;
    for (auto item : res) {
        cout << item << " :"; 
        for (int i = 0; i < graph[item].size(); i++) {
            cout << "(" << graph[item][i] << ", " << graph[item][i+1] << ")" << " ";
            i++;
        }
        cout << endl;
    } 
}

int main() {
    // Taking input the reservation table from file
    freopen("reservation-table.txt", "r", stdin);
    int row, col;
    cin >> row >> col;
    vector <vector <int>> arr(row, vector<int>(col, 0));
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cin >> arr[i][j];
            // cout << arr[i][j] << " ";
        }
    }

    // forbidden latency calculation
    vector <int> fl = forbiddenLatency(arr);
    cout << "Forbidden Latency: ";
    for (int i = 0; i < fl.size(); i++) {
        cout << fl[i] << " ";
    }
    cout << endl;

    // permissible latency calculation
    vector <int> pl = permissibleLatency(fl, col);
    cout << "Permissible Latency: ";
    for (int i = 0; i < pl.size(); i++) {
        cout << pl[i] << " ";
    }
    cout << endl;

    // collision vector calculation
    vector <int> collision = collisionVector(fl);
    cout << "Collision vector: ";
    for (int i = 0; i < collision.size(); i++) {
        cout << collision[collision.size()-i-1] << " ";
    } 
    cout << endl;


    // input of tasks no. and their initiation time
    int n;
    cin >> n;
    vector <int> assign(n);
    for (int i = 0; i < n; i++) {
        cin >> assign[i];
    }

    // task table generation and collision detection
    taskTable(arr, assign);

    // state diagram calculation
    stateDiagram(collision);

    return 0;
}