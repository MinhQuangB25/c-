#include<iostream>
#include<string>
using namespace std;
// Hàm nhập mảng 2 chiều
void nhapmang(int **&a,int &m,int &n)
{
    cout<<"xin moi nhap m:";
    cin>>m;
    cout<<"xin moi nhap n:";
    cin>>n;
    a=new int *[m];
    for (int i = 0; i < m; i++)
    {
        a[i]=new int[n];
        for (int j = 0; j < n; j++)
        {
             cout<<"phan tu thu a"<<"["<<i<<"]"<<"["<<j<<"]:";
            cin>>a[i][j];
        }
        
    }
    
}
// Hàm xuất mảng 2 chiều
void xuatmang(int **a,int m,int n)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
           cout<<a[i][j]<<" ";
        }
        cout<<endl;
        
    }
    
    
}
// Hàm tìm giá trị nhỏ nhất của mảng
int timgiatrnhonhat(int **a,int m,int n)
{
        int nhonhat=a[0][0];
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (a[i][j]<nhonhat)
                {
                    nhonhat=a[i][j];
                }
                
            }
            
        }
        return nhonhat;
        
}
// Hàm tính tổng các phần tử trên mỗi dòng của mảng
void tongcacphantu(int **a,int m,int n)
{
    cout<<"tong cac phan tu tren moi dong:\n";
    for (int i = 0; i < m; i++)
    {
        int sum=0;
        for (int j = 0; j < n; j++)
        {
            sum+=a[i][j];
        }
        cout << "Dong " << i << ": " << sum << endl;
        
    }
    
}
// Hàm tìm giá trị nhỏ nhất trên mỗi cột
void  giatrinhonhatmoicot(int **a,int m,int n)
{
    cout<<"gia tri nho nhat cua moi cot \n";
    for (int j = 0; j < n; j++)
    {
       int min=a[0][j];
       for (int i = 1; i < m; i++)
       {
        if (a[i][j]<min)
        {
            min=a[i][j];
        }
        
       }
        cout << "Cot " << j << ": " << min << endl;
    }
    
}
// Hàm giải phóng bộ nhớ
void giaiphongbonho(int **a,int m)
{
    for (int i = 0; i < m; i++)
    {
        delete []a[i];
    }
    delete []a;
    
}
int main() //Bùi Minh Quang-3123411240-DCT123C6
{
    int m,n;
    int **a;
    //a)  Nhập và xuất mảng 2 chiều.
    nhapmang(a,m,n);
    xuatmang(a,m,n);
    //b)  Tìm giá trị nhỏ nhất của mảng.
    int kqa=timgiatrnhonhat(a,m,n);
    cout<<"gia tri nho nhat la:"<<kqa<<endl;
    //c)  Tính tổng các phần tử trên mỗi dòng của mảng. 
    tongcacphantu(a,m,n);
     //d)  Tìm giá trị nhỏ nhất trên mỗi cột.
    giatrinhonhatmoicot(a,m,n);
    giaiphongbonho(a,m);

}