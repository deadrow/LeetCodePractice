class Solution {
public:
    vector<bool>visited;
    bool dfs(vector<int>& arr, int src){
        if(src<0 or src>=arr.size() or visited[src]) return false;
        if(arr[src] == 0) return true;
        visited[src]=true;
        return dfs(arr, src-arr[src]) or dfs(arr, src+arr[src]);
    }
    bool canReach(vector<int>& arr, int start) {
        visited.resize(arr.size());
        return dfs(arr, start);
    }
};