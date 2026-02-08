 class Node
        {
        public:
            int data;
            Node *next;
            Node(int data)
            {
                this->data = 0;
                this->next = nullptr;
            
            }
        };
class Stack
{
    Node* temp;
    int size = 0;

public:
    Stack()
    {
        temp = nullptr;
        size = 0;
    }

    int getSize()
    {
        return size;
    }

    bool isEmpty()
    {
        return temp == nullptr;
    }

    void push(int data)
    {
        Node* newNode = new Node(data);
        newNode->next = temp;
        temp = newNode;
        size++;
    }

    void pop()
    {
        if (temp == nullptr) return;  // stack empty

        Node* del = temp;
        temp = temp->next;
        delete del;
        size--;

    }

    int getTop()
    {
        if (temp == nullptr) return -1;  // stack empty
        return temp->data;
    }
};