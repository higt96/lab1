// lr1.cpp: определяет точку входа для консольного приложения.
//
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <conio.h>
#include "stdafx.h"
#include <windows.h>
#include <algorithm>
using namespace std;
int mas[];

void getn(int& x) {
	ifstream fin("min.txt");
	x=0;
	while (!fin.eof())
	{	x++;	}
	fin.close();

}
void masin(int* mas)
{
	ifstream fin("min.txt");
	
	int x=0;
	while (!fin.eof())
	{
		fin >> mas[x];

			x++;
	}
	fin.close();
		
	
}

void masout(int* mas,int n)
{
	ofstream fout("mout.txt"); 
	for (int i = 0; i < n; i++) {
		fout << mas[i];
	}
	fout.close(); 
	
}

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

	void merge(int l, int r,int* mas) {
		if (r == l)
			return;
		if (r - l <=10) {
			insertion_sort(r,l,mas);
			
			return;
		}
		int m = (r + l) / 2;
		merge(l, m, mas);
		merge(m + 1, r, mas);
		int buf[n];
		int xl = l;
		int xr = m + 1;
		int cur = 0;
		while (r - l + 1 != cur) {
			if (xl > m)
				buf[cur++] = mas[xr++];
			else if (xr > r)
				buf[cur++] = mas[xl++];
			else if (mas[xl] > mas[xr])
				buf[cur++] = mas[xr++];
			else buf[cur++] = mas[xl++];

		}
		for (int i = 0; i < cur; i++)
			mas[i + l] = buf[i];

}
	
	int main() {
				
		int n = 0;
		getn(n);
		int mas[n];
		masin(mas);

		DWORD start = GetTickCount();
		for (int i = 0; i < 1000; i++)

			merge(0, n - 1, mas);

		DWORD end = GetTickCount();
		cout << (unsigned int)(end - start) << endl;
		cin.get();
		masout(mas,n);
		return 0;
		
		


		return 0;
	}





