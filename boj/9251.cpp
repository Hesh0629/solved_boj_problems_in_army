/*
2020.12.19 D+103
LCS(Longest Common Subsequence) 알고리즘을 이용하여 최장 공통 부분 수열찾기
str1과 str2를 비교하는데 둘이 같으면 arr[i,j]=arr[i-1,j-1]+1 -> 바로 이전 단계 (str1과 str2 1개씩 줄인 상황)
서로 다르다면 arr[i][j]=max(arr[i-1][j],arr[i][j-1]) (위 또는 왼쪽에서 들고옴, <- 바로 이전단계, str1-1 또는 str2-1)

결론: 실수를 줄이자
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int len=0,temp=0;    
    string str1,str2;
    cin>>str1>>str2;
    str1 = "0" + str1;
    str2 = "0" + str2;
    int**arr=new int*[str2.length()];
    for(int i=0;i<str2.length();i++)
        arr[i]=new int[str1.length()];
    for(int i=0;i<str1.length();i++)
        arr[0][i]=0;
    for(int i=1;i<str2.length();i++){
        temp=0; //그리고 반례 A,B 넣으면 답 -1나옴. 이거 덕분에 10분 더 날림
        arr[i][0]=0;
        for(int j=1;j<str1.length();j++){
            if(str1[j]==str2[i]){ //요 중괄호 덕분에 30분날림
                arr[i][j]=arr[i-1][j-1]+1;
                if(arr[i][j]>temp)
                    temp=arr[i][j];
            }
            else
                arr[i][j]=max(arr[i-1][j],arr[i][j-1]);
        }
        if(temp>len)
            len=temp;
    }
    cout<<len<<endl;;
}
