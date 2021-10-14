#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
double number(char str[]){
    char S[1];
    strncpy(S, str + 0, 0);
    char E[8];
    strncpy(E, str + 1, 8);
    char M[23];
    strncpy(M, str + 9, 22);
    int frac = 0;
    for(int i = 0;i<strlen(E);i++)
    {
        if(E[i] == '1')
        {
            frac = frac*2 + 1;
        }
        else
        {
            frac = frac*2 + 0;
        }
    }
    
    double expnt = 0;
    for(int i = 0;i<strlen(M);i++)
    {
        if(M[i] == '1')
        {
            expnt += 1*(pow(2,-i-1));
        }
    }
    int sign = 1;
    if(str[0] == '1'){
        sign = -1;
    }
    double exp = 1+expnt;
    double ten = pow(2,frac-127);
    double ans = sign*exp*ten;
	return ans;
	
}
int…
[12:05, 10/13/2021] Hrudai Koda: arey aa r1/r2 varaku iyyindhi
[12:05, 10/13/2021] Hrudai Koda: next aa 32bit representation yelano telidu ra
[12:53, 10/13/2021] Hrudai Koda: #include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
double number(char str[]){
    char S[1];
    strncpy(S, str + 0, 0);
    char E[8];
    strncpy(E, str + 1, 8);
    char M[23];
    strncpy(M, str + 9, 22);
    int frac = 0;
    for(int i = 0;i<strlen(E);i++)
    {
        if(E[i] == '1')
        {
            frac = frac*2 + 1;
        }
        else
        {
            frac = frac*2 + 0;
        }
    }
    
    double expnt = 0;
    for(int i = 0;i<strlen(M);i++)
    {
        if(M[i] == '1')
        {
            expnt += 1*(pow(2,-i-1));
        }
    }
    int sign = 1;
    if(str[0] == '1'){
        sign = -1;
    }
    double exp = 1+expnt;
    double ten = pow(2,frac-127);
    double ans = sign*exp*ten;
	return ans;
	
}
int main(){
    int a = 0x42200000;
    char b[32];
    itoa(a,b,2);
    char op[] = "0";
    strcat(op,b);
    double first = number(op);

    int a_1  = 0xC1200000;
    char b_1[32];
    itoa(a_1,b_1,2);
    double second = number(b_1);
    printf("%lf\n",first/second);
    double answ = first/second;
    char msb[2];
    double result;
    if(answ >= 0){
        result = answ;
        strcpy(msb,"0");
    }else{
        result = answ*-1;
        strcpy(msb,"1");
    }
    printf("%s",msb);
    char b_2[10];
    
    itoa(result,b_2,2);
    int exp = strlen(b_2) - 1 + 127;
    char b_3[23];
    itoa(exp,b_3,2);
    printf("%s",b_3);
    char manti[23];
    strncpy(manti,b_2+1,strlen(b_2));
    printf("%s",manti);
    int len = strlen(manti);
    while(len<23){
        printf("0");
        len++;
    }
    
}
