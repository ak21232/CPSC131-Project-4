#pragma once
#include <string>
#include <fstream>
#include <iostream>
#include <unordered_map>

using namespace std;

class UserLogin {
private:

    unordered_map< string, string > table;


public:
    UserLogin(); // default constructor

    void readIn(const string& filename); // add data from file to hash table

    size_t numberOfUsers(); // return the number of users

    string passWordCheck(const string& userName); // returns the passWord of the given user

    size_t wordBucketIdMethod1(const string& userName); // return the bucket number where the given user is located

    size_t wordBucketIdMethod2(const string& userName); // another way to find the bucket number where the given user is located

    bool validateUser(const string& userName); // look up given user

    bool authenticateUser(const string& userName, const string& passWord);// authenticate given user and password

};

UserLogin::UserLogin() {
}

// COMPLETE THE FOLLOWING FUNCTIONS

void UserLogin::readIn(const string& filename) {

    // TO DO
    std::ifstream inFile(filename);
  	if (inFile.is_open())
  	{
  		std::string userName, passW;
  		while (inFile >> userName >> passW) {
  			table.emplace(userName,passW);
  		}

  		inFile.close();  // file closes
  	}

}

size_t UserLogin::numberOfUsers() {

    return table.size();

}

string UserLogin::passWordCheck(const string& userName) {

    std::unordered_map<std::string,std::string>::const_iterator it = table.find (userName);
    if (it != table.end()){
        return it->second;
    }
    return "Non-existent User";

}

size_t UserLogin::wordBucketIdMethod1(const string& userName) {

    return table.bucket(table.find (userName)->second);

}

size_t UserLogin::wordBucketIdMethod2(const string& userName) {

    return table.bucket(table.at(userName));

}

bool UserLogin::validateUser(const string& userName) {

    std::unordered_map<std::string,std::string>::const_iterator it = table.find (userName);
    if (it != table.end()){
        return true;
    }
    return false;


}

bool UserLogin::authenticateUser(const string& userName, const string& passWord) {

    std::unordered_map<std::string,std::string>::const_iterator it = table.find (userName);
    std::unordered_map<std::string,std::string>::const_iterator it2 = table.find (passWord);
    if ((it != table.end() || it2 != table.end()) && (it == it2) ){
        return true;
    }
    return false;

 }
