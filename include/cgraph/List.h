/* 
 * File:   List.h
 * Author: anthony
 *
 * Created on April 7, 2013, 9:17 PM
 */

#ifndef LIST_H
#define	LIST_H

#ifdef	__cplusplus
extern "C" {
#endif

    struct List{
        List * previous;
        void * data;
        List * next;
        static int size = 0;
    };
    
    enum ListStatus{ SUCCESS, NOTFOUND };
    int initList(List * l);
    int addToList(List & l, void * data);
    int remFromList(List & l, void * data);
    void * getData(List & l, int index);
    void appendToList(List & l, List & r);
    int findIndex(List & l, void * data);
    
#ifdef	__cplusplus
}
#endif

#endif	/* LIST_H */

