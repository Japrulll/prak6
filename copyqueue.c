#include <stdio.h>
#include "queue.h"
#include "boolean.h"

void copyQueue(Queue *queueInput, Queue *queueOutput){
/* Proses: Menyalin isi dari queueInput ke queueOutput */
/* I.S. queueInput mungkin kosong, tabel penampung elemen queueInput TIDAK penuh */
/* F.S. queueOutput memiliki isi queue yang sama */
/*
    Contoh input:
    queueInput : [2,3,4,5,6] // 2 adalah head, 6 adalah tail
    queueOutput: queue kosong

    Contoh output:
    queueInput:  [2,3,4,5,6]
    queueOutput: [2,3,4,5,6]
*/

/*
    Catatan
    - Hati-hati jangan sampai algoritma Anda mengubah hasil akhir dari queueInput juga.
      Elemen di queueInput harus tetap sama setelah algoritma dijalankan.
    Hint
    - Buat queue baru selain queueInput dan queueOutput untuk tempat penyimpanan
      queueInput sementara.
*/
    CreateQueue(queueOutput);
    Queue saveQueue;
    CreateQueue(&saveQueue);

    while(!isEmpty(*queueInput)){
        ElType ceritanya_isi;
        dequeue(queueInput, &ceritanya_isi);
        enqueue(&saveQueue, ceritanya_isi);
        enqueue(queueOutput, ceritanya_isi);
    }
    while(!isEmpty(saveQueue)){
        ElType ceritanya_isi;
        dequeue(&saveQueue, &ceritanya_isi);
        enqueue(queueInput, ceritanya_isi);
    }
    
}