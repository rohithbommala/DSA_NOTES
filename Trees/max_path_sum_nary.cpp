// C++ code to find maximum path sum
// in a N-ary tree.
#include <bits/stdc++.h>
using namespace std;

int maxSumRecur(int node, int prev, 
                vector<vector<int>> &adj, vector<int> &arr, int &ans) {
    int maxi1 = 0, maxi2 = 0;

    // Traverse all child nodes of the current node
    for (auto v : adj[node]) {

        // Skip the parent node to avoid cycles
        if (v != prev) {
            int val = maxSumRecur(v, node, adj, arr, ans);
            if (val > maxi1) {
                maxi2 = maxi1;
                maxi1 = val;
            }
            else if (val > maxi2) {
                maxi2 = val;
            }
        }
    }

    // Update the answer with the best path sum
    ans = max(ans, arr[node - 1] + maxi1 + maxi2);

    // Return the maximum path sum starting
    // at this node, considering its subtree
    return arr[node - 1] + maxi1;
}

int maxSum(vector<vector<int>> &edges, vector<int> &arr) {
    int n = arr.size();
    vector<vector<int>> adj(n + 1);

    for (auto edge : edges) {
        adj[edge[0]].push_back(edge[1]);
        adj[edge[1]].push_back(edge[0]);
    }

    int ans = 0;
    maxSumRecur(1, -1, adj, arr, ans);
    return ans;
}

int main() {
  
    vector<int> arr = {4, -1, -3, 5, 7, -2};
    vector<vector<int>> edges = {{1, 2}, {1, 3}, {2, 4}, {2, 5}, {2, 6}};
    cout << maxSum(edges, arr);
    return 0;
}
