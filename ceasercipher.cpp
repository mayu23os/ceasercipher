#include<iostream>
#include<string.h>
#include<stdio.h>
#define MAX 20
using namespace std;
string encrypt(char a[],int key,int len)
{

    char b[len];
    for(int i=0;i<len;i++)
    {
       
        b[i]=(int(a[i])+key-65)%26+65;
    }
    cout<<" ";
    for (int i = 0; i < len; i++)
    {
        cout<<b[i];
    }
    b[len]='\0';
    return b;
}

string decrypt(char a[],int key,int len)
{
    string b;
    int i;
    for(int i=0;i<len;i++)
    {
       
        b[i]=(int(a[i])-key-65)%26+65;
    }
    cout<<" ";
    for (i = 0; i < len; i++)
    {
        cout<<b[i];
    }
    b[i]='\0';
    return b;
}

int strcp(char a[],char b[],int len)
{
    for(int i=0;i<len;i++)
    {
        if(a[i]!=b[i])
        return -1;
    }
    return 0;
}

void brute_force(char decrypted[],int len,char orgmsg[])
{
    char b[len];
    int count=0;
    for(int k=1;k<26;k++)
    {
        for(int i=0;i<len;i++)
        {
            //cout<<"in";
            //count++;
            b[i]=(int(decrypted[i])-k-65)%26+65;
            //cout<<count;
        }
        //for (int i = 0; i < len; i++)
        //{
        //    cout<<b[i]<<" ";
        //}
        count++;
        //cout<<"\n"<<count;
        if(strcp(b,orgmsg,len)==0)
        break;
    }
   
    cout<<"\nBrute Force : ";
    
    for (int i = 0; i < len; i++)
    {
        cout<<b[i];
    }
     cout<<" ( "<<count<<" Attempts )";
}
int main()
{
    int i=26;
    char a[]="HELLO";
    int key=8;
    int len=5;
   char b[]="PMTTW";
   cout<<"Original : "<<a;
   cout<<"\nEncrypted : ";
   encrypt(a,key,len);
   cout<<"\nDecrypted : ";
   decrypt(b,key,len);
   brute_force(b,len,a);
}













/*


int strcp(char a[],char b[],int len)
{
    for(int i=0;i<len;i++)
    {
        if(a[i]!=b[i])
        return -1;
    }
    return 0;

}

void brute_force(char a[],int len,char c[])
{
    char b[len];
    int count=0;
    for(int k=1;k<26;k++)
    {
        for(int i=0;i<len;i++)
        {
            //cout<<"in";
            //count++;
            b[i]=(int(a[i])-k-65)%26+65;
            //cout<<count;
        }
        //for (int i = 0; i < len; i++)
        //{
        //    cout<<b[i]<<" ";
        //}
        count++;
        //cout<<"\n"<<count;
        if(strcp(b,c,len)==0)
        break;
    }
   
    cout<<"    ";
    for (int i = 0; i < len; i++)
    {
        cout<<b[i]<<" ";
    }
     cout<<"("<<count<<" Attempts )";
}*/