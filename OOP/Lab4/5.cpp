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
    int n;
    cout << "Heden ajilchin oruulah ve? : ";
    cin >> n;
    
    Ajilchin* ajilchid = new Ajilchin[n];
    
    for(int i = 0; i < n; i++) {
        cout << "\n" << i+1 << "-r ajilchin:" << endl;
        ajilchid[i].utgaAvah();
    }
    
    cout << "\n========== BUKH AJILCHDYN MEDEELEL ==========" << endl;
    for(int i = 0; i < n; i++) {
        ajilchid[i].medeelelDelgetsleh();
    }
    
    delete[] ajilchid;
    return 0;
}
