#include <stdio.h>
#include <string.h>
void generateMatrix(char key[], char matrix[5][5]) {
    int i, j, k = 0;
    int len = strlen(key);
    int isPresent[26] = {0}; 
    for (i = 0; i < len; i++) {
        if (key[i] == 'j') key[i] = 'i'; 
        if (!isPresent[key[i] - 'a']) {
            matrix[k / 5][k % 5] = key[i];
            isPresent[key[i] - 'a'] = 1;
            k++;
        }
    }
    for (i = 0; i < 26; i++) {
        if (i != ('j' - 'a') && !isPresent[i]) {
            matrix[k / 5][k % 5] = 'a' + i;
            k++;
        }
    }
}
void encrypt(char matrix[5][5], char a, char b) {
    int i, j;
    int row1, col1, row2, col2;
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            if (matrix[i][j] == a) {
                row1 = i;
                col1 = j;
            }
            if (matrix[i][j] == b) {
                row2 = i;
                col2 = j;
            }
        }
    }
    if (row1 == row2) {
        col1 = (col1 + 1) % 5;
        col2 = (col2 + 1) % 5;
    } else if (col1 == col2) {
        row1 = (row1 + 1) % 5;
        row2 = (row2 + 1) % 5;
    } else {
        int temp = col1;
        col1 = col2;
        col2 = temp;
    }
    printf("%c%c%c%c", matrix[row1][col1], matrix[row2][col2], matrix[row1][col2], matrix[row2][col1]);
}
int main() {
    char key[25];
    char matrix[5][5];
	int i;
    printf("Enter the key (up to 25 characters): ");
    scanf("%s", key);

    generateMatrix(key, matrix);

    char plaintext[100];
    printf("Enter the plaintext: ");
    scanf("%s", plaintext);

    int len = strlen(plaintext);
    for(i = 0; i < len; i += 2) {
        char a = plaintext[i];
        char b = (i + 1 < len) ? plaintext[i + 1] : 'x';
        encrypt(matrix, a, b);
    }

    return 0;
}
