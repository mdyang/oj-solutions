#include <queue>
#include <stack>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <limits.h>
#include <string.h>
#include <string>
#include <algorithm>

using namespace std;

const int MAX = 10;
double a[MAX][MAX];
double s[MAX][MAX][MAX][MAX];
double d[20][MAX][MAX][MAX][MAX];
double sqr(double x)
{
	return x*x;
}
void init()
{
	s[0][0][0][0] = a[0][0];
	d[0][0][0][0][0] = sqr(s[0][0][0][0]);
	for(int i=1; i<8; i++)
	{
		s[0][0][0][i] = s[0][0][0][i-1] + a[0][i];
		s[0][0][i][0] = s[0][0][i-1][0] + a[i][0];
		d[0][0][0][i][0] = sqr(s[0][0][i][0]);
		d[0][0][0][0][i] = sqr(s[0][0][0][i]);
	}
	double sum;
	for(int i=1; i<8; i++)
	{
		sum = a[i][0];
		for(int k=1; k<8; k++)
		{
			sum += a[i][k];
			s[0][0][i][k] = s[0][0][i-1][k] + sum;
			d[0][0][0][i][k] = sqr(s[0][0][i][k]);
		}
	}
	
	for(int i=0; i<8; i++)
		for(int k=0; k<8; k++)
			for(int p=i; p<8; p++)
				for(int q=k; q<8; q++)
				{
					s[i][k][p][q] = s[0][0][p][q] - s[0][0][p][k-1]
							 - s[0][0][i-1][q] + s[0][0][i-1][k-1];	
					d[0][i][k][p][q] = sqr(s[i][k][p][q]);
				}
}

int main()
{
	int n;
	
	while( ~scanf("%d",&n) )
	{
		memset(s,0,sizeof(s));
		memset(d,0,sizeof(d));
		double ss = 0;
		for(int i=0; i<8; i++)
			for(int k=0; k<8; k++)
			{
				scanf("%lf",&a[i][k]);
				ss += a[i][k];
			}
			
		init();

		for(int k=1; k<n; k++)
			for(int i=0; i<8; i++)
				for(int j=0; j<8; j++)
					for(int p=i; p<8; p++)
						for(int q=j; q<8; q++)
						{
							double c1,c2;
							d[k][i][j][p][q] = 1e20;
							for(int aa=i; aa<p; aa++)
							{
								c1 = min(d[k-1][i][j][aa][q] + sqr(s[aa+1][j][p][q]),
												d[k-1][aa+1][j][p][q] + sqr(s[i][j][aa][q]));
								d[k][i][j][p][q] = min(d[k][i][j][p][q],c1);
							}
							for(int bb=j; bb<q; bb++)
							{
								c2 = min(d[k-1][i][j][p][bb] + sqr(s[i][bb+1][p][q]),
												d[k-1][i][bb+1][p][q] + sqr(s[i][j][p][bb]));
								d[k][i][j][p][q] = min(d[k][i][j][p][q],c2);
							}
						}
						
		double avg = ss/n;			
		printf("%.3lf\n",sqrt(d[n-1][0][0][7][7]/n - avg*avg));
	}							 

return 0;
}
