#include<algorithm>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <cassert>
using namespace std;

int main()
{
	vector<string> V;
	vector<string>::iterator it;
	ifstream infile;
	infile.open("data.txt");   //���ļ����������ļ��������� 
	assert(infile.is_open());   //��ʧ��,�����������Ϣ,����ֹ�������� 
	string s;

		while (infile>>s)
		{
			V.push_back(s);
		}
	infile.close();             //�ر��ļ������� 

	int sizeNum = V.size();

	for (int j = 2; j < sizeNum; j=j+4)//��ȡX
	{
		//cout <<V[j]<< endl;
	/*	double X[200];
		stringstream stream(V[j]);
		stream >> X[j];
		double b = X[j];
		j++;
		cout <<"X���꣺"<<b << endl;*/
	}
	int i = 0;
	for (int k= 3; k< sizeNum; k = k + 4)//��ȡY
	{
	
		//cout << V[k] << endl;
		double Y[200];
		stringstream stream(V[k]);
		stream >> Y[i];
		double a = Y[i];
		i++;
		cout <<  "Y���꣺"<<a << endl;
	}

	system("pause");
	return 0;
}
