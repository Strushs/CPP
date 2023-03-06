#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    int liczbaBajtow = 0;
    int linia = 0;
    char byte;
    char ascii[17] = { 0 };
    string nazwa;
    system("clear");
    cout << "\t\t********************" << endl;
    cout << "\t\t* Dawid Strużyński *" << endl;
    cout << "\t\t*       4aTI       *" << endl;
    cout << "\t\t********************" << endl;

    cout << "Podaj nazwę pliku, który chcesz otworzyć: ";
    cin >> nazwa;
    ifstream plik(nazwa,ios::binary);

    while(!plik.eof()){
    // Odczytuje plik bajt po bajcie
    while (plik.get(byte))
    {
        // Wypisuje numer lini i bajty
        if (liczbaBajtow % 16 == 0)
        {
            if (liczbaBajtow > 0)
            {
                cout << "  " << ascii << endl;
            }
            cout << "\t" << dec << linia << "\t";
            linia++;
        }
        cout << hex << (int)(unsigned char)byte << ' ';

        // Zapisuje znaki ASCII, które da się wyświetlić , lub używa . dla znaków, których nie da się wyświetlić
        ascii[liczbaBajtow % 16] = (byte >= 32 && byte <= 126) ? byte : '.';
        liczbaBajtow++;
    }

    // Wypełnia spacjami wolne miejsca na bajty w ostatniej lini
    int reszta = liczbaBajtow % 16;
    for(int i = 0; i < (16-reszta)*3; i++)
    cout << " ";

    cout << " " << ascii << endl;
    cout << endl;
    plik.close();

    return 0;
    }
}
