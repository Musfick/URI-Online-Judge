// Online C++ compiler to run C++ program online
#include <iostream>
#include <stdio.h>
#include<bits/stdc++.h>
using namespace std;

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int t;
    int i;
    while(cin>>t){
        int left[t];
        int middle[t];
        int right[t];
        string sortArr[51];
        int win=0;
        int loss=0;
        int so=0;
        char c;


        for(i=0; i<t; i++){
            cin >> left[i] >> middle[i] >> c >> right[i];
        }

        string name[t];
        int pos[t];
        char sign[t];
        for(i=0; i<t; i++){
            cin>>name[i];
            cin>>pos[i];
            cin>>sign[i];
        }

        for(i=0; i<t; i++){
            int position = pos[i]-1;

            if(sign[i]=='+'){
                if((left[position]+middle[position])==right[position]){
                    win++;
                }else{
                    sortArr[so]=name[i];
                    loss++;
                    so++;
                }
            }
            if(sign[i]=='-'){
                if((left[position]-middle[position])==right[position]){
                    win++;
                }else{
                    sortArr[so]=name[i];
                    loss++;
                    so++;
                }
            }
            if(sign[i]=='*'){
                if((left[position]*middle[position])==right[position]){
                    win++;
                }else{
                    sortArr[so]=name[i];
                    loss++;
                    so++;
                }
            }
            if(sign[i]=='I'){
                if((left[position]+middle[position])==right[position]){
                    sortArr[so]=name[i];
                    loss++;
                    so++;
                }else if((left[position]-middle[position])==right[position]){
                    sortArr[so]=name[i];
                    loss++;
                    so++;
                }else if((left[position]*middle[position])==right[position]){
                    sortArr[so]=name[i];
                    loss++;
                    so++;
                }else{
                    win++;
                }
            }
        }



        if(win==t){
            cout<<"You Shall All Pass!"<<endl;
        }else if(loss==t){
            cout<<"None Shall Pass!"<<endl;
        }else{
            string temp;

            // Use Bubble Sort to arrange words
            for (int i = 0; i < loss-1; ++i) {
                for (int j = 0; j < loss-1 - i; ++j) {
                    if (sortArr[j] > sortArr[j + 1]) {
                        temp = sortArr[j];
                        sortArr[j] = sortArr[j + 1];
                        sortArr[j + 1] = temp;
                    }
                }
            }

            for(int i = 0; i < loss; ++i){
                if(i==loss-1){
                    cout<<sortArr[i]<<endl;
                }else{
                    cout<<sortArr[i]<<" ";
                }
            }
        }


    }
    return 0;
}
