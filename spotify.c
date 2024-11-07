#include <stdio.h>
#include "circular_queue.h"

int main(){
    // n: jumlah lagu
    // m: jumlah playlist

    /*
    `1`: Memutar lagu selanjutnya dari queue.
    `2`: Mengaktifkan/menonaktifkan fitur loop.
    `3 `: Menambahkan lagu ke queue berdasarkan ID-nya.
    `4 `: Menambahkan lagu dari playlist ke queue.
    `0`: Keluar dari program.

    - Saat memutar lagu: `Play lagu `
    - Saat queue kosong: `Tidak ada lagu`
    - Saat loop diaktifkan: `Looping lagu`
    - Saat loop dinonaktifkan: `Tidak looping lagu`
    - Saat queue penuh saat mencoba menambahkan lagu: `Queue penuh`
    */
   int n,m;
   scanf("%d %d", &n, &m);

   int arrSongs[m][3];
   for (int i = 0; i < m; i++){
    for (int j = 0; j < 3; j++){
        scanf("%d", &arrSongs[i][j]);
        if (arrSongs[i][j] < 0 || arrSongs[i][j] > n-1){
            printf("Playlist Tidak Valid");
            break;
        }
    
    }
   }

   Queue lagu_lagu;
   CreateQueue(&lagu_lagu);

   int mulai;
   boolean loop = false;

   while ((scanf("%d",&mulai)) && mulai != 0){
        if (mulai == 1){
            if (IsEmpty(lagu_lagu)){
                printf("Tidak ada lagu\n");
            }
            else {
                int ambil_lagu = dequeue(&lagu_lagu);
                printf("Play lagu %d\n", ambil_lagu );
                if (loop) {
                    enqueue(&lagu_lagu,ambil_lagu);
                }
            }
        }
        else if (mulai == 2){
            loop = !loop;

            if (loop) printf("Loopin Lagu");
            else printf("Tidak Loopin Lagu");
        }
        else if (mulai == 3){
            int id_lagu;
            scanf("%d", &id_lagu);
            if (IsFull(lagu_lagu)){
                printf("Queue Penuh");
            }
            else enqueue(&lagu_lagu, id_lagu);
        }
        else if (mulai == 4){
            int id_playlist;
            scanf("%d", &id_playlist);
            for (int k = 0; k < 3; k++){
                if (IsFull(lagu_lagu)){
                    printf("Queue Penuh\n");
                    break;
                }
                else enqueue(&lagu_lagu,arrSongs[id_playlist][k]);
            }
        }
   }
   return 0;




}