#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "charging.h"

extern int A2DConverter(int LSBValue,int bit);
extern int *RemoveUnwanted(int Arr[],int bit);

int main(void)
{
 
 int current_samples1[]={};                      /*Empty Array it should return counter as 0 by default limit 1,1*/
 int current_samples2[]={1};                     /* Single element it should return 1  by default limit 1,1*/
 int current_samples3[]={1,1,1,1,1,1,1};         /* All same element it should return 7 by default limit 1,1 */
 int current_samples4[]={3, 3, 5, 4, 10, 11,12}; /* Given use case  3-5 it should return 4*/
 int current_samples5[]={3, 3, 5, 4, 10, 11,12}; /* Given use case  12-12 it should return 3*/
 int current_samples6[]={1,2};                   /* Small array of length 2*/
 int current_samples7[]={1,1,1,1,1,1,1};         /* Failure case outside limit*/
 int current_samples8[]={3,2,1,0,-1,-2,-3};       /* negative value*/
  
 int Sample1[] = {0,1,1024,4096,2048,4094,6000};
 int *p,leng;
 p = RemoveUnwanted(Sample1,12);
 leng = LEN(Sample1);
 for(int i=0;i<leng;i++)
 {
  if(*(p+i)!=32768){
  printf("%d --> \n ", A2DConverter(*(p+i),12));
  }
  
 }
return 0;
  
}
