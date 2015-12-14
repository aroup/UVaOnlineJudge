//money,fear,hunger

#include <bits/stdc++.h>

using namespace std;

#define _CRT_SECURE_NO_DEPRECATE

typedef long long       ll ;
typedef vector <int>        vi ;
typedef pair <int, int>     ii ;
typedef vector <ii>     vii;
typedef set <int>       si ;
typedef map <string,int>    msi;

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

point pivot(0.00,0.00);
struct vec {
    double x,y;
    vec(double _x,double _y) : x(_x),y(_y) {}
};
double dist(point p1,point p2)
{
    return hypot(p1.x-p2.x,p1.y-p2.y);
}
vec toVec(point a,point b)
{
    return vec(b.x-a.x,b.y-a.y);
}

double Cross(vec a,vec b)
{
    return a.x*b.y-a.y*b.x;
}
bool collinear(point p,point q,point r)
{
    return fabs(Cross(toVec(p,q),toVec(p,r)))<EPS;
}
bool ccw(point p,point q,point r)
{
    //~ if(collinear(p,q,r)) return true;
    return Cross(toVec(p,q),toVec(p,r))>0;
}



bool angleCmp(point a,point b)
{
    if(collinear(pivot,a,b))
    {
        //~ cout<<pivot.x<<' '<<pivot.y<<" "<<a.x<<" "<<a.y<<" "<<b.x<<" "<<b.y<<endl;
        //~ cout<<"calling"<<endl;
        //~ if(a.x>=pivot.x&&a.y>=pivot.y)
        //~ return dist(pivot,a)<dist(pivot,b);
        //~ else
        return dist(pivot,a)<dist(pivot,b);
    }
    double d1x=a.x-pivot.x,d1y=a.y-pivot.y;
    double d2x=b.x-pivot.x,d2y=b.y-pivot.y;

    return (atan2(d1y,d1x)-atan2(d2y,d2x))<0;
}

vector <point> CH(vector<point> P)
{
    int i,j,n=(int) P.size();
    if(n<=3)
    {
        if(!(P[0]==P[n-1]))
            P.push_back(P[0]);
        return P;
    }
    int PO=0;
    REP(i,1,n-1)
    {
        if(P[i].y<P[PO].y||(P[i].y==P[PO].y&&P[i].x>P[PO].x))
            PO=i;
    }
    point temp=P[0] ;
    P[0]=P[PO];
    P[PO]=temp;
    pivot=P[0];
    point a,b;
    a=P[0];
    sort(++P.begin(),P.end(),angleCmp);
    //~ REP(i,0,P.size()-1)
    //~ {
    //~ cout<<P[i].x<<" "<<P[i].y<<endl;
    //~ double d1x=P[i].x-a.x,d1y=P[i].y-a.y;
    //~ cout<<"The Angle = "<<atan2(d1y,d1x)<<endl;
    //~ }

    vector<point>S;
    S.push_back(P[n-1]);
    S.push_back(P[0]);
    S.push_back(P[1]);
    i=2;
    while(i<n)
    {
        j=(int)S.size()-1;
        if(ccw(S[j-1],S[j],P[i])) S.push_back(P[i++]);
        else S.pop_back();
    }
    //cout<<S.size()<<endl;
    return S;
}

double area(const vector<point> &P)
{
    double result=0.0,x1,y1,x2,y2;
    REP(i,0,P.size()-2)
    {
        x1=P[i].x,x2=P[i+1].x;
        y1=P[i].y,y2=P[i+1].y;
        result+=(x1*y2-x2*y1);
    }
    return fabs(result)/2.00;
}

double perimeter(const vector<point> &P)
{
    double result=0.0;
    REP(i,0,P.size()-2)
    {
        result+=dist(P[i],P[i+1]);
    }
    return result;
}

int main()
{
	//~ freopen("a.txt","r",stdin);
	//~ freopen("b.txt","w",stdout);
	std::ios::sync_with_stdio(false);
    double initial;
    int n,t;
    cin>>t;
    double x,y;
    vector<point> arr,hull;
    REP(I,0,t-1)
    {
        cin>>initial>>n;
        REP(i,0,n-1)
        {
            cin>>x>>y;
            arr.push_back(point(x,y));
        }
        if(n==1)
        {
            cout<<fixed;
            cout<<setprecision(5);
            cout<<initial<<endl;
        }
        else if(n==2)
        {
            double x=dist(arr[0],arr[1])*2;
            cout<<fixed;
            cout<<setprecision(5);
            if(x-initial>EPS)
            {
                cout<<x<<"\n";
            }
            else
            {
                cout<<initial<<"\n";
            }
        }
        else
        {
			// see if every point is in one line
			// do other wise
			bool allsame=false,allsameX=true,allsameY=true;
			int X=arr[0].x;
			int Y=arr[0].y;
			REP(i,1,n-1)
			{
				if(X!=arr[i].x)
				{
					allsameX=false;
					break;
				}
			}
			REP(i,1,n-1)
			{
				if(Y!=arr[i].y)
				{
					allsameY=false;
					break;
				}
			}
			allsame=(allsameY|allsameX);
			//~ cout<<allsame<<endl;
			if(allsame==true)
			{
				double MAX=-1;
				REP(j,0,n-1)
				{
					REP(k,0,n-1)
					{
						MAX=max(MAX,dist(arr[j],arr[k]));
					}
				}
				cout<<fixed<<setprecision(5);
				MAX=MAX*2;
				if(MAX-initial>EPS)
				{
					cout<<MAX<<"\n";
				}
				else 
				{
					cout<<initial<<"\n";
				}
			}
            else
            {
				hull=CH(arr);
                double _peri=perimeter(hull);
                //~ cout<<_peri<<endl;
                cout<<fixed;
                cout<<setprecision(5);
                if(_peri-initial>EPS)
                {
                    cout<<_peri<<"\n";
                }
                else
                {
                    cout<<initial<<"\n";
                }
            }
        }
        arr.clear();
        hull.clear();
    }
    return 0;
}
