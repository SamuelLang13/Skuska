#ifndef __PROGTEST__
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <ctype.h>
#include <limits.h>
#include <assert.h>
#endif /* __PROGTEST__ */

typedef struct TGrade
{
  char             m_Username[76];
  char             m_Date[12];
  char             m_Grade;
  struct TGrade  * m_Next;
} TGRADE;

/* forward declaration, function is implemented in the testing environment */
void freeList ( TGRADE * l );

TGRADE * ownGrades ( const char * list )
{
  TGRADE*data=NULL;
  char username[76];
  char date[12];
  char grades[]={"Excellent","VeryGood","Good","Satisfactory","Sufficient","Failed"};
  char grades_input[20];
  int cnt=0;
  while (list[cnt]!='\0')
  {
    
  }
  
  

  return NULL; /* TODO */
}

TGRADE * allGrades ( const char * list )
{
  return NULL; /* TODO */
}

TGRADE * combineGrades ( TGRADE * listA, TGRADE * listB )
{
  freeList ( listA ); /* avoid mem leaks if the function is not implemented */
  freeList ( listB );
  return NULL; /* TODO */
}

TGRADE * findStudents ( TGRADE * list, const char * userName )
{
  return NULL; /* TODO */
}

#ifndef __PROGTEST__
void freeList ( TGRADE * l )
{ /* this implementation exists in the testing environment */
  while ( l )
  {
    TGRADE * tmp = l -> m_Next;
    free ( l );
    l = tmp;
  }
}

int gradeCount    ( TGRADE * list, const char * username, const char * date, char grade )
{
  return 0; /* TODO */
}
int listLength    ( TGRADE * list )
{
  return 0; /* TODO */
}
int gradeMatch   ( TGRADE * list, int pos, const char * username, const char * date, char grade )
{
  return 0; /* TODO */
}
int main ( void )
{
  const char * str1 =
    "{ langsamu ; 2020-11-24 ; Good }{chucknorris;2020-12-3;ExcellenT}\n"
    "{    langsamu   ;   2020-4-15   ;    Fauled   }\n"
    "{ langsamu ; 2020-07-03 ; Suficient }\n"
    "{ langsamu ; 2020-04-15 ; Failed }";
  const char * str2 =
    "{ langsamu ; 2020-04-15 ; Foiled }\n"
    "{ langsamu ; 2020-11-24 ; Good }\n"
    "{ langsamu ; 2020-11-24 ; VeryGood }\n"
    "{ langsamu ; 2020-11-24 ; Good }\n"
    "{ Slartibartfast42; 2020-04-15 ; Satisfactory }";
  const char * str3 =
    "{chucknorris;2020-12-3;ExcellenT}\n"
    "{ bond007 ; 2020-11-24 ; Good }\n"
    "{ Slartibartfast42; 2020-04-15 ; Satisfactory }";
  TGRADE * l, * tmp;

  l = allGrades ( str1 );
  assert ( listLength ( l ) == 4 );
  assert ( gradeMatch ( l, 0, "langsamu", "2020-11-24", 'C' ) );
  assert ( gradeMatch ( l, 1, "chucknorris", "2020-12-03", 'A' ) );
  assert ( gradeMatch ( l, 2, "langsamu", "2020-04-15", 'F' ) );
  assert ( gradeMatch ( l, 3, "langsamu", "2020-04-15", 'F' ) );
  freeList ( l );

  l = ownGrades ( str1 );
  assert ( listLength ( l ) == 3 );
  assert ( gradeMatch ( l, 0, "langsamu", "2020-11-24", 'C' ) );
  assert ( gradeMatch ( l, 1, "langsamu", "2020-04-15", 'F' ) );
  assert ( gradeMatch ( l, 2, "langsamu", "2020-04-15", 'F' ) );
  freeList ( l );

  l = combineGrades ( allGrades ( str1 ), allGrades ( str2 ) );
  assert ( listLength ( l ) == 7 );
  assert ( gradeCount ( l, "chucknorris", "2020-12-03", 'A' ) == 1 );
  assert ( gradeCount ( l, "langsamu", "2020-11-24", 'B' ) == 1 );
  assert ( gradeCount ( l, "langsamu", "2020-11-24", 'C' ) == 2 );
  assert ( gradeCount ( l, "Slartibartfast42", "2020-04-15", 'D' ) == 1 );
  assert ( gradeCount ( l, "langsamu", "2020-04-15", 'F' ) == 2 );
  freeList ( l );

  l = allGrades ( str3 );
  tmp = findStudents ( l, "rs" );
  assert ( listLength ( tmp ) == 2 );
  assert ( gradeCount ( tmp, "chucknorris", "2020-12-03", 'A' ) == 1 );
  assert ( gradeCount ( tmp, "bond007", "2020-11-24", 'C' ) == 1 );
  freeList ( tmp );

  tmp = findStudents ( l, "ris" );
  assert ( listLength ( tmp ) == 1 );
  assert ( gradeCount ( tmp, "chucknorris", "2020-12-03", 'A' ) == 1 );
  freeList ( tmp );

  tmp = findStudents ( l, "boris" );
  assert ( listLength ( tmp ) == 2 );
  assert ( gradeCount ( tmp, "chucknorris", "2020-12-03", 'A' ) == 1 );
  assert ( gradeCount ( tmp, "bond007", "2020-11-24", 'C' ) == 1 );
  freeList ( tmp );

  freeList ( l );

  return 0;
}
#endif /* __PROGTEST__ */
