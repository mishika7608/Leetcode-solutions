class MyLinkedList {
public:
    struct Node{
        int data;
        struct Node *next=NULL;
        Node(int x):data(x),next(nullptr){}
    };
    struct Node *head;
    int size;

    MyLinkedList() {
        head=NULL;
        size=0;
    }
    
    int get(int index) {
        struct Node *p=head;
        if (size<=index || index<0){return -1;}
        for (int i=0;i<index;i++){
            p=p->next;
        }
        return p->data;
    }
    
    void addAtHead(int val) {
        struct Node *newNode = new Node(val);
        newNode->next=head;
        head=newNode;
        size++;
    }
    
    void addAtTail(int val) {
        struct Node *newNode=new Node(val);
        if (head==NULL){
            head=newNode;
        }else{
        struct Node *p=head;
        while (p->next!=NULL){p=p->next;}
        p->next=newNode;}
        size++;
    }
    
    void addAtIndex(int index, int val) {
            if (index > size || index < 0) return;

        if (index == 0) {
            addAtHead(val);
            return;
        }

        if (index == size) {
            addAtTail(val);
            return;
        }
        struct Node *p=head;
        struct Node *newNode=new Node(val);
        if (size>index){
            for (int i=0;i<index-1;i++){
                p=p->next;
            }
            newNode->next=p->next;
            p->next=newNode;
        }
        size++;
    }
    
    void deleteAtIndex(int index) {
    if (index < 0 || index >= size) return;

    if (index == 0) {
        Node* delNode = head;
        head = head->next;
        delete delNode;
    } else {
        Node* p = head;
        for (int i = 0; i < index - 1; i++) p = p->next;
        Node* delNode = p->next;
        p->next = delNode ? delNode->next : nullptr;
        delete delNode;
    }
    size--;
}
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
