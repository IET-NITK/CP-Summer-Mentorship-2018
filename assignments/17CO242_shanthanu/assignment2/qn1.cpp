//problem: https://www.hackerrank.com/contests/university-codesprint-3/challenges/bobs-game
//solution link: https://www.hackerrank.com/contests/university-codesprint-3/challenges/bobs-game/submissions/code/1307592360

//code:

#include <bits/stdc++.h>

using namespace std;
int grundy[1000][1000];

int mez(set<int>& s) {
    int m = -1;
    while(s.find(++m) != s.end());
    return m;
}

int value(int i, int j) {
    if(i<0 || j<0) {
        return -1;
    }
    return grundy[i][j];
}

int main() {
    int q;
    cin >> q;
    for(int a0 = 0; a0 < q; a0++){
        int n;
        cin >> n;
        vector<string> board(n);
        for(int board_i = 0; board_i < n; board_i++){
        	cin >> board[board_i];
        }
        vector<int> king;
        vector<int> x;
        vector<int> y;
        for(int j = 0; j != n; j++) {
            for(int i = 0; i != n; i++) {
                if(board[i][j] == 'X') {
                    grundy[i][j] = -1;
                }
                else {
                    set<int> s;
                    s.insert(value(i-1,j));
                    s.insert(value(i-1,j-1));
                    s.insert(value(i,j-1));
                    grundy[i][j] = mez(s);
                    if(board[i][j] == 'K') {
                        king.push_back(grundy[i][j]);
                        x.push_back(i);
                        y.push_back(j);
                    }
                }
            }
        }
        int count = 0, xor_sum = 0;
        for(vector<int>::iterator it = king.begin(); it != king.end(); it++) {
            xor_sum ^= (*it);
        }
        if(xor_sum == 0) {
            cout<<"LOSE"<<endl;
        }
        else {
            int temp;
            for(int i = 0; i != king.size(); i++) {
                temp = xor_sum^(king[i]);
                int a = x[i], b = y[i];
                if(temp == value(a-1,b)) {
                    count++;
                }
                if(temp == value(a-1,b-1)) {
                    count++;
                }
                if(temp == value(a,b-1)) {
                    count++;
                }
            }
            cout<<"WIN "<<count<<endl;
        }
    }
    return 0;
}