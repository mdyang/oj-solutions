#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <memory.h>

using namespace std;

typedef unsigned long long ull;
ull a, b;
ull m = 1000000000+7;
ull matrix[26][26];

ull modolo(int root, int exp, int m)
{
	if (exp == 0)
	{
		return 1;
	}
	
	if (exp == 1)
	{
		return root % m;
	}
	
	if (exp % 2)
	{
		return ((modolo(root, exp-1, m) % m) * (root % m)) % m;
	}
	else
	{
		ull result = modolo(root, exp/2, m);
		return ((result % m) * (result % m)) % m;
	}
}

void tryswap(ull& a, ull& b)
{
	if (a < b)
	{
		ull temp = a;
		a = b;
		b = temp;
	}
}

int main() {
    cin>>a>>b;
	tryswap(a, b);
	if ((a > 25 && a - b > 2) || a < 25 || a - b < 2)
	{
		cout << 0 << endl;
		return 0;
	}
	
	memset(matrix, 0, sizeof(matrix));
	
	for (int i = 0; i <= 25; i ++)
	{
		matrix[i][0] = matrix[0][i] = 1;
	}
	
	for (int i = 1; i < 25; i ++)
		for (int j = 1; j < 25; j ++)
		{
			matrix[i][j] = (matrix[i-1][j] % m + matrix[i][j-1] % m) % m;
		}
		
	for (int i = 1; i < 25; i ++)
	{
		matrix[i][25] = matrix[i][24];
		matrix[25][i] = matrix[24][i];
	}
		
	if (a > 25)
	{
		cout << (((matrix[24][24] % m) * (modolo(2, b - 24, m) % m)) % m) << endl;
	}
	else
	{
		cout << matrix[a][b] << endl;
	}

    return 0;
}
