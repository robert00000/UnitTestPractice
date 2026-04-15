#include "Password.h"
#include <string>

using std::string;


/* Receives a string and returns a count of how many case-sensitive unique characters there are. If there are duplicate instances of the same character it should only count as a single character. Even if characters look similar, as long as they have distinct ASCII values, they should qualify as unique characters. */


unsigned int Password::unique_characters(string str){
  unsigned int num_chars = 0;

  for (int i = 0; i < str.length() - 1; i++){
    for (int j = i + 1; j < str.length(); j++) {
      if (str[i] == str[j]) {
          num_chars++; 
      }
    }
  }

  

  return num_chars;
}

/*
  The function receives a string counts how many times the same character
  occurs at the beginning of the string, before any other characters (or the
  end of the string). The function is case-sensitive so 'Z' is different than
  'z' and any ASCII characters are allowed.
*/
int Password::count_leading_characters(string phrase)
{
  int repetition = 1;
  int index = 0;
  while (index < phrase.length() - 1 && phrase[index] == phrase[index + 1])
  {
    repetition++;
    index++;
  }
  return repetition;
}

// Implementation A
#include <cctype>
//bool Password::has_mixed_case(string str)
//{
//  bool has_lower = false;
//  bool has_upper = false;
//  for (char ch : str)
//  {
//    if (std::islower(ch))
//    {
//      has_lower = true;
//    }
//    else if (std::isupper(ch))
//    {
//      has_upper = true;
//    }
//  }
//  return has_lower && has_upper;
//}
//// Implementation B
//bool Password::has_mixed_case(string str)
//{
//  int count_lower = 0;
//  for (int i = 0; i < str.length(); i++)
//  {
//    if (str[i] >= 'a' && str[i] <= 'z')
//    {
//      count_lower++;
//    }
//  }
//  return count_lower > 0 && count_lower < str.length();
//}
//// Implementation C
//bool Password::has_mixed_case(string str)
//{
//  bool lower = false;
//  bool upper = false;
//  for (int i = 0; i < str.length(); i++)
//  {
//    if (str[i] >= 'a' && str[i] <= 'z')
//    {
//      lower = true;
//    }
//    else if (str[i] >= 'A' && str[i] <= 'Z')
//    {
//      upper = true;
//    }
//  }
//  return upper && lower;
//}
//// Implementation D
#include <cctype>
bool Password::has_mixed_case(string str)
{
  bool is_lower = false;
  bool is_upper = false;
  for (char c : str)
  {
    if (std::islower(c))
    {
      is_lower = true;
    }
    else
    {
      is_upper = true;
    }
  }
  return is_lower && is_upper;
}
//// Implementation E
//bool Password::has_mixed_case(string str)
//{
//  bool found = false;
//  for(char c : str){
//    if( !found && c >= 'A' && c <= 'Z' ){
//      found = true;
//    }
//    else if( found && c >= 'a' && c <= 'z'){
//      return true;
//    }
//  }
//  return false;
//}
