/*                      SAKARYA ÜNİVERSİTESİ 
                BİLGİSAYAR VE BİLİŞİM BİLİMLERİ FAKÜLTESİ
                    BİLGİSAYAR MÜHENDİSLİĞİ BÖLÜMÜ 
                      PROGRAMLAMAYA GİRİŞİ DERSİ 


ÖDEV NUMARASI: 1.ÖDEV   
ÖĞRENCİ ADI-SOYADI: HÜSEYİN AYDIN   
ÖĞRENCİ NUMARASI: G231210046
DERS GRUBU: (İÖ) B GRUBU


*/

#include <iostream>
#include <iomanip>
#include <ctime>

using namespace std;

//struct yapısında öğrenci bilgilerini düzenli bir şekide tutmak için Ogrenci adlı bir veri oluşturuyoruz.
struct Ogrenci {
    string isim;
    string soyisim;
    int vize;
    int odev1;
    int odev2;
    int kisaSinav1;
    int kisaSinav2;
    int final1;
    double yilIciPuan;
    double yilSonuNotu;
    string harfNotu;
};


int main()
{
    // Türekçe karakter girebilmemiz için bu kodu kullanıyoruz.
    setlocale(LC_ALL, "Turkish");

    //Rastgele sayı üretiminde aynı değerde sayıyı üretmesi için sayı listesini baştan taratır.
    srand(time(0));

    //Rastgele alacağımız isim kütüphanesi oluşturuyoruz.
    string isimler[16] = { "Akın" , "Ali" , "Selim" , "Hüseyin" , "Emre", "Musa", "Ahmet","Ceren","Bengisu","Nida","Ayşe","Fatma","İzzet","İbrahim","Ömer","Yusuf" };
    string soyisimler[15] = { "Aydın", "Üçtepe", "İnel", "Özköse","Ayyıldız","Koçyiğit","Akköse","Bilgin","Sağlam","Özer","Avcı","Önal","Çalıova","Ekşi","Bayram" };

    int vize, odev1, odev2, kisaSinav1, kisaSinav2;

    //İstenilen durum gerçekleşmediğinde sistemi tekrarlaması için while döngüsüne alıyoruz.
    while (true) {

        cout << "Lütfen ağırlıklar toplamı 100 olacak şekilde yıl içi ağırlıklarını giriniz !!!" << endl;
        cout << endl;

        cout << "Öğrenci vize yıl içi not ağırlığını giriniz: ";
        cin >> vize;

        cout << "Öğrenci ödev 1 yıl içi not ağırlığını giriniz: ";
        cin >> odev1;

        cout << "Öğrenci ödev 2 yıl içi not ağırlığını giriniz: ";
        cin >> odev2;

        cout << "Öğrenci kısa sınav 1 yıl içi not ağırlığını giriniz: ";
        cin >> kisaSinav1;

        cout << "Öğrenci kısa sınav 2 yıl içi not ağırlığını giriniz: ";
        cin >> kisaSinav2;

        if (100 == (vize + odev1 + odev2 + kisaSinav1 + kisaSinav2)) {
            break;
        }
        else {
            cout << "Girdiğiniz ağırlıkların toplam değeri 100 olmalıdır." << endl;
        }

    }
    cout << endl;

    int final1;
    double yilIciPuan;
    double yilSonuNotu;

    //İstenilen durum gerçekleşmediğinde sistemi tekrarlaması için while döngüsüne alıyoruz.
    while (true) {

        cout << "Lütfen ağırlıklar toplamı 100 olacak şekilde geçme notu ağırlıklarını giriniz !!!" << endl;
        cout << endl;

        cout << "Yıl içi puanının geçme notuna etkisini giriniz: ";
        cin >> yilIciPuan;

        cout << "Final notunun geçme notuna etkisini giriniz: ";
        cin >> final1;

        if (100 == (final1 + yilIciPuan)) {
            break;
        }
        else {
            cout << "Girdiğiniz geçme notnuna etki değerler toplamı 100 olmalıdır." << endl;
        }

    }




    int ogrenciSayisi;
    cout << "Sınıftaki öğrenci sayısını giriniz: ";
    cin >> ogrenciSayisi;
    cout << endl;

    //Girilen öğrenci sayısı kadar Ogrenci veri yapısı oluşturur.
    Ogrenci* ogrenciler = new Ogrenci[ogrenciSayisi];

    double sinifOrt, sinifStandartSapma, enYuksekNot, enDusukNot;
    float standartSapma1;
    standartSapma1 = 0;
    sinifOrt = 0;
    //Öğrencilerin alamayacağı bir değer girerek en yüksek notun başlangıçını belirliyoruz.
    enYuksekNot = -1;
    //Öğrencilerin alamayacağı bir değer girerek en düşük notun başlangıçını belirliyoruz.
    enDusukNot = 101;
    sinifStandartSapma = 0;

    float AAsayisi = 0;
    float BAsayisi = 0;
    float BBsayisi = 0;
    float CBsayisi = 0;
    float CCsayisi = 0;
    float DCsayisi = 0;
    float DDsayisi = 0;
    float FDsayisi = 0;
    float FFsayisi = 0;

    float AAharfYuzdeligi, BAharfYuzdeligi, BBharfYuzdeligi, CBharfYuzdeligi, CCharfYuzdeligi, DCharfYuzdeligi, DDharfYuzdeligi, FDharfYuzdeligi, FFharfYuzdeligi;

    AAharfYuzdeligi = 0;
    BBharfYuzdeligi = 0;
    CBharfYuzdeligi = 0;
    CCharfYuzdeligi = 0;
    DCharfYuzdeligi = 0;
    DDharfYuzdeligi = 0;
    FDharfYuzdeligi = 0;
    FFharfYuzdeligi = 0;

    //Girilen öğrenci sayısı kadar öğrenci bilgilerini dolduracak.
    for (int i = 0; i < ogrenciSayisi; i++)
    {
        //Öğrenci sayısının %20'si 80-100 arası rastgele not alması için if  yapısını kullanıyoruz.
        if (i < (ogrenciSayisi * 20) / 100)
        {
            ogrenciler[i].vize = 80 + rand() % 21;
            ogrenciler[i].odev1 = 80 + rand() % 21;
            ogrenciler[i].odev2 = 80 + rand() % 21;
            ogrenciler[i].kisaSinav1 = 80 + rand() % 21;
            ogrenciler[i].kisaSinav2 = 80 + rand() % 21;
            ogrenciler[i].final1 = 80 + rand() % 21;

        }
        //Öğrenci sayısının %50'si 50-80 arası rastgele not alması için else if  yapısını kullanıyoruz.
        else if (i < (ogrenciSayisi * 70) / 100)
        {
            ogrenciler[i].vize = 50 + rand() % 31;
            ogrenciler[i].odev1 = 50 + rand() % 31;
            ogrenciler[i].odev2 = 50 + rand() % 31;
            ogrenciler[i].kisaSinav1 = 50 + rand() % 31;
            ogrenciler[i].kisaSinav2 = 50 + rand() % 31;
            ogrenciler[i].final1 = 50 + rand() % 31;

        }
        //Öğrenci sayısının gerikalanının 00-50 arası rastgele not alması için else yapısını kullanıyoruz.
        else {
            ogrenciler[i].vize = rand() % 51;
            ogrenciler[i].odev1 = rand() % 51;
            ogrenciler[i].odev2 = rand() % 51;
            ogrenciler[i].kisaSinav1 = rand() % 51;
            ogrenciler[i].kisaSinav2 = rand() % 51;
            ogrenciler[i].final1 = rand() % 51;
        }
        //İsim ve soyisimler için oluşturduğumuz kütüphaneden rastegele isim ve soyisim atıyoruz.
        ogrenciler[i].isim = isimler[rand() % 16];
        ogrenciler[i].soyisim = soyisimler[rand() % 15];

        //Öğrencilerin yıl içi puan ve yı sonu notunu hesaplıyoruz.
        ogrenciler[i].yilIciPuan = ogrenciler[i].vize * vize / 100 + ogrenciler[i].odev1 * odev1 / 100 + ogrenciler[i].odev2 * odev2 / 100 + ogrenciler[i].kisaSinav1 * kisaSinav1 / 100 + ogrenciler[i].kisaSinav2 * kisaSinav2 / 100;
        ogrenciler[i].yilSonuNotu = ogrenciler[i].final1 * final1 / 100 + ogrenciler[i].yilIciPuan * yilIciPuan / 100;

        //Sınıf ortalamasını hesaplıyoruz.
        sinifOrt += ogrenciler[i].yilSonuNotu / ogrenciSayisi;

        //En yüksek notu hesaplamak için if yapısını kullanıyoruz. 
        if (enYuksekNot < ogrenciler[i].yilSonuNotu) {
            enYuksekNot = ogrenciler[i].yilSonuNotu;
        }

        //En düşük notu hesaplamak için if yapısını kullanıyoruz. 
        if (ogrenciler[i].yilSonuNotu < enDusukNot) {
            enDusukNot = ogrenciler[i].yilSonuNotu;
        }



        string notHarfDegeri;

        /*İf, else if ve else yapılarıyla not karşılığına gelecek harf notunu hesaplıyoruz.Öğrencinin aldığı not hangi harfe denk geliyorsa
         hangi harften kaç öğrenci olduğunu hesaplamak için o harf sayısını da 1 arttırıyoruz*/
        if (90 <= ogrenciler[i].yilSonuNotu && ogrenciler[i].yilSonuNotu < 100) {
            notHarfDegeri = "AA";
            AAsayisi++;

        }
        else if (85 <= ogrenciler[i].yilSonuNotu && ogrenciler[i].yilSonuNotu < 90) {
            notHarfDegeri = "BA";
            BAsayisi++;

        }
        else if (80 <= ogrenciler[i].yilSonuNotu && ogrenciler[i].yilSonuNotu < 85) {
            notHarfDegeri = "BB";
            BBsayisi++;

        }
        else if (75 <= ogrenciler[i].yilSonuNotu && ogrenciler[i].yilSonuNotu < 80) {
            notHarfDegeri = "CB";
            CBsayisi++;

        }
        else if (65 <= ogrenciler[i].yilSonuNotu && ogrenciler[i].yilSonuNotu < 75) {
            notHarfDegeri = "CC";
            CCsayisi++;

        }
        else if (58 <= ogrenciler[i].yilSonuNotu && ogrenciler[i].yilSonuNotu < 65) {
            notHarfDegeri = "DC";
            DCsayisi++;

        }
        else if (50 <= ogrenciler[i].yilSonuNotu && ogrenciler[i].yilSonuNotu < 58) {
            notHarfDegeri = "DD";
            DDsayisi++;

        }
        else if (40 <= ogrenciler[i].yilSonuNotu && ogrenciler[i].yilSonuNotu < 50) {
            notHarfDegeri = "FD";
            FDsayisi++;

        }
        else if (0 <= ogrenciler[i].yilSonuNotu && ogrenciler[i].yilSonuNotu < 40) {
            notHarfDegeri = "FF";
            FFsayisi++;

        }

        //Alınan harf notunun yüzdeliğini hesaplıyoruz.
        AAharfYuzdeligi = AAsayisi * 100 / ogrenciSayisi;
        BAharfYuzdeligi = BAsayisi * 100 / ogrenciSayisi;
        BBharfYuzdeligi = BBsayisi * 100 / ogrenciSayisi;
        CBharfYuzdeligi = CBsayisi * 100 / ogrenciSayisi;
        CCharfYuzdeligi = CCsayisi * 100 / ogrenciSayisi;
        DCharfYuzdeligi = DCsayisi * 100 / ogrenciSayisi;
        DDharfYuzdeligi = DDsayisi * 100 / ogrenciSayisi;
        FDharfYuzdeligi = FDsayisi * 100 / ogrenciSayisi;
        FFharfYuzdeligi = FFsayisi * 100 / ogrenciSayisi;


        ogrenciler[i].harfNotu = notHarfDegeri;

        //Öğrenci değerlerini yazdırıyoruz.
        cout << "İsim: " << ogrenciler[i].isim << endl;
        cout << "Soyisim: " << ogrenciler[i].soyisim << endl;
        cout << "Vize: " << ogrenciler[i].vize << endl;
        cout << "Ödev 1: " << ogrenciler[i].odev1 << endl;
        cout << "Ödev 2: " << ogrenciler[i].odev2 << endl;
        cout << "Kısa sınav 1: " << ogrenciler[i].kisaSinav1 << endl;
        cout << "Kısa sınav 2: " << ogrenciler[i].kisaSinav2 << endl;
        cout << "Final: " << ogrenciler[i].final1 << endl;
        cout << "Yıl içi puan:  " << ogrenciler[i].yilIciPuan << endl;
        cout << "Yıl sonu puan: " << ogrenciler[i].yilSonuNotu << "  " << ogrenciler[i].harfNotu << endl;
        cout << endl;
        cout << endl;
    }

    for (int i = 0; i < ogrenciSayisi; i++)
    {
        //Standart sapma hesaplaması yapıyoruz.
        standartSapma1 += (ogrenciler[i].yilSonuNotu - sinifOrt) * (ogrenciler[i].yilSonuNotu - sinifOrt);
        sinifStandartSapma = sqrt(standartSapma1 / (ogrenciSayisi - 1));
    }
    //Sınıf genel değerleri yazdırıyoruz.
    cout << "Sınıf ortalaması: " << sinifOrt << endl;
    cout << endl;
    cout << "Sınıfın en yüksek notu: " << enYuksekNot << endl;
    cout << endl;
    cout << "Sınıfın en düşük notu: " << enDusukNot << endl;
    cout << endl;
    cout << "Sınıfın standart sapması: " << sinifStandartSapma << endl;
    cout << endl;
    cout << "AA notu alan öğrenci sayısı: " << AAsayisi << " AA alan öğrenci yüzdesi %" << AAharfYuzdeligi << endl;
    cout << "BA notu alan öğrenci sayısı: " << BAsayisi << " BA alan öğrenci yüzdesi %" << BAharfYuzdeligi << endl;
    cout << "BB notu alan öğrenci sayısı: " << BBsayisi << " BB alan öğrenci yüzdesi %" << BBharfYuzdeligi << endl;
    cout << "CB notu alan öğrenci sayısı: " << CBsayisi << " CB alan öğrenci yüzdesi %" << CBharfYuzdeligi << endl;
    cout << "CC notu alan öğrenci sayısı: " << CCsayisi << " CC alan öğrenci yüzdesi %" << CCharfYuzdeligi << endl;
    cout << "DC notu alan öğrenci sayısı: " << DCsayisi << " DC alan öğrenci yüzdesi %" << DCharfYuzdeligi << endl;
    cout << "DD notu alan öğrenci sayısı: " << DDsayisi << " DD alan öğrenci yüzdesi %" << DDharfYuzdeligi << endl;
    cout << "FD notu alan öğrenci sayısı: " << FDsayisi << " FD alan öğrenci yüzdesi %" << FDharfYuzdeligi << endl;
    cout << "FF notu alan öğrenci sayısı: " << FFsayisi << " FF alan öğrenci yüzdesi %" << FFharfYuzdeligi << endl;
}