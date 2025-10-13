/*Faça uma função recursiva para calcular o mdc de dois inteiros positivos. Sabe-se que:
mdc(x,y) = y se y<=x e x%y igual a zero
mdc(x,y) = mdc(y,x) se x<y
mdc(x,y) = mdc(x, x % y)*/

#include <stdio.h>

int mdc(int x, int y){
    if(y <= x && x % y == 0)
        return y;

    if(x < y)
        return mdc(y, x);

    return mdc(x, x % y);
}

int funcaoSecundaria(){
    int x, y, valorMDC;

    printf("Forneça o x e o y: ");
    scanf("%d %d", &x, &y);

    valorMDC=mdc(x,y);

    printf("\nMDC(%d, %d) = %d\n", x, y, valorMDC);

    return 0;
}

int main(){
    return funcaoSecundaria();
}