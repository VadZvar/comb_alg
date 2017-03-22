#include "iostream"

void number(int* s, int n) {
	int i, j, k;
	unsigned long long int f, sum=1;
	for(i=0; i<n-1; i++) {
		f = 1;
		k = 0;
		for(j=0; j<i; j++) if(s[j]<s[i]) k++;
		for(j=2; j<n-i; j++) f *= j;
		sum += (s[i]-1-k)*f;
	}
	std::cout<<sum<<std::endl;
}

int main() {
	int i=0, n;
	std::cin>>n;
	int s[n];
	for(; i<n; i++) std::cin>>s[i];
	number(s, n);
	return 0;
}
