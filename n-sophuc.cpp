#include<iostream>
#include<stdlib.h>
#include<math.h>

using namespace std;

class sophuc 
{
	private:
		float pt, pa;
	public :
		sophuc()
		{
			pt=0;
			pa=0;
		}
		void nhap();
		void hien();
		void tru(sophuc&,sophuc&);
		sophuc operator+(sophuc &sp2);
		sophuc operator-(sophuc &sp2);
		sophuc operator*(sophuc &sp2);
		sophuc operator/(sophuc &sp2);
};	

void sophuc::nhap ()
{
	cout<<"Moi nhap phan thuc :";
	cin>>pt;
	cout<<"Moi nhap phan ao :";
	cin>>pa;
}
	
void sophuc::hien()
{
	if(pa<0)
	cout<<pt<<pa<<"*i"<<"\n";
	else
	cout<<pt<<"+"<<pa<<"*i"<<"\n";
		
}

sophuc sophuc::operator+(sophuc &sp2)
{
	sophuc tong;
	tong.pt=pt+sp2.pt;
	tong.pa=pa+sp2.pa;
	return tong;
}

sophuc sophuc::operator-(sophuc &sp2)
{
	sophuc hieu;
	hieu.pt=pt-sp2.pt;
	hieu.pa=pa-sp2.pa;
	return hieu;
}

sophuc sophuc::operator*(sophuc &sp2)
{
	sophuc tich;
	tich.pt=pt*sp2.pt-pa*sp2.pa;
	tich.pa=pt*sp2.pa+pa*sp2.pt;
	return tich;
}

sophuc sophuc::operator/(sophuc &sp2)
{
	sophuc thuong;
	thuong.pt=sp2.pt/(pow(sp2.pt,2)+pow(sp2.pa,2));
	thuong.pa=-sp2.pa/(pow(sp2.pt,2)+pow(sp2.pa,2));
}

int main()
{

	sophuc sp[50], tong, hieu, tich, thuong;
	int i, n;
	cout<<"BAn muon nhap bao nhieu so phuc :";
	cin>>n;
	
	for(i=0;i<n;i++)
	{
	cout<<"Nhap so phuc thu "<<i+1<<"\n";
	sp[i].nhap();
	}
	
	for(i=0;i<n;i++)
	{
	tong=tong+sp[i];
	}

	tich=sp[0];
	for(i=1;i<n;i++)
	{
	tich=tich*sp[i];
	}

	hieu=sp[0];
	for(i=1;i<n;i++)
	{
	hieu=hieu-sp[i];
	}

	cout<<"Cac so phuc da nhap la "<<"\n";

	for(i=0;i<n;i++)
	{
	sp[i].hien();
	cout<<"\n";
	}
	cout<<"Tong cua cac so phuc da nhap la:";
	tong.hien();
	cout<<"\n";
	cout<<"Hieu cua cac so phuc da nhap la:";
	hieu.hien();
	cout<<"\n";
	cout<<"Tich cua cac so phuc da nhap la:";
	tich.hien();

	cout<<"\n";
	return 0;
}
