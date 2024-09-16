#include<iostream>
#include<fstream>
#include<cmath>
using namespace std;
// Hàm đọc file input và lưu trữ bằng mảng một chiều
void docfile(ifstream &file,int *&a,int &n )
{
    file>>n;
    a=new int[n];
    for (int i = 0; i < n; i++)
    {
        file>>a[i];
    }
    
}
// Hàm kiểm tra số nguyên tố
bool songuyento(int n)
{
    if (n<2)
    {
        return false;
    }
    else
    {
        for (int i = 2; i <= sqrt(n); i++)
        {
            if (n%i==0)
            {
               return false;
            }
            
        }
        
    }
    return true;
}
// Hàm tính trung bình cộng các số nguyên tố trong mảng
double trungbbinhcong(int *a,int n)
{
    int sum=0;
    int count=0;
    for (int i = 0; i < n; i++)
    {
        if (songuyento(a[i]))
        {
            sum+=a[i];
            count++;

        }
        
    }
    if (count==0)
    {
        return 0;
    }
    return static_cast<double>(sum)/count;
    
    
}
// Hàm xóa số nguyên tố khỏi mảng và ghi mảng sau khi xóa vào file
int xoanguyento(int *&a,int &n)
{
    int newsize=0;
    int *newarr=new int[n];
    for (int i = 0; i < n; i++)
    {
        if (!songuyento(a[i]))
        {
            newarr[newsize++]=a[i];
        }
        
    }
    delete[]a;
    a=newarr;
    return newsize;
    
}
// Hàm kiểm tra số chính phương
bool laSoChinhPhuong(int num) {
    int canBacHai = sqrt(num);
    return canBacHai * canBacHai == num;
}
// Hàm tìm số chính phương nhỏ nhất lớn hơn mọi phần tử trong mảng
int timSoChinhPhuongNhoNhat(int* arr, int n) {
    int soChinhPhuongNhoNhat = numeric_limits<int>::max();
    for (int i = 0; i < n; ++i) {
        if (laSoChinhPhuong(arr[i]) && arr[i] < soChinhPhuongNhoNhat) {
            soChinhPhuongNhoNhat = arr[i];
        }
    }
    return soChinhPhuongNhoNhat;
}
int main() //Bùi Minh Quang-3123411240-DCT123C6
{
    ifstream fi("E:\\c++\\input.txt");
    if (!fi.is_open())
    {
        cout<<"khong the mo file"<<endl;
        return 1;
    }
    int n;
    int *a;
    // a) Đọc file input và lưu trữ bằng mảng một chiều
    docfile(fi,a,n);
    
    ofstream fo("E:\\c++\\output.txt");
    if ((!fo.is_open()))
    {
        cout<<"khong the mo file";
        return 1;
    }
   // b) Tính trung bình cộng các số nguyên tố trong mảng
    double kqb=trungbbinhcong(a,n);
    fo<<"trung binh cong b) "<<kqb<<endl;
    // c) Xóa tất cả số nguyên tố ra khỏi mảng, ghi mảng sau khi xóa xuống file
    int newsize=xoanguyento(a,n);  
    fo<<"mang sau khi xoa so nguyen to c: ";
    for (int i = 0; i < newsize; i++)
    {
        fo<<a[i]<<" ";
    }
    fo<<endl;
    //d) Tìm số chính phương nhỏ nhất thỏa điều kiện lớn hơn mọi phần tử trong mảng
    int kqd=timSoChinhPhuongNhoNhat(a,n);
    fo<<"d)"<<kqd<<endl;
    
    fi.close();
    fo.close();
    delete[]a;
    
    
    
}