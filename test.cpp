#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <cassert>
using namespace std;
using std::ostringstream;

int Add()
{
	cout << "enter two numbers" << endl;

	int v1 = 0, v2 = 0;
	cin >> v1 >> v2;
	cout << "the sum of" << v1 << "and" << v2
		<< "is" << v1 + v2 << endl;
	return 0;
}

int Unsigned()
{
	unsigned u = 10, u2 = 42;
	cout << u2 - u << endl;
	cout << u - u2 << endl;

	int i = 10, i1 = 42;
	cout << i - i1 << endl;
	cout << i1 - i << endl;

	u = 42;
	i = 10;
	cout << i - u << endl;
	cout << u - i << endl;

	u = 10;
	i = -42;
	cout << i + i << endl;
	cout << u + i << endl;

// 	u = 10;
// 	cout << "hehe" << endl;
// 	while (u >= 0)
// 	{
// 		cout << u << endl;
// 		u--;
// 	}
	return 0;
}

int reused = 42;

int Scope_Levels()
{
	int unique = 0;
	
	cout << reused << "" << unique << endl;
	int reused = 0;
	cout << reused << "" << unique << endl;
	cout << ::reused << "" << unique << endl;
	return 0;
}

int ReferenceTest()
{
	int i = 0, &ri = i;

	cout << i << " " << ri << endl;
	i = 4;
	cout << i << " " << ri << endl;

	ri = 10;
	cout << i << "  " << ri << endl;
	
	return 0;
}

int CompoundRef()
{
	int i = 1024, *p = &i, &r = i;
	cout << i << " " << *p << " " << r << endl;

	int j = 42, *p2 = &j;
	int *&pref = p2;
	cout << *pref << endl;

	pref = &i;
	cout << *pref << endl;

	*pref = 0;
	cout << i << " " << *pref << " " << *p2 << endl;

	return 0;
}

// int Convs()
// {
// 	int i = 42;
// 	cout << i << endl;
// 
// 	if (i)
// 		i = 0;
// 	cout << i << endl;
// 
// 	bool b = 42;
// 	cout << b << endl;
// 
// 	int j = b;
// 	cout << j << endl;
// 
// 	double pi = 3.14;
// 	cout << pi << endl;
// 
// 	j = pi;
// 	cout << j << endl;
// 
// 	unsigned char c = -1;
// 	i = c;
// 	cout << i << endl;
// 	
// 	return 0;
// }

int TestDoublePtr()
{
	int ival = 1024;
	int* pi = &ival;
	int** ppi = &pi;

	cout << ival << "   " << *pi << "    " << **ppi << endl;

	int i = 2;
	int* p1 = &i;

	*p1 = *p1 * *p1;
	cout << "i = " << i << endl;

	*p1 *= *p1;
	cout << "i = " << i << endl;
	return 0;
}

int TestDecltype()
{
	int a = 0;
	decltype(a) c = a;
	decltype((a)) d = a;

	c++;
	cout << "a" << a << "c" << c << "d" << d << endl;

	d++;
	cout << "a" << a << "c" << c << "d" << d << endl;

	int A = 0, B = 0;
	decltype((A)) C = A;
	decltype(A = B) D = A;

	C++;
	cout << A << C << D << endl;
	D++;
	cout << A << C << D << endl;

	return 0;
}

int TestCctype()
{
	string s("Hello World!!!");
	// 	for (auto c : s)
	// 		cout << c << endl;

	string::size_type punct_cnt = 0;
	for (string::size_type c = 0; c != s.size(); c++)
		if (ispunct(s[c]))
			++punct_cnt;
	cout << punct_cnt << "        " << s << endl;

	string orig = s;
	for (string::size_type c = 0; c != s.size(); c++)
		s[c] = toupper(s[c]);
	cout << s << endl;

	s = orig;
	string::size_type index = 0;
	while (index != s.size() && !isspace(s[index]))
	{
		s[index] = toupper(s[index]);
		index++;
	}
	cout << s << endl;

	return 0;
}

int TestArrayScores()
{
	vector<unsigned> grades;
	const size_t sz = 11;
	unsigned scores[sz] = {};
	unsigned grade;

	while(cin >> grade)
	{
		if (grade <= 100)
			scores[grade / 10]++;
		grades.push_back(grade);
	}
	cout << "grades.size = " << grades.size() << endl;

	for (vector<unsigned>::const_iterator g = grades.begin(); g != grades.end(); g++)
		cout << *g << " ";
	cout << endl;

	for (size_t i = 0; i != sz; i++)
		cout << scores[i] << " ";
	cout << endl;
	return 0;

}

int TestGetline()
{
	string line;
	while (getline(cin, line))
		cout << line << endl;
	return 0;
}

