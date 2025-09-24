int maxShared(int friends_nodes, int friends_edges, 
              vector<int> friends_from, vector<int> friends_to, 
              vector<int> friends_weight) {
    
    // Create a map where key is interest (weight) and value is set of nodes connected by that interest
    unordered_map<int, unordered_set<int>> interestToNodes;
    
    // Build the interest to nodes mapping
    for (int i = 0; i < friends_edges; i++) {
        int u = friends_from[i];
        int v = friends_to[i];
        int interest = friends_weight[i];
        
        interestToNodes[interest].insert(u);
        interestToNodes[interest].insert(v);
    }
    
    // Count shared interests between each pair of nodes
    map<pair<int, int>, int> pairSharedInterests;
    
    // For each interest, check all pairs of nodes that share it
    for (auto& [interest, nodes] : interestToNodes) {
        vector<int> nodeList(nodes.begin(), nodes.end());
        
        // Check all pairs in this interest group
        for (int i = 0; i < nodeList.size(); i++) {
            for (int j = i + 1; j < nodeList.size(); j++) {
                int u = min(nodeList[i], nodeList[j]);
                int v = max(nodeList[i], nodeList[j]);
                pairSharedInterests[{u, v}]++;
            }
        }
    }
    
    // Find the maximum number of shared interests
    int maxSharedCount = 0;
    for (auto& [pair, count] : pairSharedInterests) {
        maxSharedCount = max(maxSharedCount, count);
    }
    
    // Find the maximum product among pairs with maximum shared interests
    int maxProduct = 0;
    for (auto& [pair, count] : pairSharedInterests) {
        if (count == maxSharedCount) {
            int product = pair.first * pair.second;
            maxProduct = max(maxProduct, product);
        }
    }
    
    return maxProduct;
}
