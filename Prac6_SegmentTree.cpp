#include<iostream>
#include<cmath>
using namespace std;


int *SegmentTree;

void update(int i, int x, int *SegmentTree, int N, int low=0, int high=-1, int node=0) {
	if (high == -1) high = N - 1;
	if (high < i || low > i) return;
	if (low == high) { SegmentTree[node] += x; return; }
	int mid = (low + high) / 2;
	update(i, x, SegmentTree, N, low, mid, 2 * node + 1);
	update(i, x, SegmentTree, N, mid + 1, high, 2 * node + 2);
	SegmentTree[node] = SegmentTree[2 * node + 1] + SegmentTree[2 * node + 2];
}

int query(int s, int e, int *SegmentTree, int N, int low=0, int high=-1, int node=0) {
	if (high == -1) high = N - 1;
	if (high < s || low > e) return 0;
	if (low >= s && high <= e) return SegmentTree[node];
	int mid = (low + high) / 2;
	return query(s, e, SegmentTree, N, low, mid, 2 * node + 1) + 
			query(s, e, SegmentTree, N, mid + 1, high, 2 * node + 2);
}

int main() {
    int N;
    cout << "Enter the number of elements:" << endl;
	cin >> N;
    int *SegmentTree;

    long long size =  2 * (int)pow(2,ceil(log2(N)));
    size--;
    SegmentTree = new int[size]{0};
    cout << "Size of segment tree: " << size << endl;
    
    int temp;
	for (int i = 0; i < N; i++) {
        cin >> temp;    
		update(i, temp, SegmentTree, N);
	}   
    cout << query(0, N - 1, SegmentTree, N) << endl;
    cout << query(0, 4, SegmentTree, N) << endl;
    cout << query(2, 6, SegmentTree, N) << endl;

    cout << "Segment Trees" << endl;
    cout << "=============" << endl;
    for (int i = 0; i < size; i++)
        cout << SegmentTree[i] << " ";
    cout << endl;
    delete[]SegmentTree;
}