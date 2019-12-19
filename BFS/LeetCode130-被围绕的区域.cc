#include <vector>
#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:

    void dfs(vector<vector<char>>& board,int i,int j){
        if(i<0||i>=board.size()||j<0||j>=board[0].size()||board[i][j]=='X'||board[i][j]=='O'){
            return ;
        }
        board[i][j]='#';
        dfs(board,i-1,j);
        dfs(board,i+1,j);
        dis(board,i,j+1);
        dis(board,i,j-1)；
    }
    void solve(vector<vector<char>>& board) {
        if(boad.size()==0){
            return ;
        }
        int m=board.size();
        int n=board[0].size();

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                bool isedge= (i==0)||(i==m-1)||(j==0)||(j==n-1);
                if(isedge&&board[i][j]=='O'){
                    dfs(board,i,j);
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='O'){
                    board[i][j]='X';
                }
                if(board[i][j]=='#'){
                    board[i][j]='O';
                }

            }
        }

        
    }
};


//解法二：采用递归的形式进行计算求解
class Solution {
public:
    void explore(vector<vector<char>>& board, int y, int x, int h, int w) {
        if (board[y][x] == 'V') {
            board[y][x] = 'O';
            if (x) explore(board, y, x - 1, h, w);
            if (x + 1 < w) explore(board, y, x + 1, h, w);
            if (y) explore(board, y - 1, x, h, w);
            if (y + 1 < h) explore(board, y + 1, x, h, w);
        }
    }

    void solve(vector<vector<char>>& board) {
        const int h = board.size();
        if (!h) return;
        const int w = board[0].size();
        if (!w) return;

        for (int y = 0; y < h; y++) {
            for (int x = 0; x < w; x++) {
                if (board[y][x] == 'O') board[y][x] = 'V';
            }
        }

        for (int x = 0; x < w; x++) {
            explore(board, 0, x, h, w);
            explore(board, h - 1, x, h, w);
        }

        for (int y = 0; y < h; y++) {
            explore(board, y, 0, h, w);
            explore(board, y, w - 1, h, w);
        }

        for (int y = 0; y < h; y++) {
            for (int x = 0; x < w; x++) {
                if (board[y][x] == 'V') board[y][x] = 'X';
            }
        }
    }
};