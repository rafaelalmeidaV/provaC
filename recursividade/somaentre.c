#include <stdio.h>

int function(int m, int n){
    int soma = 0;
    if (n == 0){
        return m;
    } else{
        return 1 + function(m, n-1);
    }
}

int main(){
    int m, n;

    printf("Digite dois numeros inteiros: ");
    scanf("%d %d", &m, &n);


    printf("A soma dos numeros entre %d e %d eh %d", m, n, function(m, n));


}