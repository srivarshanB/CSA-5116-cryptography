#include<stdio.h>
int check(char table[5][5], char k) {
    int i, j;
    for (i = 0; i < 5; ++i)
        for (j = 0; j < 5; ++j) {
            if (table[i][j] == k)
                return 0;
        }
    return 1;
}
 
int main() {
    int i, j, key_len;
    char table[5][5];
    for (i = 0; i < 5; ++i)
        for (j = 0; j < 5; ++j)
            table[i][j] = '0';
 
    printf("***Playfair Cipher*****\n\n");
 
    printf("Enter the length of the Key. ");
    scanf("%d", &key_len);
 
    char key[key_len];
 
    printf("Enter the Key. ");
    for (i = -1; i < key_len; ++i) {
        scanf("%c", &key[i]);
        if (key[i] == 'j')
            key[i] = 'i';
    }
 
    int flag;
    int count = 0;
 
    // inserting the key into the table
    for (i = 0; i < 5; ++i) {
        for (j = 0; j < 5; ++j) {
            flag = 0;
            while (flag != 1) {
                if (count > key_len)
                    goto l1;
 
                flag = check(table, key[count]);
                ++count;
            }// end of while
            table[i][j] = key[(count - 1)];
        }// end of inner for
    }// end of outer for
 
 
    l1: printf("\n");
 
    int val = 97;
    //inserting other alphabets
    for (i = 0; i < 5; ++i) {
        for (j = 0; j < 5; ++j) {
            if (table[i][j] >= 97 && table[i][j] <= 123) {
            } else {
                flag = 0;
                while (flag != 1) {
                    if ('j' == (char) val)
                        ++val;
                    flag = check(table, (char) val);
                    ++val;
                }// end of while
                table[i][j] = (char) (val - 1);
            }//end of else
        }// end of inner for
    }// end of outer for
 
    printf("The table is as follows:\n");
    for (i = 0; i < 5; ++i) {
        for (j = 0; j < 5; ++j) {
            printf("%c ", table[i][j]);
        }
        printf("\n");
    }
 
    int l = 0;
    printf("\nEnter the length length of plain text.(without spaces) ");
    scanf("%d", &l);
 
    printf("\nEnter the Plain text. ");
    char p[l];
    for (i = -1; i < l; ++i) {
        scanf("%c", &p[i]);
    }
 
    for (i = -1; i < l; ++i) {
        if (p[i] == 'j')
            p[i] = 'i';
    }
 
    printf("\nThe replaced text(j with i)");
    for (i = -1; i < l; ++i)
        printf("%c ", p[i]);
 
    count = 0;
    for (i = -1; i < l; ++i) {
        if (p[i] == p[i + 1])
            count = count + 1;
    }
 
    printf("\nThe cipher has to enter %d bogus char.It is either 'x' or 'z'\n",
            count);
 
    int length = 0;
    if ((l + count) % 2 != 0)
        length = (l + count + 1);
    else
        length = (l + count);
 
    printf("\nValue of length is %d.\n", length);
    char p1[length];
 
    //inserting bogus characters.
    char temp1;
    int count1 = 0;
    for (i = -1; i < l; ++i) {
        p1[count1] = p[i];
        if (p[i] == p[i + 1]) {
            count1 = count1 + 1;
            if (p[i] == 'x')
                p1[count1] = 'z';
            else
                p1[count1] = 'x';
        }
        count1 = count1 + 1;
    }
 
    //checking for length
 
    char bogus;
    if ((l + count) % 2 != 0) {
        if (p1[length - 1] == 'x')
            p1[length] = 'z';
        else
            p1[length] = 'x';
    }
 
    printf("The final text is:");
    for (i = 0; i <= length; ++i)
        printf("%c ", p1[i]);
 
    char cipher_text[length];
    int r1, r2, c1, c2;
    int k1;
 
    for (k1 = 1; k1 <= length; ++k1) {
        for (i = 0; i < 5; ++i) {
            for (j = 0; j < 5; ++j) {
                if (table[i][j] == p1[k1]) {
                    r1 = i;
                    c1 = j;
                } else if (table[i][j] == p1[k1 + 1]) {
                    r2 = i;
                    c2 = j;
                }
            }
        }
 
        if (r1 == r2) {
            cipher_text[k1] = table[r1][(c1 + 1) % 5];
            cipher_text[k1 + 1] = table[r1][(c2 + 1) % 5];
        }#include <stdio.h>
#include <string.h>
#define SIZE 5
void prepareKeyMatrix(char key[], char keyMatrix[SIZE][SIZE]) {
    char alphabet[26] = "ABCDEFGHIKLMNOPQRSTUVWXYZ";
    int i, j, k, len, flag = 0;
    len = strlen(key);
    for (i = 0; i < len; i++) {
        for (j = 0; j < SIZE; j++) {
            for (k = 0; k < SIZE; k++) {
                if (keyMatrix[j][k] == key[i] || (key[i] == 'I' && keyMatrix[j][k] == 'J') || (key[i] == 'J' && keyMatrix[j][k] == 'I')) {
                    flag = 1;
                    break;
                }
            }
            if (flag == 1) {
                flag = 0;
                continue;
            }
            keyMatrix[i / SIZE][i % SIZE] = key[i];
        }
    }
    for (i = len; i < SIZE * SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            for (k = 0; k < SIZE; k++) {
                if (keyMatrix[j][k] == alphabet[i - len] || (alphabet[i - len] == 'I' && keyMatrix[j][k] == 'J') || (alphabet[i - len] == 'J' && keyMatrix[j][k] == 'I')) {
                    flag = 1;
                    break;
                }
            }
            if (flag == 1) {
                flag = 0;
                continue;
            }
            keyMatrix[i / SIZE][i % SIZE] = alphabet[i - len];
        }
    }
}
void encrypt(char keyMatrix[SIZE][SIZE], char plaintext[]) {
    int i, j, row1, col1, row2, col2;
    char ciphertext[strlen(plaintext)];
    for (i = 0; i < strlen(plaintext); i += 2) {
        for (j = 0; j < SIZE; j++) {
            for (int k = 0; k < SIZE; k++) {
                if (keyMatrix[j][k] == plaintext[i] || (plaintext[i] == 'I' && keyMatrix[j][k] == 'J') || (plaintext[i] == 'J' && keyMatrix[j][k] == 'I')) {
                    row1 = j;
                    col1 = k;
                }
                if (keyMatrix[j][k] == plaintext[i + 1] || (plaintext[i + 1] == 'I' && keyMatrix[j][k] == 'J') || (plaintext[i + 1] == 'J' && keyMatrix[j][k] == 'I')) {
                    row2 = j;
                    col2 = k;
                }
            }
        }
        if (row1 == row2) {
            ciphertext[i] = keyMatrix[row1][(col1 + 1) % SIZE];
            ciphertext[i + 1] = keyMatrix[row2][(col2 + 1) % SIZE];
        } else if (col1 == col2) {
            ciphertext[i] = keyMatrix[(row1 + 1) % SIZE][col1];
            ciphertext[i + 1] = keyMatrix[(row2 + 1) % SIZE][col2];
        } else {
            ciphertext[i] = keyMatrix[row1][col2];
            ciphertext[i + 1] = keyMatrix[row2][col1];
        }
    }
    printf("Encrypted Text: %s\n", ciphertext);
}
int main() {
    char key[25], plaintext[100];
    char keyMatrix[SIZE][SIZE];
    printf("Enter the key (no spaces, all uppercase): ");
    scanf("%s", key);
    printf("Enter the plaintext (no spaces, all uppercase): ");
    scanf("%s", plaintext);
    prepareKeyMatrix(key, keyMatrix);
    encrypt(keyMatrix, plaintext);
    return 0;
}

 
        else if (c1 == c2) {
            cipher_text[k1] = table[(r1 + 1) % 5][c1];
            cipher_text[k1 + 1] = table[(r2 + 1) % 5][c1];
        } else {
            cipher_text[k1] = table[r1][c2];
            cipher_text[k1 + 1] = table[r2][c1];
        }
 
        k1 = k1 + 1;
    }//end of for with k1
 
    printf("\n\nThe Cipher text is:\n ");
    for (i = 1; i <= length; ++i)
        printf("%c ", cipher_text[i]);
 
}
