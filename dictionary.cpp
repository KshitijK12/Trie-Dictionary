#include<iostream>
#include<string.h>
#include<fstream>
#include<cstdlib>
#define MAX_WORD 50
using namespace std;
struct node
{
	node* child[26];
	string meaning;
	int end;
};
node* getNode()
{
	node *n=new node;
	n->end=0;
	for(int i=0;i<26;i++)
		n->child[i]=NULL;
	return n;
}
void insert(node*& root,string w,string s)
{
	if(root==NULL)
		root=getNode();
	node* t;
	t=root;
	int index;char c;
	for(int i=0;i<w.length();i++)
	{
		c=w[i];
		index=c-'a';
		if(t->child[index]==NULL)
		{
			
			t->child[index]=getNode();
		}
		t=t->child[index];
	}
	t->meaning=s;
	t->end=1;
}

void print(node* t,char str[],int index)
{
	if(t->end==1)
	{
		str[index]='\0';
		cout<<str<<endl;

	}
	
	for(int i=0;i<26;i++)
	{
		if(t->child[i])
		{
			str[index]=(i+'a');
			print(t->child[i],str,index+1);
		}
	}
}	
		
void autoguess(node* root,string word)
{	
	int i=0;
	int  index=0;
	char str[MAX_WORD];
	int ind=word[i]-'a';
	int l=word.length();
	while(root->child[ind] && i<l)
	{
		str[index]=ind+'a';
		index++;
		i++;
		root=root->child[ind];
		ind=word[i]-'a';
	}
	print(root,str,index);
}

string search(node*& root,string key)
{
	node* t=root;
	if(root==NULL)
	{	
		cout<<"Dictionary is empty\n";
		return "";
	}
	char c;
	int index;
	for(int i=0;i<key.length();i++)	
	{
		c=key[i];
		index=c-'a';
		t=t->child[index];
		if(t==NULL)
			break;
	}
	if(t->end)
	{	return t->meaning;}
	else
	{	
		cout<<"Word not in dictionary\n";
		cout<<"Related words in dictionary:\n";
		autoguess(root,key);
		return "";
	}
}


int main()
{
	char ch;
	node *root=NULL;
	string word,mean,k;
/*	while(1)
	{
		cout<<"\nEnter your choice\n";
		cout<<"1.Insert a word\n;
		cout<<"2.Search for a meaning\n";
		cout<<"3.Exit.\n";
		cin>>ch;
		switch(ch)
		{
			case 1:
				string mean;
				cout<<"Enter the word to be added\n";
				cin>>word;
				cout<<"Enter the meaning of word\n";
				cin>>mean;
				insert(root,word,mean);
				break;
			case 2:	
				cout<<"Enter a word to find meaning\n";
				cin>>word;
				string ans=search(root,word);
				if(ans.length()>0)
					cout<<word<<"  :"<<ans<<endl;
				break;
			case 3:
				exit(0);
			default:
				cout<<"Invalid choice. Try again..\n";
		}
		cout<<"Press y/Y to continue\n";
		cin>>ch;
		if(ch!='Y'||ch!='y')
	  		exit(0);
	}

*/

	ifstream fin;
	fin.open("Dictionary.txt");
	if(fin.fail())
	{
		cout<<"Error opening dictionary..\n";
		exit(0);
	}
	while(!fin.eof())
	{
		fin>>word;
		getline(fin,mean);
		insert(root,word,mean);
		
	}
	fin.close();
	
	while(1)
	{
		char ch;
		cout<<"Search a word for meaning :\n";
		cin>>k;
		string ans;
		ans=search(root,k);
		if(ans.length()>0)
			cout<<k<<" "<<ans<<endl;
		cout<<"\n\nEnter y/Y to search another word \n";
		cin>>ch;
		if(ch=='y' || ch=='Y')
			system("clear");
		else
		exit(0);
	}		
	return 0;
}	


