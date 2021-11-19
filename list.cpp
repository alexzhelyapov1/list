#include <stdio.h>

typedef int Data;
struct Node {
    Data val;
    struct Node* next; //head pref
};
struct List {
    struct Node* head;
}

struct List* list_create ();                       // необходимые действия для создания и инициализации списка: выделить память под структуру, 
struct Node* node_create (Data val);               // присвоить голове указатель на NULL.
void list_add_first (struct List* list, Data x);   // кладет число х первым (выделив под него память) или последним элементом списка
void list_add_last (struct List* list, Data x);   
struct Node* last_node (struct List *list);        // возвращает последний элемент списка 
Data list_remove_first (struct List * list);       // достает первое или последнее число из списка и возвращает его (перед 
Data list_remove_last (struct List * list);        // возвратом освободив из-под него память)  


int main () {
    List list = NULL;

    return 0;
}

struct List* list_create () {
    struct List* list = (struct List*) calloc (1, *list);
    list -> head = NULL;
    return list;
}

struct Node* node_create (Data val) {
    struct Node* node = (struct Node*) calloc (1, *node);
    node -> val = val;
    node -> next = NULL;
    return node;
}

void list_add_first (struct List* list, Data x) {
    if (!list) {
        return;
    }
    struct Node* temp_node = list -> head;
    list -> head = node_create (x);
    list -> head -> next = temp_node;
}

void list_add_last (struct List* list, Data x) {
    if (!list) {
        return;
    }   
    struct Node* last_node = last_node (list);
    last_node -> next = node_create (x);
}

struct Node* last_node (struct List *list) {
    struct Node* node = list -> head;
    while (!node -> next) {
        node = node -> next;
    }
    return node;
}

Data list_remove_first (struct List * list) {
    Data x = list -> head -> val;

    return x;
}

Data list_remove_last (struct List * list) {
    Data x = last_
    return x;
}