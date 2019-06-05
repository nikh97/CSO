#include <stdlib.h> 
#include <stdio.h> 
#include "p2.h"

/*
 * Implementation file for functions
 * declared in p2.h
 */ 




int add_to_front ( char to_add, node ** head_pointer ){
    
    //allocate memory for node
    struct node *n = (struct node *)malloc(sizeof(struct node));

    //make sure memory is allocated
    if(n == NULL) return 0;

    n->value = to_add;

    //check if list is empty
    if(*head_pointer == NULL){
    	n->next = n;
    	n->prev = n;
    }else{

	    struct node *current = (*head_pointer);

        //add to back of list
	    n->next = current;
	    n->prev = current->prev;
	    current->prev->next = n;
	    current->prev = n;
	}

    //set head to new node
    *head_pointer = n;
    return 1;
}


int add_to_back ( char to_add, node ** head_pointer ) {
    
    //allocate memory for node
    struct node *n = (struct node *)malloc(sizeof(struct node));

    //make sure memory is allocated
    if(n == NULL) return 0;

    n->value = to_add;

    //check if list is empty
    if(*head_pointer == NULL){
    	n->next = n;
    	n->prev = n;
        (*head_pointer) = n;
    }else{

	    struct node *current = (*head_pointer);

        //add to back
	    n->next = current;
	    n->prev = current->prev;
	    current->prev->next = n;
	    current->prev = n;
	}

    return 1;
}

char remove_first ( node ** head_pointer ) { 
    
    //check if list is empty
    if(head_pointer == NULL) return '\0';

    struct node *n = *head_pointer;

    char w = n->value;

    //if size of list is 1, free node and set list to null
    if(n->next == *head_pointer){

        free(n);
        *head_pointer = NULL;
        return w;
    }
    
    //remove references to node n to be removed
    n->next->prev = n->prev;
    n->prev->next = n->next;

    *head_pointer = n->next;

    //free memory of node n and set it to null
    free(n);
    n = NULL;

    return w;

}

char remove_last ( node ** head_pointer ){

    //check if list is empty
   	 if(head_pointer == NULL) return '\0';

    struct node *n = NULL;

    n = (*head_pointer);

    char w = n->value;

    //if size of list is 1, free node and set list to null
    if(n->next == *head_pointer){

        free(n);
        *head_pointer = NULL;
        return w;
    }

    n = (*head_pointer)->prev;

    //remove references to node n to be removed
    n->next->prev = n->prev;
    n->prev->next = n->next;

    //free memory of node n and set it to null
    free(n);
    n = NULL;

    return w; 

}


int index_of ( char to_locate, node * head ) {
    
    //check if argument is null or if list is empty
    if(to_locate == '\0') return -1;
    if(head == NULL) return -1;

    int index = 0;
    struct node *current = head;

    //iterate through list until node is found
    while(current->next != head){

        if(current->value == to_locate)
            return index;

        current = current->next;
        index++;
    }

    //check last node
    if(current->value == to_locate)
        return index;

    //if nothing is returned, node is not in list
    return -1;
    
}


int num_of_nodes ( node * head ) {
    
    //check for empty list    
    if(head == NULL) return 0;

    int num = 0;
    struct node *current = head;

    //iterate through list
    do{
        current = current->next;
        num++;
    }while(current != head);
        
    //return number of times the do-while loop iterates
    return num;
}

void empty ( node ** head_pointer ) {
    
    struct node *current = *head_pointer;

    //iterate through array and free memory for each node
    do{
        free(current);
        current = current->next;
    }while(current != *head_pointer);

    //set head to null
    *head_pointer = NULL;
}

void print_list ( node * head ) { 
    
    //if head is null, just print "[ ]"
     if(head == NULL){
        printf("[ ]\n");
        return;
    }

    struct node *current = head;

    printf("[");
    
    //print nodes once at a time
    while(current->next != head){
        printf(" %c,", current->value);
        current = current->next;
    }

    //print last node
    printf(" %c ]\n", current->value);

}
