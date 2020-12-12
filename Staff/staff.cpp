#include <iostream>
#include <string>
#include <vector>
#include <Windows.h>
#include <cstdlib>
#include <ctime>
#include "console.h"
#include <conio.h>
using namespace std;

void SetColor(int backgound_color, int text_color)
{
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

    int color_code = backgound_color * 16 + text_color;
    SetConsoleTextAttribute(hStdout, color_code);
}

int inputKey()
{
	if (_kbhit())
	{
		int key = _getch();

		if (key == 224)	// special key
		{
			key = _getch();
			return key + 1000;
		}

		return key;
	}
	else
	{
		return key_none;
	}

	return key_none;
}


// giao dien chinh
void giaodien(){
	while(true){
	system("cls");
	srand(time(NULL));
	SetColor(0, 1+rand()%15);
        cout<<"   *       *      **      *      *      **      * * * *  * * * *     * * * *  * * * *      **      * * * *  * * * *" <<endl;
        cout<<"   * *   * *     *  *     * *    *     *  *     *        *           *           *        *  *     *        *      " <<endl;
        cout<<"   *   *   *    * ** *    *   *  *    * ** *    *   * *  * * * *     * * * *     *       * ** *    * * * *  * * * *" <<endl;
        cout<<"   *       *   *      *   *    * *   *      *   *     *  *                 *     *      *      *   *        *      " <<endl;
        cout<<"   *       *  *        *  *      *  *        *  * * * *  * * * *     * * * *     *     *        *  *        *      " <<endl;
    Sleep(0);
	SetColor(0,2); //doi mau chu
        cout << "\n\t\t\t1. Nhap thong tin";
        cout << "\n\t\t\t2. Hien thi thong tin";
        cout << "\n\t\t\t3. Tinh tong muc luong";
        cout << "\n\t\t\t4. Tim nhan vien luong cao nhat";
        cout << "\n\t\t\t5. Xep theo luong giam dan";
        cout << "\n\t\t\t6. Tim nhan vien theo ten day du";
        cout << "\n\t\t\t7. Xoa nhan vien";
        cout << "\n\t\t\t8. Sua thong tin cua nhan vien";
        cout << "\n\t\t\t9. Thoat chuong trinh";
		 cout << "\n\t\t\t Nhap lua chon: "; 
    if(kbhit())
		break;
  }
}

//lop nhan vien
class NhanVien{
protected:
    string HoTen;
    int Tuoi;
    string MaNV; //nhap ma NV bang cach: Nv chinh thuc 1: CT1, thuc tap 1: TT1;
    double MucLuong;
    bool Check;
public:
    NhanVien(); // ham khoi tao
    ~NhanVien(); // ham huy
    int slnv1(int &n);
    int slnv2(int &n);
    friend void gotoXY (int column, int line);
    virtual void Nhap(int &n); // ham ao
    virtual void Xuat(int &n); // ham ao
    virtual void SuaNV(int &n); //ham ao
    virtual double Luong() = 0; //ham thuan ao
    bool Get_KieuNV(){
        return this->Check;
    }
    void Set_KieuNV(bool check){
        this->Check = check;
    }
    string Get_Hoten(){
        return this->HoTen;
    }
    string Get_MaNV(){
        return this->MaNV;
    }
    double Get_Luong(){
        return this->MucLuong = MucLuong;
    }
    double Get_Tuoi(){
        return this->Tuoi = Tuoi;
    }
};
NhanVien::NhanVien(){
    HoTen = "";
    Tuoi = 0;
    MucLuong = 0;
    MaNV = "";
}
NhanVien::~NhanVien(){}

//ham nhap so luong nhan vien chinh thuc
int slnv1(int &n){
    cin>>n;
    return n;
}
//ham nhap so luong nhan vien thuc tap
int slnv2(int &n){
    cin>>n;
    return n;
}

