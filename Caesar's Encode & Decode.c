#include <stdio.h> 
#include <ctype.h>
#include <conio.h>
//#include <string>
//using namespace std;

char movec(const char c, const int bit){
	if('a'<=c&&c<='z'){
		int x=c-'a'+1;
		char *a="zabcdefghijklmnopqrstuvwxy";
		x+=bit;
		x%=26;
		return a[x];
	}
	else if('A'<=c&&c<='Z'){
		int X=c-'A'+1;
		char *A="ZABCDEFGHIJKLMNOPQRSTUVWXY";
		X+=bit;
		X%=26;
		return A[X];
	}
	else if('0'<=c&&c<='9'){
		int n=c-'0';
		n+=bit;
		n%=10;
		return n+'0';
	}
	else return c;
}

void UnCaesar(const char *s){
	int i,j;
	int times=NOALPHAORDIGIT(s)?1:(isNumOnly(s)?10:(isAlphaOnly(s)?26:130));
	for(j=1;j<=times;j++){
		printf("��%s%d �γ��ԣ�",((0<=j&&j<=99)?((0<=j&&j<=9)?" 00":" 0"):" "),j);
		for(i=0;i<strlen(s);i++)
			printf("%c",movec(s[i],j));
		printf("\n");
	}
}

int isNumOnly(const char *s){
	int i;
	for(i=0;i<strlen(s);i++){
		if(isalpha(s[i])) return 0;
	}
	return 1;
}

int isAlphaOnly(const char *s){
	int i;
	for(i=0;i<strlen(s);i++){
		if(isdigit(s[i])) return 0;
	}
	return 1;
}

int NOALPHAORDIGIT(const char *s){
	int i;
	for(i=0;i<strlen(s);i++){
		if(isalpha(s[i])||isdigit(s[i])) return 0;
	}
	return 1; 
}

int main(){
	char str[1024]=" ";
	int bit;
	printf("��������ܻ�����ַ�����");
	scanf("%s",str);
	while(!('q'==str[0]&&1==strlen(str))){
		UnCaesar(str);
		printf("\n");
		getch();
		printf("��������ܻ�����ַ�����");
		scanf("%s",str);
	}
	getch();
}