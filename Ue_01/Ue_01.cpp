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

float inpFloat(string was) {
    float x;
    string zusWas = "Bitte " + was + " eingeben: ";
    cout << zusWas;
    // entweder mit iostring ausgeben, oder c-Strings verwenden
    cin >> x;
    return x;
}

string inpString(string was) {
    string x;
    string zusWas = "Bitte " + was + " eingeben: ";
    cout << zusWas;

    cin >> x;
    return x;
}

void out(string was) {
    cout << was;
}

void quader() {
    float x, y, z;
    x = inpFloat("x");
    y = inpFloat("y");
    z = inpFloat("z");

    out("vol: " + to_string(volume(x, y, z)) + "\n");
    //printf("vol: %.2f \n", volume(x, y, z));
    //printf("ob: %.2f \n", ob(x, y, z));
    out("Oberflaeche: " +  to_string(ob(x, y, z)));
}

void celsToFahrenheit() {
    out("Fahrenheit: " + to_string(inpFloat("Celcius") * 9/5 + 32));
}

void parRs() {
    float R1 = inpFloat("Widerstandswert 1");
    float R2 = inpFloat("Widerstandswert 2");
    out("Widerstaende Parallel: " + to_string((R1 * R2)/(R1 + R2)));
}

bool sucheRechenoperator(string s, char rechenOp) {
    //mehrere Rechenoperationen verfügbar erweitern?
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == rechenOp) {
            return true;
        }
    }
    return false;
}

void taschenrechner() {
    string x;
    //TODO: Leerzeichen ignorieren
    x = inpString("Rechenaufgabe (ohne Leerzeichen!)");
    
    const int lengthRechenOpt = 4;
    char rechenOpt[lengthRechenOpt] = { '+', '-', '*', '/' };
    int i = 0;
    for (; i < lengthRechenOpt; i++) {
        if (sucheRechenoperator(x, rechenOpt[i])) {
            break;
        }
    }
    string str1, str2;
    float a, b, erg;

    string delimiter = to_string(rechenOpt[i]);
    str1 = x.substr(0, x.find(delimiter));
    str2 = x.substr(x.find(delimiter), x.length());

    a = stof(str1);
    b = stof(str2);

    if (rechenOpt[i] == '+') {
        erg = a + b;
    }
    else if (rechenOpt[i] == '-') {
        erg = a + b;
    }
    else if (rechenOpt[i] == '*') {
        erg = a * b;
    }
    else if (rechenOpt[i] == '/') {
        erg = a / b;
    }

    //Rechnung durchführen
    //Ausgabe
    out("Ergbnis: " + to_string(erg));
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
        cout << "\n4   Taschenrechner";
        cout << "\n0   Programm beenden\n";

        //TODO: Eingabespeicher leeren, bevor wieder einegeben werden kann
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
        case 4: taschenrechner();
            break;
        default: cout << "Option nicht verfuegbar";
        }
    }
    
          
    return 0;
}