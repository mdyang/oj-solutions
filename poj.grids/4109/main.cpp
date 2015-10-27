#include<iostream>
#include<memory.h>

using namespace std;

bool matrix[100][100];

int main()
{
	int c;
	cin>>c;
	for(int i = 0; i < c; i ++)
	{
		cout<<"Case "<<(i+1)<<":\n";
		memset(matrix, 0, sizeof(matrix));
		int n, m, k;
		cin>>n>>m>>k;
		for(int j = 0; j < m; j ++)
		{
			int a,b;
			cin>>a>>b;
			a--; b--;
			matrix[a][b] = matrix[b][a] = true;
		}
		for(int j = 0; j < k; j ++)
		{
			int a,b,count = 0;
			cin>>a>>b;
			a--; b--;
			for(int k = 0; k < n; k ++)
			{
				if(matrix[a][k] && matrix[b][k])
					count++;
			}
			cout<<count<<endl;
		}
	}
	
	return 0;
}