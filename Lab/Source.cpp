#include"lib.h"
void merge(int a[], int l, int mid, int r) {
	int i1 = mid - l + 1;
	int i2 = r - mid;
	int* b1 = new int[i1];
	int* b2 = new int[i2];
	for (int i = 0; i < i1; i++) {
		b1[i] = a[l + i];
	}
	for (int i = 0; i < i2; i++) {
		b2[i] = a[mid + i + 1];
	}
	int i = 0;
	int j = 0;
	int k = l;
	while (i<i1&&j<i2)
	{
		if (i==i1||b1[i] >= b2[j]) {
			a[k++] = b2[j];
			j++;
		}
		else {
			a[k++] = b1[i];
			i++;
		}
	}
}
void mergeSort(int a[], int l, int r) {
	if (l >= r) return;
	int mid = (l + r) / 2;
	mergeSort(a, l, mid);
	mergeSort(a, mid + 1, r);
	merge(a, l, mid, r);
}
void print(int a[], int n) {
	cout << "\nMang sau khi sap xep: ";
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
}
void menu() {
	int ch;
	while (true)
	{
		cout << "\n\n\t\t======MENU======";
		cout << "\n\t1.Merge Sort";
		cout << "\nNhap su lua chon: ";
		cin >> ch;
		switch (ch)
		{
		case 1:
		{
			int a[] = { 1,2,5,1,4,6 };
			mergeSort(a, 0, 5);
			print(a, 6);
			break;
		}
		default:
			break;
		}
	}
}