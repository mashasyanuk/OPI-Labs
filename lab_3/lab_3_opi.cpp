#include <iostream>
const int amount=6;
const int max_count=1;


int main(){
    int counter=0;
    int array[amount];
    int tmp,k;
    int n=amount;
	int s=n;

    while (counter<max_count){
        for(int i=0; i<amount; i++){
            array[i]=rand() % 500;
            std::cout << array[i] << " ";
        }
        std::cout << std::endl;

        s=n;
        n=amount;
        long long cnt=0;

        while(n>1) {
		s/=1.247f; 
		if (s<1) s=1; 
		k=0; 
		for (int i=0; i+s<n;++i) { 
			if(array[i]/10>array[i+s]/10) {
				tmp=array[i];
				array[i]=array[i+s];
				array[i+s]=tmp; 	
				k=i;
			}
			++cnt;
		}
		if (s==1) 
			n=k+1; 
        }
    
        counter+=1;
	}  
    std::cout << std::endl;
    for (int i=0; i<amount; i++){
            std::cout<< array[i] << " ";
    }
}

