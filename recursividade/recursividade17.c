#include <stdio.h>

int function(int x){
    printf("\n Chamada para o numero %d\n", x);
    if(x < 0){
        printf("erro: numero digitado invalido");
        
    }
    if(x ==0){
        return 1;
    } else{
        return (x * function(x-1));
    }
}

int main(){
    
    int a, x;
    printf("digite um numero");
    scanf("%d", &a);
    x = function(a);
    printf("\nO fatorial de %d eh %d", a, x);

}