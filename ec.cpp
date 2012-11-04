#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <gmpxx.h>
#include <utility>
#include "ec_ops.h"
using namespace std;

Zp Zp::inverse() const{
	// Implement the Extended Euclidean Algorithm to return the inverse mod PRIME
		
}


ECpoint ECpoint::operator + (const ECpoint &a) const {
	// Implement  elliptic curve addition 	
}


ECpoint ECpoint::repeatSum(ECpoint p, mpz_class v) const {
	//Implement repeated squaring (with + rather than *) to find the sum of p+p+...+p (vtimes)
	//It can be defined as the recursive exponential algorithm discussed for RSA	
}

Zp ECsystem::power(Zp val,mpz_class pow) {
	//Implement repeated squaring (*) to find the sum of val*val+...+val (pow times)
	//It is similar to the repeat sum above or recursive exponential algorithm discussed for RSA
	//It is the power function that is required to compute square root in decryption algorithm
}


mpz_class ECsystem::pointCompress(ECpoint e) {
	//It is the gamma function explained in the assignment.
	//Note: Here return type is mpz_class because the function may
	//map to a value greater than the defined PRIME number (i.e, range of Zp)
	//This function is fully defined.
	  
	mpz_class compressedPoint = e.x.getValue();
	compressedPoint = compressedPoint<<1;
	
	if(e.infinityPoint) {
		cout<<"Point cannot be compressed as its INF-POINT"<<flush;
		abort();
		}
	else {
		if (e.y.getValue()%2 == 1)
			compressedPoint = compressedPoint + 1;
		}
		//cout<<"For point  "<<e<<"  Compressed point is <<"<<compressedPoint<<"\n";
		return compressedPoint;

}

ECpoint ECsystem::pointDecompress(mpz_class compressedPoint){
	//Implement the delta function for decompressing the compressed point
}


pair<mpz_class, Zp> ECsystem::encrypt(ECpoint publicKey, Zp plaintext){
	// You must implement elliptic curve encryption
	// to get  started, generate a random key b
}


Zp ECsystem::decrypt(pair<mpz_class, Zp> ciphertext){
	// Implement EC Decryption
}


/*
 * main: Compute a pair of public key and private key
 *       Generate plaintext m
 *       Encrypt plaintext using elliptic curve encryption
 *       Decrypt ciphertext using elliptic curve decryption
 *       Should get the original plaintext
 *       Don't change anything in main.  We will use this to 
 *       evaluate the correctness of your program.
 */


int main(void){
	srand(time(0));
	ECsystem ec;	
	pair <ECpoint, mpz_class> keys = ec.generateKeys();
	
	ECpoint publicKey = keys.first;
	cout<<"Public key is: "<<publicKey<<"\n";

	Zp plaintext(rand());	
	pair<mpz_class, Zp> ciphertext = ec.encrypt(publicKey, plaintext);	
	cout<<"Encrypted ciphertext is: ("<<ciphertext.first<<", "<<ciphertext.second<<")\n";
	Zp plaintext1 = ec.decrypt(ciphertext);
	
	cout << "Original plaintext is: " << plaintext << endl;
	cout << "Decrypted plaintext: " << plaintext1 << endl;


	if(plaintext == plaintext1)
		cout << "Correct!" << endl;
	else
		cout << "Plaintext different from original plaintext." << endl;	
			
	return 1;

}


