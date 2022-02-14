#include<bits/stdc++.h>
using namespace std;


int main(){
    cout<<"Enter the number of processes\n";
    int n;
    cin>>n;
    vector<vector<int>>process(n,vector<int>(3));
    cout<<"Enter the Arrival and Burst time \n";
    for(int i = 0 ; i < n; ++i ){
        cout<<"process id. "<<i<<" : ";
        cin>>process[i][0]>>process[i][1];
        process[i][2]=i;
    }
    vector<int>completion(n,0);
    sort(process.begin(),process.end());
    int count = 0;
    int clock = 0;
    int i = 0;
    priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
    while(count < n){
        while(i<n and process[i][0]==clock){
            pq.push({process[i][1],process[i][0],process[i][2]});
            i++;
        }
        // cout<<pq.top()[0]<<pq.top()[1]<<pq.top()[2];
        if(!pq.empty()){
            vector<int>current_process = pq.top();
            pq.pop();
            current_process[0]--;
            if(current_process[0]==0){
                count++;
                completion[current_process[2]]=clock+1;
            }else{
                pq.push(current_process);
            }
        }
        clock++;
    }
    cout<<"Process            ";
    for(int i = 0 ; i < n ; ++i){
        cout<<i<<"     ";
    }
    cout<<"\nCompletion Time    ";
    for(int i = 0 ; i < n ; ++i){
        cout<<completion[i]<<"     ";
    }
    cout<<"\nT A  Time          ";
    for(int i = 0 ; i < n ; ++i){
        cout<<completion[i]-process[i][0]<<"     ";
    }
    cout<<"\nWait  Time          ";
    for(int i = 0 ; i < n ; ++i){
        cout<<completion[i]-process[i][0]-process[i][1]<<"     ";
    }
}