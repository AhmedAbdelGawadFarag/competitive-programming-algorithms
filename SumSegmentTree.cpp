#include <bits/stdc++.h>
using namespace std;

class segmentTree
{
public:
    int size;

    vector<long long> sums;

    segmentTree(int n)
    {
        size = 1;
        while (size < n)
            size *= 2;

        sums.resize(size * 2, 0);
    }

    void build(vector<long long> &v, int x, int sl, int sr)
    { // build in o(n)
        if (sl == sr)
        {
            if (sl < v.size()) // ensure that we are in the range of vector
                sums[x] = v[sl];
            return;
        }
        int mid = (sl + sr) / 2;

        build(v, 2 * x + 1, sl, mid);
        build(v, 2 * x + 2, mid + 1, sr);

        sums[x] = sums[2 * x + 1] + sums[2 * x + 2];
    }

    void set(int i, int v, int x, int sl, int sr)
    { //set index with value o(log n)
        if (sr == sl)
        {
            sums[x] = v;
            return;
        }
        int mid = (sr + sl) / 2;
        if (i <= mid)
        { //left
            set(i, v, 2 * x + 1, sl, mid);
        }
        else
        {
            set(i, v, 2 * x + 2, mid + 1, sr);
        }
        sums[x] = sums[2 * x + 1] + sums[2 * x + 2];
        return;
    }

    void build(vector<long long> &v)
    {
        build(v, 0, 0, size - 1);
    }

    void set(int i, int v)
    {
        set(i, v, 0, 0, size - 1);
    }

    long long sum(int l, int r, int x, int sl, int sr)
    { // sum of range of numbers
        if (r < sl || l > sr)
            return 0;
        if (l <= sl && r >= sr)
            return sums[x];

        int mid = (sl + sr) / 2;

        return sum(l, r, 2 * x + 1, sl, mid) + sum(l, r, 2 * x + 2, mid + 1, sr);
    }

    long long sum(int l, int r)
    {
        return sum(l, r, 0, 0, size - 1);
    }
};

int main()
{
    int n;
    cin >> n;
    segmentTree st(n);

    vector<long long> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    st.build(v);

    cout << st.sum(0, n - 1);
}
