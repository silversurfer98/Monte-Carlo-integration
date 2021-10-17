#pragma once
#include<iostream>
#include<fstream>

# define MAX_PRECISION_TRIG 7

template <typename t>
void print(const char* a, t x)
{
	std::cout << "\n the " << a << " : " << x << "\n\n";
}

// const needed to calculate ln(x)
static double
ln2_hi = 6.93147180369123816490e-01,	/* 3fe62e42 fee00000 */
ln2_lo = 1.90821492927058770002e-10,	/* 3dea39ef 35793c76 */
L1 = 6.666666666666735130e-01,  /* 3FE55555 55555593 */
L2 = 3.999999999940941908e-01,  /* 3FD99999 9997FA04 */
L3 = 2.857142874366239149e-01,  /* 3FD24924 94229359 */
L4 = 2.222219843214978396e-01,  /* 3FCC71C5 1D8E78AF */
L5 = 1.818357216161805012e-01,  /* 3FC74664 96CB03DE */
L6 = 1.531383769920937332e-01,  /* 3FC39A09 D078C69F */
L7 = 1.479819860511658591e-01;  /* 3FC2F112 DF3E5244 */


// const needed to find exp(x)
static double
one = 1.0,
half[2] = { 0.5,-0.5, },
ln2HI[2] = { 6.93147180369123816490e-01,  /* 0x3fe62e42, 0xfee00000 */
		 -6.93147180369123816490e-01, },/* 0xbfe62e42, 0xfee00000 */
ln2LO[2] = { 1.90821492927058770002e-10,  /* 0x3dea39ef, 0x35793c76 */
			-1.90821492927058770002e-10, },/* 0xbdea39ef, 0x35793c76 */
invln2 = 1.44269504088896338700e+00, /* 0x3ff71547, 0x652b82fe */
P1 = 1.66666666666666019037e-01, /* 0x3FC55555, 0x5555553E */
P2 = -2.77777777770155933842e-03, /* 0xBF66C16C, 0x16BEBD93 */
P3 = 6.61375632143793436117e-05, /* 0x3F11566A, 0xAF25DE2C */
P4 = -1.65339022054652515390e-06, /* 0xBEBBBD41, 0xC5D26BF1 */
P5 = 4.13813679705723846039e-08; /* 0x3E663769, 0x72BEA4D0 */

float mexp(float x);
float mln(float x);
float mysq(float base);

class trignometry
{
public:
    double invf[21] =
    {
        1.000000000000000E+00,
        1.000000000000000E+00,
        5.000000000000000E-01,
        1.666666666666670E-01,
        4.166666666666670E-02,
        8.333333333333330E-03,
        1.388888888888890E-03,
        1.984126984126980E-04,
        2.480158730158730E-05,
        2.755731922398590E-06,
        2.755731922398590E-07,
        2.505210838544170E-08,
        2.087675698786810E-09,
        1.605904383682160E-10,
        1.147074559772970E-11,
        7.647163731819820E-13,
        4.779477332387390E-14,
        2.811457254345520E-15,
        1.561920696858620E-16,
        8.220635246624330E-18,
        4.110317623312160E-19
    };
    int iter, pof1;
    char c;
    double PI_doub = 3.1415926535897932384650288;
    float p, s, PI = (float)PI_doub, sign;
    trignometry(int iterations, char choice);
    float mypower(float base, int exp);
    void rad2rad(float* rad);
    void deg2rad(float* deg);
    float sin(float x);
    float cos(float x);
};

float* gauss_random(size_t x, float a,float b, float sd, unsigned long long int seed);