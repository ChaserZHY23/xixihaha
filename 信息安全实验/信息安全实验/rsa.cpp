#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<math.h>
#include"ProRPN.h"
#include<cstdlib>
#include"ProRPN.h"
using namespace std;
int main(void) {
	unsigned __int64 *pa, *qa, *pb, *qb;
	pa = new(unsigned __int64);
	qa = new(unsigned __int64);
	pb = new(unsigned __int64);
	qb = new(unsigned __int64);
	*pa = *qa = *pb = *qb = 0;
	RSA A;
	RSA B;
	B.pute(41);
	productrpn(pa, qa, pb, qb);
	A.putp(pa);
	A.putq(qa);
	B.putp(pb);
	B.putq(qb);
	A.putpq();
	B.putpq();
	A.putd(rsa(A.getp(), A.getq(), A.gete()));
	B.putd(rsa(B.getp(), B.getq(), B.gete()));
	A.prits();
	A.pritsha();
	A.puts();
	ERSA(A.getd(), B.gete(), A.gets(), A.getsha(), A.getpq(), B.getpq());
	DRSA(A.gete(), B.getd(), A.getpq(), B.getpq());
	return 0;
}

