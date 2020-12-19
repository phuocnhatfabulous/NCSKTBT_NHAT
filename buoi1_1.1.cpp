#include<iostream>
using namespace std;
class SoPhuc {
private:
    int a; //Phan thuc
    int b; //Phan ao
public:
    SoPhuc();//ham khoi tao
    ~SoPhuc();//ham huy
    void set(); //ham set: thiet lap gia tri
    void get(); // ham get: lay gia tri ra su dung
    void KQ_Cong();
    void KQ_Tru();
    friend SoPhuc cong(SoPhuc, SoPhuc);
    friend SoPhuc tru(SoPhuc, SoPhuc);
};
//Ham khoi tao khong co tham so
SoPhuc::SoPhuc(){
    a = 0;
    b = 0;
}
//Ham huy
SoPhuc::~SoPhuc(){
}
void SoPhuc::set() {
   cout << "Nhap phan thuc: ";
   cin >> a;
   cout << "Nhap phan ao: ";
   cin >> b;
}
void SoPhuc::get() {
   cout << "Gia tri so phuc: "<< a << "+" << b << "i" << endl;
}
void SoPhuc::KQ_Cong() {
   if(b < 0)
      if(b == -1)
         cout << "Ket qua cong 2 so phuc: "<< a << "-i" << endl;
      else
         cout << "Ket qua cong 2 so phuc: "<< a << b << "i" << endl;
      else
         if(b == 1)
            cout << "Ket qua cong 2 so phuc: "<< a << " + i"<< endl;
         else
            cout << "Ket qua cong 2 so phuc: "<< a << " + " << b << "i" << endl;
}
void SoPhuc::KQ_Tru() {
   if(b < 0)
      if(b == -1)
         cout << "Ket qua tru 2 so phuc: "<< a << "-i" << endl;
      else
         cout << "Ket qua tru 2 so phuc: "<< a << b << "i" << endl;
      else
         if(b == 1)
            cout << "Ket qua tru 2 so phuc: "<< a << " + i"<< endl;
         else
            cout << "Ket qua tru 2 so phuc: "<< a << " + " << b << "i" << endl;
}
SoPhuc cong(SoPhuc sp1, SoPhuc sp2) {
   SoPhuc kq;
   kq.a = sp1.a + sp2.a;//phan thuc cong phan thuc
   kq.b = sp1.b + sp2.b;//phan ao cong phan ao
   return kq;//tra ve ket qua da cong
}
SoPhuc tru(SoPhuc sp1, SoPhuc sp2) {
   SoPhuc kq;
   kq.a = sp1.a - sp2.a;//phan thuc tru phan thuc
   kq.b = sp1.b - sp2.b;//phan ao truc phan ao
   return kq;//tra ve ket qua da tru
}
int main() {
   SoPhuc n1, n2;
   SoPhuc kq;
    n1.set();
    n1.get();
    n2.set();
    n2.get();
   kq = cong(n1,n2);
   kq.KQ_Cong();
   kq = tru(n1,n2);
   kq.KQ_Tru();
}
