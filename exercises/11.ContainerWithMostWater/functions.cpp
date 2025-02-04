
#include "functions.h"

int Solution::maxArea(std::vector<int> &height)
{
    int L_POS = 0;
    int R_POS = height.size() - 1;

    int MAX_VOLUME = 0;
    int CURRENT_VOLUME = 0;

    while (L_POS < R_POS)
    {
        int L_HEIGHT = height[L_POS];
        int R_HEIGHT = height[R_POS];

        if (L_HEIGHT < R_HEIGHT)
        {
            CURRENT_VOLUME = L_HEIGHT * (R_POS - L_POS);
            L_POS++;
        }
        else
        {
            CURRENT_VOLUME = R_HEIGHT * (R_POS - L_POS);
            R_POS--;
        }

        if (MAX_VOLUME < CURRENT_VOLUME)
            MAX_VOLUME = CURRENT_VOLUME;
    }

    return MAX_VOLUME;
}