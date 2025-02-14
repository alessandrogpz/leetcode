## Problem Recap

In the Dota2 Senate:

- Each senator belongs to one of two parties: Radiant (`'R'`) or Dire (`'D'`).
- In each round, every senator who still has voting rights takes a turn in the order of the input string.
- During a turn, a senator can **ban** one senator from the opposite party (removing their right to vote in the current and future rounds).
- The process continues in rounds until all remaining senators belong to one party.
- Each senator plays optimally to ensure their own party wins.

Our goal is to simulate this process and determine the winning party.

---

## Key Concepts

1. **Queues for Each Party**:  
   We maintain two queues:

   - **Radiant Queue (`q_r`)**: Holds the indices of Radiant senators.
   - **Dire Queue (`q_d`)**: Holds the indices of Dire senators.

2. **Simulating Rounds with Indices**:

   - The senators are processed in the order they appear.
   - The senator with the **smaller index** (i.e., the one who appears earlier) gets to ban a senator from the opposite party.
   - After banning, the winning senator is rescheduled to vote in a future round by adding them back to their queue with an updated index.

3. **Index Update Mechanism**:
   - The idea is to simulate the cyclic nature of the rounds.
   - When a senator wins a turn, they are re-added with an index that ensures they will vote after all currently waiting senators.
   - This is done by adding an offset (based on the current length of the senate) to their current index.
   - In the provided solution, a variable `n` (initialized as `senate.size() - 1`) is incremented each time a senator wins a round. The winning senator is then reinserted with the new index (`current index + n`), effectively placing them at the back of the queue.

---

## Detailed Step-by-Step Approach

1. **Initialization**:

   - Create two queues: one for Radiant senators (`q_r`) and one for Dire senators (`q_d`).
   - Iterate over the input string `senate` and:
     - If the senator is `'R'`, push their index into `q_r`.
     - If the senator is `'D'`, push their index into `q_d`.
   - Initialize an integer `n` to `senate.size() - 1`. This value serves as a base offset that is updated (incremented) each time a senator wins a round, ensuring they re-enter the voting order appropriately.

2. **Processing the Rounds**:

   - **Loop Condition**: Continue the simulation as long as **both** queues are non-empty.
   - In each iteration:

     - Compare the front indices of `q_r` and `q_d`.
     - **Case 1**: If `q_d.front() < q_r.front()`:
       - The Dire senator at the front gets to ban the Radiant senator.
       - Increment `n` by 1.
       - Reinsert the winning Dire senator by pushing `q_d.front() + n` into `q_d`.
       - Pop the front element from both `q_d` (the acting senator, who has now been rescheduled) and `q_r` (the banned Radiant senator).
     - **Case 2**: If `q_r.front() < q_d.front()`:
       - The Radiant senator bans the Dire senator.
       - Increment `n` by 1.
       - Reinsert the winning Radiant senator by pushing `q_r.front() + n` into `q_r`.
       - Pop the front element from both `q_r` (the acting senator) and `q_d` (the banned senator).

   - **Rationale**:  
     The senator with the smaller index gets the chance to act first in the round. After acting, they are scheduled to vote again in a future round by receiving a new index that is guaranteed to be larger than the current indices, preserving the round order.

3. **Determining the Winner**:
   - The simulation stops when one of the queues becomes empty.
   - If `q_r` is empty, then all Radiant senators have been banned and the Dire party wins.
   - If `q_d` is empty, then all Dire senators have been banned and the Radiant party wins.
   - The function returns `"Dire"` if `q_r` is empty; otherwise, it returns `"Radiant"`.

---

## Example Walkthrough

Consider the input: `"RDD"`

1. **Initialization**:

   - `q_r`: Contains index `[0]` (for 'R').
   - `q_d`: Contains indices `[1, 2]` (for 'D').
   - `n` is initialized to `senate.size() - 1`, i.e., `2`.

2. **First Iteration**:

   - Compare `q_r.front()` = `0` with `q_d.front()` = `1`.
   - Since `0 < 1`, the Radiant senator at index `0` bans the Dire senator at index `1`.
   - Increment `n` to `3`.
   - Reinsert the Radiant senator with updated index: push `0 + 3 = 3` into `q_r`.
   - Remove the banned Dire senator (pop from `q_d`) and remove the acting Radiant senator (pop from `q_r`).
   - Queues after iteration:
     - `q_r`: `[3]`
     - `q_d`: `[2]`

3. **Second Iteration**:

   - Compare `q_r.front()` = `3` with `q_d.front()` = `2`.
   - Since `2 < 3`, the Dire senator at index `2` bans the Radiant senator at index `3`.
   - Increment `n` to `4`.
   - Reinsert the Dire senator with updated index: push `2 + 4 = 6` into `q_d`.
   - Remove the banned Radiant senator (pop from `q_r`) and remove the acting Dire senator (pop from `q_d`).
   - Queues after iteration:
     - `q_r`: `[]`
     - `q_d`: `[6]`

4. **Termination**:
   - The loop ends because `q_r` is empty.
   - Since the Radiant queue is empty, the final winner is Dire.

---

## Complexity Analysis

- **Time Complexity**:  
  Each senator is processed and reinserted into a queue until one party is eliminated. In practice, the simulation runs in **O(n)** time, where `n` is the number of senators.

- **Space Complexity**:  
  Two queues are used, and in the worst-case scenario, they store up to **O(n)** indices. Therefore, the space complexity is **O(n)**.

---

## Summary

- **Two Queues**: Used to separately track the indices of Radiant and Dire senators.
- **Cyclic Simulation**: By comparing indices and reinserting winning senators with an updated index, we simulate the cyclic nature of rounds.
- **Optimal Moves**: The senator with the earlier turn bans an opponent and gets rescheduled for future rounds.
- **Winning Condition**: The simulation stops when one of the queues is empty, indicating that all senators from that party have been banned.

This approach efficiently determines the winning party by simulating the banning process and managing the cyclic order of turns through clever index updates.

```

```
