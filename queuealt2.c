#include <stdio.h>
#include "queuealt2.h"
#include "boolean.h"


void CreateQueue(Queue *q){
/* I.S. sembarang */
/* F.S. Sebuah q kosong terbentuk dengan kondisi sbb: */ 
/* - Index head bernilai IDX_UNDEF */
/* - Index tail bernilai IDX_UNDEF */
/* Proses : Melakukan alokasi, membuat sebuah q kosong */   
    (*q).idxHead = IDX_UNDEF;
    (*q).idxTail = IDX_UNDEF;
}
/* ********* Prototype ********* */
boolean isEmpty(Queue q){
/* Mengirim true jika q kosong: lihat definisi di atas */
    return (q.idxHead == IDX_UNDEF && q.idxTail == IDX_UNDEF);
}
boolean isFull(Queue q){
/* Mengirim true jika tabel penampung elemen q sudah penuh */
/* yaitu ketika IDX_HEAD=0 dan IDX_TAIL=CAPACITY-1 */
    return (length(q) == CAPACITY);
}

int length(Queue q){
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika q kosong. */
    if (isEmpty(q)) return 0;
    else return q.idxTail - q.idxHead + 1;
}

/* *** Primitif Add/Delete *** */
void enqueue(Queue *q, ElType val) {
    if (isEmpty(*q)) {
        (*q).idxHead = 0;
        (*q).idxTail = 0;
    } else {
        // Jika ada ruang, tambah data ke tail
        if ((*q).idxTail == CAPACITY - 1) {
            for (int i = (*q).idxHead; i <= (*q).idxTail; i++) {
                (*q).buffer[i - (*q).idxHead] = (*q).buffer[i];
            }
            (*q).idxTail -= (*q).idxHead;
            (*q).idxHead = 0;
        }
        (*q).idxTail += 1;
    }
    (*q).buffer[(*q).idxTail] = val;
}


void dequeue(Queue *q, ElType *val){
/* Proses: Menghapus val pada q dengan aturan FIFO */
/* I.S. q tidak mungkin kosong */
/* F.S. val = nilai elemen HEAD pd I.S., IDX_HEAD "mundur";
        q mungkin kosong */
    *val = (*q).buffer[(*q).idxHead];
    if ((*q).idxHead == (*q).idxTail){
        (*q).idxHead = IDX_UNDEF;
        (*q).idxTail = IDX_UNDEF;
    }
    (*q).idxHead += 1;
}    

/* *** Display Queue *** */
void displayQueue(Queue q){
/* Proses : Menuliskan isi Queue dengan traversal, Queue ditulis di antara kurung 
   siku; antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan 
   karakter di depan, di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. q boleh kosong */
/* F.S. Jika q tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika Queue kosong : menulis [] */
    printf("[");
    if (!isEmpty(q)) {
        for (int i = q.idxHead; i <= q.idxTail; i++) {
            printf("%d", q.buffer[i]);
            if (i < q.idxTail) {
                printf(",");
            }
        }
    }
    printf("]\n");
}

int main(){
    Queue q ;
    CreateQueue(&q);

    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);
    enqueue(&q, 4);
    enqueue(&q, 5);

    
    enqueue(&q,100);
    displayQueue(q);
    

    ElType removal;
    dequeue(&q,&removal);
    printf("headnya: %d\n", removal);
    displayQueue(q);
    return 0;
}