#include <stdio.h>
#include <math.h>

#include "Functionality.h"
#define twoToPowerTwelve 4094
#define Max12BitValue 32768
#define NthBitCalculate(n)(int)(pow(2,n) -1)
#define Half  500

#define Converter(x)  ((int)(x*1000)%1000)


int A2DConverter(int LSBValue,int bit)
{
    int MaxValue = NthBitCalculate(bit);
    float f,ReturnVal;
    
    ReturnVal = ((float)(LSBValue)*10)/(MaxValue);
    f = Converter(ReturnVal);
    
    if(f>=Half)
    {
        ReturnVal = ceil(ReturnVal);
    }
    else
    {
        ReturnVal = floor(ReturnVal);
    }
    
    return (int)ReturnVal;
  
}
int * RemoveUnwanted(int arr[],int bit)
{ 
    const int len = 7;
    printf("SHad %d " , len);
    int threshold = NthBitCalculate(bit);
    static int r[len];
    for(int i=0;i<len;i++)
    {
        if(arr[i]<=threshold)
        {   
            r[i] = arr[i];
        }
        else{
           r[i] = Max12BitValue;
            
          
        }
    }
    return r;
}
