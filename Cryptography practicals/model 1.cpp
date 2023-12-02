#include<stdio.h>
int main(){
    int key[2][2];
    printf("Enter the 2x2 key matrix:\n");
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            scanf("%d",&key[i][j]);
        }
    }
    while(getchar()!='\n');
    char plaintext[100];
    printf("Enter the plaintext:");
    fgets(plaintext, sizeof(plaintext),stdin);
    printf("Encrypted text:");
    for(int i=0;plaintext[i]!='\0';i++){
    	if(plaintext[i]>='a'&&plaintext[i]<='z'){
        	int x=plaintext[i]-'a';
            int y=plaintext[i+1]-'a';
            int encrypted_x=(key[0][0]*x+key[0][1]*y)%26;
            int encrypted_y=(key[1][0]*x+key[1][1]*y)%26;
            printf("%c%c",encrypted_x+'a',encrypted_y+'a');
            i++; 
        }
    }
    return 0;
}
