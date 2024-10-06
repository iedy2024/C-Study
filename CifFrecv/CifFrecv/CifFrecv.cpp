#include<iostream>
#include<fstream>
using namespace std;
ifstream fin("ciffrecv.in");
ofstream fout("ciffrecv.in");
int v[1000000];
int main()
{
	int i, n, frecv[10],j,max=0,d,pp;
	fin >> n;
	for (i = 1;i <= n;i++)
		cin >> v[i];
	for (i = 1;i <= n;i++)
	{
		pp = 1;
		if (v[i] == 0 || v[i] == 1)
			pp = 0;
		else
			if (v[i] % 2 == 0 && v[i] != 2)
				pp = 0;
			else
				for (d = 3;d * d <= v[i] && pp == 1;d += 2)
				{
					if (v[i] % d == 0)
					{
						pp = 0;
					}
					else
						if (v[i] > max)
							max = v[i];
				}
	}
	for (i = 0;i <= 9;i++)
		frecv[max] = 0;
	while (cin >> max)
		frecv[max]++;
	fout << max << " " << frecv[max];
}