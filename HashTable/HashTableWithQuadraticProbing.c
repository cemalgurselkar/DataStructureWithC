#include <stdio.h>
#include <string.h>
#define TableSize 997

typedef struct s{
    char id[11];
    char name[20];
    float gano;
}student;

student h[TableSize];

void initializeHashTable(){
    int i;
    for (i=0;i<TableSize;i++){
        strcpy(h[i].id,"");
    }
}

int HashFunction(char *key, int size){
    int i,j,k,result;
    // 48 is ASCII code of 0
    i = key[10]-48; //last digit
    j = key[9]-48;  // 2nd digit from last
    k = key[6]-48;  // 5th digit from last

    result = (k*100 + j*10 + i) % size;
    return result;
}

void insert(student r){
    int c,i,p,q;
    p = HashFunction(r.id, TableSize);
    c = 0;
    i = 1;
    q = p;
    while ((strcmp(h[p].id,"")!=0) && (strcmp(h[p].id,r.id)!=0) && (c <= TableSize/2)){
        c++;
        p = q + i * i;
        i++;
        if (p > TableSize-1){
            p = p % TableSize;
        }
    }
    if (strcmp(h[p].id,"")==0){
        strcpy(h[p].id,r.id);
        strcpy(h[p].name,r.name);
        h[p].gano = r.gano;
    }
    else if (strcmp(h[p].id,r.id)==0){
        printf("Error, the same student cannot appear twice\n");
    }
    else{
        printf("Overflow, counter has reached its limit\n");
    }
}
void printHashtable(){
    printf("Hash Table:\n");
    int i;
    for (i=0;i<TableSize;i++){
        if (strcmp(h[i].id,"") != 0){
            printf("Index %d -> ID: %s, Name: %s, GPA: %.2f\n",i,h[i].id,h[i].name,h[i].gano);
        }
        else{
            printf("Index %d -> Empty\n",i);
        }
    }
}

int main() {
    // Hash Table'ı başlat
    initializeHashTable();

    // Öğrenci ekleme
    student s1 = {"12345678901", "Alice", 3.5};
    student s2 = {"23456789012", "Bob", 3.8};
    student s3 = {"34567890123", "Charlie", 2.9};

    insert(s1);
    insert(s2);
    insert(s3);

    // Aynı ID'ye sahip bir öğrenci ekleme
    student duplicate = {"12345678901", "Duplicate Alice", 3.6};
    insert(duplicate);
    printHashtable();
    return 0;
}