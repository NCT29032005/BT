#include <bits/stdc++.h>
#include <fstream>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <numeric>
#include <cstdlib>
#include <stdlib.h>


using namespace std;

const int MAX_SIZE = 1000;

class NhanVien
{
private:
    long long maNV;
    float LuongCB;
    float Phucap;
    long long CCCD;
    string HovaTen;
    string DiaChi;
    string GioiTinh;
    string NgaySinh;
    string Email;
    string SoDT;
    float ThucLinh;

public:
    void nhap()
    {
        cout << "Nhap ma nhan vien: ";  cin >> maNV;            cin.ignore();
        cout << "Nhap luong: ";         cin >> LuongCB;         cin.ignore();
        cout << "Nhap Phu Cap: ";       cin >> Phucap;          cin.ignore();
        cout << "Nhap so CCCD: ";       cin >> CCCD;            cin.ignore();
        cout << "Nhap ho va ten: ";     getline(cin, HovaTen);
        cout << "Nhap dia chi: ";       getline(cin, DiaChi);
        cout << "Nhap gioi tinh: ";     getline(cin, GioiTinh);
        cout << "Nhap ngay sinh: ";     getline(cin, NgaySinh);
        cout << "Nhap email: ";         getline(cin, Email);
        cout << "Nhap so dien thoai: "; getline(cin, SoDT);

        ThucLinh = LuongCB + Phucap;
    }

    void xuat() const
    {
        cout << fixed << setprecision(0);
        cout << setw(3) << maNV << setw(21) << HovaTen << setw(14) << NgaySinh
             << setw(19) << DiaChi << setw(9) << GioiTinh << setw(31) << Email
             << setw(18) << SoDT << setw(18) << CCCD << setw(10) << LuongCB
             << setw(10) << Phucap << setw(13) << ThucLinh << endl;
    }

    long long get_maNV() const
    {
        return maNV;
    }

    long long get_CCCD() const
    {
        return CCCD;
    }

    float get_ThucLinh() const
    {
        return ThucLinh;
    }

    float get_Phucap() const
    {
        return Phucap;
    }

    string get_HovaTen() const
    {
        return HovaTen;
    }

    static void readFile(const string& filename, NhanVien employees[], int& size)
    {
        ifstream file(filename);
        if (!file)
        {
            cout << "Khong mo duoc file." << endl;
            return;
        }

        string line;
        size = 0;
        while (getline(file, line) && size < MAX_SIZE)
        {
            istringstream iss(line);
            NhanVien& nv = employees[size];
            iss >> nv.maNV >> nv.LuongCB >> nv.Phucap >> nv.CCCD;
            iss.ignore();
            getline(iss, nv.HovaTen, ',');
            getline(iss, nv.DiaChi, ',');
            getline(iss, nv.GioiTinh, ',');
            getline(iss, nv.NgaySinh, ',');
            getline(iss, nv.Email, ',');
            getline(iss, nv.SoDT, ',');
            nv.ThucLinh = nv.LuongCB + nv.Phucap;
            size++;
        }

        file.close();
    }

    static void writeFile(const string& filename, NhanVien employees[], int size)
    {
        ofstream file(filename);
        if (!file)
        {
            cout << "Khong mo duoc file." << endl;
            return;
        }

        for (int i = 0; i < size; ++i)
        {
            const NhanVien& nv = employees[i];
            file << nv.maNV << " " << nv.LuongCB << " " << nv.Phucap << " " << nv.CCCD << " "
                 << nv.HovaTen << "," << nv.DiaChi << "," << nv.GioiTinh << "," << nv.NgaySinh
                 << "," << nv.Email << "," << nv.SoDT << "," << endl;
        }

        file.close();
    }
};

