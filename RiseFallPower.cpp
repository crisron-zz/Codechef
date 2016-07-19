// https://www.codechef.com/problems/MARCHA4

#include <iostream>
#include <cmath>

using namespace std;

long long int power( int a, int b, int mod ) {
    if( !b ) {
        return 1;
    }
    long long int temp = power( a, b / 2, mod ) * power( a, b / 2, mod ) % mod;
    // b is even
    if( !( b & 1 ) ) {
        return temp;
    }
    return ( temp * a % mod );
}

// https://discuss.codechef.com/questions/15398/first-k-digits-of-nn
int firstKDigits( int n, int k ) {
    double x = n * log10( n );
    double y = pow( 10, x - floor( x ) + k - 1 );
    return ( (int)y );
}

// x = n^n
// last k digits of x = x % 10^k
long long int lastKDigits( int n, int k ) {
    int j = pow( 10, k );
    return power( n, n, j );
}

int main() {
    int t;
    cin >> t;
    while( t-- ) {
        int n, k;
        cin >> n >> k;
        cout << firstKDigits( n, k ) << " ";
        int lastKDig = lastKDigits( n, k );
        int tmp = lastKDig;
        // Handle the case where the length of the returned
        // integer is less than k. For example, n=10, k=5
        int len = tmp ? 0 : 1;
        // Calculate the length of the returned integer
        while( tmp ) {
            len++;
            tmp /= 10;
        }
        // Append required number of zeros at the start
        for( int i = 0; i < ( k - len ); ++i ) {
            cout << "0";
        }
        cout << lastKDig << endl;
    }
    return 0;
}
