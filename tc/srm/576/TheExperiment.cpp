#include<iostream>
#include<algorithm>

#include<vector>
using namespace std;

class TheExperimentDiv2{
    public:
        vector <int> determineHumidity(vector <int> intensity, int L, vector <int> leftEnd){
            vector<int> ret;
            int*temp=new int[intensity.size()];
            for(int i=0;i<intensity.size();i++)temp[i]=1;
            for(int i=0;i<leftEnd.size();i++){
                int c=0;
                for(int j=leftEnd[i];j<leftEnd[i]+L;j++){
                    if(temp[j]){
                        temp[j]=0;
                        c+=intensity[j];
                    }
                }
                ret.push_back(c);
            }
            delete []temp;
            return ret;
        }
};

int main(){



    return 0;
}
