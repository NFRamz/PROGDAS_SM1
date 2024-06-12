#include <stdio.h>
#include <stdbool.h>

int main() {
    const double MATEMATIKA_sks = 4.0;
    const double FISIKA_sks = 3.0;
    const double BIOLOGI_sks = 2.0;
    
    double nilaiMatematika, nilaiFisika, nilaiBiologi;
    
    char matematika[20], fisika[20], biologi[20];

    printf("Masukkan nilai: ");
    scanf("%lf", &nilaiMatematika);
    printf("Masukkan nama mata pelajaran : ");
    scanf("%s", matematika);
    
    printf("Masukkan nilai: ");
    scanf("%lf", &nilaiFisika);
    printf("Masukkan nama mata pelajaran : ");
    scanf("%s", fisika);
    
    printf("Masukkan nilai: ");
    scanf("%lf", &nilaiBiologi);
    printf("Masukkan nama mata pelajaran: ");
    scanf("%s", biologi);
    
    double rataRata = (nilaiMatematika * MATEMATIKA_sks + nilaiFisika * FISIKA_sks + nilaiBiologi * BIOLOGI_sks) / (MATEMATIKA_sks + FISIKA_sks + BIOLOGI_sks);
    
    printf("Nilai rata-rata Anda untuk mata pelajaran %s, %s, dan %s: %.2lf\n", matematika, fisika, biologi, rataRata);
    
    return 0;
}
