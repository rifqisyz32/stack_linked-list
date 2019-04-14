#include <iostream>
#define MAX_STACK 10
using namespace std;

struct TNode {
	int data;
	TNode *next; };

TNode *head;

void init() 
{ head = NULL; }

bool isEmpty() {
	return head == NULL; }

bool isFull() {
	if (isEmpty() == 1) {
		return 0; }
		
	else {
		TNode *bantu;
		int l=0;
		bantu = head;
		while (bantu != NULL) {
			l++;
			bantu = bantu->next; }
		return l > MAX_STACK-1; } }

class ModifikasiStack {
    public:
    
    int getTop() {
    	return head->data; }
    	
    void push(int databaru) {
		TNode *baru;
		baru = new TNode;
		baru->data = databaru;
		baru->next = NULL;
		
		if (isEmpty() == 1) {
			baru->next = head;
			head = baru; }
		else {
			baru->next = head;
			head=baru; }
			
		cout<<"Nilai "<<getTop()<<" masuk\n"; }
		
    void pop() {
    	TNode *hapus;
		int d;
		hapus = head;
		d = getTop();
		head = head->next;
		delete hapus;
		cout<<"\nNilai "<<d<<" dihapus\n"; } };

void OutputStack() {
    	TNode *bantu;
		bantu = head;
		int l = 0;
		
			while (bantu != NULL) {
				bantu = bantu->next;
				l++; }
				
			bantu = head;
			while (bantu != NULL) {
				cout<<bantu->data<<endl;
				bantu = bantu->next; } } 

int main() {
	int data;
    char ch, re;
    ModifikasiStack s;

    do {
      	system("cls");
      	cout<<"Stack dengan Linked-list \n\n";
      	OutputStack();
      	cout<<"\nMenu : \n1. Isi data\n2. Hapus data\n3. Keluar\n-----------------\n";
      	cin>>ch;

      	switch(ch) {
      		
      		case '1' :
      			if (isFull() == 0){
      				cout<<"\nMasukkan data : ";
            		cin>>data;
            		s.push(data); }
					else {
					cout<<"\nStack telah penuh\n"; }
				break;
				
      		case '2' :
      			if (isEmpty() == 0) {
				  	s.pop(); }
      			else {
      				cout<<"\nStack masih kosong\n"; }
            		break;
            		
      		case '3' :
      			exit(0);
            		break;
      		default :
            		cout<<"\nInput salah\n"; }
            		
      	cout<<"\nLagi? (y)\n>>";
      	cin>>re; }
			while (re=='y' || re=='Y'); 
			return 0; }
