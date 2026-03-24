*This project has been created as part of the 42 curriculum by cchaudeu.*

# push_swap

## Description

push_swap is a sorting algorithm project from the 42 curriculum. The goal is to sort a stack of integers using two stacks (A and B) and a limited set of operations, while minimizing the total number of moves.

The allowed operations are:

- `sa` / `sb` / `ss` — swap the top two elements of stack A / B / both
- `pa` / `pb` — push the top element of one stack onto the other
- `ra` / `rb` / `rr` — rotate stack A / B / both upward (top becomes bottom)
- `rra` / `rrb` / `rrr` — reverse rotate stack A / B / both (bottom becomes top)

The project also includes a **checker** program that reads a list of operations from stdin and verifies whether they correctly sort the stack.

### Performance

| Input size | Average move count |
|---|---|
| 100 numbers | ~420 moves |
| 500 numbers | ~3130 moves |

---

## Algorithm Overview

### Data Structures

Rather than using linked lists, both stacks are implemented as **circular arrays of integers**. This allows O(1) index-based access to any element at any position, making binary search and cost calculations significantly faster.

### Step-by-step

1. **Indexing** — All numbers are bubble sorted into an array to assign each one a rank from 0 to N-1. All subsequent logic works with these indices rather than the original values.

2. **Copy to stack A** — The indexed values are copied into stack A in their original order.

3. **Find the absolute LIS** — The algorithm searches for the longest increasing subsequence (LIS) across all possible rotations of stack A. For example, for the sequence `5 6 1 0 2 3 4`, the absolute LIS is `0 2 3 4 5 6` (length 6, with the head at index 3), rather than just `0 2 3 4` (length 4) if only the default orientation were considered.

4. **Optional swap** — Stack A is swapped (`sa`) and the absolute LIS search is repeated. If the new LIS length is strictly greater, the swap is kept. Otherwise, a second `sa` is issued to revert to the initial order (in that case, these two operations cancel each other during the final optimization pass and do not count toward the move total).

5. **Flag LIS elements** — The actual numbers belonging to the LIS are identified and flagged. They will remain in stack A throughout the algorithm.

6. **Fill stack B** — Non-LIS numbers are pushed to stack B, with a pre-sorting step: numbers in the lower half of the value range are rotated to the bottom of B, while numbers in the upper half stay at the top. At each step, before pushing to B, the algorithm checks whether the top or bottom of B can be cheaply re-inserted directly into its correct position in A (in 1 or 2 moves). This reduces the work needed in the next phase.

7. **Empty stack B into A** — Each number in B is inserted into its correct position in A. At every step, a cost calculation is performed over the elements of B to find the cheapest one to push. The cost accounts for:
   - The number of rotations needed to bring the B element to the top of B
   - The number of rotations needed to bring its target position to the top of A
   - Combined `rr` / `rrr` moves when both stacks need to rotate in the same direction
   - Alternative rotation directions (rotating the other way around the circular buffer) when they reduce the total

8. **Final rotation of A** — Once all numbers are back in A, the stack is rotated (or reverse-rotated, whichever is cheaper) to bring the smallest element to the top.

9. **Move list optimization** — The full move list is post-processed to cancel and simplify redundant operations:
   - `sa` + `sa` & `sb` + `sb` → cancelled
   - `ra` + `rra` & `rb` + `rrb` → cancelled
   - `pa` + `pb` → cancelled
   - `ra` + `pa` + `rra` → `pa` + `sa`

---

## Instructions

### Compilation

```bash
make        # builds push_swap
make bonus  # builds checker
make clean  # removes object files
make fclean # removes object files and binaries
make re     # fclean + make
```

### Usage

```bash
# Sort a list of integers
./push_swap 5 3 1 4 2

# Verify the output with the checker
ARG="5 3 1 4 2"; ./push_swap $ARG | ./checker $ARG

# Count the number of moves
ARG="5 3 1 4 2"; ./push_swap $ARG | wc -l
```

The checker prints `OK` if the sequence of moves correctly sorts the stack, and `KO` otherwise.

---

## Resources

### References

- [Push Swap — The Least Amount of Moves with Two Stacks](https://medium.com/@jamierobertdawson/push-swap-the-least-amount-of-moves-with-two-stacks-d1e76a71789a) — Overview of cost-based sorting strategies
- [My Implementation of the 42 Push Swap Project](https://medium.com/@dansylvain84/my-implementation-of-the-42-push-swap-project-2706fd8c2e9f) — Walkthrough of a complete implementation
- [Push Swap in Less Than 4200 Operations](https://medium.com/@ulysse.gks/push-swap-in-less-than-4200-operations-c292f034f6c0) — Optimization techniques
- [Longest Increasing Subsequence | Binary Search | Intuition](https://www.youtube.com/watch?v=on2hvxBXJH4) — Clear explanation of the patience sorting approach to LIS
- [Longest Increasing Subsequence (Dynamic Programming) ](https://www.youtube.com/watch?v=E6us4nmXTHs) — Video walkthrough

### Use of AI

Claude (claude.ai) was used throughout this project for:

- **Debugging** — Identifying bugs in C code, including issues with binary search logic, circular buffer indexing, and GNL edge cases.
- **Concept clarification** — Explaining and discussing general computer science concepts used in the project, including the Longest Increasing Subsequence, circular buffers/arrays, dynamic programming, and binary search on rotated sorted arrays.
- **Writing this README.**
