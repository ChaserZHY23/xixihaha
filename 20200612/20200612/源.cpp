#define _CRT_SECURE_NO_WARNINGS 1
int xor = 0;
int and = 0;
while (B != 0)
{
	xor = A^B;
	and = (A&B) << 1;
	A = xor;
	B = and;
}
return A;