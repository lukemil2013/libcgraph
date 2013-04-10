#include <List.h>
#include <stdlib.h>

int addToList(List & l, void * data){
    List * current = l;
    List * newList;
    
    newList->data = data;
    
    while(current.next != NULL){
        current = current.next;
    }
    
    current.next = newList;
    return SUCCESS;
};

int remFromList(List & l, void * data){
    List * current = l;
    
    while(*current->data != *data && current->next != NULL){
        current = current.next;
    }
    
    if(*current->data != *data && current->next == NULL){
        return NOTFOUND;
    }
};

int length(List & l){
    int i = 1;
    for(List * current = l; current->next != NULL; current = current->next){
        i++;
    }
    return i;
};

void * getData(List & l, int index){
    void * data = NULL;
    List * current = l;
    for(int i = 0; i < length(l); i++){
        if(i == index){
            data = current.data;
        }
        current = current->next;
    }
    
    return data;
};
