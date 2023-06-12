#include <stdio.h>

int function(int m){
    if(m == 1){
        printf("%d", m);
        
    }else{
        
        function(m-1);
        printf("%d", m);
    }
}

int main(){
    int m;

    printf("Digite um numero inteiro: ");
    scanf("%d", &m);

    function(m);

    
    
}