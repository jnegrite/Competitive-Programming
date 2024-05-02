#include<iostream>
#include<unordered_map>
#include<algorithm>
#include<set>
#include<string>

using namespace std;

struct Recipe {
    string name;
    long cost;

    Recipe(){};
    Recipe(string _name, long _cost){
        name = _name;
        cost = _cost;
    };

    bool operator<(const Recipe &o) const {
        if(cost != o.cost){
            return cost < o.cost;
        } else {
            return name < o.name;
        }
    }
};

int main(){
    int nBinders;
    string s;
    string binderName;
    string recipeName;
    int nIngredients;
    int nRecipes;
    long budget;
    long cost;
    long qty;
    long recipeCost;
    cin >> nBinders;
    unordered_map<string,long> ingredients {};
    set<Recipe> recipes {};
    
    for(int binder=0;binder<nBinders;binder++){
        cin.ignore();
        getline(cin,binderName);
        cin >> nIngredients >> nRecipes >> budget;
        
        //get ingredients
        ingredients.clear();
        while(nIngredients--){
            cin >> s >> cost;
            ingredients[s] = cost;
        }

        //get recipes
        recipes.clear();
        while(nRecipes--){
            cin.ignore();
            getline(cin, recipeName);
            cin >> nIngredients;
            recipeCost = 0;
            while(nIngredients--){
                cin >> s >> qty;
                recipeCost += (qty * ingredients[s]); 
            }
            
            if(recipeCost <= budget){
                Recipe curr {recipeName, recipeCost};
                recipes.emplace(curr);
            }
        }

        //output
        transform(binderName.begin(),binderName.end(),binderName.begin(),::toupper);
        cout << binderName << '\n';
        if(recipes.empty()){
            cout << "Too expensive!\n";
        } else {
            for(Recipe curr:recipes){
                cout << curr.name << '\n';
            }
        }
        cout << '\n';

    }
}