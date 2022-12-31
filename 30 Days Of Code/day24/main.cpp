#include <cstddef>
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;	
class Node
{
    public:
        int data;
        Node *next;
        Node(int d){
            data=d;
            next=NULL;
        }
};
class Solution{
    public:
        
          Node* removeDuplicates(Node *head)
          {
            
            if(head == NULL){//empty list
                return NULL;
            }
            if(head->next == NULL){
                return head;//single element
            }
            
            Node* firstTempNode = head;
            Node* tempPrevious = head;
            
            while(firstTempNode->next != NULL){
                int numOfMatches = 0;
                tempPrevious = firstTempNode;//to save previous element
                firstTempNode = firstTempNode->next;
                Node* secondTempNode = head;
                //COMPARE currentTempNode WITH ARRAY: IF REPEATED, DELETE IT. 

                while(secondTempNode != NULL){
                    if(secondTempNode->data == firstTempNode->data){
                        numOfMatches += 1;
                    }
                    if(numOfMatches == 2){
                        tempPrevious->next = firstTempNode->next;
                        delete(firstTempNode);
                    }
                    secondTempNode = secondTempNode->next;
                }
            }
            
            return head;
          }

          Node* insert(Node *head,int data)
          {
               Node* p=new Node(data);
               if(head==NULL){
                   head=p;  

               }
               else if(head->next==NULL){
                   head->next=p;

               }
               else{
                   Node *start=head;
                   while(start->next!=NULL){
                       start=start->next;
                   }
                   start->next=p;   

               }
                    return head;
                
            
          }
          void display(Node *head)
          {
                  Node *start=head;
                    while(start)
                    {
                        cout<<start->data<<" ";
                        start=start->next;
                    }
           }
};
			
int main()
{
	Node* head=NULL;
  	Solution mylist;
    int T,data;
    cin>>T;
    while(T-->0){
        cin>>data;
        head=mylist.insert(head,data);
    }	
    head=mylist.removeDuplicates(head);

	mylist.display(head);
		
}