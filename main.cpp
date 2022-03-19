#include <iostream>
using namespace std;
#include <map>
#include <string.h>

class tree
{
    struct node
    {
        const char*key=0;
        int value;
        node*left;
        node*right;
    };
    
    size_t size=0;
    node*root=new node;
public:

    void operator()(const char*k,int v)
    {
        node*cur=root;
        
        while(cur->key)
        {
            if(strcmp(cur->key,k)>0)
                cur=cur->left;
            else
                cur=cur->right;
        }
        
        cur->key=k;
        cur->value=v;
        cur->left=new node;
        cur->right=new node;
        size++;
    }
    
    const int operator[](const char*k)
    {
        node*cur=root;
        
        for(char i=strcmp(cur->key,k);i;)
        {
            if(i>0)
                cur=cur->left;
            else
                cur=cur->right;
                
            i=strcmp(cur->key,k);
        }
        
        return cur->value;
    }
    
    operator bool()
    {
        return root->key;
    }
};

int main()
{
    tree t;
    t("text",2);
    t("da",20);
    
    cout<<t["da"];
    
    return 0;
}