void nhapds(NhanVien nv[], int& size)
{
    int n;
    cout << "Nhap so luong nhan vien: ";
    cin >> n;
    if (n > MAX_SIZE - size)
    {
        cout << "So luong nhan vien vuot qua kich thuoc toi da!" << endl;
        return;
    }

    for (int i = size; i < size + n; ++i)
    {
        cout << endl << "Nhan Vien Thu: " << i + 1 << endl;
        nv[i].nhap();
    }

    size += n;
}

void xuatds(NhanVien nv[], int size)
{
    cout << setw(3)  << "MaNV"    << setw(20) << "Ho va Ten" << setw(14) << "Ngay Sinh"
         << setw(19) << "Dia Chi" << setw(12) << "Gioi Tinh" << setw(28) << "Email"
         << setw(18) << "So DT"   << setw(18) << "CCCD"      << setw(10) << "LuongCB"
         << setw(10) << "Phu Cap" << setw(13) << "Thuc Linh" << endl;
    for (int i = 0; i < size; ++i)
    {
        nv[i].xuat();
    }
}

void TKMaNV(NhanVien nv[], int size)
{
    long long Ma;
    int count = 0;
    cout << "Nhap ma nhan vien can tim: ";
    cin >> Ma;
    for (int i = 0; i < size; ++i)
    {
        if (nv[i].get_maNV() == Ma)
        {
            nv[i].xuat();
            count++;
        }
    }
    if (count == 0)
        cout << "Khong tim thay ma nhan vien can tim." << endl;
}

void TKCCCD(NhanVien nv[], int size)
{
    long long cccd;
    int count = 0;
    cout << "Nhap CCCD nhan vien can tim: ";
    cin >> cccd;
    for (int i = 0; i < size; ++i)
    {
        if (nv[i].get_CCCD() == cccd)
        {
            nv[i].xuat();
            count++;
        }
    }
    if (count == 0)
        cout << "Khong tim thay CCCD nhan vien can tim." << endl;
}

void TKTen(NhanVien nv[], int size)
{
    string ten;
    int count = 0;
    cout << "Nhap ten nhan vien can tim: ";
    cin.ignore();
    getline(cin, ten);
    for (int i = 0; i < size; ++i)
    {
        if (nv[i].get_HovaTen() == ten)
        {
            nv[i].xuat();
            count++;
        }
    }
    if (count == 0)
        cout << "Khong tim thay nhan vien co ten can tim." << endl;
}

void sapxep(NhanVien nv[], int size)
{
    sort(nv, nv + size, [](const NhanVien& a, const NhanVien& b)
    {
        return a.get_ThucLinh() < b.get_ThucLinh();
    });
    cout << endl << "Sau khi sap xep: " << endl;
    xuatds(nv, size);
}

void tongLuong(NhanVien nv[], int size)
{
    double TongLuong = accumulate(nv, nv + size, 0.0, [](double sum, const NhanVien& nvItem)
    {
        return sum + nvItem.get_ThucLinh();
    });
    cout << fixed << setprecision(0);
    cout << "Tong luong cua nhan vien la: " << TongLuong << endl;
}

void thucLinhmax(NhanVien nv[], int size)
{
    if (size == 0)
    {
        cout << "Danh sach nhan vien trong." << endl;
        return;
    }
    auto max_nv = max_element(nv, nv + size, [](const NhanVien& a, const NhanVien& b)
    {
        return a.get_ThucLinh() < b.get_ThucLinh();
    });
    cout << "Nhan vien co thuc linh cao nhat: " << endl;
    max_nv->xuat();
}

void timphucap(NhanVien nv[], int size)
{
    int count = 0;
    for (int i = 0; i < size; ++i)
    {
        if (nv[i].get_Phucap() > 100000)
        {
            nv[i].xuat();
            count++;
        }
    }
    if (count == 0)
        cout << "Khong co nhan vien nao co phu cap > 100000." << endl;
}

