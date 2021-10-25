/*
 * set.h
 *
 *  Created on: 11/05/2021
 *      Author: jluis
 */

#ifndef SET_H_
#define SET_H_

typedef enum{FALSE,TRUE} BOOL;

typedef void * TYPE;
typedef char * STRING;


typedef int (*COMPAREFUNC)(TYPE,TYPE);
typedef void (*PRINTFUNC)(TYPE);

struct STRNODE {
	TYPE data;
	struct STRNODE *left,*right;
};

typedef struct STRNODE * NODE;

struct STRSET {
	NODE root;
	int size;
	COMPAREFUNC cf;
	PRINTFUNC pf;
};

typedef struct STRSET * SET;

#define ELEMS 15

STRING string_create(STRING str);

void set_add(SET set,TYPE data);
int set_size(SET set);
BOOL set_contains(SET set,TYPE data);
BOOL tree_contains(NODE root,TYPE data,COMPAREFUNC cf);
int tree_insert(NODE *node,TYPE data,COMPAREFUNC cf);
void set_print(SET set);
void tree_print(NODE node,PRINTFUNC pf,int level);
NODE tree_min(NODE node);
void set_remove(SET set,TYPE data);
NODE tree_remove(NODE node,TYPE data,COMPAREFUNC cf);

void printtabs(int level);
int int_compare(TYPE data1,TYPE data2);
void int_print(TYPE data);
SET set_create(COMPAREFUNC cf,PRINTFUNC pf);


#endif /* SET_H_ */
