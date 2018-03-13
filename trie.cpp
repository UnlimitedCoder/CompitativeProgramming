#include<bits/stdc++.h>
using namespace std;
struct trienode
{
    struct trienode *children[26];
    bool isendofword;
    int weight;


} ;

struct trienode* getnode()
{

    struct trienode* pnode=NULL;
    pnode=(struct trienode*)malloc(sizeof(struct trienode));
    if(pnode)
    {
        pnode->isendofword=false;
        pnode->weight=0;
        for(int i=0;i<26;i++)
        {
           pnode->children[i]=NULL;
        }

    }
    return pnode;

};
void insert(struct trienode *root,string str,int weight)
{

    struct trienode* crawl=root;
    for(int i=0;i<str.size();i++)
    {
        if(crawl->children[str[i]-'a']==NULL)
        {
            crawl->children[str[i]-'a']=getnode();

        }
        crawl->weight=max(crawl->weight,weight);
        crawl=crawl->children[str[i]-'a'];
    }

  crawl->isendofword=true;


}
int  search(struct trienode *root,string str)
{

    struct trienode *crawl=root;
    for(int i=0;i<str.size();i++)
    {
        if(crawl->children[str[i]-'a']==NULL)
                    return -1;
        crawl=crawl->children[str[i]-'a'];
    }
   return crawl->weight;
}


int main()
{

 struct trienode *root=NULL;
 int i,j,n,weight,q;
 string str;
 root=getnode();
   cin>>n;
   cin>>q;
   for(i=0;i<n;i++)
   {
       cin>>str;
       cin>>weight;
       insert(root,str,weight);
   }
   for(i=0;i<q;i++)
   {
       cin>>str;
       cout<<search(root,str)<<endl;
   }



return 0;
}
