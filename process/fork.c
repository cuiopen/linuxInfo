#include <unistd.h>  
#include <stdio.h>  
#include <stdlib.h>
FILE* stream;
int main(void)  
{  
   int m=0;
   int i=0; 
  stream = fopen("1.xlsx","a+");   
   printf("i son/parent    ppid    pid  \n");  
   //ppidָ��ǰ���̵ĸ�����pid  
   //pidָ��ǰ���̵�pid,  
   //fpidָfork���ظ���ǰ���̵�ֵ  
   for(i=0;i<4;i++){  
       pid_t fpid=fork(); 	   
       if(fpid==0){		
			printf("%d child  	%4d 	%4d \n",i,getppid(),getpid());     
	   }else{  	
			printf("%d parent 	%4d 	%4d \n",i,getppid(),getpid());  
	   }
   }  

   return 0;  
} 

