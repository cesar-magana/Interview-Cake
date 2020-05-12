# Binary Search Tree

A **binary search tree** is a binary [tree](https://www.interviewcake.com/concept/tree) where the nodes are ordered in a specific way. For every node:

- The nodes to the left are *smaller* than the current node.
- The nodes to the right are *larger* than the current node.

Checking if a binary tree is a binary *search* tree is [a favorite question from interviews](https://www.interviewcake.com/question/bst-checker).

![A binary search tree with nodes containing integers. The root node contains the integer 50. Each child node to the left of the root contains integers less than 50, and each child node to the right of the root contains integers greater than 50.](https://www.interviewcake.com/images/svgs/bst__binary_search_tree.svg?bust=205)

#### Strengths:

- **Good performance across the board.** Assuming they're [balanced](https://www.interviewcake.com/concept/tree#balanced), binary search trees are good at lots of operations, even if they're not constant time for anything.
  - Compared to a sorted [array](https://www.interviewcake.com/concept/array), lookups take the same amount of time (**O(lg(n))\*O\*(\*l\**g\*(\*n\*))**), but inserts and deletes are faster (**O(lg(n))\*O\*(\*l\**g\*(\*n\*))** for BSTs, **O(n)\*O\*(\*n\*)** for arrays).
  - Compared to [unordered maps](https://www.interviewcake.com/concept/hash-map), BSTs have better *worst case* performance—**O(lg(n))\*O\*(\*l\**g\*(\*n\*))** instead of **O(n)\*O\*(\*n\*)**. *But*, on average unordered maps perform better than BSTs (meaning **O(1)\*O\*(1)** time complexity).
- **BSTs are sorted.** Taking a binary search tree and pulling out all of the elements in sorted order can be done in **O(n)\*O\*(\*n\*)** using an in-order traversal. Finding the element *closest* to a value can be done in **O(lg(n))\*O\*(\*l\**g\*(\*n\*))** (again, if the BST is balanced!).

#### Weaknesses:

- **Poor performance if unbalanced.** Some types of binary search trees balance automatically, but not all. If a BST is not balanced, then operations become **O(n)\*O\*(\*n\*)**.
- **No \**O(1)\*O\*(1)\** operations.** BSTs aren't the *fastest* for anything. On average, [a vector](https://www.interviewcake.com/concept/array) or [an unordered map](https://www.interviewcake.com/concept/hash-map) will be faster.

## Balanced Binary Search Trees

Two binary search trees can store the same values in different ways:

![Two binary search trees: the one on the left is balanced and the one on the right is unbalanced. Both contain the same values: the integers 1 through 6.](https://www.interviewcake.com/images/svgs/bst__balanced_non_balanced.svg?bust=205)

Some trees (like AVL trees or Red-Black trees) rearrange nodes as they're inserted to ensure the tree is always balanced. With these, the worst case complexity for searching, inserting, or deleting is *always* **O(lg(n))\*O\*(\*l\**g\*(\*n\*))**, not **O(n)\*O\*(\*n\*)**.