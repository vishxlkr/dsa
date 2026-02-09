int main(){

    int n , e;

    cin>>n>>e;

    vector<Edge> v(e);

    for(int i = 0; i < e ; i++){
        cin>>v[i].src>>v[i].des>>v[i].wt;
    }

    cout<<f(v,n,e);

    

    return 0;
}