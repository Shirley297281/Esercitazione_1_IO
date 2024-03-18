#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <vector>

using namespace std;

double change_interval(double val, float a, float b, float c, float d){
    //generic math formula for changing interval of a variable
    return ((val-a)*(d-c)/(b-a))+c;
}

int main()
{
    // create the object to read the file with values
    ifstream ifes2("datas.csv");

    // create the object to read the file with values, at first run it creates a new file named result.csv, then it updates it
    ofstream wresFile("result.csv");
    //header of the new file I have to write on
    wresFile << "N Mean" <<endl;

    //check if the file opens successfully
    if (ifes2.fail()){
        cerr <<"File not found"<<endl;
        return 1;
    }

    double value=0;
    int count = 0;
    string line;
    double new_val=0;
    double mean=0;
    double sum=0;

    //values are separated by new line, so I need to use this function "getting a value for a single line"
    while (getline(ifes2,line)){

        try {
            //Convert a string (line) to a double (value)
            value = stod(line);
        }

        //errors may accur

        catch (const invalid_argument& e) {
            cerr << "Invalid value found: " << line << endl;
        }
        catch (const out_of_range& e) {
            cerr << "Value out of range: " << line << endl;
        }


        //check if values are coherent
        //cout << fixed << setprecision(16)<< value; // Print the value
        //cout << "->";


        //caluculate same values in a different interval
        new_val=change_interval(value,1,5,-1,2);
        //cout << new_val <<endl;

        //update the count of how many number I have read until now
        count ++;

        //operations to obtain the mean of values, I do it immediatly after reading the value on his line
        sum +=  new_val;
        mean = sum / count;

        //writing the new file or updating it
        // scientific for exponencial and 16 decimals format
        wresFile << scientific << setprecision(16) << count << " " << mean <<endl;
    }



    ifes2.close();


    return 0;
}
