
#ifndef NFRAMZ_H 
#define NFRAMZ_H

#include <windows.h>
#include <stdio.h>






#define Send DispatchMessage


HWND Label(HWND hwnd, const char *tipe, const char *teks,int x, int y, int lebar, int tinggi, int id) {
    return CreateWindow(tipe, teks, WS_CHILD | WS_VISIBLE | WS_BORDER, x, y, lebar, tinggi, hwnd, (HMENU) IntToPtr(id), NULL, NULL);
}









int getvalue(HWND hwnd) {
    char teks[20];
    GetWindowText(hwnd, teks, 20);
    return atof(teks);
}


void integer(HWND hwnd, double hasil) {
    char teks[20];
    sprintf(teks, "%.0f", hasil);
    SetWindowText(hwnd, teks);
}

void decimal(HWND hwnd, double hasil) {
    char teks[20];
    sprintf(teks, "%.1f", hasil);
    SetWindowText(hwnd, teks);
}

void calculate(HWND hwnd, double hasil) {
    if (hasil - (int)hasil == 0) {
        integer(hwnd, hasil);
    } else {
        decimal(hwnd, hasil);
    }
}



#endif 