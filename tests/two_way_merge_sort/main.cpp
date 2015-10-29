#include<iostream>
#include<memory.h>

using namespace std;

int result[100];
int inputs[2][100];
int lengths[2];
int cursors[2];

bool TryGetNextElement(int& value);

int main()
{
	int n;
	cin>>n;
	while (n--)
	{
		for (int i = 0; i < 2; i ++)
		{
			cin>>lengths[i];
			for (int j = 0; j < lengths[i]; j ++)
			{
				cin>>inputs[i][j];
			}
		}
		memset(cursors, 0, sizeof(cursors));
		int l = 0;
		int value;
		while (TryGetNextElement(value))
			result[l++] = value;
		
		for (int i = 0; i < l; i ++)
			cout<<result[i]<<" ";
		cout<<endl;
	}
	
	return 0;
}

bool TryGetNextElement(int& value)
{
	value = 0;
	if (cursors[0] >= lengths[0] && cursors[1] >= lengths[1])
		return false;
	bool cursor0_has_value = cursors[0] < lengths[0];
	bool cursor1_has_value = cursors[1] < lengths[1];
	bool both_have_value = cursor0_has_value && cursor1_has_value;
	if ((both_have_value && inputs[0][cursors[0]] < inputs[1][cursors[1]]) || cursor0_has_value && !both_have_value)
	{
		value = inputs[0][cursors[0]];
		cursors[0] ++;
	}
	else
	{
		value = inputs[1][cursors[1]];
		cursors[1] ++;
	}
}