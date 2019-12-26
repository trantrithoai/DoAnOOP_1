#include <iostream>
#include <string>
using namespace std;

#include "MyString.h"

//Hàm trả về kí tự đầu của chuỗi.
char MyString::Begin()
{
	return _str[0];
}

//Hàm trả về kí tự cuối của chuỗi.
char MyString::End()
{
	return _str[Length() - 1];
}

//Hàm trả về kích thước chuỗi.
int MyString::Size()
{
	int dem = 0;

	for (int i = 0; _str[i] != '\0'; i++)
	{
		dem++;
	}
	return dem;
}

//Hàm trả về chiều dài chuỗi.
int MyString::Length()
{
	int dem = 0;

	for (int i = 0; _str[i] != '\0'; i++)
	{
		dem++;
	}
	return dem;
}

//Hàm cài đặt lại kích thước của chuỗi.
void MyString::Resize(const int x)
{
	if (x < 0)
		return;

	if (x == 0)
		Clear();

	if (x > Length())
		return;

	char* temp = new char[x + 1];

	for (int i = 0; i < x; i++)
	{
		temp[i] = _str[i];
	}
	temp[x] = '\0';

	delete[] _str;

	_str = new char[x + 1];

	for (int i = 0; i < x; i++)
	{
		_str[i] = temp[i];
	}
	_str[x] = '\0';

	delete[] temp;
}

//Hàm xóa chuỗi.
void MyString::Clear()
{
	_str[0] = '\0';
}

//Hàm trả về 1 nếu chuỗi trống và 0 nếu ngược lại.
int MyString::Empty()
{
	return (Length() == 0);
}

//Hàm lấy phần tử tại vị trí x.
char MyString::At(const int x)
{
	if (x > Length() - 1 or x < 0)
		return '\0';

	return _str[x];
}

//Hàm lấy phần tử đầu tiên chuỗi.
char MyString::Front()
{
	return _str[0];
}

//Hàm lấy phần tử cuối cùng chuỗi.
char MyString::Back()
{
	return _str[Length() - 1];
}

//Toán tử cộng chuỗi.
MyString operator+ (MyString a, MyString b)
{
	MyString out;

	int size = a.Length() + b.Length();

	out._str = new char[size + 1];

	for (int i = 0; i < a.Length(); i++)
	{
		out._str[i] = a._str[i];
	}

	for (int i = a.Length(); i < size; i++)
	{
		out._str[i] = b._str[i - a.Length()];
	}
	out._str[size] = '\0';

	return out;
}

//Hàm nối chuỗi.
void MyString::Append(const string x)
{
	int size = Length() + x.length();

	char* temp = new char[size + 1];

	for (int i = 0; i < Length(); i++)
	{
		temp[i] = _str[i];
	}

	for (int i = Length(); i < size; i++)
	{
		temp[i] = x[i - Length()];
	}
	temp[size] = '\0';

	delete[] _str;

	_str = new char[size + 1];

	for (int i = 0; i < size; i++)
	{
		_str[i] = temp[i];
	}
	_str[size] = '\0';

	delete[] temp;
}

//Hàm thêm kí tự vào cuối chuỗi.
void MyString::Push_Back(const char x)
{
	int size = Length();

	if (size == 0)
	{
		_str = new char(x);
		return;
	}

	char* temp = new char[size + 1];

	for (int i = 0; i < size; i++)
	{
		temp[i] = _str[i];
	}
	temp[size] = '\0';

	delete[] _str;

	size++;

	_str = new char[size + 1];

	for (int i = 0; i < size - 1; i++)
	{
		_str[i] = temp[i];
	}
	_str[size - 1] = x;
	_str[size] = '\0';

	delete[] temp;
}

//Hàm thêm vào chuỗi tại vị trí x.
void MyString::Insert(string s, const int x)
{
	if (x > Length())
		return;

	if (x == Length())
	{
		Append(s);
		return;
	}

	if (x < 0)
		return;

	if (s == "")
		return;

	int size = Length() + s.length();

	char* temp = new char[size + 1];

	for (int i = 0; i < x; i++)
	{
		temp[i] = _str[i];
	}

	for (int i = 0; i < s.length(); i++)
	{
		temp[i + x] = s[i];
	}

	for (int i = x + s.length(); i < size; i++)
	{
		temp[i] = _str[i - s.length()];
	}
	temp[size] = '\0';

	delete[] _str;

	_str = new char[size];

	for (int i = 0; i < size; i++)
	{
		_str[i] = temp[i];
	}
	_str[size] = '\0';

	delete[] temp;
}

