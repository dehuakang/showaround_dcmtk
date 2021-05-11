#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main(int argc,char* argv[])
{
    string fileName="../data/test.dcm";
    fstream reader;
    reader.open(fileName.c_str(),ios::in|ios::binary);
    if(reader.bad()){
        cout<<"Read file failed."<<endl;
        return -1;
    }
    reader.seekg(0,ios::end);
    int pos=reader.tellg();
    cout<<"File size is : "<<pos<<endl;
    reader.seekg(128,ios::beg);
    char buffer[4];

    reader.read((char*)&buffer,4);
    cout<<"The content in buff is : "<<buffer<<endl;

    reader.seekg(132,ios::beg);
    reader.read(buffer,2);
    unsigned short data=buffer[1]<<8|buffer[0];
    cout<<"group is: "<<data<<endl;
    reader.read(buffer,2);
    data=buffer[1]<<8|buffer[0];
    cout<<"element is: "<<data<<endl;
    reader.read(buffer,2);
    data=buffer[1]<<8|buffer[0];
    cout<<"VR is : "<<data<<endl;
    reader.read(buffer,4);
    data=buffer[1]<<8|buffer[0];
    cout<<"VL is : "<<data<<endl;
    reader.read(buffer,4);
    data=buffer[3]<<24|buffer[2]<<16|buffer[1]<<8|buffer[0];
    cout<<"VF is: "<<data<<endl;
    cout<<string(50,'$')<<endl;

    reader.read(buffer,2);
    data=buffer[1]<<8|buffer[0];
    cout<<"group is: "<<data<<endl;
    reader.read(buffer,2);
    data=buffer[1]<<8|buffer[0];
    cout<<"element is: "<<data<<endl;
    reader.read(buffer,2);
    data=buffer[1]<<8|buffer[0];
    cout<<"VR is : "<<data<<endl;
    reader.read(buffer,4);
    data=buffer[1]<<8|buffer[0];
    cout<<"VL is : "<<data<<endl;
    reader.read(buffer,4);
    data=buffer[3]<<24|buffer[2]<<16|buffer[1]<<8|buffer[0];
    cout<<"VF is: "<<data<<endl;
    cout<<string(50,'$')<<endl;

    reader.read(buffer,2);
    data=buffer[1]<<8|buffer[0];
    cout<<"group is: "<<data<<endl;
    reader.read(buffer,2);
    data=buffer[1]<<8|buffer[0];
    cout<<"element is: "<<data<<endl;
    reader.read(buffer,2);
    data=buffer[1]<<8|buffer[0];
    cout<<"VR is : "<<data<<endl;
    reader.read(buffer,4);
    data=buffer[1]<<8|buffer[0];
    cout<<"VL is : "<<data<<endl;
    reader.read(buffer,4);
    data=buffer[3]<<24|buffer[2]<<16|buffer[1]<<8|buffer[0];
    cout<<"VF is: "<<data<<endl;
    cout<<string(50,'$')<<endl;


    reader.close();



    return 0;
}
