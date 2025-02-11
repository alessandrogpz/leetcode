# Asteroid Collision: Approach Explanation

## Problem Overview

Given an array `asteroids` where:

- Each element represents an asteroid.
- The **absolute value** of an element is its size.
- The **sign** of an element represents its direction:
  - **Positive**: moving to the right.
  - **Negative**: moving to the left.

When asteroids collide:

- The smaller one explodes.
- If they are of equal size, both explode.
- Asteroids moving in the same direction never collide.

Our goal is to determine the final state of the asteroids after all collisions have occurred.

## Data Structures

- **Vector (`resultCollisions`)**:  
  Stores the asteroids that survive after all collisions.

- **Stack (`stack_asteroid`)**:  
  Used to process the asteroids from left to right. The input vector is pushed onto the stack in reverse order, so that when we pop from the stack, we process asteroids in their original left-to-right order.

## Step-by-Step Algorithm

### 1. Initialization

- **Reverse the Order for Processing**:  
  Loop through the input array in reverse order and push each asteroid onto `stack_asteroid`.  
  This ensures that the first asteroid in the input will be the first one processed (when popped from the stack).

  ```cpp
  for (int i = asteroids.size() - 1; i >= 0; --i)
  {
      stack_asteroid.push(asteroids[i]);
  }
  ```

### 2. Processing Asteroids

- **Loop Until Stack is Empty**:  
  Continue processing until every asteroid has been handled.

- **Handling an Empty `resultCollisions`**:  
  If `resultCollisions` is empty, simply move the current asteroid from the stack to `resultCollisions`.

  ```cpp
  if (resultCollisions.empty())
  {
      resultCollisions.push_back(stack_asteroid.top());
      stack_asteroid.pop();
      continue;
  }
  ```

### 3. Collision Detection and Resolution

For each incoming asteroid (from `stack_asteroid.top()`), compare it with the last surviving asteroid in `resultCollisions` (denoted as `cur_elm_value`):

- **No Collision Cases**:

  - If the **incoming asteroid** is moving right (`incoming > 0`), it cannot collide with the asteroid on its left.
  - If the **last asteroid in `resultCollisions`** is moving left (`cur_elm_value < 0`), they will not meet.

  In both cases, the incoming asteroid is added to `resultCollisions`.

  ```cpp
  if (incoming > 0 || cur_elm_value < 0)
  {
      resultCollisions.push_back(incoming);
      stack_asteroid.pop();
  }
  ```

- **Collision Case**:
  When `cur_elm_value` (moving right) and `incoming` (moving left) are heading toward each other, a collision occurs:

  1. **Asteroid Sizes Comparison**:
     - **If the positive asteroid is larger**:

       - The incoming negative asteroid is destroyed.
       - Only remove the incoming asteroid from the stack.

       ```cpp
       if (std::abs(cur_elm_value) > std::abs(incoming))
       {
           stack_asteroid.pop();
       }
       ```

     - **If both asteroids are equal in size**:

       - Both asteroids are destroyed.
       - Remove the positive asteroid from `resultCollisions` and the negative from the stack.

       ```cpp
       else if (std::abs(cur_elm_value) == std::abs(incoming))
       {
           resultCollisions.pop_back();
           stack_asteroid.pop();
       }
       ```

     - **If the negative asteroid is larger**:

       - Remove the positive asteroid from `resultCollisions` as long as it is smaller than the incoming asteroid.
       - Continue checking with previous surviving asteroids in `resultCollisions` because the incoming asteroid may collide with multiple asteroids.
       - If a collision with an equal-sized asteroid occurs later, both are destroyed.
       - If no surviving positive asteroid remains to block the incoming negative, add the negative asteroid to `resultCollisions`.

       ```cpp
       else
       {
           while (!resultCollisions.empty() && resultCollisions.back() > 0 &&
                  std::abs(resultCollisions.back()) < std::abs(incoming))
           {
               resultCollisions.pop_back();
           }
           if (!resultCollisions.empty() && resultCollisions.back() > 0)
           {
               if (std::abs(resultCollisions.back()) == std::abs(incoming))
               {
                   resultCollisions.pop_back();
               }
               else
               {
                   stack_asteroid.pop();
               }
           }
           else
           {
               resultCollisions.push_back(incoming);
               stack_asteroid.pop();
           }
       }
       ```

### 4. Final Output

After processing all asteroids, `resultCollisions` contains the final state of the asteroids that survived the collisions. This vector is then returned as the output.

## Complexity Analysis

- **Time Complexity**:  
  O(n), where _n_ is the number of asteroids.  
  Each asteroid is processed at most once, and although collisions may cause repeated comparisons, each asteroid is pushed and popped at most once from the vector/stack.

- **Space Complexity**:  
  O(n) due to the additional space used by the stack and the `resultCollisions` vector.

## Summary

The solution simulates the asteroid collisions using a stack to maintain the correct order of processing and a vector to record surviving asteroids. By handling different collision scenarios (no collision, one asteroid exploding, or mutual destruction), the algorithm efficiently computes the final state of the asteroids as per the problem's requirements.

---
