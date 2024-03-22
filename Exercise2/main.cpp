#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>


using namespace std;

double change_interval(double val, float a, float b, float c, float d){
    //generic math formula for changing the interval of a variable
    return ((val-a)*(d-c)/(b-a))+c;

    //in this case
    //a = 1; b = 5; c = -1; d = 2;
}

int main()
{
    // create an object to read the file with values
    ifstream ifes2("data.csv");


    //check if the file opens successfully
    if (ifes2.fail()){
        cerr <<"File not found"<<endl;
        return 1;//terminate main
    }

    //at first run it creates a new file named result.csv, then it updates it
    ofstream wresFile("result.csv");
    //header of the new file I have to write on
    wresFile << "#N  Mean" <<endl;

    double value=0;
    int count = 0;
    double new_val=0;
    double mean=0;
    double sum=0;

    //separator of values is defualt new line
    while (ifes2 >> value){

        //calculate values in a different interval
        new_val=change_interval(value,1,5,-1,2);

        //update the count of how many number I have read until now
        count ++;

        //operations to obtain the mean of values, I do it immediatly after reading the value on its line
        sum +=  new_val;
        mean = sum / count;

        //writing the new file or updating it
        // use scientific notation for exponential and 16 decimal format
        wresFile << count<< "   " << scientific << setprecision(16) << mean <<endl;
    }


    //close input file
    ifes2.close();
    wresFile.close();

    return 0;
}

