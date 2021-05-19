#include <unordered_set>
#include "header.h"

static bool canFinishThisCourse(int course, unordered_set<int>& can_finish, unordered_set<int>& pending, vector<unordered_set<int>>& dependency);

// A course can be finished if
//  1. there is no dependency.
//  2. all the dependent course can be finished.
// So, we can have a helper function to recursively check if a course can be finished using above
// creteria.
// Use a set(can_finish) to track all the courses that can be finished to reduce recursion.
// Use a set(pending) to temporarily save current path to detect looping dependency, 
// which means a course can't be finished. 

bool canFinish(int numCourses, vector<vector<int>>& prerequisites)
{
    // Build the dedpendent information
    vector<unordered_set<int>> dependency(numCourses, unordered_set<int>());
    for (int i = 0; i < prerequisites.size(); i++)
    {
        dependency[prerequisites[i][0]].insert(prerequisites[i][1]);
    }

    unordered_set<int> can_finish;
    unordered_set<int> pending;

    // We don't have to check all the courses, just check the ones that
    // have dependencies.
    for (int i = 0; i < prerequisites.size(); i++)
    {
        int course = prerequisites[i][0];

        pending.insert(course);
        if (!canFinishThisCourse(course, can_finish, pending, dependency))
        {
            return false;
        }
        pending.erase(course);
    }

    return true;
}

bool canFinishThisCourse(int course, unordered_set<int>& can_finish, unordered_set<int>& pending, vector<unordered_set<int>>& dependency)
{
    // If this course has been confirmed can-be-finished, then no need to check again.
    if (can_finish.find(course) != can_finish.end())
    {
        return true;
    }

    // If a course has no dependency, it can be finished.
    unordered_set<int> dependees = dependency[course];
    if (dependees.empty())
    {
        can_finish.insert(course);
        return true;
    }

    // If the dependent courses can be finished, the course itself can be finished.
    for (unordered_set<int>::iterator it = dependees.begin(); it != dependees.end(); it++)
    {
        // If the dependent course is in the dependency chain, there is a loop.
        if (pending.find(*it) != pending.end())
        {
            return false;
        }

        // Check the dependency of the dependent course. 
        pending.insert(*it);
        if (!canFinishThisCourse(*it, can_finish, pending, dependency))
        {
            return false;
        }
        pending.erase(*it);
    }

    // All dependent courses can be finished, the course itself can be finished.
    can_finish.insert(course);
    return true;
}