//Hàm xóa phần tử của chuỗi tại vị trí x.
void MyString::Erase(const int x)
{
	if (x >= Length() or x < 0)
		return;

	int size = Length() - 1;

	char* temp = new char[size + 1];

	for (int i = 0; i < x; i++)
	{
		temp[i] = _str[i];
	}

	for (int i = x; i < size; i++)
	{
		temp[i] = _str[i + 1];
	}
	temp[size] = '\0';

	delete[] _str;

	_str = new char[size + 1];

	for (int i = 0; i < size; i++)
	{
		_str[i] = temp[i];
	}
	_str[size] = '\0';

	delete[] temp;
}

//Hàm thay thế chuỗi x vào chuỗi hiện tại từ vị trí s đến e.
void MyString::Replace(const int s, const int e, const string x)
{
	if (s >= Length() or e >= Length() or s >= e)
		return;

	for (int i = 0; i <= e - s; i++)
	{
		Erase(s);
	}

	Insert(x, s);
}

//Hàm đảo ngược chuỗi.
void MyString::Swap()
{
	for (int i = 0; i < Length() / 2; i++)
	{
		char temp = _str[i];
		_str[i] = _str[Length() - 1 - i];
		_str[Length() - 1 - i] = temp;
	}
}

//Hàm xóa phần tử cuối của chuỗi.
void MyString::Pop_Back()
{
	if (Length() == 0)
		return;

	_str[Length() - 1] = '\0';
}

//Tạo chuỗi copy từ chuỗi truyền vào là chuỗi x.
void MyString::Copy(MyString x)
{
	_str = new char[x.Length() + 1];

	for (int i = 0; i < x.Length(); i++)
	{
		_str[i] = x._str[i];
	}
	_str[x.Length()] = '\0';
}

//Hàm tìm sự có mặt của chuỗi con x trong chuỗi hiện tại. Nếu có thì trả về 1 và 0 nếu ngược lại.
int MyString::Find(const string x)
{
	if (x.length() > Length())
		return 0;

	if (x == "")
		return 0;

	for (int i = 0; i < Length(); i++)
	{
		int check = 1;

		for (int j = 0; j < x.length(); j++)
		{
			if (_str[i + j] != x[j])
			{
				check = 0;
				break;
			}
		}
		if (check == 1)
			return 1;
	}
	return 0;
}

//So sánh hai chuỗi. Hàm trả về 0 nếu giống hoàn toàn và trả về -1 nhỏ hơn và 1 nếu lớn hơn.
int MyString::Compare(MyString x)
{
	if (Length() == x.Length())
	{
		int check = 1;

		for (int i = 0; i < Length(); i++)
		{
			if (_str[i] != x._str[i])
			{
				check = 0;
				break;
			}
		}
		if (check == 1)
			return 0;
	}

	int size;
	if (Length() > x.Length())
	{
		size = Length();
	}
	else
		size = x.Length();

	for (int i = 0; i < size; i++)
	{
		if (_str[i] == '\0')
			return -1;

		if (x._str[i] == '\0')
			return 1;

		if (_str[i] < x._str[i])
		{
			return -1;
		}
		else if (_str[i] > x._str[i])
		{
			return 1;
		}
	}
	return 0;
}

//Hàm trả về vị trí đầu tiên của kí tự x trong chuỗi. Nếu không có trả về -1.
int MyString::Find_First_Of(const char x)
{
	for (int i = 0; i < Length(); i++)
	{
		if (_str[i] == x)
			return i;
	}
	return -1;
}

//Hàm trả về vị trí cuối cùng của kí tự x trong chuỗi. Nếu không có trả về -1.
int MyString::Find_Last_Of(const char x)
{
	for (int i = Length(); i >= 0; i--)
	{
		if (_str[i] == x)
			return i;
	}
	return -1;
}

//Toán tử nhập chuỗi.
istream& operator>> (istream& is, MyString& str)
{
	cout << "Nhap chuoi: ";
	cin.ignore();
	str.Getline();
	return is;
}

//Toán tử xuất chuỗi.
ostream& operator<<(ostream& os, const MyString& str)
{
	os << "Chuoi cua ban: " << str._str;
	return os;
}

//Hàm getline.
void MyString::Getline()
{
	_str = new char[100];
	cin.getline(_str, 100);
}

MyString::MyString()
{
	_str = new char;
	_str[0] = '\0';
}

MyString::~MyString()
{
}