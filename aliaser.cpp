#include<iostream>
#include<fstream>
#include<cstdlib>

using namespace std;

bool checkFileExits(const string& str){
    ifstream ifs(str);
    return ifs.is_open();
}

int main(){
    fstream file;
    string homeName = getenv("HOME");
    string settingFile = homeName + "/.bashrc";
    string aliasCommand;
    string aliasPath;

    cout<<"input command name"<<endl;
    cin >>aliasCommand;
    cout<<"input command path"<<endl;
    cin >>aliasPath;
    
    if(!checkFileExits(aliasPath)){
        cout<<"this path isn't exited"<<endl;
        return EXIT_FAILURE;
    }
    
    file.open(settingFile,ios::app);
    if(!file.is_open()){
        return EXIT_FAILURE;
    }
    file<<"alias " +aliasCommand+"="+aliasPath<<endl;
    file.close();
}
