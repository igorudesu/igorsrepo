#include "mainwindow.h"
#include <QApplication>
#include <math.h>
#include <fstream>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    static float buffer[10000];
    float pi = 3.14;
    std::fstream fs;
    fs.open ("test.txt", std::fstream::in | std::fstream::out | std::fstream::trunc);

    float Fs = 42050;
    float L = 10000;
    float t = 1;
    int F1 = 280;

    for(int i = 0; i < L; i++)
    {
        t = (t+1/Fs);
        buffer[i] = 0.25*sin(2 * pi * F1 * t);

        fs << buffer[i] << ", ";
    }


    fs.close();
    return a.exec();
}
