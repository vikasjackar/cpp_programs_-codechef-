//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
    public:
    int closedIslands(vector<vector<int>>& matrix, int N, int M) {
        // Code here
        vector<int> parent(N*M+1,-1);
        auto get = [&](int r, int c){return r*M+c;};
        function<int(int)> find = [&](int s)->int{
            if (parent[s]<0) return s;
            return s=find(parent[s]);
        };
        function<void(int,int)> Union=[&](int a, int b){
            int p1 = find(a), p2 = find(b);
            if (p1==p2) return;            
            if (parent[p1]<parent[p2]) parent[p2] = p1;
            else parent[p1] = p2;
        };
        for (int j=0;j<M;j++) parent[get(0,j)] = -2;
        for (int j=0;j<M;j++) parent[get(N-1,j)] = -2;
        for (int i=0;i<N;i++) parent[get(i,0)] = -2;
        for (int i=0;i<N;i++) parent[get(i,M-1)] = -2;
        for (int i=1;i<N-1;i++)
            for (int j=1;j<M-1;j++)
            {
                if (!matrix[i][j]) continue;
                if (matrix[i-1][j]) Union(get(i,j),get(i-1,j));
                if (matrix[i+1][j]) Union(get(i,j),get(i+1,j));
                if (matrix[i][j-1]) Union(get(i,j),get(i,j-1));
                if (matrix[i][j+1]) Union(get(i,j),get(i,j+1));
            }
        map<int,int> m;
        int ans=0;
        for (int i=1;i<N-1;i++)
            for (int j=1;j<M-1;j++)
            {
                if (!matrix[i][j]) continue;
                int p = find(get(i,j));
                if (parent[p]==-1&&!m[p]) ans++,m[p]++;
            }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
        int N, M;
        cin >> N >> M;
        vector<vector<int>>matrix(N, vector<int>(M, 0));
        for(int i=0; i<N; i++)
            for(int j=0; j<M; j++)
                cin >> matrix[i][j];
                
        Solution obj;
        int ans = obj.closedIslands(matrix, N, M);
        cout << ans << "\n";
    }
	
	return 0;
	
}


// } Driver Code Ends