void xoa(NhanVien nv[], int& size)
{
    long long Ma;
    cout << "Nhap ma nhan vien can xoa: ";
    cin >> Ma;
    int pos = -1;
    for (int i = 0; i < size; ++i)
    {
        if (nv[i].get_maNV() == Ma)
        {
            pos = i;
            break;
        }
    }
    if (pos != -1)
    {
        for (int i = pos; i < size - 1; ++i)
        {
            nv[i] = nv[i + 1];
        }
        size--;
        cout << "Da xoa nhan vien co ma " << Ma << endl;
    }
    else
    {
        cout << "Khong tim thay ma nhan vien can xoa." << endl;
    }
}

void them(NhanVien nv[], int& size)
{
    if (size >= MAX_SIZE)
    {
        cout << "Danh sach nhan vien da day." << endl;
        return;
    }
    nv[size].nhap();
    size++;
}

void sua(NhanVien nv[], int size)
{
    long long Ma;
    cout << "Nhap ma nhan vien can sua: ";
    cin >> Ma;
    for (int i = 0; i < size; ++i)
    {
        if (nv[i].get_maNV() == Ma)
        {
            nv[i].nhap();
            cout << "Sua thong tin thanh cong." << endl;
            return;
        }
    }
    cout << "Khong tim thay ma nhan vien." << endl;
}

void sapXepTheoTen(NhanVien nv[], int size)
{
    sort(nv, nv + size, [](const NhanVien& a, const NhanVien& b)
    {
        return a.get_HovaTen() < b.get_HovaTen();
    });
    cout << endl << "Danh sach sau khi sap xep theo ten: " << endl;
    xuatds(nv, size);
}

