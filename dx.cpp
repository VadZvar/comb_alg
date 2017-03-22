 #include "iostream"

void pr(char* s) {
	int i=0;
	while (s[i+1]!=0) {
		std::cout<<s[i]<<" ";
		i++;
	}
	std::cout<<s[i]<<std::endl;
}

int main() {
	int i, j, n, tmp, l, r;
	std::cin>>n;
	char s[n+1];
	s[n] = 0;
	for(i=0; i<n; i++) s[i]=i+0x31;
	i = n-2;
	while (i>=0) {
		pr(s);
		j = n-1;
		while(s[i]>s[j]) j--;
		tmp = s[i]; 
		s[i] = s[j];
		s[j] = tmp;
		l = i+1;
		r = n-1;
		while(l<r) {
			tmp = s[l];
			s[l] = s[r];
			s[r] = tmp;
			l++; r--;
		}
		i = n-2;
		while(i>=0 && s[i]>s[i+1]) i--;
	}
	pr(s);
	retutn 0;
}
