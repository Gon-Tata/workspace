#include<bits/stdc++.h>
using namespace std;
const int N=3e6+10;
vector<int> prime;
bool is_prime[N];
void Eratosthenes(int n) {
  is_prime[0] = is_prime[1] = false;
  for (int i = 2; i <= n; ++i) is_prime[i] = true;

  for (int i = 2; i * i <= n; ++i) {
    if (is_prime[i])
      for (int j = i * i; j <= n; j += i) is_prime[j] = false;
  }
  for (int i = 2; i <= n; ++i)
    if (is_prime[i]) prime.push_back(i);
}
int main(){
    freopen("prime.txt","w",stdout);
    int n=(int)(2e6+3e5);
    Eratosthenes(n);
    cerr<<prime.size();
    for(auto k:prime) cout<<k<<",";
}
