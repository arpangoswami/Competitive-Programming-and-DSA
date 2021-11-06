#include <bits/stdc++.h>
#define int long long
#define ff first
#define ss second
#define Boost() ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<pii> vpi;
typedef long double ld;
struct pt {
    double x, y;
};

bool cmp(pt a, pt b) {
    return a.x < b.x || (a.x == b.x && a.y < b.y);
}

bool cw(pt a, pt b, pt c) {
    return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) < 0;
}

bool ccw(pt a, pt b, pt c) {
    return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) > 0;
}

vector<pt> convex_hull(vector<pt>& a) {
    if (a.size() == 1)
        return {};

    sort(a.begin(), a.end(), &cmp);
    pt p1 = a[0], p2 = a.back();
    vector<pt> up, down;
    up.push_back(p1);
    down.push_back(p1);
    for (int i = 1; i < (int)a.size(); i++) {
        if (i == a.size() - 1 || cw(p1, a[i], p2)) {
            while (up.size() >= 2 && !cw(up[up.size()-2], up[up.size()-1], a[i]))
                up.pop_back();
            up.push_back(a[i]);
        }
        if (i == a.size() - 1 || ccw(p1, a[i], p2)) {
            while(down.size() >= 2 && !ccw(down[down.size()-2], down[down.size()-1], a[i]))
                down.pop_back();
            down.push_back(a[i]);
        }
    }
    vector<pt> diff;
    for (int i = 0; i < (int)up.size(); i++)
        diff.push_back(up[i]);
    for (int i = down.size() - 2; i > 0; i--)
        diff.push_back(down[i]);
    return diff;
}
int32_t main(int32_t argc, char const *argv[])
{
	/* code */
	Boost();
	int N;
	cin >> N;
	vector<pt> arr(N);
	for(int i=0;i<N;i++){
		cin >> arr[i].x >> arr[i].y;
	}
	vector<pt> convexHull = convex_hull(arr);
	set<pii> st;
	for(pt temp:convexHull){
		st.insert({temp.x,temp.y});
	}
	int ans = 0;
	for(pt temp:arr){
		if(!st.count({temp.x,temp.y})){
			ans++;
		}
	}
	cout << ans << "\n";
	return 0;
}