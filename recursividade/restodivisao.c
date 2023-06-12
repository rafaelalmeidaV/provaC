#include <stdio.h>

float restoDivisao(float m, float n){
    if (m < n){
        return m;
    } else{
        return restoDivisao(m-n, n);
    }
}

int main(){
    float m, n;

    printf("Digite dois numeros inteiros: ");
    scanf("%f %f", &m, &n);

    printf("O resto da divisao de %f por %f eh %f", m, n, restoDivisao(m, n));

}