#include <stdio.h>
#include <math.h>

int hash(char *key, int tableSize){
    int hashVal = 0;
    int i;
    for (i=0;key[i]!='\0';i++){
        hashVal += key[i];
    }
    return hashVal % tableSize;
}

int hash2(char *key, int tableSize){
    return (key[0]+27 * key[1] + 729*key[2]) % tableSize;
}

int hash3(char *key, int tableSize){
    int hashval = 0;
    int i;
    for (i=0;key[i]!='\0';i++){
        hashval = hashval + key[i] * pow(37,i);
    }
    hashval = hashval % tableSize;
    if (hashval < 0){
        hashval += tableSize;
    }
    return hashval;
}

int main() {
    char *keys[] = {"key1", "key2", "hello", "world", "hash"};
    int tableSize = 10;

    printf("Hashing Results:\n");
    for (int i = 0; i < 5; i++) {
        printf("Key: %s\n", keys[i]);
        printf(" - hash1: %d\n", hash(keys[i], tableSize));
        printf(" - hash2: %d\n", hash2(keys[i], tableSize));
        printf(" - hash3: %d\n", hash3(keys[i], tableSize));
        printf("\n");
    }

    return 0;
}