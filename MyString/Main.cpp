#include <iostream>
#include <string>
using namespace std;

#include "MyString.h"

int main()
{
	MyString str;

	int luachon;
	do
	{
		system("cls");
		cout << "======================= MENU =======================\n";
		cout << "1.Nhap chuoi.\n";
		cout << "2.Xuat chuoi.\n";
		cout << "3.Tra ve ki tu dau.\n";
		cout << "4.Tra ve ki tu cuoi.\n";
		cout << "5.Tra ve kich thuoc chuoi.\n";
		cout << "6.Cai dat lai kich thuoc chuoi.\n";
		cout << "7.Xoa chuoi.\n";
		cout << "8.Kiem tra chuoi trong.\n";
		cout << "9.Tra ve ki tu bat ki trong chuoi.\n";
		cout << "10.Cong hai chuoi.\n";
		cout << "11.Noi chuoi.\n";
		cout << "12.Them ki tu vao cuoi chuoi.\n";
		cout << "13.Chen chuoi vao vi tri bat ki.\n";
		cout << "14.Xoa ki tu tai vi tri bat ki.\n";
		cout << "15.Thay the chuoi.\n";
		cout << "16.Dao chuoi.\n";
		cout << "17.Xoa ki tu cuoi chuoi.\n";
		cout << "18.Copy chuoi.\n";
		cout << "19.Tim chuoi co hay khong nam trong chuoi hien tai.\n";
		cout << "20.So sanh hai chuoi.\n";
		cout << "21.Tim vi tri dau tien xuat hien ki tu.\n";
		cout << "22.Tim vi tri cuoi cung xuat hien ki tu.\n";
		cout << "0.THOAT CHUONG TRINH\n";

		cout << "\nNhap lua chon: ";
		cin >> luachon;

		switch (luachon)
		{
		case 1:
			cin >> str;
			break;
		case 2:
			cout << str;
			break;
		case 3:
			if (str.Size() == 0)
				cout << "Chuoi rong!!!";
			else
				cout << "Ki tu dau tien: " << str.Front();
			break;
		case 4:
			if (str.Size() == 0)
				cout << "Chuoi rong!!!";
			else
				cout << "Ki tu cuoi cung: " << str.Back();
			break;
		case 5:
			cout << "Kich thuoc chuoi: " << str.Size();
			break;
		case 6:
			if (str.Size() == 0)
				cout << "Chuoi rong!!!";
			else
			{
				int x;
				cout << "Nhap kich thuoc x can cai lai cho chuoi: ";
				cin >> x;
				str.Resize(x);
				cout << "Cai lai kich thuoc hoan tat!";
			}
			break;
		case 7:
			str.Clear();
			cout << "Da xoa chuoi thanh cong!";
			break;
		case 8:
			if (str.Empty() == 1)
				cout << "Chuoi rong!";
			else
				cout << "Chuoi KHONG rong!";
			break;
		case 9:
			if (str.Size() == 0)
				cout << "Chuoi rong!!!";
			else
			{
				int x;
				cout << "Nhap vi tri x: ";
				cin >> x;
				cout << "Ki tu tai vi tri " << x << " cua chuoi: " << str.At(x);
			}
			break;
		case 10:
			if (str.Size() == 0)
				cout << "Chuoi rong!!!";
			else
			{
				MyString sum;
				cin >> sum;
				cout << operator+(str, sum);
			}
			break;
		case 11:
			if (str.Size() == 0)
				cout << "Chuoi rong!!!";
			else
			{
				string x;
				cout << "Nhap chuoi noi: ";
				cin.ignore();
				getline(cin, x);
				str.Append(x);
				cout << "Da noi chuoi thanh cong!";
			}
			break;
		case 12:
			if (str.Size() == 0)
				cout << "Chuoi rong!!!";
			else
			{
				char x;
				cout << "Nhap ki tu can them: ";
				cin >> x;
				str.Push_Back(x);
				cout << "Da them thanh cong!";
			}
			break;
		case 13:
			if (str.Size() == 0)
				cout << "Chuoi rong!!!";
			else
			{
				string x;
				cout << "Nhap chuoi can chen: ";
				cin.ignore();
				getline(cin, x);

				int i;
				cout << "Nhap vi tri can chen: ";
				cin >> i;

				str.Insert(x, i);
				cout << "Da chen thanh cong!";
			}
			break;
		case 14:
			if (str.Size() == 0)
				cout << "Chuoi rong!!!";
			else
			{
				int x;
				cout << "Nhap vi tri ma ban muon xoa: ";
				cin >> x;

				str.Erase(x);
				cout << "Da xoa thanh cong!";
			}
			break;
		case 15:
			if (str.Size() == 0)
				cout << "Chuoi rong!!!";
			else
			{
				int s;
				cout << "Nhap vi tri bat dau: ";
				cin >> s;

				int e;
				cout << "Nhap vi tri ket thuc: ";
				cin >> e;

				string x;
				cout << "Nhap chuoi ma ban muon thay the: ";
				cin.ignore();
				getline(cin, x);

				str.Replace(s, e, x);
				cout << "Da thay the thanh cong!";
			}
			break;
		case 16:
			if (str.Size() == 0)
				cout << "Chuoi rong!!!";
			else
			{
				str.Swap();
				cout << "Dao chuoi thanh cong!";
			}
			break;
		case 17:
			if (str.Size() == 0)
				cout << "Chuoi rong!!!";
			else
			{
				str.Pop_Back();
				cout << "Xoa ki tu cuoi chuoi thanh cong!";
			}
			break;
		case 18:
		{
			MyString copy;
			cout << "Nhap chuoi ma ban muon copy:\n";
			cin >> copy;

			str.Copy(copy);
			cout << "Da copy thanh cong!";
		}
			break;
		case 19:
			if (str.Size() == 0)
				cout << "Chuoi rong!!!";
			else
			{
				string x;
				cout << "Nhap chuoi ban can tim: ";
				cin.ignore();
				getline(cin, x);

				if (str.Find(x) == 1)
				{
					cout << "Ton tai chuoi nay trong chuoi hien tai!";
				}
				else
					cout << "KHONG ton tai chuoi nay trong chuoi hien tai!";
			}
			break;
		case 20:
			if (str.Size() == 0)
				cout << "Chuoi rong!!!";
			else
			{
				MyString x;
				cout << "Nhap chuoi ban can so sanh:\n";
				cin >> x;

				if (str.Compare(x) < 0)
				{
					cout << "Chuoi hien tai nho hon chuoi nay!";
				}
				else if (str.Compare(x) > 0)
				{
					cout << "Chuoi hien tai lon hon chuoi nay!";
				}
				else
					cout << "Hai chuoi bang nhau!";
			}
			break;
		case 21:
			if (str.Size() == 0)
				cout << "Chuoi rong!!!";
			else
			{
				char x;
				cout << "Nhap ki tu ban muon tim: ";
				cin >> x;

				if (str.Find_First_Of(x) == -1)
				{
					cout << "KHONG ton tai ki tu nay!";
				}
				else
					cout << "Vi tri dau tien ki tu nay xuat hien la: " << str.Find_First_Of(x);
			}
			break;
		case 22:
			if (str.Size() == 0)
				cout << "Chuoi rong!!!";
			else
			{
				char x;
				cout << "Nhap ki tu ban muon tim: ";
				cin >> x;

				if (str.Find_Last_Of(x) == -1)
				{
					cout << "KHONG ton tai ki tu nay!";
				}
				else
					cout << "Vi tri cuoi cung ki tu nay xuat hien la: " << str.Find_Last_Of(x);
			}
			break;
		case 0:
			cout << "\n---------------- HEN GAP LAI!!! ----------------";
		}
		cout << endl;
		system("pause");

	} while (luachon != 0);

	return  0;
}