int TestCstring()
{
	string s1 = "A string example";
	string s2 = "A different string";

	if (s1 < s2)
		cout << s1 << endl;
	else
		cout << s2 << endl;

	const char ca1[] = "A string example";
	const char ca2[] = "A string example";

	if (strcmp(ca1, ca2) < 0)
		cout << ca1 << endl;
	else
		cout << ca2 << endl;

	const char *cp1 = ca1, *cp2 = ca2;
	cout << strcmp(cp1, cp2) << endl;
	cout << strcmp(cp2, cp1) << endl;
	cout << strcmp(cp1, cp1) << endl;

	cout << strlen(cp1) << endl;

	const unsigned sz = 16 + 18 + 2;
	//char largeStr[sz];
	//pass
	return 0;
}

int TestIterator()
{
	string str("some string"), orig = str;
	if (!str.empty())
		cout << str[0] << endl;
	if (!str.empty())
		str[0] = toupper(str[0]);
	cout << str << endl;

	str = orig;

	if (str.begin() != str.end()) 
	{
		string::iterator it = str.begin();
		*it = toupper(*it);
	}
	cout << str << endl;

	str = orig;
	for (string::size_type index = 0; index != str.size() && !isspace(str[index]); index++)
		str[index] = toupper(str[index]);
	cout << str << endl;

	str = orig;
	for (string::iterator it = str.begin(); it != str.end() && !isspace(*it); it++)
		*it = toupper(*it);
	cout << str << endl;

	str = orig;
	string::size_type index = 0;
	while (index != str.size() && !isspace(str[index]))
	{
		str[index] = toupper(str[index]);
		index++;
	}
	cout << str << endl;

	string::iterator beg = str.begin();
	while (beg != str.end() && !isspace(*beg))
	{
		*beg = toupper(*beg);
		beg++;
	}
	cout << str << endl;

	str = orig;
	for (string::const_iterator c = str.begin(); c != str.end(); c++)
		cout << *c;
	cout << endl;
	for (string::iterator c = str.begin(); c != str.end(); c++)
		*c = '*';
	cout << str << endl;

	str = orig;
	for (string::size_type ix = 0; ix != str.size(); ix++)
		cout << str[ix];
	for (string::size_type ix = 0; ix != str.size(); ++ix)
		str[ix] = '*'; 
	cout << str << endl;

	return 0;

}

int arr[10];
int *p1[10];
int(*p2)[10] = &arr;

typedef int arrT[10];

arrT* func(int i);
int(*func(int i))[10];

int odd[] = { 1, 3, 5, 7, 9 };
int even[] = { 0, 2, 4, 6, 8 };

int* elemPtr(int i)
{
	return (i % 2) ? odd : even;
}

int(*arrPtr(int i))[5]	
{
	return (i % 2) ? &odd : &even;
}

int (&arrRef(int i))[5]
{
	return (i % 2) ? odd : even;
}

int TestBefore1()
{
	int* p = elemPtr(6);
	int(*arrP)[5] = arrPtr(5);
	int(&arrR)[5] = arrRef(4);

	for (size_t i = 0; i < 5; i++)
		cout << p[i];
	cout << endl;
	for (size_t i = 0; i < 5; i++)
		cout << (*arrP)[i];
	cout << endl;
	for (size_t i = 0; i < 5; i++)
		cout << arrR[i];
	return 0;
}

// struct ErrCode 
// {
// 	ErrCode(int i) : num(i) {}
// 	string msg()
// 	{
// 		ostringstream s;
// 		s << "ErrCode" << num;
// 		return s.str();
// 	}
// 	int num;
// };

string::size_type sumLength(const string&, const string&);
string::size_type latgerLength(const string&, const string&);

string::size_type sumLength(const string& s1, const string& s2)
{
	return s1.size() + s2.size();
}

string::size_type largerLength(const string& s1, const string& s2)
{
	return (s1.size() > s2.size()) ? s1.size() : s2.size();
}

string::size_type(*getFcn(const string& fetch))(const string&, const string&)
{
	if (fetch == "sum")
		return sumLength;
	return largerLength;
}

int TestBefore2()
{
	cout << getFcn("sum")("hello", "world") << endl;
	cout << getFcn("larger")("hello", "world") << endl;
	return 0;
}

inline const string&
shorterString(const string& s1, const string& s2)
{
	return s1.size() <= s2.size() ? s1 : s2;
}

int TestBefore3()
{
	string s1("successes"), s2("failure");
	cout << shorterString(s1, s2) << endl;
	cout << shorterString(s1, s2).size() << endl;
	cout << (s1.size() < s2.size() ? s1 : s2) << endl;
	return 0;
}

void print(const int ia[], size_t size)
{
#ifndef NDEBUG
	cerr << "print(int *, size_t)" << "  " << size << endl;
#endif
}

int TestErrorDeal()
{
	string word = "foo";
	const string::size_type threshold = 5;
	if (word.size() < threshold)
		cerr << "Error: " << __FILE__
		<< " : in function " << TestErrorDeal
		<< " at line " << __LINE__ << endl
		<< "       Compiled on " << __DATE__
		<< " at " << __TIME__ << endl
		<< "       Word read was \"" << word
		<< "\":  Length too short" << endl;
	word = "something longer than five chars";
	assert(word.size() > threshold);

	return 0;
}







