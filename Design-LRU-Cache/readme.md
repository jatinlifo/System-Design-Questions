## Problem statement
Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.

Implement the LRUCache class:

LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
int get(int key) Return the value of the key if the key exists, otherwise return -1.
void put(int key, int value) Update the value of the key if the key exists. Otherwise, add the key-value pair to the cache. If the number of keys exceeds the capacity from this operation, evict the least recently used key.
The functions get and put must each run in O(1) average time complexity.

 

Example 1:

Input
["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
[[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
Output
[null, null, null, 1, null, -1, null, -1, 3, 4]

Explanation
LRUCache lRUCache = new LRUCache(2);
lRUCache.put(1, 1); // cache is {1=1}
lRUCache.put(2, 2); // cache is {1=1, 2=2}
lRUCache.get(1);    // return 1
lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
lRUCache.get(2);    // returns -1 (not found)
lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
lRUCache.get(1);    // return -1 (not found)
lRUCache.get(3);    // return 3
lRUCache.get(4);    // return 4
 

Constraints:

1 <= capacity <= 3000
0 <= key <= 104
0 <= value <= 105
At most 2 * 105 calls will be made to get and put.

## Approach 1 Brute Force

```
# Requirements 
1. We need to data structure where store our data as a key value
2. Maybe array is good to store key value and also another Data Structure is good like Hash Map , stack, 
but the problem is how to handle LRU condition.
3. Array (vector) is good to store least recent data store in back side and get easily.
4. We would use vector<pair<int, int>>  store {key, value}

T.C O(n ^ n)
S.C O(n)
```

## Approach 2 Optimal 

```
# Requirements
1. We need to like data structure provide a ability to easy delete any position and easy insert in last position
2. We would use Linked List because Linked List provide O(1) inseration at last position and O(1) delete any position 
but you know already where my node position
3. Imagine you are deleting any node so you need to know about what is my previous node because i have to join the link 
next node and remove current node.
4. We would use Doubly Linked List to store the information previous node and next node.
5. We would use HashMap to store every key because we may phase a lookup problem imagine you want to get a value for corresponding
a middle node then you need to traverese whole list and check if node.key == key this is problem.
6. We would use Hash Map store key -> node lookup time is O(1).

T.C O(1) 
S.C O(n) n is the number of key value pair
```