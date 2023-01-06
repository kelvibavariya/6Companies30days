/*7.Course Schedule
There are a total of numCourses courses you have to take,
labeled from 0 to numCourses - 1. You are given an array
prerequisites where prerequisites[i] = [ai, bi] indicates
that you must take course bi first if you want to take course ai.
For example, the pair [0, 1], indicates that to take course 0
you have to first take course 1.Return true if you can finish
all courses. Otherwise, return false.*/

/*Approach-KAHN'S ALGORITHM/Topological sort*/
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses],inDeg(numCourses,0);
        int c=0;
        for(int i=0;i<prerequisites.size();i++)
        {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        for(int i=0;i<numCourses;i++)
        {
            for(int j=0;j<adj[i].size();j++)
                inDeg[adj[i][j]]++;     //Compute in-degree
        }
        queue<int> q;
        for(int i=0;i<numCourses;i++)
        {
            if(!inDeg[i])q.push(i);  //add 0 degree vertex into queue
        }
        //BFS
        while(!q.empty())
        {
            int n=q.front();
            q.pop();
            c++;    //count visited vertex
            for(int i=0;i<adj[n].size();i++)
            {
                inDeg[adj[n][i]]--; //Decrease in-degree by 1 for all adjcent nodes of n
                if(inDeg[adj[n][i]]==0)  //if in-degree reduced to 0 add it to queue
                    q.push(adj[n][i]);
            }
        }

        return c==numCourses; /*If the count of visited vertex is not equal to no. of vertex then the topological sort is not possible*/
    }
};
