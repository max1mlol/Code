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
    // УСТГАГЧ ФУНКЦ
    ~Ajilchin(){
        cout << "Ustgagch funtion ajillaj baina: " << ner << " (dugaar: " << dugaar << ")" << endl;
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
void test(){
    cout << "\n--- Function dotor object uusgeh ---" << endl;
    Ajilchin temp(999, "Baatar", "ajilchin", 15);
    temp.medeelelDelgetsleh();
}
int main() {
    cout << "========== USTGAGCH FUNCTIONII TURSHILT ==========" << endl;

    cout << "\n--- Object 1: Ankhdagch baiguulagch ---" << endl;
    Ajilchin a1;                  //анхдагч байгуулагч дуудах
    a1.utgaAvah();                // гараас утга авах
    cout << "\n--- Object 2: Parametertei baiguulagch ---" << endl;
    Ajilchin a2(003, "Sumiya", "zahiral", 15); 
    test();
    cout << "\n--- Dynamic Object ---" << endl;
    Ajilchin *ptr = new Ajilchin(888, "Bilguun", "ajilchin", 15);
    ptr->medeelelDelgetsleh();
    cout << "Dynamic Object Ustgah: ";
    delete ptr;
    return 0;
}