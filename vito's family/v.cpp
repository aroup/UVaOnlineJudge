#include <iostream>
#include <algorithm>
#include <vector>

using namespace std ;

int main ()
{
    int houses,number, testcase,median  ;
    vector <int> v ;
    vector <int>::iterator it ;
    cin >> testcase ;
    while (testcase--)
    {
        cin >> houses ;
        for (int i = 1 ; i <= houses ;i++)
        {
            cin >> number ;
            v.push_back (number) ;
        }
        sort (v.begin () ,v.end()) ;
        if (houses%2 == 1)
        {
            median = v[(houses-1)/2]  ;
        }
        if(houses %2 == 0)
        {
            median =(v[(houses-1)/2] + v[(houses-1)/2] ) / 2 ;
        }
        int sum = 0;
        for (it = v.begin () ;it!= v.end () ;it++)
        {
            sum = sum + abs (median - *it) ;
        }
        cout << sum << endl ;
        v.erase (v.begin () ,v.end ()) ;
    }
}
