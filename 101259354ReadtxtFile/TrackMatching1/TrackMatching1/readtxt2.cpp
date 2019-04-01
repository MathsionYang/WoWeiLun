#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include <cstdlib>

using namespace std;
double* ReadPoint(string strFileName);

int main()
{
 //ReadPoint("test1.txt");   //在这里输入你的文件名称,确保路径正确
	 double* m=ReadPoint("DataSet.txt"); 
	 cout<<m[0]<<"  "<<m[1]<<endl;
 getchar();
 
 return 0;
}

double* ReadPoint(string strFileName)
{

	double a[2]={0};
    double * p = a;
	ifstream is(strFileName.c_str());

    if(is)
    {
		string strBuffer;
	
        while(is>>strBuffer)
        {
			size_t nFlagX = strBuffer.find('x');
            size_t nFlagY = strBuffer.find('y');
			if(nFlagX != -1)
			{
				string strXOut = strBuffer.substr(2,8);
	            double Xout=atof(strXOut.c_str());
		        a[0]=Xout;
	         }
	         if(nFlagY != -1)
             {
				 string strYOut = strBuffer.substr(2,8);
	             double Yout=atof(strYOut.c_str());
			
				 a[1]=Yout;
				
		      }
		      
	     }
		is.close();
		return p;
	}
 else
 {
  cerr<<"File open falured!"<<endl;
  exit(1);
 }
}

