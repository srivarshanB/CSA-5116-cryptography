#include<stdio.h>
#include<string.h>
int main() {
    char alpha[100] = "abcdefghijklmnopqrstuvwxyz", key[100] = "zyxwvutsrqponmlkjihgfedcba", plain[100], cipher[100];
    int m = 0, index[100];
    printf("Enter plain text: ");
    scanf("%s", plain); 
    int length = strlen(plain);
    for (int i = 0; i < length; i++) {
        for (int j = 0; j < strlen(alpha); j++) {
            if (plain[i] == alpha[j]) {
                index[m] = j;
                m++;
            }
        }
    }
    printf("Cipher text: ");
    for (int i = 0; i < length; i++) {
        cipher[i] = key[index[i]];
        printf("%c", cipher[i]);
    }
    printf("\nPlain text: ");
    for (int i = 0; i < length; i++) {
        plain[i] = alpha[index[i]];
        printf("%c", plain[i]);
    }
    return 0;
}

