// Eventually you will be bored !

#include <bits/stdc++.h>

using namespace std;

#define _CRT_SECURE_NO_DEPRECATE

typedef long long		ll ;
typedef vector <int> 		vi ;
typedef pair <int, int>		ii ;
typedef vector <ii>		vii;
typedef set <int>		si ;
typedef map <string,int>	msi;

#define REP(i,a,b) \
	for (int i = int (a) ; i <= int (b) ; i++) // a to b , i is local 
#define TRvi(c,it)  \
	for (vi::iterator it = (c).begin () ; it != (c).end () ; it++)
#define TRvii(c,it)  \
	for (vii::iterator it = (c).begin () ;it !=(c).end () ;it++)
#define TRmsi(c,it)  \
	for (msi::iterator it = (c).begin () ;it != (c).end () ; it++)

#define INF 2000000000
#define MEMSET_INF 127
#define MEMSET_HALF_INF 63
#define DFS_WHITE -1
#define DFS_BLACK 1
#define DFS_GRAY 2
const double PI = 2*acos(0.0);
#define EPS 1e-9
struct point {
    double x,y;
    point () {
        x=y=0.0;
    }
    point (double _x,double _y) : x(_x), y(_y) {}
    bool operator < (point other) const {
        if(fabs(x-other.x)>EPS)
            return x<other.x;
        return y<other.y;
    }
    bool operator == (point other) const {
        return (fabs(x-other.x)<EPS&&fabs(y-other.y)<EPS);
    }
};

struct point_i {
    char C;
    int x,y;
    point_i() {
        x=y=0;
        C='a';
    }
    point_i(char _c,int _x,int _y) : C(_c),x(_x),y(_y) {}
};

vector<point_i> arr;

int area(vector<point_i> &P)
{
    int x1=P[0].x,y1=P[0].y;
    int x2=P[1].x,y2=P[1].y;
    int x3=P[2].x,y3=P[2].y;
    return abs((y3-y1)*(x2-x1)-(y2-y1)*(x3-x1));
}
int A,n;
bool check(int i,int j,int k)
{
    vector<point_i> G;
    REP(I,0,n-1)
    {
        if(I!=i&&I!=j&&I!=k)
        {
			G.clear();
            G.push_back(arr[i]);
            G.push_back(arr[j]);
            G.push_back(arr[I]);
            int A1=area(G);
            G.clear();
            G.push_back(arr[j]);
            G.push_back(arr[I]);
            G.push_back(arr[k]);
            int A2=area(G);
            G.clear();
            G.push_back(arr[i]);
            G.push_back(arr[k]);
            G.push_back(arr[I]);
            int A3=area(G);
            G.clear();
            if(A1+A2+A3==A||((A1==0||A2==0||A3==0) &&A1+A2+A3==A))
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    std::ios::sync_with_stdio(false);
    char C;
    int x,y;
    while(cin>>n)
    {
		if (n==0) break;
        REP(i,0,n-1)
        {
            cin>>C>>x>>y;
            arr.push_back(point_i(C,x,y));
        }
        int Area=-INF;
        string ans="   ";
        REP(i,0,n-1)
        REP(j,i+1,n-1)
        REP(k,j+1,n-1)
        {
            vector<point_i> G;
            G.push_back(arr[i]);
            G.push_back(arr[j]);
            G.push_back(arr[k]);
            A=area(G);
            if(check(i,j,k)&&A>Area)
            {
                Area=A;
                ans[0]=arr[i].C;
                ans[1]=arr[j].C;
                ans[2]=arr[k].C;
                //~ cout<<Area<<' '<<ans<<endl;
            }
        }
        cout<<ans<<endl;
        arr.clear();
        ans="   ";
    }
    return 0;
}
