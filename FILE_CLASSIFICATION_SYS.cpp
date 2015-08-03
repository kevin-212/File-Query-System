#include<bits/stdc++.h>
#include<dirent.h>
#include<sys/stat.h>
using namespace std;

map<string,int>msearch;
map<string,int>curr;
vector<map<string,int> >mdoc;
vector<double>tf_idf;
vector<int>num;
vector<string>names;
bool cmp(int a,int b)
{
	return tf_idf[a]>tf_idf[b];
}
void search(char*c1)
{
	char* s;
	freopen(c1,"r",stdin);
	while((scanf("%s",s)!=EOF))
	{
		msearch[s];
	}
	
}

double calc(){
		int sz=mdoc.size();
		tf_idf.resize(sz);
		map<string,int>::iterator it1,it2;
	 	double tf,idf;
	 	int freq,i,j,k;
		it1=msearch.begin();
		it2=msearch.end();
		
		for(i=0;i<sz;i++)
			num.push_back(i),tf_idf[i]=0;		
	while(it1!=it2){
		for(i=0;i<sz;i++)
		{
			if(mdoc[i].find(it1->first)!=mdoc[i].end())
			(it1->second)++;
			
		}
		it1++;
	}
	it1=msearch.begin();
	while(it1!=it2){
		for(i=0;i<sz;i++)
		{
			if(mdoc[i].find(it1->first)!=mdoc[i].end())
				tf_idf[i]+=((1+log10(mdoc[i][it1->first])*(log10(sz/(it1->second)))));
		}
		it1++;
	}
	sort(num.begin(),num.end(),cmp);
	
}

void explore(char* dir_name){
	
	DIR*dir;
	char*s;
	struct dirent *entry;
	struct stat *info;
	int index=-1;
	dir=opendir(dir_name);
	bool check;
	int sz;
	if(!dir)	{
		puts("Directorty Not found\n");
		return;
	}
	
	while((entry=readdir(dir))!=NULL){
		if(entry->d_name[0]=='.')
		continue;
		
		 string path1=string(dir_name)+"\\"+ string(entry->d_name);
		 sz=path1.length();
		 char*path=new char[sz+1];
		 for(int i=0;i<sz;i++)
		 path[i]=path1[i];
		 path[sz]='\0';
		 names.push_back(entry->d_name);
		 cout<<path<<endl;
		freopen (path,"r",stdin);
		
	
		while(scanf("%s",s)!=EOF)
			cout<<s<<endl,curr[s]++;	
			mdoc.push_back(curr);
			curr.clear();
			fclose(stdin);
	}
	closedir(dir);
}

int main(int argc,char**argv){
	char c[1000];
	char c1[1000];
	int sz;
	
	cout<<"Enter directory path."<<endl;
	cin>>c;
	
	cout<<"Enter Path of Document."<<endl;
	cin>>c1;
	
	search(c1);
	cout<<"ok1"<<endl;
	explore(c);
	cout<<"ok"<<endl;
	calc();
	sz=num.size();
	
	if(sz<3){
		for(int i=0;i<sz;i++)
		cout<<names[num[i]]<<endl;
	}else{
		for(int i=0;i<3;i++)
		cout<<names[num[i]]<<endl;
	}
}
