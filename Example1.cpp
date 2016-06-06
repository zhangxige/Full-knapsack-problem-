#include<stdio.h>  
#include<stdlib.h>  
#include<iostream>  
#include<queue>  
#include<climits>  
#include<cstring>  
using namespace std;  
const int c = 10;             //背包的容量  
int w[] = {5, 4, 6, 3};//物品的重量，其中0号位置不使用 。   
int v[] = {10, 40, 30, 50};//物品对应的待加，0号位置置为空。  
const int n = sizeof(w)/sizeof(w[0])  ; //n为物品的个数  
int x[n+1]; 

int findM(int N,int K,int G[],int W[])
{    int *M=new int[N+1],i,j,k;   
      for(i=0;i<N+2;i++)
          M[i]=0;
      for(i=0;i<K;i++)
      {        
          for(j=N;j>=G[i];j--)
               {            
                   for(k=1;j-k*G[i]>=0;k++)
                       {
                          M[j]=M[j]>k*W[i]+M[j-k*G[i]]?M[j]:k*W[i]+M[j-k*G[i]];   
                        }    
               } 
       }  
           return M[N];
}

int main(){               
	cout<<findM(c,n,w,v)<<endl;   
	system("pause");
    return 0;
}
