#include <cstdio>
#include <algorithm>
using namespace std;

int n, ans = 1e9;
int a[20][20];
bool c[20];

void solve(int cnt, int idx) {
    if (idx == n) return;
    if (cnt == n/2) {
        int s1 = 0, s2 = 0;
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                if (c[i] && c[j]) s1 += a[i][j];
                if (!c[i] && !c[j]) s2 += a[i][j];
            }
        }
        ans = min(ans, abs(s1-s2));
        return;
    }
    c[idx] = true;
    solve(cnt+1, idx+1);
    c[idx] = false;
    solve(cnt, idx+1);
}

int main() {
    scanf("%d", &n);
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    solve(0, 0);
    printf("%d\n", ans);
    return 0;
}