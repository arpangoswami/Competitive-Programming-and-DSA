#include<bits/stdc++.h>
using namespace std;
struct color
{
	int red;
	int blue;
	int green;
};


bool Red(color &r1, color &r2)
{
	return (r1.red < r2.red);
}

bool Blue(color &b1, color &b2)
{
	return (b1.blue < b2.blue);
}

bool Green(color &g1, color &g2)
{
	return (g1.green < g2.green);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);


	int n, q;
	cin >> n >> q;

	color arr[n];
	color red[n];
	color blue[n];
	color green[n];


	for (int i = 0; i < n; i++)
	{
		cin >> arr[i].red >> arr[i].blue >> arr[i].green;

		red[i].red = arr[i].red;
		red[i].blue = arr[i].blue;
		red[i].green = arr[i].green;

		blue[i].red = arr[i].red;
		blue[i].blue = arr[i].blue;
		blue[i].green = arr[i].green;

		green[i].red = arr[i].red;
		green[i].blue = arr[i].blue;
		green[i].green = arr[i].green;
	}

	int redCheck[n];
	int blueCheck[n];
	int greenCheck[n];


	sort(red, red + n, Red);
	sort(blue, blue + n, Blue);
	sort(green, green + n, Green);

	for (int i = 0; i < n; i++)
	{
		redCheck[i] = red[i].red;
		blueCheck[i] = blue[i].blue;
		greenCheck[i] = green[i].green;
	}
	unordered_map<int, pair<int, int>> red_map;
	unordered_map<int, pair<int, int>> blue_map;
	unordered_map<int, pair<int, int>> green_map;
	while (q--)
	{
		color temp;
		cin >> temp.red >> temp.blue >> temp.green;
		if (!binary_search(redCheck, redCheck + n, temp.red) || !binary_search(blueCheck, blueCheck + n, temp.blue) || !binary_search(greenCheck, greenCheck + n, temp.green))
		{
			cout << "NO" << endl;
			continue;
		}
		bool f = false;
		bool rf = false;
		int rl;
		int ru;
		if (red_map.find(temp.red) != red_map.end())
		{
			rl = red_map[temp.red].first;
			ru = red_map[temp.red].second;
		}
		else
		{
			rl = lower_bound(redCheck, redCheck + n, temp.red) - redCheck;
			ru =  upper_bound(redCheck, redCheck + n, temp.red) - redCheck;
			red_map[temp.red].first = rl;
			red_map[temp.red].second = ru;
		}

		for (int i = rl; i < ru; i++)
		{
			if (red[i].blue <= temp.blue && red[i].green <= temp.green)
			{
				if (red[i].blue == temp.blue && red[i].green == temp.green)
				{
					f = true;
				}
				rf = true;
				break;
			}
		}
		if (f)
		{
			cout << "YES" << endl;
			continue;
		}
		bool bf = false;
		int bl;
		int bup;
		if (blue_map.find(temp.blue) != blue_map.end())
		{
			bl = blue_map[temp.blue].first;
			bup = blue_map[temp.blue].second;
		}
		else
		{
			bl = lower_bound(blueCheck, blueCheck + n, temp.blue) - blueCheck;
			bup = upper_bound(blueCheck, blueCheck + n, temp.blue) - blueCheck;

			blue_map[temp.blue].first = bl;
			blue_map[temp.blue].second = bup;
		}

		for (int i = bl; i < bup; i++)
		{
			if (blue[i].red <= temp.red && blue[i].green <= temp.green)
			{
				if (blue[i].red == temp.red && blue[i].green == temp.green)
				{
					f = true;
				}
				bf = true;
				break;
			}
		}

		if (f)
		{
			cout << "YES" << endl;
			continue;
		}
		bool gf = false;
		int gl;
		int gu;
		if (green_map.find(temp.green) != green_map.end())
		{
			gl = green_map[temp.green].first;
			gu = green_map[temp.green].second;
		}
		else
		{
			gl = lower_bound(greenCheck, greenCheck + n, temp.green) - greenCheck;
			gu = upper_bound(greenCheck, greenCheck + n, temp.green) - greenCheck;
			green_map[temp.green].first = gl;
			green_map[temp.green].second = gu;
		}

		for (int i = gl; i < gu; i++)
		{
			if (green[i].red <= temp.red && green[i].blue <= temp.blue)
			{
				if (green[i].red <= temp.red && green[i].blue <= temp.blue)
				{
					f = true;
				}
				gf = true;
				break;
			}

		}

		if (rf == true && bf == true && gf == true)
		{
			cout << "YES" << endl;
		}
		else
		{
			cout << "NO" << endl;
		}


	}

}