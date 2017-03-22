#include "iostream"
int m[20], p[20];

void handle(int k) {
  int i = 0;
  for (;i<k; i++)
    std::cout<<m[i]<<' '<<p[i]<<' ';
  std::cout<<m[i]<<' '<<p[i]<<std::endl;
}

int main() {
	int k=0, n, s;
	std::cin>>n;
	m[k] = n;
	p[k] = 1;
	handle(k);
	while (p[k]!=n)
	{
	  if (m[k]>1)
	    s = m[k]*p[k]-p[k]-1;
	  else
	  {
	    s = m[k-1]*p[k-1]+p[k]-p[k-1]-1;
	    k--;
	  }
	  if (k>0 && p[k-1]==(p[k]+1))
	    m[k-1]++;
	  else
	  {
	    m[k] = 1;
	    p[k]++;
	    k++;
	  }
	  if(s>0)
	  {
	    m[k] = s;
	    p[k] = 1;
	  }
	  else k--;
	  handle(k);
	}
	return 0;
}
