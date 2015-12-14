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
    if(n<3)
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

int main()
{
	int n;
	double x,y;
	vector<point> arr,Hull,V;
	vector<point> C;
	vector<double>A;
	double TA;
	while(cin>>n&&n>=3)
	{
		REP(i,0,n-1)
		{
			cin>>x>>y;
			arr.push_back(point(x,y));
		}
		Hull=CH(arr);
		Hull.pop_back();
		TA=0;
		REP(i,1,n-2)
		{
			V.push_back(Hull[0]);
			V.push_back(Hull[i]);
			V.push_back(Hull[i+1]);
			V.push_back(Hull[0]);
			TA=TA+area(V);
			A.push_back(area(V));
			C.push_back(point((Hull[0].x+Hull[i].x+Hull[i+1].x)/3.00,(Hull[0].y+Hull[i].y+Hull[i+1].y)/3.00));
			V.clear();
		}
		double Cx=0,Cy=0;
		REP(i,0,C.size()-1)
		{
			Cx=Cx+(C[i].x*A[i]);
			Cy=Cy+(C[i].y*A[i]);
		}
		cout<<fixed;
		cout<<setprecision(3);
		cout<<Cx/TA<<" "<<Cy/TA<<"\n";
		
		C.clear();
		V.clear();
		A.clear();
		arr.clear();
		Hull.clear();
	}
	return 0;
}
