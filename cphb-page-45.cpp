#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vb vector<bool>
#define pr(v) for(auto i : v) cout<<i<<' ';cout << '\n'
#define sc(v) for(auto &i : v) cin >> i
#define rep(i , a , b) for(int (i) = (a) ; (i) < (b) ; (i)++)
#define all(v) v.begin() , v.end()
#define ll long long
#define exp6 1000000


void algorithm1(){
    int n1 , n2;
    cin >> n1 >> n2;
    set <int> s;
    rep(i , 0 , n1){
        int elm1;
        cin >> elm1;
        s.insert(elm1);
    }
    int count = 0;
    rep(i , 0 , n2){
        int elm2;
        cin >> elm2;
        if(s.count(elm2) == 1) count++;
    }
    cout << count << '\n';
}

void algorithm2(){
    int n1 , n2;
    cin >> n1 >> n2;
    unordered_set <int> s;
    rep(i , 0 , n1){
        int elm1;
        cin >> elm1;
        s.insert(elm1);
    }
    int count = 0;
    rep(i , 0 , n2){
        int elm2;
        cin >> elm2;
        if(s.count(elm2) == 1) count++;
    }
    cout << count << '\n';
}

void algorithm3(){
    int n1 , n2;
    cin >> n1 >> n2;
    vi v1(n1) , v2(n2);
    sc(v1);sc(v2);
    sort(all(v1));
    sort(all(v2));
    auto i = v1.begin() , j = v2.begin();
    int count = 0;
    while(i != v1.end() && j != v2.end() ){
        if((*i) < (*j)) i++;
        else if((*i) > (*j)) j++;
        if(*i == *j) {count++;i++;j++;}
    }
    cout << count << '\n';
}

void generate_random_input(size_t size ,size_t sample , FILE * f ,int algoritms_num){
    vi v1(size);
    vi v2(size);
    rep(i , 0 , algoritms_num){
        if(i == 0)rep(i , 0 , size) {v1[i] = i;v2[i] = i;}

        fprintf(f , "%d %d\n" , sample , sample);

        if(i == 0)random_shuffle(all(v1));
        for(size_t i = 0 ; i < sample ; i++){
            fprintf(f , "%d " ,  v1[i]);
        }
        fprintf(f , "\n");

        if(i == 0)random_shuffle(all(v2));
        for(size_t i = 0 ; i < sample ; i++){
            fprintf(f , "%d " ,  v2[i]);
        }
        fprintf(f , "\n");
    }
}


int main(){
    // generating random input
    size_t samples[] = {1*exp6 , 2*exp6 , 3*exp6 , 4*exp6 , 5*exp6 , 10*exp6};
    
    for(auto sample_size : samples){
        size_t size  = 2*1e7;// parameters to edit
        cout << "n = " << sample_size << '\n';
        FILE * f = fopen("input-test.txt" , "w");
        generate_random_input(size, sample_size , f , 3);
        fclose(f);
        cout << "input generated" << '\n';

        #ifndef ONLINE_JUDGE
            freopen("input-test.txt", "r", stdin);
        #endif

        clock_t start_time = clock();
        cout << "algorithm 1" <<'\n';
        algorithm1();
        clock_t end_time = clock();
        double elapsed_time = double(end_time - start_time) / CLOCKS_PER_SEC;
        cout << "Elapsed time: " << elapsed_time << " seconds" << '\n';
        
        start_time = clock();
        cout << "algorithm 2" <<'\n';
        algorithm2();
        end_time = clock();
        elapsed_time = double(end_time - start_time) / CLOCKS_PER_SEC;
        cout << "Elapsed time: " << elapsed_time << " seconds" << '\n';

        start_time = clock();
        cout << "algorithm 3" <<'\n';
        algorithm3();
        end_time = clock();
        elapsed_time = double(end_time - start_time) / CLOCKS_PER_SEC;
        cout << "Elapsed time: " << elapsed_time << " seconds" << '\n';
    }
}
