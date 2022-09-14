
* [link](https://github.com/tan405/test_project/blob/main/Folder01/readmee.md)
### Linear Search
>`linearSearch.cpp`

```cpp=
#include<iostream>
using namespace std;

int linearSearch(int *arr, int n, int key) {
    for(int i=0; i<n; i++) {
        if(*(arr+i) == key) {
            return i;
        }
    }
    return -1;
}
```
