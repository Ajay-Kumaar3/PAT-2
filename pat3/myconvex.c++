
#include <bits/stdc++.h>
using namespace std;

struct P { int x,y; };

int cross(P a,P b,P c){
    return (b.x-a.x)*(c.y-a.y)
         - (b.y-a.y)*(c.x-a.x);
}

double dist(P a,P b){
    return hypot(a.x-b.x,a.y-b.y);
}

int main(){
    int n;
    cin>>n;
    vector<P> p(n),h;

    for(auto &v:p) cin>>v.x>>v.y;

    int s=0;
    for(int i=1;i<n;i++)
        if(p[i].y<p[s].y ||
          (p[i].y==p[s].y && p[i].x<p[s].x))
            s=i;

    int cur=s;
    do{
        h.push_back(p[cur]);
        int nxt=(cur+1)%n;

        for(int i=0;i<n;i++)
            if(cross(p[cur],p[nxt],p[i])<0 ||
              (cross(p[cur],p[nxt],p[i])==0 &&
               dist(p[cur],p[i])>dist(p[cur],p[nxt])))
                nxt=i;

        cur=nxt;
    }while(cur!=s);

    double per=0;
    for(int i=0;i<h.size();i++)
        per+=dist(h[i],h[(i+1)%h.size()]);

    cout<<h.size()<<'\n';
    for(auto v:h) cout<<v.x<<" "<<v.y<<'\n';
    cout<<fixed<<setprecision(2)<<per<<'\n';
}
