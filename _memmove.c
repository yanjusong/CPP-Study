#include <stdio.h>

void* _memmove(void *dest, const void *src, unsigned int size)
{
	if (!dest || !src)
		return (void *)0;
	
	char *pDest = (char *)dest;
	char *pSrc  = (char *)src;
	int d = 1;
	
	if (pDest > pSrc) {
		d = -1;
		pSrc  += size - 1;
		pDest += size - 1;
	}
	
	while (size--) {
	    *pDest = *pSrc;
		pDest += d;
		pSrc  += d;
	}
	
	return (void *)pDest;
}

int main()
{
	char buf[32] = "hello world";
	int i = 0;
	
	for (i = 0; i < 32; ++i)
		printf("%d ", buf[i]);
	printf("\n");
	
	_memmove(buf + 2, buf, 5);
	// _memmove(buf, buf + 2, 5);
	
	for (i = 0; i < 32; ++i)
		printf("%d ", buf[i]);
	printf("\n");
	
	return 0;
}