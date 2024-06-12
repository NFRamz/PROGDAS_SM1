#include<stdio.h>

int myfunction(int a, int b);

int main (){
    int a = 5;
    int b = 10;
    printf("Hello world\n");
    int c = myfunction(a, b);
    printf("%d\n", c);
    return 0;
}


int myfunction(int a, int b){

    int c = a + b; 
    printf("Ini sebuah fungsi\n");
    return c;
}

/*dari fungsi main anda mengrimkan 2 variabel a dan b isinya 5 dan 10 ,
kedua variabel ini dikirim ke myfunction dan di function ada rumus aritmatika untuk mengembalikan dengan return c*/