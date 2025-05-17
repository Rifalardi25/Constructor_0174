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
        buku(string j, string p) : judul(j), penulis(p), dipinjam(false) {}
        friend class petugas;

};

class peminjam
{
    private:
    string nama;
    string id;
    int totalPinjaman;

    
    
};

class petugas 
{
    private:
    string nama;
    string idPetugas;
    string levelAkses;
};

class admin 
{
    private:

};

