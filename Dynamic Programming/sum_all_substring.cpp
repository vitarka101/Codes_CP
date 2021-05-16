// https://www.hackerrank.com/challenges/sam-and-substrings/problem

#include <bits/stdc++.h>

#define MOD 1000000007
typedef long long ll;
using namespace std;

int substrings(string n) {
    
    //int num = int(n);
    
    ll curr_sum = n[0] - '0';
    ll sum = n[0] - '0';
    
    for(int i=1;i<n.length();i++)
    {
        curr_sum = (curr_sum*10 + (n[i] - '0')*(i+1));
        curr_sum = curr_sum%MOD;
        sum = (sum + curr_sum)%MOD;
        
    }
    return sum;

}

int main()
{
    string n;
    getline(cin, n);

    int result = substrings(n);

    cout << result << "\n";

    return 0;
}

