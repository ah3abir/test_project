# test_project


# Queue

## Array based Queue

>`main.cpp`
```cpp=
#include <bits/stdc++.h>
#define SIZE 5
using namespace std ;
int A[SIZE];
int front = -1, rear = -1;

bool isEmpty() {
    return (rear == -1 && front == -1);
}

bool isFull() {
    return (front == ((rear + 1) % SIZE));
}

```
