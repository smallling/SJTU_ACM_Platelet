#include<cstdio>
char B[1<<22],*S=B,*T=B;
#define getc() (S==T&&(T=(S=B)+fread(B,1,1<<15,stdin),S==T)? EOF : *S++) //n+e�����Ż�
#define R register
//#define getc() getchar() // ����������Ż� 
inline double FastIn1(){
	R char ch=getc();R double cnt=0,ee=1;R bool minus=0,e=0;
	while (ch!='-'&&(ch<'0'||ch>'9')) ch=getc();
	if (ch=='-') minus=1,ch=getc();
	while (ch>='0'&&ch<='9') cnt=cnt*10+ch-'0',ch=getc();
	if (ch=='.') e=1,ee*=0.1,ch=getc();
	while (ch>='0'&&ch<='9'&&e) cnt+=(ch-'0')*ee,ee*=0.1,ch=getc();
	return minus?-cnt:cnt;
}//�������ж���double�͵Ķ����Ż� 
inline int FastIn2(){
	R char ch=getc();R int cnt=0;R bool minus=0;
	while (ch!='-'&&(ch<'0'||ch>'9')) ch=getc();
	if (ch=='-') minus=1,ch=getc();
	while (ch>='0'&&ch<='9') cnt=cnt*10+ch-'0',ch=getc();
	return minus?-cnt:cnt;
}//�������ж���int�͵Ķ����Ż�  
inline long long FastIn3(){
	R char ch=getc();R long long cnt=0;R bool minus=0;
	while (ch!='-'&&(ch<'0'||ch>'9')) ch=getc();
	if (ch=='-') minus=1,ch=getc();
	while (ch>='0'&&ch<='9') cnt=cnt*10+ch-'0',ch=getc();
	return minus?-cnt:cnt;
}//�������ж���long long�͵Ķ����Ż� 
int main()
{
}
