//단순한 다익스트라 구현문제. 이론처럼 priority queue에 다 넣고 순서조정하지말고 *BFS* 처럼 처리하기

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int main() {
    int v,e,start;
    cin>>v>>e;
    cin>>start;
    vector<pair<int,int>>map[v]; // 그래프 저장용 <node_number, dist>
    vector<int>dist(v,2000000); //  각 노드별 출발점으로 부터의 거리 저장
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq; // <cost,node_number>
    for(int i=0;i<e;i++){
        int st,ed,dist;
        cin>>st>>ed>>dist;
        map[st-1].push_back({ed-1,dist});
    }
    dist[start-1]=0;
    pq.push({0,start-1});
    while(!pq.empty()){
        int cost=pq.top().first;
        int cur=pq.top().second;
        pq.pop();
        for(auto i:map[cur]){
             if(dist[i.first]> cost+i.second){
                  dist[i.first]=cost+i.second;
                  pq.push({dist[i.first],i.first}); //경로 최신화가 이루어진 노드에 한해서 pq에 푸시
             }
        }
    }
    for(auto i:dist){
        if(i==2000000)
            cout<<"INF\n";
        else
            cout<<i<<"\n";
    }
}
