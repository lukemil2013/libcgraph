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
        void * previous;
        void * current;
        void * next;
    };

    void addToList(List & l, void * data);
    void remFromList(List & l, void * data);
    int length(List & l);
    void * getData(List & l, int index);
    
    
#ifdef	__cplusplus
}
#endif

#endif	/* LIST_H */

