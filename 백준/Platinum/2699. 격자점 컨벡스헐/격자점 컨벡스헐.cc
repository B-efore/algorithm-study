#include <cstdio>
#include <vector>
#include <stack>
#include <algorithm>
#define N 50
using namespace std;

struct point{
    int x;
    int y;
};

vector<point> g;

long long ccw(point a, point b, point c){
    return (a.x*b.y + b.x*c.y + c.x*a.y - b.x*a.y - c.x*b.y - a.x*c.y);
}

bool comp1(point a, point b){
    
    if(a.y>b.y) return false;
    else if(a.y==b.y && a.x>b.x) return false;
    return true;
}

bool comp2(point a, point b){
    long long val = ccw(g[0], a, b);
    
    if(val) return (val>0);
    else if(a.y!=b.y) return a.y<b.y;
    else return a.x<b.x;
}

int main(void)
{
    int p;
    scanf("%d", &p);
    
    while(p--){
        
        g.clear();
        
        int n, x, y;
        scanf("%d", &n);
        
        g.resize(n);
        for(int i=0; i<n; i++){
            scanf("%d %d", &x, &y);
            g[i].x = x;
            g[i].y = -y;
        }
        
        sort(g.begin(), g.end(), comp1);
        sort(g.begin()+1, g.end(), comp2);
        
        point tmp1, tmp2;
        stack<point> s;
        s.push(g[0]); s.push(g[1]);
 
        for(int i=2; i<n; i++){
            while(s.size()>=2){
                tmp2 = s.top(); s.pop();
                tmp1 = s.top();
                
                if(ccw(tmp1, tmp2, g[i])>0){
                    s.push(tmp2);
                    break;
                }
            }
            s.push(g[i]);
        }
        
        stack<point> ans;
        while(!s.empty()){
            tmp1 = s.top(); s.pop();
            ans.push(tmp1);
        }
        
        printf("%d\n", (int)ans.size());
        while(!ans.empty()){
            tmp2 = ans.top(); ans.pop();
            printf("%d %d\n", tmp2.x, -tmp2.y);
        }
    }
}