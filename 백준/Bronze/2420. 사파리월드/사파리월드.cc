#include <bits/stdc++.h>

using namespace std;

int main(){

        ios_base::sync_with_stdio(false);
        cin.tie(0);

        long long N, M;

        cin >> N >> M;

        long long result = N - M;

        result = abs(result);

        cout << result << '\n';

        return 0;

}
