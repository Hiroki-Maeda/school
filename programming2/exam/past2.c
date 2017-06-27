#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct seiseki{
		 char name[10];
		 int eigo;
		 int sugaku;
		 double ave;
}LIST;

void quick_sd(LIST sk[],int left,int right);
void quick_sc(LIST sk[],int left,int right);
void input(LIST sk[],int *nmax);
void heikin(LIST sk[],int nmax);
void output(LIST sk[],int nmax);
void kensaku(char *who,LIST sk[],int nmax,int result[],int *n_result);

int main(void)
{
LIST sk[30];
int nmax=0;
char who[10];
int result[10];
int n_result;
int i;

input(sk,&nmax);
heikin(sk,nmax);
quick_sd(sk,0,nmax-1);
printf("%d\n",nmax);
for(i=0;i<=nmax-1;i++) printf("%s %f\n",sk[i].name,sk[i].ave);

printf("Whose grade do you want to know? \n");
scanf("%s",who);
    output(sk,nmax);
quick_sc(sk,0,nmax-1);
n_result=0;
kensaku(who,sk,nmax,result,&n_result);
if(n_result>=0)
{
for(i=0;i<=n_result;i++)
{
printf("Average of %s = %2.2f \n",sk[result[i]].name,sk[result[i]].ave);
}
}
else printf("nodody\n");
return(0);
}

void quick_sd(LIST sk[],int left,int right)
{
int i,j;
LIST temp;
LIST pivot;
i=left;
j=right;
pivot=sk[(left+right)/2];
while(1)
{
while(sk[i].ave>pivot.ave) i++;
while(pivot.ave>sk[j].ave) j--;
if(i>=j) break;
temp=sk[i];
sk[i]=sk[j];
sk[j]=sk[i];
i++;
j--;
}
if(left<i-1) quick_sd(sk,left,i-1);
if(j+1<right) quick_sd(sk,j+1,right);
}

void quick_sc(LIST sk[],int left,int right)
{
int i,j;
LIST temp;
LIST pivot;
i=left;
j=right;
pivot=sk[(left+right)/2];
while(1)
{
while(strcmp(sk[i].name,pivot.name)<0) i++;
while(strcmp(pivot.name,sk[j].name)<0) j--;
if(i>=j) break;
temp=sk[i];
sk[i]=sk[j];
sk[j]=temp;
i++;
j--;
}
if(left<i-1) quick_sc(sk,left,i-1);
if(j+1<right) quick_sc(sk,j+1,right);
}

void heikin(LIST sk[],int nmax)
{
int i;
for(i=0;i<=nmax-1;i++) sk[i].ave=(sk[i].eigo+sk[i].sugaku)/2.0;
}

void kensaku(char *who,LIST sk[],int nmax,int result[],int *n_result)
{
int lowerbound;
int upperbound;
int middle;
int hit;
int temp;
lowerbound=0;
upperbound=nmax-1;
hit=-1;

while(lowerbound<=upperbound)
{
middle=(lowerbound+upperbound)/2;
if(strcmp(who,sk[middle].name)==0)
{
 hit=middle;
printf("%d\n",hit);
break;
}
else if(strcmp(who,sk[middle].name)<0) upperbound=middle-1;
else lowerbound=middle+1;
}
if(hit!=-1)
{
*n_result=0;
result[*n_result]=hit;
temp=hit;
while(temp<nmax-1)
{
temp+=1;
if(strcmp(sk[temp].name,who)==0)
{
*n_result+=1;
result[*n_result]=temp;
}
else break;
}
temp=hit;
while(temp>0)
{
temp-=1;
if(strcmp(sk[temp].name,who)==0)
{
*n_result+=1;
result[*n_result]=temp;
}
else break;
}
}
else *n_result=-1;
}

void input(LIST sk[],int *nmax)
{
FILE *fpi;
char infile[20];
printf("Write the name of input date file\n");
scanf("%s",infile);
if((fpi=fopen(infile,"r"))==NULL)
{
printf("error at file\n");
exit(1);
}
while(fscanf(fpi,"%s %d %d",&sk[*nmax].name,&sk[*nmax].eigo,&sk[*nmax].sugaku)!=EOF)
{
(*nmax)++;
}
fclose(fpi);
}

void output(LIST sk[],int nmax)
{
FILE *fpo;
char outfile[20];
int i;
printf("Write the name of output date file\n");
scanf("%s",outfile);
if((fpo=fopen(outfile,"w"))==NULL)
{
printf("error at file\n");
exit(1);
}
for(i=0;i<=nmax-1;i++) fprintf(fpo,"%12s\t%2.2f\t\n",sk[i].name,sk[i].ave);
fclose(fpo);
}
