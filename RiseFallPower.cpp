// https://www.codechef.com/problems/MARCHA4

#include <iostream>
#include <cmath>

using namespace std;

// https://discuss.codechef.com/questions/15398/first-k-digits-of-nn
int firstKDigits( int n, int k ) {
    double x = n * log10( n );
    double y = pow( 10, x - floor( x ) + k - 1 );
    return ( (int)y );
}

// x = n^n
// last k digits of x = x % 10^k
int lastKDigits( int n, int k ) {
    long long res = 1;
    int j = pow( 10, k );
    for( int i = 1; i <= n; i++ ) {
        res = ( res * n ) % j;
    }
    return res;
}

int main() {
    int t;
    cin >> t;
    while( t-- ) {
        int n, k;
        cin >> n >> k;
        cout << firstKDigits( n, k ) << " ";
        cout << lastKDigits( n, k ) << endl;
    }
    return 0;
}
