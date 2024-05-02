#include<iostream>
#include<map>
#include<string>
#include<sstream>

using namespace std;

struct Term {
    char operation {'\0'};
    string content {};   
};

int main(){
    int numCases {};
    string s;

    cin >> numCases;
    getline(cin, s);

    for(int tc=1;tc<=numCases;tc++){
        int numExp {};
        cin >> numExp;
        getline(cin,s);
        map<string,Term> terms {};
        string fin {};
        
        while(numExp--){
            getline(cin,s);
            string temp;
            auto strIn {stringstream(s)};

            string target, op1, op2, opr;

            if((s.find("+")>=0) || (s.find("*")>=0)){
                strIn >> target >> temp >> op1 >> opr >> op2;

                string output {};
                Term term1 {}, term2 {};
                auto it1 = terms.find(op1);
                auto it2 = terms.find(op2);

                if(it1 == terms.end()){
                    term1.content = op1;
                    term1.operation = '\0';
                } else {
                    term1 = it1->second;
                    op1 = term1.content;
                }

                if(it2 == terms.end()){
                    term2.content = op2;
                    term2.operation = '\0';
                } else {
                    term2 = it2->second;
                    op2 = term2.content;
                }
                
                //only wrap first term if it's a plus and operator is a multiply
                if(opr == "*" && term1.operation == '+'){
                    op1 = "(" + op1 + ")";
                }
                
                //make sure to wrap 2nd term if it's an expression and operator is +
                if((opr == "*" && term2.operation != '\0') || (opr == "+" && term2.operation == '+')){
                    op2 = "(" + op2 + ")";
                }

                Term tmp {};
                fin = op1 + opr + op2;
                tmp.content = fin;
                tmp.operation = opr.at(0);
                terms[target] = tmp;


            } else {
                strIn >> target >> temp >> op1;
                auto idx {terms.find(op1)};

                if(idx == terms.end()){
                    Term curr {};
                    curr.operation = '\0';
                    curr.content = op1;

                    terms[target] = curr;
                } else {
                    terms[target] = idx->second;
                }
                continue;
            }
        }
        
        cout << "Expression #" << tc << ": " << fin << '\n';
    }
}