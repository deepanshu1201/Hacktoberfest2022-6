


#include<iostream>
#include<vector>
#include<map>
#include<list>
#include<set>
#include<algorithm>
#include<queue>
#include<stack>
#include<cstring>
#include<cmath>
#include<string>
#include<unordered_set>
#include<unordered_map>
#include<cstdlib>
using namespace std;

/*int main(){
    vector <int> tvSets;
    int n,m,in,res=0;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin >> in;
        tvSets.push_back(in);
    }
    sort(tvSets.begin(), tvSets.end());
    for(int i=0; i<m;i++){
       res=res+(tvSets[i] * -1);
    }
    cout << res;
    return 0;
}*/
int main()
{
    int n, m, a[100];
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    sort(a, a + n);

    int s(0);
    for (int i = 0; i < m; ++i)
    {
        if (a[i] >= 0)
        {
            break;
        }
        s += a[i];
    }
    cout << -s << endl;
    return 0;
}