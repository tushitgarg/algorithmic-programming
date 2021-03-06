#include <iostream>
using namespace std;

int partition(int a[], int l ,int r) {
	swap(a[l], a[l + rand() % (r - l + 1)]);
	int pos = l + 1;
	int pivot = a[l];
	for(int i = l + 1; i <= r; i++) {
		if(a[j] < pivot) {
			swap(a[pos], a[i]);
			pos++;
		}
	}
	swap(a[--pos], a[l]);
	return pos;
}

void quickSort(int a[], int l, int r) {
	if(l < r) {
		int p = partition(a, l, r);
		quickSort(a, 0, p-1);
		quickSort(a, p+1, r);
	}
}

int main()
{
	int a[]={1,6,12,2,7,90,45,23,101,1,893,1236,390,1902,345,12,45};
	int sz=sizeof(a)/sizeof(a[0]);
	quickSort(a,0,sz);
	for(int i:a)
		cout<<i<<" ";
}