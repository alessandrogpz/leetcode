#include "functions.h"

std::vector<int> Solution::asteroidCollision(std::vector<int> &asteroids)
{
    std::vector<int> resultCollisions; // Will store surviving asteroids in order
    std::stack<int> stack_asteroid;

    // Push all asteroids onto the stack in reverse order.
    // This ensures that when we pop from the stack, we process asteroids from left to right.
    for (int i = asteroids.size() - 1; i >= 0; --i)
    {
        stack_asteroid.push(asteroids[i]);
    }

    // Process the asteroids until the stack is empty.
    while (!stack_asteroid.empty())
    {
        // If resultCollisions is empty, simply push the current asteroid.
        if (resultCollisions.empty())
        {
            resultCollisions.push_back(stack_asteroid.top());
            stack_asteroid.pop();
            continue;
        }

        int cur_elm_value = resultCollisions.back();
        int incoming = stack_asteroid.top();

        // If no collision is possible (either the incoming asteroid is moving right,
        // or the last surviving asteroid is moving left), then push the incoming asteroid.
        if (incoming > 0 || cur_elm_value < 0)
        {
            resultCollisions.push_back(incoming);
            stack_asteroid.pop();
        }
        else
        {
            // At this point, cur_elm_value is positive (moving right) and incoming is negative (moving left)
            // so a collision will occur.
            if (cur_elm_value > 0)
            {
                // The positive asteroid is larger so the negative asteroid is destroyed.
                if (std::abs(cur_elm_value) > std::abs(incoming))
                {
                    stack_asteroid.pop();
                }
                // Both are equal in size, so both explode.
                else if (std::abs(cur_elm_value) == std::abs(incoming))
                {
                    resultCollisions.pop_back();
                    stack_asteroid.pop();
                }
                // std::abs(cur_elm_value) < std::abs(incoming)
                // Remove all positive asteroids smaller than the incoming negative.
                else
                {
                    while (!resultCollisions.empty() && resultCollisions.back() > 0 &&
                           std::abs(resultCollisions.back()) < std::abs(incoming))
                    {
                        resultCollisions.pop_back();
                    }
                    // Now check: if there is a surviving positive asteroid
                    if (!resultCollisions.empty() && resultCollisions.back() > 0)
                    {
                        // Both explode.
                        if (std::abs(resultCollisions.back()) == std::abs(incoming))
                        {
                            resultCollisions.pop_back();
                        }
                        // Otherwise, the surviving positive is larger, so the negative asteroid is destroyed.
                        stack_asteroid.pop();
                    }
                    // No surviving positive in the result; push the negative asteroid.
                    else
                    {
                        resultCollisions.push_back(incoming);
                        stack_asteroid.pop();
                    }
                }
            }
        }
    }

    return resultCollisions;
}
