#include "iostream"

char tab[16] = {0,1,1,2,1,2,2,3,1,2,2,3,2,3,3,4};

int weight(unsigned long long a) 
{
  int w = 0;
  char b;
  unsigned long long x = a;
  while(x!=0) {
    b = (char)x&15;
    x >>= 4;
    w += tab[b];
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

