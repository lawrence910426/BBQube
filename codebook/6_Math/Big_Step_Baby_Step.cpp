#include <iostream>
#include <unordered_map>
#include <cmath>

using namespace std;

/* a^k = b (mod p). k is the returning answer. */
class Discrete_Log {
public:
    long long pow(long long base, long long power, long long p) {
        long long ans = 1, temp = base;
        while(power != 0) {
            if(power % 2 == 1) ans = (ans * temp) % p;
            temp = (temp * temp) % p;
            power >>= 1;
        }
        return ans;
    }

    long long solve(long long a, long long b, long long p) {
        unordered_map<long long, long long> appear;
        long long m = sqrt(p) + 1, temp;
        for(long long i = 0;i <= m;i++) {
            temp = pow(a, m * i, p);
            temp = pow(temp, p - 2, p);
            temp = (temp * b) % p;
            appear[temp] = i;
        }
        for(long long i = 0;i <= m;i++) {
            temp = pow(a, i, p);
            if(appear.find(temp) != appear.end()) return appear[temp] * m + i;
        }
        return -1;
    }
} Log;

int main() {
    long long a, b, p, ans;
    cin >> a >> b >> p;
    ans = Log.solve(a, b, p);
    cout << ans << endl;
    cout << Log.pow(a, ans, p) << " " << b << endl;
}
