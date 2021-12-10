#include<iostream>
#include<pthread.h>
#include<time.h>
#include<cmath>
#include<vector>
#include<queue>
#include<array>
#include<stdint.h>


using namespace std;


queue<int> million;


//input primes under 1 million into a queue
void prime_till_million()
{
    int myArray[999999]={};

    for (int i=0; i<999999; i++){
        if(myArray[i]==0){
            million.push(i+2);
        }
        else{
            continue;
        }
        int multiple=2*(i+2);
        while(multiple<=1000000)
        {
            myArray[multiple-2]=1;
            multiple+=i+2;
        }
    }
    
}

//divide 1 trillion into million patrs and calculate
void* thread_function(void *data){

    
    
    array<char, 1000000> arr = {};
    int64_t input;
   
  
    queue<int>  copy = million;
    int times = (intptr_t)data + 1;
    int element = 0;
    int64_t starting_number;
    int64_t partialsum = 0;

    while (copy.empty() == 0)
    {

        element = copy.front();
       

        if (copy.empty() == 1 || (int64_t)element * (int64_t)element > (int64_t)times * 1000000) {
            break;
        }

        starting_number = (((int64_t)(times - 1) * (int64_t)1000000) / (int64_t)element) * (int64_t)element + (int64_t)element;
     

        for (int64_t i = starting_number; i <= (int64_t)times * (int64_t)1000000; i+=element ) {
            input = i - (int64_t)(times - 1) * 1000000 - 1;
            
            if (arr[input] == '1'|| i==element) {
                continue;
            }
            
            arr[(int)input] = '1';
            partialsum++;
            

        }
        
        copy.pop();
    }
   
    
    pthread_exit((void*)(intptr_t)partialsum);
}


int main(){

    
    
    time_t start_time=time(NULL);
    int64_t sum=0;
   
    prime_till_million();
   
    //create 100 threads
    pthread_t thread[100];
    
    
    intptr_t data=0;
    

   

    //for the number l such that k<l below, count the number of primes under l times 100 million.  
    for (int k = 0; k < 10000; k++) {

        for (int i = 0; i < 100; i++) {


            pthread_create(&thread[i], NULL, thread_function, (void*)data);
            
            data++;
            

        }


        void* value;
        for (int j = 0; j < 100; j++) {
            pthread_join(thread[j], &value);
            
            sum += (intptr_t)value;
        }

    }






    int64_t ans=1000000000000-sum-1;
    
   cout<<dec<<ans<<endl;
    
    
    time_t end_time=time(NULL);
    time_t elapsed_time=(double)(end_time-start_time);
    cout<<"Elapsed time: "<<elapsed_time<<endl;

    return 0;
}




