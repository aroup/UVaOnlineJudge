//money,fear,hunger
// accepted
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
#define PI acos(-1)
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
    if(collinear(p,q,r)) return true;
    return Cross(toVec(p,q),toVec(p,r))>0;
}
bool ccw2(point p,point q,point r)
{
    if(collinear(p,q,r)) return true;
    return Cross(toVec(p,q),toVec(p,r))>0;
}

double dot(vec a,vec b)
{
    return (a.x*b.x+a.y*b.y);
}

double norm_sq(vec v)
{
    return v.x*v.x+v.y*v.y;
}

double angle(point a,point o,point b)
{
    vec oa=toVec(o,a) ,ob=toVec(o,b);
    return acos(dot(oa,ob)/sqrt(norm_sq(oa)*norm_sq(ob)));
}

bool angleCmp(point a,point b)
{
    if(collinear(pivot,a,b))
    {
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
        //~ if(!(P[0]==P[n-1]))
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
    vector<point>S;
    S.push_back(P[n-1]);
    S.push_back(P[0]);
    S.push_back(P[1]);
    i=2;
    while(i<n)
    {
        j=(int)S.size()-1;
        if(ccw(S[j-1],S[j],P[i]) && !(S[j]==P[i])) S.push_back(P[i++]);
        else S.pop_back();
    }
    return S;
}
double area (const vector<point> &P)
{
    double result=0.0,x1,y1,x2,y2;
    REP(i,0,P.size()-2)
    {
        x1=P[i].x,x2=P[i+1].x;
        y1=P[i].y,y2=P[i+1].y;
        result=result+(x1*y2-x2*y1);
    }
    return fabs(result)/2.0;
}

vec scale(vec v,double s)
{
    return vec(v.x*s,v.y*s);
}

point translate(point p,vec v)
{
    return point (p.x+v.x,p.y+v.y);
}

double distToLine(point p,point a,point b,point &c)
{
    vec ap=toVec(a,p),ab=toVec(a,b);
    double u=dot(ap,ab) / norm_sq(ab);
    c=translate(a,scale(ab,u));
    return dist(p,c);
}

double distToLineSegment(point p,point a,point b,point &c)
{
    vec ap=toVec(a,p),ab=toVec(a,b);
    double u=dot(ap,ab)/norm_sq(ab);
    if(u<0.0) {
        c=point (a.x,a.y);
        return dist(p,a);
    }
    if(u>1.0)
    {
        c=point(b.x,b.y);
        return dist(p,b);
    }
    return distToLine(p,a,b,c);
}

bool inPolygon(point pt,const vector<point> &P)
{
    // in inPolygon test we have to look for 3 qualities,
    // first of all we have to look for if there is a point of edges
    // then we have to look if there is a point on edges
    // then we can check inside the polygon
    //~ if(P.size()==0)
    //~ {
		//~ return false;
	//~ }
    point q;
    REP(i,0,P.size()-1)
    {
		if(pt==P[i])
		{
			return true;
		}
	}
	REP(i,0,P.size()-2)
	{
		if(distToLineSegment(pt,P[i],P[i+1],q)<EPS)
		{
			return true;
		}
	}
    double sum=0;
    REP(i,0,P.size()-2)
    {
        if(ccw(pt,P[i],P[i+1]))
        {
            sum+=angle(P[i],pt,P[i+1]);
        }
        else
        {
            sum-=angle(P[i],pt,P[i+1]);
        }
    }
    return fabs(fabs(sum)-2*PI)<EPS;
}

int main()
{
    //~ freopen("a.txt","r",stdin);
    //~ freopen("b.txt","w",stdout);
    int c,r,o;
    double x,y;
	vector<point>C,R,O;
    vector<point>C_hull,R_hull;
    int testcase=0;

    while(cin>>c>>r>>o)
    {
        if(c==0&&r==0&&o==0) break;
        REP(i,0,c-1)
        {
            cin>>x>>y;
            C.push_back(point(x,y));
        }
        REP(i,0,r-1)
        {
            cin>>x>>y;
			R.push_back(point(x,y));
        }
        REP(i,0,o-1)
        {
            cin>>x>>y;
            O.push_back(point(x,y));
        }
        //~ cout<<C.size()<<" "<<R.size()<<endl;
        if(C.size()!=0)
            C_hull=CH(C);
        if(R.size()!=0)
            R_hull=CH(R);
      //~ cout<<"C hull: ";
        //~ REP(i,0,C_hull.size()-1)
        //~ {
        //~ cout<<"("<<C_hull[i].x<<","<<C_hull[i].y<<"),"<<endl;
        //~ }
		//~ cout<<"R_hull:"<<endl;
		//~ REP(i,0,R_hull.size()-1)
		//~ {
			//~ cout<<R_hull[i].x<<" "<<R_hull[i].y<<endl;
		//~ }
        cout<<"Data set "<<++testcase<<":\n";
        REP(i,0,o-1)
        {
			  bool safe=false;
            //~ bool safe2=false;
            if(inPolygon(O[i],C_hull)&&C_hull.size()>3)
            {
                safe=true;
                cout<<"     Citizen at ("<<O[i].x<<","<<O[i].y<<") is safe.\n";
            }
            if(safe==false)
            {
                if(inPolygon(O[i],R_hull)&&R_hull.size()>3)
                {
                    cout<<"     Citizen at ("<<O[i].x<<","<<O[i].y<<") is robbed.\n";
                }
                else
                {
                    cout<<"     Citizen at ("<<O[i].x<<","<<O[i].y<<") is neither.\n";
                }
            }
        }
        cout<<"\n";
        O.clear();
        C.clear();
        R.clear();
        R_hull.clear();
        C_hull.clear();
    }
    return 0;
}
