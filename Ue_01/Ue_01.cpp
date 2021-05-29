// Ue_01.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//


#include <stdio.h>
#include <math.h>
#include <string>
#include <iostream>
using namespace std;

float volume(float x, float y, float z) {
    return x * y * z;
}

float ob(float x, float y, float z) {
    return x * y * 4 + x * z * 2;
}

float inp(string was) {
    float x;
    string zusWas = "Bitte " + was + " eingeben: ";
    cout << zusWas;
    // entweder mit iostring ausgeben, oder c-Strings verwenden
    scanf_s("%f", &x);
    return x;
}

void out(string was) {
    cout << was;
}

void quader() {
    float x, y, z;
    x = inp("x");
    y = inp("y");
    z = inp("z");

    out("vol: " + to_string(volume(x, y, z)) + "\n");
    //printf("vol: %.2f \n", volume(x, y, z));
    //printf("ob: %.2f \n", ob(x, y, z));
    out("Oberflaeche: " +  to_string(ob(x, y, z)));
}

void celsToFahrenheit() {
    out("Fahrenheit: " + to_string(inp("Celcius") * 9/5 + 32));
}

void parRs() {
    float R1 = inp("Widerstandswert 1");
    float R2 = inp("Widerstandswert 2");
    out("Widerstaende Parallel: " + to_string((R1 * R2)/(R1 + R2)));
}

int main()
{
    bool menu = true;
    while (menu) {
        int w;
        cout << "\n\nWelche Auswahl soll getroffen werden?";
        cout << "\n1   Quader Volumen & Oberflaeche";
        cout << "\n2   Celsius zu Fahrenheit";
        cout << "\n3   Parallele Widerstaende";
        cout << "\n0   Programm beenden\n";

        cin >> w;

        switch (w) {
        case 0: cout << "Programm wird beendet.";
            menu = false;
            break;
        case 1: quader();
            break;
        case 2: celsToFahrenheit();
            break;
        case 3: parRs();
            break;
        default: cout << "Option nicht verfuegbar";
        }
    }
    
          
    return 0;
}