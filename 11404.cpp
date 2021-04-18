//단순한 다익스트라 구현문제. 이론처럼 priority queue에 다 넣고 순서조정하지말고 *BFS* 처럼 처리하기

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int main() {
    int n,m;
    cin>>n>>m;
    vector<pair<int,int>>map[n]; // 그래프 저장용 <node_number, dist>
    for(int i=0;i<m;i++){
        long long int st,ed,dist;
        cin>>st>>ed>>dist;
        map[st-1].push_back({ed-1,dist});
    }
    for(int start=0;start<n;start++){
        vector<long long int>dist(n,999999999999); //  각 노드별 출발점으로 부터의 거리 저장
        priority_queue<pair<long long int,int>,vector<pair<long long int,int>>,greater<pair<long long int,int>>>pq;
        dist[start]=0;
        pq.push({0,start});
        while(!pq.empty()){
            long long int cost=pq.top().first;
            int cur=pq.top().second;
            pq.pop();
            for(auto i:map[cur]){
                if(dist[i.first]> cost+i.second){
                    dist[i.first]=cost+i.second;
                    pq.push({dist[i.first],i.first}); //경로 최신화가 이루어진 노드에 한해서 pq에 푸시
                }
            }  
        }
        for(auto j:dist){
            if(j==999999999999)
                cout<<0<<" "; //이거땜에 2번 틀림. 출력 양식 지키자
            else
                cout<<j<<" ";
        }
        cout<<'\n';
    }
}
