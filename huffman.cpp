# include <iostream>
# include <queue>
using namespace std;
priority_queue<int, vector<int>, greater<int> > q;
int main(){
    int n, num, num1, num2, i;
    while(cin>>n){
        while(!q.empty()){
            q.pop();
        }
        for(i=1; i<=n; i++){
            cin>>num;
            q.push(num);
        }
        int ans=0;
        while(q.size()!=1){
            num1=q.top();
            q.pop();
            num2=q.top();
            q.pop();
            ans=ans+num1+num2;
            q.push(num1+num2);
        }
        cout<<ans<<endl;
    }
    return 0;
}
