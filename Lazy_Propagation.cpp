//Segment tree with range of update under same value...
#include <bits/stdc++.h>
using namespace std;
vector<int> v, segtree, lazytree;
void build_st(int node, int b, int e)
{
    if (b == e)
    {
        segtree[node] = v[e];
        return;
    }
    int mid = (b + e) / 2, left = 2 * node + 1, right = 2 * node + 2;
    build_st(left, b, mid);
    build_st(right, mid + 1, e);
    segtree[node] = (segtree[left] + segtree[right]);
}
int query(int node, int b, int e, int i, int j)
{
    if (b > j || e < i)
        return 0;
    if (b >= i && e <= j)
    {
        return segtree[node];
    }
    int mid = (b + e) / 2, left = 2 * node + 1, right = 2 * node + 2;
    int p1 = query(left, b, mid, i, j);
    int p2 = query(right, mid + 1, e, i, j);
    return (p1 + p2);
}
void update(int node, int b, int e, int l, int r, int newval)
{
    if (lazytree[node] != 0)
    {
        segtree[node] += (e - b + 1) * lazytree[node];
        if (b != e)
        {
            lazytree[2 * node + 1] += newval;
            lazytree[2 * node + 1] += newval;
        }
        lazytree[node] = 0;
    }

    if (b > r || e < l || l > r)
        return;
    if (b >= l && e <= r)
    {
        segtree[node] += (e - b + 1) * newval;
        if (b != e)
        {
            lazytree[2 * node + 1] += newval;
            lazytree[2 * node + 2] += newval;
        }
        return;
    }
    int mid = (b + e) / 2, left = 2 * node + 1, right = 2 * node + 2;

    update(left, b, mid, l, r, newval);
    update(right, mid + 1, e, l, r, newval);

    segtree[node] = (segtree[left] + segtree[right]);
}
int main()
{
    int n;
    cin >> n;
    v.resize(n);
    segtree.resize(4 * n);
    lazytree.resize(4 * n, 0);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    build_st(0, 0, n - 1);
    cout << "sum of the given range is: " << query(0, 0, n - 1, 1, 4) << "\n";
    update(0, 0, n - 1, 1, 4, 2);
    cout << "After update new value, new sum of the given range is: " << query(0, 0, n - 1, 1, 4) << "\n";
}