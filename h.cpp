#include <iostream>
#include <unordered_map>
using namespace std;
struct node
{
    int data;
    struct node *next;
};
void display(node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}
void insert_end(struct node **l, int x)
{
    node *insertNode = (struct node *)malloc(sizeof(struct node));
    node *temp = *l;
    if (temp == NULL)
    {
        insertNode->data = x;
        insertNode->next = NULL;
        *l = insertNode;
        return;
    }
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    insertNode->data = x;
    insertNode->next = NULL;
    temp->next = insertNode;
}

node *union_LL(node *head1, node *head2)
{
    node *result = NULL;
    unordered_map<int, int> record;
    node *temp1 = head1, *temp2 = head2;

    while (temp1 != NULL)
    {
        record[temp1->data] = 1;
        temp1 = temp1->next;
    }

    while (temp2 != NULL)
    {
        record[temp2->data] = 1;
        temp2 = temp2->next;
    }

    for (auto itr : record)
        insert_end(&result, itr.first);

    return result;
}
node *intersection_LL(node *head1, node *head2)
{
    node *result = NULL;
    unordered_map<int, bool> record;
    node *temp1 = head1, *temp2 = head2;

    while (temp1 != NULL)
    {
        record[temp1->data] = false;
        temp1 = temp1->next;
    }

    while (temp2 != NULL)
    {
        if (record.find(temp2->data) != record.end())
            record[temp2->data] = true;
        else
            record[temp2->data] = false;

        temp2 = temp2->next;
    }

    for (auto itr : record)
        if (itr.second)
            insert_end(&result, itr.first);

    return result;
}

int main()
{
    node *head1 = NULL, *head2 = NULL;

    insert_end(&head1, 7);
    insert_end(&head1, 2);
    insert_end(&head1, 3);
    insert_end(&head1, 4);
    insert_end(&head1, 5);
    insert_end(&head1, 6);

    insert_end(&head2, 6);
    insert_end(&head2, 7);
    insert_end(&head2, 4);
    insert_end(&head2, 3);
    insert_end(&head2, 8);

    cout << "Union of 2 LinkedList- \n";
    node *unionList = union_LL(head1, head2);
    display(unionList);

    cout << "\nIntersection of 2 LinkedList- \n";
    node *interList = intersection_LL(head1, head2);
    display(interList);

    return 0;
}