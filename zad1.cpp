#include <iostream>

using namespace std;

int main()
{
    int a, b, count = 0, n = 0;
    cin >> a >> b;

    int num[b];
    int prime[500000];

    for( int i = 0; i < b; i++)
        num[i] = 0;
    for( int i = 2; i*i <= b; i++)
    {
        if( num[i] == 0)
            for( int j = i*i; j <= b; j+=i )
                num[j] = 1;
    }

    for( int i = 0 ; i < b; i++)
        if( num[i] == 0)
        {
            prime[n] = i;
            n++;
        }

    for( int i = a; i < b; i++)
    {
        if( prime[i+1] - prime[i] == 2)
            count++;
    }

    cout << count;
    return 0;
}