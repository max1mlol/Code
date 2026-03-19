#include <iostream>
#include <cstring>
using namespace std;

class Ajilchin {
private:
    int dugaar;
    char ner[20];
    char albanTushaal[10];
    float ajillasanTsag;

public:
    // 1. Анхны утга оноох
    void anhniiUtga() {
        dugaar = 0;
        strcpy(ner, "");
        strcpy(albanTushaal, "ajilchin");
        ajillasanTsag = 0;
    }
    // АНХДАГЧ БАЙГУУЛАГЧ
    Ajilchin(){
        dugaar = 0;
        strcpy(ner, "");
        strcpy(albanTushaal, "ajilchin");
        ajillasanTsag = 0;
    }
    // ПАРАМЕТРТЭЙ БАЙГУУЛАГЧ
    Ajilchin(int number, const char n[], const char occupation[], float hoursWorked){
        dugaar = number;
        strcpy(ner, n);
        strcpy(albanTushaal, occupation);
        ajillasanTsag = hoursWorked;
    }
    // 2. Гараас утга авах
    void utgaAvah() {
        cout << "Dugaar: ";
        cin >> dugaar;
        cout << "Ner: ";
        cin >> ner;
        cout << "Alban tushaal: ";
        cin >> albanTushaal;
        cout << "Ajillasan tsag: ";
        cin >> ajillasanTsag;
    }

    // 3. Мэдээлэл дэлгэцлэх
    void medeelelDelgetsleh() {
        cout << "\n--- Ajilchnii medeelel ---\n";
        cout << "Dugaar: " << dugaar << endl;
        cout << "Ner: " << ner << endl;
        cout << "Alban tushaal: " << albanTushaal << endl;
        cout << "Ajillasan tsag: " << ajillasanTsag << endl;
        cout << "Tsalin: " << tsalinBodoh() << endl;
    }

    // 4. Захирлын цалин
    float zahirliinTsalin() {
        return ajillasanTsag * 30000;
    }

    // 5. Цалин бодох
    float tsalinBodoh() {
        float undsenTsalin = ajillasanTsag * 15000;

        if (strcmp(albanTushaal, "zahiral") == 0)
            return zahirliinTsalin();
        else
            return undsenTsalin;
    }

    // 6. Ажилласан цаг нэмэх (0-24 шалгана)
    bool ajillasanTsagNemegduuleh(float tsag) {
        if (tsag >= 0 && tsag <= 24) {
            ajillasanTsag += tsag;
            return true;
        }
        return false;
    }
};

int main() {
    Ajilchin a1;                  //анхдагч байгуулагч дуудах
    Ajilchin a2(003, "Sumiya", "zahiral", 15); // параметртай байгуулагч
    a1.anhniiUtga();              // анхны утга
    a1.utgaAvah();                // гараас утга авах
    a1.medeelelDelgetsleh();      // мэдээлэл харах
    a2.medeelelDelgetsleh();
    return 0;
}