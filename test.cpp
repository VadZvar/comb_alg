#include "iostream"

void sort(int n, char* s) {
	int i=0, j=0;
	char tmp;
	for (;i<(n/2);i++) {
	  tmp = s[i];
	  s[i] = s[n-1-i];
	  s[n-1-i] = tmp;
	}
};

void pr(char* s) {
	int i=0;
	while (s[i+1]!=0) {
		std::cout<<s[i]<<" ";
		i++;
	}
	std::cout<<s[i]<<std::endl;
}

int antilex(int m, char* s) {
	char tmp;
	if (m == 2) {
// 		std::cout<<s<<std::endl;
		pr(s);
		tmp = s[0];
		s[0] = s[1];
		s[1] = tmp;
// 		std::cout<<s<<std::endl;
		pr(s);
		return 0;
	}
	for (int i = 0; i<m-1; i++) {
		antilex(m-1, s);
		tmp = s[i];
		s[i] = s[m-1];
		s[m-1] = tmp;
		sort(m-1, s);
	}
	antilex(m-1, s);
	return 0;
};

int main() {
	int m, i;
	std::cin>>m;
	if (m==1) {std::cout<<"1"<<std::endl; return 0;}
	char s[m+1];
	s[m] = 0;
	for (i = 0; i<m; i++) s[i] = i+0x31;
	antilex(m,s);
	return 0;
} 
