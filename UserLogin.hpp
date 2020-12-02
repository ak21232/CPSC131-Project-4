#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class UserLogin {
private:
  unordered_map<string, string> table;

public:
  UserLogin(); // default constructor

  void readIn(const string &filename); // add data from file to hash table

  size_t numberOfUsers(); // return the number of users

  string passWordCheck(
      const string &userName); // returns the passWord of the given user

  size_t
  wordBucketIdMethod1(const string &userName); // return the bucket number where
                                               // the given user is located

  size_t wordBucketIdMethod2(
      const string &userName); // another way to find the bucket number where
                               // the given user is located

  bool validateUser(const string &userName); // look up given user

  bool authenticateUser(
      const string &userName,
      const string &passWord); // authenticate given user and password
};

UserLogin::UserLogin() {}

// COMPLETE THE FOLLOWING FUNCTIONS

void UserLogin::readIn(const string &filename) {
  // Open file, read each line and store into variables
  std::ifstream inFile(filename);
  if (inFile.is_open()) {
    std::string userName, passW;
    while (inFile >> userName >> passW) {
      table[userName] = passW;
    }

    inFile.close();
  }
}

size_t UserLogin::numberOfUsers() { return table.size(); }

string UserLogin::passWordCheck(const string &userName) {
  // Find username in table
  std::unordered_map<std::string, std::string>::const_iterator it =
      table.find(userName);
  if (it != table.end()) {
    return it->second;
  }
  return "Non-existent User";
}

size_t UserLogin::wordBucketIdMethod1(const string &userName) {
  // Return bucket number using .find()
  return table.bucket(table.find(userName)->second);
}

size_t UserLogin::wordBucketIdMethod2(const string &userName) {
  // Return bucket number using .at()
  return table.bucket(table.at(userName));
}

bool UserLogin::validateUser(const string &userName) {
  // Determine if user exists in table
  std::unordered_map<std::string, std::string>::const_iterator it =
      table.find(userName);
  if (it != table.end()) {
    return true;
  }
  return false;
}

bool UserLogin::authenticateUser(const string &userName,
                                 const string &passWord) {
  // Detrmine if username and password exist together in table
  std::unordered_map<std::string, std::string>::const_iterator it =
      table.find(userName);
  if ((it != table.end() && (table[userName] == passWord))) {
    return true;
  }
  return false;
}
