#include <bits/stdc++.h>
using namespace std;

struct P{
    double x,y;
};

struct S{
    P a,b;
};

int main(){
    int n;
    cin>>n;
    vector<S> s(n);

    for(auto &v:s){
        cin>> v.a.x >> v.a.y >> v.b.x >> v.b.y;
    }

    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            double x1 = s[i].a.x;
            double y1 = s[i].a.y;
            double x2 = s[i].b.x;
            double y2 = s[i].b.y;
            double x3 = s[j].a.x;
            double y3 = s[j].a.y;
            double x4 = s[j].b.x;
            double y4 = s[j].b.y;

            double d = (x1-x2)*(y3-y4)-(y1-y2)*(x3-x4);
            if(abs(d) < 1e-9) continue;

            double x = ((x1*y2-y1*x2)*(x3-x4)-(x1-x2)*(x3*y4-y3*x4))/d;
            double y = ((x1*y2-y1*x2)*(y3-y4)-(y1-y2)*(x3*y4-y3*x4))/d;

            if(x>=min(x1,x2) && x<=max(x1,x2) &&
               x>=min(x3,x4) && x<=max(x3,x4) &&
               y>=min(y1,y2) && y<=max(y1,y2) &&
               y>=min(y3,y4) && y<=max(y3,y4)){
                cout<<"Collision Detected\n";
                cout<<fixed<<setprecision(2)<<x<<" "<<y;
                return 0;
               }
        }
        
    }
    cout<<"clear\n";
}