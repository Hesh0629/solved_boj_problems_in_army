#include<iostream>
#include<algorithm>
#include<deque>
using namespace std;
int main(){
    int n,k,m;
    cin>>n>>k>>m;
    deque<int>q;
    for(int i=1;i<=n;i++){
        q.push_back(i);
    }
    int cnt=1,cnt2=0,total=n,flag=1;
    while(q.size()){
        if(flag){
            if(cnt==k){
                cout<<q.front()<<'\n';
                q.pop_front();
                cnt=1;
                cnt2++;
                if(cnt2==m){
                    flag=0;
                    cnt2=0;
                }
            }
            else{
                q.push_back(q.front());
                q.pop_front();
                cnt++;
            }    
        }
        else{
            if(cnt==k){
                cout<<q.back()<<'\n';
                q.pop_back();
                cnt=1;
                cnt2++;
                if(cnt2==m){
                    flag=1;
                    cnt2=0;
                }
            }
            else{
                q.push_front(q.back());
                q.pop_back();
                cnt++;
            }    
        }
    }
    return 0;
}