void menu(NhanVien nv[], int& size)
{
    int choice;

     do
    {
        cout << " _____________________________________________________________________________" << endl;
        cout << "|*****************************************************************************|" << endl;
        cout << "|                              QUAN LY NHAN VIEN                              |" << endl;
        cout << "|_____________________________________________________________________________|" << endl;
        cout << "|*                                                                           *|" << endl;
        cout << "|              ||\\"<<"\\        //|| ||======  ||\\"<<"\\    || ||       ||              |" << endl;
        cout << "|              || \\"<<"\\      // || ||        || \\"<<"\\   || ||       ||              |" << endl;
        cout << "|              ||  \\"<<"\\    //  || ||======  ||  \\"<<"\\  || ||       ||              |" << endl;
        cout << "|              ||   \\"<<"\\  //   || ||        ||   \\"<<"\\ || ||       ||              |" << endl;
        cout << "|              ||    \\"<<"\\//    || ||======  ||    \\"<<"\\||  \\"<<"\\=====//               |" << endl;
        cout << "|_____________________________________________________________________________|" << endl;
        cout << "|                                                                             |" << endl;
        cout << "|  1.  Nhap danh sach nhan vien                                               |" << endl;
        cout << "|  2.  Hien thi danh sach nhan vien                                           |" << endl;
        cout << "|  3.  Tim kiem nhan vien theo maNV                                           |" << endl;
        cout << "|  4.  Tim kiem nhan vien theo CCCD                                           |" << endl;
        cout << "|  5.  Tim kiem nhan vien theo ten                                            |" << endl;
        cout << "|  6.  Sap xep luong nhan vien tang dan                                       |" << endl;
        cout << "|  7.  Tinh tong luong nhan vien                                              |" << endl;
        cout << "|  8.  Tim kiem nhan vien thu nhap cao nhat                                   |" << endl;
        cout << "|  9.  Tim kiem nhan vien phu cap > 100.000                                   |" << endl;
        cout << "|  10. Xoa nhan vien                                                          |" << endl;
        cout << "|  11. Them nhan vien                                                         |" << endl;
        cout << "|  12. Sua thong tin mot nhan vien                                            |" << endl;
        cout << "|  13. Ghi danh sach nhan vien ra file khac                                   |" << endl;
        cout << "|  14. Xap sep ten theo ma ASCII                                              |" << endl;
        cout << "|  15. Thoat                                                                  |" << endl;
        cout << "|                                                                             |" << endl;
        cout << "|*___________________________________________________________________________*|" << endl;
        cout << "|_____________________________________________________________________________|" << endl;
        cout << "|*****************                    ~2TK~                   ****************|" << endl;
        cout << "|*****************************************************************************|" << endl;
        cout << "|_____________________________________________________________________________|" << endl;
        cout << "Nhap lua chon cua ban [1-15]: ";
        cin >> choice;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Lua chon khong hop le. Vui long chon lai." << endl;
            continue;
        }

        switch (choice)
        {
            case 1:
                nhapds(nv, size);
                NhanVien::writeFile("NhanVien.txt", nv, size);
                break;
            case 2:
                xuatds(nv, size);
                break;
            case 3:
                TKMaNV(nv, size);
                break;
            case 4:
                TKCCCD(nv, size);
                break;
            case 5:
                TKTen(nv, size);
                break;
            case 6:
                sapxep(nv, size);
                break;
            case 7:
                tongLuong(nv, size);
                break;
            case 8:
                thucLinhmax(nv, size);
                break;
            case 9:
                timphucap(nv, size);
                break;
            case 10:
                xoa(nv, size);
                NhanVien::writeFile("NhanVien.txt", nv, size);
                break;
            case 11:
                them(nv, size);
                NhanVien::writeFile("NhanVien.txt", nv, size);
                break;
            case 12:
                sua(nv, size);
                NhanVien::writeFile("NhanVien.txt", nv, size);
                break;
            case 13:
            {
                string newFilename;
                cout << "Nhap ten file moi de luu danh sach: ";
                cin.ignore();
                getline(cin, newFilename);
                NhanVien::writeFile(newFilename, nv, size);
                cout << "Da luu danh sach nhan vien vao file " << newFilename << endl;
                break;
            }
            case 14:
                sapXepTheoTen(nv, size);
                break;
            case 15:
               cout <<                                                               endl;
               cout << "                   Thoat chuong trinh                   " << endl;
               cout << "                   ------------------                   " << endl;
               cout << "   Cam on ban da su dung chuong trinh cua chung toi!    " << endl;
               cout << "                                                        " << endl;
               cout << "   Chuong trinh duoc xay dung va phat trien boi:        " << endl;
               cout << "  ----------------------------------------------------  " << endl;
               cout << "|  Nguyen Cao Truong(C)  ETTN-K68       20233686       |" << endl;
               cout << "|  Pham Minh Tuan        ETTN-K68       20233701       |" << endl;
               cout << "|  Dang Nam Khanh        ETTN-K68       20233460       |" << endl;
               cout << "|  Nguyen Van Khang      ETTN-K68       20233458       |" << endl;
               cout << "|                                                      |" << endl;
               cout << "|                 Cam on va hen gap lai!               |" << endl;
               cout << "|------------------------------------------------------|" << endl;
               cout                                                               << endl;
               cout << "   +--------------------------------------+             " << endl;
               cout << "    Thong tin lien he:                                  " << endl;
               cout << "   +--------------------------------------+             " << endl;
               cout << "   Dia chi: 123 ABC Street, XYZ City, Vietnam           " << endl;
               cout << "   Email: nguyencaotruong911@gmail.com                  " << endl;
               cout << "   So dien thoai: (+84) 036 633 2601                    " << endl;
               cout << "   Website: https://linktr.ee/nguyencaotruong           " << endl;
               cout << "   +--------------------------------------+             " << endl;
               exit(0);

            default:
                cout << "Lua chon khong hop le. Vui long chon lai." << endl;
        }

        if (choice != 15)
        {
            cout << "Nhan 'ENTER' de tiep tuc..." << endl;
            cin.ignore();
            cin.get();
        }
    } while (choice != 15);
}

int main()
{
    NhanVien nv[MAX_SIZE];
    int size = 0;
    NhanVien::readFile("NhanVien.txt", nv, size);
    menu(nv, size);
    return 0;
}
