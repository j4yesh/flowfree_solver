#include <bits/stdc++.h>
using namespace std;
vector<pair<int,int>>sign={{0,1},{0,-1},{1,0},{-1,0}};

void printBoard(vector<vector<char>>board){
  for(auto it: board){
    for(auto ut: it){
      cout<<ut<<" ";
    } cout<<endl;
  }
}

  bool valid(vector<vector<char>>&board,int row,int col){
    // cout<<row<<" "<<col<<endl;
    int m=board.size(),n=board[0].size();
    if(row>=m || row<0 || col>=n || col<0){return false;}
    if(isupper(board[row][col]))return false;
    if(board[row][col]=='x' || (board[row][col]>='a' && board[row][col]<='z')){
      return false;
    }
    return true;
  }

  bool solution(vector<vector<char>>&board,
              int row,
              int col,
              vector<pair<char,pair<int,int>>>&color,
              int cidx ){
      if(board[row][col]==color[cidx].first && (row!=color[cidx].second.first
        && col!=color[cidx].second.second)){
        return true;
      }
      for(auto it: sign){
        int nextX=row+it.first;
        int nextY=col+it.second;
         if((nextX>=0 && nextX<board.size() && nextY>=0 && nextY<board[0].size())&&
          board[nextX][nextY] == color[cidx].first && (nextX!=color[cidx].second.first || nextY!=color[cidx].second.second)){
           if(cidx+1==color.size()){
            return true;
           }
           if(solution(board,color[cidx+1].second.first,color[cidx+1].second.second,color,cidx+1)){
            return true;
           }
           return false;
         }
         if(valid(board,nextX,nextY)){
            board[nextX][nextY]=tolower(color[cidx].first);
            if(solution(board,nextX,nextY,color,cidx)){
              return true;
            }
            board[nextX][nextY]='_'; //:(
         }
      }
      return false;
  }

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);  
  
  vector<vector<char>>board={
              {'R','_','G','_','Y',},
              {'_','_','B','_','O',},
              {'_','_','_','_','_',},
              {'_','G','_','Y','_',},
              {'_','R','B','O','_',}, };

// vector<vector<char>>board={
//               {'B','_','_','_','Y',},
//               {'_','_','_','_','_',},
//               {'_','R','G','_','_',},
//               {'_','_','B','_','_',},
//               {'G','R','Y','_','_',}, }; //l30


  // vector<vector<char>>board={
  //             {'G','Y','C','_','R','B'},
  //             {'_','_','_','_','O','_'},
  //             {'_','_','C','_','_','_'},
  //             {'_','_','R','_','_','_'},
  //             {'G','_','O','_','_','_'},
  //             {'Y','_','B','_','_','_'},
  //              };

  // vector<vector<char>>board={
  //             {'_','_','_','_','O','N','_','_','N'},
  //             {'_','_','_','_','P','_','_','_','_'},
  //             {'_','P','U','_','_','_','R','_','Y'},
  //             {'_','_','_','_','_','_','C','_','_'},
  //             {'_','_','_','_','U','_','_','G','_'},
  //             {'_','B','G','_','_','_','_','_','R'},
  //             {'_','_','Y','_','O','_','_','_','_'},
  //             {'_','_','B','_','_','_','_','C','_'},
  //             {'_','_','_','_','_','_','_','_','_'},
  //           }; //l22 9*9

  int m=board.size(),n=board[0].size();
  vector<pair<char,pair<int,int>>>color;
  unordered_set<char>s;
  for(int i=0;i<m;i++){
    for(int j=0;j<n;j++){
        if(board[i][j]!='_' && s.find(board[i][j])==s.end()){
          color.push_back({board[i][j],{i,j}});
          s.insert(board[i][j]);
        } 
    }
  }  

  int p=color.size();
  

  printBoard(board);
  cout<<endl<<endl;
  // int sol=solution(board,color[0].second.first,color[0].second.second,color,0);

  int sol;
  for(int i=0;i<m;i++){
    for(int j=0;j<n;j++){
      if(board[i][j]!='_' && s.find(board[i][j])!=s.end()){
        sol=solution(board,i,j,color,0);
        if(sol){
          printBoard(board); 
        }else{
          cout<<"solution does not exist bro :("<<endl;
        }
        return 0;
      }
    }
  }
        // sol=solution(board,0,0,color,0);


  return 0;
}
