#include "vector.h"
#include <string>
#include <sstream>
#include <cstdlib>

#include <iostream>
using std::cout;
using std::endl;

using std::string;
using std::stringstream;

Vector::Vector(int size):size(size){
	data = new double[size];
	if (!data){
		throw "Not Enough Memory";
	}
	cout << "Llamado a Constructor size = " << size << " data = " << data << endl;
}

Vector::Vector(const Vector& other):size(other.size){
	data = new double[size];
	if (!data){
		throw "Not Enough Memory";
	}
	for (int i=0; i<size; i++)
		data[i] = other.data[i];
	cout << "Llamando a Constructor de Copia size = " << size << " data = " << data << endl;
}
Vector::~Vector(){
	cout << "Llamado a Destructor size = " << size << " data = " << data << endl;
	if (data)
		delete[] data;
}
string Vector::toString()const{
	stringstream ss;
	ss << "[";
	for (int i=0; i<size; i++)
		if (i == size - 1)
			ss << data[i] << "]";
		else
			ss << data[i] << ", ";
	return ss.str();
}
const Vector Vector::suma(const Vector& r)const{
	if (size != r.size)
		throw "I would do anything for love, but I won\'t do that...";
	Vector retVal(size);
	for (int i=0; i<size; i++)
		retVal.data[i] = data[i] + r.data[i];
	return retVal;
	
}
const Vector& Vector::assign(const Vector& r){
	if (size != r.size){
		delete[] data;
		size = r.size;
		data = new double[size];
	}
	for (int i=0; i<size; i++)
		data[i] = r.data[i];
	return *this;
}
const Vector Vector::mult(double number)const{
	Vector retVal(size);
	for (int i=0; i<size; i++)
		retVal.data[i] = number * data[i];
	return retVal;
}
void Vector::set(double value, int index){
	if (index < 0 || index >= size)
		throw "Array Index Out Of Bounds Exception... seek help elsewhere";
	data[index] = value;
}
