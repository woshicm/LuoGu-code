#include<iostream>
using namespace std;

class person
{
public:
	int id;
	int grade;
};

void order(person* list, int len)
{
	int i,j;
	int min;
	person temp;
	for(i=0;i<len-1;i++)
	{
		for(j=0;j<len-i-1;j++)
		{
			if(list[j].grade<list[j+1].grade)
			{
				temp=list[j];
				list[j]=list[j+1];
				list[j+1]=temp;
			}
			else if(list[j].grade==list[j+1].grade)
			{
				if(list[j].id>list[j+1].id)
				{
					temp=list[j];
					list[j]=list[j+1];
					list[j+1]=temp;	
				}
			}
		}
	}
}

int main()
{
	int len,aim,accepted_grade,accepted_num;
	cin>>len>>aim;
	person* list=new person[len];
	int i;
	for(i=0;i<len;i++) cin>>list[i].id>>list[i].grade;
	order(list,len);
	accepted_num=aim*1.5;
	accepted_grade=list[accepted_num-1].grade;
	i=accepted_num-1;
	while(list[++i].grade==accepted_grade) accepted_num++;
	cout<<accepted_grade<<" "<<accepted_num<<endl;
	for(i=0;i<accepted_num;i++)
		cout<<list[i].id<<" "<<list[i].grade<<endl;
 	return 0;
}

