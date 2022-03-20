#include <iostream>
using namespace std;
#include <string.h>

 template<typename type=int>
class tree
{
    struct node
    {
        const char*key=0;
        type value;
        node*left;
        node*right;

        node&operator,(const bool b)
        {if(b)return*right;return*left;}
        
        ~node()
        {
            if(!key)return;
            delete left;
            delete right;
            //cout<<key<<" was deleted"<<endl;
        }
        
        void out(int a)
        {
            if(!key)return;
            cout<<a<<'\t'<<key<<':'<<value<<endl;
            a=abs(a)+1;
            left->out(-a);
            right->out(a);
        }
    };
    
    size_t size=0;
public:
    node*root=new node;
    
    ~tree()
    {delete root;}

    node&operator*()
    {return*root;}

    bool operator()(const char*k,int v)
    {
        node*cur=root;
        
        while(cur->key)
        {
            const char c=strcmp(cur->key,k);
            if(!c)return false;
            
            if(c>0)
                cur=cur->left;
            else
                cur=cur->right;
        }
        
        cur->key=k;
        cur->value=v;
        cur->left=new node;
        cur->right=new node;
        size++;
        
        return true;
    }
    
    const type operator[](const char*k)
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
    
    operator size_t()
    {return size;}
    
    operator bool()
    {return root->key;}
    
    inline void out()
    {root->out(0);}
};

int main()
{
    tree<>t;
    
    t("f",1);
    
    t("e",2);
    t("g",3);
    
    t("c",4);
    t("d",5);
    t("h",6);
    t("i",7);
    
    t("a",8);
    t("b",9);
    t("j",10);
    t("k",11);
    t("l",12);
    
    t.out();
    cout<<(*t,0,0,0).key;
    
    return 0;
}
