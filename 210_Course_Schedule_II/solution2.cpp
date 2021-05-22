#include <unordered_set>
#include <queue>
#include "header.h"

// BFS
vector<int> findOrder2(int numCourses, vector<vector<int>>& prerequisites)
{
    vector<vector<int>> graph(numCourses, vector<int>());
    vector<int> result;
    vector<int> degrees(numCourses, 0);

    // Build graph: vertex->{ all dependers };
    for (int i = 0; i < prerequisites.size(); i++)
    {
        graph[prerequisites[i][1]].push_back(prerequisites[i][0]);

        // build dependency degree
        degrees[prerequisites[i][0]]++;
    }

    // In-queue all free crouses.
    queue<int> no_dependency;
    for (int i = 0; i < numCourses; i++)
    {
        if (!degrees[i])
        {
            no_dependency.push(i);
        }
    }

    // Try to free other courses.
    int count = 0;
    while (!no_dependency.empty())
    {
        int course = no_dependency.front();
        no_dependency.pop();
        ++count;
        result.push_back(course);

        // Decrese the degree for all vertices that depends on course.
        for (int i = 0; i < graph[course].size(); i++)
        {
            degrees[graph[course][i]]--;

            // In-queue if the vertex that is just freed.
            if (!degrees[graph[course][i]])
            {
                no_dependency.push(graph[course][i]);
            }
        }
    }

    if (count != numCourses)
    {
        result.clear();
    }

    return result;
}