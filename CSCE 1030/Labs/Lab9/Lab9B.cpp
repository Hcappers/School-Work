#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

void get_stream(ifstream& in_s, ofstream& out_s);

int main(){
    char c;
    ifstream in_s;
    ofstream out_s;
    get_stream(in_s, out_s);
    in_s.get(c);
    
    cout << "*** Here are the contents of the input file ***" << endl;

    while(!in_s.eof()){
        out_s.put(c);
        in_s.get(c);

    }
    
    cout << endl << "*** Done writing the contents of the file ***" << endl;

    in_s.close();

    return 0;
}

/*  Function: get  stream
    Parameters: in_s and  out_s
    Return: new file
    Description: Takes info from one file and puts thm onto another  file
*/
void get_stream(ifstream& in_s, ofstream& out_s){
    char input_file[15];
    char output_file[15];

    cout << "Please enter the name of the input file name: ";
    cin >> input_file;
    in_s.open(input_file);

    if(in_s.fail()){
        cout << "Unable to open input file " << input_file << endl;
        exit(EXIT_FAILURE); // This terminates the program if an error is found while opening the file.
    }

    cout << "Enter the name of the output file : ";
    cin >> output_file;
    out_s.open(output_file);

    if(out_s.fail()){
        cout << "Unable to open input file " << output_file << endl;
        exit(EXIT_FAILURE);
    }
    return;
}