// lr1.cpp: определяет точку входа для консольного приложения.
//
#include <iostream>
#include <conio.h>
#include "stdafx.h"
using namespace std;
#define maxn 100


int a[maxn];
int mas[];
int n;
int* foo = mas;


void insertion_sort(int l,int r, int* arr)
{
	
	int key = 0, j = 0;
	for (int i = l; i <= r; i++)
	{
		key = arr[i];
		j = i - 1;
		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
	}
}

	void merge(int l, int r) {
		if (r == l)
			return;
		if (r - l <=10) {
			insertion_sort(r,l,mas);
			
			return;
		}
		int m = (r + l) / 2;
		merge(l, m);
		merge(m + 1, r);
		int buf[maxn];
		int xl = l;
		int xr = m + 1;
		int cur = 0;
		while (r - l + 1 != cur) {
			if (xl > m)
				buf[cur++] = a[xr++];
			else if (xr > r)
				buf[cur++] = a[xl++];
			else if (a[xl] > a[xr])
				buf[cur++] = a[xr++];
			else buf[cur++] = a[xl++];

		}
		for (int i = 0; i < cur; i++)
			a[i + l] = buf[i];

}
	void merge1(int l, int r) {
		if (r == l)
			return;
		if (r - l == 1) {
			if (a[r] < a[l])
				swap(a[r], a[l]);
			return;
		}
		int m = (r + l) / 2;
		merge(l, m);
		merge(m + 1, r);
		int buf[maxn];
		int xl = l;
		int xr = m + 1;
		int cur = 0;
		while (r - l + 1 != cur) {
			if (xl > m)
				buf[cur++] = a[xr++];
			else if (xr > r)
				buf[cur++] = a[xl++];
			else if (a[xl] > a[xr])
				buf[cur++] = a[xr++];
			else buf[cur++] = a[xl++];

		}
		for (int i = 0; i < cur; i++)
			a[i + l] = buf[i];

	}
	int main() {
		cin >> n;

		for (int i = 0; i < n; i++)
			cin >> a[i];

		merge(0, n - 1);

		for (int i = 0; i < n; i++)
			cout << a[i] << " ";

		getch();
		return 0;
	}





