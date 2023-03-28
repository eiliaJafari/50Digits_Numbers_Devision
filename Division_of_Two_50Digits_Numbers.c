#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 51

char secondNum[MAX];
char firstNum[MAX];
int q = 0;

char* multiply(char*, char* );
void devAlgorithm();

int main(){
    char *multiplyRes;

    printf("This program is for multiplying and dividing two 50 digits numbers.\n\n");

    printf("Please enter the 1st number(50 digits):\n");
    scanf("%s", firstNum);

    printf("\nPlease enter the 2nd number(50 digits):\n");
    scanf("%s", secondNum);
    printf("\n**********************************************************************");
    printf("\n\n");

    printf("|| Multiplication of two numbers ||\n\n");
    printf("Result:\n");
    multiplyRes = multiply(firstNum,secondNum);
    printf("%s",multiplyRes);
    printf("\n\n######################################################################");
    printf("\n\n\n");

    printf("|| Devision of two numbers ||\n\n");

    int res, temp = 1;

    for(int i = 0; i < temp; i++){

        res = strcmp(firstNum, secondNum);
        temp = temp + 1;

        if(res < 0){
            printf("The Remainder (Baghi Mandeh):\n");
            printf("%s\n\n", firstNum);
            printf("The Quotient (Khareje Ghesmat):\n");
            printf("%d\n\n\n", q);
            break;
        }

        else if(res > 0){
            devAlgorithm();
            i = 0;
        }

        else if (res == 0){
            printf("The Remainder (Baghi Mandeh):\n0\n\n");
            printf("The Quotient (Khareje Ghesmat):\n1\n\n\n");
            break;
        }
    }

    return 0;
}


char* multiply(char* num1, char* num2) {

    int len1 = strlen(num1);
    int len2 = strlen(num2);

    if (len1 == 1 && num1[0] == '1')
        return num2;
    if (len2 == 1 && num2[0] == '1')
        return num1;

    char *result = malloc((len1+len2)*sizeof(char));
    memset(result, '0', (len1+len2)*sizeof(char));

    for (int i = len1-1; i >= 0; i--) {
        int r = 0;
        for (int j = len2-1; j >= 0; j--) {
            int sum = (result[i+j+1] - '0') + (num1[i] - '0') * (num2[j] - '0') + r;
            result[i+j+1] = sum % 10 + '0';
            r = sum / 10;
        }
        result[i] += r;
    }
    return &result[0];
}


void devAlgorithm(){

    int Temp1 = 0, Temp2 = 0, temp = 0;
    char chTemp;

    for(int j = 49; j >= 0; j--){
        chTemp = firstNum[j];
        Temp1 = chTemp - '0';
        chTemp = secondNum[j];
        Temp2 = chTemp - '0';

        if(Temp1 < Temp2){
            Temp1 += 10;
            chTemp = firstNum[j-1];
            temp = chTemp - '0';
            temp--;
            chTemp = '0' + temp;
            firstNum[j-1] = chTemp;
        }

        temp = Temp1 - Temp2;
        chTemp = '0' + temp;
        firstNum[j] = chTemp;
    }
    q = q + 1;
}
