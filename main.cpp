#include<bits/stdc++.h>
#include<conio.h>

using namespace std;

// Class containing node which is bssically single element of linked list

class Node{
    public:
        int roll_no;               // Attrbutes of a node
        string name;
        float marks,per;
        Node *next_add;            // Pointer to next node
};

class Linked_List{
    public:
        Node *head = NULL;
        void Insert(){              // Method to add a new record which is basically a new node
            int r;
            string n;
            float m;
            cout<<"\n\n Enter Roll No. : ";
            cin>>r;
            cout<<"\n\n Enter name : ";
            cin.ignore();
            getline(cin,n);
            cout<<"\n\n Enter marks : ";
            cin>>m;
            Node *new_node = new Node;
            new_node->roll_no = r;
            new_node->name = n;
            new_node->marks = m;
            new_node->per = (m/100)*100;
            new_node->next_add = NULL;
            if(head == NULL){
                head = new_node;
            }
            else{
                Node *ptr = head;
                while(ptr->next_add!=NULL){
                    ptr=ptr->next_add;
                }
                ptr->next_add = new_node;
            }
            cout<<"\n\n New node inserted successfully...";
            //getch();
        }

        void Search(){              // Method to search a record
            if(head==NULL){
                cout<<"\n\n Linked list is empty...!";
            }
            else{
                int r,found=0;
                cout<<"Enter roll no. to search : ";
                cin>>r;
                Node *ptr = head;
                while(ptr!=NULL){
                    if(ptr->roll_no==r){
                        cout<<"\n\n Roll No. : "<<ptr->roll_no;
                        cout<<"\n\n Name : "<<ptr->name;
                        cout<<"\n\n Marks : "<<ptr->marks;
                        cout<<"\n\n Percentage : "<<ptr->per;
                        found++;
                        //getch();
                    }
                    ptr=ptr->next_add;
                }
                if(found==0){
                    cout<<"\n\n\n Roll No. "<<r<<" not found...!";
                }
            }
        }

        void Count(){
            if(head==NULL){
                cout<<"\n\n Linked list is empty";
            }
            else{
                int c=0;
                Node *ptr=head;
                while(ptr!=NULL){
                    c++;
                    ptr=ptr->next_add;
                }
                cout<<"\n\n Total no. of nodes : "<<c;
            }
        }

        void Update(){              // Method to search a record
            if(head==NULL){
                cout<<"\n\n Linked list is empty...!";
            }
            else{
                int r,found=0;
                cout<<"Enter roll no. to update : ";
                cin>>r;
                Node *ptr = head;
                while(ptr!=NULL){
                    if(ptr->roll_no==r){
                        cout<<"\n\n Enter New Roll No. : ";
                        cin>>ptr->roll_no;
                        cout<<"\n\n Enter New Name : ";
                        cin.ignore();
                        getline(cin,ptr->name);
                        cout<<"\n\n Enter New Marks : ";
                        cin>>ptr->marks;
                        ptr->per=(ptr->marks/100)*100;
                        cout<<"\n\n\n Record Updated Successfully...";
                        found++;
                    }
                    ptr=ptr->next_add;
                }
                if(found==0){
                    cout<<"\n\n\n Roll No. "<<r<<" not found...!";
                }
            }
        }

        void Del(){              // Method to search a record
            if(head==NULL){
                cout<<"\n\n Linked list is empty...!";
            }
            else{
                int r,found=0;
                cout<<"Enter roll no. to delete : ";
                cin>>r;
                if(r==head->roll_no){
                    Node *ptr=head;
                    head=head->next_add;
                    delete(ptr);
                    found++;
                    cout<<"\n\n Record deleted successfully...";
                }
                else{
                    Node *pre=head, *ptr=head->next_add;
                    while(ptr!=NULL){
                        if(r==ptr->roll_no){
                            pre->next_add=ptr->next_add;
                            found++;
                            cout<<"\n\n Record deleted successfully...";
                            delete(ptr);
                            break;
                        }
                        pre=ptr;
                        ptr=ptr->next_add;
                    }

                }
                if(found==0){
                    cout<<"Roll no. "<<r<<" not found...!";
                }
            }
        }

        void Show(){
            if(head==NULL){
                cout<<"\n\n Linked list is empty...!";
            }
            else{
                Node *ptr = head;
                while(ptr!=NULL){
                    cout<<"\n\n----\t----\t----\t----\t----\t----\t----\t----\t";
                    cout<<"\n\n Roll No. : "<<ptr->roll_no;
                    cout<<"\n\n Name : "<<ptr->name;
                    cout<<"\n\n Marks : "<<ptr->marks;
                    cout<<"\n\n Percentage : "<<ptr->per;
                    ptr=ptr->next_add;
                }
                
            }
        }


};

int main(){                         // Main function
    Linked_List obj;
    int choice;
    p:
    system("cls");
    system("color 0A");
    cout<<"----\t----\t----\t----\tWelcome to the main menu\t----\t----\t----\t----\t\n";
    cout<<"\n\n 1. Insert Record";
    cout<<"\n\n 2. Search Record";
    cout<<"\n\n 3. Count Record";
    cout<<"\n\n 4. Update Record";
    cout<<"\n\n 5. Delete Record";
    cout<<"\n\n 6. Show All Records";
    cout<<"\n\n 7. Exit";
    cout<<"\n\n\n  Your Choice : ";
    cin>>choice;

    switch(choice){
        case 1:
            system("cls");
            obj.Insert();
            getch();
            break;
        case 2:
            system("cls");
            obj.Search();
            getch();
            break;
        case 3:
            system("cls");
            obj.Count();
            getch();
            break;
        case 4:
            system("cls");
            obj.Update();
            getch();
            break;
        case 5:
            system("cls");
            obj.Del();
            getch();
            break;
        case 6:
            system("cls");
            obj.Show();
            getch();
            break;
        case 7:
            exit(0);
        defualt:
            cout<<"\n\n\n Invalid Choice !... Please try again!";
            getch();            
    }
    //getch();
    goto p;
    
    return 0;
}