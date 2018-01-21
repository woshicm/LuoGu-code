#include<iostream>
using namespace std;

int compare(string a, string b)
{
	int i;
	for(i=0;i<a.length();i++)
		if(a[i]-b[i]>0) return 0;
		else if(a[i]-b[i]<0) return 1;
}
int cal(string* list, int len)
{
	int i;
	int max=0;
	for(i=1;i<len;i++)
	{
		if(list[max].length()<list[i].length()) max=i;
		else if(list[max].length()==list[i].length()&&compare(list[max],list[i])) max=i;
	}
	return max;
}

int main()
{
	int len;
	cin>>len;
	string* list=new string[len];
	int i,j;
	for(i=0;i<len;i++) cin>>list[i];
	int pos=cal(list,len);
	cout<<pos+1<<endl<<list[pos]<<endl;
 	return 0;
}

