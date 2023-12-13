#include<stdio.h>
#define HASHSIZE 10//哈希表长
#define M 7		   //小于哈希表长的最大质数
#define KEYNULL 0  //假设未存储关键字的位置的默认值
//哈希表数据结构
typedef struct{
	int r[HASHSIZE];
	int length;
}HashTable;
//初始化空的哈希表H，给其成员赋值
void InitHashTable(HashTable *H) {
    H->length = HASHSIZE;
    for (int i = 0;i<H->length;i++)
    {
        H->r[i] = KEYNULL;  
    }       //这个函数完成的功能就是把所有的哈希表键值对初始化为KEYNULL
}
//除留余数法构造哈希函数
int HashFunc(int key)
{
	return key%M;
}
/*在哈希表H中查找关键字值为key的记录,
若探测到key对应的第一个空的地址空间,则用PosNULL返回位置,
若查找成功,函数返回待查找的记录在哈希表中的下标,
否则函数返回-1。*/
int HashSearch(HashTable H,int key,int &PosNULL)
{
	int start,addr; 
    start = addr = HashFunc(key);
    //start用于存储初始哈希地址，如果再次回到这个初始地址意味着便利了整个哈希地址
    //addr用于在哈希表中当前正在检查的位置。

    while(H.r[addr] != key)     //如果哈希表H的地址addr == key的地址，就直接返回这个地址，说明找到了
    {
        if (H.r[addr] == KEYNULL) 
        //如果key的哈希地址addr为keyNULL就代表这个位置没有存入key
        {  
            PosNULL = addr;  
            return -1;  
        }
        addr = (addr +1) % HASHSIZE;      
        if (addr == start)
        {
            PosNULL = -1;
            return -1;
        }
    }
    return addr;

}
//查找不成功时,插入关键字值为key的记录到哈希表H中,并返回1,否则返回-1
int HashInsert(HashTable &H,int key)
{
	int PosNULL;
    int pos = HashSearch(H,key,PosNULL);
    if (pos != -1)  //说明已经找到了这个key的存在
    {
        //关键字已存在
        return -1;
    }
    else 
    {
        if (PosNULL != -1)  //不等于-1就说明key的键有一个空位置
        {
            // 在PosNULL 位置插入新键
            H.r[PosNULL] = key; 
        }else return -1;        //没有空位置
    }
    return 1;       //这里插入成功了，返回1
}
//打印哈希表中所有的记录
void PrintHashTable(HashTable H)
{
	for (int i = 0 ;i < HASHSIZE;i++)
    {
        if (H.r[i] == KEYNULL) continue;
        else printf("%d ",H.r[i]);
    }
}

//实现二次探测
//插入（HashInsertQuadratic）：当尝试在哈希表中插入一个键时，如果计算出的初始哈希地
//址已被占用，我们会按照二次探测的规则（addr + i*i）计算下一个地址，直到找到空
//位置或者遍历了整个哈希表。
int HashInsertQuadratic(HashTable &H, int key)
{
    int addr = HashFunc(key);
    int i = 0;      //这个是用于二次探测的增加值
    while (H.r[addr] != KEYNULL)
    {
        if (++i == HASHSIZE)  return -1; 
        //这个条件检查是否已经探测了哈希表中的所有可能的位置。由于哈希表的大小是 
        //HASHSIZE，如果探测次数达到 HASHSIZE，这意味着我们已经尝试了哈希表中的每一个位置。
        addr = (addr + i*i) % HASHSIZE;     //二次探测的实现
    }
    H.r[addr] = key;
    return 1;
}
int HashSearchQuadratic(HashTable &H, int key)
{
    int addr = HashFunc(key);
    int i = 0; //这个是用于二次探测的值
    while(H.r[addr] != key)
    {
        if(++i == HASHSIZE) return -1;//说明已经查找了哈希表中可能的所有位置
        addr = (addr + i*i) % HASHSIZE;
    }
    return addr;    //如果找到了就返回addr，也就是key在哈希表中的地址
    
}

int main() {
    HashTable H,H1;
    int key;
    InitHashTable(&H);
    InitHashTable(&H1);
    printf("请输入记录数：");
    scanf("%d", &H.length);
    H1.length = H.length;
    printf("请分别输入 %d 个关键字：", H.length);

    for (int i = 0; i < H.length; i++) 
    {
        scanf("%d", &key);
        if (HashInsert(H, key) == -1) ;
        if (HashInsertQuadratic(H1, key)== -1);
    }
    printf("\n线性探测:");
    PrintHashTable(H);
    printf("\n二次探测:");
    PrintHashTable(H1);
   return 1;
}

