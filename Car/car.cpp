#include <iostream>
#include <cmath>
using namespace std ;

int main ()
{
    int _case ,cnum = 0;
    double u,v,t,a,s;
    cout << fixed ;
    cout.precision (3) ;
    while (cin >> _case && _case)
    {
        if (_case ==1)
        {
    		cin >> u >> v >> t ;
            a = (v-u)/t ;
            s= u * t + .5 * a *t*t ;
            cout << "Case " << ++cnum << ": " << s << ' '<<a << endl; 
        }
        if (_case ==2)
        {
			cin >> u >> v >> a ;
            s = (v*v -u*u) /(2*a) ;
            t = (v-u)/a ;
            cout << "Case " << ++cnum << ": " << s << ' '<<t << endl;
        }
        if (_case == 3)
        {
			cin >> u >> a >>s ;
            v = sqrt (u*u + 2 *a *s) ;
            t = (v-u) /a ;
            cout << "Case " << ++cnum << ": " << v << ' '<<t<< endl;
        }
        if (_case ==4)
        {
			cin >> v >> a >>s ;
            u = sqrt (v*v-2*a*s) ;
            t = (v-u) / a ;
            cout << "Case " << ++cnum << ": " << u << ' '<<t << endl;
        }
    }
    return 0 ;
    
}
