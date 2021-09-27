#include <iostream>
#include <stack>
#include <vector>
#include <string>

using namespace std;

void DFS(int n, vector<int>& visited, stack<int>& dfs_stack, vector<vector<int>>& computers)
{
    //int node = 0;

    while(!dfs_stack.empty())
    {
        int node = dfs_stack.top();
        dfs_stack.pop();

        for (int i = 0; i < n; i++)
        {
            if (i != node && computers[node][i] == 1 && visited[i] == 0)
            {
                visited[i] = 1;
                dfs_stack.push(i);
            }
        }
    }
}

int solution(int n, vector<vector<int>> computers)
{
    int network = 0;

    vector<int> visited(n, 0);
    stack<int> dfs_stack;

    

    for (int i = 0; i < n; i++)
    {
        if (visited[i] == 1)
            continue;

        network++;
        visited[i] = 1;
        dfs_stack.push(i);
        DFS(n, visited, dfs_stack, computers);
    }



    return network;
}

//int solution(int n, vector<vector<int>> computers) 
//{
//    int answer = 0;
//
//    queue<int> bfs_queue;
//    vector<int> visited(n, 0);
//
//    
//
//    bool unvisit =true;
//    int unvisited_idx = 0;
//
//    while (unvisit)
//    {
//        unvisit = false;
//
//        bfs_queue.push(unvisited_idx);
//        visited[unvisited_idx] = 1;
//
//        while (!bfs_queue.empty())
//        {
//            int node = bfs_queue.front();
//            bfs_queue.pop();
//            visited[node] = 1;
//
//            for (int i = 0; i < n; i++)
//            {
//                if (visited[i] == 0 && computers[node][i] == 1)
//                {
//                    bfs_queue.push(i);
//                    visited[i] = 1;
//                }
//            }
//        }
//
//        answer++;
//
//        for (int i = 0; i < visited.size(); i++)
//        {
//            if (visited[i] == 0)
//            {
//                unvisit = true;
//                unvisited_idx = i;
//                break;
//            }
//
//        }
//    }
//
//    
//
//    return answer;
//}