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
    friend class admin;
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
    petugas(string n, string ip, string lv) : nama(n), idPetugas(ip), levelAkses(lv){}
    void prosesPinjam(buku& b, peminjam& p)
    {
        if (!b.dipinjam) 
        {
            b.dipinjam = true;
            p.totalPinjaman++;
            cout << "Buku berhasil dipinjam oleh " << p.nama << endl;
        } 
        else 
        {
            cout << "Buku sedang dipinjam.\n";
        }
    }

        void prosesKembali(buku& b, peminjam& p) 
    {
        if (b.dipinjam) {
            b.dipinjam = false;
            p.totalPinjaman--;
            cout << "Buku dikembalikan oleh " << p.nama << endl;
        } else {
            cout << "Buku belum dipinjam.\n";
        }
    }

    friend class admin;
};



class admin 
{
   public:
   void lihatStatistik(const peminjam &p, const buku &b)
   {
            cout << "Statistik Peminjam:\n";
        cout << "- Nama: " << p.nama << "\n";
        cout << "- Total Pinjaman: " << p.totalPinjaman << "\n";
        cout << "- Status Buku: " << (b.dipinjam ? "Dipinjam" : "Tersedia") << "\n";

   }
   void ubahLevelPetugas(petugas &pgs, string levelBaru)
    {
        pgs.levelAkses = levelBaru;
        cout << "Level akses petugas " << pgs.nama << " diubah menjadi " << levelBaru << endl;
    }
};

int main()
{
    buku buku("Sejarah Bantul", "Gibran van Saput");
    peminjam peminjam("Lik Haffi", "PM001");
    petugas petugas("Bowo", "PT001", "standard");
    admin admin;

    petugas.prosesPinjam(buku, peminjam);
    admin.lihatStatistik(peminjam, buku);
    petugas.prosesKembali(buku, peminjam);
    admin.ubahLevelPetugas(petugas, "senior");
    admin.lihatStatistik(peminjam, buku);

    return 0;
}

