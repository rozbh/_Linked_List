#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
};

class linked_list
{
private:
    node *head, *tail;

public:
    linked_list()
    {
        head = NULL;
        tail = NULL;
    }
    void add_node(int n)
    {
        node *tmp = new node;
        tmp->data = n;
        tmp->next = NULL;

        if (head == NULL)
        {
            head = tmp;
            tail = tmp;
        }
        else
        {
            tail->next = tmp;
            tail = tail->next;
        }
    }
    int Length()
    {
        int counter = 0;
        node *tmp = new node;
        tmp = head;

        while (tmp != NULL)
        {
            tmp = tmp->next;
            counter++;
        }
        return counter;
    }
    int show_node(int n)
    {
        if (head == NULL)
        {
            cout << "Linked list is empty";
            return -1;
        }
        if (n == 0)
        {
            return head->data;
        }
        node *tmp = new node;
        tmp = head;
        int counter = 0;
        while (counter != n && tmp != NULL)
        {
            tmp = tmp->next;
            counter++;
        }
        if (counter == n)
        {
            return tmp->data;
        }
        return -1;
    }
    void Show_All()
    {
        if (head == NULL)
        {
            cout << "Linked list is empty";
        }
        node *tmp = new node;
        tmp = head;

        while (tmp != NULL)
        {
            cout << tmp->data << "_";
            tmp = tmp->next;
        }
        cout << endl;
    }
    int Remove_Node(int n)
    {
        if (head == NULL)
        {
            cout << "Linked list is empty";
            return -1;
        }
        int len = Length();
        if (len-1  < n || len-1 > n )
        {
            cout<<"index not in range 0 to "<<len<<"-1"<<endl;
            return -1;
        }

        if (n == 0)
        {
            head = head->next;
            return 1;
        }
        node *tmp = new node;
        node *tmp2 = new node;
        tmp = head;

        int counter = 0;
        while (counter + 1 != n && tmp != NULL)
        {
            tmp = tmp->next;
            counter++;
        }
        tmp2 = tmp->next;
        tmp->next = tmp2->next;
       // delete tmp;
        delete tmp2;
        return 1;
    }
 // int add in middle im lazy now fuck it
};

int main()
{
    linked_list List;

    for (int i = 0; i < 35; i++)
    {
        List.add_node(i);
    }
    cout << List.Length() << endl;
    List.Show_All();
    List.Remove_Node(35);
    List.Show_All();
    return 0;
}