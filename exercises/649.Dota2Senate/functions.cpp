
#include "functions.h"

std::string Solution::predictPartyVictory(std::string senate)
{
    std::queue<int> q_r;
    std::queue<int> q_d;
    int n = senate.size() - 1;

    for (int i = 0; i < senate.size(); ++i)
    {
        if (senate[i] == 'D')
        {
            q_d.push(i);
        }
        else
        {
            q_r.push(i);
        }
    }

    while (!q_r.empty() && !q_d.empty())
    {

        if (q_d.front() < q_r.front())
        {
            n++;
            q_d.push(q_d.front() + n);
            q_d.pop();
            q_r.pop();
        }

        else if (q_d.front() > q_r.front())
        {
            n++;
            q_r.push(q_r.front() + n);
            q_r.pop();
            q_d.pop();
        }
    }

    return q_r.empty() ? "Dire" : "Radiant";
}