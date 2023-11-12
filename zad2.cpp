#include <iostream>

using namespace std;

void sieveOfEratosthenes( int b, int num[1000000])
{
    for( int i = 0; i < b; i++)
        num[i] = 0;
    for( int i = 2; i*i <= b; i++)
    {
        if( num[i] == 0)
            for( int j = i*i; j <= b; j+=i )
                num[j] = 1;
    }
}

int main()
{
    int n = 0, b = 1000000, max;
    int num[b];
    int prime[500000];
    int count[b];

    // tworzenie tablicy z liczbami pierwszymi
    sieveOfEratosthenes( b, num);
    for( int i = 0 ; i < b; i++)
        if( num[i] == 0)
        {
            prime[n] = i;
            n++;
        }
    
    // zerowanie licznika
    for(int i = 0; i < b; i++)
        count[i] = 0;

    // rozkład + zapisywanie danych do licznila
    for( int a = 4; a < b; a = a+2)
    {
        for(int g = 0; g < a; g++)
        {
            for(int j = 0; j < a; j++)
                if( prime[g] + prime[j] == a)
                    count[a] = count[a] + 1;
        }
    }

    // szukanie najwiekszej wartosci w tablicy count
    max = count[0];
    for(int i = 1; i < b; i++)
    {
        if( count[i] > count[i-1])
            max = count[i];
    }

    cout << max;

}