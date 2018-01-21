#include<iostream>
using namespace std;

class tree
{
public:
	char* pre;
	string in;
	string post;
	int len;
	int counter;
	void create();
	void cal(int begin_in, int end_in, int begin_post, int end_post);
	void display(); 
};

void tree::create()
{
	counter=0;
	cin>>in>>post;
	len=in.length();
	pre=new char[len];
	cal(1,len,1,len);
	display();
};

void tree::cal(int begin_in, int end_in, int begin_post, int end_post)
{
	if(end_in<begin_in||end_in>len||begin_in<1) return;
	pre[counter++]=post[end_post-1];
	if(end_in==begin_in) return;
	int i;
	for(i=begin_in-1;i<end_in;i++)
	{
		if(in[i]==post[end_post-1])
		{
			cal(begin_in,i,begin_post,begin_post+i-begin_in);
			cal(i+2,end_in,end_post-1-end_in+(i+2),end_post-1);
			break;
		}
	}
} 

void tree::display()
{
	int i;
//	for(i=0;i<len;i++) cout<<pre[i];
	cout<<pre;
	cout<<endl;
}

int main()
{
	tree qq;
	qq.create();
 	return 0;
}

