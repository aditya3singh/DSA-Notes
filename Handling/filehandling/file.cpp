/*
Just getting the complete i/p and o/p from the user not just single character

#include<bits/stdc++.h>
using namespace std;

int main(){
    string data;
    getline(cin, data);
    cout << data;
}

*/

/*
creating and opening file


#include<bits/stdc++.h>
using namespace std;
int main(){
    fstream file;
    file.open("fileDemo.txt", ios :: in | ios :: out | ios :: trunc);

    if(!file.is_open()){
        cout << "error while opening the file";
    }
    else{
        cout << "file opened successfully";
        file.close();
    }
    return 0;
}
*/

/*

write to a file using ofStream class
using this the previous method will be removed and brand new file will be open and offered to us

*/

/*
#include<bits/stdc++.h>
using namespace std;
int main(){
    fstream file("fileDemo.txt",ios :: in | ios :: out );

    if(!file.is_open()){
        cout << "unable to open the file"<<endl;
    }else{

        file << "Learning is Important"<<" ";
        file << "We have learned almost everthing...";
        file.seekg(0, ios::beg);
        string lined;
        while(file.good()){
        getline(file, lined);
        cout << lined<< endl;
       }
        cout << "successfully written to the file open it and check it out";
        file.close();
    }

    return 0;
}
*/

/*
#include<bits/stdc++.h>
using namespace std;
int main(){
    ifstream file("fileDemo.txt");

    if(!file.is_open()){
        cout << "error while oppening the file";
    }
    else{
        cout << "reading from the file contents are"<<endl;

*/

/*
when there is a use of reading of multiple lines we use the while loop for reading the multiple line
here we have reached the end of the file or not so we can check that by using the file.good
so, here this 'good' is a method available from the class you know which allows us to check whether any flag such as
the good bit or the eof bit or the failed bit or the bad bit is set or
*/
/*
        string line;
while(file.good()){
getline(file, line);
cout << line<< endl;
}
}

return 0;
}
*/

/*
This is for the append method used to append to the file.


#include <bits/stdc++.h>
using namespace std;
int main()
{
    fstream file("fileDemo.txt", ios::in | ios::out | ios::app);
    if (!file.is_open())
    {
        cout << "error to open the file";
    }
    else
    {
        cout << "file opened successfully" << endl;
        cout << "writing to the file" << endl;

        file << "learning is important";

        file.seekg(0);
        cout << "reading to the file ";
        string line;
        while (file.good())
        {
            getline(file, line);
            cout << line << endl;
        }
    }
}
*/

/*

File position indicators

#include <bits/stdc++.h>
using namespace std;

int main()
{
    fstream file("fileDemo.txt", ios::in| ios::out);
    if (!file.is_open())
    {
        cout << "error to open the file";
    }
    else
    {
        cout << file.tellg() << endl;
        // cout << file.tellp() << endl;
        string line;
        while (file.good())
        {
            file.seekg(2);//this will start reading from the second position
            getline(file, line);
            cout << line;
            cout  << endl;
        }
    }
}
*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    fstream file("fileDemo.txt", ios::in | ios::out);
    if (!file.is_open())
    {
        cout << "error to open the file";
    }
    else
    {
        cout << file.tellp() << endl;
        // file << "he is you good";
        string line;
        getline(file, line);
        // cout << line<<endl;
        cout << file.tellp() << endl;

        file.seekp(20);

        file << "kup is now where";

        // cout << file.tellp();
        cout << endl;
    }
}
/*
* /


/*
Binary files


#include <bits/stdc++.h>
using namespace std;

int main(){
    char input[100];
    strcpy(input, "learning lad rocks");

    fstream file("binaer.bin", ios::binary | ios::in | ios:: out| ios:: trunc);

    if(!file.is_open()){
        cout << "error while opening the file";
    }else{
        int length = strlen(input);
        for(int counter = 0; counter < length; counter++){
            file.put(input[counter]);
        }
        file.seekg(0);
        char ch;
        while(file.good()){
            file.get(ch);
            cout << ch;
        }
    }
}
*/
