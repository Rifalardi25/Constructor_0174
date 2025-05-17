#include <iostream>
#include <string>
using namespace std;

class petugas;
class buku 
{
    private:
    string judul;
    string penulis;
    bool dipinjam;
    
    public:
    buku(string j, string p) : judul(j), penulis(p), dipinjam(false){}
    friend class petugas;

};

class peminjam
{
    private:
    string nama;
    string id;
    int totalPinjaman;

    public:
    peminjam(string n, string i) : nama(n), id(i), totalPinjaman(0){}
    friend class petugas;
    friend class admin;
};

class petugas 
{
    private:
    string nama;
    string idPetugas;
    string levelAkses;

    public:
    petugas(string n, string ip) : nama(n), idPetugas(ip), levelAkses(0){}
    friend class admin;
};

class admin 
{
    

};

