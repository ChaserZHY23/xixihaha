#define _CRT_SECURE_NO_WARNINGS 1
class UnusualAdd {
public:
	int addAB(int A, int B) {
		// write code here
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
	}
};