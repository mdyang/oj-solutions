#include<iostream>
#include<string>

using namespace std;

bool bitlists[2][1024];
int lengths[2];

void calculate_bitlists(int index, const string& str)
{
	int str_length = str.size();
	int length = 0;
	for (int i = 2; i < str_length; i ++)
	{
		char cur_char = str.at(i);
		int cur_val = (cur_char >= 'a' && cur_char <= 'f') ? (cur_char - 'a' + 10) : (cur_char - '0');
		bitlists[index][length++] = ((cur_val & 8) != 0);
		bitlists[index][length++] = ((cur_val & 4) != 0);
		bitlists[index][length++] = ((cur_val & 2) != 0);
		bitlists[index][length++] = ((cur_val & 1) != 0);
	}
	
	lengths[index] = length;
}

int calculate_result(int index)
{
	int segments = 1;
	for (int i = 1; i < lengths[index]; i ++)
		if (bitlists[index][i-1] != bitlists[index][i])
			segments ++;
	if (bitlists[index][0]) segments ++;
	return segments / 2;
}

int main()
{
	int c;
	cin>>c;
	while (c--)
	{
		string a[2];
		cin>>a[0]>>a[1];
		for (int i = 0; i < 2; i ++)
			calculate_bitlists(i, a[i]);
		int a0 = calculate_result(0);
		int a1 = calculate_result(1);
		cout<<(a0 > a1 ? "Alice" : (a0 < a1 ? "Bob" : "Tie"))<<endl;
	}
	
	return 0;
}