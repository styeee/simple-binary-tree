#pragma once

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
            delete[]key;
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

    const type operator()(const char*k,const type v)
    {
        node*cur=root;
        
        while(cur->key)
        {
            const char c=strcmp(cur->key,k);
            if(!c)return 0;
            
            if(c>0)
                cur=cur->left;
            else
                cur=cur->right;
        }
        
        size_t l=strlen(k);
        char*temp=new char[l+1];
        strcpy(temp,k);temp[l]=0;

        cur->key=temp;
        cur->value=v;
        cur->left=new node;
        cur->right=new node;
        size++;
        
        return cur->value;
    }
    
    const type operator[](const char*k)
    {
        node*cur=root;
        
        if(!cur->key)return 0;//exeption

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
    inline const type operator[](char*k)
    {operator[]((const char*)k);}
    
    operator size_t()const
    {return size;}
    
    operator bool()const
    {return root->key;}
    
    inline void out()const
    {root->out(0);}
};
