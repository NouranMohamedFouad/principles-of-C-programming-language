#include <stdio.h>
#include <stdlib.h>
#include "builtInFunctions.h"
#include <string.h>

#define SIZE 50
#define TERMINATOR '\0'

int main()
{
    char str[SIZE]="mmm";
    char source[]="xyz";
    //voidStringCat(str,source);
    //printf("\nsize of the array is: %d ",intGetStringLength(str));
    //printf("\n result of the array is:  %d ",intStringComp(str,source));
    //printf("\n result of the str comp is:%d", strcmp(str,source));
    //voidStringCopy(str,source,SIZE);
    //printf("\nresult of the str cpy is: %s",strcpy(str,source));
    char str2[]="xY1wwZ";
    //voidStringToLower(str2);
    //voidStringToHigher(str2);
    //printf("\nresult of the str lower is: %s",strlwr(str2));

    return 0;
}
///////////////////////////////////////////
int intStringLength(char str[])
{
    int i=0;
    while(str[i] != TERMINATOR ){
        i++;
    }
    return i;
}
///////////////////////////////////////////
void voidStringCat(char dest[],char source[])
{
    printf("\nbefore concatenation: %s",dest);

    int i=0;
    while(dest[i] != TERMINATOR){
        i++;
    }
    int j=0;
    while(source[j] != TERMINATOR){
        dest[i]+=source[j];
        i++;
        j++;
    }
    printf("\nafter concatenation: %s",dest);
}
///////////////////////////////////////////
int intStringComp(char dest[],char source[])
{
    int i=0;
    int j=0;
    int flag=1;
    while(flag)
    {
        if(dest[i] == TERMINATOR && source[j] != TERMINATOR)
        {
            j++;
            flag=0;

        }

        else if(dest[i] != TERMINATOR && source[j] == TERMINATOR)
        {
            i++;
            flag=0;
        }
        else if(dest[i] == TERMINATOR && source[j] == TERMINATOR)
        {
            flag=0;
        }
        else if(dest[i]==source[j])
        {
            i++;
            j++;
        }
         else if(dest[i]>source[j])
        {
            return 1;
        }
        else if(dest[i]<source[j])
        {
            return -1;
        }


    }
    if(i==j){
        return 0;
    }
    else if(i>j)
    {
        return 1;
    }
    else if(i<j)
    {
        return -1;
    }
}
//////////////////////////////////////////
void voidStringCopy(char dest[],char source[],int sizee)
{
    printf("\nbefore copy: %s",dest);
    if(intStringLength(source)<=sizee-1)
    {
        int i=0;
        while(source[i]!= TERMINATOR)
        {
            dest[i]=source[i];
            i++;
        }
        dest[i]='\0';
        printf("\nafter copy: %s",dest);
    }
    else
    {
        printf("\nsize of the destination is not enough");
    }
}
//////////////////////////////////////////
void voidStringToLower(char str[])
{
    printf("\nBefore conversion: %s",str);

    int i=0;
    while(str[i]!= TERMINATOR)
    {
        if(str[i]>='A' && str[i]<='Z')
        {
            str[i]=str[i]+32;

        }
        i++;
    }
    printf("\nafter conversion: %s",str);


}
//////////////////////////////////////////
void voidStringToHigher(char str[])
{
    printf("\nBefore conversion: %s",str);

    int i=0;
    while(str[i]!= TERMINATOR)
    {
        if(str[i]>='a' && str[i]<='z')
        {
            str[i]=str[i]-32;

        }
        i++;
    }
    printf("\nafter conversion: %s",str);


}
