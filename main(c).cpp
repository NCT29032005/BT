#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SIZE 1000

struct NhanVien {
    long long maNV;
    float LuongCB;
    float Phucap;
    long long CCCD;
    char HovaTen[100];
    char DiaChi[100];
    char GioiTinh[10];
    char NgaySinh[20];
    char Email[50];
    char SoDT[15];
    float ThucLinh;
};

void nhap(NhanVien *nv) {
    printf("Nhap ma nhan vien: ");  scanf("%lld", &nv->maNV);            getchar();
    printf("Nhap luong: ");         scanf("%f", &nv->LuongCB);            getchar();
    printf("Nhap Phu Cap: ");       scanf("%f", &nv->Phucap);             getchar();
    printf("Nhap so CCCD: ");       scanf("%lld", &nv->CCCD);             getchar();
    printf("Nhap ho va ten: ");     fgets(nv->HovaTen, sizeof(nv->HovaTen), stdin);
    printf("Nhap dia chi: ");       fgets(nv->DiaChi, sizeof(nv->DiaChi), stdin);
    printf("Nhap gioi tinh: ");     fgets(nv->GioiTinh, sizeof(nv->GioiTinh), stdin);
    printf("Nhap ngay sinh: ");     fgets(nv->NgaySinh, sizeof(nv->NgaySinh), stdin);
    printf("Nhap email: ");         fgets(nv->Email, sizeof(nv->Email), stdin);
    printf("Nhap so dien thoai: "); fgets(nv->SoDT, sizeof(nv->SoDT), stdin);

    nv->ThucLinh = nv->LuongCB + nv->Phucap;
}

void xuat(const NhanVien *nv) {
    printf("%-3lld %-20s %-14s %-19s %-9s %-31s %-18s %-18lld %-10.2f %-10.2f %-13.2f\n",
           nv->maNV, nv->HovaTen, nv->NgaySinh, nv->DiaChi, nv->GioiTinh,
           nv->Email, nv->SoDT, nv->CCCD, nv->LuongCB, nv->Phucap, nv->ThucLinh);
}

void nhapds(NhanVien nv[], int *size) {
    int n;
    printf("Nhap so luong nhan vien: ");
    scanf("%d", &n);
    getchar();

    if ((*size + n) > MAX_SIZE) {
        printf("So luong nhan vien vuot qua kich thuoc toi da!\n");
        return;
    }

    for (int i = *size; i < *size + n; ++i) {
        printf("\nNhan Vien Thu: %d\n", i + 1);
        nhap(&nv[i]);
    }

    *size += n;
}

void xuatds(NhanVien nv[], int size) {
    printf("%-3s %-20s %-14s %-19s %-12s %-28s %-18s %-18s %-10s %-10s %-13s\n",
           "MaNV", "Ho va Ten", "Ngay Sinh", "Dia Chi", "Gioi Tinh",
           "Email", "So DT", "CCCD", "LuongCB", "Phu Cap", "Thuc Linh");
    for (int i = 0; i < size; ++i) {
        xuat(&nv[i]);
    }
}

void TKMaNV(NhanVien nv[], int size) {
    long long Ma;
    int count = 0;
    printf("Nhap ma nhan vien can tim: ");
    scanf("%lld", &Ma);
    for (int i = 0; i < size; ++i) {
        if (nv[i].maNV == Ma) {
            xuat(&nv[i]);
            count++;
        }
    }
    if (count == 0)
        printf("Khong tim thay ma nhan vien can tim.\n");
}

void TKCCCD(NhanVien nv[], int size) {
    long long cccd;
    int count = 0;
    printf("Nhap CCCD nhan vien can tim: ");
    scanf("%lld", &cccd);
    for (int i = 0; i < size; ++i) {
        if (nv[i].CCCD == cccd) {
            xuat(&nv[i]);
            count++;
        }
    }
    if (count == 0)
        printf("Khong tim thay CCCD nhan vien can tim.\n");
}

void TKTen(NhanVien nv[], int size) {
    char ten[100];
    int count = 0;
    printf("Nhap ten nhan vien can tim: ");
    getchar();
    fgets(ten, sizeof(ten), stdin);
    ten[strcspn(ten, "\n")] = 0;

    for (int i = 0; i < size; ++i) {
        if (strcmp(nv[i].HovaTen, ten) == 0) {
            xuat(&nv[i]);
            count++;
        }
    }
    if (count == 0)
        printf("Khong tim thay nhan vien co ten can tim.\n");
}

