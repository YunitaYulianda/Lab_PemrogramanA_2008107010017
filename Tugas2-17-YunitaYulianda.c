#include<stdio.h>

int main(){
    int no_pilih, jmlh_barang, totalbelanja=0, sum,uang,i,kembalian,uang_kurang, uang_tambah;
    char jawaban;
    
    typedef struct Barang{
    int no_pilih;
    int harga_barang;
    char *nama_barang;
    }Skincare;

  Skincare Barang [5];

  Barang[0].no_pilih= 1;
  Barang[0].nama_barang= "Serum wajah";
  Barang[0].harga_barang= 55000;

  Barang[1].no_pilih= 2;
  Barang[1].nama_barang= "Body Lotion";
  Barang[1].harga_barang= 65000;

  Barang[2].no_pilih= 3;
  Barang[2].nama_barang= "Lipstik";
  Barang[2].harga_barang= 44000;

  Barang[3].no_pilih= 4;
  Barang[3].nama_barang= "Eyeliner";
  Barang[3].harga_barang= 32000;

  Barang[4].no_pilih= 5;
  Barang[4].nama_barang= "Pensil Alis";
  Barang[4].harga_barang= 25000;

  Barang[5].no_pilih= 6;
  Barang[5].nama_barang= "Maskara";
  Barang[5].harga_barang= 30000;

    printf("\n");
    printf("\t+===========================================================+\n");
    printf("\t|                      YunitaSkincare                       |\n");
    printf("\t+===========================================================+\n\n");

    printf("                  \t  Welcome to YunitaSkincare\n");
    printf("                \tDunia Kecantikan Untuk Wanita\n\n");
    
    do{
    printf("\t1.Daftar barang\n");
    printf("\t2.Belanja\n");
    printf("\t3.Keluar\n\n");

    printf("\tMasukkan pilihan anda : "); 
    scanf("%d", &no_pilih);
    while(no_pilih<1 || no_pilih>3){
      printf("\t\t\tMaaf pilihan anda tidak sesuai\n");
      printf("\t\t\tMasukkan pilihan anda : "); 
	 scanf("%d", &no_pilih);
    }

    if(no_pilih==1){
      printf("\t\t+------------------------------------------+\n");
      printf("\t\t| No  |   Nama barang    |      Harga      |\n");
      printf("\t\t+------------------------------------------+\n");
      printf("\t\t|  1  | Serum wajah      |      55000      |\n");
      printf("\t\t|  2  | Body Lotion      |      65000      |\n");
      printf("\t\t|  3  | Lipstik          |      44000      |\n");
      printf("\t\t|  4  | Eyeliner         |      32000      |\n");
      printf("\t\t|  5  | Pensil Alis      |      25000      |\n");
      printf("\t\t|  6  | Maskara          |      30000      |\n");
      printf("\t\t+------------------------------------------+\n");
      printf("\t\tTekan enter untuk pilihan selanjutnya...");
      getchar();
      printf("\n");
      }
      
    if(no_pilih == 2){
     do{
     printf("\n\tInput nomor barang yang akan dibeli : ");
     scanf("%d", &i);
     while(i<1 || i>6){ //mengulang jika nomor novel yang diinput bukan 1-6
          printf("\tMaaf input anda tidak sesuai !\n"); 
          printf("\tMasukkan pilihan anda : ");
          scanf("%d", &i);
          }
          printf("\n\tMasukkan jumlah barang yang diinginkan : ");
     	scanf("%d", &jmlh_barang);
          sum = jmlh_barang*Barang[i-1].harga_barang;
          totalbelanja=totalbelanja+sum;
          printf("\n");
          
          printf("\n\tApakah anda ingin belanja lagi (y/t) : ");
               scanf(" %c", &jawaban);
               while(jawaban != 'y' && jawaban != 't'){ //mengulang ketika karakter yang diinput bukan y atau n
                  printf("\tMaaf input anda tidak sesuai !\n");
                  printf("\tApakah anda ingin belanja lagi (y/t) : ");
                  scanf(" %c", &jawaban);
                  sum=jmlh_barang*Barang[i-1].harga_barang;
                  totalbelanja=totalbelanja+sum;
               }
               printf("\n");
     }while(jawaban=='y');
             
	printf("\tTotal belanja           : Rp. %d\n", totalbelanja);
     printf("\tMasukkan uang anda      : Rp. ");
     scanf("%d",&uang);
     belanja(totalbelanja, uang, kembalian, uang_kurang, uang_tambah);
     break;
          
  }if(no_pilih==3){
     break;
     }
     
     }while(getchar());
     
     printf("                  \t  Terima Kasih :)\n");
     printf("                \tMari Cantik Bersama *,*\n\n");
     
     return 0;
}

//perhitungan uang belanjaan   
int belanja(int totalbelanja, int uang, int kembalian, int uang_kurang, int uang_tambah){
    if(uang>=totalbelanja){ 
        kembalian=uang-totalbelanja;
        printf("\tKembalian anda          : Rp. %d\n\n\n", kembalian);
    }if(uang<totalbelanja){ // ketika uang kurang dari nilai total belanja
        printf("\n");
        uang_kurang=totalbelanja-uang;
        printf("\tUang anda kurang        : Rp. %d\n",uang_kurang);
        printf("\tMasukkan uang tambahan  : Rp. ");
        scanf("%d",&uang_tambah);
        kembalian=uang_tambah-uang_kurang;
        printf("\tKembalian anda          : Rp. %d\n\n\n", kembalian);
    }
    return kembalian;
} 

