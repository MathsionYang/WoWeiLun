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
	infile.open("data.txt");   //将文件流对象与文件连接起来 
	assert(infile.is_open());   //若失败,则输出错误消息,并终止程序运行 
	string s;

		while (infile>>s)
		{
			V.push_back(s);
		}
	infile.close();             //关闭文件输入流 

	int sizeNum = V.size();

	for (int j = 2; j < sizeNum; j=j+4)//获取X
	{
		//cout <<V[j]<< endl;
	/*	double X[200];
		stringstream stream(V[j]);
		stream >> X[j];
		double b = X[j];
		j++;
		cout <<"X坐标："<<b << endl;*/
	}
	int i = 0;
	for (int k= 3; k< sizeNum; k = k + 4)//获取Y
	{
	
		//cout << V[k] << endl;
		double Y[200];
		stringstream stream(V[k]);
		stream >> Y[i];
		double a = Y[i];
		i++;
		cout <<  "Y坐标："<<a << endl;
	}

	system("pause");
	return 0;
}
