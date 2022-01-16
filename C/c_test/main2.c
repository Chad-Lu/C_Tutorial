#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int B = 2;
void func(int *p){p = &B;}

int main()
{

//     int A = 1, C = 3;
//     int *ptrA = &A;
//     func(ptrA);
//     printf("%d\n", *ptrA);
//

//    char strAry[] = "This is string";
//    char *aryPtr = strAry;
//    int *intPtr = (int*)strAry;
//    printf("\t[Line01] strAry=%s\n", strAry); //This is string
//    printf("\t[Line02] aryPtr=%s\n", aryPtr); //This is string
//  //printf("\t[LineX] *aryPtr=%s\n", *aryPtr); // Segment fault
//    printf("\t[Line03] sizeof(aryPtr)=%d\n", sizeof(aryPtr)); //4
//    printf("\t[Line04] sizeof(*aryPtr)=%d\n", sizeof(*aryPtr)); //1
//    printf("\t[Line05] *aryPtr=・%c・\n", *aryPtr); //'T'
//    printf("\t[Line06] *aryPtr+1=・%c・\n", *aryPtr+1); //'U'
//    printf("\t[Line07] *(aryPtr+1)=・%c・\n", *(aryPtr+1)); //'h'
//    printf("\t[Line08] sizeof(intPtr)=%d\n", sizeof(intPtr)); //4
//    printf("\t[Line09] sizeof(*intPtr)=%d\n", sizeof(*intPtr)); //4
//    printf("\t[Line10] intPtr=%s\n", intPtr); //This is string
//  //printf("\t[LineX] *intPtr=%s\n", *intPtr); // Segment fault
//    printf("\t[Line11] *intPtr=・%c・\n", *intPtr); //'T'
//    printf("\t[Line12] *intPtr+1=・%c・\n", *intPtr+1); //'U'
//    printf("\t[Line13] *(intPtr+1)=・%c・\n", *(intPtr+1)); //' '


    int arr[] = {10,20,30,40,50};
    int *ptr1 = arr;
    int *ptr2 = arr+5;
    printf("%d\n", (ptr2-ptr1));               //5
    printf("%d, %d:\n",(char*)ptr2,(char*)ptr1);
    printf("%d\n", (char*)ptr2 - (char*)ptr1); //20



//      char *str[ ][2] ={"professor","Justin","teacher","Momor","student","Caterpillar"};
//      char str2[3][10] = {"professor", "Justin", "etc"};
//
////      printf("size:%d\n",(sizeof(str)/sizeof(str[0][0]))/(sizeof(str)/sizeof(str[0])));
//      printf("%s\n", str[1][1]); //Momor
//      printf("%c\n",str2[1][1]); //u

//    unsigned long v1 = 0x00001111;
//    unsigned long v2 = 0x00001202;
//    unsigned long v;
//
//
//    printf("v2:%x\n",~v2);
//    v = v1 &(~v2);
//
//    printf("v:%x\n", v);
//
//    v = v | v2;
//
//    printf("v:%X\n",v);

    return 0;
}
