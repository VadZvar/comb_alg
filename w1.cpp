#include "iostream"

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

int main()
{
  unsigned long long a = 0;
  int w;
  char s[64];
  char *c = s;
  std::cin>>s;
  while(*c)
  {
    a <<=1;
    if (*c=='1')
      a += 1;
    c++;
  }
  std::cout<<weight(a)<<std::endl;
}