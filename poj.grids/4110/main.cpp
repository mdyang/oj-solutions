#include<iostream>
#include<iomanip>
#include<algorithm>

int values[100];
int weights[100];
float densities[100];
int indices[100];

int compare(int i, int j)
{
	return densities[i] > densities[j] ? 1 : 0;
}

using namespace std;

int main()
{
	int n, w;
	cin>>n>>w;
	for (int i = 0; i < n; i ++)
	{
		indices[i] = i;
		cin>>values[i]>>weights[i];
		densities[i] = float(values[i]) / weights[i];		
	}
	
	sort(indices, indices + n, compare);
	
	float value = 0;
	for (int i = 0; i < n; i ++)
	{
		if (w < weights[indices[i]])
		{
			value += (w * densities[indices[i]]);
			break;
		}
		else
		{
			w -= weights[indices[i]];
			value += values[indices[i]];
		}
	}
	
	cout.setf(ios::fixed, ios::floatfield);
	cout.precision(1);
	cout<<value<<endl;
	
	return 0;
}