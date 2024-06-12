#include <stdio.h>
int main(){
    double const kambing = 120+85.8+23;
    double a,b,c,d;
    printf("masukkan berat sapi 1:");
    scanf("%lf", &a);
    printf("masukkan berat sapi 2:");
    scanf("%lf",&b);
    printf("masukkan berat sapi 3:");
    scanf("%lf",&c);
    printf("masukkan berat sapi 4:");
    scanf("%lf",&d);

    printf("\nHasil Berat Sapi:%g\n", a+b+c+d);
    printf("Hasil Berat Kambing:%g", kambing);

return 0;

}
