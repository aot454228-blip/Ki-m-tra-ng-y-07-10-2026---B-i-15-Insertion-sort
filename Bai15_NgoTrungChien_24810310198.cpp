#include <iostream>
#include <string>
using namespace std;

struct KhachHang
{
    int maKH;
    string tenKH;
    string soDT;
    string diaChi;
    float tongTien;
};

void nhapDanhSach(KhachHang a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "\nNhap khach hang thu " << i + 1 << ":\n";

        cout << "Ma khach hang: ";
        cin >> a[i].maKH;
        cin.ignore();

        cout << "Ten khach hang: ";
        getline(cin, a[i].tenKH);

        cout << "So dien thoai: ";
        getline(cin, a[i].soDT);

        cout << "Dia chi: ";
        getline(cin, a[i].diaChi);

        cout << "Tong tien thanh toan: ";
        cin >> a[i].tongTien;
    }
}

void xuatDanhSach(KhachHang a[], int n)
{
    cout << "\n========== DANH SACH KHACH HANG ==========\n";

    for (int i = 0; i < n; i++)
    {
        cout << "\nKhach hang " << i + 1 << ":\n";
        cout << "Ma KH: " << a[i].maKH << endl;
        cout << "Ten KH: " << a[i].tenKH << endl;
        cout << "So dien thoai: " << a[i].soDT << endl;
        cout << "Dia chi: " << a[i].diaChi << endl;
        cout << "Tong tien thanh toan: " << a[i].tongTien << endl;
    }
}

void sapXep(KhachHang a[], int n)
{
    for (int i = 1; i < n; i++)
    {
        KhachHang x = a[i];
        int j = i - 1;

        while (j >= 0 && a[j].tongTien > x.tongTien)
        {
            a[j + 1] = a[j];
            j--;
        }

        a[j + 1] = x;
    }
}

void timKiemNhiPhan(KhachHang a[], int n, float X)
{
    int left = 0;
    int right = n - 1;
    int viTri = -1;

    while (left <= right)
    {
        int mid = (left + right) / 2;

        if (a[mid].tongTien == X)
        {
            viTri = mid;
            break;
        }
        else if (a[mid].tongTien < X)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    if (viTri == -1)
    {
        cout << "\nKhong tim thay khach hang co tong tien = " << X << endl;
        return;
    }

    cout << "\nCac khach hang co tong tien = " << X << ":\n";

    int i = viTri;

    while (i >= 0 && a[i].tongTien == X)
    {
        i--;
    }

    i++;

    while (i < n && a[i].tongTien == X)
    {
        cout << "\nMa KH: " << a[i].maKH << endl;
        cout << "Ten KH: " << a[i].tenKH << endl;
        cout << "So dien thoai: " << a[i].soDT << endl;
        cout << "Dia chi: " << a[i].diaChi << endl;
        cout << "Tong tien: " << a[i].tongTien << endl;

        i++;
    }
}

int main()
{
    int n;

    cout << "Nhap so luong khach hang: ";
    cin >> n;

    KhachHang a[100];

    nhapDanhSach(a, n);

    cout << "\n\nDANH SACH VUA NHAP:";
    xuatDanhSach(a, n);

    sapXep(a, n);

    cout << "\n\nDANH SACH SAU KHI SAP XEP TANG DAN:";
    xuatDanhSach(a, n);

    float X;
    cout << "\n\nNhap X can tim: ";
    cin >> X;

    timKiemNhiPhan(a, n, X);

    return 0;
}
