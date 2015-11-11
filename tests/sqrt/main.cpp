#include<iostream>
#include<cmath>
using namespace std;

double sqrt_binsearch(double);
double sqrt_newton(double);

const double error = 1e-12;

int main(){
	cout<<"newton method"<<endl;
	sqrt_newton(2);
	sqrt_newton(8);
	sqrt_newton(1024);
	sqrt_newton(1027);
	sqrt_newton(1111111);
	cout<<"binary search"<<endl;
	sqrt_binsearch(2);
	sqrt_binsearch(8);
	sqrt_binsearch(1024);
	sqrt_binsearch(1027);
	sqrt_binsearch(1111111);
	return 0;
}

double sqrt_binsearch(double input){
	double left = 0, right = input, result;
	int iterations = 0;
	while (true){
		iterations ++;
		result = (left + right) / 2;
		double sqr = result * result;
		if (fabs(sqr - input) < error) break;
		if (sqr < input) left = result;
		else right = result;
	}
	
	cout<<iterations<<" iterations, sqrt("<<input<<") = "<<result<<", error = "<<error<<endl;
	cout.flush();
	return result;
}

double sqrt_newton(double input){
	// f(x) = x^2 - input
	// let f(x) = 0, then x is sqrt(input)
	// f'(x) = 2x
	// x(n+1) = x(n) - f(n)/f'(n)
	double result = input;
	int iterations = 0;
	while (true){
		iterations ++;
		double sqr = result * result;
		if (fabs(sqr - input) < error) break;
		result = result - (result * result - input) / (result * 2);		
	}
	
	cout<<iterations<<" iterations, sqrt("<<input<<") = "<<result<<", error = "<<error<<endl;
	return result;
}