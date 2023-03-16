#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

#define endl "\n"
#define ll long long
#define ld long double
#define ull unsigned long long
#define  pi  acos(-1)

const ll mod = 1000000007;
const ld EPS = 1e-9;
const int N = 2e5 + 9;

//          U   R  D  L
int dx[] = {-1, 0, 1, 0, -1, +1, +1, -1}; // dx for the 8 adjacent places in matrix
int dy[] = {0, 1, 0, -1, +1, +1, -1, -1};// dy for the 8 adjacent places in matrix

typedef tree<
        int,
        null_type,
        less<int>,
        rb_tree_tag,
        tree_order_statistics_node_update>
        ordered_set;

class MinHeap {
public:
    vector<int> heap;

    MinHeap() {

    }

    void push(int val) {
        heap.push_back(val);
        heapifyUP(heap.size() - 1);
    }

    void heapifyUP(int indx) {
        if (indx == 0 || heap[parent(indx)] < heap[indx])return;

        swap(heap[indx], heap[parent(indx)]);
        heapifyUP(parent(indx));

    }

    void heapifyDown(int indx) {

        if (leftChild(indx) == -1)
            return;

        int mini = leftChild(indx);

        if (rightChild(indx) != -1 && heap[mini] > heap[rightChild(indx)])
            mini = rightChild(indx);

        if (heap[indx] > heap[mini]) {
            swap(heap[indx], heap[mini]);
            heapifyDown(mini);
        }


    }

    void pop() {
        heap[0] = heap[heap.size() - 1];
        heap.pop_back();
        heapifyDown(0);
    }

    int leftChild(int indx) {
        int l = 2 * indx + 1;
        if (l >= heap.size())return -1;
        return l;
    }

    int rightChild(int indx) {
        int r = 2 * indx + 2;
        if (r >= heap.size())
            return -1;
        return r;
    }

    int parent(int indx) {
        return (indx - 1) / 2;
    }

    int top() {
        return heap.front();
    }

};

int main() {


    MinHeap m;

    m.push(7);
    m.push(5);
    m.push(6);
    m.push(-1);

    cout << m.top() << endl;
    m.pop();
    cout << m.top() << endl;
    m.pop();
    cout << m.top() << endl;
}
