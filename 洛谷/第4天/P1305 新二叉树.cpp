#include<iostream>
#include<queue>
#include<queue>
using namespace std;

class node
{
public:
	char data;
	node* lc;
	node* rc; 
};

class tree
{
public:
	node* root;	
	void create();
	void display1();
	void display2(node* p);
};

void tree::create()
{
	node* p;
	queue<node*> que;
	int len,n,i,pos=0,flag=1,times;
	cin>>len;
	char** str=new char*[len];
	for(i=0;i<len;i++)
	{
		str[i]=new char[3];
		cin>>str[i];
	}
	times=len;
	while(times--)
	{
		for(i=1;i<len&&!flag;i++)
		{
			if(que.front()->data==str[i][0]) 
			{
				pos=i;
				break;
			}
		}
		if(flag)
		{
			p=new node;
			p->data=str[0][0];
			que.push(p);
			root=p;
			flag=0;
		}
		n=2;
		i=1;
		while(n--)
		{
			if(str[pos][i]=='*')
			{
				if(i==1) que.front()->lc=NULL;
				else que.front()->rc=NULL;
				i++;
				continue;
			}
			p=new node;
			p->data=str[pos][i];
			que.push(p);
			if(i==1) que.front()->lc=p;
			else que.front()->rc=p;
			i++;
		}
		que.pop();
	}
}

void tree::display1()
{
	display2(root);
}

void tree::display2(node* p)
{
	if(p==NULL) ;
	else
	{
		cout<<p->data;
		display2(p->lc);
		display2(p->rc);
	}
}

int main()
{
	tree qq;
	qq.create();
	qq.display1();
 	return 0;
}

