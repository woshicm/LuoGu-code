#include<iostream>
using namespace std;

int main()
{
	int i,j;
	int len,min,temp;
	cin>>len;
	int* list=new int[len];
	for(i=0;i<len;i++) cin>>list[i];
	for(i=0;i<len;i++)
	{
		min=i;
		for(j=i+1;j<len;j++)
		{
			if(list[min]==list[j])
			{
				list[j]=list[len-1];
				len--;
				j--;
				continue;
			}
			if(list[j]<list[min]) min=j;
		}
		temp=list[i];
		list[i]=list[min];
		list[min]=temp;
	}
	cout<<len<<endl;
	for(i=0;i<len;i++) cout<<list[i]<<" ";
 	return 0;
}

