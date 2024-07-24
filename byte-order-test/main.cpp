#include <stddef.h> // for size_t
#include <stdint.h> // for uint8_t
#include <stdio.h> // for printf

uint16_t my_ntohs(uint16_t n) {
	/*
	uint16_t ret_val;
	ret_val = n >> 8;  0x12
	ret_val |= (n & 0xff) << 8;
	return ret_val;
	*/
	return (n >> 8) | ((n & 0xff) << 8);
}

uint32_t my_ntohl(uint32_t n) {
	return ((n & 0xff000000) >> 8*3) | ((n & 0xff0000) >> 8) | ((n & 0xff00) << 8) | ((n & 0xff) << 8*3);
}

void dump(void* p, size_t n) {
	uint8_t* u8 = static_cast<uint8_t*>(p);
	size_t i = 0;
	while (true) {
		printf("%02X ", *u8++);
		if (++i >= n) break;
		if (i % 8 == 0)
			printf("\n");
	}
	printf("\n");
}

void write_4660() {
	uint16_t port = 4660; // 0x1234
	printf("port number = %d\n", port);
	dump(&port, sizeof(port));
}

void  write_0x1234() {
	uint8_t network_buffer[] = { 0x12, 0x34 };
	uint16_t* p = reinterpret_cast<uint16_t*>(network_buffer);
	uint16_t n = my_ntohs(*p); // TODO
	printf("16 bit number=0x%x\n", n);
}

void  write_0x12345678() {
	uint8_t network_buffer[] = { 0x12, 0x34, 0x56, 0x78 };
	uint32_t* p = reinterpret_cast<uint32_t*>(network_buffer);
	uint32_t n = my_ntohl(*p); // TODO
	printf("32 bit number=0x%x\n", n);
}

int main() {
	//write_4660();
	//write_0x1234();
	write_0x12345678();
}
