#include <bits/stdc++.h>
#define rep(i, l, r) for (int i = (l); i < (r); i++)

typedef long long ll;
const ll LINF = 1e18;
const int INF = 1e9;

using namespace std;

int main()
{
    int w;
    int h;
    int count_x;
    int count_y;
    cin >> w >> h >> count_x >> count_y; cin.ignore();
    
    vector<int> v_line(count_x + 2);
    vector<int> r_line(count_y + 2);
    v_line[0] = 0;
    v_line[count_x + 1] = w;
    r_line[0] = 0;
    r_line[count_y + 1] = h;

    for (int i = 0; i < count_x; i++) {
        int x;
        cin >> x; cin.ignore();
        v_line[1 + i] = x;
    }
    for (int i = 0; i < count_y; i++) {
        int y;
        cin >> y; cin.ignore();
        r_line[1 + i] = y;
    }

    int ans = 0;
    vector<int> leng_list_v(20010,0);
    vector<int> leng_list_r(20010,0);
    rep(v1, 0, count_x + 1)
        rep(v2, v1 + 1, count_x + 2)
            leng_list_v[v_line[v2] - v_line[v1]]++;
    rep(r1, 0, count_y + 1)
        rep(r2, r1 + 1, count_y + 2)
            leng_list_r[r_line[r2] - r_line[r1]]++;
    
    rep(i, 0, 20010)
        ans += leng_list_v[i] * leng_list_r[i];

    // Write an answer using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;

    cout << ans << endl;
}