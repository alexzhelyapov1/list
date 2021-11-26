#include <stdio.h>
#include <stdlib.h>

typedef int Data;
struct Node {
    Data val;
    struct Node* next; //head pref
};
struct List {
    struct Node* head;
    int size = 0;
};

struct List* list_create ();                       // необходимые действия для создания и инициализации списка: выделить память под структуру, 
    
void list_add_first (struct List* list, Data x);   // кладет число х первым (выделив под него память) или последним элементом списка
void list_add_last (struct List* list, Data x);   
Data list_remove_first (struct List * list);       // достает первое или последнее число из списка и возвращает его (перед 
Data list_remove_last (struct List * list);        // возвратом освободив из-под него память)  
Data list_get_first (struct List * list);          // возвращает число, лежащее в первом или последнем узле,
Data list_get_last (struct List * list);           // не изменяя состояния списка
void list_print (struct List * list);              // печать списка
int list_size (struct List * list);                // возвращает размер списка
void list_clear (struct List * list);              // опустошает список, освобождая память. После этого можно опять добавлять элементы в список. 
void list_destroy (struct List * list);            //опустошает список, освобождая память, а затем освобождает сам list.


int main () {
    struct List * list = list_create();
    list_add_first(list, 5);
    list_add_first(list, 6);
    list_add_first(list, 7);
    list_add_first(list, 8);
    list_add_last(list, 9);
    list_print(list);
    list_remove_first (list);
    list_remove_last (list);
    list_print (list);
    list_destroy(list);
    return 0;
}


struct Node* last_node (struct List *list);        // возвращает последний элемент списка 
struct Node* semi_last_node (struct List* list);   // возвращает предпоследний элемент списка
struct Node* node_create (Data val);               // присвоить голове указатель на NULL.
void list_clear_node (struct Node* node);          // чистит все, начиная с данной ячейки

struct List* list_create () {
    struct List* list = (struct List*) calloc (1, sizeof (*list));
    list -> head = NULL;
    return list;
}

struct Node* node_create (Data val) {
    struct Node* node = (struct Node*) calloc (1, sizeof (struct Node));
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
    struct Node* last = last_node (list);
    if (!last) {
        list_add_first (list, x);
        return;
    }
    last -> next = node_create (x);
}

struct Node* last_node (struct List* list) {
    struct Node* node = list -> head;
    while (node -> next) {
        node = node -> next;
    }
    return node;
}

struct Node* semi_last_node (struct List* list) {
    if (!list) {
        return NULL;
    }
    struct Node* node = list -> head;
    if (node -> next == NULL) {
        return NULL;
    }
    while (node -> next -> next){
        node = node -> next;
    }
    return node;
}

Data list_remove_first (struct List* list) {
    Data x = list -> head -> val;
    struct Node* temp = list -> head;
    list -> head = list -> head -> next;
    free (temp);
    return x;
}

Data list_remove_last (struct List* list) {
    if (!list) {
        return 1331;
    }
    struct Node* semi_last = semi_last_node (list);

    Data x = 0;
    if (semi_last) {
        x = semi_last -> next -> val;
        free (semi_last -> next);
        semi_last -> next = NULL;
    } 
    else {
        x = list -> head -> val;
        free (list -> head);
        list -> head = NULL;
    }
    return x;
}

Data list_get_first (struct List* list) {
    return list -> head -> val;
}

Data list_get_last (struct List* list) {
    return last_node (list) -> val;
}

void list_print (struct List* list) {
    if (!list || !list -> head) {
        printf ("Empty list");
    }
    struct Node* node = list -> head;
    while (node) {
        printf ("%d ", node -> val);
        node = node -> next;
    }
    printf ("\n");
}

int list_size (struct List* list) {
    int size = 0;
    if (!list) {
        return 0;
    }
    struct Node* node = list -> head;
    while (node) {
        size += 1;
        node = node -> next;
    }
    return size;
}

void list_clear (struct List* list) {
    if (!list) {
        return;
    }
    list_clear_node (list -> head);
    list -> head = NULL;
}

void list_destroy (struct List * list) {
    if (!list) {
        return;
    }
    list_clear_node (list -> head);
    list -> head = NULL;
    free (list);
}

void list_clear_node (struct Node* node) {
    if (!node) {
        return;
    }
    list_clear_node (node -> next);
    free (node);
}