#include <stdio.h>

//recursive func
void hexDec(int V, char *res, int *i){
    char hex[6] = {'A', 'B' ,'C', 'D', 'E', 'F'};

    int rem = V % 16;
    int quot = V / 16;

    if(quot == 0){
        if(rem > 9){
            res[*i] = hex[rem - 10];
            return;
    }

        else{
            res[*i] = rem + '0'; //'0' converts -1 < int < 10 into char
            return;
        }
    }

    if(rem > 9){
        res[*i] = hex[rem - 10];
        *i += 1; //*i++ doesnt work for incremental purposes
        hexDec(quot, res, i);
    }

    else{
        res[*i] = rem + '0';
        *i += 1;
        hexDec(quot, res, i);
    }
}

int main(){
    int V;
    char res[11] = {};

    scanf("%d", &V);

    int i = 0;

    hexDec(V, res, &i);

    for(i; i >= 0; i--) printf("%c", res[i]);

    printf("\n");

    return 0;
}
