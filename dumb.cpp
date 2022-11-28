#include <stdio.h>
#include <bit>

/// requires use of C++20 for std::bit_cast


void PrintHelp()
{
	printf("dumb [numbers..] \nCheck if a number is a perfect power of two.\n");
}

inline bool Acceptible(const int& width)
{
	// firstly convert a provided number to a float
    float num = width;
	
#if __cplusplus == 202002L
	
	// "safely" interpret float's pointer as an integer and bitwise mask
	return (std::bit_cast<int>(num) & (8388607)) == 0;
	
#else
	//unsafe method for use in compiling prior to C++20 aka: "trust me bro"	
	return (*((int*)&num) & (8388607)) == 0;
	
#endif
}

int main(int argc, char** argv)
{	
	if (argc < 2)
	{
		PrintHelp();
		return 0;
	}
	
	unsigned long long num = 0,
		arg = 1, // first argument is always the full executable path, so skip
		cha = 0;
	
	while (arg < argc)
	{
		num = 0;
		cha = 0;
		while ((unsigned char)(argv[arg][cha] - 48) < 10)
				num = num * 10 + (argv[arg][cha++] - 48);		
		printf("%llu is %s\n", num, Acceptible(num)? "acceptible" : "unacceptable");
		arg++;
	}
	return 0;
}