void gotoXY (int column, int line)
{
    COORD coord;
    coord.X = column;
    coord.Y = line;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

void NhanVien::Nhap(int &n){   
    cin.ignore();
    gotoXY(36, 5+n);
    getline(cin, HoTen);
    gotoXY(52, 5+n);
    getline(cin, MaNV);
    gotoXY(59, 5+n);
    cin >> Tuoi;
    gotoXY(69,5+n);
    cin >> MucLuong;
}

void NhanVien::Xuat(int &n){   
    gotoXY(36, 5+n);
    cout<< HoTen;
    gotoXY(52, 5+n);
    cout<< MaNV;
    gotoXY(59, 5+n);
    cout << Tuoi;
    cout<<"\n\n\n";
}

void NhanVien::SuaNV(int &n){
	cin.ignore();
    gotoXY(36, 5+n);
    getline(cin, HoTen);
    gotoXY(52, 5+n);
    getline(cin, MaNV);
    gotoXY(59, 5+n);
    cin >> Tuoi;
    gotoXY(69,5+n);
    cin >> MucLuong;
}

//Lop nhan vien chinh thuc
class NhanVienChinhThuc : public NhanVien{
   
  private:
    int ThamNien;

  public:
    NhanVienChinhThuc();
    ~NhanVienChinhThuc();
    void Nhap(int &n);
    void Xuat(int &n);
    void SuaNV(int &n);
    double Luong();
    
};
NhanVienChinhThuc::NhanVienChinhThuc(){
    ThamNien = 0;
}

NhanVienChinhThuc::~NhanVienChinhThuc(){}

double NhanVienChinhThuc::Luong(){
    return Get_Luong() * 1600;
}

void NhanVienChinhThuc::Nhap(int &n){
    NhanVien::Nhap(n);
    //cout << "Nhap Tham Nien: " << endl;
    gotoXY(86,5+n);
    cin >> ThamNien;
}

void NhanVienChinhThuc::Xuat(int &n){
    NhanVien::Xuat(n);
    gotoXY(86,5+n);
    cout<< ThamNien;
    gotoXY(69,5+n);
    cout <<Luong();
    cout<<"\n\n\n";
}

void NhanVienChinhThuc::SuaNV(int &n){
	NhanVien::SuaNV(n);
	//cout << "Nhap lai Tham Nien: " << endl;
    gotoXY(86,5+n);
    cin >> ThamNien;
}


class NhanVienThuViec : public NhanVien{
private:
    int NgayLamViec;

public:
    NhanVienThuViec();
    ~NhanVienThuViec();
    void Nhap(int &n);
    void Xuat(int &n);
    void SuaNV(int &n);
    double Luong();
};
NhanVienThuViec::NhanVienThuViec(){
    NgayLamViec = 0;
}

NhanVienThuViec::~NhanVienThuViec(){
}

void NhanVienThuViec::Nhap(int &n){
    NhanVien::Nhap(n);
    //cout << "Nhap ngay lam viec: " << endl;
    gotoXY(102, 5+n);
    cin >> NgayLamViec;
}

void NhanVienThuViec::Xuat(int &n){
    NhanVien::Xuat(n);
    gotoXY(102, 5+n);
    cout << NgayLamViec;
    gotoXY(69,5+n);
    cout << Luong();
    cout<<"\n\n\n";
}

void NhanVienThuViec::SuaNV(int &n){
	NhanVien::SuaNV(n);
	//cout << "Nhap lai ngay lam viec: " << endl;
    gotoXY(102, 5+n);
    cin >> NgayLamViec;
}

double NhanVienThuViec::Luong(){
    return MucLuong * 1600 * 0.8;
}

class CongTy{
private:
    vector<NhanVien *> dsnv;

public:
    CongTy();
    ~CongTy();
    void Nhap();
    void Xuat();
    float TongLuong();
    void LuongMax();
    void Sapxep();
    void Timkiem();
    void XoaNhanVien();
    void SuaNV();
    friend void inkhung();
    friend void inmenu1();
};

CongTy::CongTy(){
}

CongTy::~CongTy(){
}

void CongTy::Nhap(){
    int i=1,Luachon,n;
        inmenu1();
         while (i)
    {
        cout << "\n \n   Nhap lua chon: ";
        cin >> Luachon;
        NhanVien *x;
        switch (Luachon)
        {
        case 1:  
		  {
            system("cls");
        	inkhung();
        	inmenu1();
            cout<<"\n\n\n Nhap so luong nv chinh thuc: ";
            int a= slnv1(n);
            for(int i=0; i<a; i++){
            x = new NhanVienChinhThuc[n];
            x->Nhap(i);
            x->Set_KieuNV(true);
            dsnv.push_back(x);
            }
            
            break;
        }
        case 2:
        {   
            system("cls");
        	inkhung();
            inmenu1();
        	cout<<"\n\n\n Nhap so luong nv thuc tap: ";
            int b= slnv2(n);
            for(int i=0; i<b; i++){
            x = new NhanVienThuViec[n];
            x->Nhap(i);
            x->Set_KieuNV(false);
            dsnv.push_back(x);
            }
			break;
            
        }
        case 3:
        {
            i--;
            break;
        }
        default:
        {
            cout << "Lua chon khong hop le!!!" << endl;
            break;
        }
        }
    }
}
float CongTy::TongLuong(){
    float sum = 0;
    for (int i = 0; i < dsnv.size(); i++)
    {
        sum = sum + dsnv[i]->Luong();
    }
    return sum;
}
void CongTy::Xuat(){   
    system("cls");
	inkhung();
    for (int i = 0; i < dsnv.size(); i++){
    	
        if (dsnv[i]->Get_KieuNV() == true)
            dsnv[i]->Xuat(i);
        
    }
    for (int i = 0; i < dsnv.size(); i++){
        
		
		if (dsnv[i]->Get_KieuNV() == false)
            dsnv[i]->Xuat(i);
        
    }
}
void CongTy::LuongMax(){
    float max;
    int temp = 0;
    max = dsnv[0]->Luong();
    for (int i = 1; i < dsnv.size(); i++){
        if (dsnv[i]->Luong() > max){
            max = dsnv[i]->Luong();
            temp = i;
        }
    }
    dsnv[temp]->Xuat(temp);
}

void CongTy::Sapxep(){
    for (int i = 0; i < dsnv.size() - 1; i++){
        for (int j = i + 1; j < dsnv.size(); j++){
            if (dsnv[i]->Luong() < dsnv[j]->Luong()){
                NhanVien *temp;
                temp = dsnv[i];
                dsnv[i] = dsnv[j];
                dsnv[j] = temp;
            }
        }
    }
}
void CongTy::Timkiem(){
    int dem = 0;
    string Timkiem;
    cout << "Nhap ten day du de tim: " << endl;
    cin.ignore();
    getline(cin, Timkiem);
    for (int i = 0; i < dsnv.size(); i++)
    {
        if (Timkiem == dsnv[i]->Get_Hoten())
        {
            dem++;
            if (dsnv[i]->Get_KieuNV())
                cout << "Nhan vien chinh thuc!\n\n " << endl;
            else
                cout << "Nhan vien thuc tap!\n\n " << endl;
            inkhung();
            dsnv[i]->Xuat(i);
        }
    }
    if (dem == 0)
        cout << "\nKhong tim duoc nhan vien theo yeu cau!!!\n\n" << endl;
}
//Xoa nhan vien theo ma
void CongTy::XoaNhanVien(){
	int dem = 0;
	string XoaNV;
	cout << "Nhap ma NV can xoa: " << endl;
	cin.ignore();
	getline(cin, XoaNV);
	for (int i = 0; i < dsnv.size(); i++)
	{
		if (XoaNV == dsnv[i]->Get_MaNV())
		{
			dem++;
			for (int j = i; j < dsnv.size(); j++) {
                dsnv[j] = dsnv[j+1];
            }
			if (dsnv[i]->Get_KieuNV())
				cout << "Nhan vien chinh thuc da bi xoa" << endl;
			else
				cout << "Nhan vien thuc tap da bi xoa" << endl;
			break;
		}
	}
	if (dem == 0)
        cout << "\nKhong tim duoc nhan vien theo yeu cau!!!\n\n" << endl;
}
//Sua thong tin nhan vien
void CongTy::SuaNV(){
    int dem = 0;
    string SuaNV;
    cout << "Nhap ma NV de thay doi: " << endl;
    cin.ignore();
    getline(cin, SuaNV);
    for (int i = 0; i < dsnv.size(); i++){
        if (SuaNV == dsnv[i]->Get_MaNV()){
            dem++;
			if (dsnv[i]->Get_KieuNV()){
				cout << "Nhan vien chinh thuc\n\n" << endl;
			}
			else{
					cout << "Nhan vien thuc tap\n\n" << endl;
			}
			inkhung();
			dsnv[i]->SuaNV(i);
        }
}
		if (dem == 0)
        cout << "\nKhong tim duoc nhan vien theo yeu cau!!!\n\n" << endl;
}
//in khung cho lua chon 1
void inmenu1(){
    for(int i=1; i <5; i++){
        gotoXY(1,i);
        putchar(179);
    }
    
    for(int i=1; i <5; i++){
        gotoXY(30,i);
        putchar(179);
    }
    for(int i=2; i <30; i++){
        gotoXY(i,0);
        putchar(95);
    }
    for(int i=2; i <30; i++){
        gotoXY(i,4);
        putchar(95);
    }
    //in menu o lua chon 1
        gotoXY(2,1);
        cout << "1. Nhap nhan vien chinh thuc";
        gotoXY(2,2);
        cout << "2. Nhap nhan vien thuc tap";
        gotoXY(2,3);
        cout << "3. Thoat ";
}

//in khung de hien thi du lieu
void inkhung(){
//in bien doc
    for(int i=1; i <25; i++){
        gotoXY(35,i);
        putchar(179);
        gotoXY(50,i);
        putchar(179);
        gotoXY(115,i);
        putchar(179);
        gotoXY(58,i);
        putchar(179);
        gotoXY(68,i);
        putchar(179);
        gotoXY(85,i);
        putchar(179);
        gotoXY(101,i);
        putchar(179);
    }

    //in bien ngang
    for(int i=35; i <115; i++){
        gotoXY(i,0);
        putchar(95);
        gotoXY(i,25);
        putchar(95);
        gotoXY(i,4);
        putchar(95);
    }
    // in cac tieu de
    gotoXY(36,2);
    cout<<"Ten day du";
    gotoXY(52,2);
    cout<<"Ma NV";
    gotoXY(60,2);
    cout<<"Tuoi";
    gotoXY(70,2);
    cout<<"Muc luong";
    gotoXY(87,2);
    cout<<"Tham nien";
    gotoXY(86,3);
    cout<<"(NV chinh thuc)";
    gotoXY(102,2);
    cout<<"Ngay lam viec";
    gotoXY(102,3);
    cout<<"(NV thuc tap)";
}
int main(){
	
   CongTy CongTy;
    bool check;
    int Luachon;
    while (true){ 
    giaodien();
        cin >> Luachon;
        system("Color 71");
        switch (Luachon)
        {
        case 1:
        {
        	system("cls");
        	inkhung();
            CongTy.Nhap();
            check = true;
            break;
        }
        case 2:
        {
            if (check)
            {
                CongTy.Xuat();
                system("pause");
            }
            else
            {
                cout << "Ban chua nhap thong tin vao!" << endl;
                system("pause");
            }
            break;
        }
        case 3:
        {   
        
            CongTy.Xuat();
            gotoXY(51,26);
            cout << "Tong muc luong la: " << (size_t)CongTy.TongLuong() << endl;
            system("pause");
            break;
        }
        case 4:
        {
        	system("cls");
        	inkhung();
            cout << "\n\n Nhan vien co luong cao nhat la: " << endl;
            CongTy.LuongMax();
            system("pause");
            break;
        }
        case 5:
        {
            cout << "\t\t Xep luong giam dan theo nhan vien: " << endl;
            CongTy.Sapxep();
            CongTy.Xuat();
            system("pause");
            break;
        }
        case 6:
        	system("cls");
            CongTy.Timkiem();
            system("pause");
            break;
    	case 7:
    		system("cls");
    		CongTy.XoaNhanVien();
    		system("pause");
    		break;
        case 8:
    		system("cls");
    		CongTy.SuaNV();
    		system("pause");
    		break;
		case 9:
        {
            system("cls");
            cout << "\t\tTam biet!!!" << endl;
            cout << "\t";
            system("pause");
            exit(0);
        }
        default:
        {
            cout << "Lua chon khong hop le!!!" << endl;
            break;
        }
        }
}
    system("pause");  
    return 0; 
}
