//Not efficient

// unordered_map<pair<int, int>, int> vis;
//     bool isSafe(int x, int board, vector<vector<char>>& board)
//     {
//         if(x>=0 && y>=0 && x<board.size() && y<board[0].size())
//             return true;
//         return false;
//     }
//     bool dfs(vector<vector<char>>& board, int idx, int l, int i, int j, string word)
//     {
//         if(idx==l)
//             return true;
//         if(isSafe(i,j,board) && board[i][j]==word[idx] && vis.find({i, j})==vis.end())
//         {
//             vis.insert({i,j});
//             bool r1 = dfs(board, idx+1, l, i-1, j, word);
//             bool r2 = dfs(board, idx+1, l, i, j-1, word);
//             bool r3 = dfs(board, idx+1, l, i+1, j, word);
//             bool r4 = dfs(board, idx+1, l, i, j+1, word);
//             return r1|r2|r3|r4;
//         }
//         return false;
//     }
//     bool exist(vector<vector<char>>& board, string word) {
//         if(word.length()<1)     return false;
//         int m= board.size();
//         int n= board[0].size();
//         for(int i=0; i<m; i++)
//         {
//             for(int j=0; j<n; j++)
//             {
//                 vis.clear();
//                 if(board[i][j]==word[0] && dfs(board, 0, word.length(), i, j, word))
//                     return true;
//             }
//         }
//         return false;
//     }



//OPtimal

class Solution {
    public:
         bool exist(vector<vector<char> > &board, string word) {
             m=board.size();
             n=board[0].size();
            for(int x=0;x<m;x++)
                for(int y=0;y<n;y++)
                {
                    if(isFound(board,word.c_str(),x,y))
                        return true;
                }
            return false;
        }
    private:
        int m;
        int n;
        bool isFound(vector<vector<char> > &board, const char* w, int x, int y)
        {
            if(x<0||y<0||x>=m||y>=n||board[x][y]=='\0'||*w!=board[x][y])
                return false;
            if(*(w+1)=='\0')
                return true;
            char t=board[x][y];
            board[x][y]='\0';
            if(isFound(board,w+1,x-1,y)||isFound(board,w+1,x+1,y)||isFound(board,w+1,x,y-1)||isFound(board,w+1,x,y+1))
                return true; 
            board[x][y]=t;
            return false;
        }
    };