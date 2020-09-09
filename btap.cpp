/*
 Viết một chương trình nhập mã sinh viên, họ tên, giới tính, điểm các môn học bạn đã học và tính điểm trung bình học tập của bạn (Hệ 4 và hệ 10) tại thời điểm hiện tại bằng ngôn ngữ lập trình C++.
 */
//                          Em chưa làm tính trung bình hệ 4
#include<iostream>
#include<string>

using namespace::std;

void nhapDiem(float &KTCT, float &KNM, float &GT, float &LTNC, float &CNXH, float &VL, float &DSTT);
float dtbHe10(float KTCT, float KNM, float GT, float LTNC, float CNXH, float VL, float DSTT);
float dtbHe4(float KTCT, float KNM, float GT, float LTNC, float CNXH, float VL, float DSTT);

int main(){
    string hoTen;
    string mssv;
    string gioiTinh;
    float KTCT, KNM, GT, LTNC, CNXH, VL, DSTT, diemhe10;
    cout << "Nhap ho ten: "<<endl;
        cin >> hoTen;
        cin.ignore(0);
        getline(cin, hoTen);
    cout << "Nhap ma so sinh vien: "<<endl;
        cin >> mssv;
        cin.ignore(0);
        getline(cin, mssv);
    cout << "Gioi tinh cua ban la: ";
        cin >> gioiTinh;
        cin.ignore(0);
        getline(cin, gioiTinh);
    nhapDiem(KTCT, KNM, GT, LTNC, CNXH, VL, DSTT);
    cout<< "Diem he so 10 cua ban" <<" la: " << dtbHe10 <<endl;

    return 0;
};
void nhapDiem(float &KTCT, float &KNM, float &GT, float &LTNC, float &CNXH, float &VL, float &DSTT){
    do{
           cout<<"Nhap diem mon KTCT: "<<endl;
               cin>>KTCT;
        }while(KTCT<0||KTCT>10);
    do{
           cout<<"Nhap diem mon KNM: "<<endl;
               cin>>KNM;
       }while(KNM<0||KNM>10);
    do{
           cout<<"Nhap diem mon GT: "<<endl;
               cin>>GT;
        }while(GT<0||GT>10);
    do{
           cout<<"Nhap diem mon LTNC: "<<endl;
               cin>>LTNC;
        }while(LTNC<0||LTNC>10);
    do{
           cout<<"Nhap diem mon CNXH: "<<endl;
               cin>>CNXH;
        }while(CNXH<0||CNXH>10);
    do{
           cout<<"Nhap diem mon VL: "<<endl;
               cin>>VL;
        }while(VL<0||VL>10);
    do{
           cout<<"Nhap diem mon DSTT: "<<endl;
               cin>>DSTT;
        }while(DSTT<0||DSTT>10);
}
float dtbHe10(float KTCT, float KNM, float GT, float LTNC, float CNXH, float VL, float DSTT){
    float diemhe10;
    diemhe10 = ((KTCT + KNM + GT + LTNC + CNXH + VL + DSTT)/7);
    cout<< "Diem he so 10 cua ban" <<" la: " << diemhe10 <<endl;

    return ((KTCT + KNM + GT + LTNC + CNXH + VL + DSTT)/7);
}


