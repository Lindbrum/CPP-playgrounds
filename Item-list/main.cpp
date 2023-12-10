#include <iostream>
#include <vector>
#include <algorithm> // For sorting

using namespace std;

int main(){
    vector<int> content {};
    vector<int> sorted {};
    bool dirty {false};

    cout << "Welcome!" << endl;
    char selected {};
    do{
        cout << "\n------------" << endl;
        cout << "L - List content" << endl;
        cout << "A - add new item" << endl;
        cout << "M - calculate mean" << endl;
        cout << "G - show greatest" << endl;
        cout << "S - show smallest" << endl;
        cout << "Q - Quit" << endl;
        cout << "What do you want to do? ";
        cin >> selected;
        cout << endl;

        switch (selected){
            case 'a':
            case 'A':{
                string to_add {};
                int parsed {};
                do{
                    cout << "Please input an integer to add: ";
                    cin >> to_add;
                    if(isdigit(to_add[0]) || (to_add[0] == '-' && isdigit(to_add[1]))){
                        parsed = stoi(to_add);
                    }
                }while(to_string(parsed) != to_add);

                content.push_back(parsed);
                sorted.push_back(parsed);
                dirty = true;
                cout << parsed << " has been added." << endl;
                break;
            }
            case 'l':
            case 'L':{
                cout << "Current item list: [";
                for(long long unsigned int i = 0; i < content.size(); i++){
                    cout << content.at(i);
                    if (i+1 < content.size()){
                        cout << ", ";
                    }
                }
                cout << ']' << endl;
                break;
            }
            case 'm':
            case 'M':{
                float mean {0};
                if(content.size() == 0){
                    cout << "No items to calculate the mean on!";
                    break;
                }
                for(long long unsigned int i = 0; i < content.size(); i++){
                    mean += content.at(i);
                }
                mean /= static_cast<float>(content.size());
                cout << "The mean of the items is: " << mean <<endl;
                break;
            }
            case 's':
            case 'S':{
                if(content.size() == 0){
                    cout << "The list is empty!";
                    break;
                }
                if (dirty){
                    sort(sorted.begin(), sorted.end());
                    dirty = false;
                }
                cout << "The smallest item is: " << sorted.at(0) << endl;
                break;
            }
            case 'g':
            case 'G':{
                if(content.size() == 0){
                    cout << "The list is empty!";
                    break;
                }
                if (dirty){
                    sort(sorted.begin(), sorted.end());
                    dirty = false;
                }
                cout << "The greatest item is: " << sorted.at(sorted.size()-1) << endl;
                break;
            }
            default: {
                cout << "Unknown command, try again."
            }


        }

    }while(selected != 'q' && selected != 'Q');

    cout << "Goodbye!";
    //Print to standard output
    cout << endl;

    //Exit with normal state
    return 0;
}