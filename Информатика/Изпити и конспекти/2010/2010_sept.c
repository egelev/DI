/*
fileB.txt
12345$$6789
$$abcdefg
*/
#include <stdio.h>
#include <fcntl.h>
int main( )
{
  int fdr, fdw, n_byt, i = 0 , status;
  char buff [ 40 ], c ;
  if ( fork( ) )
  {
    wait ( &status);
//    write(1, "hello", 5);
    if ( open ("file_new", 0 ) != -1 )
    execlp ("grep", "grep", "$", "file_new",0 );
  }
  else {
    if ( ( fdr = open ("fileB.txt",0 ) ) == -1 )
    { printf ("\n Cannot open \n" ); exit (1); }
 
    if ( ( fdw= creat ("file_new", 0666 ) ) == -1 )
    { printf ("\n Cannot creat \n" ); exit (1); }
    

    n_byt = read ( fdr, buff, 40 );
    c = buff[ i++];
    if ( c <= '1' || c >= '9' )
    {
      while ( buff [ i ++] != '\n' && i < n_byt )
        write ( fdw, "$", 1 );
      write ( fdw, "\nE", 2 );
      write ( 1, "\nF", 2 ); // Не излиза
    }
    else { write( 1, buff, n_byt ); write ( 1, "\nG", 2 ); }
    write ( fdw, "$", 1 );
    close ( fdr); close (fdw);
  }
}
// "\n$$$$$$$$$$$\n$\n
