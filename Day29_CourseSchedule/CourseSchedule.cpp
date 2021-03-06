// Problem Link : https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/538/week-5-may-29th-may-31st/3344/

// Course Schedule

/* There are a total of numCourses courses you have to take, labeled from 0 to numCourses-1.

Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?

 

Example 1:

Input: numCourses = 2, prerequisites = [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take. 
             To take course 1 you should have finished course 0. So it is possible.
Example 2:

Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
Output: false
Explanation: There are a total of 2 courses to take. 
             To take course 1 you should have finished course 0, and to take course 0 you should
             also have finished course 1. So it is impossible.
 

Constraints:

The input prerequisites is a graph represented by a list of edges, not adjacency matrices. Read more about how a graph is represented.
You may assume that there are no duplicate edges in the input prerequisites.
1 <= numCourses <= 10^5 */

#define MAXN 100000
class Solution {
public:
    vector<int> adj[MAXN];
    bool vis[MAXN];
    bool trav[MAXN];
    
    bool topologicalSort(int src) {
        if (trav[src]) return false;
        
        vis[src] = true;
        trav[src] = true;
        for (int x : adj[src]) {
            if (!topologicalSort(x)) return false;
        }
        
        trav[src] = false;
        
        return true;
    }
    bool canFinish(int numCourses, vector<vector<int>>& pre) {
        for (vector<int> x : pre) {
            adj[x[0]].push_back(x[1]);
        }
        
        for (int i = 0; i < numCourses; ++i) {   
            if (!topologicalSort(i)) return false;
        }
        
        return true;
    }
};