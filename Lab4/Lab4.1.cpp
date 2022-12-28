#include <stdio.h>

void go( int **y, int *m ) ;

int main() {
 int *a, b = 10, c = 20 ;
 go( &a, &b ) ;
 printf( "%d %p %p\n", *a, a, &a ) ;
 printf("--------------------------\n") ;
 go( &a, &c ) ;
 printf( "%d %p %p\n", *a, a, &a ) ;
 return 0 ;
}//end function

void go ( int **y, int *m ) {
	*y = m ;
	printf( "%d %p %p\n", **y, *y, y ) ;
}
