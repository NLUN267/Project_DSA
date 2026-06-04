// Ví dụ main.cpp để test
#include <iostream>
#include "LinkedList.hpp"
#include "Stack.hpp"
#include "Queue.hpp"
#include "PriorityQueue.hpp"
#include "Algorithms.hpp"
#include "BST.hpp"
#include "AVL.hpp"
#include "HashTable.hpp"

using namespace std;

int main() {
    LinkedList<int> list;
    list.insertBack(10);
    list.insertBack(20);
    list.insertFront(5);

    list.printForward();

    Stack<int> st;
    st.push(1);
    st.push(2);

    cout << st.pop() << endl;

    Queue<int> q;
    q.enqueue(100);
    q.enqueue(200);

    cout << q.dequeue() << endl;

    int arr[] = {5, 1, 4, 2, 8};

    bubbleSort(arr, 5);

    for (int i = 0; i < 5; i++)
        cout << arr[i] << " ";

    cout << endl;

    BST<int> bst;
    bst.insert(50);
    bst.insert(30);
    bst.insert(70);

    bst.inorder();

    AVL<int> avl;
    avl.insert(10);
    avl.insert(20);
    avl.insert(30);

    HashTable<string, int> table;
    table.insert("Alice", 100);

    cout << table.contains("Alice") << endl;

    return 0;
}


/*# README.md mẫu

```md
# DSA Template Library

## Compile

g++ app/main.cpp -o main

## Run

./main
```

---

# Lưu ý quan trọng( chat gpt đề xuất)

1. KHÔNG tách template ra file `.cpp`.
2. Tất cả implementation phải nằm trong `.hpp`.
3. Có comment/chú thích ngắn cho mỗi hàm.
4. Sorting phải có comparator.
5. HashTable phải dùng AVL chaining đúng như đề.
6. Thư viện và app phải tách thư mục riêng.
7. Nên thêm Makefile để chuyên nghiệp hơn.*/
