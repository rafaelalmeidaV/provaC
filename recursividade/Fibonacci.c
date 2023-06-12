#include <stdio.h>
#include <stdlib.h>


int fibonacci(int n){
 
    if (n == 1 || n == 2){
        return 1;
        
    }
    else{
        return fibonacci(n-1) + fibonacci(n-2);
    }
}

int main(){
    int n;
    int i,x;
    printf("\ndigte um numero");
    scanf("%d", &n);

    
    for(i = 0 ; i < n; i++){
        x = fibonacci(i+1);
        printf("%d ", x);       
    }
     
}