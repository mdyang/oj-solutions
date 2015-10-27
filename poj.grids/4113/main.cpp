#include<iostream>
#include<algorithm>
#include<string>

using namespace std;
typedef long long LL;

string stations[2][20];
LL distances[2][20];
LL intersections[2];
LL lengths[2];
LL l;

LL calculate_distance(LL line, LL from, LL to);
LL get_index(const string& station, LL line);
LL get_price(LL distance);

int main()
{
	LL c;
	cin>>c;
	for (int i = 0; i < c; i ++)
	{
		cout<<"Case "<<(i+1)<<":\n";
		LL d;
		cin>>l>>d;
		for (int j = 0; j < l; j++)
		{
			LL m;
			cin>>m>>stations[j][0];
			lengths[j] = m;
			for (int k = 1; k < m; k ++)
			{
				cin>>distances[j][k-1]>>stations[j][k];
			}
		}
		for (int j = 0; j < d; j ++)
		{
			string from, to;
			cin>>from>>to;
			LL from_0 = get_index(from, 0);
			LL from_1 = get_index(from, 1);
			LL to_0 = get_index(to, 0);
			LL to_1 = get_index(to, 1);
			LL from_line = ((from_0 < 0 ? 0 : 1) | (from_1 < 0 ? 0 : 2));
			LL to_line = ((to_0 < 0 ? 0 : 1) | (to_1 < 0 ? 0 : 2));
			bool need_transfer = ((from_line & to_line) == 0);
			LL distance = 0;
			if (need_transfer)
			{
				for (intersections[0] = 0; intersections[0] < lengths[0]; intersections[0] ++)
					for (intersections[1] = 0; intersections[1] < lengths[1]; intersections[1] ++)
						if (intersections[0] == intersections[1]) 
							break;
				if (from_0 >= 0)
					distance = calculate_distance(0, from_0, intersections[0]) + calculate_distance(1, intersections[1], to_1);
				else
					distance = calculate_distance(1, from_1, intersections[1]) + calculate_distance(0, intersections[0], to_0);
			}
			else
			{
				if (from_0 >= 0)
					distance = calculate_distance(0, from_0, to_0);
				else
					distance = calculate_distance(1, from_1, to_1);
			}
			cout<<get_price(distance)<<endl;
		}
	}
}

LL calculate_distance(LL line, LL a, LL b)
{
	LL distance = 0;
	LL from = min(a, b), to = max(a, b);
	for (int i = from; i < to; i ++)
		distance += distances[line][i];
	return distance;
}

LL get_index(const string& station, LL line)
{
	if (line >= l) return -1;
	for (int i = 0; i < lengths[line]; i ++)
	{
		if (stations[line][i] == station)
			return i;
	}
	
	return -1;
}

LL get_price(LL distance)
{
	if (distance <= 6000)
		return 3;
	if (distance <= 12000)
		return 4;
	if (distance <= 22000)
		return 5;
	if (distance <= 32000)
		return 6;
	return 6 + (distance - 32000 + 20000) / 20000;
}