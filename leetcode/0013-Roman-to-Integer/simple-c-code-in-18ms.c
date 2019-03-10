/**
 * source:
 * https://leetcode.com/problems/roman-to-integer/discuss/6857/Simple-c-code-in-18ms
 */
int romanToInt(char* s) {
    int NUM[256] = { 0 };
	NUM['I'] = 1;
	NUM['V'] = 5;
	NUM['X'] = 10;
	NUM['L'] = 50;
	NUM['C'] = 100;
	NUM['D'] = 500;
	NUM['M'] = 1000;
	int val = 0;
	int prev = 0;
	int buf = 0;
	while(*s != '\0')
	{
		buf = NUM[*s]; // getNum(*s);
		if (prev && prev<buf)
		{
			val += buf - prev;
			prev = 0;
		}
		else if (prev && prev>=buf)
		{
			val += prev;
			prev = buf;
		}
		else
		{
			prev = buf;
		}
		s++;
	}

	return val + prev;
}
