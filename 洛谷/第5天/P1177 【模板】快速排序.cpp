#include<iostream>
#include<stdlib.h>
#include<time.h> 
using namespace std;

int judge(int* list, int len)
{
	int i;
	for(i=len-1;i>0;i--)
		if(list[i]<list[i-1]) return 0;
	return 1;
}

void fast_sort(int* list, int begin, int end) 
{
	srand(time(NULL));
    if(begin>end) return;
    int i=begin,j=end;
    int pioneer=rand()%(end-begin+1)+begin;
    int temp=list[pioneer];
	list[pioneer]=list[i];
    list[i]=temp;
    while(i<j)
    {
        while(list[j]>=temp&&i<j) j--;
        list[i]=list[j];
        while(list[i]<=temp&&i<j) i++;
        list[j]=list[i];
    }
    list[i]=temp;
	fast_sort(list,begin,i-1);
    fast_sort(list,i+1,end);
}

int main()
{
    int len;
    cin>>len;
    int* list=new int[len];
    for(int i=0;i<len;i++) cin>>list[i];
    if(!judge(list,len)) fast_sort(list,0,len-1);
  //  else cout<<"yes"<<endl;
    for(int i=0;i<len;i++) cout<<list[i]<<" ";
 	return 0;
}
