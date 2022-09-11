#include <cstdio>
#include <vector>
#include <stack>
#include <algorithm>
#define N 10000
using namespace std;

int cnt, scc_cnt;
int visit[N+1], mark[N+1], scc_number[N+1];
vector<vector<int>> scc;
vector<int> graph[N+1];
stack<int> s;

int DFS(int cur)
{
    s.push(cur);
    visit[cur] = ++cnt;
    int parent = visit[cur];
    
    for(int next : graph[cur]){
        if(!visit[next]) parent = min(parent, DFS(next));
        else if(!mark[next]) parent = min(parent, visit[next]);
    }
    
    if(parent == visit[cur]){
     
        vector<int> v;
        scc_cnt++;
        
        while(true){
          int tmp = s.top(); s.pop();
            v.push_back(tmp);
            scc_number[tmp] = scc_cnt;
            mark[tmp] = 1;
            
            if(tmp==cur) break;
        }
        
        scc.push_back(v);
    }
    
    return parent;
}

bool comp1(int a, int b){
    if(a>b) return false;
    return true;
}

bool comp2(vector<int> a, vector<int> b){
    if(a[0]>b[0]) return false;
    return true;
}

int main(void)
{
    int i, v, e, a, b;
    scanf("%d %d", &v, &e);
    
    for(i=0; i<e; i++){
        scanf("%d %d", &a, &b);
        graph[a].push_back(b);
    }
    
    for(i=1; i<=v; i++)
        if(!visit[i]) DFS(i);
        
    for(i=0; i<(int)scc.size(); i++)
        sort(scc[i].begin(), scc[i].end(), comp1);
    sort(scc.begin(), scc.end(), comp2);

    printf("%d\n", scc.size());

    for(i=0; i<(int)scc.size(); i++){
        vector<int> v = scc[i];

        for(int j=0; j<(int)v.size(); j++){
            printf("%d ", v[j]);
        }
        printf("-1\n");
    }
    
    return 0;
}