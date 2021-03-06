#include <iostream>
#include <vector>

using std::vector;

int lcs2(vector<long long> &a, vector<long long> &b) {
  vector<vector<long long>> dp(a.size()+1,vector<long long>(b.size()+1,0));
/*  for(int i=0;i<=a.size();i++){
    dp[i][0]=0;
  }
 
  for(int i=0;i<=b.size();i++){
    dp[0][i]=0;
  }*/
for(int i=1;i<=a.size();i++){
  for(int j=1;j<=b.size();j++){
          if(a[i-1]==b[j-1]){
            dp[i][j]=dp[i-1][j-1]+1;
          }else{dp[i][j]=std::max(dp[i-1][j],dp[i][j-1]);}
  }
}return dp[a.size()][b.size()];
}

int main() {
  size_t n;
  std::cin >> n;
  vector<long long> a(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> a[i];
  }

  size_t m;
  std::cin >> m;
  vector<long long> b(m);
  for (size_t i = 0; i < m; i++) {
    std::cin >> b[i];
  }

  std::cout << lcs2(a, b) << std::endl;
}
