#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; cin>>n;
    vector<vector<int>>a(n,vector<int>(3));
    for(int i = 0 ; i < n ; ++i){
        a[i][1]=i+1;
        cin>>a[i][0]>>a[i][2];
    }
    int tq;
    cin>>tq;

    sort(a.begin(),a.end());
    queue<vector<int>>ready,running;
    int clk=0;
    int i=1;
    vector<int> t;
    // bool ongoing = false;
    ready.push(a[0]);
    while(i<n or !ready.empty()){
        // if(!ongoing){
        //     t = ready.front();
            
        // }else{

        // }

        t = ready.front();
        if(t[0]<=clk){  
            ready.pop();
            if(t[2]<tq){
                running.push({t[1],clk,clk+t[2]});
                clk+=t[2];
            }else{
                running.push({t[1],clk,clk+tq});
                if(t[2]>tq){
                    while( i<n  and a[i][0]<=clk+tq){
                        ready.push(a[i]);
                        i++;
                    }
                    ready.push({t[0],t[1],t[2]-tq});
                }
                clk+=tq;
            }
        }
        else{
            clk++;
        }
        // clk++;
    }
    while(!running.empty()){
        t=running.front();
        running.pop();
        for (auto x : t ){
            cout<<x<<" ";
        }
        cout<<endl;
    }

}