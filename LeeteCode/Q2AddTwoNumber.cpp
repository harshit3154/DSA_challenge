#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
class ListNode{
    public : 
        int data;
        ListNode *next;
        ListNode(int data){
            this->data=data;
            this->next=nullptr;
        }
};

ListNode* createLinkList(vector<int> &nums,ListNode* &root){
    
    ListNode *current=nullptr;
    for(auto it:nums){
        if(!root){
            root=new ListNode(it);
            current=root;
        }
        else{
            current->next=new ListNode(it);
            current=current->next;
        }
    }
    return root;
}

void displayLinkList(ListNode* root){
    ListNode *temp=root;
    cout<<"\n\n\n\t\tThe value of link list are :  ";
    while(temp){
        cout<<"\t"<<temp->data;
        temp=temp->next;
    }
}

ListNode* addTwoList(ListNode* l1,ListNode* l2){
    int carry=0;
    ListNode* sum=new ListNode(-1),*current=sum;
    while(l1 ||l2 || carry){
        int ans=0;
        ans+=l1?l1->data:0;
        ans+=l2?l2->data:0;
        ans+=carry;
        current->next=new ListNode(ans%10);
        current=current->next;
        carry=ans/10;
        l1=l1?l1->next:l1;
        l2=l2?l2->next:l2;
    }
    return sum->next;
}
int main(){
    vector<int> v1{1,2,3,4};
    vector<int> v2{2,3,9,6};
    ListNode *l1=nullptr,*l2=nullptr;
    createLinkList(v1,l1);
    createLinkList(v2,l2);
    displayLinkList(l1);
    displayLinkList(l2);
    displayLinkList(addTwoList(l1,l2));

}