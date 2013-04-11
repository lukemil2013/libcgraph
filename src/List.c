#include <List.h>
#include <stdlib.h>

int initList(List * l){
    l = malloc(sizeof(List));
    l->data = NULL;
    l->next = NULL;
    l->previous = NULL;
    l->size++;
}

int addToList(List & l, void * data){
    List * current = l;
    List * newList;
    if(l.data == NULL){
        l.data = data;
    }else{
        newList->data = data;
    
        while(current.next != NULL){
                current = current.next;
        }
    
        current.next = newList;
        current->size++;
    }
    
    return SUCCESS;
};

int remFromList(List & l, void * data){
    List * current = l;
    
    while(*current->data != *data && current->next != NULL){
        current = current.next;
    }
    
    if(*current->data != *data && current->next == NULL){
        return NOTFOUND;
    } else {
        current->previous->next = current->next;
        current->size++;
    }
};

void * getData(List & l, int index){
    void * data = NULL;
    List * current = l;
    for(int i = 0; i < l.size; i++){
        if(i == index){
            data = current.data;
        }
        current = current->next;
    }
    
    return data;
};

void appendToList(List & l, List & r){
    List * currentl = l;
    while(currentl->next != NULL){
        currentl = currentl->next;
    }
    
    currentl->next = r;
    r.previous = currentl;
}

int findIndex(List & l, void * data){
    int i = 0;
    
    for(i; i < l->size;)
}