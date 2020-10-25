#include<stdio.h>
#include<string.h>
#define DATA_SEGMENT_SIZE 100000
char DS[DATA_SEGMENT_SIZE];
char * BP;
void init() {
	memset(DS,0,sizeof(DS));
	BP=DS;
}
void OUTPUT() {
	putchar(*BP);
}
void INPUT() {
	puts("Please input an ASCII character:");
	*BP=getchar();
	getchar();
}
void problem() {
	$$$BRAINFUCK2C_CONTENT$$$
}
int main() {
	init();
	problem();
}