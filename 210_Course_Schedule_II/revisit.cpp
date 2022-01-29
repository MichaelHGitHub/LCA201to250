#include "header.h"
#include <unordered_set>

using namespace std;

static bool canFinishCourse(int curCourse, vector<int>& order, vector<vector<int>>& dependencies, unordered_set<int>& visited, vector<int>& marks);

vector<int> findOrder_r(int numCourses, vector<vector<int>>& prerequisites)
{
    vector<int> order;

    vector<int> marks(numCourses, 0);
    vector<vector<int>> dependencies(numCourses, vector<int>());

    for (int i = 0; i < prerequisites.size(); i++)
    {
        dependencies[prerequisites[i][0]].push_back(prerequisites[i][1]);
    }

    for (int i = 0; i < numCourses; i++)
    {
        unordered_set<int> pending;
        if (!canFinishCourse(i, order, dependencies, pending, marks))
        {
            order.clear();
            break;
        }
    }

    return order;
}

static bool canFinishCourse(int curCourse, vector<int>& order, vector<vector<int>>& dependencies, unordered_set<int>& pending, vector<int>& marks)
{
    if (marks[curCourse] == 1)
    {
        return true;
    }
    else if (marks[curCourse] == -1)
    {
        return false;
    }

    if (pending.find(curCourse) != pending.end())
    {
        marks[curCourse] = -1;
        return false;
    }

    pending.insert(curCourse);

    for (int i = 0; i < dependencies[curCourse].size(); i++)
    {
        if (!canFinishCourse(dependencies[curCourse][i], order, dependencies, pending, marks))
        {
            return false;
        }
    }

    pending.erase(curCourse);
    marks[curCourse] = 1;
    order.push_back(curCourse);

    return true;
}