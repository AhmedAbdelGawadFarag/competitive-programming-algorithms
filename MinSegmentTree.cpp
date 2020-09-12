#include <bits/stdc++.h>
using namespace std;

class segmentTree
{
public:
    int size;

    vector<long long> minis;

    segmentTree(int n)
    {
        size = 1;
        while (size < n)
            size *= 2;

        minis.resize(size * 2, 0);
    }

    void build(vector<long long> &v, int x, int sl, int sr)
    { // build in o(n)
        if (sl == sr)
        {
            if (sl < v.size()) // ensure that we are in the range of vector
                minis[x] = v[sl];
            return;
        }
        int mid = (sl + sr) / 2;

        build(v, 2 * x + 1, sl, mid);
        build(v, 2 * x + 2, mid + 1, sr);

        minis[x] = min(minis[2 * x + 1], minis[2 * x + 2]);
    }

    void set(int i, int v, int x, int sl, int sr)
    { //set index with value o(log n)
        if (sr == sl)
        {
            minis[x] = v;
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
        minis[x] = min(minis[2 * x + 1], minis[2 * x + 2]);
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

    long long getMin(int l, int r, int x, int sl, int sr)
    { // sum of range of numbers
        if (r < sl || l > sr)
            return INT_MAX;
        if (l <= sl && r >= sr)
            return minis[x];

        int mid = (sl + sr) / 2;

        return min(getMin(l, r, 2 * x + 1, sl, mid), getMin(l, r, 2 * x + 2, mid + 1, sr));
    }

    long long getMin(int l, int r)
    {
        return getMin(l, r, 0, 0, size - 1);
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

    cout << st.getMin(0, 1);
}