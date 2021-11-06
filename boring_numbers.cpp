#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int, int> pii;
char odd[5] = {'1', '3', '5', '7', '9'};
char even[5] = {'0', '2', '4', '6', '8'};
int binPow(int x, int y) {
	int ans = 1;
	while (y) {
		if (y & 1) {
			ans *= x;
		}
		x *= x;
		y >>= 1;
	}
	return ans;
}
void countNumbers2(int idx, int length, string a, string s, int &cnt, bool flag) {
	if (flag) {
		cnt += binPow(5LL, length - idx);
		return;
	}
	if (idx == length) {
		cnt++;
		return;
	}
	if (idx % 2 == 0) {
		for (int i = 1; i <= 9; i += 2) {
			int dig = s[idx] - '0';
			if (i > dig) {
				break;
			} else if (i == dig) {
				a.push_back(i + '0');
				countNumbers2(idx + 1, length, a, s, cnt, false);
			} else {
				a.push_back(i + '0');
				countNumbers2(idx + 1, length, a, s, cnt, true);
			}
		}
	} else {
		for (int i = 0; i <= 8; i += 2) {
			int dig = s[idx] - '0';
			if (i > dig) {
				break;
			} else if (i == dig) {
				a.push_back(i + '0');
				countNumbers2(idx + 1, length, a, s, cnt, false);
			} else {
				a.push_back(i + '0');
				countNumbers2(idx + 1, length, a, s, cnt, true);
			}
		}
	}
}
void countNumbers1(int idx, int length, string a, string s, int &cnt, bool flag) {
	if (flag) {
		cnt += binPow(5LL, length - idx);
		return;
	}
	if (idx == length) {
		cnt++;
		return;
	}
	if (idx % 2 == 0) {
		for (int i = 9; i >= 1; i -= 2) {
			int dig = s[idx] - '0';
			if (i < dig) {
				break;
			} else if (i == dig) {
				a.push_back(i + '0');
				countNumbers1(idx + 1, length, a, s, cnt, false);
			} else {
				a.push_back(i + '0');
				countNumbers1(idx + 1, length, a, s, cnt, true);
			}
		}
	} else {
		for (int i = 8; i >= 0; i -= 2) {
			int dig = s[idx] - '0';
			if (i < dig) {
				break;
			} else if (i == dig) {
				a.push_back(i + '0');
				countNumbers1(idx + 1, length, a, s, cnt, false);
			} else {
				a.push_back(i + '0');
				countNumbers1(idx + 1, length, a, s, cnt, true);
			}
		}
	}
}
void countNumbers3(int idx, int len, string s, string a, string b, int &cnt, bool flag1, bool flag2) {
	if (flag1 && flag2) {
		cnt += binPow(5LL, len - idx);
		return;
	}
	if (idx == len) {
		cnt++;
		return;
	}
	if (flag1) {
		int dig2 = b[idx] - '0';
		for(int i=0;i<=dig2;i++){
			if (idx % 2 == 0 && i % 2 == 0) {
				continue;
			}
			if (idx % 2 == 1 && i % 2 == 1) {
				continue;
			}
			s.push_back(i + '0');
			if(i < dig2){
				countNumbers3(idx+1,len,s,a,b,cnt,true,true);
			}else{
				countNumbers3(idx+1,len,s,a,b,cnt,true,false);
			}
		}
	} else if (flag2) {
		int dig1 = a[idx] - '0';
		for(int i=9;i>=dig1;i--){
			if (idx % 2 == 0 && i % 2 == 0) {
				continue;
			}
			if (idx % 2 == 1 && i % 2 == 1) {
				continue;
			}
			s.push_back(i + '0');
			if(i > dig1){
				countNumbers3(idx+1,len,s,a,b,cnt,true,true);
			}else{
				countNumbers3(idx+1,len,s,a,b,cnt,false,true);
			}
		}
	} else {
		int dig1 = a[idx] - '0', dig2 = b[idx] - '0';
		for (int i = dig1; i <= dig2; i++) {
			if (idx % 2 == 0 && i % 2 == 0) {
				continue;
			}
			if (idx % 2 == 1 && i % 2 == 1) {
				continue;
			}
			s.push_back(i + '0');
			if (i > dig1 && i < dig2) {
				countNumbers3(idx + 1, len, s, a, b, cnt, true, true);
			} else if (i == dig1 && i < dig2) {
				countNumbers3(idx + 1, len, s, a, b, cnt, false, true);
			} else if (i > dig1 && i == dig2) {
				countNumbers3(idx + 1, len, s, a, b, cnt, true, false);
			} else if (i == dig1 && i == dig2) {
				countNumbers3(idx + 1, len, s, a, b, cnt, false, false);
			}
		}
	}
}
void solveQ() {
	int left, right; 
	cin >> left >> right;
	string a = to_string(left), b = to_string(right);
	int nD1 = a.size(), nD2 = b.size();
	int extra = 0;
	for (int i = nD1 + 1; i <= nD2 - 1; i++) {
		extra += binPow(5LL, i);
	}
	int cnt = 0;
	if (nD1 < nD2) {
		countNumbers2(0, nD2, "", b, cnt, false);
		countNumbers1(0, nD1, "", a, cnt, false);
	} else {
		countNumbers3(0, nD1, "", a, b, cnt, false, false);
	}
	cout << cnt + extra << "\n";
}
int32_t main(int32_t argc, char const* argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int test;
	cin >> test;
	for (int t = 1; t <= test; ++t) {
		cout << "Case #" << t << ": ";
		solveQ();
	}
	return 0;
}