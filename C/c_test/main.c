#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <ctype.h>  //判斷是不是英文或數字
#define max(a,b) ((a) > (b) ? (a) : (b))
#define min(a,b) ((a) < (b) ? (a) : (b))

//函式庫
// https://www.cs.ccu.edu.tw/~hst95u/BestSteve/CStandardLibrary.html#string.h

// function 應用, 不回傳

void swap(int *a, int *b){ //位子交換

   int t = *a;
   *a = *b;
   *b = t;

}

void mar_swap(int *a, int *b){ //位子交換

 int t = *a;
     *a = *b;
     *b = t;

}

void print(int **v, int v_r,int v_c){  //二維陣列,印出

  for(int i =0; i < v_r; i++){
      for(int j=0; j < v_c; j++){

       printf("%d ",v[i][j]);
      }
      printf("\n");
   }
}

// function 應用, 回傳

double add(double a,double b){ //加法

   double c =  a +c;
   printf("%f \n",c);

   return c;

}


bool bo(int a, int b){  //比大小

   if(a > b){

     return true;
   }else{

     return false;
   }

}


double* dous(int size,int arr[]){  //一維陣列回傳,浮點數

  double *arrays = malloc(size * sizeof(double));

  for(int i = 0; i < size; i++){

          arrays[i] = arr[i] *2;
  }

  return arrays;
}


int* ints(int size,int init){ //一維陣列回傳,正整數

    int *arr = malloc(size * sizeof(int));

    for(int i =0; i < size; i++){

            arr[i] = init;
    }

   return arr;
}

int** sec_array(int v_r,int v_c,int **v){ //回傳二維陣列

    //產生新陣列後回傳

   int **arr = malloc(v_r*sizeof(int*));

   for(int i = 0; i < v_r; i++){

       arr[i] = malloc(v_r*sizeof(int));
   }

   for(int i =0; i < v_r; i++){
      for(int j=0; j < v_c; j++){

       arr[i][j] = v[i][j]*2;
      }
   }

   return arr;
}


int** arr_com(int data_r,int data_c,int **data){ //回傳二維陣列

    int **arr = malloc(data_r*sizeof(int*));

    for(int i=0; i < data_r; i++){

        arr[i] = malloc(data_c*sizeof(int));
    }

    for(int i=0; i < data_r; i++){
        for(int j=0; j < data_c; j++){

            arr[i][j] = data[i][j]*data[i][j];
        }
    }

    return arr;
}


int compare(const void *a,const void *b) { //qsort 排序法,重要
    int *x = (int *) a;
    int *y = (int *) b;
    return *x - *y;
}

// 宣告 struct
struct student{

int id;
char name[10];

};

struct d_s{

int x;
int y;
float dis;

};



//tree 應用
int binarytree[20] = {0}; //全域宣告

void CreateTree(int data[], int n){

   int node = 1;

   for(int i=0; i < 20; i++){
       binarytree[i] = 0;
    }
   for(int i=0; i <n; i++){

        binarytree[node] = data[i];
        node++;
   }

}

void Preorder(int node){ //前序追蹤 ,中 -> 左 -> 右

   if(binarytree[node]!=0){

     if(binarytree[node]!=0){
         printf("%d ",binarytree[node]);
     }

     Preorder(2*node); //左子樹
     Preorder(2*node+1); //右子樹
   }

}

void Inorder(int node){  //中序追蹤 ,左 -> 中 -> 右

   if(binarytree[node]!=0){

        Inorder(2*node); //左子樹

    if(binarytree[node]!=0){
        printf("%d ",binarytree[node]);
    }
        Inorder(2*node+1);
   }
}

void  Postorder(int node){  //後續追蹤 ,左 -> 右 -> 中

  if(binarytree[node]!=0){

    Postorder(2*node);
    Postorder(2*node+1);

    if(binarytree[node]!=0){
        printf("%d ",binarytree[node]);
    }
  }

}

struct ListNode { //鏈結串列宣告

      int val;
      struct ListNode *next;
  };


// 鏈結串列建立
struct ListNode *createlist(int *arr, int size){

