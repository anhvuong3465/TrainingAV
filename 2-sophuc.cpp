#include<iostream>
#include<stdlib.h>
#include<math.h>


using namespace std;

class sophuc
	{
	private:
		float pt, pa;
	public:
		sophuc()
		{
			pt=0;
			pa=0;
		}
		void nhap();
		void xuat();
		void cong(sophuc&, sophuc&);
		void tru(sophuc&,sophuc&);
		void nhan(sophuc&,sophuc&);
		void chia(sophuc&,sophuc&);
	};

void sophuc::nhap ()
{
	cout<<"Moi nhap phan thuc :";
	cin>>pt;
	cout<<"Moi nhap phan ao :";
	cin>>pa;
}
	
void sophuc::xuat()
{
	if(pa<0)
	cout<<pt<<pa<<"*i"<<"\n";
	else
	cout<<pt<<"+"<<pa<<"*i"<<"\n";
		
}
void sophuc::cong(sophuc&c1,sophuc&c2)
{
	this ->pt=c1.pt+c2.pt;
	this ->pa=c1.pa+c2.pa;
}
void sophuc::tru(sophuc&c1,sophuc&c2)
{
	this ->pt=c1.pt-c2.pt;
	this ->pa=c1.pa-c2.pa;
}
void sophuc::nhan(sophuc&c1,sophuc&c2)
{
	this ->pt=c1.pt*c2.pt-c1.pa*c2.pa;
	this ->pa=c1.pt*c2.pa+c1.pa*c2.pt;
}
void sophuc::chia(sophuc&c1,sophuc&c2)
{
	sophuc kq;
	if((c2.pt==0)&&(c2.pa==0)) return;
	kq.pt=c2.pt/(pow(c2.pt,2)+pow(c2.pa,2));
	kq.pa=-c2.pa/(pow(c2.pt,2)+pow(c2.pa,2));
	(*this).nhan(c1,kq);
}

int main()
{
	sophuc c1,c2;
	sophuc kq;
	cout<<"Moi nhap vao hai so phuc"<<"\n";
	cout<<"So thu nhat"<<"\n";
	c1.nhap();
	cout<<"So thu hai"<<"\n";
	c2.nhap();
	cout<<"So thu nhat là:";c1.xuat();
	cout<<"So thu hai la:";c2.xuat();
	cout<<"\n Ket qua cac phep toan:\n";
	cout<<"\n Phep cong hai so:";
	kq.cong(c1,c2);
	kq.xuat();
	cout<<"\n Ket qua tru so thu nhat cho so thu hai la:";
	kq.tru(c1,c2);
	kq.xuat();
	cout<<"\n Phep nhan hai so:";
	kq.nhan(c1,c2);
	kq.xuat();
	cout<<"\n Ket qua chia so thu nhat cho so thu hai la:";
	kq.chia(c1,c2);
	kq.xuat();
}




