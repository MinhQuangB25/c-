#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
// Hàm tách chuỗi thành các từ và đếm số từ
int tachchuoi(const char *s)
{
    int dem=0;
    const char *p=s;
    while (*p)
    {
        if (*p==' ')
        {
            dem++;
            while (*p&&*p==' ')
            {
                p++;
            }
            
        }
        else
        {
            p++;
        }
        
    }
    return dem+1;
    
}
// Hàm sắp xếp các từ trong chuỗi theo thứ tự giảm dần
void sapxep(char *s)
{
    // Tạo một mảng lưu trữ các từ
    string *w=new string[tachchuoi(s)];
    int chu=0;
     // Tách chuỗi thành các từ và lưu vào mảng
    char *a=strtok(s," ");
    while (a!=NULL)
    {
        w[chu++]=a;
        a=strtok(NULL," ");
    }
    for (int i = 0; i < chu-1; i++)
    {
        for (int j = i+1; j < chu; j++)
        {
            if (*(w[i].c_str())<*(w[j].c_str()))
            {
                swap(w[i],w[j]);
            }
            
        }
        
    }
    strcpy(s,w[0].c_str());
    for (int i = 1; i < chu; i++)
    {
        strcat(s," ");
        strcat(s,w[i].c_str());
    }
    delete []w;
    
    
    
}
// Hàm đếm số lần xuất hiện của mỗi từ
void demsolan(const char *s)
{
    const int solonnhat=100;
    string sotu[solonnhat];
    int dem[solonnhat]={0};
    int so=0;
    char *copy=strdup(s);
    char *kyhieu=strtok(copy," ");
    while (kyhieu!=NULL)
    {
        string tu(kyhieu);
        int vitri=-1;
        for (int i = 0; i < so; i++)
        {
            if (sotu[i]==tu)
            {
                vitri=i;
                break;
            }
            
        }
        if (vitri!=-1)
        {
            dem[vitri]++;
        }
        else
        {
            sotu[so]=tu;
            dem[so]=1;
            so++;
        }
        kyhieu=strtok(NULL," ");
        
        
    }
    free(copy);
    cout<<"so lan xuat hien cua moi tu:"<<endl;
    for (int i = 0; i < so; i++)
    {
        cout<<sotu[i]<<":"<<dem[i]<<endl;
    }
    
    
}
// Hàm tìm và in ra các từ có số lần xuất hiện lớn hơn hoặc bằng k
void timcacsotuxuathien(const char*s,int k)
{
    const int so_tu_toi_da=100;
    string tu[so_tu_toi_da];
    int solanxuathien[so_tu_toi_da]={0};
    int sotu=0;
    char *copy=strdup(s);
    char *token=strtok(copy," ");
    while (token!=NULL)
    {
        string  tus(token);
        int vitri=-1;
        for (int i = 0; i < sotu; i++)
        {
            if (tu[i]==tus)
            {
                vitri=i;
                break;
            }
            
        }
        if (vitri!=-1)
        {
            solanxuathien[vitri]++;
        }
        else
        {
            tu[sotu]=tus;
            solanxuathien[sotu]=1;
            sotu++;
        }
        token=strtok(NULL," ");
        
        
    }
    free(copy);
    cout<<"cac tu xuat hien lon hon bang "<<k<<":"<<endl;
    for (int i = 0; i < sotu; i++)
    {
        if (solanxuathien[i]>=k)
        {
            cout<<tu[i]<<": "<<solanxuathien[i]<<endl;
        }
        
    }
    
    
}
// Hàm xóa tất cả các vị trí mà ký tự c xuất hiện trong chuỗi str
void xoakytu(char *s,char c)
{
    int len=strlen(s);
    int shift=0;
    for (int i = 0; i < len; i++)
    {
        if (s[i]==c)
        {
            shift++;
        }
        else
        {
            s[i-shift]=s[i];
        }
        
    }
    s[len-shift]='\0';
    
}
int main() //Bùi Minh Quang-3123411240-DCT123C6
{
    const int solonnhat = 1000;
    char s[solonnhat];
    cout << "Nhap vao chuoi ky tu: ";
    cin.getline(s, solonnhat);
    // a) Đếm số từ
    int kqa = tachchuoi(s);
    cout << "So tu trong chuoi: " << kqa << endl;
    // b) Sắp xếp các từ giảm dần
   sapxep(s);
    cout<<"sap xep giam dan:"<<s<<endl;
    // c) Đếm số lần xuất hiện của mỗi từ
    demsolan(s);
    // d) Tìm các từ có số lần xuất hiện lớn hơn hoặc bằng k
    int k;
    cout<<"nhap vao k:";
    cin>>k;
    timcacsotuxuathien(s,k);
    // e) Nhập vào một ký tự và xóa các vị trí xuất hiện của ký tự đó trong chuỗi
    char kytu;
    cout<<"nhap vao ky tu can xoa: ";
    cin>>kytu;
    xoakytu(s,kytu);
    cout<<"chuoi ky tu sau khi xoa "<<kytu<<": "<<s<<endl;
return 0;

}