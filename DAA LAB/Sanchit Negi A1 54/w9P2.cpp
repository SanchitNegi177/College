#include<bits/stdc++.h>
using namespace std;

bool custom(pair<int,int>a,pair<int,int>b)
{
    double r1=(1.0*a.first)/a.second;
    double r2=(1.0*b.first)/b.second;
    
    return r1>r2;
}

int main()
{
    int n;cin>>n;
    vector<int>item(n),weight(n);
    for(auto &it:weight)  cin>>it;
    for(auto &it:item)  cin>>it;
    int cap;cin>>cap;

    vector<pair<int,int>> v(n);
    map<pair<int,int>,int>mp;
    for(int i=0;i<n;i++)   
    {
        v[i]={item[i],weight[i]};
        mp[{item[i],weight[i]}]=i+1;
    } 

    sort(v.begin(),v.end(),custom);

    double profit=0.0;
    vector<pair<int,double>>ans;
    for(auto it:v)
    {
        if(it.second<cap)
        {
            profit+=it.first;
            cap-=it.second;
            ans.push_back({mp[{it.first,it.second}],it.second});
        }
        else
        {
            profit+=it.first*((1.0*cap)/it.second);
            ans.push_back({mp[{it.first,it.second}],cap});
            break;
        }
    }

    
    cout<<"Maximum value: "<<profit<<endl;
    cout<<"item-weight"<<endl;
    for(auto it:ans)
        cout<<"Item " <<it.first<<" - "<<it.second<<endl;

    return 0;
}

