#include <stdio.h>
#include "test.h"

//自定义一个“装置”结构体
typedef struct {
   int status;
   void (*statusChange)();     //回调函数格式
}T_Device;

T_Device g_Device;

void addCallbackFunc(void (*pstatusChange)(int status)){    //注册回调函数
   g_Device.statusChange = pstatusChange;
}

void run(){
   g_Device.status = 10;
   if (g_Device.status == 10){
      if(g_Device.statusChange != NULL){
         g_Device.statusChange(g_Device.status);
      }
   }
}

//用户代码
void callBack(int status){
   printf("stauts = %d\n",status);
}

void Write(const char* plistdata,int len){
   char *mdata = (char *)malloc(len);     //申请一块空间
   memcpy(mdata,plistdata,len);     //数据拷贝

   /*TODO*/

   free(mdata);      //释放空间
}

void main(){
   //当用户需要使用回调函数时需要把回调触发的函数注册到回调结构体里面
   addCallbackFunc(callBack);
   run();
}
