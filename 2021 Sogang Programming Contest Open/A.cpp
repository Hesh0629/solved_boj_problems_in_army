#include<bits/stdc++.h>
using namespace std;
string s;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin>>s;
  for(auto i:s){
    if(i=='A'||i=='K'||i=='M'||i=='O'||i=='T') cout<<(char)(i+32);
    else if(i=='B')cout<<"v";
    else if(i=='E')cout<<"ye";
    else if(i=='H')cout<<"n";
    else if(i=='P')cout<<"r";
    else if(i=='C')cout<<"s";
    else if(i=='Y')cout<<"u";
    else if(i=='X')cout<<"h";
  }
  return 0;
}
