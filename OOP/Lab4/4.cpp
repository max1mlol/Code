#include <iostream>
#include <cstring>
using namespace std;

class Ajilchin {
private:
    int dugaar;
    char ner[20];
    char albanTushaal[10];
    float ajillasanTsag;

    // 4. Захирлын цалин
    float zahirliinTsalin() {
        return ajillasanTsag * 30000;
    }
public:
    void setDugaar(int d){
        dugaar = d;
    }
    void setNer(const char n[]){
        strcpy(ner, n);
    }
    void setAlbanTushaal(const char at[]){
        strcpy(albanTushaal, at);
    }
    void setAjillasanTsag(float atsag){
        if(atsag >= 0){
            ajillasanTsag = atsag;
        }
    }
    int getDugaar(){
        return dugaar;
    }
    const char* getNer(){
        return ner;
    }
    const char* getAlbanTushaal(){
        return albanTushaal;
    }
    float getAjillasanTsag(){
        return ajillasanTsag;
    }
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
        setDugaar(number);
        setNer(n);
        setAlbanTushaal(occupation);
        setAjillasanTsag(hoursWorked);
    }
    // 2. Гараас утга авах
    void utgaAvah() {
        int d;
        char n[20], at[10];
        float atsag;
        cout << "Dugaar: ";
        cin >> d;
        setDugaar(d);
        cout << "Ner: ";
        cin >> n;
        setNer(n);
        cout << "Alban tushaal: ";
        cin >> at;
        setAlbanTushaal(at);
        cout << "Ajillasan tsag: ";
        cin >> atsag;
        setAjillasanTsag(atsag);
    }

    // 3. Мэдээлэл дэлгэцлэх
    void medeelelDelgetsleh() {
        cout << "\n--- Ajilchnii medeelel ---\n";
        cout << "Dugaar: " << getDugaar() << endl;
        cout << "Ner: " << getNer() << endl;
        cout << "Alban tushaal: " << getAlbanTushaal() << endl;
        cout << "Ajillasan tsag: " << getAjillasanTsag() << endl;
        cout << "Tsalin: " << tsalinBodoh() << endl;
    }

    

    // 5. Цалин бодох
    float tsalinBodoh() {
        float undsenTsalin = getAjillasanTsag() * 15000;

        if (strcmp(getAlbanTushaal(), "zahiral") == 0)
            return zahirliinTsalin();
        else
            return undsenTsalin;
    }

    // 6. Ажилласан цаг нэмэх (0-24 шалгана)
    bool ajillasanTsagNemegduuleh(float tsag) {
        if (tsag >= 0 && tsag <= 24) {
            setAjillasanTsag(getAjillasanTsag() + tsag);
            return true;
        }
        return false;
    }
};

int main() {
    cout << "========== SETTER/GETTER - PUBLIC/PRIVATE ==========" << endl;
    
    // Энгийн ажилчин
    Ajilchin a1(2, "Jargal", "ajilchin", 10);
    cout << "\nAjilchin:";
    a1.medeelelDelgetsleh();
    
    // Захирал
    Ajilchin a2(3, "Anar", "zahiral", 10);
    cout << "\nZahiral:";
    a2.medeelelDelgetsleh();
    
    // SETTER/GETTER ашиглах жишээ
    cout << "\n--- SETTER/GETTER ASHIGLAH ---" << endl;
    cout << "Getter: " << a2.getNer() << " - " << a2.getAlbanTushaal() << endl;
    
    a2.setAjillasanTsag(20);
    cout << "Settereer tsag 20 bolgoson: " << a2.getAjillasanTsag() << " tsag" << endl;
    
    // Private функцэд хандах боломжгүй гэдгийг харуулах
    cout << "\n--- PRIVATE FUNCTION ---" << endl;
    cout << "// a2.zahirliinTsalin(); - Compile error (private)" << endl;
    cout << "// a2.dugaar = 5; - Compile error (private)" << endl;
    
    return 0;
}