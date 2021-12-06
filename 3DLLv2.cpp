#include <iostream>
using namespace std;

struct Node{
    int data;
    struct Node* length;
    struct Node* breadth;
    struct Node* height; 
}*Origin=NULL;

void highdata(struct Node *temp,int x, int y);

void insert(int element,int x, int y,int z){
    struct Node *temp=new Node;
    struct Node *Len=Origin;
    struct Node *Bth=Origin;
    for (int i=0;i<z;i++){
        Len=Len->height;
        Bth=Bth->height;
    }
    temp->height=NULL;
    temp->data=element;
    if(z>0)highdata(temp,x,y);
    if (Origin==NULL){
        temp->length=NULL;
        temp->breadth=NULL;
        Origin=temp;
        return;        
    }
    else if((x!=0 && y==0)||(x==0 && y!=0)){
        x--;
        y--;
        while (x>=1)
        {
            Len=Len->length;
            x--;
        }
        while (y>=1)
        {
            Len=Len->breadth;
            y--;
        }
        if(x==0)Len->length=temp;
        if(y==0)Len->breadth=temp;
        temp->length=NULL;
        temp->breadth=NULL;
        return;
    }
    else if (x==0&&y==0)
    {
        return;
    }
    
    else{
        for (int i = 0; i < x; i++)
        {
            Len=Len->length;
        }
        for (int i = 0; i < y-1; i++)
        {
            Len=Len->breadth;
        }
        for (int i = 0; i < y; i++)
        {
            Bth=Bth->breadth;
        }
        for (int i = 0; i < x-1; i++)
        {
            Bth=Bth->length;
        }
        Bth->length=temp;
        Len->breadth=temp;
        temp->length=NULL;
        temp->breadth=NULL;
    }
}
void highdata(struct Node *temp,int x, int y){
    struct Node *high=Origin;
    for (int i = 0; i < x; i++)
    {
        high=high->length;
    }
    for (int i = 0; i < y; i++)
    {
        high=high->breadth;
    }
    while (high->height)
    {
        high=high->height;
    }
    high->height=temp;
    return;
}
void display(int x,int y,int z){
    struct Node *show=Origin;
     for (int i = 0; i < x; i++)
    {
        show=show->length;
    }
    for (int i = 0; i < y; i++)
    {
        show=show->breadth;
    }
    for (int i = 0; i < z; i++)
    {
        show=show->height;
    }
    cout<<show->data<<"\t";
    return;
}
void deletehighdata(int x ,int y,int z){
    struct Node *delhigh1=Origin;
    for (int i = 0; i < x; i++)
    {
        delhigh1=delhigh1->length;
    }
    for (int i = 0; i < y; i++)
    {
        delhigh1=delhigh1->breadth;
    }
    for (size_t i = 0; i < z; i++)    
    {
        delhigh1=delhigh1->height;
    }
    free(delhigh1);    
}

int main()
{   
    insert(10,0,0,0);
    insert(20,1,0,0);
    insert(20,0,1,0);
    insert(30,0,0,1);
    insert(40,1,1,0);
    insert(50,1,0,1);
    insert(70,0,1,1);
    insert(60,1,1,1);
    cout<<"Successfully Completed"<<endl;
    cout<<"3D Linked List MTE Project By"<<endl;
    cout<<"Guddu Kumar 2K20/MC/52"<<endl;
    cout<<"Hemaank Mahajan 2K20/MC/55"<<endl;
    cout<< Origin->breadth->length->height->data<<endl;
    cout<< Origin->length->height->breadth->data<<endl;
    cout<< Origin->height->breadth->length->data<<endl;
    display(1,1,1);
    return 0; 
}