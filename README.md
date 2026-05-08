# Push_Swap

*This project has been created as part of the 42 curriculum by bkusi-fr, ecakiray .*

## Description
The **Push_Swap** project is a challenge focused on sorting data on a stack with a limited set of instructions and the smallest number of moves possible. The goal is to manipulate two stacks ($A$ and $B$) to sort a random sequence of integers. This implementation is optimized to meet the strict efficiency benchmarks for **100** and **500** elements required by the 42 curriculum[cite: 1].

## Instructions

### Compilation
The project is written in C. To compile the source code, run the following command in the root directory:
```bash
make
```

### Execution
Run the program by passing the desired algorithm flag followed by a list of integers. If no flag is provided, the program defaults to the most efficient algorithm for the input size.

```bash
# To use Selection Sort (O(n^2))
./push_swap --simple 3 2 5 1 4

# To use Chunk Sort (O(n√n))
./push_swap --medium 3 2 5 1 4

# To use Radix Sort (O(n log n))
./push_swap --complex 3 2 5 1 4
```

### Operations
*   `pa`, `pb`: Push the top element from one stack to the other.
*   `sa`, `sb`, `ss`: Swap the first two elements.
*   `ra`, `rb`, `rr`: Rotate the stack up.
*   `rra`, `rrb`, `rrr`: Reverse rotate the stack down.

## Algorithm Explanation and Justification
This project implements three distinct algorithms to handle different dataset sizes and complexity requirements:

### 1. Selection Sort ($O(n^2)$) — `--simple`
*   **Logic:** The algorithm searches for the smallest remaining number in Stack A and pushes it to Stack B. Once Stack A is empty, it pushes everything back.[cite: 1]
*   **Justification:** This serves as the foundational $n^2$ logic for the project and is used primarily for very small stacks ($n < 10$) where the overhead of complex algorithms is unnecessary.

### 2. Chunk Sort ($O(n\sqrt{n})$) — `--medium`
*   **Logic:** The stack is divided into "chunks" based on the sorted index of the numbers. Elements within a sliding window are pushed to Stack B using proximity-based rotation logic.[cite: 1]
*   **Justification:** This is the primary choice for passing the 100 and 500 element tests. It utilizes bidirectional rotations (`ra`/`rra`) to keep operation counts low.

### 3. Radix Sort ($O(n \cdot \text{bits})$) — `--complex`
*   **Logic:** A non-comparative algorithm that sorts numbers bit by bit using binary representation. Each bit serves as a pass to partition the stack into Stack B and back.[cite: 1]
*   **Justification:** Radix provides a highly reliable $n \log n$ complexity. It is ideal for large datasets where a deterministic operation count is required.

## Resources
*   **42 Project Documentation:** Provided subject PDF and evaluation scale[cite: 1].
*   **Algorithm Theory:** Documentation on bitwise operations and sliding window logic.
*   **Visualizer:** [Push_Swap Visualizer](https://github.com/o-m-i-d/Push_Swap_Visualizer) used for debugging stack movements.

### AI Usage
AI was utilized in this project for the following tasks:
*   **Logic Clarification:** AI was used to explain the movement of elements in a two-stack system for the Chunking algorithm.
*   **README Drafting:** Assisted in structuring this document according to the 42 curriculum's mandatory formatting rules.
*   **Technical Explanations:** Used to simplify the explanation of bitwise manipulation for the Radix implementation.