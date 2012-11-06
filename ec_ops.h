#ifndef ZP_H
#define ZP_H

#include <iostream>
#include <utility>
#include <gmpxx.h>
using namespace std;


/*
 * Parameters for EC and transform into constants
 */

#define PRIME_STR "6277101735386680763835789423207666416083908700390324961279"
#define ORDER_STR "6277101735386680763835789423176059013767194773182842284081"
#define A_STR  "-3"
#define B_STR  "64210519 e59c80e7 0fa7e9ab 72243049 feb8deec c146b9b1"
#define GX_STR "188da80e b03090f6 7cbf20eb 43a18800 f4ff0afd 82ff1012"
#define GY_STR "07192b95 ffc8da78 631011ed 6b24cdd5 73f977a1 1e794811"
#define MESSAGE_STR "13144236608967899886525283787315573770527831478534"
#define XA_STR "865252837873155737705278314785349179279"  //private Key of receiver
#define XB_STR "31442366089678998865252837873155737705278314785349" //private key of sender

/*
#define PRIME_STR "11"
#define ORDER_STR "13"
#define A_STR  "1"
#define B_STR  "6"
#define GX_STR "2"
#define GY_STR "7"
*/


const mpz_class PRIME(PRIME_STR);
const mpz_class ORDER(ORDER_STR);
const mpz_class A(A_STR);
const mpz_class B(B_STR, 16);
const mpz_class GX(GX_STR, 16);
const mpz_class GY(GY_STR, 16);
const mpz_class MESSAGE(MESSAGE_STR);
const mpz_class XA(XA_STR); //private key of receiver
const mpz_class XB(XB_STR); //private key of sender

/*
 * class Zp: An element in GF(p)
 */
class Zp{

	// Overloading cout
	friend ostream& operator<<(ostream& output, const Zp& a);

	private:
	mpz_class value;
	
	public:
	Zp(){}
	Zp(const mpz_class v){ value = v; value %= PRIME; }
	Zp(const int v){ value = v; value %= PRIME; }
	void setValue(const mpz_class v){ 
		if (v < 0) {
			value = PRIME + v;
		}
		else {
			value = v;
		}
	}
	mpz_class getValue() const { return value; }

	Zp operator + (const Zp &a) const;
	Zp operator - (const Zp &a) const;
	Zp operator * (const Zp &a) const;
	bool operator == (const Zp &a) const;
	Zp inverse() const;
};


/* 
 * class ECpoint: A point on an elliptic curve
 */
class ECpoint{

	// Overloading cout
	friend ostream& operator<<(ostream& output, const ECpoint& a);

	public:
	Zp x;
	Zp y;
	bool infinityPoint; //If true, the point is the infinity point

	ECpoint(){
		infinityPoint = false;}
	ECpoint(Zp xx, Zp yy){ x = xx; y =  yy; infinityPoint = false;}
	ECpoint(bool inf){ infinityPoint = inf;}

	ECpoint repeatSum(ECpoint p, mpz_class v) const;
	bool operator == (const ECpoint &a) const;
	ECpoint operator + (const ECpoint &a) const;
	ECpoint operator * (const mpz_class &a) const;
};


/*
 * class ECsystem: Encryption and decryption functions of ec
 */
class ECsystem{
	private:
		mpz_class privateKey;
		ECpoint publicKey;
		ECpoint G; //Generator G
		Zp power(Zp base, mpz_class pow);
		mpz_class pointCompress(ECpoint e);
		ECpoint pointDecompress(mpz_class compressedPoint);
	public:

		ECsystem(){ G = ECpoint(GX, GY);}
		ECpoint getPublicKey(){ return publicKey;}
		
		pair <ECpoint, mpz_class> generateKeys();		

		
		pair<mpz_class, Zp> encrypt(ECpoint publicKey, mpz_class privateKey, Zp plaintext);
		Zp decrypt(pair<mpz_class, Zp> cm);
};

#endif

