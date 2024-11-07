#include <stdio.h>
#include "dividequeue.h"
#include "queuealt2.h"

void divideQueue(Queue *queue, Queue *oddQueue, Queue *evenQueue){
/* Proses: Membagi isi dari queue ke oddQueue untuk elemen ganjil dan evenQueue untuk elemen genap */
/* I.S. queue mungkin kosong, tabel penampung elemen queue TIDAK penuh */
/* F.S. oddQueue memiliki isi queue elemen ganjil, evenQueue memiliki isi queue elemen genap */
/*
Contoh input:
queue : [2,3,4,5,6] // 2 adalah head, 6 adalah tail
oddQueue: queue kosong
evenQueue: queue kosong

Contoh output:
queue:  [2,3,4,5,6]
oddQueue: [3,5]
evenQueue: [2,4,6]
*/

/*
Catatan
- Hati-hati jangan sampai algoritma Anda mengubah hasil akhir dari queueInput juga.
    Elemen di queueInput harus tetap sama setelah algoritma dijalankan.
Hint
- Buat queue baru selain queue, oddQueue, dan evenQueue untuk tempat penyimpanan
    queue sementara.
*/
    Queue saveq;
    CreateQueue(&saveq);

    while(!isEmpty(*queue)){
        ElType simpanan;
        dequeue(queue,&simpanan);
        if (simpanan % 2 != 0){
            enqueue(oddQueue,simpanan);
            printf("Masukkan ke oddQueue: %d\n", simpanan);  // Debug print

        }
        else {
            enqueue(evenQueue,simpanan);
            printf("Masukkan ke evenQueue: %d\n", simpanan);  // Debug print

        }
        enqueue(&saveq,simpanan);
        printf("masuk ke saveq: %d\n", simpanan);
    }
    while (!isEmpty(saveq))
    {
        ElType simpanan;
        dequeue(&saveq,&simpanan);
        enqueue(queue,simpanan);
        printf("masuk ke queue awal: %d", simpanan);
    }
    displayQueue(*queue);
    displayQueue(*oddQueue);
    displayQueue(*evenQueue);
}

int main(){
    Queue qcek ;
    CreateQueue(&qcek);
    Queue qodd ;
    CreateQueue(&qodd);
    Queue qeven ;
    CreateQueue(&qeven);

    enqueue(&qcek, 1);
    enqueue(&qcek, 2);
    enqueue(&qcek, 3);
    enqueue(&qcek, 4);
    enqueue(&qcek, 5);

    divideQueue(&qcek, &qodd, &qeven);
    return 0;
    
}