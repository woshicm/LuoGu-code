#include<iostream>
#include<cmath>
using namespace std;

class tree
{
public:
	char* list;
	int len;
	void create(); 
	char cal(int begin, int end);
};

void tree::create()
{
	int n;
	cin>>n;
	len=pow(2,n);
	list=new char[len+1];
	int i;
	for(i=1;i<=len;i++) cin>>list[i];
	cal(1,len);
}

char tree::cal(int begin, int end)
{
	char temp1,temp2;
	if(begin!=end)
	{
		temp1=cal(begin,(begin+end)/2);
		temp2=cal((begin+end)/2+1,end);
		if(temp1!=temp2||temp1=='F')
		{
			cout<<"F";
			return 'F';
		}
		else if(temp1=='I')
		{
			cout<<"I";
			return 'I';
		}
		else
		{
			cout<<"B";
			return 'B';
		}
	}
	else if(list[begin]=='0')
	{
		cout<<"B";
		return 'B';
	}
	else
	{
		cout<<"I";
		return 'I';
	}
}

int main()
{
	tree qq;
	qq.create();
 	return 0;
}

