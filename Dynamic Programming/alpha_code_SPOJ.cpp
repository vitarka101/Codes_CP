#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll m = 1000000000 + 7;

ll num_code_iter(ll *arr,ll n)
{
        ll *output = new ll[n+1]();

        // 0 , 1,2,3.... are all lengths
        output[0] = 1;
        output[1] = 1;

        for(int i=2;i<=n;i++)
        {
            if(arr[i-1] != 0)
                output[i] = output[i-1] % m;
               // since we are decreasing the size from the end
               if( arr[i-2]*10 + arr[i-1] >=10  &&  arr[i-2]*10 + arr[i-1] <= 26)
                output[i] = (output[i] + output[i-2]) %  m;
        }

        ll op = output[n];

        delete [] output;

        return op;
}



int main()
{
    
    while(cin)
    {
        string n;
        cin>>n;
        
        if(n=="0")
            break;
        
    	ll *input = new ll[n.size()]();
        
        
        for(int i=0;i<n.size();i++)
        input[i] = n[i] - '0';
        
        cout<<num_code_iter(input,n.size())<<endl;
    }

    // i is the total number of elements in input
    
    return 0;
}

