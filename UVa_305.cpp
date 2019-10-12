#include <iostream>
#include <vector>
using namespace std;

int k, step, size, multiple;

bool stepCorrect(){
    int badGuys = k, position;

    position = step%size;
    if(position == 0) position = 2*k;

    while(position > k ){
        if(size > step) position = step - (size - position);
        else{
            position = (step - (size - position))%(size - 1);
            if(position == 0) position = size-1;
        }
        --badGuys;
        --size;
    }
    size = 2*k;
    return (badGuys == 0);
}

int findStep(){
    bool check = false;
    multiple = 3;
    size = 2*k;
    step = size-1; // step minimum
    if(stepCorrect()) return step;
    ++step;
    if(stepCorrect()) return step;
    else{
        while (!check) {
            step = k*multiple + 1;
            for (int i = 0; i < k; ++i) {
                check = stepCorrect();
                if(check) return step;
                else ++step;
            }
            ++multiple;
        }
    }
}

int main() {
    vector<int> steps(13); // { 2, 7, 5, 30, 169, 441, 1872, 7632, 1740, 93313, 459901, 1358657, 2504881 }
    for (int i = 0; i < 13; ++i) {
        k = i+1;
        steps[i] = findStep();
    }
    while(cin>>k, k){
        cout << steps[k-1] << endl;
    }
    return 0;
}