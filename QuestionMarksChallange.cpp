#include<bits/stdc++.h>

using namespace std;

string CountQuestionsMarks(string s, int pos1, int pos2);

string QuestionsMarks(string str){
  int pos1 = -1, pos2 = -1, num1, num2, length;
  string present = "false", result;

  length = str.length();

  for(int i = 0; i < length; i++){
    if('0' <= str[i] && '9' >= str[i]){
      if(pos1 == -1){
        pos1 = i;
        num1 = str[i] - 48;
      }
      else if(pos2 == -1){
        pos2 = i;
        num2 = str[i] - 48;

        if(num1 + num2 == 10){
          present = "true";

          result = CountQuestionsMarks(str, pos1, pos2);
          
          if(result == "false"){
            return "false";
          }

          pos1 = pos2;
          pos2 = -1;
        }
      }
    }
    if(present == "true"){
      return "true";

      return "false";
    }
  }
}

string CountQuestionsMarks(string s, int pos1, int pos2){
  int qcount = 0;

  for(int i = pos1; i < pos2; i++){
    if(s[i] == '?')
      qcount++;
  }
  if(qcount == 3)
    return "true";
  else
    return "false";
}

int main(){
	char str[100];
	cin >> str;	
  	cout << QuestionsMarks(str);
  	return 0;
}
