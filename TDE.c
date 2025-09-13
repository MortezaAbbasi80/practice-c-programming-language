#include<stdio.h>
#include<string.h>
#include<stdlib.h>



typedef struct  Record  //44 byte
{
    int id;         //4 byte 
    char name[32];   //32 byte 
    int age ;       //4 byte 
    int tombstone;  //4  byte    // flag -> value 1 for delete 
}Record;

typedef struct indexEntry //12 byte
{
    int id ;        //4 byte
    long offset;   // 8 byte
    indexEntry * next;
}indexEntry;

struct HashMap
{
    indexEntry ** buckets;
    int size;
    int count;

};





void set_Record(Record *,int ,char*,int );
//start hashmap functions 
void initializeHashMap(struct HashMap* mp);
int hashFunction(struct HashMap* mp,int id );
void insertHashMap(struct HashMap*,int,long );
long hashMapGet(struct HashMap*,int );
void hashMapRemove(struct HashMap* ,int );
//end hashmap functions 




int main()
{

}


void set_Record(Record *R ,int id ,char* name,int age )
{
    R->id=id;
    strncpy(R->name,name,32);
    R->age=age;
    R->tombstone=0;
}
// strat hashmap functions 
int hashFunction(struct HashMap* HashMap,int id )
{
    int sum = 0;

    sum = (id*31)%HashMap->size;
    return sum;
}

void initializeHashMap(struct HashMap* mp)
{

    // Default size in this case
    mp->size= 100;
    mp->count = 0;

    // array of size = 1
    mp->buckets = (struct indexEntry**)malloc(sizeof(struct indexEntry*)
                                    * mp->size);
    return;
}

void insertHashMap(struct HashMap* mp,int id ,long offset)
{
    int index= hashFunction(mp,id);

    indexEntry * current = mp->buckets[index];

    while (current!=NULL)
    {
        if(current->id==id)
        {
            current->offset=offset;
            return;
        }
        current=current->next;
    }
    
    indexEntry *newEntry = malloc(sizeof(indexEntry));
    newEntry->id=id;
    newEntry->offset=offset;
    
    newEntry->next=mp->buckets[index];
    mp->buckets[index]=newEntry;

    mp->count++;
}

long hashMapGet(struct HashMap* mp,int id )
{
    int index= hashFunction(mp,id );

    return mp->buckets[index]->offset;
}

void hashMapRemove(struct HashMap* mp,int id)
{
    int index=hashFunction(mp,id);

    indexEntry* current = mp->buckets[index];
    indexEntry* prev = NULL;
    while (current!=NULL)
    {
        if(current->id==id)
        {
            if(prev==NULL)
                // in  head 
                mp->buckets[index]=current->next;
            else
            {
                // or middle 
                 prev->next=current->next;
            }
            free(current);
            mp->count--;
            break;;
        }

        prev=current;
        current=current->next;
    }
    
    return;
}

//end hash map functions 











