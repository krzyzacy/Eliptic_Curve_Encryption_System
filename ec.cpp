#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <gmpxx.h>
#include <utility>
#include "ec_ops.h"
using namespace std;

Zp Zp::inverse() const{
	cout << "inverse" << endl;

	Zp tmp;
	tmp.setValue(getValue());

	
	// Implement the Extended Euclidean Algorithm to return the inverse mod PRIME		
}


ECpoint ECpoint::operator + (const ECpoint &a) const {
	cout << "op add" << endl;
	// Implement  elliptic curve addition 		
}


ECpoint ECpoint::repeatSum(ECpoint p, mpz_class v) const {
	cout << "repeat sum" << endl;
	cout << "initial x = " << p.x << " and y = " << p.y << endl;

	ECpoint ret;
		
	ret.x = p.x;
	ret.y = p.y;

	return ret;
	//Implement repeated squaring (with + rather than *) to find the sum of p+p+...+p (vtimes)
	//It is similar to the recursive exponential algorithm discussed for RSA		
}

Zp ECsystem::power(Zp val, mpz_class pow) {
	cout << "power" << endl;
	//Implement repeated squaring (*) to find the sum of val*val+...+val (pow times)
	//It is similar to the repeat sum above or recursive exponential algorithm discussed for RSA
	//It is the power function that is required to compute the square root in decryption algorithm
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


pair<mpz_class, Zp> ECsystem::encrypt(ECpoint publicKey, mpz_class privateKey,Zp plaintext){
	// You must implement elliptic curve encryption
	//  Do not generate a random key. Use the private key that is passed from the main function
}


Zp ECsystem::decrypt(pair<mpz_class, Zp> ciphertext){
	// Implement EC Decryption
}


/*
 * main: Compute a pair of public key and private key
 *       Generate plaintext (m1, m2)
 *       Encrypt plaintext using elliptic curve encryption
 *       Decrypt ciphertext using elliptic curve decryption
 *       Should get the original plaintext
 *       Don't change anything in main.  We will use this to 
 *       evaluate the correctness of your program.
 */

/*
Sample outputs when I increment the default value of sender's private key by 0 and 10 (i.e., incrementVal = 0 or 10).


Public key is: (255327928637822452671873704925306707585883356606885118757,1178994775650364079714920946269118201013822806360569629545)
Enter offset value for sender's private key
0
Encrypted ciphertext is: (9247497218780836794879316060361233346975398346664066655991, 4543832438888944923552833060316220869572984002670167722866)
Original plaintext is: 13144236608967899886525283787315573770527831478534
Decrypted plaintext: 13144236608967899886525283787315573770527831478534
Correct!

Public key is: (255327928637822452671873704925306707585883356606885118757,1178994775650364079714920946269118201013822806360569629545)
Enter offset value for sender's private key
10
Encrypted ciphertext is: (1193511452837154558346198495501062413165085465361676812503, 5128694964446153190876111107899960761864546024068218061320)
Original plaintext is: 13144236608967899886525283787315573770527831478534
Decrypted plaintext: 13144236608967899886525283787315573770527831478534
Correct!


For grading I will set the incremental value to some other value.
*/
int main(void){
	cout << "start" << endl;
	srand(time(0));
	ECsystem ec;
	mpz_class incrementVal;	
	
	Zp tmp(10);
	cout << tmp << endl;
	/*pair <ECpoint, mpz_class> keys = ec.generateKeys();
	
	
	Zp plaintext = MESSAGE;
	ECpoint publicKey = keys.first;
	cout<<"Public key is: "<< publicKey <<"\n";
	
	cout<<"Enter offset value for sender's private key"<<endl;
	cin>>incrementVal;
	mpz_class privateKey = XB + incrementVal;
	
	pair<mpz_class, Zp> ciphertext = ec.encrypt(publicKey, privateKey, plaintext);	
	cout<<"Encrypted ciphertext is: ("<<ciphertext.first<<", "<<ciphertext.second<<")\n";
	Zp plaintext1 = ec.decrypt(ciphertext);
	
	cout << "Original plaintext is: " << plaintext << endl;
	cout << "Decrypted plaintext: " << plaintext1 << endl;


	if(plaintext == plaintext1)
		cout << "Correct!" << endl;
	else
		cout << "Plaintext different from original plaintext." << endl;	
			
	return 1;
	*/
}