void sapxep(NhanVien nv[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = i + 1; j < size; ++j) {
            if (nv[i].ThucLinh > nv[j].ThucLinh) {
                NhanVien temp = nv[i];
                nv[i] = nv[j];
                nv[j] = temp;
            }
        }
    }
    printf("\nSau khi sap xep:\n");
    xuatds(nv, size);
}

void tongLuong(NhanVien nv[], int size) {
    float TongLuong = 0;
    for (int i = 0; i < size; ++i) {
        TongLuong += nv[i].ThucLinh;
    }
    printf("Tong luong cua nhan vien la: %.2f\n", TongLuong);
}

void thucLinhmax(NhanVien nv[], int size) {
    if (size == 0) {
        printf("Danh sach nhan vien trong.\n");
        return;
    }

    NhanVien max_nv = nv[0];
    for (int i = 1; i < size; ++i) {
        if (nv[i].ThucLinh > max_nv.ThucLinh) {
            max_nv = nv[i];
        }
    }
    printf("Nhan vien co thuc linh cao nhat:\n");
    xuat(&max_nv);
}

void timphucap(NhanVien nv[], int size) {
    int count = 0;
    for (int i = 0; i < size; ++i) {
        if (nv[i].Phucap > 100000) {
            xuat(&nv[i]);
            count++;
        }
    }
    if (count == 0)
        printf("Khong co nhan vien nao co phu cap > 100000.\n");
}

void xoa(NhanVien nv[], int *size) {
    long long Ma;
    printf("Nhap ma nhan vien can xoa: ");
    scanf("%lld", &Ma);
    int pos = -1;
    for (int i = 0; i < *size; ++i) {
        if (nv[i].maNV == Ma) {
            pos = i;
            break;
        }
    }
    if (pos != -1) {
        for (int i = pos; i < *size - 1; ++i) {
            nv[i] = nv[i + 1];
        }
        (*size)--;
        printf("Da xoa nhan vien co ma %lld\n", Ma);
    } else {
        printf("Khong tim thay ma nhan vien can xoa.\n");
    }
}

void them(NhanVien nv[], int *size) {
    if (*size >= MAX_SIZE) {
        printf("Danh sach nhan vien da day.\n");
        return;
    }
    nhap(&nv[*size]);
    (*size)++;
}

void sua(NhanVien nv[], int size) {
    long long Ma;
    printf("Nhap ma nhan vien can sua: ");
    scanf("%lld", &Ma);
    for (int i = 0; i < size; ++i) {
        if (nv[i].maNV == Ma) {
            nhap(&nv[i]);
            printf("Sua thong tin thanh cong.\n");
            return;
        }
    }
    printf("Khong tim thay ma nhan vien.\n");
}

void sapXepTheoTen(NhanVien nv[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = i + 1; j < size; ++j) {
            if (strcmp(nv[i].HovaTen, nv[j].HovaTen) > 0) {
                NhanVien temp = nv[i];
                nv[i] = nv[j];
                nv[j] = temp;
            }
        }
    }
    printf("\nSau khi sap xep theo ten:\n");
    xuatds(nv, size);
}

int main() {
    NhanVien nv[MAX_SIZE];
    int size = 0;
    int choice;

    while (1) {
        printf("\n===============MENU=================\n");
        printf("1. Nhap danh sach nhan vien\n");
        printf("2. Xuat danh sach nhan vien\n");
        printf("3. Tim nhan vien theo ma nhan vien\n");
        printf("4. Tim nhan vien theo CCCD\n");
        printf("5. Tim nhan vien theo ten\n");
        printf("6. Sap xep danh sach nhan vien tang dan theo thuc linh\n");
        printf("7. Tinh tong luong cua tat ca nhan vien\n");
        printf("8. Tim nhan vien co thuc linh cao nhat\n");
        printf("9. Tim nhan vien co phu cap > 100000\n");
        printf("10. Xoa nhan vien\n");
        printf("11. Them nhan vien\n");
        printf("12. Sua thong tin nhan vien\n");
        printf("13. Sap xep danh sach nhan vien theo ten\n");
        printf("0. Thoat chuong trinh\n");
        printf("Nhap lua chon cua ban: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                nhapds(nv, &size);
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
                xoa(nv, &size);
                break;
            case 11:
                them(nv, &size);
                break;
            case 12:
                sua(nv, size);
                break;
            case 13:
                sapXepTheoTen(nv, size);
                break;
            case 0:
                printf("Cam on ban da su dung chuong trinh!\n");
                return 0;
            default:
                printf("Lua chon khong hop le. Vui long chon lai!\n");
                break;
        }
    }

    return 0;
}
