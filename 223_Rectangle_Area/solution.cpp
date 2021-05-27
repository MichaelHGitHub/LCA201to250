#include <unordered_map>
#include <set>
#include "header.h"

static unordered_map<int, int> getIntersection(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2);

// There are lots of tricky points that need special handling, check the in line comments
// for details.

int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {

    // Rule out the scenario where one rectange nests the other or both are the same.
    if (ax1 <= bx1 && ay1 <= by1 && ax2 >= bx2 && ay2 >= by2)
    {
        return (ax2 - ax1) * (ay2 - ay1);
    }
    else if (bx1 <= ax1 && by1 <= ay1 && bx2 >= ax2 && by2 >= ay2)
    {
        return (bx2 - bx1) * (by2 - by1);
    }

    // Prepare 4 edges of each rectangle, note the direction, always go right or up
    // to fecilitate the increasmential operation later.
    vector<vector<pair<int, int>>> rc1(4, vector<pair<int, int>>(2, pair<int, int>()));
    vector<vector<pair<int, int>>> rc2(4, vector<pair<int, int>>(2, pair<int, int>()));

    rc1[0][0] = pair<int,int>(ax1, ay1);
    rc1[0][1] = pair<int,int>(ax1, ay2);
    rc1[1][0] = pair<int,int>(ax1, ay1);
    rc1[1][1] = pair<int,int>(ax2, ay1);
    rc1[2][0] = pair<int,int>(ax1, ay2);
    rc1[2][1] = pair<int,int>(ax2, ay2);
    rc1[3][0] = pair<int,int>(ax2, ay1);
    rc1[3][1] = pair<int,int>(ax2, ay2);

    rc2[0][0] = pair<int,int>(bx1, by1);
    rc2[0][1] = pair<int,int>(bx1, by2);
    rc2[1][0] = pair<int,int>(bx1, by1);
    rc2[1][1] = pair<int,int>(bx2, by1);
    rc2[2][0] = pair<int,int>(bx1, by2);
    rc2[2][1] = pair<int,int>(bx2, by2);
    rc2[3][0] = pair<int,int>(bx2, by1);
    rc2[3][1] = pair<int,int>(bx2, by2);

    // Find the intersections by calling a helper function
    set<pair<int, int>> intersections;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            unordered_map<int, int> crossings = getIntersection(rc1[i][0].first, rc1[i][0].second, rc1[i][1].first, rc1[i][1].second, rc2[j][0].first, rc2[j][0].second, rc2[j][1].first, rc2[j][1].second);
            intersections.insert(crossings.begin(), crossings.end());
        }
    }

    bool first_dot = false;
    pair<int, int> dot;
    int length = 0;
    int height = 0;

    // Check the intersections and calculate the length and height of the overlap rectangle.
    for (set<pair<int, int>>::iterator it = intersections.begin(); it != intersections.end(); it++)
    {
        if (!first_dot)
        {
            dot = *it;
            first_dot = true;
            continue;
        }

        if (it->first == dot.first)
        {
            height = abs(it->second - dot.second);
        }
        else if (it->second == dot.second)
        {
            length = abs(it->first - dot.first);
        }
        else
        {
            height = abs(it->second - dot.second);
            length = abs(it->first - dot.first);
        }

        dot = *it;
    }

    // Handling when both intersection are in a line, draw a picture, it will help
    // understand it better.
    if (!height && length)
    {
        height = min(by2, ay2) - max(by1, ay1);
    }

    if (!length && height)
    {
        length = min(bx2, ax2) - max(bx1, ax1);
    }

    return (ax2-ax1)*(ay2-ay1) + (bx2-bx1)*(by2-by1) - length * height;
}

// Helper function that get intersection of two lines.
unordered_map<int, int> getIntersection(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2)
{
    unordered_map<int, int> intersections;

    // Don't search for the intersection if both lines are parallel.
    if (bx1 - ax1 == bx2 - ax2 ||
        by1 - ay1 == by2 - ay2)
    {
        return intersections;
    }

    // Put all the dots of line A in a set.
    set<pair<int, int>> dots;
    for (int i = ax1; i <= ax2; i++)
    {
        for (int j = ay1; j <= ay2; j++)
        {
            dots.insert(pair<int,int>(i, j));
        }
    }

    // Check if dots of line B also at line A
    for (int i = bx1; i <= bx2; i++)
    {
        for (int j = by1; j <= by2; j++)
        {
            if (dots.find(pair<int,int>(i, j)) != dots.end())
            {
                intersections[i] = j;
            }
        }
    }

    return intersections;
}