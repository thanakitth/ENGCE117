#include <stdio.h>
#include <string.h>

struct studentNode {
    char name[20];
    int age;
    char sex;
    float gpa;
    struct studentNode *next; //what is mean
};

struct studentNode *AddNode( struct studentNode **walk, char n[], int a, char s, float g );
void InsNode( struct studentNode *Node, char n[], int a, char s, float g ) ;
void ShowAll( struct studentNode *walk );
void DelNode( struct studentNode *Node );

int main(){
    struct studentNode *start, *now;
    start = NULL;
    now = AddNode(&start, "one", 6, 'M', 3.11); ShowAll(start);
    now = AddNode(&start, "two", 8, 'F', 3.22); ShowAll(start);
    InsNode( now, "three", 10, 'M', 3.33 ) ; ShowAll( start ) ;
 	InsNode( now, "four", 12, 'F', 3.44 ) ; ShowAll( start ) ;
 	DelNode(now); ShowAll(start);
    return 0;
} // end function

void ShowAll( struct studentNode *walk )
{
    while (walk != NULL)
    {
        printf("%s ", walk->name);
        walk = walk->next;
    } // end while
    printf(" ");
} // end function

struct studentNode *AddNode( struct studentNode **walk, char n[], int a, char s, float g ){
	while( *walk != NULL ){
		walk = &(*walk)->next;
	}
	struct studentNode *data;
	data = new struct studentNode; 
	strcpy(data->name, n);
	data->age = a;
	data->sex = s;
	data->gpa = g;
	*walk = data;
	data->next = NULL;
	return data;
}

void InsNode( struct studentNode *now, char n[], int a, char s, float g ){
    struct studentNode *temp = new studentNode;
    strcpy(temp->name, n);
    temp->age = a;
    temp->sex = s;
    temp->gpa = g;
    temp->next = now->next;
	now->next = temp;
}
void DelNode( struct studentNode *Node ){
	struct studentNode *delNode = Node->next;
    Node->next = delNode->next;
    delete delNode;
}



