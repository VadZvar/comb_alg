#include "iostream"

int n, k;
unsigned long long b = 0, d = 0;

int weight(unsigned long long a) 
{
  int w = 0;
  unsigned long long x = a;
  while(x!=0) {
    x &= x-1;
    w++;
  }
  return w;
}

void handle()
{
  int x = 1;
  unsigned long long tmp;
  for(;x<=n;x++){
    tmp = (unsigned long long)1<<(n-x);
    if(b&tmp) std::cout<<x<<" ";
  }
  std::cout<<std::endl;
}

int main()
{
  unsigned long long w;
  unsigned long long c;
  std::cin>>n>>k;
  d = (((unsigned long long)1)<<k)-1;
  b = d<<(n-k);
  handle();
  while(b!=d) {
    c = (b+1)&b;
    w = weight((c-1)^b)-2;
    b = (((((b+1)^b)<<1)+1)<<w)^c;
    handle();
  }
  return 0;
}