    struct ListNode *first,*curr,*prev;

    for(int i=0; i < size; i++){

        //建立node
        curr = malloc(1*sizeof(struct ListNode));
        curr->val = arr[i];

        if(i==0){

            first = curr;

        }else{

            prev->next = curr;
        }

        curr->next = NULL;
        prev = curr;
    }

    return first;

};



int main(){

//sort------------------------------------------------------------------
  /*
  //int arr[] = {9,16,13,25,21,12,7,10,35};
  int arr[] ={14,18,11,14,12,13};
  const int arr_size = sizeof(arr)/sizeof(arr[0]);
  int ans = 0;

  qsort (arr, arr_size, sizeof(int), compare);

  for(int i=0; i<arr_size; i++){

    printf("%d ",arr[i]);
  }

  const int mix = 40;
  int curr = 0;

  for(int i =0; i < arr_size; i++){

    curr += arr[i];

    if(curr >= mix){

        printf("\ncurr: %d",curr);
        printf(" %d ",arr[i] );

        ans+=1;
        curr=arr[i];

    }

  }

  printf("\ncurr: %d",curr);

  if(curr!=0) ans+=1;

  printf("\nans: %d",ans);
  */

//泡沫排序法
/*
   int arr[] = {10,21,3,45,5,63,6,1};
   int length = sizeof(arr)/sizeof(arr[0]);
   printf("length= %d \n",length);

   bool found = true;

   while(found){

          found = false;

          for(int i = 0; i< length-1;i++){

                if(arr[i] > arr[i+1]){

                    int t = arr[i];
                    arr[i] = arr[i+1];
                    arr[i+1] = t;

                    found = true;
                }
          }
   }

   for(int j = 0; j < length;j++){

          printf("%d ",arr[j]);
   }
*/

//讀取資料----------------------------------------------------------------------------
/*
//讀取資料 int

   int data[3][4] = {0};
   const int data_r = sizeof(data)/sizeof(data[0]);
   const int data_c = (sizeof(data)/sizeof(data[0][0]))/(sizeof(data)/sizeof(data[0]));

   FILE *fp = fopen("125.txt","r");  //陣列文件

   if(fp==NULL){

    printf("None File");
    return -1;
   }

   for(int i = 0; i< data_r; i++){

       for(int j = 0; j < data_c; j++){

        fscanf(fp,"%d",&data[i][j]);

       }

       fscanf(fp,"\n");

   }

   fclose(fp);

   //print

   for(int i = 0; i< data_r; i++){

       for(int j = 0; j < data_c; j++){

        printf("%d ",data[i][j]);

       }

       printf("\n");
   }

   int *data_p[3] = {data[0],data[1],data[2]};

   //回傳新的陣列,做運算
   int **new_data = arr_com(data_r,data_c,data_p);


   for(int i = 0; i< data_r; i++){

       for(int j = 0; j < data_c; j++){

        printf("%d ",new_data[i][j]);

       }

       printf("\n");
   }

*/
   //讀取檔案 amazon q1-q2
   // q1
   /*
   FILE *fp =fopen("amazon_q1.txt","r");

   int max = 0;
   int size = 0;

   if(fp == NULL){

    printf("none file...");
    return -1;
   }

   fscanf(fp,"%d %d/n",&size,&max); //寫入記憶體
   printf("size: %d, max: %d",size,max);

   //建立資料
   int *data = malloc(size*sizeof(int));

   for(int i =0; i < size; i++){

       fscanf(fp,"%d ",&data[i]);
       printf("\ndata: %d",data[i]);
   }

    qsort(data,size,sizeof(int), compare);
    printf("\n");

    for(int j =0; j < size; j++){
        printf("%d ",data[j]);
    }
    */

    // q2
    /*

    FILE *fp = fopen("amazon_q2.txt","r");

    int size = 0;

    fscanf(fp,"%d ",&size);

    printf("size: %d \n",size);

    int **data = malloc((size+1)*sizeof(int*));

    // 建立陣列與讀取資料
    for(int i=0; i < (size+1); i++){

        data[i] = malloc(2*sizeof(int));
        fscanf(fp, "%d ",&data[i][0]);
        fscanf(fp, "%d ",&data[i][1]);
    }


    for(int i=0; i< (size+1); i++){
        for(int j=0; j< 2; j++){

            printf("%d ",data[i][j]);

        }
        printf("\n");

    }

    printf("data size: %d ",size+1);

    free(data);
    */

    //scanf q1
    /*
    int size = 0;
    int max = 0;

    scanf("%d",&size);
    scanf("%d",&max);

    printf("size: %d\n",size);
    printf("max: %d\n",max);

    int *data = malloc(size*sizeof(int));

    for(int i=0; i < size; i++){
        scanf("%d",&data[i]);
    }
    printf("\n");

    for(int j=0; j < size; j++){
        printf("%d ",data[j]);
    }
    */

    //scanf q2
    /*
    int size = 0;

    scanf("%d",&size);
    printf("size: %d\n",size);

    int **data = malloc((size+1)*sizeof(int*));

    for(int i=0; i< (size+1); i++){
        printf("row:%d\n",i+1);

        data[i] = malloc(2*sizeof(int));
        scanf("%d",&data[i][0]);
        scanf("%d",&data[i][1]);
    }

    for(int i=0; i < (size+1); i++){
        for(int j=0; j < 2; j++){

            printf("%d ",data[i][j]);
        }
        printf("\n");
    }
    */


   //讀取資料 char
/*
   char data[4][101] ={0};
   const int data_r = sizeof(data)/sizeof(data[0]);
   const int data_c = (sizeof(data)/sizeof(data[0][0]))/(sizeof(data)/sizeof(data[0]));

   printf("r: %d ,c: %d \n",data_r,data_c);

   FILE *fp = fopen("135.txt","r");


   if(fp==NULL){

    printf("None FILE...");
    return -1;
   }

   for(int i = 0; i < data_r; i++){
      for(int j = 0; j < data_c; j++){

        fscanf(fp,"%c",&data[i][j]);

      }

    fscanf(fp,"\n");
   }

   fclose(fp);



   for(int i = 0; i< data_r; i++){

       for(int j = 0; j < data_c; j++){

        printf("%c",data[i][j]);

       }

       printf("\n");
   }
*/


//數學函式-----------------------------------------------------------------------

/*
//數學函式
#include <math.h>
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))

printf("pow: %f ",pow(2,3));
printf("sprt: %f ",sqrt(25));
printf("abs: %d ", abs(-112.0));
printf("max: %f ",max(2.0,5.0));
printf("min: %f ",min(2.0,5.0));

char a = 'a';
char A = 'A';


printf("%d \n", 'a'-a);
printf("%d \n", 'z'-a);
printf("%d \n", 'A'-A);
printf("%d \n", 'Z'-A);
*/


//轉型-----------------------------------------------------------------------
/*
//轉型

  int a = 10;
  float a_f = (float)a;   //int to float
  printf("%f ",a_f);
  int a_i = (int)a_f;     //float to int
  printf("%d ",a_i);


  char b[2] = "11";
  printf("%s ",b);
  int b_i = atoi(b);      //char to int
  printf("%d ",b_i+1);
  char b_c[10];
  itoa(b_i,b_c,sizeof(b_c));   //int to char
  printf("%s \n",b_c);

  char s[10] = "jack,chad";
  //printf("len: %d \n",(sizeof(s)/sizeof(s[0])));

  for(int i = 0; i < strlen(s);i++){

          printf("%c",s[i]);
  }
*/

//函數呼叫--------------------------------------------------------------

// function 應用
/*
  double ans = add(10.1,22.6);
  printf("%f \n",ans);
  bool ans_bo = bo(20,2);
  printf("%d \n",ans_bo); //print out 1 is true

  //交換
  int c = 10;
  int d = 5;
  printf("c:%d ,d:%d \n",c,d);
  swap(&c,&d);
  printf("c:%d ,d:%d \n",c,d);

  //陣列交換
  int z[10] = {0};
  int len = (sizeof(z)/sizeof(z[0]));

  for(int i=0; i < len; i++){
      z[i] = i+1;
  }

  for(int j=0; j < len; j++){
      printf("%d ",z[j]);
  }

  printf("\n");
  for(int k=0; k < len-1;k++){

      mar_swap(&z[k],&z[k+1]);
  }

  for(int j=0; j < len; j++){

      printf("%d ",z[j]);
  }

  printf("\n\n");

  char stt[] = "asdfg";

  printf("size(strlen) : %d \n",strlen(stt));
  printf("size(sizeof): +1(/0結尾) %d ",sizeof(stt)/sizeof(stt[0]));
*/

//陣列----------------------------------------------------------------------


  //回傳陣列
  //part 1  double
  /*
  int o[] = {1, 2, 3, 4, 5, 6, 7, 7};
  int size = sizeof(o)/sizeof(o[0]);

  double *new_o = dous(size, o);

  for(int j=0; j < size; j++){

      printf("%d ",o[j]);
  }

  printf("\n");

  for(int j=0; j < size; j++){

      printf("%f ",new_o[j]);
  }
  new_o[0] = 0;
  new_o[1] = 0;

  printf("\n");
  for(int j=0; j < size; j++){

      printf("%f ",new_o[j]);
  }
  */

  //part 2
  /*
  int a = 15; //size
  int b = 11;

  int *arr= ints(a, b);
  int len  = sizeof(arr)/sizeof(arr[0]);
  printf("size: %d\n",len);  //會有問題長度是2
  printf("real size: %d\n",a);

  for(int j=0; j < a; j++){
      printf("%d ",arr[j]);
  }
  */

  //part3 二維 void 印出
  /*
  int v[][3]={{1,2,3},{4,4,5},{6,5,3},{9,4,1}};
  int v_r = sizeof(v)/sizeof(v[0]);
  int v_c = (sizeof(v)/sizeof(v[0][0]))/(sizeof(v)/sizeof(v[0]));

  printf("R: %d\n",v_r);
  printf("C: %d\n",v_c);

  int* p[4] = {v[0],v[1],v[2],v[3]}; //二維陣列需要產生這個p

  print(p,v_r,v_c);
  printf("\n");

  //二維 回傳
  int **arrs =  sec_array(v_r,v_c,p);

  for(int i = 0; i < v_r;i++){
    for(int j = 0; j < v_c; j++){

       printf("%d ",arrs[i][j]);
    }
     printf("\n");
  }
  */



  //二維陣列
  /*

  int v[5][10] = {0};

  int size_r = sizeof(v)/sizeof(v[0]);
  int size_c = sizeof(v)/sizeof(v[0][0]) / (sizeof(v)/sizeof(v[0]));

  printf("R: %d\n",size_r);
  printf("C: %d\n",size_c);

  for(int i = 0; i < size_r;i++){
    for(int j = 0; j < size_c; j++){

       printf("%d",v[i][j]);
       v[i][j] += j;
    }
     printf("\n");
  }

  for(int i = 0; i < size_r;i++){
    for(int j = 0; j < size_c; j++){

       printf("%d",v[i][j]);
    }
     printf("\n");
  }

  */

  // 二維陣列不同維度
  /*
  int **arr = malloc(5*sizeof(int*));


  for(int i =0; i< 5; i++){

    arr[i] = malloc((i+1)*sizeof(int));
  }


  for(int i=0; i<5; i++ ){

      for(int j=0; j<=i; j++ ){

          arr[i][j] = i+j;
          printf("%d",arr[i][j]);
      }

    printf("\n");
  }
  */

  // 二維陣列中 row列印與col列印
  /*
  int data[][5] = {{1,5,6,7,8},{5,6,7,1,1},{0,3,6,9,4},{1,5,5,3,0}};
  const int data_r_size = sizeof(data)/sizeof(data[0]);
  const int data_c_size = (sizeof(data)/sizeof(data[0][0]))/(sizeof(data)/sizeof(data[0]));

  printf("row: %d, col: %d\n",data_r_size,data_c_size);
  //row
  for(int i =0; i< data_r_size; i++){
    for(int j = 0; j < data_c_size; j++){

        printf("%d ",data[i][j]);
    }
    printf("\n");
  }
  printf("\n");
  // col
  for(int i =0; i < data_c_size; i++){
    for(int j = 0; j < data_r_size;j++){
        printf("%d ",data[j][i]);
    }
    printf("\n");
  }
  */


  // 陣列中尋找最多的值
  /*

  int vec[] = {10,16,16,16,16,18,18,12,11,11,12,10,12};
  const int vec_size = sizeof(vec)/sizeof(vec[0]);
  int count = 1;
  int ans,max_count = 0;

  printf("vec size: %d\n",vec_size);

  //排序
  qsort(vec, vec_size, sizeof(int), compare);

  for(int i = 0; i < vec_size; i++){

    printf("%d ",vec[i]);

  }

  //尋找最多
  int compares = vec[0];

  for(int j =1; j <= vec_size; j++){


    if(vec[j] == compares){

        count++;

    }else{

      //printf("\ncompare-> %d, %d ",max_count,count);

      if(max_count < count){

        max_count = count;
        ans = vec[j-1];
      }
      compares = vec[j];
      count = 1;

    }
  }

printf("\nans:%d ",ans);

*/

// struct 用法 ----------------------------------------------------------
// struct結構在上方
/*
struct student john = {291, {'j', 'o', 'h', 'n', '\0'}};

john.id = john.id +1000;

printf("學號：%d\n", john.id);
printf("姓名：%s\n", john.name);
printf("\n");
*/

// tree 用法----------------------------------------------------------------
/*
int n;
printf("請輸入節點數個數: ");
scanf("%d",&n); //節點數個數

int *data = malloc(20*sizeof(int));

printf("請輸入節點數值: ");
for(int i=0; i < n; i++){
    scanf("%d",&data[i]);
}

CreateTree(data,n);      //建立tree
printf("Preorder:\n");
Preorder(1);             //前序追蹤
printf("\nInorder:\n");
Inorder(1);              //中序追蹤
printf("\nPostorder:\n");
Postorder(1);            //後續追蹤
*/

//練習--------------------------------------------
// 題目 https://www.geeksforgeeks.org/find-k-closest-points-to-the-origin/
// size = 3, point = [[3, 3], [5, -1], [-2, 4]], K = 2
// size = 2, point = [[1, 3], [-2, 2]], K  = 1
/*
printf("size: ");
int size = 0;
scanf("%d",&size);

int **data = malloc(size*sizeof(int*));
printf("data: ");
for(int i =0; i < size; i++){
    data[i] = malloc(2*sizeof(int));
    scanf("%d",&data[i][0]);
    scanf("%d",&data[i][1]);
}

int k = 0;
printf("k =");
scanf("%d",&k);

float *distance = malloc(size*sizeof(float));

for(int i=0; i < size; i++){

    float p1 = pow((0-data[i][0]),2);
    float p2 = pow((0-data[i][1]),2);

    distance[i] = sqrt(p1 + p2);

}

//data結構
struct d_s *data_struct = malloc(size*sizeof(struct d_s));  //結構宣告

for(int i = 0; i < size; i++){

    struct d_s d = {data[i][0],data[i][1],distance[i]};
    data_struct[i] = d;
}

//sort
qsort (distance, size, sizeof(float), compare);

for(int i=0; i < size; i++){
    printf("%f ",distance[i]);
}
printf("\n[");

for(int i=0; i < k; i++){

    for(int j=0;j < size; j++){

        if(distance[i]==data_struct[j].dis){

            printf("[%d ,%d]",data_struct[j].x,data_struct[j].y);
            break;
        }
    }

}
printf("]");
*/

// Link List 鏈結串列 https://lakesd6531.pixnet.net/blog/post/329288496
//建立串列
/*
struct ListNode *first;
int arr[] = {14,27,32,46,50};
int arr_size = sizeof(arr)/sizeof(arr[0]);
first = createlist(arr,arr_size);

while(first!=NULL){

    printf("val: %d,next: %p\n",first->val,first->next);
    first = first->next;
}
*/


    return 0;
}
