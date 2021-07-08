#include <iostream>
using namespace std;
int v[1000], b[1000];
void Csb(int p, int n) 
{
	int i, a[256] = { 0 };

	for ( i = 0; i < n; i++)
		a[(v[i] >> (p * 8)) & 255]++;
	
	for (i = 1; i <= 255; i++)
		a[i] += a[i - 1];

	int aux;
	for (i = n - 1; i >= 0; i--)
	{
		aux = v[i] >> (p * 8) & 255;
		b[a[aux] - 1] = v[i];
		a[aux]--;
	}
	for (i = 0; i < n; i++)
		v[i] = b[i];
}
void radix(int n)
{
	int i;
	for (i = 0; i < sizeof(int); i++)
		Csb(i,n);
	
}

int main()
{
	int i,n;
	cout << "dati n= ";
	cin >> n;
	for ( i = 0; i < n; i++)
	{
		cout << "v[" << i << "]= ";
		cin >> v[i];
	}
	radix(n);
	cout << "vector sortat radix_sort_pe_biti: " << endl;
	for (int i = 0; i < n; i++)
		cout << v[i] << " ";
}