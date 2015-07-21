#include <stdio.h>
#include <stdlib.h>
int main()
{
    int no,ders,notu,kredi,ogrenciSay=0,basariliKiz=0,basariliErkek=0,basarisizKiz=0,basarisizErkek=0,erkekSay=0,kizSay=0;
    int altmisSay=0,kisiHesap=0,toplam=0,kisiKredi=0,kisiToplam=0,toplamHesap=0,toplamKredi=0;
    int dersUcKucuk=0,notOtuzbes=0,notSeksenbes=0,ucyuz=0,biriciNo=0,birinciKredi=0,enCokNo=0,enCokKredi=0,evSay=0,aileSay=0,yurtSay=0,i=0;
    char cinsiyet,ikamet;
    float ortalama=0,ucret=0,BasariliErkekYuzdesi=0,basariliKizYuzdesi=0,okulBasariYuzdesi=0,kizOrtalama=0,erkekOrtalama=0,okulOrtalama=0;
    float krediOrtalama=0,ucyuzYuzdesi=0,birinciNoOrtalama=0,birinciUcret=0,enCokUcret=0,enCokOrtalama=0,ayUcret=0,evYuzde=0;
    float dersTopla=0,aileYuzde=0,yurtYuzde=0,altmisYuzde=0,notOtuzbesYuzde=0,notSeksenbesYuzde=0,max=0;

    printf("Ogrenci Numarasini Giriniz(Cikis Icin 0 veya Negatif Sayi Giriniz):");
    scanf("%d",&no);
    if(no<=0)
    printf("Cikis Degeri Girilmistir\nProgram Sonlandirilmistir..!\n");  // cikis deðeri girilip programa giris yapmak istemedigimiz zaman cikmamizi saglar
    else{

    while(no>0)  // numaranin cikis degeri olmadigi müddetce asagidaki islemleri yapacak
    {
        printf("\nCinsiyeti (E/e:erkek, K/k:kiz)=");
        fflush(stdin);
        cinsiyet=getchar();   // karakterin alinmasini sagladik..
        while (cinsiyet!='E' && cinsiyet!='e' && cinsiyet!='K' && cinsiyet!='k')
        {
            printf("Hatali Veri Girisi Lutfen Ogrencinin Cinsiyetini Tekrar Giriniz.(E|e,K|k)\n");  // hata raporu belirtildi
            fflush(stdin);
            cinsiyet=getchar();
        }
        printf("Ikamet Yeri (A/a:ailesiyle, Y/y:yurtta, E/e:evde):");
        fflush(stdin);
        ikamet=getchar();  // burada da karakter alinmasini sagladik ama ayrica erkegin 'e' siyle karismamis oldu bu ise de yarar
        while (ikamet!='A' && ikamet!='a' && ikamet!='Y' && ikamet!='y' && ikamet!='E' && ikamet!='e')  // ikamet yerlerinin alinmasi saglandi
        {
            printf("Hatali Veri Girisi Yaptiniz Lutfen Ikamet Yerini Tekrar Giriniz.(A|a,Y|y,E|e)\n");  // hata raporu verildi
            fflush(stdin);
            ikamet=getchar();
        }
        printf("Bir Donemde Aldigi Ders Sayisi (1-10 Arasinda Tamsayi):");
        scanf("%d",&ders);
        while(ders<1||ders>10)  // ders sayisinin araligini belirlemis olduk
        {
            printf("Hatali Veri Girisi Yaptiniz! (1-10 Arasinda Tamsayi Olmali):");  // hata raporu
            scanf("%d",&ders);
        }

        kisiHesap=0;
        kisiKredi=0;  // ogrenciye ait krediyi ve hesabini 0 a atadik.
        for(i=1; i<=ders; i++)    // girilen ders sayisinin dongu icinde donmesini saglamis olduk
        {
            printf("%d.Dersin Kredisini Giriniz(1-10):",i);
            scanf("%d",&kredi);

            while(kredi<1 || kredi>10)  // ders kredisinin araligi belirlendi
            {
                printf("Hatali Veri Girisi!%d.Dersin Kredisini Giriniz(1 ile 10 Arasinda Olmali):",i);  // hata raporu
                scanf("%d",&kredi);
            }
            printf("%d.Dersin Notunu Giriniz(1-100):",i);
            scanf("%d",&notu);
            while(notu<0 || notu>100)  // dersin notunun araligi belirlendi
            {
                printf("%d. Dersin Notunu Hatali Girdiniz!(1-100 Arasinda Olmali):",i);  // hata raporu
                scanf("%d",&notu);
            }
            kisiHesap+=kredi*notu;
            kisiKredi+=kredi;
            toplamKredi+=kisiKredi;
            toplamHesap+=kisiHesap;  // kisiye ait kredisi ve hesaplamasi yapildi
        }
        ortalama=(float)kisiHesap/kisiKredi;  // kisiye ait agirliklandirilmis ortalamasi hesaplandi

        if(ortalama<60)  // basarisiz ogrencileri belirtecek olan not kosulu
        {
            ucret=100;  // basarisizlarin alacagi burs miktari atandi
            if(cinsiyet=='e' || cinsiyet=='E')
                basarisizErkek++;
            else
                basarisizKiz++;   // cinsiyete gore basarisiz sayisini artirdik
        }
        else if(ortalama>59 && ortalama<70)
            ucret=140+ortalama*1.2;
        else if(69<ortalama && ortalama<80)
            ucret=170+ortalama*1.3;
        else if(79<ortalama && ortalama<90)
            ucret=190+ortalama*1.5;
        else if(89<ortalama && ortalama<101)
            ucret=200+ortalama*1.8;           // bu kisimlarda ise diger not araliklari icin burs miktarlari hesaplandi
        if(cinsiyet=='e' || cinsiyet=='E')
            erkekSay++;
        else
            kizSay++;

        if(notu>60)   // basarili ogrencileri belirtecek olan not kosulu
        {
            if(ikamet=='a'||ikamet=='A')
                aileSay++;
            else if(ikamet=='y'||ikamet=='Y')
                yurtSay++;
            else
                evSay++;    // ikamet yerlerine gore sayilarini artirdik son istatistik veri icin
            altmisSay++;   // basarili sayisi artirildi
        }

        if(ortalama<35)   // 35'in altinda alanlarin kosulu
            notOtuzbes++;
            if(ortalama>85) // 85'in uzerinde alanlarin kosulu
            notSeksenbes++;
        if(cinsiyet=='k'||cinsiyet=='K')
            kizOrtalama+=ortalama;
        else
            erkekOrtalama+= ortalama;   // basarili erkek ve kizlarin sayilari ortalamaya eklendi
        if(ikamet=='y' || ikamet=='Y')
            ucret+=ucret*0.3;
        if(ikamet=='e' || ikamet=='E')
            ucret+=ucret*0.5;     // ikamet yerlerine gore ek burs hesaplama islemleri
        if(ucret>300)  // burs miktari 300 den buyuk olanlar
            ucyuz++;
        if(ortalama>birinciNoOrtalama)  // okul birincisinin bilgilerinin yazilmasi
        {
            birinciNoOrtalama=ortalama;
            biriciNo=no;
            birinciKredi=kredi;
            birinciUcret=ucret;
        }
        if(ucret>enCokUcret) // en cok burs alan kisiye ait bilgilerin yazilmasi
        {
            enCokOrtalama=ortalama;
            enCokKredi=kredi;
            enCokNo=no;
            enCokUcret=ucret;
        }
        ayUcret+=ucret;
        dersTopla+=ders;
        if(ders<4)  // aldigi ders sayisi 4'un altinda olanlar
            dersUcKucuk++;

        ogrenciSay++;
        printf("\n\nOgrenci Numarasi:%d",no);
        printf("\nBir Donemde Aldigi Derslerin Toplam Kredisi:%d",kisiKredi);
        printf("\nBir donemde Ki Agirliklandirilmis Not Ortalamasi:%.2f",ortalama);
        printf("\nSonraki Donem Alacagi Aylik Burs Miktari:%.2f (TL)\n",ucret);
        printf("\n\nOgrencinin Butun Verileri Girilmistir.\n"
               "Lutfen Siradaki Ogrencinin Numarasini Giriniz.\n");
        printf("Eger Yeni Giris Yapmayacaksaniz Ogrenci No Yerine 0 veya Negatif Sayi Giriniz:\n");
        scanf("%d",&no);
    }   // yukarida bir ogrenciye ait girilen verilerin yazdirilmasi islemi yapildi
    basariliErkek=erkekSay-basarisizErkek;
    basariliKiz=kizSay-basarisizKiz;
    if(basariliErkek!=0)
    BasariliErkekYuzdesi=(float)(basariliErkek*100)/erkekSay;
    else
    BasariliErkekYuzdesi=0;
    if(basariliKiz!=0)  // yanda gorulen kisimdaki gibi asagidaki diger yerlerde de 0'a bome hatasi kontrol edildi.
    basariliKizYuzdesi=(float)(basariliKiz*100)/kizSay;
    else
    basariliKizYuzdesi=0;
    if(ogrenciSay!=0)
    {
        okulBasariYuzdesi=(float)(basariliErkek+basariliKiz)*100/ogrenciSay;
        okulOrtalama=(float)(kizOrtalama+erkekOrtalama)/ogrenciSay;
    }
    else
    {
        okulBasariYuzdesi=0;
        okulOrtalama=0;
    }

    if(kizSay!=0)
    kizOrtalama=(float)kizOrtalama/kizSay;
    else
    kizOrtalama=0;
    if(erkekSay!=0)
    erkekOrtalama=(float)erkekOrtalama/erkekSay;
    else
    erkekOrtalama=0;
    if(dersTopla!=0)
    krediOrtalama=(float)toplamHesap/dersTopla;
    else
    dersTopla=0;
    if(ogrenciSay!=0)
    altmisYuzde=(float)altmisSay*100/ogrenciSay;
    else
    altmisYuzde=0;
    if(ogrenciSay!=0)
    notOtuzbesYuzde=(float)notOtuzbes*100/ogrenciSay;
    else
    notOtuzbesYuzde=0;
    if(ogrenciSay!=0)
    notSeksenbesYuzde=(float)notSeksenbes*100/ogrenciSay;
    else
    notSeksenbesYuzde=0;
    evYuzde=(float)evSay*100/(evSay+aileSay+yurtSay);
    aileYuzde=(float)aileSay*100/(evSay+aileSay+yurtSay);
    yurtYuzde=(float)yurtSay*100/(evSay+aileSay+yurtSay);
    // bu kisima kadar yukaridaki islemler asagidaki istatistiksel verilerin yazdirilmasi icin gerekli olan islemlerin yapildigi kisimlardir
    printf("\n\t\t------------------------------\n");
    printf("\t\t*****Istatistiksel Veriler****\n");  // istatistiksel veriler
    printf("\t\t------------------------------\n");
    printf("-------------------------------------------------------------\n");
    printf("Basarili Erkeklerin Yuzdesi:%.2f\n",BasariliErkekYuzdesi);
    printf("Basarili Kizlarin Yuzdesi:%.2f\n",basariliKizYuzdesi);
    printf("Okulun Geneli Icin Basari Yuzdesi:%.2f\n",okulBasariYuzdesi);
    printf("-------------------------------------------------------------\n");
    printf("Erkeklerin Agirlikli Not Ortalamasi:%.2f\n",erkekOrtalama);
    printf("Kizlarin Agirlikli Not Ortalamasi:%.2f\n",kizOrtalama);
    printf("Okulun Geneli Icin Agirlikli Not Ortalamasi:%.2f\n",okulOrtalama);
    printf("-------------------------------------------------------------\n");
    printf("Ogrencilerin Aldigi Kredilerin Ortalamasi:%.2f\n",krediOrtalama);
    printf("O Donem Aldigi Ders Sayisi 3 ve Altinda Olan Ogrencilerin Sayisi:%d\n",dersUcKucuk);
    printf("Hicbir Dersinin Notu 60'in Altinda Olmayan Ogrencilerin Yuzdesi:%.2f\n",altmisYuzde);
    printf("Hicbir Dersinin Notu 60'in Altinda Olmayan Ogrencilerin Sayisi:%d\n",altmisSay);
    printf("------------------------------------------------------------------------------\n");
    printf("O Donemki Agirlikli Not Ortalamasi 35'in Altinda Olan Ogrencilerin Sayilari:%d\n",notOtuzbes);
    printf("O Donemki Agirlikli Not Ortalamasi 35'in Altinda Olan Ogrencilerin Yuzdesi:%.2f\n",notOtuzbesYuzde);
    printf("O Donemki Agirlikli Not Ortalamasi 85'in Uzerinde Olan Ogrencilerin Sayilari:%d\n",notSeksenbes);
    printf("O Donemki Agirlikli Not Ortalamasi 85'in Uzerinde Olan Ogrencilerin Yuzdesi:%.2f\n",notSeksenbesYuzde);
    printf("Sonraki Donem Alacagi Burs Miktari 300 TL'den Fazla Olan Ogrencilerin Sayisi:%d\n",ucyuz);
    printf("-------------------------------------------------------------------------------\n");
    printf("Okul Birincisi Olan Ogrencinin Numarasi:%d\n",biriciNo);
    printf("Okul Birincisi Olan Ogrencinin Kredisi:%d\n",birinciKredi);
    printf("Okul Birincisi Olan Ogrencinin Agirlikli Not Ortalamasi:%.2f\n",birinciNoOrtalama);
    printf("Okul Birincisi Olan Ogrencinin Aldigildigi Aylik burs:%.2f\n",birinciUcret);
    printf("-------------------------------------------------------------\n");
    printf("En Cok Burs Alan Ogrencinin Numarasi:%d\n",enCokNo);
    printf("En Cok Burs Alan Ogrencinin Kredisi:%d\n",enCokKredi);
    printf("En Cok Burs Alan Ogrencinin Agirlikli Not Ortalamasi:%.2f\n",enCokOrtalama);
    printf("En Cok Burs Alan Ogrencinin Aldigi Aylik Burs:%.2f\n",enCokUcret);
    printf("----------------------------------------------------------\n");
    printf("Ogrencilere Sonraki Donem Her Ay Odenecek Toplam Burs Miktari:%.2f\n",ayUcret);

    if(basariliErkek !=0 || basariliKiz!=0){   //basarili ogrencilerin yuzdesinin en dusuk olanin belirlendigi kosullar
    if(evYuzde<aileYuzde && evYuzde<yurtYuzde && evYuzde!=0)
        printf("BASARILI Ogrencilerin Yuzdesinin En Dusuk Oldugu Ikamet Yeri :EV'dir\n");
    else if(aileYuzde<evYuzde && aileYuzde<yurtYuzde && aileYuzde!=0)
        printf("BASARILI Ogrencilerin Yuzdesinin En Dusuk Oldugu Ikamet Yeri :AILE'dir\n");
    else if(yurtYuzde!=0)
        printf("BASARILI Ogrencilerin Yuzdesinin En Dusuk Oldugu Ikamet Yeri :YURT'tur\n");
    }
    else if(basariliErkek==0 && basariliKiz==0)  // hic basarili ogrenci olmama durumu
        printf("Basarili Ogrencilere Ait Ikamet Yeri Bulunmamaktadir...\n");
    printf("------------------------------------------------------------------\n");
    }
    return 0;  //programin sonlandirilmasi
}







