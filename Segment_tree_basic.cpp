
#include <bits/stdc++.h>
#include <vector>
using namespace std;

vector<int> v;
vector<int> segtree;

void build_seg_tree(int node, int b, int e)
{
    if (b == e)
    {
        segtree[node] = v[b];
        return;
    }
    int Left = node * 2 + 1;
    int Right = node * 2 + 2;
    int mid = (b + e) / 2;
    build_seg_tree(Left, b, mid);
    build_seg_tree(Right, mid + 1, e);
    segtree[node] = segtree[Left] + segtree[Right];
}
int query(int node, int b, int e, int i, int j)
{
    if (b > j || e < i)
        return 0;
    if (b >= i && e <= j)
        return segtree[node];
    int Left = node * 2 + 1;
    int Right = node * 2 + 2;
    int mid = (b + e) / 2;
    int p1 = query(Left, b, mid, i, j);
    int p2 = query(Right, mid + 1, e, i, j);
    return p1 + p2;
}
void update(int node, int b, int e, int idx, int newvalue)
{
    if (b > idx || e < idx)
        return;
    if (b >= idx && e <= idx)
    {
        segtree[node] = newvalue;
        return;
    }
    int Left = node * 2 + 1;
    int Right = node * 2 + 2;
    int mid = (b + e) / 2;
    if (idx <= mid)
    {
        update(Left, b, mid, idx, newvalue);
    }
    else
    {
        update(Right, mid + 1, e, idx, newvalue);
    }
    segtree[node] = segtree[Left] + segtree[Right];
}

int main()
{
    int n;
    cin >> n;
    v.resize(n);
    int size = 2 * pow(2, ceil(log2(n))) - 1;
    segtree.resize(size);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    build_seg_tree(0, 0, n - 1);
    cout << "sum of the given range is: " << query(0, 0, n - 1, 1, 3) << "\n";
    update(0, 0, n, 3, 10);
    cout << "After update new value, new sum of the given range is: " << query(0, 0, n - 1, 1, 3) << "\n";
}