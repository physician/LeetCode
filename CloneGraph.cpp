/*
 Author:     physician
 Date:       Feb 11, 2015
 Update:     Feb 11, 2015
 Problem:    Clone Graph
 Difficulty: Medium
 Source:     http://oj.leetcode.com/problems/copy-list-with-random-pointer/

 Problem Description:
 Clone Graph: 

 Clone an undirected graph. Each node in the graph contains a label and a list of its neighbors.

 OJ's undirected graph serialization:
 Nodes are labeled uniquely.

 We use # as a separator for each node, and , as a separator for node label and each neighbor of the node.
 As an example, consider the serialized graph {0,1,2#1,2#2,2}.

 The graph has a total of three nodes, and therefore contains three parts as separated by #.

 First node is labeled as 0. Connect node 0 to both nodes 1 and 2.
 Second node is labeled as 1. Connect node 1 to node 2.
 Third node is labeled as 2. Connect node 2 to node 2 (itself), thus forming a self-cycle.
 Visually, the graph looks like the following:

        1
       / \
      /   \
     0 --- 2
          / \
          \_/

 Notes:
 1. First implementation, recursion, BFS/DFS. 
 2. Create object pointer using new statement.
 3. Compile using g++: g++ -std=c++0x CloneGraph.cpp -o CloneGraph.
*/


/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
 
# include <iostream>
# include <stack>
# include <queue>
# include <unordered_set>
# include <unordered_map>

using namespace std;
 
struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};

class Solution {
public:
    typedef unordered_map<UndirectedGraphNode *, UndirectedGraphNode *> MAP;

    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        return cloneGraphBFS(node); 
        //return cloneGraphDFS(node); 
        //return cloneGraphRecursive(node); 
    }

    // BFS
    UndirectedGraphNode *cloneGraphBFS(UndirectedGraphNode *node) {
        if (node == nullptr)
            return nullptr;
        unordered_map<UndirectedGraphNode *, UndirectedGraphNode *> visited;
        UndirectedGraphNode *newNode = new UndirectedGraphNode(node->label);
        visited[node] = newNode;
        queue<UndirectedGraphNode *> q;
        q.push(node);
        while(!q.empty()) {
            UndirectedGraphNode *oldNode = q.front();
            q.pop();
            for (auto neighbor : oldNode->neighbors) {
                if (visited.find(neighbor) == visited.end()) {
                    UndirectedGraphNode *neighborNode = new UndirectedGraphNode(neighbor->label);
                    visited[neighbor] = neighborNode;
                    q.push(neighbor);
                }
                visited[oldNode]->neighbors.push_back(visited[neighbor]);
            }
        }
        return visited[node];
    }

    // DFS
    UndirectedGraphNode *cloneGraphDFS(UndirectedGraphNode *node) {
        if (node == nullptr)
            return nullptr;
        unordered_map<UndirectedGraphNode *, UndirectedGraphNode *> visited;
        UndirectedGraphNode *newNode = new UndirectedGraphNode(node->label);
        visited[node] = newNode;
        stack<UndirectedGraphNode *> stk;
        stk.push(node);
        while(!stk.empty()) {
            UndirectedGraphNode *oldNode = stk.top();
            stk.pop();
            for (auto neighbor : oldNode->neighbors) {
                if (visited.find(neighbor) == visited.end()) {
                    UndirectedGraphNode *neighborNode = new UndirectedGraphNode(neighbor->label);
                    visited[neighbor] = neighborNode;
                    stk.push(neighbor);
                }
                visited[oldNode]->neighbors.push_back(visited[neighbor]);
            }
        }
        return visited[node];
    }

    // Recursion
    UndirectedGraphNode *cloneGraphRecursive(UndirectedGraphNode *node) {
        MAP visited;
        return cloneGraphRecursiveHelper(node, visited);
    }

    UndirectedGraphNode *cloneGraphRecursiveHelper(UndirectedGraphNode *node, MAP &visited) {
        if (node == nullptr)
            return nullptr;
        if (visited.find(node) != visited.end())
            return visited[node];
        UndirectedGraphNode *newNode = new UndirectedGraphNode(node->label);
        visited[node] = newNode;
        for (auto neighbor : node->neighbors)
            newNode->neighbors.push_back(cloneGraphRecursiveHelper(neighbor, visited));
        return newNode;
    }
};

void printGraph(UndirectedGraphNode *node) {
    unordered_set<int> visited;
    stack<UndirectedGraphNode *> stk;
    stk.push(node);
    while (!stk.empty()) {
        UndirectedGraphNode *ptr = stk.top();
        stk.pop();
        if (visited.find(ptr->label) == visited.end()) {
            visited.insert(ptr->label);
            cout << ptr->label << " --> ";
            for (auto neighbor : ptr->neighbors)
                cout << neighbor->label << " ";
            cout << endl;
            for (auto neighbor : ptr->neighbors)
                if (visited.find(neighbor->label) == visited.end())
                    stk.push(neighbor);
        }
    }
}


int main() {
    UndirectedGraphNode node0(0);
    UndirectedGraphNode node1(1);
    UndirectedGraphNode node2(2);
    node0.neighbors.push_back(&node1);
    node0.neighbors.push_back(&node2);
    node1.neighbors.push_back(&node0);
    node1.neighbors.push_back(&node2);
    node2.neighbors.push_back(&node0);
    node2.neighbors.push_back(&node1);
    node2.neighbors.push_back(&node2);

    Solution sol;

    cout << "Original Graph:" << endl;
    printGraph(&node0);

    cout << "Cloned Graph:" << endl;
    printGraph(sol.cloneGraph(&node0));
}
