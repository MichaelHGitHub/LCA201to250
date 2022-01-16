#include "header.h"
#include <queue>
#include <unordered_set>

static bool checkCourse(int course, vector<vector<int >>& dependencies, vector<bool>& marks, unordered_set<int>& pending);

bool canFinish_r(int numCourses, vector<vector<int>>& prerequisites)
{
    // Build the edges of each vertex
    vector<vector<int >> dependencies(numCourses);

    for (int i = 0; i < prerequisites.size(); i++)
    {
        dependencies[prerequisites[i][0]].push_back(prerequisites[i][1]);
    }

    // accelerator
    vector<bool> marks(numCourses, false);

    // Check if there is loop
    for (int i = 0; i < numCourses; i++)
    {
        std::unordered_set<int> pending;
        if(!checkCourse(i, dependencies, marks, pending))
        {
            return false;
        }
    }

    return true;
}


bool checkCourse(int course, vector<vector<int >>& dependencies, vector<bool>& marks, unordered_set<int>& pending)
{
    if (marks[course] || dependencies[course].size() == 0)
    {
        return true;
    }

    for (int i = 0; i < dependencies[course].size(); i++)
    {
        if (pending.find(dependencies[course][i]) != pending.end())
        {
            return false;
        }

        pending.insert(dependencies[course][i]);

        if (!checkCourse(dependencies[course][i], dependencies, marks, pending))
        {
            return false;
        }

        pending.erase(dependencies[course][i]);
    }

    marks[course] = true;

    return true;
}