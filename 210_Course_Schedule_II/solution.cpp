#include <unordered_set>
#include "header.h"

static bool canFinish(vector<int>& result, int course, vector<unordered_set<int>>& dependency, vector<int>& states);

// DFS

vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites)
{
    vector<unordered_set<int>> dependency(numCourses, unordered_set<int>());
    vector<int> result;

    // states: 0:initial, 1:in-progress, 2:free.
    vector<int> states(numCourses, 0);

    // Build graph: vertex->{ all dependees}
    for (int i = 0; i < prerequisites.size(); i++)
    {
        dependency[prerequisites[i][0]].insert(prerequisites[i][1]);
    }

    // Check each of the course
    for (int i = 0; i < numCourses; i++)
    {
        if (!canFinish(result, i, dependency, states))
        {
            result.clear();
            return result;
        }
    }

    return result;
}


bool canFinish(vector<int>& result, int course, vector<unordered_set<int>>& dependency, vector<int>& states)
{
    if (states[course] == 2)
    {
        return true;
    }
    else if (states[course] == 1)
    {
        // If the current node is alreadyin the checking process, there is 
        // loop.
        return false;
    }
    else
    {
        // Change the node state to in progress.
        states[course] = 1;
    }

    unordered_set<int> dependees = dependency[course];
    if (dependees.empty())
    {
        // If a node has no dependency, it is free.
        states[course] = 2;
        result.push_back(course);
        return true;
    }

    // If all the dependees are free, the current node is free.
    for (unordered_set<int>::iterator it = dependees.begin(); it != dependees.end(); it++)
    {
        if (!canFinish(result, *it, dependency, states))
        {
            return false;
        }
    }
    states[course] = 2;
    result.push_back(course);
    return true;
}