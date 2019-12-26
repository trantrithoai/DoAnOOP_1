#pragma once
#ifndef _MYSTRING_H
#define _MYSTRING_H

class MyString
{
private:
	char* _str;
public:
	char Begin();//Hàm trả về kí tự đầu của chuỗi.
	char End();//Hàm trả về kí tự cuối của chuỗi.
public:
	int Size();//Hàm trả về kích thước chuỗi.
	int Length();//Hàm trả về chiều dài chuỗi.
	void Resize(const int x);//Hàm cài đặt lại kích thước của chuỗi.
	void Clear();//Hàm xóa chuỗi.
	int Empty();//Hàm trả về 1 nếu chuỗi trống và 0 nếu ngược lại.
public:
	char At(const int x);//Hàm lấy phần tử tại vị trí x.
	char Front();//Hàm lấy phần tử đầu tiên chuỗi.
	char Back();//Hàm lấy phần tử cuối cùng chuỗi.
public:
	friend MyString operator+ (MyString a, MyString b);//Toán tử cộng chuỗi.
	void Append(const string x);//Hàm nối chuỗi.
	void Push_Back(const char x);//Hàm thêm kí tự vào cuối chuỗi.
	void Insert(string s, const int x);//Hàm thêm vào chuỗi tại vị trí x.
	void Erase(const int x);//Hàm xóa phần tử của chuỗi tại vị trí x.
	void Replace(const int s, const int e, const string x);//Hàm thay thế chuỗi x vào chuỗi hiện tại từ vị trí s đến e.
	void Swap();//Hàm đảo ngược chuỗi.
	void Pop_Back();//Hàm xóa phần tử cuối của chuỗi.
public:
	void Copy(MyString x);//Tạo chuỗi copy từ chuỗi truyền vào là chuỗi x.
	int Find(const string x);//Hàm tìm sự có mặt của chuỗi con x trong chuỗi hiện tại. Nếu có thì trả về 1 và 0 nếu ngược lại.
	int Compare(MyString x);//So sánh hai chuỗi. Hàm trả về 0 nếu giống hoàn toàn và trả về -1 nhỏ hơn và 1 nếu lớn hơn.
	int Find_First_Of(const char x);//Hàm trả về vị trí đầu tiên của kí tự x trong chuỗi. Nếu không có trả về -1.
	int Find_Last_Of(const char x);//Hàm trả về vị trí cuối cùng của kí tự x trong chuỗi. Nếu không có trả về -1.
public:
	friend istream& operator>> (istream& is, MyString& str);//Toán tử nhập chuỗi.
	friend ostream& operator<< (ostream& os, const MyString& str);//Toán tử xuất chuỗi.

	void Getline();//Hàm getline.
public:
	MyString();
	~MyString();
};

#endif // !_MYSTRING_H

